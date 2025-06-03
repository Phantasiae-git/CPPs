#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc!=2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    std::string path="data.csv";
    std::map<std::string, float> db=get_db(path);

    // std::map<std::string, float>::iterator it= db.begin();

    // while(it!=db.end())
    // {
    //     std::cout << it->first << " "<<it->second<< std::endl;
    //     it++;
    // }
    exchange(db, argv[1]);
}