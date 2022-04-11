#include <iostream>
#include <string>

typedef std::string str;

str get_input(){
    str my_str;
    std::cin>>my_str;
    return my_str;
}

void change_word(str& word, const str old, const str my_new){
    try{
        int pos = word.find(old);
        int len = old.length();
        word.replace(pos, len, my_new);
    }
    catch(std::out_of_range){}
}


int main(){
    str word = get_input();
    change_word(word, "rz", "z");
    std::cout<<word<<std::endl;
    return 0;
}