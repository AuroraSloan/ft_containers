#ifndef ITERATOR_TESTS_HPP
# define ITERATOR_TESTS_HPP

# include "TestClass.hpp"

# include <ctime>       //clock

class IteratorTests : public TestClass {

public:

    IteratorTests(void);
    ~IteratorTests(void);

    void testOutput(void);
    void testPerformance(void);

private:

    double    timeTests(void);

    bool    construction(void);

    template <typename IteratorA, typename IteratorB>
    bool    modification(IteratorA vecit, IteratorB compit);

    IteratorTests(const IteratorTests& src);
    const IteratorTests & operator=(const IteratorTests& rhs);
};

#endif
