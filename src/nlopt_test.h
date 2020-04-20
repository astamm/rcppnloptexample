#ifndef NLOPT_TEST_H
#define NLOPT_TEST_H

#include "Rcpp.h"
#include <nloptrAPI.h>

static int fcount = 0, ccount = 0;

double myfunc(unsigned n, const double *x, double *grad, void *my_func_data);

typedef struct {
  double a, b;
} my_constraint_data;

double myconstraint(unsigned n, const double *x, double *grad, void *data);

//' A simple example for for NLopt integration for Rcpp,
//' using an example from the NLopt tutorial.
//'
//' @title NLopt Call Example from Rcpp
//' @param method A string defaulting to \sQuote{MMA} (also allowing \sQuote{COBYLA})
//' which selects the algorithm use.
//' @param verbose A boolean toggle defaulting to \sQuote{false}
//' @return A numeric vector with two elements
//' @seealso \url{https://nlopt.readthedocs.io/en/latest/NLopt_Tutorial/}
//' @examples
//' testConstrainedProblem("MMA", TRUE)
// [[Rcpp::export]]
std::vector<double> testConstrainedProblem(std::string method = "MMA",
                                           bool verbose = false);

#endif /* NLOPT_TEST_H */
