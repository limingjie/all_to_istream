//
// All to istream
//
// Process standard input, file or string as istream, to simplify support to
// different inputs.
//
// Author - Mingjie Li
// Email  - limingjie@outlook.com
// Date   - May 21, 2015
// Github - https://github.com/limingjie/all_to_istream
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void usage()
{
    std::cerr
        << "Usage: all_to_istream\n"
        << "   or: all_to_istream FILE\n"
        << "   or: all_to_istream -s STRING\n"
        << "   or: all_to_istream -h\n"
        << "Process standard input, file or string as istream, "
        << "to simplify support to different inputs."
        << std::endl;
}

void read_istream(std::istream &in)
{
    char c;

    while (in.get(c))
    {
        std::cout << c;
    }
}

void read_std_input()
{
    std::cerr << "read_std_input" << std::endl;

    read_istream(std::cin);
}

void read_file(const std::string &filename)
{
    std::cerr << "read_file" << std::endl;

    std::ifstream file(filename);
    if (file)
    {
        read_istream(file);
    }
    else
    {
        usage();
    }

    file.close();
}

void read_string(const std::string &data)
{
    std::cerr << "read_string" << std::endl;

    std::stringstream ss(data);
    read_istream(ss);
}

int main(int argc, char const *argv[])
{
    switch (argc)
    {
    case 1:
        read_std_input();
        break;
    case 2:
        if (argv[1][0] == '-')
        {
            usage();
        }
        else
        {
            read_file(argv[1]);
        }
        break;
    case 3:
        if (std::string(argv[1]) == "-s")
        {
            read_string(argv[2]);
        }
        else
        {
            usage();
        }
        break;
    default:
        usage();
    }

    return 0;
}
