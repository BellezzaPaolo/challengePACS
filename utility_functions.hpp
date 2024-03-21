#ifndef utility_functions_library
#define utility_functions_libarary
#include "Parameters.hpp"

double norm(const Point& a);
Point operator- (const Point& a, const Point& b);
bool condition(const Point& x, double alpha,double omega,std::function<double(Point)> f,std::vector<std::function<double(Point)>> df);
double calcAlphak(const Parameters& p, strategy S,double k);
Point Minimum(const Parameters& p,strategy S);

#endif