#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "../include/vector.hpp"
# include "../include/utils.hpp"
# include "testUtils.hpp"
# include <ctime>           //clock
# include <vector>

template <typename ftContainer, typename stdContainer>
bool    containers_equal(ftContainer & vec, stdContainer & comp) {

    typedef typename ftContainer::size_type size_type;
    typename ftContainer::iterator  vecIterator;
    typename stdContainer::iterator compIterator;

    //check size
    size_type vecSize, compSize;
    vecSize = vec.size();
    compSize = comp.size();
    if (vecSize != compSize)
        return (false);



   /*if ((unsigned long)vec.capacity() != comp.capacity())
        std::cout << "my capacity " << vec.capacity() << " comp capacity " << comp.capacity() << '\n';*/

    //check items
    vecIterator = vec.begin();
    compIterator = comp.begin();
    for (size_type i = 0; i < vecSize; i++) {
        if (*(vecIterator + i) != *(compIterator + i))
            return (false);
    }
    while (vecIterator != vec.end() && compIterator != comp.end()) {
        if ((*(vecIterator) != *(compIterator)) || vecIterator == vec.end() || compIterator == comp.end())
            return (false);
        vecIterator++;
        compIterator++;
    }
    return (true);
}

//============================ CONSTRUCTION TESTS ============================//
template <typename VectorClass>
bool    containers_equal(VectorClass & A, VectorClass & B, VectorClass & C) {

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

template < typename Container >
double vector_construction_timed_tests(void) {
    clock_t begin, end;

    begin = clock();
    vector_construction<Container>();
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}

void    vector_construction_tests(void) {
    double stdtime, fttime;

    std::cout << CYAN << '\t' << SUBHDR << "Construction Tests" << SUBHDR << RESET << '\n';
    std::cout << "vector construction - ";
    if (vector_construction<ft::vector<int> >())
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;
    stdtime = vector_construction_timed_tests<std::vector<int> >();
    fttime = vector_construction_timed_tests<ft::vector<int> >();
    print_results(stdtime, fttime);
}

//============================ MODIFIER TESTS ============================//

template <typename VectorClass>
bool    vector_assign() {
    typedef typename VectorClass::size_type size_type;
    VectorClass         myvec(10, 100);
    std::vector<int>    comp(10, 100);

    // void  assign(size_type n, value_type const & val)
    myvec.assign(10, size_type(35));
    comp.assign(10, size_type(35));
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.assign(1, size_type(3700));
    comp.assign(1, size_type(3700));
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.assign(100, size_type(17));
    comp.assign(100, size_type(17));
    if (!containers_equal(myvec, comp))
        return (false);

    //template <class InputIterator>
    //void assign(InputIterator first, InputIterator last)
    VectorClass         newvec(30, 7);
    std::vector<int>    newcomp(30, 7);

    typename VectorClass::iterator vecs = newvec.begin();
    typename VectorClass::iterator vece = newvec.end();
    std::vector<int>::iterator comps = newcomp.begin();
    std::vector<int>::iterator compe = newcomp.end();
    myvec.assign(vecs, vece);
    comp.assign(comps, compe);
    if (!containers_equal(myvec, comp))
        return (false);

    VectorClass         largervec(400, 987654);
    std::vector<int>    largercomp(400, 987654);
    vecs = largervec.begin();
    vece = largervec.end();
    comps = largercomp.begin();
    compe = largercomp.end();
    myvec.assign(vecs, vece);
    comp.assign(comps, compe);
    if (!containers_equal(myvec, comp))
        return (false);
    return (true);
}
template <typename VectorClass>
bool    vector_push_back() {
    VectorClass         myvec;
    VectorClass         myvec2(10, 555);
    std::vector<int>    comp;
    std::vector<int>    comp2(10, 555);

    myvec.push_back(-4444);
    comp.push_back(-4444);
    if (!containers_equal(myvec, comp))
        return (false);
    for (int i = 0; i < 50; i++) {
        myvec.push_back(i);
        comp.push_back(i);
    }
    if (!containers_equal(myvec, comp))
        return (false);
    myvec2.push_back(987654);
    comp2.push_back(987654);
    if (!containers_equal(myvec2, comp2))
        return (false);

    return (true);
}

template <typename VectorClass>
bool    vector_pop_back() {
    VectorClass         myvec(30, 999);
    VectorClass         myvec2;
    std::vector<int>    comp(30, 999);

    myvec.pop_back();
    comp.pop_back();
    if (!containers_equal(myvec, comp))
        return (false);

    for (int i = 0; i < 29; i++) {
        myvec.pop_back();
        comp.pop_back();
    }
    if (!containers_equal(myvec, comp))
        return (false);
    myvec2.pop_back();
    if (!containers_equal(myvec, comp))
        return (false);

    return (true);
}

template <typename VectorClass>
bool    vector_insert() {
/*    VectorClass         myvec(30, 999);
    VectorClass         myvec2;
    std::vector<int>    comp(30, 999);

    myvec.pop_back();
    comp.pop_back();
    if (!containers_equal(myvec, comp))
        return (false);

    for (int i = 0; i < 29; i++) {
        myvec.pop_back();
        comp.pop_back();
    }
    if (!containers_equal(myvec, comp))
        return (false);
    myvec2.pop_back();
    if (!containers_equal(myvec, comp))
        return (false);*/

    return (true);
}

template < typename Container >
double vector_modifier_timed_tests(void) {
    clock_t begin, end;

    begin = clock();
    vector_assign<Container>();
    vector_push_back<Container>();
    vector_pop_back<Container>();
    vector_insert<Container>();
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}

void    vector_modifier_tests(void) {
    double stdtime = 0, fttime = 0;

    std::cout << CYAN << '\t' << SUBHDR << "Modifier Tests" << SUBHDR << RESET << '\n';

    // ASSIGN
    std::cout << "vector assign - ";
    if (vector_assign<ft::vector<int> >())
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;

    // PUSH_BACK
    std::cout << "vector push_back - ";
    if (vector_push_back<ft::vector<int> >())
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;

    // POP_BACK
    std::cout << "vector pop_back - ";
    if (vector_pop_back<ft::vector<int> >())
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;

    // INSERT
    std::cout << "vector insert - ";
    if (vector_insert<ft::vector<int> >())
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;


    stdtime = vector_modifier_timed_tests<std::vector<int> >();
    fttime = vector_modifier_timed_tests<ft::vector<int> >();
    print_results(stdtime, fttime);
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

void    vector_iterator_tests(void) {
    double stdtime, fttime;

    std::cout << CYAN << '\t' << SUBHDR << "Iterator Tests" << SUBHDR << RESET << '\n';

    // Vector iterator construction
    std::cout << "vector iterator construction - ";
    if (vector_iterator_construction<ft::vector<int> >(4, 100))
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;
/*    // others
    std::cout << "vector iterator construction - ";
    if (vector_iterator_construction<ft::vector<int> >(4, 100))
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;*/

    stdtime = vector_iterator_timed_tests<std::vector<int> >();
    fttime = vector_iterator_timed_tests<ft::vector<int> >();
    print_results(stdtime, fttime);
}

#endif
