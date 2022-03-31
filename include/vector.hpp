#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>          // std::allocator
# include <iterator>        // std::iterator
# include <cstddef>         // ptrdiff_t, size_t
# include <iostream>        // std::cout
# include <stdexcept>
# include "iterator.hpp"
# include "utils.hpp"

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
        explicit vector(allocator_type const & alloc = allocator_type()) : _begin(NULL), _end(NULL), _size(0), _cap(0), _alloc(alloc) {}
        explicit vector(size_type n, value_type const & val = value_type(), allocator_type const & alloc = allocator_type()) : _alloc(alloc) {
            _allocate(n);
            _construct(_end, n, val);
        }
        ~vector() {
            _dealoc();
        }
        // do enable if, ad tests...... figure out test main.cpp
        /*template <class InputIterator>
        vector(InputIterator first, InputIterator last, allocator_type const & alloc = allocator_type()) : _alloc(alloc) {
            size_type n = static_cast<size_type>(std::distance(first, last));
            _allocate(n);
            _construct(_end, n, first);
        }*/
        vector(vector const & x) : _alloc(allocator_type()) {
            _allocate(x._cap);
            _construct(_end, x._size, x._begin);
        }

        vector& operator=(const vector& rhs) {
            if (this != &rhs) {
                _dealoc();
                _alloc = rhs._alloc;
                _size = 0;
                _allocate(rhs.capacity());
                _construct(_end, rhs.size(), rhs._begin);
            }
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
        size_type               size() const { return (_size); }
        size_type               max_size() { return (_alloc.max_size()); }
        /*void                    resize(size_type n, value_type val = value_type()) {
        //inserts and erases
        }*/
        size_type               capacity() const { return (_cap); }
        bool                    empty() const { return (!size()); }
        void                    reserve(size_type n) {
            // try to use _dealloc _alloc and _construct later
            pointer     _newBegin, _newEnd;
            size_type   tmpSize = _size;

            if (!_passedMaxCapacity(n)) {
                std::cout << "returning\n";
                return ;
            }
            _newBegin = _alloc.allocate(n);
            _newEnd = _newBegin;
            _construct(_newEnd, _begin);
            _dealoc();
            _begin = _newBegin;
            _end = _newEnd;
            _size = tmpSize;
            _cap = n;
        }


        // ELEMENT ACCESS
        reference               operator[](size_type n) { return (*(_begin + n)); }
        const_reference         operator[](size_type n) const { return (*(_begin + n)); }
        reference               at(size_type n) {
            if (n >= size())
                throw std::out_of_range("vector");
            return (_begin[n]);
        }
        const_reference         at(size_type n) const {
            if (n >= size())
                throw std::out_of_range("vector");
            return (_begin[n]);
        }
        reference               front() { return (*_begin); }
        const_reference         front() const { return (*_begin); }
        reference               back() {
            if (!empty())
                return (*(_end - 1));
        }
        const_reference         back() const {
            if (!empty())
                return (*(_end - 1));
        }


        // MODIFIERS
        template <class InputIterator> //====NEED TO CHECK FOR AT LEAST FORWARD ITERATOR====//
        void assign(InputIterator first, InputIterator last) {
            size_type  dist = static_cast<size_type>(std::distance(first, last));
            if (_passedMaxCapacity(dist)) {
                _dealoc();
                _allocate(dist * 2);
                _cap = dist * 2;
            }else {
                clear();
            }
            _construct(_end, dist, first);
        }
        void        assign(size_type n, value_type const & val) {
            if (_passedMaxCapacity(n)) {
                _dealoc();
                _allocate(n);
                _cap = n;
            } else {
                clear();
            }
            _construct(_end, n, val);
        }
        void        push_back(value_type const & val) {
            if (_atMaxCapacity())
                reserve((size() == 0 ? 1 : size()) * 2);
            *(_end++) = val;
            _size++;
        }
        void        pop_back() {
            if (!empty()) {
                _alloc.destroy(--_end);
                _size--;
            }
        }
        iterator    insert(iterator position, value_type const & val) {
            pointer _p;
            size_type location = static_cast<size_type>(std::distance(begin(), position));

            if (_atMaxCapacity())
                reserve(size() * 2);
            _p = _begin + location;
            _construct_from_end(_p, 1);
            _alloc.destroy(_p);
            _alloc.construct(_p, val);
            _size++;
            return (iterator(_p));
        }
        void        insert(iterator position, size_type n, value_type const & val) {
            pointer _pbegin, _pend;
            size_type location = static_cast<size_type>(std::distance(begin(), position));

            if (_passedMaxCapacity(_size + n))
                reserve((_size + n) * 2);
            _pbegin = _begin + location;
            _pend = _begin + location + n;
            _construct_from_end(_pend, n);
            for (size_type i = 0; i < n; i++) {
                _alloc.destroy(_pbegin + i);
                _alloc.construct(_pbegin + i, val);
                _size++;
            }
        }
        template <class InputIterator>// check that Input iterator is compatible with value_type
        void    insert(iterator position, InputIterator first, InputIterator last) {
            pointer _pbegin, _pend;
            size_type location = static_cast<size_type>(std::distance(begin(), position));
            size_type n = static_cast<size_type>(std::distance(first, last));

            if (_passedMaxCapacity(_size + n))
                reserve((_size + n) * 2);
            _pbegin = _begin + location;
            _pend = _begin + location + n;
            _construct_from_end(_pend, n);
            for (size_type i = 0; i < n; i++) {
                _alloc.destroy(_pbegin + i);
                _alloc.construct(_pbegin + i, *(first + i));
                _size++;
            }
        }
        iterator    erase(iterator position) {
            return (_erase(position, 1));
        }
        iterator    erase(iterator first, iterator last) {
            return (_erase(first, static_cast<size_type>(std::distance(first, last))));
        }
        void        swap(vector & x) {
           _swap(_begin, x._begin);
           _swap(_end, x._end);
           _swap(_size, x._size);
           _swap(_cap, x._cap);
           _swap(_alloc, x._alloc);
        }
        void        clear() {
            while(_end > _begin)
                _alloc.destroy(--_end);
            _size = 0;
        }


        // ALLOCATOR
        allocator_type      get_allocator() const { return (_alloc); }


    private:
        pointer         _begin;
        pointer         _end;
        size_t          _size;
        size_t          _cap;
        allocator_type  _alloc;

        void    _dealoc(void) {
            clear();
            _alloc.deallocate(_begin, capacity());
        }
        void    _allocate(size_type n) {
            _begin = _alloc.allocate(n);
            _end = _begin;
            _cap = n;
            _size = 0;
        }

        void    _construct(pointer & start, size_type n, value_type val) {
            for(size_type i = 0; i < n; i++) {
                _alloc.construct(start++, val);
                _size++;
            }
        }
        void    _construct(pointer & start, size_type n, pointer src) {
            for(size_type i = 0; i < n; i++) {
                _alloc.construct(start++, *(src + i));
                _size++;
            }
        }
        void    _construct(pointer & start, pointer src) {
            for(size_type i = 0; i < _size; i++)
                _alloc.construct(start++, *(src + i));
        }
//        template <typename InputIterator>
        void    _construct(pointer & start, size_type n, iterator src) {
            for(size_type i = 0; i < n; i++) {
                _alloc.construct(start++, *(src + i));
                _size++;
            }
        }
        void    _construct_from_end(pointer & position, size_type n) {
            _end += n;
            if (_end - 1 == position)
                return ;
            for (size_type i = 1; _end - i >= position; i++) {
                _alloc.destroy(_end - i);
                _alloc.construct(_end - i, *(_end - i - n));
            }
        }
        iterator    _erase(iterator position, size_type n) {
            pointer start = _begin + static_cast<size_type>(std::distance(begin(), position));
            size_type j = 0;

            for (; j < n; j++) {
                _alloc.destroy(start + j);
                _size--;
            }
            for(size_type i = 0; start + j != _end; i++) {
                _alloc.destroy(start + i);
                _alloc.construct(start + i, *(start + j));
                j++;
            }
            _end = _begin + _size;
            _alloc.destroy(_end);

            return (iterator(start));
        }
        template <typename S>
        void    _swap(S & a, S & b) {
            S tmp = a;
            a = b;
            b = tmp;
        }

        bool    _atMaxCapacity(void) { return (_size == _cap); }
        bool    _passedMaxCapacity(size_type n) { return (n > _cap); }

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
