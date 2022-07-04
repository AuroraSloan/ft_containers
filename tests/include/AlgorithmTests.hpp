#ifndef ALGORITHMTESTS_HPP
# define ALGORITHMTESTS_HPP

# include "TestClass.hpp"

class AlgorithmTests : public TestClass {

public:

    // canonical functions
    AlgorithmTests(void);
    ~AlgorithmTests(void);

    // tester functions for main
    void testOutput(void);
    void testPerformance(void);

private:

    // private tester functions
    double timeTests(void);

    // Algorithm tests
    bool equal(void);
    bool lexicographical_compare(void);

    // canonical functions
    AlgorithmTests(const AlgorithmTests& src);
    const AlgorithmTests& operator=(const AlgorithmTests & rhs);
};

#endif
