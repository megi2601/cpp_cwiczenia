#include <iostream>
#include <cmath>
#include <tuple>

std::tuple<double, double, int> solveQuad(double a, double b, double c){
    double delta = b*b -4*a*c;
    double epsilon = 1.0e-10;
    double x1, x2;
    int solutions;
    if(delta>epsilon){
        x1=(-b+sqrt(delta))/(2*a);
        x2=(-b+sqrt(delta))/(2*a);
        solutions=2;
    }
    else if(epsilon>=delta>=-epsilon){
        x1 = -b/(2*a);
        x2 = x1;
        solutions=1;
    }
    else{
        solutions = 0;
        x1 = 0.0;
        x2= 0.0;
    }
    return std::tuple<double, double, int>{x1, x2, solutions};
}

void printQuad(const std::tuple<double, double, int> & aSolution){
    std::cout<<"x1= "<<std::get<0>(aSolution)<<", x2= "<<std::get<1>(aSolution)
    <<", number of solutions= "<<std::get<2>(aSolution)<<std::endl;
}

double a=1.0, b=2.0, c=-3.0;

int main(){
    std::tuple<double, double, int> sol = solveQuad(a, b, c);
    printQuad(sol);
}
