#include "./vector.cpp"
template <typename T>
// Take the first end of the vector as the bottom of the stack
// Take the last end of the vector as the top of the stack
class Stack : public Vector<T>
{
public:
    // Push: equivalent to inserting a new element as the final element of a vector
    void push(T const &e) { insert(size(), e); }
    // Pop: equivalent to deleting the final element of a vector
    T pop() { return remove(size() - 1); }
    // Top: return the final element of a vector directly
    T &top() { return (*this)[size() - 1]; }
};