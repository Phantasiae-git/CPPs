#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cerrno>
#include <iterator>

std::vector<int> jacobstahl(int ps, int struggler, int size)
{
    int pool=size-struggler;

    int b_nbr=(size/ps)/2;
    if((size/ps)%2==1)
        b_nbr++;
    
}

template <typename T> void FJ(T &cont, int pair_size)
{
    int pairs=cont.size()/pair_size;
    if(pairs<2)
        return;
    typedef typename T::iterator itr;

    itr start = cont.begin();

    for(int i=0; i<pairs; i++)
    {
        itr n1 = start + pair_size/2-1;
        itr n2 = start + pair_size-1;
        std::cout << "start: "<< *start << " n1: "<< *n1 << " n2: "<< *n2 << std::endl;
        if((*n1)>(*n2))
        {
            T tmp(n2-(pair_size/2-1), n2+1);
            std::copy((n1-(pair_size/2-1)), (n1+1), (n2-(pair_size/2-1)));
            std::copy(tmp.begin(), tmp.end(), (n1-(pair_size/2-1)));
        }
        if(i<(pairs-1))
            start+=pair_size;
    }
    std::cout << "recursion level "<< pair_size/2 << std::endl;
    itr a=cont.begin();
    while (a!=cont.end())
    {
        std::cout << *a << " ";
        a++;
    }
    std::cout << std::endl << std::endl;
    FJ(cont, pair_size*2);


    int struggler=cont.size()%pair_size;//how many numbers are left
    itr pool_end = cont.end()-struggler;//start of the struggler, not part of the pool
    (void)pool_end;//REMOVE THIS
    T main=cont;
    T pend;
    std::vector<int> order=jacobstahl(pair_size, struggler, cont.size());

}