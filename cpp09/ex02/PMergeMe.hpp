#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cerrno>

template <typename T> void FJ(T &cont, int pair_size)
{
    int pairs=cont.size()/pair_size;
    if(pairs<2)
        return;
    int struggler=cont.size()%pair_size;//how many numbers are left

    typedef typename T::iterator itr;

    itr start = cont.begin();
    itr pool_end = cont.end()-struggler;
    
}