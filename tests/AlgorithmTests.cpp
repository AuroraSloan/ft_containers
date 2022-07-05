#include "include/AlgorithmTests.hpp"
#include "include/TestClass.hpp"
#include "../ft_containers.hpp"

// canonical functions
AlgorithmTests::AlgorithmTests() : TestClass() {}
AlgorithmTests::~AlgorithmTests() {}

// tester functions for main
void AlgorithmTests::testOutput(void) {
    print_test_result("equal - ", equal());
    print_test_result("lexicographical_compare - ", lexicographical_compare());
}

void AlgorithmTests::testPerformance(void) {
    ftTime = timeTests();
    namespace ft = std;
    stdTime = timeTests();
    print_time_results(stdTime, ftTime);
}

// private tester functions
double AlgorithmTests::timeTests(void) {
    clock_t begin, end;

    begin = clock();

    //algorithms
    equal();
    lexicographical_compare();

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
bool AlgorithmTests::equal(void) {
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
bool AlgorithmTests::lexicographical_compare(void) {
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

AlgorithmTests::AlgorithmTests(const AlgorithmTests& src) : TestClass(src) {}
const AlgorithmTests& AlgorithmTests::operator=(const AlgorithmTests & rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
