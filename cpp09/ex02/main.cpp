#include "PMergeMe.hpp"

void check_args(std::string str, std::vector<int> &numbers, int i)
{
    if(str.find_first_not_of("1234567890")!=std::string::npos)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    long n = strtol(str.c_str(), NULL, 10);
    if (errno==ERANGE || n>2147483647 || n<1)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    //std::cout << n << std::endl;
    numbers[i]=n;
}

int main(int argc, char **argv)
{
    if(argc<2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<std::string> args;
    if(argc==2)
    {
        std::string s;
        std::istringstream str(argv[1]);
        while (std::getline(str, s, ' '))
            args.push_back(s);
    }
    else
    {
        for(int i=1; i<argc; i++)
            args.push_back(argv[i]);
    }

    std::vector<int> numbers(args.size());
    for(unsigned int i=0; i<args.size(); i++)
        check_args(args[i], numbers, i);
    
    FJ(numbers, 2);
}