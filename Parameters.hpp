#ifndef Parameters_library
#define Parameters_libarary
#include <iostream>
#include <functional>
#include <vector>

enum strategy {exponential,inverse,Armijo};
typedef std::pair<double,double> Point;

struct Grad{
    std::vector<std::function<double(Point)>> df;
    std:: gradNum;

    Grad(std::vector<std::function<double(Point)>> DF,std::function<double (Point, double, std::function<double(Point)>)> GRADNUM){
        df=DF, gradNum=GRADNUM;
    }

    Grad() = default;
};

struct Parameters{
    Point x0;
    double tollr;
    double tolls;
    int maxIter;
    double alpha0;
    double omega;
    double mu;
    std::function<double(Point)> f;
    Grad gradient;

    Parameters(Point x, double Tr,double Ts,int Max,double alpha,double om, double m,
        std::function<double(Point)> F,std::vector<std::function<double(Point)>> DF,
        std::function<double (Point, double, std::function<double(Point)>)> GRADNUM){
            x0=x, tollr=Tr, tolls=Ts, maxIter=Max, alpha0=alpha, omega=om, mu=m, f=F, gradient.df=DF,gradient.gradNum=GRADNUM;
        }
};

#endif