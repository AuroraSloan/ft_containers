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
        typedef Key                                                                 key_type;
        typedef T                                                                   mapped_type;
        typedef ft::pair<const key_type, mapped_type>                               value_type;
        typedef Compare                                                             key_compare;
        typedef Alloc                                                               allocator_type;
        typedef typename allocator_type::reference                                  reference;
        typedef typename allocator_type::const_reference                            const_reference;
        typedef typename allocator_type::pointer                                    pointer;
        typedef typename allocator_type::const_pointer                              const_pointer;
        typedef ptrdiff_t                                                           difference_type;
        typedef size_t                                                              size_type;

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
        typedef typename ft::_rb_map_tree<value_type, value_compare>    rb_tree;
        typedef typename rb_tree::iterator                                          iterator;
        typedef const iterator                                                      const_iterator;
        typedef typename rb_tree::reverse_iterator                                  reverse_iterator;
        typedef const reverse_iterator                                              const_reverse_iterator;

    private:
        key_compare     _key_comp;
        value_compare   _value_comp;
        rb_tree         _tree;
        allocator_type  _alloc;

    public:

        // CONSTRUCTORS / DESTRUCTOR
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _key_comp(comp), _value_comp(value_compare(_key_comp)), _tree(_value_comp), _alloc(alloc) {
            //std::cerr << "map default constructor called" << std::endl;
        }

        template <class InputIterator>
        map (InputIterator first,
             typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
             const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type()) : _key_comp(comp), _value_comp(value_compare(_key_comp)), _tree(_value_comp), _alloc(alloc) {
            //std::cerr << "map iterator constructor" << std::endl;
            while (first != last) {
                _tree.insert(*first++);
            }
        }
        map (const map& x) : _key_comp(x.key_comp()), _value_comp(x.value_comp()), _tree(x._tree), _alloc(allocator_type()) {
            //std::cerr << "map copy constructor called" << std::endl;
        }
        map& operator=(const map& rhs) {
            if (this != &rhs) {
                _tree = rhs._tree;
                _key_comp = rhs.key_comp();
                _value_comp = rhs.value_comp();
                //std::cerr << "map equal operator called" << std::endl;
            }
            return (*this);
        }

        ~map() {
            //std::cerr << "map destructor called" << std::endl;
        }



        // Iterators
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

        //size_type max_size() { return (_alloc.max_size()); }

        // ELEMENT ACCESS
        /*mapped_type& operator[](const key_type& k) {}*/

        // MODIFIERS
        ft::pair<iterator,bool> insert (const value_type& val) {
            return (_tree.insert(val));
        }
        /*iterator insert (iterator position, const value_type& val) {}
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last) {}
        void erase (iterator position) {}
        size_type erase (const key_type& k);
        void erase (iterator first, iterator last);*/
        /*void swap(map &x) {
            _swap(_begin, x._begin);
            _swap(_end, x._end);
            _swap(_size, x._size);
            _swap(_cap, x._cap);
            _swap(_alloc, x._alloc);
            _swap(_key_comp, x._key_comp);
        }*/
        void clear() { _tree.clear(); }

        // OBSERVERS
        key_compare key_comp() const { return (_key_comp); }
        value_compare value_comp() const { return (_tree.value_comp()); }

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
        void inOrderWalk() {
            _tree.inOrderWalk(_tree.getRoot());
        }
    private:



    };
}

#endif
