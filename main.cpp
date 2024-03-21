#include "utility_functions.hpp"
#include <cmath>



int main(){
    auto f=[](Point x){return x.first*x.second+4*std::pow(x.first,4) +std::pow(x.second,2) +3*x.first;};
    std::vector<std::function<double(Point)>> df;
    constexpr strategy S= strategy::Armijo;
    df.push_back([](Point x){return x.second+16*std::pow(x.first,3)+3;});
    df.push_back([](Point x){return x.first+2*x.second;});
    Parameters p(std::make_pair(0.0,0.0),1e-6,1e-6,1e6,0.1,0.5,0.2,f,df);

    Point res=Minimum(p, S);

    std::cout<< "\n\nPoint of minimum:  (" << res.first <<",  "<<res.second << ")"<<std::endl;
    std::cout<< "with value: "<< p.f(res)<<std::endl;
    return 0;
}