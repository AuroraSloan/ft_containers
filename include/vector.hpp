#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>          // std::allocator
# include <iterator>        // std::iterator
# include <cstddef>         // ptrdiff_t, size_t
# include <iostream>        // std::cout
# include "iterator.hpp"

namespace ft {
    template<typename T, class Alloc = std::allocator<T> >
    class vector {
        public:
            //vector(void) : var(5) {}
            //int var;


            // MEMBER TYPES
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            // should be convertable to const
            typedef typename ft::random_access_iterator<T>      iterator;
            // const in the right place?? cannot be convertable to non-const
            /* Constant iterators are iterators that do not fulfill the requirements of an output iterator;
            *  Dereferencing them yields a reference to a constant element (such as const T&).
            */
            typedef const iterator                              const_iterator;
            // should be convertable to const
            typedef typename ft::reverse_iterator<iterator>     reverse_iterator;
            // const in the right place?? cannot be convertable to non-const
            typedef const reverse_iterator                      const_reverse_iterator;
            typedef ptrdiff_t                                   difference_type;
            typedef size_t                                      size_type;


            // CONSTRUCTORS / DESTRUCTOR
            explicit vector(allocator_type const & alloc = allocator_type()) : _begin(NULL), _end(NULL), _alloc(alloc) {}
            explicit vector(size_type n, value_type const & val = value_type(), allocator_type const & alloc = allocator_type()) : _alloc(alloc) {
                size_type i = 0;

                _begin = _alloc.allocate(n);
                for(; i < n; i++)
                    _alloc.construct(_begin + i, val);
                _end = _begin + i;
                _cap = _end;
            }
            ~vector() {
                __dealoc(_begin, size());
            }
            /*template <class InputIterator>
             * ///////NEED TO ADD TESTS TO VECTOR CONSTRUCTOR TESTESt a
                vector(InputIterator first, InputIterator last, allocator_type const & alloc = allocator_type()) {

                }*/
            vector(vector const & x) : _alloc(allocator_type()) {
                size_type   n = x.size();
                size_type   i = 0;

                _begin = _alloc.allocate(n);
                for(; i < n; i++)
                    _alloc.construct(_begin + i, *(x._begin + i));
                _end = _begin + i;
                _cap = _end;
            }

            vector& operator=(const vector& rhs) {
                size_type   i = 0;
                size_type   n = rhs.size();

                if (this == &rhs)
                    return (*this);
                __dealoc(_begin, size());
                _alloc = rhs._alloc;
                _begin = _alloc.allocate(n);
                for(; i < n; i++)
                    _alloc.construct(_begin + i, *(rhs._begin + i));
                _end = _begin + i;
                _cap = _end;
                return (*this);
            }

            // ITERATORS
            iterator                begin() { return (iterator(_begin)); }
            const_iterator          begin() const { return (const_iterator(_begin)); }
            iterator                end() { return (iterator(_end)); }
            const_iterator          end() const { return (const_iterator(_end)); }
            reverse_iterator        rbegin() { return (reverse_iterator(_end)); }
            const_reverse_iterator  rbegin() const { return (const_reverse_iterator(_end)); }
            reverse_iterator        rend() { return (reverse_iterator(_begin)); }
            const_reverse_iterator  rend() const { return (const_reverse_iterator(_begin)); }


            // CAPACITY
            size_type               size() const { return (_end - _begin); }
            //size_type               max_size() {/*numeric limits?allocator::max_size?*/}
            //void                    resize() {}
            size_type               capacity() const { return (_cap - _begin); }
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

            void    __dealoc(pointer begin, size_type n) {
                for(size_type i = 0; i < n; i++)
                    _alloc.destroy(begin + i);
                _alloc.deallocate(begin, n);
            }

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
