#pragma once
#ifndef ALGORITHMTESTS_HPP
# define ALGORITHMTESTS_HPP

# include "TestClass.hpp"

class AlgorithmTests : public TestClass {

public:

    // Canonical methods
    AlgorithmTests();
    ~AlgorithmTests();

private:

    // Inherited pure methods
    void printLongResults();
    void printShortResults();
    double timerTest();

    // Algorithm tests
    bool equal();
    bool lexicographical_compare();

    // canonical methods
    AlgorithmTests(const AlgorithmTests& src);
    const AlgorithmTests& operator=(const AlgorithmTests & rhs);
};

#endif
