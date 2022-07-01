#include "include/OtherTests.hpp"
#include "include/TestClass.hpp"
#include "../ft_containers.hpp"


OtherTests::OtherTests() : TestClass() {}
OtherTests::~OtherTests() {}

void OtherTests::testOutput(void) {
    print_subheader("Algorithm Tests");
    print_test_result("equal - ", equal());
    print_test_result("lexicographical_compare - ", lexicographical_compare());

    print_subheader("Utility Tests");
    print_test_result("pair - ", pair());
}

void OtherTests::testPerformance(void) {
    ftTime = timeTests();
    namespace ft = std;
    stdTime = timeTests();
    print_time_results(stdTime, ftTime);
}

double OtherTests::timeTests(void) {
    clock_t begin, end;

    begin = clock();

    //algorithms
    equal();
    lexicographical_compare();

    //utility
    //pair();
    //make_pair();

    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}

//============================================================================//
//                                                                            //
//                              ALGORITHM TESTS                               //
//                                                                            //
//============================================================================//
//====================================//
//                EQUAL               //
//====================================//
bool equal_toPredicate(int a, int b) {
    return (a == b);
}
bool OtherTests::equal(void) {
    ft::vector<int> vecA;
    ft::vector<int> vecB;

    for (int i = 0; i < 40; i++) {
        vecA.push_back(i);
        vecB.push_back(i);
    }

    // begin, end, begin
    if (!ft::equal(vecA.begin(), vecA.end(), vecB.begin())) {
        return (false);
    }
    if (ft::equal(++vecA.begin(), vecA.end(), vecB.begin())) {
        return (false);
    }
    if (ft::equal(vecA.begin(), vecA.end(), ++vecB.begin())) {
        return (false);
    }

    // begin, end, begin, predicate
    if (!ft::equal(vecA.begin(), vecA.end(), vecB.begin(), equal_toPredicate)) {
        return (false);
    }
    if (ft::equal(++vecA.begin(), vecA.end(), vecB.begin(), equal_toPredicate)) {
        return (false);
    }
    if (ft::equal(vecA.begin(), vecA.end(), ++vecB.begin(), equal_toPredicate)) {
        return (false);
    }

    return (true);
}

//====================================//
//      LEXICOGRAPHICAL COMPARE       //
//====================================//
bool less_than_predicate(int a, int b) {
    return (a < b);
}
// true if the first range is lexicographically less than the second
bool OtherTests::lexicographical_compare(void) {
    ft::vector<int> vecA;
    ft::vector<int> vecB;
    ft::vector<int> vecShort;

    for (int i = 0; i < 40; i++) {
        vecA.push_back(i);
        vecB.push_back(i);
        if (i < 39) {
            vecShort.push_back(i);
        }
    }

    // no prdicate
    if (!ft::lexicographical_compare(vecShort.begin(), vecShort.end(), vecA.begin(), vecA.end())) {
        return (false);
    }
    if (ft::lexicographical_compare(vecA.begin(), vecA.end(), vecShort.begin(), vecShort.end())) {
        return (false);
    }
    if (ft::lexicographical_compare(vecA.begin(), vecA.end(), vecB.begin(), vecB.end())) {
        return (false);
    }

    // predicate
    if (!ft::lexicographical_compare(vecShort.begin(), vecShort.end(), vecA.begin(), vecA.end(), less_than_predicate)) {
        return (false);
    }
    if (ft::lexicographical_compare(vecA.begin(), vecA.end(), vecShort.begin(), vecShort.end(), less_than_predicate)) {
        return (false);
    }
    if (ft::lexicographical_compare(vecA.begin(), vecA.end(), vecB.begin(), vecB.end(), less_than_predicate)) {
        return (false);
    }
    return (true);
}

//============================================================================//
//                                                                            //
//                              UTILITY TESTS                                 //
//                                                                            //
//============================================================================//
//====================================//
//                PAIR                //
//====================================//
bool OtherTests::pair() {
   return (true);
}


OtherTests::OtherTests(const OtherTests& src) : TestClass(src) {}
const OtherTests& OtherTests::operator=(const OtherTests & rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
