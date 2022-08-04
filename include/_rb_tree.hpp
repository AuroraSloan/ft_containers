#ifndef _RB_TREE_HPP
# define _RB_TREE_HPP

# include <iterator>
# include <iostream>
# include "iterator.hpp"

namespace ft {

    enum color_bool { black, red };

    template <typename node_type>
    node_type* tree_min(node_type* node, node_type* nil) {
        while (node->left != nil) {
            node = node->left;
        }
        return (node);
    }

    template <typename node_type>
    node_type* tree_max(node_type* node, node_type* nil) {
        while (node->right != nil) {
            node = node->right;
        }
        return (node);
    }

    template <typename T>
    struct _rb_node {
        typedef _rb_node*   node_ptr;
        typedef T           value_type;

        value_type  value;
        node_ptr    left;
        node_ptr    right;
        node_ptr    parent;
        bool        color;

        _rb_node() : value(), left(), right(), parent(), color(black) {}
        explicit _rb_node(const value_type val) : value(val), left(), right(), parent(), color(red) {}
        _rb_node(const _rb_node& src) : value(src.value), left(src.left), right(src.right), parent(src.parent), color(src.color) {}
        ~_rb_node() {}

        _rb_node& operator=(const _rb_node& rhs) {
            if (this != &rhs) {
                value = rhs.value;
                left = rhs.left;
                right = rhs.right;
                parent = rhs.parent;
                color = rhs.color;
            }
            return (*this);
        }
    };

    // ITERATOR
    template <typename T, typename node_type>
    class _tree_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {

    public:
        typedef T                                                           value_type;
        typedef value_type*                                                 pointer;
        typedef value_type&                                                 reference;
        typedef typename ft::iterator_traits<node_type*>::difference_type   difference_type;
        typedef typename ft::iterator_traits<node_type*>::value_type        node_value_type;
        typedef typename ft::iterator_traits<node_type*>::pointer           node_pointer;
        typedef typename ft::iterator_traits<node_type*>::reference         node_reference;
        typedef typename ft::iterator_traits<node_type*>::iterator_category iterator_category;

        _tree_iterator() : _data(), _nil() {}
        _tree_iterator(node_pointer x) : _data(x), _nil() {}
        _tree_iterator(_tree_iterator const & src) : _data(src._data), _nil(src._nil) {}
        ~_tree_iterator() {}

        reference   operator*() const { return (_data->value); }
        pointer     operator->() const { return (&_data->value); }

        _tree_iterator& operator=(_tree_iterator const &rhs) {
            if (this != &rhs) {
                _data = rhs._data;
                _nil = rhs._nil;
            }
            return (*this);
        }

        _tree_iterator& operator++() {
            if (_data->right != _nil) {
                _data = ft::tree_min(_data->right, _nil);
            } else {
                while (_data->parent != _nil && _data == _data->parent->right) {
                    _data = _data->parent;
                }
                _data = _data->parent;
            }
            return (*this);
        }

        _tree_iterator operator++(int) {
            _tree_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        _tree_iterator & operator--() {
            if (_data->left != _nil) {
                _data = (ft::tree_max(_data->left, _nil));
            } else {
                while (_data->parent != _nil && _data == _data->parent->left) {
                    _data = _data->parent;
                }
                _data = _data->parent;
            }
            return (*this);
        }

        _tree_iterator operator--(int) {
            _tree_iterator tmp(*this);
            --(*this);
            return tmp;
        }

        node_pointer base() const { return (_data); }

    private:
        node_pointer _data;
        node_pointer _nil;

    };
    template <typename T>
    bool operator==(ft::_tree_iterator<T, _rb_node<T> > const &lhs, ft::_tree_iterator<T, _rb_node<T> > const &rhs) {
        return (lhs.base() == rhs.base());
    }
    template <typename T>
    bool operator!=(ft::_tree_iterator<T, _rb_node<T> > const &lhs, ft::_tree_iterator<T, _rb_node<T> > const &rhs) {
        return (lhs.base() != rhs.base());
    }

    // TREE REVERSE ITERATOR
    template <typename Iterator>
    class _tree_reverse_iterator {
    public:
        typedef Iterator                                                    iterator_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
        typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
        typedef typename ft::iterator_traits<Iterator>::reference           reference;
        typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
        iterator_type _rit;

        // CONSTRUCTORS
        _tree_reverse_iterator() : _rit() {}
        explicit _tree_reverse_iterator(iterator_type it) : _rit(it) {}

        template <typename iter>
        _tree_reverse_iterator(_tree_reverse_iterator<iter> const & rev_it) : _rit(rev_it.base()) {}

        iterator_type base() const { return (_rit); }
        reference   operator*() const {
            iterator_type tmp = _rit.base();
            return (*--tmp);
        }
        pointer     operator->() const { return (&(*_rit)); }

        _tree_reverse_iterator & operator++() {
            --_rit;
            return (*this);
        }
        _tree_reverse_iterator operator++(int) {
            _tree_reverse_iterator tmp(*this);
            _rit--;
            return tmp;
        }

        _tree_reverse_iterator & operator--() {
            ++_rit;
            return (*this);
        }
        _tree_reverse_iterator operator--(int) {
            _tree_reverse_iterator tmp(*this);
            _rit++;
            return tmp;
        }

    };
    template <typename Iterator>
    bool operator==(_tree_reverse_iterator<Iterator> const & lhs, _tree_reverse_iterator<Iterator> const & rhs) { return (lhs.base() == rhs.base()); }
    template <typename Iterator>
    bool operator!=(_tree_reverse_iterator<Iterator> const & lhs, _tree_reverse_iterator<Iterator> const & rhs) { return (lhs.base() != rhs.base()); }

    // RED BLACK TREE
    template <typename T, class Comp, class Alloc = std::allocator<_rb_node<T> > >
    class _rb_map_tree {
    public:

        typedef T                                       value_type;
        typedef _rb_node<T>                             node;
        typedef Comp                                    value_compare;
        typedef Alloc                                   allocator_type;
        typedef size_t                                  size_type;
        typedef _tree_iterator<T, node>                 iterator;
        typedef const _tree_iterator<T, node>           const_iterator;
        typedef _tree_reverse_iterator<iterator>        reverse_iterator;
        typedef const _tree_reverse_iterator<iterator>  const_reverse_iterator;
        typedef typename allocator_type::reference      node_reference;
        typedef typename allocator_type::pointer        node_pointer;

    private:
        node_pointer    _root;
        node_pointer    _begin;
        node_pointer    _end;
        node_pointer    _nil;
        value_compare   _comp;
        Alloc           _alloc;
        size_type       _size;

    public:
        // CONSTRUCTORS / DESTRUCTORS
        explicit _rb_map_tree(const Comp& comp, const allocator_type& alloc = allocator_type()) : _root(), _begin(), _nil(), _comp(comp), _alloc(alloc), _size(0) {
            //std::cerr << "tree default constructor called\n";
            _end = _alloc.allocate(1);
            _alloc.construct(_end, node());
        }

        _rb_map_tree(const _rb_map_tree& src) : _root(), _begin(), _nil(src._nil), _comp(src._comp), _alloc(allocator_type()) {
            //std::cerr << "tree copy constructor called\n";
            _size = 0;
            _end = _alloc.allocate(1);
            _alloc.construct(_end, node());
            _insert_nodes(src._root, src._end);
        }

        _rb_map_tree& operator=(const _rb_map_tree& rhs) {
            //std::cerr << "tree equal operator overload called\n";
            if (this != &rhs) {
                clear();
                _size = 0;
                _comp = rhs._comp;
                _nil = rhs._nil;
                _end = _alloc.allocate(1);
                _alloc.construct(_end, node());
                _insert_nodes(rhs._root, rhs._end);
            }
            return (*this);
        }
        ~_rb_map_tree() {
            //std::cerr << "tree destructor called\n";
            clear();
        }
        bool search(node_pointer src, value_type& val) {
            if (src != _nil && src != _end) {
                search(src->left, val);
                search(src->right, val);
            }
        }

        /*iterator insert (iterator position, const value_type& val) {
            return (iterator());
        }
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last) {
        }*/
        ft::pair<iterator, bool> insert(const value_type& val) {
            node_pointer y = _nil;
            node_pointer x = _root;
            //std::cerr << "inserting: " << node->value << '\n';
            while (x != _nil && x != _end) {
                y = x;
                /*if (node->value < x->value) {*/
                if (_comp(val, x->value)) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }
            if (x != _nil && x == y->right && !(_comp(y->value, val))) {
                return (ft::make_pair(iterator(y), false));
            }
            node_pointer new_node = _alloc.allocate(1);
            _alloc.construct(new_node, node(val));
            new_node->parent = y;
            if (y == _nil) {
                _root = new_node;
            } else if (new_node->value < y->value) {
                y->left = new_node;
            } else {
                y->right = new_node;
            }
            if (_begin == _nil || new_node->value < _begin->value) {
                _begin = new_node;
            }
            if (!_end->parent || new_node->value > _end->parent->value) {
                _end->parent = new_node;
                new_node->right = _end;
            }
            _size++;
            return (ft::make_pair(iterator(new_node), true));
        }

        void tree_transplant(node_pointer u, node_pointer v) {
            // need to deallocate and reallocate nodes?
            if (u->parent == _nil) {
                _root = v;
            } else if (u == u->parent->left) {
                u->parent->left = v;
            } else {
                u->parent->right = v;
            }
            if (v != _nil) {
                v->parent = u->parent;
            }
        }

        void tree_delete(node_pointer node) {
            node_pointer y = _nil;
            node_pointer x = _root;
            if (node->left == _nil) {
                tree_transplant(node, node->right);
            } else if (node->right == _nil) {
                tree_transplant(node, node->left);
            } else {
               if (y->parent != node) {
                   tree_transplant(y, y->right);
                   y->right = node->right;
                   y->right->parent = y;
               }
               tree_transplant(node, y);
               y->left = node->left;
               y->left->parent = y;
            }
        }

        void inOrderWalk(node_pointer x) {
            if (x != _nil && x != _end) {
                inOrderWalk(x->left);
                inOrderWalk(x->right);
                std::cout << "key: " << x->value.first << " - value: " << x->value.second << '\n';
            }
        }

        iterator begin() { return (iterator(_begin)); }
        const_iterator begin() const { return (const_iterator(_begin)); }

        iterator end() { return (iterator(_end)); }
        const_iterator end() const { return (const_iterator(_end)); }

        reverse_iterator rbegin() { return (reverse_iterator(_end)); }
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(_end)); }

        reverse_iterator rend() { return (reverse_iterator(_begin)); }
        const_reverse_iterator rend() const { return (const_reverse_iterator(_begin)); }

        size_type size() const { return (_size); }
        size_type empty() const { return (!_size); }
        size_type max_size() { return (_alloc.max_size()); }

        void clear () {
            _free_nodes(_root, _end);
            _alloc.destroy(_end);
            _alloc.deallocate(_end, 1);
        }

        node_pointer getRoot() const { return (_root); }
        value_compare value_comp() const { return (_comp); }

    private:
        void _free_nodes(node_pointer src, node_pointer end) {
            if (src != _nil && src != end) {
                //std::cerr << "destructing: " << src->value << '\n';
                _free_nodes(src->left, end);
                _free_nodes(src->right, end);
                _alloc.destroy(src);
                _alloc.deallocate(src, 1);
            }
        }

        void _insert_nodes(node_pointer src, node_pointer end) {
            if (src != _nil && src != end) {
                _insert_nodes(src->left, end);
                _insert_nodes(src->right, end);
                insert(src->value);
                /*node_pointer new_node = _alloc.allocate(1);
                _alloc.construct(new_node, node(src->value));
                //std::cerr << "constructing: " << new_node->value << '\n';
                tree_insert(new_node);*/
            }
        }

    };
}

#endif
