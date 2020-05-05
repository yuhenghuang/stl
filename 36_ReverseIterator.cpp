template <class Iterator>
class reverse_iterator {
  protected:
    Iterator current;
  public:
    typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
    typedef typename iterator_traits<Iterator>::value_type value_type;
    typedef typename iterator_traits<Iterator>::reference reference;
    typedef typename iterator_traits<Iterator>::pointer pointer;
    typedef typename iterator_traits<Iterator>::difference_type difference_type;
    typedef Iterator iterator_type;
    typedef reverse_iterator<Iterator> self;
  public:
    explicit reverse_iterator(iterator_type x): current(x) {}
             reverse_iterator(const self& x): current(x.current) {}

    iterator_type base() const { return current; }
    reference operator* () const { Iterator tmp=current; return *--tmp; }
    pointer operator-> () const { return &(operator*()); }

    self& operator++ () { --current; return *this; }
    self& operator-- () { ++current; return *this; }
    self operator+ (difference_type n) const { return self(current-n); }
    self operator- (difference_type n) const { return self(current+n); }
};