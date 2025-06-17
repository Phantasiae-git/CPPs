#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>
#include <fstream>

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

std::map<std::string, float> get_db(std::string &path);
void exchange(std::map<std::string, float> db, char *path);

#endif