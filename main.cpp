#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <iostream>
#include <vector>

#define RED '\u001b[31m'
#define GREEN '\u001b[32m'
#define RESET '\u001b[0m'

void    ft_write(std::string color, std::string message)
{
    std::cout << color + message << RESET + '\n';
    return ;
}

void    ft_write(std::string color, int x)
{
    std::cout << color << x << RESET << '\n';
    return ;
}

void    vector_iterator_example(int count, int data)
{
    std::vector<int> vec(count, data);
    vec.push_back(55);

    ft_write(GREEN, "default constructed");
    std::vector<int>::iterator default_it;
    ft_write(GREEN, "copy assigned");
    std::vector<int>::iterator begin = vec.begin();
    std::vector<int>::iterator end= vec.end();
    (begin == vec.begin() && end == vec.end()) ? ft_write(GREEN, "copy assigner success") : ft_write(RED, "copy assigner failure") :
    ft_write(GREEN, "copy constructed");
    std::vector<int>::iterator copy_it(begin);
    copy_it == begin ? ft_write(GREEN, "copy constructor success") : ft_write(RED, "copy constructor failure") :
}

int main(void)
{
    vector_iterator_example(4, 100);
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
