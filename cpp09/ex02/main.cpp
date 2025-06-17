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

	std::cout << "Before:  ";
	for(std::vector<int>::iterator it=numbers.begin(); it!= numbers.end(); it++)
		std::cout << *it << " ";
    std::cout << std::endl;

	std::deque<int> deque;
	for(unsigned int i = 0; i<numbers.size(); i++)
		deque.push_back(numbers[i]);

	unsigned long start_v= timern();
    FJ<std::vector<int> >(numbers, 2);
	unsigned long end_v= timern();

	std::cout << "After:  ";
    for(std::vector<int>::iterator it=numbers.begin(); it!= numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	unsigned long start_d= timern();
	 FJ<std::deque<int> >(deque, 2);
	unsigned long end_d= timern();

	// std::cout << "After (deque):  ";
    // for(std::vector<int>::iterator it=numbers.begin(); it!= numbers.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector: " << (end_v-start_v) << " us" << std::endl;
	std::cout << "Time to process a range of " << numbers.size() << " elements with std::deque: " << (end_d-start_d) << " us" << std::endl;
}