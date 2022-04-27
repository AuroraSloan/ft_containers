#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "TestClass.hpp"

# include <ctime>       //clock

class VectorTests : public TestClass {

public:
    VectorTests();
    ~VectorTests();

    void testOutput();
    void testPerformance();


private:

    double    timeTests(void);

    // Construcion tests
    bool    construction(void);

    // Iterator tests
    bool    reverse_iterator_methods(void);

    // Modifier tests
    bool    assign();
    bool    push_back();
    bool    pop_back();
    bool    insert();
    bool    erase();
    bool    swap();
    bool    clear();

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
