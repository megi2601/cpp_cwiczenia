#include <iostream>
#include <string>
#include <fstream>

typedef std::string str;


int main(int argc, char*argv[]){
    std::ofstream out;
    out.open(argv[2], std::ios_base::app);
    out << argv[1]<<"\n";
    out.close();
    return 0;
}

// int main(int argc, char *argv[]){
//     for(int i; i<argc;i++){std::cout<<*(argv+i)<<" x "<<argv[i]<<std::endl;}
// }