// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// edgelist_to_adjmat_cpp
arma::sp_mat edgelist_to_adjmat_cpp(const arma::mat& edgelist, NumericVector weights, int n, bool undirected, bool self, bool multiple);
RcppExport SEXP _netdiffuseR_edgelist_to_adjmat_cpp(SEXP edgelistSEXP, SEXP weightsSEXP, SEXP nSEXP, SEXP undirectedSEXP, SEXP selfSEXP, SEXP multipleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type edgelist(edgelistSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type weights(weightsSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< bool >::type undirected(undirectedSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    Rcpp::traits::input_parameter< bool >::type multiple(multipleSEXP);
    rcpp_result_gen = Rcpp::wrap(edgelist_to_adjmat_cpp(edgelist, weights, n, undirected, self, multiple));
    return rcpp_result_gen;
END_RCPP
}
// adjmat_to_edgelist_cpp
arma::mat adjmat_to_edgelist_cpp(const arma::sp_mat& adjmat, bool undirected);
RcppExport SEXP _netdiffuseR_adjmat_to_edgelist_cpp(SEXP adjmatSEXP, SEXP undirectedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type adjmat(adjmatSEXP);
    Rcpp::traits::input_parameter< bool >::type undirected(undirectedSEXP);
    rcpp_result_gen = Rcpp::wrap(adjmat_to_edgelist_cpp(adjmat, undirected));
    return rcpp_result_gen;
END_RCPP
}
// toa_diff_cpp
IntegerMatrix toa_diff_cpp(const IntegerVector& year);
RcppExport SEXP _netdiffuseR_toa_diff_cpp(SEXP yearSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type year(yearSEXP);
    rcpp_result_gen = Rcpp::wrap(toa_diff_cpp(year));
    return rcpp_result_gen;
END_RCPP
}
// egonet_attrs_cpp
List egonet_attrs_cpp(const arma::sp_mat& graph, const arma::uvec V, bool outer, bool self, bool valued);
RcppExport SEXP _netdiffuseR_egonet_attrs_cpp(SEXP graphSEXP, SEXP VSEXP, SEXP outerSEXP, SEXP selfSEXP, SEXP valuedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const arma::uvec >::type V(VSEXP);
    Rcpp::traits::input_parameter< bool >::type outer(outerSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    Rcpp::traits::input_parameter< bool >::type valued(valuedSEXP);
    rcpp_result_gen = Rcpp::wrap(egonet_attrs_cpp(graph, V, outer, self, valued));
    return rcpp_result_gen;
END_RCPP
}
// approx_geodesicCpp
arma::sp_mat approx_geodesicCpp(const arma::sp_mat& G, unsigned int n, bool warn);
RcppExport SEXP _netdiffuseR_approx_geodesicCpp(SEXP GSEXP, SEXP nSEXP, SEXP warnSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type G(GSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< bool >::type warn(warnSEXP);
    rcpp_result_gen = Rcpp::wrap(approx_geodesicCpp(G, n, warn));
    return rcpp_result_gen;
END_RCPP
}
// infection_cpp
NumericVector infection_cpp(List graph, const arma::colvec& times, bool normalize, int K, double r, bool expdiscount, int n, bool valued, bool outgoing);
RcppExport SEXP _netdiffuseR_infection_cpp(SEXP graphSEXP, SEXP timesSEXP, SEXP normalizeSEXP, SEXP KSEXP, SEXP rSEXP, SEXP expdiscountSEXP, SEXP nSEXP, SEXP valuedSEXP, SEXP outgoingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type times(timesSEXP);
    Rcpp::traits::input_parameter< bool >::type normalize(normalizeSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< bool >::type expdiscount(expdiscountSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< bool >::type valued(valuedSEXP);
    Rcpp::traits::input_parameter< bool >::type outgoing(outgoingSEXP);
    rcpp_result_gen = Rcpp::wrap(infection_cpp(graph, times, normalize, K, r, expdiscount, n, valued, outgoing));
    return rcpp_result_gen;
END_RCPP
}
// susceptibility_cpp
NumericVector susceptibility_cpp(List graph, const arma::colvec& times, bool normalize, int K, double r, bool expdiscount, int n, bool valued, bool outgoing);
RcppExport SEXP _netdiffuseR_susceptibility_cpp(SEXP graphSEXP, SEXP timesSEXP, SEXP normalizeSEXP, SEXP KSEXP, SEXP rSEXP, SEXP expdiscountSEXP, SEXP nSEXP, SEXP valuedSEXP, SEXP outgoingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type times(timesSEXP);
    Rcpp::traits::input_parameter< bool >::type normalize(normalizeSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< bool >::type expdiscount(expdiscountSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< bool >::type valued(valuedSEXP);
    Rcpp::traits::input_parameter< bool >::type outgoing(outgoingSEXP);
    rcpp_result_gen = Rcpp::wrap(susceptibility_cpp(graph, times, normalize, K, r, expdiscount, n, valued, outgoing));
    return rcpp_result_gen;
END_RCPP
}
// select_egoalter_cpp
DataFrame select_egoalter_cpp(const arma::sp_mat& adjmat_t0, const arma::sp_mat& adjmat_t1, const NumericVector& adopt_t0, const NumericVector& adopt_t1);
RcppExport SEXP _netdiffuseR_select_egoalter_cpp(SEXP adjmat_t0SEXP, SEXP adjmat_t1SEXP, SEXP adopt_t0SEXP, SEXP adopt_t1SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type adjmat_t0(adjmat_t0SEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type adjmat_t1(adjmat_t1SEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type adopt_t0(adopt_t0SEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type adopt_t1(adopt_t1SEXP);
    rcpp_result_gen = Rcpp::wrap(select_egoalter_cpp(adjmat_t0, adjmat_t1, adopt_t0, adopt_t1));
    return rcpp_result_gen;
END_RCPP
}
// sp_trimatl
arma::sp_mat sp_trimatl(const arma::sp_mat& x);
RcppExport SEXP _netdiffuseR_sp_trimatl(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(sp_trimatl(x));
    return rcpp_result_gen;
END_RCPP
}
// sp_diag
arma::sp_mat sp_diag(const arma::sp_mat& x, const arma::vec& v);
RcppExport SEXP _netdiffuseR_sp_diag(SEXP xSEXP, SEXP vSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type v(vSEXP);
    rcpp_result_gen = Rcpp::wrap(sp_diag(x, v));
    return rcpp_result_gen;
END_RCPP
}
// unif_rand_w_exclusion
int unif_rand_w_exclusion(int n, int e);
RcppExport SEXP _netdiffuseR_unif_rand_w_exclusion(SEXP nSEXP, SEXP eSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type e(eSEXP);
    rcpp_result_gen = Rcpp::wrap(unif_rand_w_exclusion(n, e));
    return rcpp_result_gen;
END_RCPP
}
// sp_as_undirected
arma::sp_mat sp_as_undirected(const arma::sp_mat& x);
RcppExport SEXP _netdiffuseR_sp_as_undirected(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(sp_as_undirected(x));
    return rcpp_result_gen;
END_RCPP
}
// bootnet_fillself
arma::sp_mat bootnet_fillself(arma::sp_mat& graph, const IntegerVector& index, const NumericVector& E);
RcppExport SEXP _netdiffuseR_bootnet_fillself(SEXP graphSEXP, SEXP indexSEXP, SEXP ESEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type index(indexSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type E(ESEXP);
    rcpp_result_gen = Rcpp::wrap(bootnet_fillself(graph, index, E));
    return rcpp_result_gen;
END_RCPP
}
// grid_distribution
List grid_distribution(const arma::vec& x, const arma::vec& y, int nlevels);
RcppExport SEXP _netdiffuseR_grid_distribution(SEXP xSEXP, SEXP ySEXP, SEXP nlevelsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< int >::type nlevels(nlevelsSEXP);
    rcpp_result_gen = Rcpp::wrap(grid_distribution(x, y, nlevels));
    return rcpp_result_gen;
END_RCPP
}
// edges_coords
NumericMatrix edges_coords(const arma::sp_mat& graph, const arma::colvec& toa, const arma::colvec& x, const arma::colvec& y, const arma::colvec& vertex_cex, bool undirected, bool no_contemporary, NumericVector dev, NumericVector ran, LogicalVector curved);
RcppExport SEXP _netdiffuseR_edges_coords(SEXP graphSEXP, SEXP toaSEXP, SEXP xSEXP, SEXP ySEXP, SEXP vertex_cexSEXP, SEXP undirectedSEXP, SEXP no_contemporarySEXP, SEXP devSEXP, SEXP ranSEXP, SEXP curvedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type toa(toaSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type vertex_cex(vertex_cexSEXP);
    Rcpp::traits::input_parameter< bool >::type undirected(undirectedSEXP);
    Rcpp::traits::input_parameter< bool >::type no_contemporary(no_contemporarySEXP);
    Rcpp::traits::input_parameter< NumericVector >::type dev(devSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ran(ranSEXP);
    Rcpp::traits::input_parameter< LogicalVector >::type curved(curvedSEXP);
    rcpp_result_gen = Rcpp::wrap(edges_coords(graph, toa, x, y, vertex_cex, undirected, no_contemporary, dev, ran, curved));
    return rcpp_result_gen;
END_RCPP
}
// edges_arrow
List edges_arrow(const double& x0, const double& y0, const double& x1, const double& y1, const double& height, const double& width, const double beta, NumericVector dev, NumericVector ran, bool curved);
RcppExport SEXP _netdiffuseR_edges_arrow(SEXP x0SEXP, SEXP y0SEXP, SEXP x1SEXP, SEXP y1SEXP, SEXP heightSEXP, SEXP widthSEXP, SEXP betaSEXP, SEXP devSEXP, SEXP ranSEXP, SEXP curvedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const double& >::type x0(x0SEXP);
    Rcpp::traits::input_parameter< const double& >::type y0(y0SEXP);
    Rcpp::traits::input_parameter< const double& >::type x1(x1SEXP);
    Rcpp::traits::input_parameter< const double& >::type y1(y1SEXP);
    Rcpp::traits::input_parameter< const double& >::type height(heightSEXP);
    Rcpp::traits::input_parameter< const double& >::type width(widthSEXP);
    Rcpp::traits::input_parameter< const double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type dev(devSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ran(ranSEXP);
    Rcpp::traits::input_parameter< bool >::type curved(curvedSEXP);
    rcpp_result_gen = Rcpp::wrap(edges_arrow(x0, y0, x1, y1, height, width, beta, dev, ran, curved));
    return rcpp_result_gen;
END_RCPP
}
// vertices_coords
List vertices_coords(const arma::colvec& x, const arma::colvec& y, const arma::colvec& size, const arma::colvec& nsides, const arma::colvec& rot, NumericVector dev, NumericVector ran);
RcppExport SEXP _netdiffuseR_vertices_coords(SEXP xSEXP, SEXP ySEXP, SEXP sizeSEXP, SEXP nsidesSEXP, SEXP rotSEXP, SEXP devSEXP, SEXP ranSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type size(sizeSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type nsides(nsidesSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type rot(rotSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type dev(devSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ran(ranSEXP);
    rcpp_result_gen = Rcpp::wrap(vertices_coords(x, y, size, nsides, rot, dev, ran));
    return rcpp_result_gen;
END_RCPP
}
// rgraph_er_cpp
arma::sp_mat rgraph_er_cpp(int n, double p, bool undirected, bool weighted, bool self);
RcppExport SEXP _netdiffuseR_rgraph_er_cpp(SEXP nSEXP, SEXP pSEXP, SEXP undirectedSEXP, SEXP weightedSEXP, SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type p(pSEXP);
    Rcpp::traits::input_parameter< bool >::type undirected(undirectedSEXP);
    Rcpp::traits::input_parameter< bool >::type weighted(weightedSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(rgraph_er_cpp(n, p, undirected, weighted, self));
    return rcpp_result_gen;
END_RCPP
}
// ring_lattice
arma::sp_mat ring_lattice(int n, int k, bool undirected);
RcppExport SEXP _netdiffuseR_ring_lattice(SEXP nSEXP, SEXP kSEXP, SEXP undirectedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    Rcpp::traits::input_parameter< bool >::type undirected(undirectedSEXP);
    rcpp_result_gen = Rcpp::wrap(ring_lattice(n, k, undirected));
    return rcpp_result_gen;
END_RCPP
}
// rewire_endpoints
arma::sp_mat rewire_endpoints(const arma::sp_mat& graph, double p, bool both_ends, bool self, bool multiple, bool undirected);
RcppExport SEXP _netdiffuseR_rewire_endpoints(SEXP graphSEXP, SEXP pSEXP, SEXP both_endsSEXP, SEXP selfSEXP, SEXP multipleSEXP, SEXP undirectedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< double >::type p(pSEXP);
    Rcpp::traits::input_parameter< bool >::type both_ends(both_endsSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    Rcpp::traits::input_parameter< bool >::type multiple(multipleSEXP);
    Rcpp::traits::input_parameter< bool >::type undirected(undirectedSEXP);
    rcpp_result_gen = Rcpp::wrap(rewire_endpoints(graph, p, both_ends, self, multiple, undirected));
    return rcpp_result_gen;
END_RCPP
}
// rewire_swap
arma::sp_mat rewire_swap(const arma::sp_mat& graph, int nsteps, bool self, bool multiple, bool undirected, double pr_rewire);
RcppExport SEXP _netdiffuseR_rewire_swap(SEXP graphSEXP, SEXP nstepsSEXP, SEXP selfSEXP, SEXP multipleSEXP, SEXP undirectedSEXP, SEXP pr_rewireSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< int >::type nsteps(nstepsSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    Rcpp::traits::input_parameter< bool >::type multiple(multipleSEXP);
    Rcpp::traits::input_parameter< bool >::type undirected(undirectedSEXP);
    Rcpp::traits::input_parameter< double >::type pr_rewire(pr_rewireSEXP);
    rcpp_result_gen = Rcpp::wrap(rewire_swap(graph, nsteps, self, multiple, undirected, pr_rewire));
    return rcpp_result_gen;
END_RCPP
}
// rewire_ws
arma::sp_mat rewire_ws(arma::sp_mat G, int K, double p, bool self, bool multiple);
RcppExport SEXP _netdiffuseR_rewire_ws(SEXP GSEXP, SEXP KSEXP, SEXP pSEXP, SEXP selfSEXP, SEXP multipleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::sp_mat >::type G(GSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type p(pSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    Rcpp::traits::input_parameter< bool >::type multiple(multipleSEXP);
    rcpp_result_gen = Rcpp::wrap(rewire_ws(G, K, p, self, multiple));
    return rcpp_result_gen;
END_RCPP
}
// permute_graph_cpp
arma::sp_mat permute_graph_cpp(const arma::sp_mat& x, bool self, bool multiple);
RcppExport SEXP _netdiffuseR_permute_graph_cpp(SEXP xSEXP, SEXP selfSEXP, SEXP multipleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    Rcpp::traits::input_parameter< bool >::type multiple(multipleSEXP);
    rcpp_result_gen = Rcpp::wrap(permute_graph_cpp(x, self, multiple));
    return rcpp_result_gen;
END_RCPP
}
// rgraph_ba_cpp
arma::sp_mat rgraph_ba_cpp(const arma::sp_mat& graph, const arma::colvec& dgr, int m, int t, bool self);
RcppExport SEXP _netdiffuseR_rgraph_ba_cpp(SEXP graphSEXP, SEXP dgrSEXP, SEXP mSEXP, SEXP tSEXP, SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type dgr(dgrSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type t(tSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(rgraph_ba_cpp(graph, dgr, m, t, self));
    return rcpp_result_gen;
END_RCPP
}
// rgraph_ba_new_cpp
arma::sp_mat rgraph_ba_new_cpp(int m0, int m, int t, bool self);
RcppExport SEXP _netdiffuseR_rgraph_ba_new_cpp(SEXP m0SEXP, SEXP mSEXP, SEXP tSEXP, SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type m0(m0SEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type t(tSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(rgraph_ba_new_cpp(m0, m, t, self));
    return rcpp_result_gen;
END_RCPP
}
// rgraph_sf_homo
arma::sp_mat rgraph_sf_homo(const arma::colvec& eta, const arma::sp_mat& graph, const arma::colvec& dgr, int m, int t, bool self);
RcppExport SEXP _netdiffuseR_rgraph_sf_homo(SEXP etaSEXP, SEXP graphSEXP, SEXP dgrSEXP, SEXP mSEXP, SEXP tSEXP, SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type eta(etaSEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type dgr(dgrSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type t(tSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(rgraph_sf_homo(eta, graph, dgr, m, t, self));
    return rcpp_result_gen;
END_RCPP
}
// rgraph_sf_homo_new
arma::sp_mat rgraph_sf_homo_new(const arma::colvec& eta, int m0, int m, int t, bool self);
RcppExport SEXP _netdiffuseR_rgraph_sf_homo_new(SEXP etaSEXP, SEXP m0SEXP, SEXP mSEXP, SEXP tSEXP, SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type eta(etaSEXP);
    Rcpp::traits::input_parameter< int >::type m0(m0SEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type t(tSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(rgraph_sf_homo_new(eta, m0, m, t, self));
    return rcpp_result_gen;
END_RCPP
}
// vertex_covariate_dist
arma::sp_mat vertex_covariate_dist(const arma::sp_mat& graph, const arma::mat& X, double p);
RcppExport SEXP _netdiffuseR_vertex_covariate_dist(SEXP graphSEXP, SEXP XSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(vertex_covariate_dist(graph, X, p));
    return rcpp_result_gen;
END_RCPP
}
// vertex_mahalanobis_dist_cpp
arma::sp_mat vertex_mahalanobis_dist_cpp(const arma::sp_mat& graph, const arma::mat& X, const arma::mat& S);
RcppExport SEXP _netdiffuseR_vertex_mahalanobis_dist_cpp(SEXP graphSEXP, SEXP XSEXP, SEXP SSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type S(SSEXP);
    rcpp_result_gen = Rcpp::wrap(vertex_mahalanobis_dist_cpp(graph, X, S));
    return rcpp_result_gen;
END_RCPP
}
// vertex_covariate_compare
arma::sp_mat vertex_covariate_compare(const arma::sp_mat& graph, const NumericVector& X, std::string funname);
RcppExport SEXP _netdiffuseR_vertex_covariate_compare(SEXP graphSEXP, SEXP XSEXP, SEXP funnameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type X(XSEXP);
    Rcpp::traits::input_parameter< std::string >::type funname(funnameSEXP);
    rcpp_result_gen = Rcpp::wrap(vertex_covariate_compare(graph, X, funname));
    return rcpp_result_gen;
END_RCPP
}
// moran_cpp
List moran_cpp(const arma::colvec& x, const arma::sp_mat& w);
RcppExport SEXP _netdiffuseR_moran_cpp(SEXP xSEXP, SEXP wSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type w(wSEXP);
    rcpp_result_gen = Rcpp::wrap(moran_cpp(x, w));
    return rcpp_result_gen;
END_RCPP
}
// matrix_compareCpp
arma::sp_mat matrix_compareCpp(const arma::sp_mat& A, const arma::sp_mat& B, Function fun);
RcppExport SEXP _netdiffuseR_matrix_compareCpp(SEXP ASEXP, SEXP BSEXP, SEXP funSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< Function >::type fun(funSEXP);
    rcpp_result_gen = Rcpp::wrap(matrix_compareCpp(A, B, fun));
    return rcpp_result_gen;
END_RCPP
}
// struct_test_mean
double struct_test_mean(NumericVector& y, std::string funname, bool self);
RcppExport SEXP _netdiffuseR_struct_test_mean(SEXP ySEXP, SEXP funnameSEXP, SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type y(ySEXP);
    Rcpp::traits::input_parameter< std::string >::type funname(funnameSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(struct_test_mean(y, funname, self));
    return rcpp_result_gen;
END_RCPP
}
// struct_test_var
double struct_test_var(NumericVector& y, std::string funname, bool self);
RcppExport SEXP _netdiffuseR_struct_test_var(SEXP ySEXP, SEXP funnameSEXP, SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type y(ySEXP);
    Rcpp::traits::input_parameter< std::string >::type funname(funnameSEXP);
    Rcpp::traits::input_parameter< bool >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(struct_test_var(y, funname, self));
    return rcpp_result_gen;
END_RCPP
}
// ego_variance
NumericVector ego_variance(const arma::sp_mat& graph, const NumericVector& Y, std::string funname, bool all);
RcppExport SEXP _netdiffuseR_ego_variance(SEXP graphSEXP, SEXP YSEXP, SEXP funnameSEXP, SEXP allSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type graph(graphSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< std::string >::type funname(funnameSEXP);
    Rcpp::traits::input_parameter< bool >::type all(allSEXP);
    rcpp_result_gen = Rcpp::wrap(ego_variance(graph, Y, funname, all));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_netdiffuseR_edgelist_to_adjmat_cpp", (DL_FUNC) &_netdiffuseR_edgelist_to_adjmat_cpp, 6},
    {"_netdiffuseR_adjmat_to_edgelist_cpp", (DL_FUNC) &_netdiffuseR_adjmat_to_edgelist_cpp, 2},
    {"_netdiffuseR_toa_diff_cpp", (DL_FUNC) &_netdiffuseR_toa_diff_cpp, 1},
    {"_netdiffuseR_egonet_attrs_cpp", (DL_FUNC) &_netdiffuseR_egonet_attrs_cpp, 5},
    {"_netdiffuseR_approx_geodesicCpp", (DL_FUNC) &_netdiffuseR_approx_geodesicCpp, 3},
    {"_netdiffuseR_infection_cpp", (DL_FUNC) &_netdiffuseR_infection_cpp, 9},
    {"_netdiffuseR_susceptibility_cpp", (DL_FUNC) &_netdiffuseR_susceptibility_cpp, 9},
    {"_netdiffuseR_select_egoalter_cpp", (DL_FUNC) &_netdiffuseR_select_egoalter_cpp, 4},
    {"_netdiffuseR_sp_trimatl", (DL_FUNC) &_netdiffuseR_sp_trimatl, 1},
    {"_netdiffuseR_sp_diag", (DL_FUNC) &_netdiffuseR_sp_diag, 2},
    {"_netdiffuseR_unif_rand_w_exclusion", (DL_FUNC) &_netdiffuseR_unif_rand_w_exclusion, 2},
    {"_netdiffuseR_sp_as_undirected", (DL_FUNC) &_netdiffuseR_sp_as_undirected, 1},
    {"_netdiffuseR_bootnet_fillself", (DL_FUNC) &_netdiffuseR_bootnet_fillself, 3},
    {"_netdiffuseR_grid_distribution", (DL_FUNC) &_netdiffuseR_grid_distribution, 3},
    {"_netdiffuseR_edges_coords", (DL_FUNC) &_netdiffuseR_edges_coords, 10},
    {"_netdiffuseR_edges_arrow", (DL_FUNC) &_netdiffuseR_edges_arrow, 10},
    {"_netdiffuseR_vertices_coords", (DL_FUNC) &_netdiffuseR_vertices_coords, 7},
    {"_netdiffuseR_rgraph_er_cpp", (DL_FUNC) &_netdiffuseR_rgraph_er_cpp, 5},
    {"_netdiffuseR_ring_lattice", (DL_FUNC) &_netdiffuseR_ring_lattice, 3},
    {"_netdiffuseR_rewire_endpoints", (DL_FUNC) &_netdiffuseR_rewire_endpoints, 6},
    {"_netdiffuseR_rewire_swap", (DL_FUNC) &_netdiffuseR_rewire_swap, 6},
    {"_netdiffuseR_rewire_ws", (DL_FUNC) &_netdiffuseR_rewire_ws, 5},
    {"_netdiffuseR_permute_graph_cpp", (DL_FUNC) &_netdiffuseR_permute_graph_cpp, 3},
    {"_netdiffuseR_rgraph_ba_cpp", (DL_FUNC) &_netdiffuseR_rgraph_ba_cpp, 5},
    {"_netdiffuseR_rgraph_ba_new_cpp", (DL_FUNC) &_netdiffuseR_rgraph_ba_new_cpp, 4},
    {"_netdiffuseR_rgraph_sf_homo", (DL_FUNC) &_netdiffuseR_rgraph_sf_homo, 6},
    {"_netdiffuseR_rgraph_sf_homo_new", (DL_FUNC) &_netdiffuseR_rgraph_sf_homo_new, 5},
    {"_netdiffuseR_vertex_covariate_dist", (DL_FUNC) &_netdiffuseR_vertex_covariate_dist, 3},
    {"_netdiffuseR_vertex_mahalanobis_dist_cpp", (DL_FUNC) &_netdiffuseR_vertex_mahalanobis_dist_cpp, 3},
    {"_netdiffuseR_vertex_covariate_compare", (DL_FUNC) &_netdiffuseR_vertex_covariate_compare, 3},
    {"_netdiffuseR_moran_cpp", (DL_FUNC) &_netdiffuseR_moran_cpp, 2},
    {"_netdiffuseR_matrix_compareCpp", (DL_FUNC) &_netdiffuseR_matrix_compareCpp, 3},
    {"_netdiffuseR_struct_test_mean", (DL_FUNC) &_netdiffuseR_struct_test_mean, 3},
    {"_netdiffuseR_struct_test_var", (DL_FUNC) &_netdiffuseR_struct_test_var, 3},
    {"_netdiffuseR_ego_variance", (DL_FUNC) &_netdiffuseR_ego_variance, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_netdiffuseR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
