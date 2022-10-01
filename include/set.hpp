#pragma once
#ifndef SET_HPP
# define SET_HPP

# include <memory>   // std::allocator
# include <iterator> // std::iterator
# include <cstddef>  // ptrdiff_t, size_t
# include "_rb_tree.hpp"
# include "utility.hpp" // ft::pair
# include "type_traits.hpp" // ft::enable_if

namespace ft {
    template<typename T,
            typename Compare = std::less<T>,
            typename Alloc = std::allocator<const T> >
    class set {
    public:

        // MEMBER TYPES
        typedef T                                                                   key_type;
        typedef T                                                                   value_type;
        typedef Compare                                                             key_compare;
        typedef Compare                                                             value_compare;
        typedef Alloc                                                               allocator_type;
        typedef typename allocator_type::reference                                  reference;
        typedef typename allocator_type::const_reference                            const_reference;
        typedef typename allocator_type::pointer                                    pointer;
        typedef typename allocator_type::const_pointer                              const_pointer;
        typedef typename ft::_rb_map_tree<key_type, value_compare>                  rb_tree;
        typedef typename rb_tree::iterator                                          iterator;
        typedef const iterator                                                      const_iterator;
        typedef typename rb_tree::reverse_iterator                                  reverse_iterator;
        typedef const reverse_iterator                                              const_reverse_iterator;
        typedef ptrdiff_t                                                           difference_type;
        typedef size_t                                                              size_type;

    private:
        key_compare     _key_comp;
        value_compare   _value_comp;
        rb_tree         _tree;
        allocator_type  _alloc;

    public:

        // CONSTRUCTORS / DESTRUCTOR
        explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                : _key_comp(comp), _value_comp(comp), _tree(_key_comp), _alloc(alloc) {}

        template <class InputIterator>
        set (InputIterator first,
             typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
             const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
             : _key_comp(comp), _value_comp(value_compare(_key_comp)), _tree(_value_comp), _alloc(alloc) {
            while (first != last) {
                _tree.insert(*first++);
            }
        }
        set (const set& x) : _key_comp(x.key_comp()), _value_comp(x.value_comp()), _tree(x._tree), _alloc(allocator_type()) {}

        set& operator=(const set& rhs) {
            if (this != &rhs) {
                _tree = rhs._tree;
                _key_comp = rhs.key_comp();
                _value_comp = rhs.value_comp();
            }
            return (*this);
        }

        ~set() {}


        // ITERATORS
        iterator begin() { return (_tree.begin()); }
        const_iterator begin() const { return (_tree.begin()); }
        iterator end() { return (_tree.end()); }
        const_iterator end() const { return (_tree.end()); }
        reverse_iterator rbegin() { return (_tree.rbegin()); }
        const_reverse_iterator rbegin() const { return (_tree.rbegin()); }
        reverse_iterator rend() { return (_tree.rend()); }
        const_reverse_iterator rend() const { return (_tree.rend()); }


        // CAPACITY
        bool empty() const { return (_tree.empty()); }
        size_type size() const { return (_tree.size()); }
        size_type max_size() const { return (_tree.max_size()); }


        // MODIFIERS
        ft::pair<iterator,bool> insert (const value_type& val) {
            return (_tree.insert(val));
        }
        iterator insert (iterator position, const value_type& val) {
            return (_tree.insert(position, val));
        }
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last) {
            _tree.insert(first, last);
        }

        void erase (iterator position) {
            _tree.erase((position));
        }
        void erase (iterator first, iterator last) {
            _tree.erase(first, last);
        }
        size_type erase (const key_type& k) {
            return (_tree.erase(k));
        }

        void swap(set &x) {
            if (this != &x) {
                _tree.swap(x._tree);
            }
        }

        void clear() { _tree.clear(); }

        // OBSERVERS
        key_compare key_comp() const { return (_key_comp); }
        value_compare value_comp() const { return (_tree.value_comp()); }


        // OPERATIONS
        iterator find (const key_type& k) {
            return (iterator(_tree.find(k)));
        }
        const_iterator find (const key_type& k) const {
            return (const_iterator(_tree.find(k)));
        }

        size_type count (const key_type& k) const {
            return(_tree.count(k));
        }

        iterator lower_bound (const key_type& k) {
            return(_lower_bound(k));
        }
        const_iterator lower_bound (const key_type& k) const {
            return (_lower_bound(k));
        }

        iterator upper_bound (const key_type& k) {
            return (_upper_bound(k));
        }
        const_iterator upper_bound (const key_type& k) const {
            return (_upper_bound(k));
        }
        pair<iterator,iterator>             equal_range(const key_type& k) {
            return _equal_range(k);
        }
        pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
            return _equal_range(k);
        }

        // ALLOCATOR
        allocator_type get_allocator() const { return (_alloc); }

    private:
        bool _keys_equal(const key_type & a, const key_type& b) const {
            return (!_key_comp(a, b) && !_key_comp(b, a));
        }

        iterator _lower_bound (const key_type& k) const {
            iterator begin(_tree.begin());

            for (;begin != _tree.end(); begin++) {
                if (_keys_equal(k, *begin) || _key_comp(k, *begin)) {
                    break ;
                }
            }
            return (begin);
        }
        iterator _upper_bound (const key_type& k) const {
            iterator begin(_tree.begin());

            for (;begin != _tree.end(); begin++) {
                if (_key_comp(k, *begin)) {
                    break ;
                }
            }
            return (begin);

        }
        ft::pair<iterator,iterator>     _equal_range(const key_type& k) const {
            return (ft::make_pair(_lower_bound(k), _upper_bound(k)));
        }
    };
}

#endif
