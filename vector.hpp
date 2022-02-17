#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>       // std::allocator
# include <iterator>     // std::iterator
# include <cstddef>      // ptrdiff_t, size_t

namespace ft {
    template<typename T>
    class vector {
        public:
            vector(void) : var(5) {}
            int var;

            // MEMBER TYPES
            typedef T                                                                           value_type;
            typedef typename std::allocator<value_type>                                         allocator_type;
            typedef typename allocator_type::reference                                          reference;
            typedef typename allocator_type::const_reference                                    const_reference;
            typedef typename allocator_type::pointer                                            pointer;
            typedef typename allocator_type::const_pointer                                      const_pointer;
            // should be convertable to const
            typedef typename std::iterator<std::random_access_iterator_tag, value_type>         iterator;
            // const in the right place?? cannot be convertable to non-const
            typedef typename std::iterator<const std::random_access_iterator_tag, value_type>   const_iterator;
            typedef typename std::reverse_iterator<iterator>                                    reverse_iterator;
            typedef typename std::reverse_iterator<const_iterator>                              const_reverse_iterator;
            typedef ptrdiff_t                                                                   difference_type;
            typedef size_t                                                                      size_type;

            // CONSTRUCTORS / DESTRUCTOR

    };
}

#endif
