#include "BitcoinExchange.hpp"

std::map<std::string, float> get_db(std::string &path)
{
    std::ifstream	file(path.c_str());
    std::map<std::string, float> db;
    
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t sep = line.find(',');

        std::string dateStr = line.substr(0, sep);
        std::string rateStr = line.substr(sep + 1);

        float rate = atof(rateStr.c_str());
        db[dateStr] = rate;
    }
    file.close();
    return db;
}

int parseDate(std::string date)
{
    struct tm tm;

    if(strptime(date.c_str(), "%Y-%m-%d", &tm)==NULL)
    {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return 1;
    }
    return 0;
}

int parseValue(std::string rate)
{
    if(rate.find_first_not_of("-0123456789.")!=std::string::npos)
    {
        std::cerr << "Error: invalid rate => " << rate << std::endl;
        return 1;
    }

    if(rate.find_first_of("-")==std::string::npos || (rate.find_first_of("-")!=std::string::npos && rate.find_first_of("-")==rate.find_last_of("-") && rate.find_first_of("-")==0))
    {
        if(rate.find_first_of(".")==std::string::npos || (rate.find_first_of(".")!=std::string::npos && rate.find_first_of(".")==rate.find_last_of(".") && rate.find_first_of(".")!=(rate.length()-1)))
        {
            if(atof(rate.c_str())>1000)
            {
                std::cerr << "Error: too large a number." << std::endl;
                return 1;
            }
            if(atof(rate.c_str())<0)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                return 1;
            }
            else
                return 0;
        }
    }
    std::cerr << "Error: invalid rate => " << rate << std::endl;
    return 1;
}

void exchange(std::map<std::string, float> db, char *path)
{
    std::ifstream	file(path);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);
    if(line!="date | value")
    {
        std::cerr << "Error: invalid headline." << std::endl;
        exit(1);
    }
    while (std::getline(file, line)) {
        size_t sep = line.find('|');
        if(sep==std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string dateStr = line.substr(0, sep-1);
        if(dateStr.find_first_not_of("-0123456789")!=std::string::npos)
        {
            std::cerr << "Error: invalid date => " << dateStr << std::endl;
            continue;
        }
        std::string valueStr = line.substr(sep + 2);

        if(!parseDate(dateStr) && !parseValue(valueStr))
        {
            float value = atof(valueStr.c_str());
            std::map<std::string, float>::iterator it= db.find(dateStr);
            if(it==db.end())
            {
                it=db.upper_bound(dateStr);
                it--;
            }
            std::cout << dateStr << " => " << value << " = " << (value*it->second) << std::endl;
        }
    }
    file.close();
}