#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "../include/vector.hpp"
# include "../include/utils.hpp"
# include <ctime>           //clock

template <typename VectorClass>
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

template < typename Container >
double vector_iterator_tests(std::string color, std::string container) {
    clock_t begin, end;

    ft::display(color, container);
    begin = clock();
    // Vector iterator construction
    vector_iterator_construction<Container>(4, 100);
    // others

    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}

#endif
