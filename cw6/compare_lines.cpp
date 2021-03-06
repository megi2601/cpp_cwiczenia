#include <iostream>
#include <fstream>
#include <string>

typedef std::string str;


bool same_lines(str line1, str line2)
{
    return !line1.compare(line2);
}


void compare_and_write(std::ifstream& in1, std::ifstream& in2, std::ofstream& out)
{
    str line1, line2;
    while(std::getline(in1, line1) && std::getline(in2, line2))
    {
        if(same_lines(line1, line2))
        {
            out<<line1<<"\n";
        }

    }
}

void process_files(str in_file1, str in_file2, str out_file)
{
    std::ofstream out;
    std::ifstream in1, in2;
    in1.open(in_file1);
    in2.open(in_file2);
    out.open(out_file, std::ofstream::trunc);
    compare_and_write(in1, in2, out);
    out.close();
    in1.close();
    in2.close();
}

int main(int argc, char* argv[])
{
    process_files(argv[1], argv[2], argv[3]);
    return 0;
}