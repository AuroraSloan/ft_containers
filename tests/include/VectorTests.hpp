#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "TestClass.hpp"

# include <ctime>       //clock

class VectorTests : public TestClass {

public:
    // Canonical methods
    VectorTests(void);
    ~VectorTests(void);

private:

    // Inherited pure methods
    void printLongResults(void);
    void printShortResults(void);
    double  timerTest(void);

    // Construction tests
    bool    construction(void);

    // Iterator tests
    bool    iterator_methods(void);
    bool    reverse_iterator_methods(void);

    // Modifier tests
    bool    assign(void);
    bool    push_back(void);
    bool    pop_back(void);
    bool    insert(void);
    bool    erase(void);
    bool    swap(void);
    bool    clear(void);

    // Capacity Tests
    bool    size(void);
    bool    resize(void);
    bool    capacity(void);
    bool    reserve(void);

    // Element access Tests
    bool    element_access(void);

    // Relational operators tests
    bool    relational_operators(void);

    // canonical methods
    VectorTests(const VectorTests& src);
    const VectorTests& operator=(const VectorTests& rhs);

};


#endif
