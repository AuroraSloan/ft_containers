#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <iostream>
#include <vector>
#include <ctime>           //clock
#include <time.h>
#include "utils.hpp"

void    vector_iterator_construction(int count, int data)
{
    VectorClass vec(count, data);
    //vec.push_back(55);

    ft::display( "default construct - ");
    typename VectorClass::iterator default_it;
    ft::display(GREEN, "SUCCESS\n");


    ft::display( "copy assign - ");
    typename VectorClass::iterator begin = vec.begin();
    typename VectorClass::iterator end= vec.end();
    (begin == vec.begin() && end == vec.end()) ? ft::display(GREEN, "SUCCESS\n") : ft::display(RED, "FAILURE\n");

    ft::display( "copy construct - ");
    typename VectorClass::iterator copy_it(begin);
    copy_it == vec.begin() ? ft::display(GREEN, "SUCCESS\n") : ft::display(RED, "FAILURE\n");

    return ;
}

template < typename F >
void ft_test(std::string testName, F test) {
    ft::write(SUBHDR + testName + SUBHDR + '\n');

}

void vectorTests(void) {
    ft::write(MAGENTA, HDR + std::string(" Vector Tests ") + HDR + RESET + '\n');
    ft_test("vector_iterator_constructor", vector_iterator_construction)
    ft::display(CYAN, "\tSTD\n");
    clock_t begin = clock();
    vector_iterator_construction<std::vector<int> >(4, 100);
    double  stdtime = ((double)(clock() - begin)) / CLOCKS_PER_SEC;
    ft::display(CYAN, "\tFT\n");
    begin = clock();
    vector_iterator_construction<ft::vector<int> >(4, 100);
    double  fttime = ((double)(clock() - begin)) / CLOCKS_PER_SEC;
    if (stdtime < fttime)
    {
        int ratio = (int)(fttime/stdtime);
        std::string color = ratio > 20 ? RED : YELLOW;
        ft::write(color + std::string("std is "), ratio, "x faster\n");
    }
    else
        ft::write(GREEN + std::string("ft is "), (int)(stdtime/fttime), "x faster\n");

    return ;
}

int main(void)
{
    vectorTests();

 //   vector_iterator_example(4, "hey");


/*    std::cout << "int vector\n";
    std::cout << *it << '\n';
    std::cout << *it + 1 << '\n';
    std::cout << *it << '\n';
    std::cout << *--e << '\n';
    std::cout << *it + *e << '\n';
    std::cout << (it - e) << '\n';;
    std::cout << *(it + 1) << '\n';
    std::cout << "str vector\n";*/
    std::vector<std::string> sstdvec(4, "hey");
    sstdvec.push_back("bye");
    std::vector<std::string>::iterator sit = sstdvec.begin();
    std::vector<std::string>::iterator se = sstdvec.end();
    std::cout << *sit << '\n';
    std::cout << *sit + "yes" << '\n';
    std::cout << *sit << '\n';
    std::cout << *--se << '\n';
    std::cout << *sit + *se << '\n';

   // std::cout << (it + e) << '\n';
    //std::cout << "std size: " << stdvec.size() << std::endl;
    //std::cout << "ft size: " << vec.size() << std::endl;
    //std::cout << "std capacity: " << stdvec.capacity() << std::endl;
    //std::cout << "ft capacity: " << vec.capacity() << std::endl;
//    for (std::vector<int>::iterator stdit = stdvec.begin(); stdit != stdvec.end(); stdit++)
 //       std::cout << "stdit: " << *stdit << '\n';
    //for (ft::vector<int>::iterator ftit = vec.begin(); ftit != vec.end(); ftit++)
    //    std::cout << "ftit: " << *ftit << '\n';
    //std::cout << *vec._vec << std::endl;
    //std::cout << stdvec.max_size() << '\n';
//    std::cout << vec.var << std::endl;

    //std::allocator<int> j = std::allocator<int>();
    //int* arr = j.allocate(1);
    //j.construct(arr, 0);
    /*ft::map<int, int> map;
    std::cout << map.var << std::endl;
    ft::stack<int> stack;
    std::cout << stack.var << std::endl;*/


    return (0);
}
