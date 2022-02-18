#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>          // std::allocator
# include <iterator>        // std::iterator
# include <cstddef>         // ptrdiff_t, size_t
# include <iostream>        // std::cout

namespace ft {
    template<typename T, typename Alloc = std::allocator<T> >
    class vector {
        public:
            //vector(void) : var(5) {}
            //int var;

            // MEMBER TYPES
            typedef T                                                                           value_type;
            typedef Alloc                                                                       allocator_type;
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
            explicit vector(allocator_type const & alloc = allocator_type()) : _alloc(alloc) {
                _arr = _alloc.allocate(1);
                _alloc.construct(_arr, 0);
                //std::cout << alloc.max_size() << '\n';
            }
            /*explicit vector(size_type n, value_type const & val = value_type()) {}
            template <typename InputIterator>
                vector(InputIterator first, InputIterator last, allocator_type const & alloc = allocator_type()) {

                }
            vector(vector const & x) {}*/
        private:
            T*  _arr;
            allocator_type _alloc;

    };
}

#endif
