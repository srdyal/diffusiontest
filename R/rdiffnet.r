#' Random diffnet network
#'
#' Simulates a diffusion network by creating a random dynamic network and
#' adoption threshold levels.
#'
#' @param n Integer scalar. Number of vertices.
#' @param t Integer scalar. Time length.
#' @param seed.nodes Either a character scalar or a vector. Type of seed nodes (see details).
#' @param seed.p.adopt Numeric scalar. Proportion of early adopters.
#' @param seed.graph Baseline graph used for the simulation (see details).
#' @param rgraph.args List. Arguments to be passed to rgraph.
#' @param rewire Logical scalar. When TRUE, network slices are generated by rewiring
#' (see \code{\link{rewire_graph}}).
#' @param rewire.args List. Arguments to be passed to \code{\link{rewire_graph}}.
#' @param threshold.dist Either a function to be applied via \code{\link{sapply}},
#' a numeric scalar, or a vector/matrix with \eqn{n} elements. Sets the adoption
#' threshold for each node.
#' @param exposure.args List. Arguments to be passed to \code{\link{exposure}}.
#' @param name Character scalar. Passed to \code{\link{as_diffnet}}.
#' @param behavior Character scalar. Passed to \code{\link{as_diffnet}}.
#' @param stop.no.diff Logical scalar. When \code{TRUE}, the function will return
#' with error if there was no diffusion. Otherwise it throws a warning.
#' @return A random \code{\link{diffnet}} class object.
#' @family simulation functions
#' @details
#'
#' Instead of randomizing whether an individual adopts the innovation or not, this
#' toy model randomizes threshold levels, seed adopters and network structure, so
#' an individual adopts the innovation in time \eqn{T} iff his exposure is above or
#' equal to his threshold. The simulation is done in the following steps:
#'
#' \enumerate{
#'  \item Using \code{seed.graph}, a baseline graph is created.
#'  \item Given the baseline graph, the set of initial adopters is defined
#'  using \code{seed.nodes}.
#'  \item Afterwards, if \code{rewire=TRUE} \eqn{t-1} slices of the network are created
#'  by iteratively rewiring the baseline graph.
#'  \item The \code{threshold.dist} function is applied to each node in the graph.
#'  \item Simulation starts at \eqn{t=2} assigning adopters in each time period
#'  accordingly to each vertex's threshold and exposure.
#' }
#'
#' When \code{seed.nodes} is a character scalar it can be \code{"marginal"}, \code{"central"} or \code{"random"},
#' So each of these values sets the initial adopters using the vertices with lowest
#' degree, with highest degree or completely randomly. The number of early adoptes
#' is set as \code{seed.p.adopt * n}. Please note that when marginal nodes are
#' set as seed it may be the case that no diffusion process is attained as the
#' chosen set of first adopters can be isolated. Any other case will be considered
#' as an index (via \code{\link{[<-}} methods), hence the user can manually set the set of initial adopters, for example
#' if the user sets \code{seed.nodes=c(1, 4, 7)} then nodes 1, 4 and 7 will be
#' selected as initial adopters.
#'
#' The argument \code{seed.graph} can be either a function that generates a graph
#' (Any class of accepted graph format (see \code{\link{netdiffuseR-graphs}})), a
#' graph itself or a character scalar in which the user sets the algorithm used to
#' generate the first network (network in t=1), this can be either "scale-free"
#' (Barabasi-Albert model using the \code{\link{rgraph_ba}} function, the default),
#' \code{"bernoulli"} (Erdos-Renyi model using the \code{\link{rgraph_er}} function),
#' or \code{"small-world"} (Watts-Strogatz model using the \code{\link{rgraph_ws}}
#' function). The list \code{rgraph.args} passes arguments to the chosen algorithm.
#'
#' When \code{rewire=TRUE}, the networks that follow t=1 will be generated using the
#' \code{\link{rewire_graph}} function as \eqn{G(t) = R(G(t-1))}, where \eqn{R}
#' is the rewiring algorithm.
#'
#' If a function, the argument \code{threshold.dist} sets the threshold for each vertex in the graph.
#' It is applied using \code{sapply} as follows
#'
#' \preformatted{
#' sapply(1:n, threshold.dist)
#' }
#'
#' By default sets the threshold to be random for each node in the graph.
#'
#' If \code{seed.graph} is provided, no random graph is generated and the simulation
#' is applied using that graph instead.
#'
#' \code{rewire.args} has the following default options:
#'
#' \tabular{ll}{
#'   \code{p}          \tab \code{.1} \cr
#'   \code{undirected} \tab \code{getOption("diffnet.undirected", FALSE)} \cr
#'   \code{self}       \tab \code{getOption("diffnet.self", FALSE)}
#' }
#'
#' \code{exposure.args} has the following default options:
#'
#' \tabular{ll}{
#'   \code{outgoing} \tab \code{TRUE} \cr
#'   \code{valued} \tab \code{getOption("diffnet.valued", FALSE)} \cr
#'   \code{normalized} \tab \code{TRUE}
#' }
#'
#' @examples
#' # A simple example -----------------------------------------------------------
#' set.seed(123)
#' z <- rdiffnet(100,10)
#' z
#' summary(z)
#'
#' # A more complex example: Adopt if at least one neighbor has adopted --------
#' y <- rdiffnet(100, 10, threshold.dist=function(x) 1,
#'     exposure.args=list(valued=FALSE, normalized=FALSE))
#'
#' # Re thinking the Adoption of Tetracycline ----------------------------------
#' newMI <- rdiffnet(seed.graph = medInnovationsDiffNet$graph,
#'  threshold.dist = threshold(medInnovationsDiffNet), rewire=FALSE)
#'
#'
#' @author George G. Vega Yon
#' @name rdiffnet
NULL

rdiffnet_make_threshold <- function(x, n, num_of_behaviors) {

  # Check if x is a matrix or array with correct dimensions
  if (is.matrix(x) || is.array(x)) {
    if (!all(dim(x) == c(n, num_of_behaviors))) {
      stop("Incorrect threshold input in function -rdiffnet_make_threshold-. The matrix/array must have dimensions ", n, "x", num_of_behaviors, ".")
    }
    return(as.matrix(x)) # Return the matrix as-is
  } else if (!is.list(x) && num_of_behaviors > 1) {
    x <- rep(list(x), num_of_behaviors)
  }

  # Make a list, for single diffusion
  if (!is.list(x) && num_of_behaviors==1) {
    x <- list(x)
  }

  thr <- matrix(NA, nrow = n, ncol = num_of_behaviors)

  for (q in seq_len(num_of_behaviors)) {
    if (inherits(x[[q]], "function")) {
      set.seed(123)
      thr[, q] <- sapply(1:n, function(j) x[[q]]())

    } else if (is.numeric(x[[q]]) && length(x[[q]]) == 1) {

      thr[, q] <- rep(x[[q]], n)

    } else if (is.vector(x[[q]]) && length(x[[q]]) == n) {

      thr[, q] <- x[[q]]

    } else if (is.vector(x[[q]]) && length(x[[q]]) != n) {
      stop("Incorrect threshold input in function -rdiffnet_make_threshold-.")
    }
  }
  return(thr)
}

rdiffnet_check_seed_graph <- function(seed.graph, rgraph.args, t, n) {

  test <- class(seed.graph)

  if ("function" %in% test) {

    # Does it returns a graph
    test <- seed.graph()
    # Coercing into appropiate type
    if (inherits(test, "dgCMatrix")) {
      sgraph <- test
    } else if (inherits(test, "matrix")) {
      sgraph <- methods::as(test, "dgCMatrix")
    } else if (inherits(test, "array")) {
      sgraph <- apply(test, 3, function(x) methods::as(x, "dgCMatrix"))
    } else if (inherits(test, "diffnet")) {
      sgraph <- test$graph
    } else if (inherits(test, "list")) {

      sgraph <- test

    }

    # In the case of calling a function
  } else if ("character" %in% test) {

    # Scale-free networks ------------------------------------------------------
    if (seed.graph == "scale-free") {

      if (!length(rgraph.args$m0))
        rgraph.args$t <- n-1L

      sgraph <- do.call(rgraph_ba, rgraph.args)

      # Bernoulli graphs ---------------------------------------------------------
    } else if (seed.graph == "bernoulli") {

      rgraph.args$n <- n

      sgraph <- do.call(rgraph_er, rgraph.args)

      # Small-world network ------------------------------------------------------
    } else if (seed.graph == "small-world") {

      rgraph.args$n <- n
      if (!length(rgraph.args$k)) rgraph.args$k <- 2L
      if (!length(rgraph.args$p)) rgraph.args$p <- .1

      sgraph <- do.call(rgraph_ws, rgraph.args)

    } else
      stop("Invalid -seed.graph-. It should be either ",
           "'scale-free\', \'bernoulli\' or \'small-world\'.")

    # Creating t duplicates
    graph <- rep(list(sgraph), t)

  } else if (any(c("matrix", "dgCMatrix", "array") %in% test)) {

    # If not dgCMatrix
    if (("array" %in% test) & !("matrix" %in% test))
      sgraph <- apply(seed.graph, 3, function(x) methods::as(x, "dgCMatrix"))
    else
      sgraph <- methods::as(seed.graph, "dgCMatrix")

  } else if ("list" %in% test) {

    sgraph <- seed.graph

  } else if ("diffnet" %in% test) {

    sgraph <- seed.graph$graph

  } else
    stop("Invalid argument for -seed.graph-. No support for objects of class -",test,"-.")

  sgraph
}

#' @rdname rdiffnet
#' @export
#' @param R Integer scalar. Number of simulations to be done.
#' @param statistic A Function to be applied to each simulated diffusion network.
#' @param ... Further arguments to be passed to \code{rdiffnet}.
#' @param ncpus Integer scalar. Number of processors to be used (see details).
#' @param cl An object of class \code{\link[parallel:makeCluster]{c("SOCKcluster", "cluster")}}
#' (see details).
#' @details
#' The function \code{rdiffnet_multiple} is a wrapper of \code{rdiffnet} wich allows
#' simulating multiple diffusion networks with the same parameters and apply
#' the same function to all of them. This function is designed to allow the user
#' to perform larger simulation studies in which the distribution of a particular
#' statistic is observed.
#'
#' When \code{cl} is provided, then simulations are done via
#' \code{\link[parallel:parSapply]{parSapply}}. If \code{ncpus} is greater than
#' 1, then the function creates a cluster via \code{\link[parallel:makeCluster]{makeCluster}}
#' which is stopped (removed) once the process is complete.
#'
#' @return \code{rdiffnet_multiple} returns either a vector or an array depending
#' on what \code{statistic} is (see \code{\link{sapply}} and
#' \code{\link[parallel:parSapply]{parSapply}}).
#'
#' @examples
#' # Simulation study comparing the diffusion with diff sets of seed nodes -----
#'
#' # Random seed nodes
#' set.seed(1)
#' ans0 <- rdiffnet_multiple(R=50, statistic=function(x) sum(!is.na(x$toa)),
#'     n = 100, t = 4, seed.nodes = "random", stop.no.diff=FALSE)
#'
#' # Central seed nodes
#' set.seed(1)
#' ans1 <- rdiffnet_multiple(R=50, statistic=function(x) sum(!is.na(x$toa)),
#'     n = 100, t = 4, seed.nodes = "central", stop.no.diff=FALSE)
#'
#' boxplot(cbind(Random = ans0, Central = ans1), main="Number of adopters")
rdiffnet_multiple <- function(
  R,
  statistic,
  ...,
  ncpus = 1L,
  cl    = NULL
) {

  # Checking the type of answer that it returns


  # Calling parallel
  if ((ncpus > 1) | length(cl)) {

    # Creating the cluster
    if (!length(cl)) {
      cl <- parallel::makeCluster(ncpus)
      on.exit(parallel::stopCluster(cl))

      # Loading R packages
      parallel::clusterEvalQ(cl, library(netdiffuseR))
    }

    # Calling the function
    parallel::parSapply(cl, X=seq_len(R), function(i, statistic, ...) {
      statistic(netdiffuseR::rdiffnet(...))
    }, statistic = statistic, ...)

  } else {

    # If no parallel apply
    sapply(X=seq_len(R), function(i, statistic, ...) {
      statistic(netdiffuseR::rdiffnet(...))
    }, statistic = statistic, ...)
  }

}

#' @rdname rdiffnet
#' @export
rdiffnet <- function(
    n,
    t,
    seed.nodes     = "random",
    seed.p.adopt   = 0.05,
    seed.graph     = "scale-free",
    rgraph.args    = list(),
    rewire         = TRUE,
    rewire.args    = list(),
    threshold.dist = runif(n),
    exposure.args  = list(),
    name           = "A diffusion network",
    behavior       = "Random contagion",
    stop.no.diff   = TRUE,
    disadopt       = NULL
  ) {

  # Checking options
  if (!length(rewire.args[["p"]])) rewire.args[["p"]] <- .1
  if (!length(rewire.args[["undirected"]])) rewire.args[["undirected"]] <- getOption("diffnet.undirected", FALSE)
  if (!length(rewire.args[["self"]])) rewire.args[["self"]] <- getOption("diffnet.self", FALSE)

  if (!length(exposure.args[["outgoing"]])) exposure.args[["outgoing"]] <- TRUE
  if (!length(exposure.args[["valued"]])) exposure.args[["valued"]] <- getOption("diffnet.valued", FALSE)
  if (!length(exposure.args[["normalized"]])) exposure.args[["normalized"]] <- TRUE

  if (inherits(exposure.args[["attrs"]], "matrix")) {
    # Checking if the attrs matrix is has dims n x t
    if (any(dim(exposure.args[["attrs"]]) != dim(matrix(NA, nrow = n, ncol = t)))) {
      stop("Incorrect size for -attrs- in rdiffnet. Does not match n dim or t dim.")}
    attrs_arr <- exposure.args[["attrs"]]
    if (inherits(seed.p.adopt, "list")){
      attrs_arr <- array(attrs_arr, dim = c(n, t, length(seed.p.adopt)))
    } else {attrs_arr <- array(attrs_arr, dim = c(n, t, 1))}
  }

  # Step 0.0: Creating the network seed ----------------------------------------
  # Checking the class of the seed.graph
  sgraph <- rdiffnet_check_seed_graph(seed.graph, rgraph.args, t, n)

  # Checking baseline graph --------------------------------------------------
  meta <- classify_graph(sgraph)

  # Was n set?
  if (!missing(n) && n != meta$n) {
    warning("While the user set n=",n,", nnodes(seed.graph)=", meta$n,". The later will be used.")
    n <- meta$n
  }
  if (missing(n)) n <- meta$n

  # If static, t must be provided, otherwise t should be missing
  if (meta$nper == 1) {

    if (missing(t))
      stop("When -seed.graph- is static, -t- must be provided.")
    else
      sgraph <- rep(list(sgraph), t)

  } else {

    if (!missing(t))
      warning("When -seed.graph- is dynamic, -t- shouldn't be provided.")

    t <- meta$nper

  }

  # Step 0.1: Rewiring or not ------------------------------------------------

  # Rewiring
  if (rewire) {
    sgraph <- do.call(rewire_graph, c(list(graph=sgraph), rewire.args))
  }
  sgraph <- lapply(sgraph, `attr<-`, which="undirected", value=NULL)

  # Step 1.0: Setting the seed nodes -----------------------------------------

  rdiffnet_args <- rdiffnet_validate_args(seed.p.adopt, seed.nodes, behavior)
  seed.p.adopt <- rdiffnet_args$seed.p.adopt
  seed.nodes <- rdiffnet_args$seed.nodes
  behavior <- rdiffnet_args$behavior
  num_of_behaviors <- rdiffnet_args$num_of_behaviors

  # Step 1.1: Number of initial adopters

  n0 <- list()

  for (i in 1:num_of_behaviors) {

    if ((seed.p.adopt[[i]] > 1) | (seed.p.adopt[[i]] < 0)) {
      stop(paste("The proportion of initial adopters for behavior", i, "should be a number in [0,1]"))
    }
    if (n*seed.p.adopt[[i]] < 1) {
      warning(paste("Set of initial adopters for behavior", i, "set to 1."))
    }

    n0[[i]] <- max(1, n * seed.p.adopt[[i]])
  }

  # Step 1.2: finding the nodes
  d <- list()

  if (all(sapply(seed.nodes, is.character))) { # "central", "marginal", or "random"

    if (any(seed.nodes %in% c("central", "marginal"))) {
      dg <- dgr(sgraph)[, 1, drop = FALSE]
      central_d <- rownames(dg[order(dg, decreasing = TRUE), , drop = FALSE])
      marginal_d <- rownames(dg[order(dg, decreasing = FALSE), , drop = FALSE])
    }

    for (i in seq_along(seed.nodes)) { # assign nodes characters values in seed.nodes
      d[[i]] <- switch(seed.nodes[[i]],
                       "central" = as.numeric(central_d[1:floor(n0[[i]])]),
                       "marginal" = as.numeric(marginal_d[1:floor(n0[[i]])]),
                       "random" = sample.int(n, floor(n0[[i]])),
                       stop("Unsupported -seed.nodes- value. It must be either \"central\", \"marginal\", or \"random\"")
                      )
    }

  } else if (all(sapply(seed.nodes, is.numeric))) { # specific nodes

    for (i in 1:num_of_behaviors) {
      d[[i]] <- seed.nodes[[i]]
    }

  } else {
    stop("Unsupported -seed.nodes- value. See the manual for references.")
  }

  # Step 1.3: Defining cumadopt and toa (time of adoption) --------------------
  cumadopt <- array(0L, dim = c(n, t, num_of_behaviors))

  toa <- matrix(NA, nrow = dim(cumadopt)[1], ncol = dim(cumadopt)[3])

  for (q in 1:num_of_behaviors) {
    cumadopt[d[[q]],,q] <- 1L
    toa[d[[q]],q] <- 1L
  }

  # Step 2.0: Thresholds -------------------------------------------------------

  thr <- rdiffnet_make_threshold(threshold.dist, n, num_of_behaviors)

  # Step 3.0: Running the simulation -------------------------------------------

  for (i in 2:t) {

    # 3.1 Computing exposure
    if (exists("attrs_arr")){
      exposure.args[c("attrs")] <- list(attrs_arr[,i, ,drop=FALSE])
    }

    exposure.args[c("graph", "cumadopt")] <- list(sgraph[i], cumadopt[,i, ,drop=FALSE])
    expo <- do.call(exposure, exposure.args)

    for (q in 1:num_of_behaviors) {

      # 3.2 Identifying who adopts based on the threshold
      whoadopts <- which( (expo[,,q] >= thr[,q]) & is.na(toa[,q]))

      # 3.3 Updating the cumadopt
      cumadopt[whoadopts, i:t, q] <- 1L

      # 3.4 Updating the toa
      if (length(whoadopts) > 0) {
        toa[cbind(whoadopts, q)] <- i
      }
    }

    # 3.5 identifiying the disadopters
    if (length(disadopt)) {

      # Run the disadoption algorithm. This will return the following:
      # - A list of length q with the nodes that disadopted
      disadopt_res <- disadopt(expo, cumadopt, i)

      for (q in seq_along(disadopt_res)) {

        # So only doing this if there's disadoption
        if (length(disadopt_res[[q]]) == 0)
          next

        # Checking this makes sense (only adopters can disadopt)
        q_adopters <- which(!is.na(toa[, q]))

        if (length(setdiff(disadopt_res[[q]], q_adopters)) > 0)
          stop("Some nodes that disadopted were not adopters.")

        # Updating the cumadopt
        cumadopt[disadopt_res[[q]], i:t, q] <- 0L

        # Updating toa
        toa[cbind(disadopt_res[[q]], q)] <- NA

      }
    }
  }

  for (i in 1:num_of_behaviors) {
    reachedt <- max(toa[,i], na.rm=TRUE)

    if (reachedt == 1) {
      if (stop.no.diff)
        stop(
          paste(
            "No diffusion in this network for behavior", i,
            "(Ups!) try changing the seed or the parameters."
            )
          )
      else
        warning(paste("No diffusion for behavior", i, " in this network."))
    }
  }

  # Step 4.0: Creating diffnet object ------------------------------------------
  # Checking attributes
  isself <- any(sapply(sgraph, function(x) any(Matrix::diag(x) != 0) ))

  if (num_of_behaviors==1) {
    toa <- as.integer(toa)
  } else {
    toa <- array(as.integer(toa), dim = dim(toa))
  }

  new_diffnet(
    graph      = sgraph,
    toa        = toa,
    self       = isself,
    t0         = 1,
    t1         = t,
    vertex.static.attrs = data.frame(real_threshold=thr),
    name       = name,
    behavior   = behavior
  )
}

rdiffnet_validate_args <- function(seed.p.adopt, seed.nodes, behavior) {

  # seed.p.adopt stuff
  # The class of seed.p.adopt determines if is a single or multiple diff pross.

  if (inherits(seed.p.adopt, "list")) {
    message(paste("Message: Multi-diffusion behavior simulation selected.",
                  "Number of behaviors: ", length(seed.p.adopt)))
    multi <- TRUE
  } else if (inherits(seed.p.adopt, "numeric")) {

    if (length(seed.p.adopt)>1) {
      stop(paste("length(seed.p.adopt) =", length(seed.p.adopt),
                 ", but for multi-diffusion -seed.p.adopt- must be a -list-."))
    }

    multi <- FALSE
  } else {

    stop("The object -seed.p.adopt- must be a -numeric- (for a single behavior diff)",
         "or a -list- (multiple behavior diff).")
  }

  # seed.nodes stuff

  if (multi) {

    # For multi-diff.

    if (inherits(seed.nodes, "list")) {
      if (length(seed.nodes) != length(seed.p.adopt)) {
        stop("Length of lists -seed.nodes- and -seed.p.adopt- must be the same for multi diffusion.")
      }
      if (all(sapply(seed.nodes, is.character))) {
        if (any(!seed.nodes %in% c("marginal", "central", "random"))) {
          stop("Some element in list -seed.nodes- is a -character- different from 'marginal', 'central', or 'random'.")
        }
      } else if (all(sapply(seed.nodes, is.numeric))) {
        if (any(sapply(seed.nodes, is.null))) {
          stop("There is a NULL -numeric- element")
        }
        if (any(sapply(seed.nodes, function(x) any(x != round(x))))) {
          stop("Some value in the elements of the list -seed.nodes- is non-integer.")
        }
      } else {
        stop("All elements of the list seed.nodes must be either -character- or -numeric-.")
      }
    } else if (inherits(seed.nodes, "numeric")) {
      message("Message: Object -seed.nodes- converted to a -list-.",
              "All behaviors will have the same -", seed.nodes, "- seed nodes.")

      seed.nodes <- replicate(length(seed.p.adopt), seed.nodes, simplify = FALSE)
    } else if (inherits(seed.nodes, "character")) {
      if (length(seed.nodes)==length(seed.p.adopt)) {
        seed.nodes <- as.list(seed.nodes)
        message("Message: Object -seed.nodes- converted to a -list-.",
                "For example, the first behavior has seed -", seed.nodes[[1]], "-, the second has -", seed.nodes[[2]], "-, etc.")
      } else {
      message("Message: Object -seed.nodes- converted to a -list-.",
              "All behaviors will have the same -", seed.nodes, "- seed nodes.")
      seed.nodes <- replicate(length(seed.p.adopt), seed.nodes, simplify = FALSE)
      }
    } else {
      stop("Unsupported -seed.nodes- value. See the manual for references.")
    }

    if (inherits(behavior, "list")) {
      if (length(seed.p.adopt)!=length(behavior)) {
        stop("If -behavior- is a list, it must be of the same length as -seed.p.adopt-.")
      }
    } else if (inherits(behavior, "character") && length(behavior) > 1) {
      if (length(behavior) != length(seed.p.adopt)) {
        stop("Mismatch between length(behavior) and length(seed.p.adopt)")
      } else {
        behavior <- as.list(behavior)
      }
    } else if (inherits(behavior, "character") && length(behavior) == 1) {
      message(paste("Message: Name of 1 behavior provided, but", length(seed.p.adopt), "are needed. "),
              "Names generalized to 'behavior'_1, 'behavior'_2, etc.")
      behaviors <- list()
      for (i in seq_along(seed.p.adopt)) {
        behaviors[[i]] <- paste(behavior, i, sep = "_")
      }
      behavior <- behaviors
    }

  } else {

    # For Single-diff.

    if (length(seed.nodes) == 1 && inherits(seed.nodes, "character")) {
      if (!seed.nodes %in% c("marginal", "central", "random")) {
        stop("Object -seed.nodes- is a -character- different from 'marginal', 'central', or 'random'.")
      }
    } else if (!inherits(seed.nodes, "character")) {
      if (any(sapply(seed.nodes, function(x) any(x != round(x))))) {
        stop("Some value in the elements of the list -seed.nodes- is non-integer.")
      }
    } else {
      stop("Unsupported -seed.nodes- value. See the manual for references.")
    }
    if (length(behavior)>1) {
      stop("More names were provided than necessary.")
    }

    seed.p.adopt <- list(seed.p.adopt)
    seed.nodes <- list(seed.nodes)
    behavior <- list(behavior)
  }

  list(
    seed.p.adopt = seed.p.adopt,
    seed.nodes = seed.nodes,
    behavior = behavior,
    num_of_behaviors = length(seed.p.adopt)
  )
}

#' Splitting behaviors
#'
#' Split each behavior within multi-diffusion diffnet object. The function gets
#' \code{toa}, \code{adopt}, \code{cumadopt}, and the \code{behavior} name from
#' each behavior, and returns a list where each element is a single behavior.
#' All the rest of the structure remains the same for each element in the list.
#'
#' @param diffnet_obj A multi-diffusion diffnet object.
#' @examples
#' # Running a multi-diffusion simulation
#' set.seed(1231)
#' diffnet_multi <- rdiffnet(50, 5, seed.p.adopt = list(0.1,0.1))
#'
#' diffnet_multi_list <- split_behaviors(diffnet_multi)
#' diffnet_single <- diffnet_multi_list[[1]]
#'
#' # You can now run standard functions for a single behavior
#' # Plotting single behavior
#' plot_diffnet(diffnet_single, slices = c(1, 3, 5))
#'
#' @return A list of diffnet objects. Each element represent a unique behavior.
#' @export
#' @author George G. Vega Yon & Aníbal Olivera M.
#' @name split_behaviors
split_behaviors <- function(diffnet_obj) {

  # creates a list, keeping the structure of each element
  diffnets <- replicate(ncol(diffnet_obj$toa), diffnet_obj, simplify = FALSE)

  behaviors_names <- strsplit(diffnet_obj$meta$behavior, ", ")[[1]]

  # loop over the behaviors
  for (q in 1:ncol(diffnet_obj$toa)) {
    diffnets[[q]]$toa <- as.integer(diffnet_obj$toa[, q, drop = FALSE])
    names(diffnets[[q]]$toa) <- rownames(diffnet_obj$toa)

    diffnets[[q]]$adopt <- diffnet_obj$adopt[[q]]

    diffnets[[q]]$cumadopt <- diffnet_obj$cumadopt[[q]]

    diffnets[[q]]$meta$behavior <- behaviors_names[q]
  }

  return(diffnets)
}

