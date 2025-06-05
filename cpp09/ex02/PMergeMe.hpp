#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cerrno>
#include <iterator>

template <typename T> void FJ(T &cont, int pair_size)
{
    int pairs=cont.size()/pair_size;
    if(pairs<2)
        return;
    int struggler=cont.size()%pair_size;//how many numbers are left

    typedef typename T::iterator itr;

    itr start = cont.begin();
    itr pool_end = cont.end()-struggler;//start of the struggler, not part of the pool

    for(int i=0; i<pairs; i++)
    {
        itr n1 = start + pair_size/2-1;
        itr n2 = start + pair_size-1;
        std::cout << "start: "<< *start << " n1: "<< *n1 << " n2: "<< *n2 << std::endl;
        if((*n1)>(*n2))
        {
            itr range_s = (n1-(pair_size/2-1));
            itr range_e = (n1+1);
            itr paste_s = (n2-(pair_size/2-1));
            T tmp(n2-(pair_size/2-1), n2+1);
            std::copy(range_s, range_e, paste_s);
            std::copy(tmp.begin(), tmp.end(), range_s);
        }
        if(i<(pairs-1))
            start+=pair_size;
    }
    // std::cout << "recursion level "<< pair_size/2 << std::endl;
    // itr a=cont.begin();
    // while (a!=cont.end())
    // {
    //     std::cout << *a << " ";
    //     a++;
    // }
    // std::cout << std::endl << std::endl;
    (void)pool_end;//REMOVE THIS
    FJ(cont, pair_size*2);
}