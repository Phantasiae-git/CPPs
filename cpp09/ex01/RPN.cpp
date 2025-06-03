#include "RPN.hpp"

void rpn(std::string input)
{
    std::stack<long int> rpn;

    unsigned int i= 0;
    int right;
    int left;
    while(i<input.length())
    {
        if(input[i]!=' ')
        {
            if(isdigit(input[i]))
                rpn.push(input[i]-48);
            else
            {
                right=rpn.top();
                rpn.pop();
                left=rpn.top();
                rpn.pop();
                if(input[i]=='+')
                    rpn.push(left+right);
                if(input[i]=='-')
                    rpn.push(left-right);
                if(input[i]=='*')
                    rpn.push(left*right);
                if(input[i]=='/')
                {
                    if(right==0)
                    {
                        std::cerr << "do not divide by 0!" << std::endl;
                        return;
                    }
                    rpn.push(left/right);
                }
                // std::cout << rpn.top() << std::endl;
                // if(rpn.top()>2147483647 || rpn.top()< -2147483648)
                // {
                //     std::cerr << "result too long!" << std::endl;
                //     return;
                // }
            }
        }
        i++;
    }
    std::cout << rpn.top() << std::endl;
    //std::cout << rpn.size() << std::endl;
}