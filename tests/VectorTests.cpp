#include "include/VectorTests.hpp"
#include "include/TestClass.hpp"
#include "../ft_containers.hpp"
#include <vector>
#include <ctime>
#ifdef TEST
# include "../include/vector.hpp"
# else
namespace ft = std;
#endif


// Canonical methods
VectorTests::VectorTests(void) : TestClass() {}
VectorTests::~VectorTests(void) {}

// Inherited pure methods
void VectorTests::printLongResults(void) {
    print_header(" Vector Tests ");

    print_subheader("Construction Tests");
    print_test_result("construction - ", construction());

    print_subheader("Iterator Tests");
    print_test_result("iterator methods - ", iterator_methods());
    print_test_result("reverse iterator methods - ", reverse_iterator_methods());

    print_subheader("Modifiers Tests");
    print_test_result("assign - ", assign());
    print_test_result("push_back - ", push_back());
    print_test_result("pop_back - ", pop_back());
    print_test_result("insert - ", insert());
    print_test_result("erase - ", erase());
    print_test_result("swap - ", swap());
    print_test_result("clear - ", clear());


    print_subheader("Capacity Tests");
    print_test_result("size - ", size());
    print_test_result("resize - ", resize());
    print_test_result("capacity - ", capacity());
    print_test_result("reserve - ", reserve());

    print_subheader("Element Access Tests");
    print_test_result("operator[], at, front, back - ", element_access());

    print_subheader("Relational operator tests");
    print_test_result("relational operators and swap - ", relational_operators());
}
void    VectorTests::printShortResults(void) {
    std::cout << "Vector tests - ";
    if (construction() && iterator_methods() && reverse_iterator_methods() && assign()
    && push_back() && pop_back() && insert() && erase() && swap() && clear() && size()
    && resize() && capacity() && reserve() && element_access() && relational_operators()) {
        print_result(true);
    } else {
        print_result(false);
    }
}
double  VectorTests::timerTest(void) {
    clock_t begin, end;

    begin = clock();

    // construction
    construction();

    // iterator
    iterator_methods();
    reverse_iterator_methods();

    //modifier
    assign();
    push_back();
    pop_back();
    insert();
    erase();
    swap();
    clear();

    // capacity
    size();
    resize();
    capacity();
    reserve();

    // element access
    element_access();

    // relational operators
    relational_operators();

    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}


//============================================================================//
//                                                                            //
//                              CONSTRUCTOR TESTS                             //
//                                                                            //
//============================================================================//
//====================================//
//        VECTOR CONSTRUCTION         //
//====================================//
bool    VectorTests::construction(void)
{
#ifdef INT
    typedef ft::vector<int> VectorClass;
    typedef ft::vector<int>::iterator iterator;

    // Default construction
    VectorClass dflt;
    // Default construction overload
    VectorClass empty(0);
    VectorClass emptyXdata(0, 100);
    VectorClass sizeOnly(100);
    VectorClass sizeXdata(100, 99999);
    VectorClass large(1000000, 99999);
#endif
#ifdef STR
    typedef ft::vector<std::string> VectorClass;
    typedef ft::vector<std::string>::iterator iterator;

    // Default construction
    VectorClass dflt;
    // Default construction overload
    VectorClass empty(0);
    VectorClass emptyXdata(0, "hey");
    VectorClass sizeOnly(100);
    VectorClass sizeXdata(100, "YELLOW");
    VectorClass large(1000000, "YELLOW");
#endif
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

#ifdef INT
    std::vector<int>    compsxd(100, 99999);
    std::vector<int>::iterator compbg = compsxd.begin();
    std::vector<int>::iterator compend = compsxd.end();
    std::vector<int> comp(compbg, compend);
#endif
#ifdef STR
    std::vector<std::string>    compsxd(100, "YELLOW");
    std::vector<std::string>::iterator compbg = compsxd.begin();
    std::vector<std::string>::iterator compend = compsxd.end();
    std::vector<std::string> comp(compbg, compend);
#endif
    iterator bg = sizeXdata.begin();
    iterator end = sizeXdata.end();
    VectorClass templateTest(bg, end);
    if (!containers_equal(comp, templateTest))
        return (false);
    return (true);
}


//============================================================================//
//                                                                            //
//                              ITERATOR TESTS                                //
//                                                                            //
//============================================================================//
bool    VectorTests::iterator_methods(void) {
    ft::vector<int>     vec;
    std::vector<int>    comp;

    for (int i = 1; i < 25; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }

    std::vector<int>::iterator  cit_b = comp.begin();
    std::vector<int>::iterator  cit_e = comp.end();
    ft::vector<int>::iterator   vit_b = vec.begin();
    ft::vector<int>::iterator   vit_e = vec.end();
    if (*cit_b != *vit_b || *--cit_e != *--vit_e)
        return (false);
    for (size_t i = 0; i < 4; i++) {
        vit_b++;
        cit_b++;
        vit_e--;
        cit_e--;
    }
    if (*cit_b != *vit_b || *cit_e != *vit_e)
        return (false);
    return (true);
}

bool    VectorTests::reverse_iterator_methods(void) {
    ft::vector<int>     vec;
    std::vector<int>    comp;

    for (int i = 1; i < 25; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }

    std::vector<int>::reverse_iterator  crit_b = comp.rbegin();
    std::vector<int>::reverse_iterator  crit_e = comp.rend();
    ft::vector<int>::reverse_iterator   vrit_b = vec.rbegin();
    ft::vector<int>::reverse_iterator   vrit_e = vec.rend();
    if (*crit_b != *vrit_b || *--crit_e != *--vrit_e)
        return (false);
    for (size_t i = 0; i < 4; i++) {
        vrit_b++;
        crit_b++;
        vrit_e--;
        crit_e--;
    }
    if (*crit_b != *vrit_b || *crit_e != *vrit_e)
        return (false);
    return (true);
}



//============================================================================//
//                                                                            //
//                              MODIFIER TESTS                                //
//                                                                            //
//============================================================================//

//====================================//
//               ASSIGN               //
//====================================//
bool    VectorTests::assign() {

    ft::vector<int>     myvec(10, 100);
    std::vector<int>    comp(10, 100);

    // void  assign(size_type n, value_type const & val)
    myvec.assign(10, 35);
    comp.assign(10, 35);
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.assign(1, 3700);
    comp.assign(1, 3700);
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.assign(100, 17);
    comp.assign(100, 17);
    if (!containers_equal(myvec, comp))
        return (false);
    //template <class InputIterator>
    //void assign(InputIterator first, InputIterator last)
    ft::vector<int>     newvec(30, 7);
    std::vector<int>    newcomp(30, 7);

    ft::vector<int>::iterator vecs = newvec.begin();
    ft::vector<int>::iterator vece = newvec.end();
    std::vector<int>::iterator comps = newcomp.begin();
    std::vector<int>::iterator compe = newcomp.end();
    myvec.assign(vecs, vece);
    comp.assign(comps, compe);
    if (!containers_equal(myvec, comp))
        return (false);
    ft::vector<int>     largervec(400, 987654);
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
bool    VectorTests::push_back() {
    ft::vector<int>     myvec;
    ft::vector<int>     myvec2(10, 555);
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
bool    VectorTests::pop_back() {
    ft::vector<int>     myvec(30, 999);
    ft::vector<int>     myvec2;
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
bool    VectorTests::insert() {

    ft::vector<int>     myvec(30, 5);
    std::vector<int>    comp(30, 5);

    // ==== Insert one val ==== //
    ft::vector<int>::iterator   vecCheck;
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
    ft::vector<int>     tmpvec(100);
    std::vector<int>    tmpcomp(100);

    ft::vector<int>::iterator   firstvec = tmpvec.begin();
    std::vector<int>::iterator  firstcomp = tmpcomp.begin();
    ft::vector<int>::iterator   lastvec = tmpvec.end() - 1;
    std::vector<int>::iterator  lastcomp = tmpcomp.end() - 1;
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
bool    VectorTests::erase() {
    typedef ft::vector<int>::iterator   vecIterator;
    typedef std::vector<int>::iterator  compIterator;

    ft::vector<int>     vec;
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
bool    VectorTests::swap() {
    ft::vector<int>     vecA(50, 155);
    ft::vector<int>     vecB;
    ft::vector<int>     vecC;
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
bool    VectorTests::clear() {
    ft::vector<int>     vecA(50, 155);
    ft::vector<int>     vecB;
    ft::vector<int>     vecC;
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



//============================================================================//
//                                                                            //
//                              CAPACITY TESTS                                //
//                                                                            //
//============================================================================//

//====================================//
//         SIZE & MAX SIZE            //
//====================================//
bool    VectorTests::size(void)
{
    ft::vector<int>     vec;
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
bool    VectorTests::resize(void)
{
    ft::vector<int>     vec(50, 300);
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
bool    VectorTests::capacity(void)
{
    ft::vector<int>     vec(50, 300);
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
bool    VectorTests::reserve(void)
{
    ft::vector<int>     vec(50, 300);
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

//============================================================================//
//                                                                            //
//                          ELEMENT ACCESS TESTS                              //
//                                                                            //
//============================================================================//

//====================================//
//    opeerator[], at, front, back    //
//====================================//
bool    VectorTests::element_access(void)
{
    ft::vector<int>      vec;
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

    bool thrownExcpeption = false;
    try
    {
        vec.at(50);
    }
    catch(...)
    {
        thrownExcpeption = true;
    }
    if (!thrownExcpeption) {
        std::cout << RED << "no thrown exception for at() \n" << RESET;
        return (false);
    }

    return (true);
}

//============================================================================//
//                                                                            //
//                      RELATIONAL OPERATORS TESTS                            //
//                                                                            //
//============================================================================//

//====================================//
//   relational operators and swap    //
//====================================//
bool    VectorTests::relational_operators(void)
{
    ft::vector<int>     vec1;
    ft::vector<int>     vec2;

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
    ft::vector<int>     swapA(vec1);
    ft::vector<int>     swapB;

    ft::swap(vec1, swapB);
    if (swapA != swapB || !(swapA == swapB) || !vec1.empty())
        return (false);

    return (true);
}




VectorTests::VectorTests(const VectorTests& src) : TestClass(src) {}
const VectorTests& VectorTests::operator=(const VectorTests& rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
