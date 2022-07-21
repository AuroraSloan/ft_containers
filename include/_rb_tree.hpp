#include <iterator>
#include <iostream>
#include "iterator.hpp"

namespace ft {

    enum color_bool { black, red };

    template <typename node_type>
    node_type& tree_min(node_type& node, const node_type& nil) {
        while (node->left != nil) {
            node = node->left;
        }
        return (node);
    }

    template <typename node_type>
    node_type& tree_max(node_type& node, const node_type& nil) {
        while (node->right != nil) {
            node = node->right;
        }
        return (node);
    }

    template <typename T>
    struct _rb_node {
        typedef _rb_node*   _base_node;
        typedef T           value_type;

        value_type  key;
        _base_node  left;
        _base_node  right;
        _base_node  parent;
        bool        color;

        _rb_node() : key(), left(), right(), parent(), color(black) {}
        explicit _rb_node(const T& value) : key(value), left(), right(), parent(), color(red) {}
        _rb_node(const _rb_node& src) : key(src.key), left(src.left), right(src.right), parent(src.parent), color(src.color) {}
        ~_rb_node() {}

        _rb_node& operator=(const _rb_node& rhs) {
            if (this != &rhs) {
                key = rhs.key;
                left = rhs.left;
                right = rhs.right;
                parent = rhs.parent;
                color = rhs.color;
            }
            return (*this);
        }
    };

    // ITERATOR
    template <typename T>
    class _tree_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {

    public:
        typedef typename ft::iterator_traits<T*>::difference_type       difference_type;
        typedef typename ft::iterator_traits<T*>::value_type            value_type;
        typedef typename ft::iterator_traits<T*>::pointer               pointer;
        typedef typename ft::iterator_traits<T*>::reference             reference;
        typedef typename ft::iterator_traits<T*>::iterator_category     iterator_category;

        _tree_iterator() : _data(), _nil() {}
        _tree_iterator(value_type *x) : _data(x), _nil() {}
        _tree_iterator(_tree_iterator const & src) : _data(src._data), _nil() {}
        ~_tree_iterator() {}

        reference   operator*() const { return (*_data); }
        pointer     operator->() const { return (_data); }

        _tree_iterator& operator=(_tree_iterator const &rhs) {
            if (this != &rhs) {
                _data = rhs->_data;
                _nil = rhs->_nil;
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

        pointer base() const { return (_data); }

    private:
        pointer _data;
        pointer _nil;

    };
    template <typename T>
    bool operator==(ft::_tree_iterator<T> const &lhs, ft::_tree_iterator<T> const &rhs) { return (lhs.base() == rhs.base()); }
    template <typename T>
    bool operator!=(ft::_tree_iterator<T> const &lhs, ft::_tree_iterator<T> const &rhs) { return (lhs.base() != rhs.base()); }

    // RED BLACK TREE
    template <typename T, class Alloc = std::allocator<_rb_node<T> > >
    class _rb_tree {
    public:

        typedef _rb_node<T>                         node;
        typedef node*                               node_pointer;
        typedef node&                               node_reference;
        typedef Alloc                               allocator_type;
        typedef _tree_iterator<node>                iterator;
        typedef const _tree_iterator<node>          const_iterator;
        typedef typename allocator_type::reference  reference;
        typedef typename allocator_type::pointer    pointer;

    private:
        node_pointer    _root;
        node_pointer    _nil;
        Alloc           _alloc;

    public:
        _rb_tree() : _root(), _nil(), _alloc(allocator_type()) {}
        _rb_tree(const _rb_tree& src) : _root(src._root), _nil(), _alloc(allocator_type()) {}
        ~_rb_tree() {}

        void tree_insert(node_pointer node) {
            node_pointer y = _nil;
            node_pointer x = _root;
            while (x != _nil) {
                y = x;
                if (node->key < x->key) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }
            node->parent = y;
            if (y == _nil) {
                _root = node;
            } else if (node->key < y->key) {
                y->left = node;
            } else {
                y->right = node;
            }
        }

        void tree_insert(T key) {
            pointer new_node = _alloc.allocate(1);
            *new_node = _rb_node<T>(key);
            tree_insert(new_node);
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
            if (x != _nil) {
                inOrderWalk(x->left);
                std::cout << "key: " << x->key << '\n';
                inOrderWalk(x->right);
            }
        }

        iterator begin() { return (iterator(_root)); }

        node_pointer getRoot() { return (_root); }

    private:
        _rb_tree& operator=(const _rb_tree& rhs) {
            if (this == &rhs) {
                return (*this);
            }
            return (_rb_tree(rhs));
        }
    };
}
