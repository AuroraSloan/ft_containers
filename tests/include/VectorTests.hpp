#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "TestClass.hpp"

# include <ctime>       //clock

class VectorTests : public TestClass {

public:
    VectorTests(void);
    ~VectorTests(void);

    void testOutput(void);
    void testPerformance(void);

private:

    double    timeTests(void);

    // Construcion tests
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

    VectorTests(const VectorTests& src);
    const VectorTests& operator=(const VectorTests& rhs);


};


#endif
