namespace ft {

    enum rb_bit {black = false, red = true};

    template <typename T>
    struct _rb_node {
        typedef *_rb_node<T>    _base_node;
        typedef T               value_type;

        value_type  key;
        _base_node  left;
        _base_node  right;
        _base_node  parent;
        rb_bit      color;

        _rb_node(void) : key(), left(NULL), right(NULL), parent(NULL), color(rb_bit.black) {}
        _rb_node(const T& value) : key(value), left(NULL), right(NULL), parent(NULL), color(rb_bit.black) {}
        _rb_node(const _rb_node& src) : key(src.key), left(src.left), right(src.right), parent(src.parent), color(src.color) {}
        ~_rb_node() {}

        const _rb_node& operator=(const _rb_node& rhs) {
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

    template <typename T, class Alloc = std::allocator<T> >
    class _rb_tree : public _rb_node<T> {
    public:
        typedef typename _rb_node<T>    node;
        typedef Alloc                   allocator_type;
    };
}
