#include <sys/time.h>
#include <iostream>
#include <vector>

unsigned long	timern(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

std::vector<int> jacobstahl(int ps, int size)//organic jacobstahl (+regression), actual index will be -1
{
    std::vector<int> order;
    unsigned int elements= size/ps;
    if (elements<1)
        return order;
    order.push_back(1);
    if(elements==1)
        return order;
    if (elements >=2)
        order.push_back(3);
    int prev= 3;
    int prev1= 1;
    //std::cout << "order size= " << order.size() << " elements: " << elements << std::endl;
    while(order.size()<elements) {
        int back=prev;
        while(--back>prev1 && order.size()<elements)
            order.push_back(back);
        if(order.size()==elements) break;
        int next = prev + 2 * prev1;
        order.push_back(next);
        prev1=prev;
        prev=next;
    }
            //std::cout << "prev= " << prev << " elements: " << elements << std::endl;
    if(prev>(int)elements)
    {
        //std::cout << "prev= " << prev << " elements: " << elements << std::endl;
        std::vector<int>::iterator ceil_it = order.begin();
        while ((*ceil_it)!=prev)
            ceil_it++;
        int diff=0;
        while (*ceil_it>((int)elements))
        {
            (*ceil_it)--;
            diff++;
        }
        while (++ceil_it!=order.end())
            (*ceil_it)-=diff;
    }
    // std::vector<int>::iterator it=order.begin();
    // std::cout << "--------JACOBSTAHL: ";
    // while (it!=order.end())
    // {
    //     std::cout << *it << " ";
    //     it++;
    // }
    return order;
}