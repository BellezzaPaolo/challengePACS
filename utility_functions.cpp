#include "utility_functions.hpp"
#include <cmath>

double norm(const Point& a){
    return sqrt(std::pow(a.first,2)+std::pow(a.second,2));
}

Point operator- (const Point& a, const Point& b){
    return std::make_pair(a.first-b.first,a.second-b.second);
}

bool condition(const Point& x, double alpha,double omega,std::function<double(Point)> f,std::vector<std::function<double(Point)>> df){
    Point XmenoGrad=std::make_pair(x.first-alpha*df[0](x),x.second-alpha*df[1](x));
    double norma=norm(std::make_pair(df[0](x),df[1](x)));

    return f(x)-f(XmenoGrad)>=omega*alpha*std::pow(norma,2);
}

double calcAlphak(const Parameters& p, strategy S,double k){
    double alphaK;
    switch(S){
        case exponential:
            alphaK=p.alpha0*std::exp(-p.mu*k);
        case inverse:
            alphaK=p.alpha0/(1+p.mu*k);
        case Armijo:
            alphaK=p.alpha0;
            while(!condition(p.x0, alphaK,p.omega,p.f,p.gradient.df)){
                alphaK/=2;
            }
    }
    return alphaK;
}

Point Minimum(const Parameters& p,strategy S){
    Point x=p.x0, xN(1.0,1.0);
    size_t k=0;
    bool condizione=true;

    double alphaK=p.alpha0;

    while (condizione){
        k++;
        alphaK=calcAlphak(p,S,k);
 
        xN.first=x.first-alphaK*p.gradient.df[0](x);
        xN.second=x.second-alphaK*p.gradient.df[1](x);

        if(norm(xN-x)<p.tolls || norm(std::make_pair(p.gradient.df[0](xN),p.gradient.df[1](xN)))<p.tollr || k>p.maxIter){
            condizione=false;      
        }

        x=xN;
    }

    std::cout<<"iterate "<<k<<"\n"<<std::endl;

    return xN;
}
