#include<iostream>
#include<string>

typedef std::string str;

// int main(){
//     for(char i = ' '; i<'~';++i) std::cout<<int(i)<<':'<<' '<<i<<std::endl;
// }

int main(){
    str word;
    std::cin>>word;
    for(int i=0; i< word.size();i++){
        std::cout<<word[i]<<' '<<typeid(int(word[i])).name()<<std::endl;
    }
}