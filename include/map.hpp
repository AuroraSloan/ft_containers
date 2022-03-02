#ifndef MAP_HPP
# define MAP_HPP

# include <memory>   // std::allocator
# include <iterator> // std::iterator
# include <cstddef>  // ptrdiff_t, size_t
# include <utility>  // std::pair

namespace ft {
    template<typename Key, typename T>
    class map {
        public:
            map(void) : var(5) {}
            int var;

            // MEMBER TYPES
            typedef Key                                                                           key_type;
            typedef T                                                                             mapped_type;
            typedef std::pair<const key_type, mapped_type>                                        value_type;
            typedef typename std::less<key_type>                                                  key_compare;
            // NEED TEMPLATE FOR VALUE_COMP?
            typedef typename std::allocator<value_type>                                           allocator_type;
            typedef typename allocator_type::reference                                            reference;
            typedef typename allocator_type::const_reference                                      const_reference;
            typedef typename allocator_type::pointer                                              pointer;
            typedef typename allocator_type::const_pointer                                        const_pointer;
            // should be convertable to const
            typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>           iterator;
            // const in the right place?? cannot be convertable to non-const
            typedef typename std::iterator<const std::bidirectional_iterator_tag, value_type>     const_iterator;
            typedef typename std::reverse_iterator<iterator>                                      reverse_iterator;
            typedef typename std::reverse_iterator<const_iterator>                                const_reverse_iterator;
            typedef ptrdiff_t                                                                           difference_type;
            typedef size_t                                                                              size_type;

            // CONSTRUCTORS / DESTRUCTOR

    };
}

#endif
