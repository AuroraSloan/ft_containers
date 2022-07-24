#ifndef TREETESTS_HPP
# define TREETESTS_HPP

# include "TestClass.hpp"

class TreeTests : public TestClass {

public:
    // Canonical methods
    TreeTests(void);
    ~TreeTests(void);

private:

    // Inherited pure methods
    void printLongResults(void);
    void printShortResults(void);
    double  timerTest(void);

    // Construction tests
    bool    construction(void);

    // Iterator tests
    /*bool    iterator_methods(void);

    // Modifier tests
    bool    tree_insert(void);
    bool    tree_transplant(void);
    bool    tree_delete(void);*/

    // Helper Methods
    template <typename Tree>
    bool    trees_equal(Tree & A, Tree & B) {

        //typedef typename Tree::iterator   Iterator;

        //check size
        size_t ASize, BSize;
        ASize = A.size();
        BSize = B.size();
        if (ASize != BSize) {
            std::cerr << "ASize: " << ASize << "\nBSize: " << BSize << '\n';
            return (false);
        }

        /*Iterator iteratorA = A.begin();
        Iterator iteratorB = B.begin();

        for (size_t i = 0; i < ASize; i++, iteratorA++, iteratorB++) {
            std::cerr << "1\n";
            std::cerr << "iteratorA: " << *iteratorA << '\n';
            if (*iteratorA != *iteratorB)
                return (false);
        }
        while (iteratorA != A.end() || iteratorB != B.end()) {
            if ((*(iteratorA) != *(iteratorB)) || iteratorA == A.end() || iteratorB == B.end())
                return (false);
            iteratorA++;
            iteratorB++;
        }*/
        return (true);
    }
    // canonical methods
    TreeTests(const TreeTests& src);
    const TreeTests& operator=(const TreeTests& rhs);

};


#endif
