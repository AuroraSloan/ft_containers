#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "../include/vector.hpp"
# include "../include/utils.hpp"
# include "testUtils.hpp"
# include <ctime>           //clock
# include <vector>


//=================== Compare two containers ==============//
template <typename ftContainer, typename stdContainer>
bool    containers_equal(ftContainer & vec, stdContainer & comp) {

    typedef typename ftContainer::size_type size_type;
    typename ftContainer::iterator  vecIterator;
    typename stdContainer::iterator compIterator;

    //check size
    size_type vecSize, compSize;
    vecSize = vec.size();
    compSize = comp.size();
    if (vecSize != compSize){
        std::cout << "\nSIZE IS A PROBLEM\nme: " << vecSize << " std: " << compSize << '\n';
        return (false);
    }


   /*if ((unsigned long)vec.capacity() != comp.capacity())
        std::cout << "my capacity " << vec.capacity() << " comp capacity " << comp.capacity() << '\n';*/

    //check items
    vecIterator = vec.begin();
    compIterator = comp.begin();
//    std::cout << "in tester\n";
    for (size_type i = 0; i < vecSize; i++) {
 //       std::cout << "vec: " << *(vecIterator + i) << " comp: " << *(compIterator + i) << '\n';
        if (*(vecIterator + i) != *(compIterator + i))
            return (false);
    }
    while (vecIterator != vec.end() || compIterator != comp.end()) {
        if ((*(vecIterator) != *(compIterator)) || vecIterator == vec.end() || compIterator == comp.end())
            return (false);
        vecIterator++;
        compIterator++;
    }
    return (true);
}

//=================== Compare three containers ==============//
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

//========================= Print Containers ====================//
template <typename Container>
void    print_container(Container container, std::string name) {
    typedef typename Container::iterator iterator;

    std::cout << name << '\n';
    for(iterator it = container.begin(); it != container.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

//========================= Print Results ====================//
void    print_test_result(std::string testName, bool success) {
    std::cout << testName;
    if (success)
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;
}

//============================================================================//
//                                                                            //
//                              CONSTRUCTOR TESTS                             //
//                                                                            //
//============================================================================//
//====================================//
//        VECTOR CONSTRUCTION         //
//====================================//
template <typename VectorClass>
bool    vector_construction(void)
{
    typedef typename VectorClass::iterator iterator;
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

    std::vector<int>    compsxd(100, 5);
    std::vector<int>::iterator compbg = compsxd.begin();
    std::vector<int>::iterator compend = compsxd.end();
    std::vector<int> comp(compbg, compend);
    iterator bg = sizeXdata.begin();
    iterator end = sizeXdata.end();
    VectorClass templateTest(bg, end);
    if (!containers_equal(comp, templateTest))
        return (false);
    return (true);
}
//==============Calculate time===========//
template < typename Container >
double vec_construction_timer(void) {
    clock_t begin, end;

    begin = clock();
    vector_construction<Container>();
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}
//=====Perform all tests and time tests =====//
void    vector_construction_tests(void) {
    std::cout << CYAN << '\t' << SUBHDR << "Construction Tests" << SUBHDR << RESET << '\n';
    print_test_result("vector construction - ",vector_construction<ft::vector<int> >());
    print_time_results(vec_construction_timer<std::vector<int> >(),vec_construction_timer<ft::vector<int> >());
}




//============================================================================//
//                                                                            //
//                              MODIFIER TESTS                                //
//                                                                            //
//============================================================================//

//====================================//
//               ASSIGN               //
//====================================//
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

//====================================//
//            PUSH_BACK               //
//====================================//
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

//====================================//
//             POP_BACK               //
//====================================//
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

//====================================//
//              INSERT                //
//====================================//
template <typename VectorClass>
bool    vector_insert() {
    typedef typename VectorClass::iterator VecClassIterator;
    VectorClass         myvec(30, 5);
    std::vector<int>    comp(30, 5);

    // ==== Insert one val ==== //
    VecClassIterator            vecCheck;
    std::vector<int>::iterator  compCheck;
    // reallocate
    vecCheck = myvec.insert((myvec.begin() + 5), 7);
    compCheck = comp.insert((comp.begin() + 5), 7);
    if (!containers_equal(myvec, comp) || *vecCheck != *compCheck)
        return (false);
    // No reallocate
    vecCheck = myvec.insert((myvec.begin() + 5), 30);
    compCheck = comp.insert((comp.begin() + 5), 30);
    if (!containers_equal(myvec, comp) || *vecCheck != *compCheck)
        return (false);

    // ==== Insert Mult val ==== //
    // reallocate
    myvec.insert(myvec.begin() + 20, 50, 44);
    comp.insert(comp.begin() + 20, 50, 44);
    if (!containers_equal(myvec, comp))
        return (false);
    // No reallocate
    myvec.insert((myvec.begin() + 30), 3, 900);
    comp.insert((comp.begin() + 30), 3, 900);
    if (!containers_equal(myvec, comp))
        return (false);

    // ==== Insert iterators ==== //
    // reallocate
    VectorClass         tmpvec(100);
    std::vector<int>    tmpcomp(100);

    VecClassIterator firstvec = tmpvec.begin();
    std::vector<int>::iterator firstcomp = tmpcomp.begin();
    VecClassIterator lastvec = tmpvec.end() - 1;
    std::vector<int>::iterator lastcomp = tmpcomp.end() - 1;
    myvec.insert(myvec.begin() + 10, firstvec, lastvec);
    comp.insert(comp.begin() + 10, firstcomp, lastcomp);
    if (!containers_equal(myvec, comp))
        return (false);

    // No reallocation
    firstvec = tmpvec.begin() + 8;
    lastvec = tmpvec.begin() + 45;
    firstcomp = tmpcomp.begin() + 8;
    lastcomp = tmpcomp.begin() + 45;
    myvec.insert(myvec.begin() + 44, firstvec, lastvec);
    comp.insert(comp.begin() + 44, firstcomp, lastcomp);
    if (!containers_equal(myvec, comp))
        return (false);

    // ==== Edge casees ==== //
    myvec.insert(myvec.end(), 7);
    comp.insert(comp.end(), 7);
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.insert(myvec.end(), 4, 555);
    comp.insert(comp.end(), 4, 555);
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.insert(myvec.end(), myvec.begin(), myvec.end() - 1);
    comp.insert(comp.end(), comp.begin(), comp.end() - 1);
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.insert(myvec.begin(), myvec.begin(), myvec.end());
    comp.insert(comp.begin(), comp.begin(), comp.end());
    if (!containers_equal(myvec, comp))
        return (false);

    return (true);
}

//====================================//
//               ERASE                //
//====================================//
template <typename VectorClass>
bool    vector_erase() {
    typedef typename VectorClass::iterator  vecIterator;
    typedef std::vector<int>::iterator      compIterator;

    VectorClass         vec;
    vecIterator         vecIt;
    std::vector<int>    comp;
    compIterator        compIt;

    for(size_t i = 0; i < 20; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }

    vecIt = vec.erase(vec.begin());
    compIt = comp.erase(comp.begin());
    if (!containers_equal(vec, comp) || *vecIt != *compIt)
        return (false);

    vecIt = vec.erase(vec.begin() + 6, vec.end());
    compIt = comp.erase(comp.begin() + 6, comp.end());
    if (!containers_equal(vec, comp) || *vecIt != *compIt)
        return (false);

    vecIt = vec.erase(vec.end() - 1);
    compIt = comp.erase(comp.end() - 1);
    if (!containers_equal(vec, comp) || *vecIt != *compIt)
        return (false);

    vecIt = vec.erase(vec.begin(), vec.end());
    compIt = comp.erase(comp.begin(), comp.end());
    if (!containers_equal(vec, comp) || *vecIt != *compIt)
        return (false);

    return (true);
}

//====================================//
//               SWAP                 //
//====================================//
template <typename VectorClass>
bool    vector_swap() {
    VectorClass         vecA(50, 155);
    VectorClass         vecB;
    VectorClass         vecC;
    std::vector<int>    compA(50, 155);
    std::vector<int>    compB;
    std::vector<int>    compC;

    for(size_t i = 0; i < 30; i++) {
        vecB.push_back(i);
        compB.push_back(i);
    }

    vecA.swap(vecB);
    compA.swap(compB);
    if (!containers_equal(vecA, compA) || !containers_equal(vecB, compB))
        return (false);

    vecA.swap(vecC);
    compA.swap(compC);
    if (!containers_equal(vecA, compA) || !containers_equal(vecC, compC))
        return (false);

    return (true);
}

//====================================//
//              CLEAR                 //
//====================================//
template <typename VectorClass>
bool    vector_clear() {
    VectorClass         vecA(50, 155);
    VectorClass         vecB;
    VectorClass         vecC;
    std::vector<int>    compA(50, 155);
    std::vector<int>    compB;
    std::vector<int>    compC;

    for(size_t i = 0; i < 30; i++) {
        vecB.push_back(i);
        compB.push_back(i);
    }

    vecA.clear();
    compA.clear();
    if (!containers_equal(vecA, compA))
        return (false);

    vecB.clear();
    compB.clear();
    if (!containers_equal(vecB, compB))
        return (false);

    vecC.clear();
    compC.clear();
    if (!containers_equal(vecC, compC))
        return (false);

    return (true);
}

//==============Calculate time===========//
template < typename Container >
double vec_modifiers_timer(void) {
    clock_t begin, end;

    begin = clock();
    vector_assign<Container>();
    vector_push_back<Container>();
    vector_pop_back<Container>();
    vector_insert<Container>();
    vector_erase<Container>();
    vector_swap<Container>();
    vector_clear<Container>();
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}

//============= Perform all tests =============//
void    vector_modifiers_tests(void) {
    std::cout << CYAN << '\t' << SUBHDR << "Modifiers Tests" << SUBHDR << RESET << '\n';

    print_test_result("vector assign - ", vector_assign<ft::vector<int> >());
    print_test_result("vector push_back - ", vector_push_back<ft::vector<int> >());
    print_test_result("vector pop_back - ", vector_pop_back<ft::vector<int> >());
    print_test_result("vector insert - ", vector_insert<ft::vector<int> >());
    print_test_result("vector erase - ", vector_erase<ft::vector<int> >());
    print_test_result("vector swap - ", vector_swap<ft::vector<int> >());
    print_test_result("vector clear - ", vector_clear<ft::vector<int> >());

    print_time_results(vec_modifiers_timer<std::vector<int> >(), vec_modifiers_timer<ft::vector<int> >());
}




//============================================================================//
//                                                                            //
//                              ITERATOR TESTS                                //
//                                                                            //
//============================================================================//

//====================================//
//      ITERATOR CONSTRUCTION         //
//====================================//
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

//==============Calculate time===========//
template < typename Container >
double vec_iterator_timed_tests(void) {
    clock_t begin, end;

    begin = clock();
    vector_iterator_construction<Container>(10, 1000);
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}
//=====Perform all tests and time tests =====//
void    vector_iterator_tests(void) {

    std::cout << CYAN << '\t' << SUBHDR << "Iterator Tests" << SUBHDR << RESET << '\n';

    print_test_result("vector iterator construction - ", vector_iterator_construction<ft::vector<int> >(4, 100));

    print_time_results(vec_iterator_timed_tests<std::vector<int> >(), vec_iterator_timed_tests<ft::vector<int> >());

}

//============================================================================//
//                                                                            //
//                              CAPACITY TESTS                                //
//                                                                            //
//============================================================================//

//====================================//
//         SIZE & MAX SIZE            //
//====================================//
template <typename VectorClass>
bool    vector_size(void)
{
    VectorClass         vec;
    std::vector<int>    comp;

    if (!containers_equal(vec, comp) || vec.size() != comp.size())
        return (false);
    for (size_t i = 0; i < 30; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }
    if (!containers_equal(vec, comp) || vec.size() != comp.size())
        return (false);
    if (vec.max_size() != comp.max_size())
        std::cout << YELLOW << "max size differs\nstl: " << comp.max_size() << "\nft: " << vec.max_size() << RESET << '\n';

    vec.insert(vec.begin() + 7, 8, 550);
    comp.insert(comp.begin() + 7, 8, 550);
    if (!containers_equal(vec, comp) || vec.size() != comp.size())
        return (false);
    if (vec.max_size() != comp.max_size())
        std::cout << YELLOW << "max size differs\nstl: " << comp.max_size() << "\nft: " << vec.max_size() << RESET << '\n';

    for (size_t i = 0; i < 4; i++) {
        vec.pop_back();
        comp.pop_back();
    }
    if (!containers_equal(vec, comp) || vec.size() != comp.size())
        return (false);
    if (vec.max_size() != comp.max_size())
        std::cout << YELLOW << "max size differs\nstl: " << comp.max_size() << "\nft: " << vec.max_size() << RESET << '\n';

    return (true);
}

//====================================//
//               RESIZE               //
//====================================//
template <typename VectorClass>
bool    vector_resize(void)
{
    VectorClass         vec(50, 300);
    std::vector<int>    comp(50, 300);

    vec.resize(2);
    comp.resize(2);
    if (!containers_equal(vec, comp))
        return (false);

    vec.resize(30, 80);
    comp.resize(30, 80);
    if (!containers_equal(vec, comp))
        return (false);

    vec.resize(60);
    comp.resize(60);
    if (!containers_equal(vec, comp))
        return (false);

    return (true);
}

//====================================//
//         CAPACITY & EMPTY           //
//====================================//
template <typename VectorClass>
bool    vector_capacity(void)
{
    VectorClass         vec(50, 300);
    std::vector<int>    comp(50, 300);

    if (vec.capacity() != comp.capacity())
        return (false);

    vec.reserve(100);
    comp.reserve(100);
    if (vec.capacity() != comp.capacity())
        return (false);

    if (vec.empty() != comp.empty())
        return (false);

    vec.clear();
    comp.clear();
    if (vec.empty() != comp.empty())
        return (false);

    return (true);
}
//====================================//
//               RESERVE              //
//====================================//
template <typename VectorClass>
bool    vector_reserve(void)
{
    VectorClass         vec(50, 300);
    std::vector<int>    comp(50, 300);

    vec.reserve(0);
    comp.reserve(0);
    if (!containers_equal(vec, comp))
        return (false);

    vec.reserve(133);
    comp.reserve(133);
    if (!containers_equal(vec, comp))
        return (false);

    return (true);
}

//==============Calculate time===========//
template < typename Container >
double vec_capacity_timed_tests(void) {
    clock_t begin, end;

    begin = clock();
    vector_size<Container>();
    vector_resize<Container>();
    vector_capacity<Container>();
    vector_reserve<Container>();
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}
//=====Perform all tests and time tests =====//
void    vector_capacity_tests(void) {

    std::cout << CYAN << '\t' << SUBHDR << "Capacity Tests" << SUBHDR << RESET << '\n';

    print_test_result("vector size - ", vector_size<ft::vector<int> >());
    print_test_result("vector resize - ", vector_resize<ft::vector<int> >());
    print_test_result("vector capacity - ", vector_capacity<ft::vector<int> >());
    print_test_result("vector reserve - ", vector_reserve<ft::vector<int> >());

    print_time_results(vec_capacity_timed_tests<std::vector <int> > (), vec_capacity_timed_tests<ft::vector<int> >());
}

//============================================================================//
//                                                                            //
//                          ELEMENT ACCESS TESTS                              //
//                                                                            //
//============================================================================//

//====================================//
//    opeerator[], at, front, back    //
//====================================//
template <typename VectorClass>
bool    vector_element_access(void)
{
    VectorClass         vec;
    std::vector<int>    comp;

    for (size_t i = 0; i < 25; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }

    // OPERATOR []
    if (vec[0] != comp[0] || vec[20] != comp[20] || vec[24] != comp[24])
        return (false);

    // AT
    if (vec.at(4) != comp.at(4) || vec.at(0) != comp.at(0) || vec.at(24) != comp.at(24))
        return (false);

    // FRONT
    if (vec.front() != comp.front())
        return (false);

    // BACK
    if (vec.back() != comp.back())
        return (false);

    return (true);
}

//==============Calculate time===========//
template < typename Container >
double vec_elem_access_timed_tests(void) {
    clock_t begin, end;

    begin = clock();
    vector_element_access<Container>();
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}
//=====Perform all tests and time tests =====//
void    vector_elem_access_tests(void) {

    std::cout << CYAN << '\t' << SUBHDR << "Element Access Tests" << SUBHDR << RESET << '\n';

    print_test_result("operator[], at, front, back - ", vector_element_access<ft::vector<int> >());

    print_time_results(vec_elem_access_timed_tests<std::vector <int> > (), vec_elem_access_timed_tests<ft::vector<int> >());
}






//============================================================================//
//                                                                            //
//                      RELATIONAL OPERATORS TESTS                            //
//                                                                            //
//============================================================================//

//====================================//
//   relational operators and swap    //
//====================================//
template <typename VectorClass>
bool    vector_relational_operators(void)
{
    VectorClass         vec1;
    VectorClass         vec2;

    // RELATIONAL OPERATORS
    if (!(vec1 == vec2) || vec1 != vec2 || vec1 < vec2 || vec1 > vec2 || !(vec1 <= vec2) || !(vec1 >= vec2))
        return (false);

    for (size_t i = 0; i < 25; i++) {
        vec1.push_back(i);
        vec2.push_back(i);
    }

    if (!(vec1 == vec2) || vec1 != vec2 || vec1 < vec2 || vec1 > vec2 || !(vec1 <= vec2) || !(vec1 >= vec2))
        return (false);

    vec1.pop_back();
    if (vec1 == vec2 || !(vec1 != vec2) || !(vec1 < vec2) || vec2 < vec1 || vec1 > vec2 || !(vec2 > vec1))
        return (false);
    if (!(vec1 <= vec2) || vec2 <= vec1 || vec1 >= vec2 || !(vec2 >= vec1))
        return (false);

    // SWAP && RELATIONAL OPERATORS
    VectorClass         swapA(vec1);
    VectorClass         swapB;

    swap(vec1, swapB);
    if (swapA != swapB || !(swapA == swapB) || !vec1.empty())
        return (false);

    return (true);
}

//==============Calculate time===========//
template < typename Container >
double vec_relational_operators_timed_tests(void) {
    clock_t begin, end;

    begin = clock();
    vector_relational_operators<Container>();
    end = clock();
    return ((double)(end - begin) / CLOCKS_PER_SEC);
}

//=====Perform all tests and time tests =====//
void    vector_relational_operators_tests(void) {

    std::cout << CYAN << '\t' << SUBHDR << "Relational Operators Tests" << SUBHDR << RESET << '\n';

    print_test_result("relational operators and swap - ", vector_relational_operators<ft::vector<int> >());

    print_time_results(vec_relational_operators_timed_tests<std::vector <int> > (), vec_relational_operators_timed_tests<ft::vector<int> >());
}

#endif
