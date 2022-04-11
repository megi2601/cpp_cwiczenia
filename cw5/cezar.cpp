#include<iostream>
#include<string>
#include<tuple>
#include<fstream>

typedef std::string str;
typedef std::tuple<int, str> tuple;

str encodeStr(tuple x){
    int n = std::get<0>(x); str mess = std::get<1>(x);
    str encoded;
    for(int i=0; i< mess.size();i++){   //for(char i:str)
        if('A'<=mess[i] && mess[i]<='Z'){encoded+=char('A'+(mess[i]-'A'+n)%('Z'-'A'+1));}
        else if('a'<=mess[i] && mess[i]<='z'){encoded +=char('a'+(mess[i]-'a'+n)%('z'-'a'+1));}
        else {encoded+=mess[i];}
    }
    return encoded;
}


void encodeFile(str in_file, str out_file, int shift){
    std::ofstream out; std::ifstream in; // out("endoded.txt")
    str x;
    in.open(in_file);
    out.open(out_file);
    while(std::getline(in, x)){
        str encoded = encodeStr(tuple{shift, x});
        out<<encoded+"\n";
    }
    in.close();
    out.close();
}

// pierwszy argument - plik źródłowy txt, drugi - plik wyjściowy txt, trzeci - o ile przesunięcie

int main(int argc, char *argv[]){
    int n;
    str str_n = argv[3];
    n = std::stoi(str_n);
    encodeFile(argv[1], argv[2], n);
}
