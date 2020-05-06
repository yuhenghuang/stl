template <typename... Value> class tuple{};
template <> class tuple<> {}; // end condition

template <typename Head, typename... Tail>
class tuple<Head, Tail...>: private tuple<Tail...> {
  typedef tuple<Tail...> inherited;
  protected:
    Head m_head;
  public:
    tuple() {}
    tuple(Head v, Tail... vtail): m_head(m), inherited(vtail...) {} // initialize tail

    typename Head::type head() { return m_head; }
    inherited& tail() { return *this; } // type change to inherited, thus return all of *this except head;
};