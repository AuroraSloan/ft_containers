#pragma once
#ifndef SETTESTS_HPP
# define SETTESTS_HPP

# include "TestClass.hpp"

class SetTests : public TestClass {

public:
    // Canonical methods
    SetTests();
    ~SetTests();

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

    // Modifier Tests
    bool    insert();
    bool    erase();
    bool    swap();
    bool    clear();

    // Lookup Tests
    bool    find();
    bool    count();
    bool    bounds_range();


    // Helper Methods*/
    template <typename setA, typename setB>
    bool    sets_equal(setA & A, setB & B) {

        typedef typename setA::iterator   IteratorA;
        typedef typename setB::iterator   IteratorB;

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
            if (*itA != *itB || itA == A.end() || itB == B.end()) {
                std::cerr << "iterator A not equal to iterator B\n";
                return (false);
            }
        }
        return (true);
    }

    template <typename setA, typename setB>
    void    print_sets(setA & A, setB & B) {

        typename setA::iterator   itA = A.begin();
        typename setB::iterator   itB = B.begin();

        for (; itA != A.end() && itB != B.end(); itA++, itB++) {
            std::cout << "A>> " << *itA << "\tB>> " << *itB << "\n";
        }
        for (; itA != A.end(); itA++) {
            std::cout << "A>> " << *itA << "\n";
        }
        for (; itB != B.end(); itB++) {
            std::cout << "\t\tB>>" << *itB << "\n";
        }
    }

    template <typename setA, typename setB>
    bool    sets_equal(setA & setAA, setA & setAB, setB & comp) {

        typedef typename setA::iterator Iterator;
        typedef typename setB::iterator CompIterator;

        //check size
        size_t ASize, BSize, compSize;
        ASize = setAA.size();
        BSize = setAB.size();
        compSize = comp.size();
        if (ASize != BSize || ASize != compSize || BSize != compSize) {
            std::cerr << "ASize: " << ASize << " - BSize: " << BSize << " - CompSize" << compSize << '\n';
            return (false);
        }

        Iterator iteratorA = setAA.begin();
        Iterator iteratorB = setAB.begin();
        CompIterator compIterator = comp.begin();

        for (size_t i = 0; i < ASize; i++, iteratorA++, iteratorB++, compIterator++) {
            if (*iteratorA != *iteratorB || *compIterator != *iteratorA
                || iteratorA == setAA.end() || iteratorB == setAB.end() || compIterator == comp.end()) {
                std::cerr << "iterator A not equal to iterator B\n";
                return (false);
            }
        }
        return (true);
    }

    template<typename FT, typename STD>
    void _generate_ordered_sets(FT &ft_set, STD &std_set, size_t count) {
        for (size_t i = 0; i < count; i++) {
            ft_set.insert(i);
            std_set.insert(i);
        }
    }

    template<typename FT, typename STD>
    void _generate_random_sets(FT &ft_set, STD &std_set, size_t count) {
        int     random_number;
        srand (time(NULL));

        for (size_t i = 0; i < count; i++) {
            random_number = rand();
            ft_set.insert(random_number);
            std_set.insert(random_number);
        }
    }
    
    template<typename FT>
    void _generate_random_sets(FT &ft_set, size_t count) {
        int     random_number;
        srand (time(NULL));

        for (size_t i = 0; i < count; i++) {
            random_number = rand();
            ft_set.insert(random_number);
        }
    }
    // canonical methods
    SetTests(const SetTests& src);
    const SetTests& operator=(const SetTests& rhs);

};


#endif
