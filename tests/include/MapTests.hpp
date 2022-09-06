#ifndef MAPTESTS_HPP
# define MAPTESTS_HPP

# include "TestClass.hpp"

class MapTests : public TestClass {

public:
    // Canonical methods
    MapTests();
    ~MapTests();

private:

    // Inherited pure methods
    void printLongResults();
    void printShortResults();
    double  timerTest();

    // Construction tests
    bool    construction();

    // Iterator tests
    bool    iterator();
    bool    reverse_iterator();

    // Capacity
    bool    capacity();

    // Element Access
    bool    bracketOperator();
    //bool  at();

    // Modifier Tests
    bool    insert(void);


    // Helper Methods*/
    template <typename MapA, typename MapB>
    bool    maps_equal(MapA & A, MapB & B) {

        typedef typename MapA::iterator   IteratorA;
        typedef typename MapB::iterator   IteratorB;

        //check size
        size_t ASize, BSize;
        ASize = A.size();
        BSize = B.size();
        if (ASize != BSize) {
            std::cerr << "ASize: " << ASize << "\nBSize: " << BSize << '\n';
            return (false);
        }

        IteratorA itA = A.begin();
        IteratorB itB = B.begin();

        for (size_t i = 0; i < ASize; i++, itA++, itB++) {
            if ((*itA).first != (*itB).first || (*itA).second != (*itB).second
                || itA == A.end() || itB == B.end()) {
                std::cerr << "iterator A not equal to iterator B\n";
                return (false);
            }
        }
        return (true);
    }
    template <typename MapA, typename MapB>
    bool    maps_equal(MapA & mapAA, MapA & mapAB, MapB & comp) {

        typedef typename MapA::iterator Iterator;
        typedef typename MapB::iterator CompIterator;

        //check size
        size_t ASize, BSize, compSize;
        ASize = mapAA.size();
        BSize = mapAB.size();
        compSize = comp.size();
        if (ASize != BSize || ASize != compSize || BSize != compSize) {
            std::cerr << "ASize: " << ASize << " - BSize: " << BSize << " - CompSize" << compSize << '\n';
            return (false);
        }

        Iterator iteratorA = mapAA.begin();
        Iterator iteratorB = mapAB.begin();
        CompIterator compIterator = comp.begin();

        for (size_t i = 0; i < ASize; i++, iteratorA++, iteratorB++, compIterator++) {
            if ((*iteratorA).first != (*iteratorB).first || (*iteratorA).second != (*iteratorB).second
                || (*compIterator).first != (*iteratorA).first || (*compIterator).second != (*iteratorA).second
                || iteratorA == mapAA.end() || iteratorB == mapAB.end() || compIterator == comp.end()) {
                std::cerr << "iterator A not equal to iterator B\n";
                return (false);
            }
        }
        return (true);
    }

        // canonical methods
    MapTests(const MapTests& src);
    const MapTests& operator=(const MapTests& rhs);

};


#endif
