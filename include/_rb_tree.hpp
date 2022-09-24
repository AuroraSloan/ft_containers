#pragma once
#ifndef _RB_TREE_HPP
# define _RB_TREE_HPP

# include <iterator>
# include <iostream>
# include "iterator.hpp"
# include "utility.hpp"

namespace ft {

    enum color_bool { black, red };

    template <typename node_type>
    node_type tree_min(node_type node, node_type nil) {
        while (node->left != nil) {
            node = node->left;
        }
        return (node);
    }

    template <typename node_type>
    node_type tree_max(node_type node, node_type nil) {
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

        _rb_node() : value(), left(), right(), parent(), color(red) {}
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
            }
            else {
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
    template <typename T, typename Key, class Comp, class Alloc = std::allocator<_rb_node<T> > >
    class _rb_map_tree {
    public:

        typedef T                                       value_type;
        typedef Key                                     key_type;
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

        explicit _rb_map_tree(const _rb_map_tree& src) : _root(), _begin(), _nil(src._nil), _comp(src._comp), _alloc(allocator_type()) {
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

        // ITERATORS
        iterator begin() { return (iterator(_begin)); }
        const_iterator begin() const { return (const_iterator(_begin)); }

        iterator end() { return (iterator(_end)); }
        const_iterator end() const { return (const_iterator(_end)); }

        reverse_iterator rbegin() { return (reverse_iterator(_end)); }
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(_end)); }

        reverse_iterator rend() { return (reverse_iterator(_begin)); }
        const_reverse_iterator rend() const { return (const_reverse_iterator(_begin)); }


        // CAPACITY
        size_type size() const { return (_size); }
        size_type empty() const { return (!_size); }
        size_type max_size() {
            return (_alloc.max_size());
        }

        // ELEMENT ACCESS

        // MODIFIERS
        ft::pair<iterator, bool> insert(const value_type& val) {
            node_pointer parent = _find_parent(_root, val);

            if (_is_valid_node(parent) && _values_equal(parent->value, val)) {
                return (ft::make_pair(iterator(parent), false));
            }
            return (ft::make_pair(_setup_new_node(parent, val), true));
        }

        iterator insert (iterator position, const value_type& val) {
            node_pointer parent = _find_parent(_resolve_hint(position, val), val);

            if (_is_valid_node(parent) && _values_equal(parent->value, val)) {
                return (iterator(parent));
            }
            return (_setup_new_node(parent, val));
        }

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last) {
            while (first != last) {
                insert(*first);
                first++;
            }
        }

        size_type erase(const key_type& k) {
            node_pointer node = _find(_root, k);

            if (_is_valid_node(node)) {
                iterator last = --(iterator(_end));
                if (node == _begin) {
                    if (node == last.base()) {
                        _rb_delete(node);
                        _begin = _nil;
                        _root = _nil;
                        return (1);
                    }
                    iterator new_begin = ++(iterator(_begin));
                    _begin = new_begin.base();
                }
                if (node == last.base()) {
                    node_pointer new_last = (--last).base();
                    _end->parent = new_last;
                    new_last->right = _end;
                }
                _rb_delete(node);
                return (1);
            }
            return (0);
        }

        void erase(iterator position) {
            node_pointer node = position.base();

            if (_is_valid_node(node)) {
                iterator last = --(iterator(_end));
                if (node == _begin) {
                    if (node == last.base()) {
                        _rb_delete(node);
                        _begin = _nil;
                        _root = _nil;
                        return ;
                    }
                    iterator new_begin = ++(iterator(_begin));
                    _begin = new_begin.base();
                }
                if (node == last.base()) {
                    node_pointer new_last = (--last).base();
                    _end->parent = new_last;
                    new_last->right = _end;
                }
                _rb_delete(node);
            }
        }

        void erase(iterator first, iterator last) {
            key_type key;
            for (iterator it = first; it != last;) {
                key = (*first).first;
                ++first;
                erase(key);
            }
        }
        void tmpdelete(node_pointer node) {
            iterator end = iterator(_end);
            node_pointer last = (--end).base();
            if (_is_valid_node(node)) {
                if (node == _begin) {
                    _begin = (++iterator(_begin)).base();
                } else if (node == last) {
                    node_pointer new_last_node = (--end).base();
                    _end->parent = new_last_node;
                    new_last_node->right = _end;
                }
                _rb_delete(node);
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
            }
        }
        void clear () {
            if (_size) {
                _free_nodes(_root, _end);
                _alloc.destroy(_end);
                _alloc.deallocate(_end, 1);
                _size = 0;
            }
        }

        node_pointer    find(const key_type& k) {
            return (_find(_root, k));
        }
        /*void inOrderWalk(node_pointer x) {
            if (x != _nil && x != _end) {
                inOrderWalk(x->left);
                std::cerr << "\t" << x->value.first << ':' << x->value.second << std::endl;
                inOrderWalk(x->right);
                //std::cerr << "key: " << x->value.first << " - value: " << x->value.second << '\n';
            }
        }*/

        node_pointer getRoot() const { return (_root); }
        value_compare value_comp() const { return (_comp); }

    private:
        void _left_rotate(node_pointer x) {
            node_pointer y = x->right;
            x->right = y->left;
            if (_is_valid_node(y->left)) {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (_not_valid_node(x->parent)) {
                _root = y;
            } else if (x == x->parent->left) {
                x->parent->left = y;
            } else {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }
        void _right_rotate(node_pointer x) {
            node_pointer y = x->left;
            x->left = y->right;
            if (_is_valid_node(y->right)) {
                y->right->parent = x;
            }
            y->parent = x->parent;
            if (_not_valid_node(x->parent)) {
                _root = y;
            } else if (x == x->parent->right) {
                x->parent->right = y;
            } else {
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;
        }

        //=================================================================//
        //                        INSERT FIXUP                             //
        //=================================================================//
        void _rb_insert_fixup_traverse(node_pointer node, node_pointer nodes_uncle) {
            node->parent->color = black;
            nodes_uncle->color = black;
            node->parent->parent->color = red;
            node = node->parent->parent;
        }

        void __parent_granparent_color_change(node_pointer node) {
            node->parent->color = black;
            node->parent->parent->color = red;
        }

        void _rb_insert_fixup_left(node_pointer node) {
            node_pointer nodes_uncle = _nil;
            nodes_uncle = node->parent->parent->right;
            if (_is_valid_node(nodes_uncle) && nodes_uncle->color == red) {
                _rb_insert_fixup_traverse(node, nodes_uncle);
            } else {
                if (_is_valid_node(node->parent->right) && node == node->parent->right) {
                    node = node->parent;
                    _left_rotate(node);
                }
                __parent_granparent_color_change(node);
                _right_rotate(node->parent->parent);
            }
        }

        void _rb_insert_fixup_right(node_pointer node) {
            node_pointer nodes_uncle = _nil;
            nodes_uncle = node->parent->parent->left;
            if (_is_valid_node(nodes_uncle) && nodes_uncle->color == red) {
                _rb_insert_fixup_traverse(node, nodes_uncle);
            } else {
                if (_is_valid_node(node->parent->left) && node == node->parent->left) {
                    node = node->parent;
                    _right_rotate(node);
                }
                __parent_granparent_color_change(node);
                _left_rotate(node->parent->parent);
            }
        }

        void _rb_insert_fixup(node_pointer node) {
            while (_is_valid_node(node->parent) && node->parent->color == red) {
                if (node->parent == node->parent->parent->left) {
                    _rb_insert_fixup_left(node);
                } else {
                    _rb_insert_fixup_right(node);
                }
            }
            _root->color = black;
        }

        //=================================================================//
        //                         INSERT HELPERS                          //
        //=================================================================//
        node_pointer    _find_parent(node_pointer start, const value_type &val) {
            node_pointer parent = _nil;
            while (_is_valid_node(start)) {
                parent = start;
                if (_values_equal(start->value, val)) {
                    break ;
                } else if (_comp(val, start->value)) {
                    start = start->left;
                } else {
                    start = start->right;
                }
            }
            return (parent);
        }
        iterator _setup_new_node(node_pointer parent, const value_type &val) {
            node_pointer new_node = _alloc.allocate(1);
            _alloc.construct(new_node, node(val));
            new_node->parent = parent;
            new_node->left = _nil;
            new_node->right = _nil;

            if (_not_valid_node(parent)) {
                _root = new_node;
            } else if (_comp(new_node->value, parent->value)) {
                parent->left = new_node;
            } else {
                parent->right = new_node;
            }

            if (_not_valid_node(_begin) || new_node->value < _begin->value) {
                _begin = new_node;
            }
            if (!_end->parent || new_node->value > _end->parent->value) {
                _end->parent = new_node;
                new_node->right = _end;
            }
            new_node->color = red;
            _size++;
            _rb_insert_fixup(new_node);
            //std::cerr << new_node << " new_node key: " << (*new_node).value.first << "\n" << _root << " root key: " << (*_root).value.first << std::endl;
            return (iterator(new_node));
        }

        node_pointer _resolve_hint(iterator hint, const value_type &val) {
            node_pointer position = hint.base();
            node_pointer next_position = (++hint).base();
            if (_comp(position->value, val) && _comp(val, next_position->value)) {
                return (position);
            }
            return (_root);
        }

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

        //=================================================================//
        //                         ERASE HELPERS                           //
        //=================================================================//
        void _rb_transplant(node_pointer toErase, node_pointer toReplace) {
            // need to deallocate and reallocate nodes?
            if (_not_valid_node(toErase->parent)) {
                _root = toReplace;
            } else if (toErase == toErase->parent->left) {
                toErase->parent->left = toReplace;
            } else {
                toErase->parent->right = toReplace;
            }
            if (toReplace) {
                toReplace->parent = toErase->parent;
            }
        }

        void _rb_delete(node_pointer node) {
            node_pointer    node_grandchild = _nil;
            node_pointer    to_replace = node;
            bool            node_original_color = to_replace->color;

            if (node->left == _nil) {
                node_grandchild = node->right;
                _rb_transplant(node, node->right);
            } else if (node->right == _nil) {
                node_grandchild = node->left;
                _rb_transplant(node, node->left);
            } else {
                to_replace = tree_min(node->right, _nil);
                node_original_color = to_replace->color;
                node_grandchild = to_replace->right;
                if (to_replace->parent == node) {
                    if (node_grandchild) {
                        node_grandchild->parent = to_replace;
                    }
                } else {
                    _rb_transplant(to_replace, to_replace->right);
                    to_replace->right = node->right;
                    to_replace->right->parent = to_replace;
                }
                _rb_transplant(node, to_replace);
                to_replace->left = node->left;
                to_replace->left->parent = to_replace;
                to_replace->color = node->color;
            }
            if (node_original_color == black && node_grandchild) {
                _rb_delete_fixup(node_grandchild);
            }
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
            _size--;
        }

        void _rb_delete_fixup(node_pointer x) {
            node_pointer w = _nil;
            while (x != _root && x->color == black) {
                if (x == x->parent->left) {
                    w = x->parent->right;
                    if (w->color == red) {
                        w->color = black;
                        x->parent->color = red;
                        _left_rotate(x->parent);
                        w = x->parent->right;
                    }
                    if (w->left && w->right && w->left->color == black && w->right->color == black) {
                        w->color = red;
                        x = x->parent;
                    } else if (w->right && w->right->color == black) {
                        w->left->color = black;
                        w->color = red;
                        _right_rotate(w);
                        w = x->parent->right;
                    }
                    if (w->right && w->color == black && w->right->color == red) {
                        w->color = x->parent->color;
                        x->parent->color = black;
                        w->right->color = black;
                        _left_rotate(x->parent);
                        x = _root;
                    }
                } else {
                    w = x->parent->left;
                    if (w->color == red) {
                        w->color = black;
                        x->parent->color = red;
                        _right_rotate(x->parent);
                        w = x->parent->left;
                    }
                    if (w->right && w->left && w->right->color == black && w->left->color == black) {
                        w->color = red;
                        x = x->parent;
                    } else if (w->left && w->left->color == black) {
                        w->right->color = black;
                        w->color = red;
                        _left_rotate(w);
                        w = x->parent->left;
                    }
                    if (w->left && w->color == black && w->left->color == red) {
                        w->color = x->parent->color;
                        x->parent->color = black;
                        w->left->color = black;
                        _right_rotate(x->parent);
                        x = _root;
                    }
                }
            }
            x->color = black;
        }

        node_pointer _find(node_pointer src, const key_type& k) {
            if (_not_valid_node(src) || src->value.first == k) {
                return (src);
            }
            if (k < src->value.first) {
                return (_find(src->left, k));
            } else {
                return (_find(src->right, k));
            }
        }

        bool _is_valid_node(node_pointer node) {
            return (node != _nil && node != _end);
        }
        bool _not_valid_node(node_pointer node) {
            return (node == _nil || node == _end);
        }
        bool _values_equal(const value_type& a, const value_type& b) {
            return (!_comp(a, b) && !_comp(b, a));
        }
    };
}

#endif
