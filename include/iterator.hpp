#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>         // ptrdiff_t, size_t

namespace ft {

    // ITERATOR TRAITS
    template <typename Iterator>
    struct iterator_traits {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };

    // === if we make an iterator from a regular pointer we will have access to all the types we need....=== //
    template <typename T>
    struct iterator_traits<T*> {
        typedef ptrdiff_t                                   difference_type;
        typedef T                                           value_type;
        typedef T*                                          pointer;
        typedef T&                                          reference;
        typedef typename std::random_access_iterator_tag    iterator_category;
    };
    template <typename T>
    struct iterator_traits<const T*> {
        typedef ptrdiff_t const                                     difference_type;
        typedef T const                                             value_type;
        typedef T* const                                            pointer;
        typedef T&                                                  reference;
        typedef typename std::random_access_iterator_tag const      iterator_category;
    };

}
#endif
