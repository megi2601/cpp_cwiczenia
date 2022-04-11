#include <iostream>

double sum1(double a, double b){
    return b+=a;
}

double sum2(double &a, double &b){
    return b+=a;
}

double sum3(const double a, const double b){
    return b+a;
}

double a = 1.0, b=2.0;

int main(){
    std::cout<<sum1(a, b)<<"\n"<<sum2(a, b)<<"\n"<<sum3(a, b)<<"\n";
}
