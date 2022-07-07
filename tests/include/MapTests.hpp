#ifndef MAPTESTS_HPP
# define MAPTESTS_HPP

# include "TestClass.hpp"

class MapTests : public TestClass {

public:
    // Canonical methods
    MapTests(void);
    ~MapTests(void);

private:

    // Inherited pure methods
    void printLongResults(void);
    void printShortResults(void);
    double  timerTest(void);

    /*// Construction tests
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
    bool    relational_operators(void);*/

    // canonical methods
    MapTests(const MapTests& src);
    const MapTests& operator=(const MapTests& rhs);

};


#endif
