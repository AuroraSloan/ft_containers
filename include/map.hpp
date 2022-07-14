#ifndef MAP_HPP
# define MAP_HPP

# include <memory>   // std::allocator
# include <iterator> // std::iterator
# include <cstddef>  // ptrdiff_t, size_t
# include "_rb_tree.hpp"
# include "utility.hpp" // ft::pair

namespace ft {
    template<typename Key,
             typename T,
             typename Compare = std::less<Key>,
             typename Alloc = std::allocator<ft::pair<const Key,T> > >
    class map {
    public:

        // MEMBER TYPES
        typedef Key                                                                          key_type;
        typedef T                                                                            mapped_type;
        typedef ft::pair<const key_type, mapped_type>                                        value_type;
        typedef Compare                                                                      key_compare;
        typedef Alloc                                                                        allocator_type;
        typedef typename allocator_type::reference                                           reference;
        typedef typename allocator_type::const_reference                                     const_reference;
        typedef typename allocator_type::pointer                                             pointer;
        typedef typename allocator_type::const_pointer                                       const_pointer;
        // should be convertable to const
        typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>          iterator;
        typedef const iterator                                                               const_iterator;
        typedef typename ft::reverse_iterator<iterator>                                      reverse_iterator;
        typedef const reverse_iterator                                                       const_reverse_iterator;
        typedef ptrdiff_t                                                                    difference_type;
        typedef size_t                                                                       size_type;

    private:
        pointer _begin;
        pointer _end;
        size_t _size;
        size_t _cap;
        key_compare _key_comp;
        allocator_type _alloc;

    public:

        // CONSTRUCTORS / DESTRUCTOR
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _begin(NULL), _end(NULL), _size(0), _cap(0), _key_comp(comp), _alloc(alloc) {}

        template <class InputIterator>
        map (InputIterator first,
             typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
             const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type()) : _key_comp(comp), _alloc(alloc) {
            size_type n = static_cast<size_type>(std::distance(first, last));
            // need to check for duplicates? maybe I am using vector of pairs as iterators?
            _allocate(n);
            _construct(_end, n, first);
        }
        map (const map& x) : _key_comp(key_compare()), _alloc(allocator_type()) {
            _allocate(x._cap);
            _construct(_end, x._size, x._begin);
        }

        ~map() {
            _dealoc();
        }

        map& operator=(const map& rhs) {
            if (this != &rhs) {
                _dealoc();
                //_alloc = rhs._alloc;
                _key_comp = rhs.key_comp();
                _size = 0;
                _allocate(rhs.size());
                _construct(_end, rhs.size(), rhs._begin);
            }
            return (*this);
        }

        // Iterators
        iterator begin() { return (iterator(_begin)); }

        const_iterator begin() const { return (const_iterator(_begin)); }

        iterator end() { return (iterator(_end)); }

        const_iterator end() const { return (const_iterator(_end)); }

        reverse_iterator rbegin() { return (reverse_iterator(_end)); }

        const_reverse_iterator rbegin() const { return (const_reverse_iterator(_end)); }

        reverse_iterator rend() { return (reverse_iterator(_begin)); }

        const_reverse_iterator rend() const { return (const_reverse_iterator(_begin)); }

        // CAPACITY
        bool empty() const { return (!size()); }

        size_type size() const { return (_size); }

        size_type max_size() { return (_alloc.max_size()); }

        // ELEMENT ACCESS
        /*mapped_type& operator[](const key_type& k) {}*/

        // MODIFIERS
        /*pair<iterator,bool> insert (const value_type& val) {}
        iterator insert (iterator position, const value_type& val) {}
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last) {}
        void erase (iterator position) {}
        size_type erase (const key_type& k);
        void erase (iterator first, iterator last);*/
        void swap(map &x) {
            _swap(_begin, x._begin);
            _swap(_end, x._end);
            _swap(_size, x._size);
            _swap(_cap, x._cap);
            _swap(_alloc, x._alloc);
            _swap(_key_comp, x._key_comp);
        }
        void clear() {
            while (_end > _begin)
                _alloc.destroy(--_end);
            _size = 0;
        }

        // OBSERVERS
        key_compare key_comp() const { return (_key_comp); }

        class value_compare : std::binary_function<value_type, value_type, bool> {
            friend class map;
        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}
        public:
            bool operator()(const value_type& x, const value_type& y) const {
                return (comp(x.first, y.first));
            }
        };

        // OPERATIONS
        /*iterator find (const key_type& k) {}
        const_iterator find (const key_type& k) const {}
        size_type count (const key_type& k) const {}
        iterator lower_bound (const key_type& k) {}
        const_iterator lower_bound (const key_type& k) const {}
        iterator upper_bound (const key_type& k) {}
        const_iterator upper_bound (const key_type& k) const {}
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const {}
        pair<iterator,iterator>             equal_range (const key_type& k) {}*/

        // ALLOCATOR
        allocator_type get_allocator() const { return (_alloc); }
    private:
        void _dealoc(void) {
            clear();
            _alloc.deallocate(_begin, _size);
        }

        void _construct(pointer &start, size_type n, pointer src) {
            for (size_type i = 0; i < n; i++) {
                _alloc.construct(start++, *(src + i));
                _size++;
            }
        }

        void _allocate(size_type n) {
            _begin = _alloc.allocate(n);
            _end = _begin;
            _cap = n;
            _size = 0;
        }

        template<typename S>
        void _swap(S &a, S &b) {
            S tmp = a;
            a = b;
            b = tmp;
        }
    };
}

#endif
