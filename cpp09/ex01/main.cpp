#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc!=2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    unsigned int i= 0;
    std::string input(argv[1]);
    if(input.find_first_not_of("0123456789 *+/-")!= std::string::npos)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    int operands=0;
    int operators=0;
    while (i<input.length())
    {
        // std::cout << i << std::endl;
        if(i==0 && !isdigit(input[i]))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        if(i%2==1 && input[i]!=' ')
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        if(i==(input.length()-1))
        {
            if(input[i]!='+' && input[i]!='-' && input[i]!='*' && input[i]!='/')
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
        if(isdigit(input[i]))
            operands++;
        if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/')
            operators++;
        i++;
    }
    if(operands!=(operators+1))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    rpn(input);
}