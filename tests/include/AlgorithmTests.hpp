#ifndef ALGORITHMTESTS_HPP
# define ALGORITHMTESTS_HPP

# include "TestClass.hpp"

class AlgorithmTests : public TestClass {

public:

    // Canonical methods
    AlgorithmTests(void);
    ~AlgorithmTests(void);

private:

    // Inherited pure methods
    void printLongResults(void);
    void printShortResults(void);
    double timerTest(void);

    // Algorithm tests
    bool equal(void);
    bool lexicographical_compare(void);

    // canonical methods
    AlgorithmTests(const AlgorithmTests& src);
    const AlgorithmTests& operator=(const AlgorithmTests & rhs);
};

#endif
