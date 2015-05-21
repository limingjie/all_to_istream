//
// All to istream
//
// Process standard input, file or string as istream, to simplify support to
// different inputs.
//
// May 21, 2015 - by Mingjie Li (limingjie@outlook.com)
// https://github.com/limingjie/all_to_istream
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

void read_istream(std::istream &is)
{
    char c;

    while (is.get(c))
    {
        std::cout << c;
    }

    std::cout.flush();
}

void read_std_input()
{
    std::cerr << "Info: read_std_input" << std::endl;

    read_istream(std::cin);
}

void read_file(const std::string &filename)
{
    std::ifstream ifs(filename);

    if (ifs)
    {
        std::cerr << "Info: read_file" << std::endl;

        read_istream(ifs);
    }
    else
    {
        std::cerr << "Error: fail to open file " << filename << std::endl;
    }

    ifs.close();
}

void read_string(const std::string &data)
{
    std::cerr << "Info: read_string" << std::endl;

    std::stringstream ss(data);
    read_istream(ss);
}

int main(int argc, char *argv[])
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
