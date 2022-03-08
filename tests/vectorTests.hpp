#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "../include/vector.hpp"
# include "../include/utils.hpp"
# include <ctime>           //clock
# include <vector>

//============================ CONSTRUCTION TESTS ============================//
template <typename VectorClass>
bool    vector_construction(void)
{
//    VectorClass vec(count, data);

    // Default construction
    VectorClass dflt;
    // Default construction overload
    VectorClass empty(0);
    VectorClass emptyXdata(0, 100);
    VectorClass sizeOnly(100);
    VectorClass sizeXdata(100, 5);
    VectorClass large(1000000, 5);

    // Copy Construction
    VectorClass emptyCP(empty);
    VectorClass emptyXdataCP(emptyXdata);
    VectorClass sizeOnlyCP(sizeOnly);
    VectorClass sizeXdataCP(sizeXdata);
    VectorClass largeCP(large);


    // Equal overload

    return (true);
}

void    vector_construction_tests(void) {

    // Vector construction
    std::cout << "vector construction - ";
    if (vector_construction<ft::vector<int> >())
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;
    // others

}

template < typename Container >
double vector_construction_timed_tests(void) {
    clock_t begin, end;

    begin = clock();
    // Vector iterator construction
    vector_construction<Container>();
    // others
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}

//============================ ITERATOR TESTS ============================//
template <typename VectorClass>
bool    vector_iterator_construction(int count, int data)
{
    VectorClass vec(count, data);

    // Default construction
    typename VectorClass::iterator default_it;
    // Default construction overload
    typename VectorClass::iterator begin = vec.begin();
    if (*begin != data)
        return (false);
    // Copy Construction
    typename VectorClass::iterator copy_it(begin);
    if (*copy_it != data)
        return (false);
    // Equal overload
    default_it = begin;
    if (*default_it != data)
        return (false);

    return (true);
}

void    vector_iterator_tests(void) {

    // Vector iterator construction
    std::cout << "vector iterator construction - ";
    if (vector_iterator_construction<ft::vector<int> >(4, 100))
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;
    // others

}

template < typename Container >
double vector_iterator_timed_tests(void) {
    clock_t begin, end;

    begin = clock();
    // Vector iterator construction
    vector_iterator_construction<Container>(10, 1000);
    // others
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}

#endif
