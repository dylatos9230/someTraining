#include "./list.cpp"
template <typename T>
class Queue : public List<T>
{
private:
    /* data */
public:
    void enqueue(T const &e)
    {
        insertAsLast(e);
    }
    T dequeue() { return remove(first()); }
    T &front() { return first()->data }
};
