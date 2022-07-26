#ifndef ITERATOR_TESTS_HPP
# define ITERATOR_TESTS_HPP

# include "TestClass.hpp"

class IteratorTests : public TestClass {

public:

    // Canonical methods
    IteratorTests();
    ~IteratorTests();

private:

    // Inherited pure methods
    void printLongResults();
    void printShortResults();
    double    timerTest();

    // Iterator tests
    bool    construction();

    template <typename IteratorA, typename IteratorB>
    bool    modification(IteratorA vecit, IteratorB compit);

    // Canonical methods
    IteratorTests(const IteratorTests& src);
    const IteratorTests & operator=(const IteratorTests& rhs);
};

#endif
