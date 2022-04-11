#include <iostream>
#include <tuple>

typedef std::tuple<double, double, double> my_tuple;

my_tuple getInput(){
    double a, b, c;
    std::cin>>a>>b>>c;
    return my_tuple{a, b, c};
}

double getMax(my_tuple t){
    double a = std::get<0>(t);
    double b = std::get<1>(t);
    double c = std::get<2>(t);
    if(a<b){
        double p = a;
        a=b;
        b=p;
    }
    if(c>a){
        double p = a;
        a=c;
        c=p;
    }
    return a;
}

int main(){
    my_tuple liczby = getInput();
    std::cout<<getMax(liczby)<<std::endl;
}