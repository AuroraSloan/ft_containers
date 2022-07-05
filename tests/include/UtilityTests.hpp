#ifndef UTILITYTESTS_HPP
# define UTILITYTESTS_HPP

# include "TestClass.hpp"

class UtilityTests : public TestClass {

public:

    // canonical methods
    UtilityTests(void);
    ~UtilityTests(void);

private:

    // inherited pure methods
    void printLongResults(void);
    void printShortResults(void);
    double timerTest(void);

    // Utility tests
    bool pair_construction(void);
    bool pair_relational_operators(void);
    bool make_pair(void);

    // canonical methods
    UtilityTests(const UtilityTests& src);
    const UtilityTests& operator=(const UtilityTests & rhs);
};

#endif
