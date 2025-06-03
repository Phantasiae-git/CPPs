#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>
#include <fstream>

std::map<std::string, float> get_db(std::string &path);
void exchange(std::map<std::string, float> db, char *path);