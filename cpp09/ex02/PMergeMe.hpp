#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <deque>
#include <cerrno>
#include <iterator>

std::vector<int> jacobstahl(int ps, int size)//organic jacobstahl (+regression), actual index will be -1
{
    std::vector<int> order;
    unsigned int elements= size/ps;
    if (elements<1)
        return order;
    order.push_back(1);
    if(elements==1)
        return order;
    if (elements >2)
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
    if(prev>(int)elements+1)
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

template <typename T, typename itr> void insert_m(itr s, itr e, int idx, T &main)//insert range ("pair") in main at index
{
    itr paste_s = main.begin()+idx;
    while (s!=e)
    {
        main.insert(paste_s, *s);
        paste_s++;
        s++;
    }
}

template <typename T>  void do_insertion(T &cont, int pair_size, int pairs)
{
    typedef typename T::iterator itr;
    int b_nbr=pairs/2;
    if(pairs%2==1)
        b_nbr++;
    //std::cout << "pairs: "<< pairs << " b nbr: " << b_nbr << std::endl;
    T pend(b_nbr*(pair_size));
    T main(cont.size()-pend.capacity());

    //     std::cout << "recursion level "<< pair_size << std::endl;
    // itr a=cont.begin();
    // while (a!=cont.end())
    // {
    //     std::cout << *a << " ";
    //     a++;
    // }
    // std::cout << std::endl;
    itr b_s=cont.begin();
    itr paste_p=pend.begin();
    itr paste_m=main.begin();
    //if b_nbr>1
    for(int i=0; i<b_nbr; i++)
    {
        itr b_e= b_s + pair_size;//not included/ past the end of b
        //std::cout << "b_s: " << *b_s << " b_e: " << *(b_e-1) << " pair size :" << pair_size << " pend capacity: " << pend.capacity() << std::endl;
        std::copy(b_s, b_e, paste_p);
        if(!(pairs%2==1 && i==(b_nbr-1)))
        {
            //std::cout << "HELLOOOOOOOOOOOOOOOOOOOOOOO " << i << std::endl;
            b_s=b_e+ pair_size;//start (included) of the next b is also end (not included) of the next a
            std::copy(b_e, b_s, paste_m);//b_e=a_s, b_s=a_e
            //std::cout << "b_s: " << *(b_s-1) << " b_e: " << *b_e << " pair size :" << pair_size << " pend capacity: " << pend.capacity() << std::endl;
            paste_m+=pair_size;
        }
        paste_p+=pair_size; 
    }
    int struggler=cont.size()%pair_size;//how many numbers are left
    itr pool_end = cont.end()-struggler;//start of the struggler, not part of the pool
    
    while(paste_m!=main.end())//adding leftover numbers to end of main
    {
        std::copy(pool_end, pool_end+1, paste_m);
        paste_m++;
        pool_end++;
    }
    // itr idk = pend.begin();
    // std::cout << "pend: " << std::endl;
    // while (idk!=pend.end())
    // {
    //     std::cout << *idk << " ";
    //     idk++;
    // }
    // std::cout << std::endl;

    // idk = main.begin();
    // std::cout << "main: " << std::endl;
    // while (idk!=main.end())
    // {
    //     std::cout << *idk << " ";
    //     idk++;
    // }
    // std::cout << std::endl;
    cont= main;
    std::vector<int> order=jacobstahl(pair_size, pend.size());
    order.erase(order.begin());
    b_s=pend.begin();
    itr b_e=b_s+pair_size;

    insert_m(b_s, b_e, 0, cont);//insert b1 in main
    // idk = cont.begin();
    // std::cout << "main (cont): " << std::endl;
    // while (idk!=cont.end())
    // {
    //     std::cout << *idk << " ";
    //     idk++;
    // }
    std::vector<int>::iterator order_it=order.begin();

    //std::cout << "INSERTION: " << std::endl;

    std::vector<int> idxs;
    int count=1;
    T small_main;
    small_main.push_back(cont[pair_size-1]);
    for(int as=0; as<(pairs-b_nbr); as++)//tracks the indexes of the As
    {
        small_main.push_back(cont[pair_size*(count+1)-1]);//making a small main out of every nth element (n being pair_size) to apply lower_bound on.
        idxs.push_back(count);
        count++;
    }
    if(pairs%2==1)
        idxs.push_back(count);

    //PRINTS
    // std::vector<int>::iterator idxs_it= idxs.begin();//EACH INDEX IS LEFTMOST ELEMENT OF A X = index * pair_size, so index 3 means ax actually starts at pair_size*3
    // while (idxs_it!=idxs.end())
    // {
    //     //std::cout << "index: " << *idxs_it << std::endl;
    //     idxs_it++;
    // }


    while (order_it!=order.end())
    {
        // idk = pend.begin();
        // std::cout << "pend: " << std::endl;
        // while (idk!=pend.end())
        // {
        //     std::cout << *idk << " ";
        //     idk++;
        // }
        //std::cout << std::endl;
        b_e=pend.begin()+pair_size*(*order_it);
        //std::cout << "hello " << *order_it << " " << *(b_e-1) << std::endl;
        b_s=b_e-pair_size;
        //std::cout <<"b_s: "<< *b_s <<std::endl;



        int pool_end= idxs[(*order_it)-1];
        //std::cout <<"pool end: "<< pool_end <<std::endl;
        itr ins_pos=std::lower_bound(small_main.begin(), small_main.begin()+pool_end, *(b_e-1));
        int ins_idx=std::distance(small_main.begin(), ins_pos)*pair_size;
        //std::cout << "FINAL INSERTION INDEX: " << ins_idx << std::endl;
        insert_m(b_s, b_e, ins_idx, cont);

        //itr small_main_it =small_main.begin();
        // std::cout << "small main: " << std::endl;
        // while(small_main_it!=small_main.end())
        // {
        //     std::cout << *small_main_it << std::endl;
        //     small_main_it++;
        // }

        small_main.insert(ins_pos, *(b_e-1));
        // idk = cont.begin();
        // std::cout << "main (cont): " << std::endl;
        // while (idk!=cont.end())
        // {
        //     std::cout << *idk << " ";
        //     idk++;
        // }
        //std::cout << "ins_idx/pair_size=" << ins_idx/pair_size << std::endl;
        std::vector<int>::iterator idxs_it= idxs.begin();//only the As from ins_idx on moved forward (by pair size)
        //std::cout << "UPDATED INDEXES: " << std::endl;
        while(idxs_it!=idxs.end())//updating indexes of As that moved
        {
            if(*idxs_it>=(ins_idx/pair_size))
                break;
            idxs_it++;
        }
        while (idxs_it!=idxs.end())
        {
            (*idxs_it)++;
            //std::cout << "index number " << std::distance(idxs.begin(), idxs_it) << ": " << *idxs_it << std::endl;
            idxs_it++;
        }
        

        // for(idxs_it=idxs.begin()+ins_idx/pair_size; idxs_it!=idxs.end(); idxs_it++)
        //     (*idxs_it)++;
        order_it++;
    }
}

template <typename T> void FJ(T &cont, int pair_size)
{
    int pairs=cont.size()/pair_size;
    // int pairs_f=cont.size()/(pair_size/2);//this is a surpirse tool that can help us later! ;) because i messed up the recursion

    if(pairs<1)
        return;
    typedef typename T::iterator itr;
    //std::cout << "pairs: " <<pairs << std::endl;
    itr start = cont.begin();

    for(int i=0; i<pairs; i++)
    {
        itr n1 = start + pair_size/2-1;
        itr n2 = start + pair_size-1;
        //std::cout << "start: "<< *start << " n1: "<< *n1 << " n2: "<< *n2 << std::endl;
        if((*n1)>(*n2))
        {
            T tmp(n2-(pair_size/2-1), n2+1);
            std::copy((n1-(pair_size/2-1)), (n1+1), (n2-(pair_size/2-1)));
            std::copy(tmp.begin(), tmp.end(), (n1-(pair_size/2-1)));
        }
        if(i<(pairs-1))
            start+=pair_size;
    }
    // std::cout << "recursion level "<< pair_size << std::endl;
    // itr a=cont.begin();
    // while (a!=cont.end())
    // {
    //     std::cout << *a << " ";
    //     a++;
    // }
    // std::cout << std::endl << std::endl;

    FJ(cont, pair_size*2);

    // pair_size/=2;
    // pairs=pairs_f;

    do_insertion(cont, pair_size, pairs);
    if(pair_size==2)
        do_insertion(cont, 1, cont.size());
}