namespace ft {

    enum color_bool { black, red };

    template <typename T>
    struct _rb_node {
        typedef _rb_node*   _base_node;
        typedef T           value_type;

        value_type  key;
        _base_node  left;
        _base_node  right;
        _base_node  parent;
        bool        color;

        _rb_node() : key(), left(NULL), right(NULL), parent(NULL), color(black) {}
        explicit _rb_node(const T& value) : key(value), left(NULL), right(NULL), parent(NULL), color(red) {}
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

    template <typename T, class Alloc = std::allocator<_rb_node<T> > >
    class _rb_tree {
    public:

        typedef Alloc                               allocator_type;
        typedef typename allocator_type::reference  reference;
        typedef typename allocator_type::pointer    pointer;
        typedef _rb_node<T>                         node;
        typedef node*                               node_pointer;
        typedef node&                               node_reference;

    private:
        node_pointer    _nill;
        node_pointer    _root;
        Alloc           _alloc;

    public:
        _rb_tree() : _nill(), _root(), _alloc(allocator_type()) {}
        _rb_tree(const _rb_tree& src) : _nill(src._nill), _root(src._root), _alloc(allocator_type()) {}
        ~_rb_tree() {}

        void insert(node_pointer node) {
            node_pointer y = _nill;
            node_pointer x = _root;
            while (x != _nill) {
                y = x;
                if (node->key < x->key) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }
            node->parent = y;
            if (y == _nill) {
                _root = node;
            } else if (node->key < y->key) {
                y->left = node;
            } else {
                y->right = node;
            }
        }

        void insert(T key) {
            pointer new_node = _alloc.allocate(1);
            *new_node = _rb_node<T>(key);
            insert(new_node);
        }

        void inOrderWalk(node_pointer x) {
            if (x != _nill) {
                inOrderWalk(x->left);
                std::cout << "key: " << x->key << '\n';
                inOrderWalk(x->right);
            }
        }

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
