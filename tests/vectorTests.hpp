#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "../include/vector.hpp"
# include "../include/utils.hpp"
# include <ctime>           //clock
# include <vector>

//============================ CONSTRUCTION TESTS ============================//
template <typename VectorClass>
bool    containers_equal(VectorClass A, VectorClass B, VectorClass C) {

    typedef typename VectorClass::size_type size_type;
    typedef typename VectorClass::iterator  iterator;

    //check size
    size_type Asize, Bsize, Csize;

    Asize = A.size();
    Bsize = B.size();
    Csize = C.size();
    if (Asize != Bsize || Asize != Csize || Bsize != Csize)
        return (false);

    //check items
    iterator Aiterator, Biterator, Citerator;
    Aiterator = A.begin();
    Biterator = B.begin();
    Citerator = C.begin();
    for (size_type i = 0; i < Asize; i++) {
        if (*(Aiterator + i) != *(Biterator + i)
            || *(Aiterator + i) != *(Citerator + i)
            || *(Biterator + i) != *(Citerator + i))
            return (false);
    }


    return (true);
}

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
    VectorClass emptyEQ, emptyXdataEQ, sizeOnlyEQ, sizeXdataEQ, largeEQ;

    emptyEQ = emptyCP;
    emptyXdataEQ = emptyXdataCP;
    sizeOnlyEQ = sizeOnlyCP;
    sizeXdataEQ = sizeXdataCP;
    largeEQ = largeCP;
    dflt = sizeXdataCP;

    if (!containers_equal(empty, emptyCP, emptyEQ)
        || !containers_equal(emptyXdata, emptyXdataCP, emptyXdataEQ)
        || !containers_equal(sizeOnly, sizeOnlyCP, sizeOnlyEQ)
        || !containers_equal(sizeXdata, sizeXdataCP, sizeXdataEQ)
        || !containers_equal(large, largeCP, largeEQ)
        || !containers_equal(dflt, sizeXdata, sizeXdataEQ))
        return (false);

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
    vector_construction<Container>();
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}

//============================ MODIFIER TESTS ============================//

template <typename VectorClass>
bool    vector_assign(void) {

    return (true);
}
void    vector_modifier_tests(void) {

    // Vector construction
    std::cout << "vector assign - ";
    if (vector_assign<ft::vector<int> >())
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;
    // others

}

template < typename Container >
double vector_modifier_timed_tests(void) {
    clock_t begin, end;

    begin = clock();
    vector_assign<Container>();
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
