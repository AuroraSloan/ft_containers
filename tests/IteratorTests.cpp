#include "../ft_containers.hpp"
#include "include/IteratorTests.hpp"
#include "TestClass.cpp"
#include <ctime>

// Canonical methods
IteratorTests::IteratorTests(void) : TestClass() {}
IteratorTests::~IteratorTests(void) {}

// test helper
void createSampleIntVector(ft::vector<int>& vec, std::vector<int>& comp) {
    for (size_t i = 0; i < 30; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }
}
// Inherited pure methods
void IteratorTests::printLongResults() {
    ft::vector<int>     vec;
    std::vector<int>    comp;
    createSampleIntVector(vec, comp);
    print_header(" Iterator Tests ");

    print_subheader("Construction Tests");
    print_test_result("construction - ", construction());

    print_subheader("Modification Tests");
    print_test_result("iterator - ", modification<ft::vector<int>::iterator, std::vector<int>::iterator >(vec.begin(), comp.begin()));
    print_test_result("reverse iterator - ", modification<ft::vector<int>::reverse_iterator, std::vector<int>::reverse_iterator >(vec.rbegin(), comp.rbegin()));
}
void IteratorTests::printShortResults() {
    ft::vector<int>     vec;
    std::vector<int>    comp;
    createSampleIntVector(vec, comp);

    std::cout << "Iterator tests - ";
    if (construction()
    && modification<ft::vector<int>::iterator, std::vector<int>::iterator >(vec.begin(), comp.begin())
    && modification<ft::vector<int>::reverse_iterator, std::vector<int>::reverse_iterator >(vec.rbegin(), comp.rbegin())) {
        print_result(true);
    } else {
        print_result(false);
    }
}

double    IteratorTests::timerTest(void) {
    clock_t begin, end;

    ft::vector<int>     vec;
    std::vector<int>    comp;
    createSampleIntVector(vec, comp);
    begin = clock();

    construction();
    modification<ft::vector<int>::iterator, std::vector<int>::iterator >(vec.begin(), comp.begin());
    modification<ft::vector<int>::reverse_iterator, std::vector<int>::reverse_iterator >(vec.rbegin(), comp.rbegin());

    end = clock();

    return ((double) (end - begin) / CLOCKS_PER_SEC);
}

//============================================================================//
//                                                                            //
//                              ITERATOR TESTS                                //
//                                                                            //
//============================================================================//

//==============================================//
//      ITERATOR / REVERSE IT CONSTRUCTION      //
//==============================================//
bool    IteratorTests::construction(void) {
    ft::vector<int> vec(55, 37);
    vec.push_back(999);


    // Default construction
    ft::vector<int>::iterator           default_it;
    ft::vector<int>::reverse_iterator   default_rit;
    // Default construction overload
    ft::vector<int>::iterator           begin = vec.begin();
    ft::vector<int>::reverse_iterator   rbegin = vec.rbegin();
    if (*begin != 37 || *rbegin != 999)
        return (false);

    // Copy Construction
    ft::vector<int>::iterator           copy_it(begin);
    ft::vector<int>::reverse_iterator   copy_rit(rbegin);
    if (*copy_it != 37 || *copy_rit != 999)
        return (false);
    // Equal overload
    default_it = begin;
    default_rit = rbegin;
    if (*default_it != 37 || *default_rit != 999)
        return (false);

    return (true);
}

//====================================//
//      ITERATOR MODIFICATION         //
//====================================//
template <typename IteratorA, typename IteratorB>
bool    IteratorTests::modification(IteratorA vecit, IteratorB compit) {
    // INC, DEREF, EQUALITY, MULTIPASS
    vecit++;
    compit++;
    if (*vecit != *compit)
        return (false);
    if(*(++compit) != *(++vecit) ||*(compit++) != *(vecit++))
        return (false);
    if (!(*compit == *vecit) || (*compit != *vecit))
        return (false);
    if ((*compit + 1) != (*vecit + 1) || (*compit - 1) != (*vecit - 1))
        return (false);
    // DEC, DEREF, EQUALITY, MULTIPASS
    vecit--;
    compit--;
    if (*vecit != *compit)
        return (false);
    if(*(--compit) != *(--vecit) ||*(compit--) != *(vecit--))
        return (false);
    if (!(*compit == *vecit) || (*compit != *vecit))
        return (false);
    // ARITHMETIC OPERATORS
    IteratorA vecitB = vecit + 8;
    IteratorB compitB = compit + 8;
    if (*vecitB != *compitB)
        return (false);
    vecitB = 5 + vecitB;
    compitB = 5 + compitB;
    if (*vecitB != *compitB)
        return (false);
    vecitB = vecitB - 3;
    compitB = compitB - 3;
    if (*vecitB != *compitB)
        return (false);
    if ((vecitB - (vecit + 2)) != (compitB - (compit + 2)))
        return (false);

    // INEQUALITY COMPARISON
    if (!(vecit < vecitB == compit < compitB)
        || !(vecit > vecitB == compit > compitB)
        || !(vecit <= vecitB == compit <= compitB)
        || !(vecit >= vecitB == compit >= compitB))
        return (false);

    // COMPOUND ASSIGNMENT OPERATIONS
    vecitB += 13;
    compitB += 13;
    if (*vecitB != *compitB)
        return (false);
    vecitB -= 4;
    compitB -= 4;
    if (*vecitB != *compitB)
        return (false);
    if (vecitB[0] != compitB[0]
        || vecitB[1] != compitB[1]
        || vecitB[-1] != compitB[-1])
        return (false);

    return (true);
}

IteratorTests::IteratorTests(const IteratorTests& src) : TestClass(src) {}
const IteratorTests & IteratorTests::operator=(const IteratorTests& rhs) {
    if (this != &rhs) {
        this->ftTime = rhs.ftTime;
        this->stdTime = rhs.stdTime;
    }
    return (*this);
}
