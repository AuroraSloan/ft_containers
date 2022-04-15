#ifndef ITERATORTESTS_HPP
# define ITERATORTESTS_HPP

# include <vector>
# include "../include/vector.hpp"

//============================================================================//
//                                                                            //
//                              ITERATOR TESTS                                //
//                                                                            //
//============================================================================//

//====================================//
//      ITERATOR CONSTRUCTION         //
//====================================//
template <typename VectorClass>
bool    iterator_construction(void)
{
    VectorClass vec(55, 37);
    vec.push_back(999);


    // Default construction
    typename VectorClass::iterator default_it;
    typename VectorClass::reverse_iterator default_rit;
    // Default construction overload
    typename VectorClass::iterator begin = vec.begin();
    typename VectorClass::reverse_iterator rbegin = vec.rbegin();
    if (*begin != 37 || *rbegin != 999)
        return (false);

    // Copy Construction
    typename VectorClass::iterator copy_it(begin);
    typename VectorClass::reverse_iterator copy_rit(rbegin);
    if (*copy_it != 37 || *copy_rit != 999)
        return (false);
    // Equal overload
    default_it = begin;
    default_rit = rbegin;
    if (*default_it != 37 || *default_rit != 999)
        return (false);

    return (true);
}

//====================================//
//      ITERATOR MODIFICATION         //
//====================================//
template <typename FtIterator, typename StdIterator>
bool    iterator_modification(FtIterator vecit, StdIterator compit) {
    // INC, DEREF, EQUALITY, MULTIPASS
    vecit++;
    compit++;
    if (*vecit != *compit)
        return (false);
    if(*(++compit) != *(++vecit) ||*(compit++) != *(vecit++))
        return (false);
    if (!(*compit == *vecit) || (*compit != *vecit))
        return (false);
    // DEC, DEREF, EQUALITY, MULTIPASS
    vecit--;
    compit--;
    if (*vecit != *compit)
        return (false);
    if(*(++compit) != *(++vecit) ||*(compit++) != *(vecit++))
        return (false);
    if (!(*compit == *vecit) || (*compit != *vecit))
        return (false);
    // ARITHMETIC OPERATORS
    FtIterator vecitB = vecit + 8;
    StdIterator compitB = compit + 8;
    if (*vecitB != *compitB)
        return (false);
    vecitB = 5 + vecitB;
    compitB = 5 + compitB;
    if (*vecitB != *compitB)
        return (false);
    vecitB = vecitB - 3;
    compitB = compitB - 3;
    if (*vecitB != *compitB)
        return (false);
    if ((vecitB - (vecit + 2)) != (compitB - (compit + 2)))
        return (false);

    // INEQUALITY COMPARISON
    if (!(vecit < vecitB == compit < compitB)
        || !(vecit > vecitB == compit > compitB)
        || !(vecit <= vecitB == compit <= compitB)
        || !(vecit >= vecitB == compit >= compitB))
        return (false);

    // COMPOUND ASSIGNMENT OPERATIONS
    vecitB += 13;
    compitB += 13;
    if (*vecitB != *compitB)
        return (false);
    vecitB -= 4;
    compitB -= 4;
    if (*vecitB != *compitB)
        return (false);
    if (vecitB[0] != compitB[0]
        || vecitB[1] != compitB[1]
        || vecitB[-1] != compitB[-1])
        return (false);

    return (true);
}

void    iterator_tests(void) {
    print_test_result("Iterator/Reverse Iterator Construction - ", iterator_construction<ft::vector<int> >());

    ft::vector<int>     vec;
    std::vector<int>    comp;
    for (size_t i = 0; i < 30; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }
    print_test_result("Iterator Modification - ", iterator_modification<ft::vector<int>::iterator, std::vector<int>::iterator>(vec.begin(), comp.begin()));
    print_test_result("Reverse Iterator Modification - ", iterator_modification<ft::vector<int>::reverse_iterator, std::vector<int>::reverse_iterator>(vec.rbegin(), comp.rbegin()));
}

#endif
