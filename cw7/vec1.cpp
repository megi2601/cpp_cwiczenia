#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<double> my_vec;
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
std::vector<double> getXValues(unsigned int nPoints, double xMin, double xMax){
  std::vector<double> x;
  double h = (xMax - xMin)/(nPoints -1);
  for(unsigned int i=0;i<nPoints;++i){
    x.push_back(xMin + h*i);
  }
  return x;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
double calculateIntegral(my_vec x, my_vec y){
    double len = x[1]-x[0];
    double area = 0.0;
    for(int i=1; i<=x.size(); i++){
        area += 0.5*len * (y[i-1]+y[i]);
    }
    return area;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
std::vector<double> getFunctionValues(const std::vector<double> & x){

  std::vector<double> y;
  for(unsigned int i=0;i<x.size();++i){
    y.push_back(sin(x[i])*sin(x[i]));
  }
  return y;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
double getMean(const std::vector<double> & x){

  if(!x.size()) return 0.0;

  double sum = 0.0;
  for(unsigned int i=0;i<x.size();++i){
    sum += x[i];
  }
  sum /= x.size();
  return sum;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
double getVariance(const std::vector<double> & x){

  double sum2 = 0.0;
  for(unsigned int i=0;i<x.size();++i){
    sum2 += x[i]*x[i];
  }
  sum2 /= x.size();
  double mean = getMean(x);
  return sum2 - mean*mean;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int main() {

  unsigned int nPoints = 20000;
  double xMin = 0;
  double xMax = 2*M_PI;
  std::vector<double> x = getXValues(nPoints, xMin, xMax);
  std::vector<double> y = getFunctionValues(x);
  double mean = getMean(y);
  double variance = getVariance(y);
  std::cout<<"Mean = "<<mean<<" variance: "<<variance<<std::endl;
//   std::cout<<"Expected values: "<<std::endl;
//   mean = 2.0/M_PI;
//   variance = 0.5 - 4.0/M_PI/M_PI;
//   std::cout<<"Mean = "<<mean<<" variance: "<<variance<<std::endl;
  double area = calculateIntegral(x, y);
  std::cout<<"Area = "<<area<<std::endl;
  return 0;
}
