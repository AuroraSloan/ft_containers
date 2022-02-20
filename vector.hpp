#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>          // std::allocator
# include <iterator>        // std::iterator
# include <cstddef>         // ptrdiff_t, size_t
# include <iostream>        // std::cout

namespace ft {
    template<typename T, class Alloc = std::allocator<T> >
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
            explicit vector(allocator_type const & alloc = allocator_type()) : _begin(NULL), _end(NULL), _alloc(alloc) {}
            explicit vector(size_type n, value_type const & val = value_type(), allocator_type const & alloc = allocator_type()) : _alloc(alloc) {
                _vec = _alloc.allocate(n + 1);
                for(size_t i = 0; i < n; i++) {
                    _alloc.construct(_vec + i, val);
                }
            }
            /*template <class InputIterator>
                vector(InputIterator first, InputIterator last, allocator_type const & alloc = allocator_type()) {

                }
            vector(vector const & x) {}
            ~vector() {}
            */
            // ITERATORS
            /*iterator                begin() {}
            cons_iterator           begin() const {}
            iterator                end() {}
            const_iterator          end() const {}
            reverse_iterator        rbegin() {}
            const_reverse_iterator  rbegin() const {}
            reverse_iterator        rend() {}
            const_reverse_iterator  rend() const {}*/


            // CAPACITY
            size_type               size() { return (_end - _begin); }
            //size_type               max_size() {/*numeric limits?*/}
            //void                    resize() {}
            size_type               capacity() { return (_cap - _begin); }
            //bool                    empty() const { return (!size()) }
            //void                    reserve(size_type n) {}


            // ELEMENT ACCESS
            //reference               operator[](size_type n) {}
            //const_reference         operator[](size_type n) const {}
            //reference               at(size_type n) {}
            //const_reference         at(size_type n) const {}
            reference               front() { return (*_begin); }
            const_reference         front() const { return (*_begin); }
            reference               back() { return (*_end); }
            const_reference         back() const { return (*_end); }


            // MODIFIERS
            /*tmeplate <class InputIterator>
                void    assign(InputIterator first, InputIterator last) {
                }
            void        assign(size_type n, value_type const & val) {}
            void        push_back(value_type const & val) {}
            void        pop_back() {}
            iterator    insert(iterator position, value_type const & val) {}
            void        insert(iterator position, size_type n, value_type const & val) {}
            template <class InputIterator>
                void    insert(iterator position, InputIterator first, InputIterator last) {
                }
            iterator    erase(iterator position) {}
            iterator    erase(iterator first, iterator last) {}
            void        swap(vector & x) {}
            void        clear() {}*/


            // ALLOCATOR
            allocator_type      get_allocator() const { return (_alloc); }


        private:
            pointer         _begin;
            pointer         _end;
            pointer         _cap;
            allocator_type  _alloc;

    };
}

/*template <typename T, class Alloc>
    bool    operator==(ft::vector<T,Alloc> const & lhs, ft::vector<T,Alloc> const & rhs) {}
template <typename T, class Alloc>
    bool    operator!=(ft::vector<T,Alloc> const & lhs, ft::vector<T,Alloc> const & rhs) {}
template <typename T, class Alloc>
    bool    operator<(ft::vector<T,Alloc> const & lhs, ft::vector<T,Alloc> const & rhs) {}
template <typename T, class Alloc>
    bool    operator<=(ft::vector<T,Alloc> const & lhs, ft::vector<T,Alloc> const & rhs) {}
template <typename T, class Alloc>
    bool    operator>(ft::vector<T,Alloc> const & lhs, ft::vector<T,Alloc> const & rhs) {}
template <typename T, class Alloc>
    bool    operator>=(ft::vector<T,Alloc> const & lhs, ft::vector<T,Alloc> const & rhs) {}
template <typename T, class Alloc>
    void    swap(ft::vector<T,Alloc> const & lhs, ft::vector<T,Alloc> const & rhs) {}
*/
#endif
