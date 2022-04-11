#include<iostream>
#include<string>

typedef std::string str;

int main(){
    str w1, w2, w3;
    std::cin>>w1>>w2>>w3;
    str Sentence = w1+" "+w2+" "+w3;
    std::cout<<Sentence<<std::endl;
    return 0;
}