/*
 * @Description: Do not edit
 * @Date: 2020-04-28 00:12:17
 * @LastEditors: dylatos
 * @LastEditTime: 2020-05-07 12:17:48
 */
#include "fib.cpp"
typedef int Rank;
#define DEFAULT_CAPACITY 3
template <typename T>
class Vector
{
private:
  /* data */
  Rank _size;
  int _capacity;
  T *_elem;

protected:
  void copyFrom(T *const A, Rank lo, Rank hi);
  void expand();
  void shrink();
  void unsort(Rank lo, Rank hi);
  Rank insert(Rank r, T const& e);
  int remove(Rank lo, Rank hi);
  T remove(Rank r);
  int deduplicate();
  void traverse(void (*visit)(T&));
  template <typename VST>
  void traverse(VST& visit);
  void increase(Vector<T> & V);
  int uniquify();

  

public:
  Vector(int c = DEFAULT_CAPACITY)
  {
    _elem = new T[_capacity = c];
    size = 0;
    while (lo<hi)
    {
      /* code */
      _elem[_size++] = A[lo++];
    }
    
  };
  
  Vector(T *A, Rank lo, Rank hi)
  {
    copyFrom(A, lo, hi);
  };

  ~Vector(){ delete [] _elem};

  int disordered() const;
  

  Rank find(T const &e) const { return find(e, 0, (Rank)_size) }
  Rank find(T const &e,Rank lo, Rank hi) const;

  Rank search(T const& e, Rank lo, Rank hi) const;
  
  T& operator[](Rank r) const;
  Vector<T> & operator = (Vector<T> const&);

  static Rank binSearch(T* A, T const& e, Rank lo, Rank hi);

  
};
template <typename T> 
void Vector<T>::copyFrom(T* const A, Rank lo, Rank hi) {
  _elem = new T[_capacity = 2*(hi - lo)];
  _size = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V){
  if(_elem) delete [] _elem;
  copyFrom(V._elem,0,V._size);
  return *this;
}

template <typename T>
void Vector<T>::expand(){
  // Return immediately when vector is no full;
  if (_size<_capacity) return; 
  // Ensure that capacity is not less than the defalt value;
  if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
  // Double the value of capacity;
  T* oldElem = _elem;
  _elem = new T[_capacity<<=1];
  for (int i = 0; i < _size; i++)
    _elem[i] = oldElem[i];

  delete [] oldElem;

}

template<typename T>
void Vector<T>::shrink(){
  // The capacity is not reduced to less than default value;
  if (_capacity<DEFAULT_CAPACITY) return;
  // Make sure that the 25% of size of vector 
  // that needs to be shrunk is less than the capacity.  
  if (_size << 2 > _capacity) return;
  T* oldElem = _elem;
  _elem = new T[_capacity>>=1];
  for (int i = 0; i < size; i++)
    _elem[i] = oldElem[i];
  delete [] oldElem;
};

template <typename T>
T & Vector<T>::operator[](Rank r) const {return _elem[r]};

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi){
  T* V = _elem + lo;
  for (Rank i = hi - lo; i > 0; i--)
    swap(V[i-1],V[rand() % i]);
}

template <typename T>
Rank Vector<T>::find(T const& e,Rank lo,Rank hi) const{
  while ((lo<hi--)&&(e != _elem[hi]));
  return hi;
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const& e){
  expand();
  for (int i = _size; i < r; i--)
  {
    /* code */
    _elem[i] = _elem[i-1];
  }
  _elem[r] = e;
  _size++;
  return r;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi){
  if (lo == hi) return 0;
  while (hi < _size) _elem[lo++] = _elem[hi++];
  _size = lo;
  shrink();
  return hi - lo;
}

template <typename T>
T Vector<T>::remove(Rank r){
  T e = _elem[r];
  remove(r,r+1);
  return e;
}

template <typename T>
int Vector<T>::deduplicate(){
  int oldsize = _size; // Record the old size;
  Rank i = 1;// Start with the second element;
  while (i<_size)// Check elements one by one from front to back;
    (find(_elem[i],0,i)<0)? // 
      i++:remove(i);
  return oldsize - _size;
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T&)){
  for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template <typename T> template <typename VST>
void Vector<T>::traverse(VST& visit){
  for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template <typename T>
struct Increase
{
  // Assume that T can be increased directly or 
  // that the "++" operator is already overloader;
  virtual void operator()(T& e){ e++;} 
  /* data */
};

template <typename T> 
void Vector<T>::increase(Vector<T> & V){
  V.traverse(Increase<T>());
}

template <typename T> 
int Vector<T>::disordered() const{ // Return the number of adjacent elements in reverse order of a vector.(inefficient)
  int counter = 0;
  for (int i = 0; i < _size; i++) // Traverse the elements of the vector one by one.
    if (_elem[i-1]>_elem[i]) counter++; // Count if meet the pair of elements in reverse.
  return counter;
}

template <typename T>
int Vector<T>::uniquify(){ // The algorithm that remove repetitive elements in a vector class object.
  int oldSize = _size; int i = 1; // the current rank of vector,start with index of 1.
  while (i<_size)
    // if the current element same as it's predecessor, remove it;
    // Otherwise,i points the next elements.
    _elem[i-1]==_elem[i]?remove(i):i++; 
  return oldSize-_size; // Return the size of the deleted elements.
}

template <typename T>
int Vector<T>::uniquify(){ // The algorithm that remove repetitive elements in a vector class object.(efficient)
  Rank i = 0;int j = 0;
  while (++j < _size) // Scan the elements of the vector one by one to the end.
    if (_elem[i]!=_elem[j]) // Ignore the repetitive each pair of elements adjacent.
      _elem[i++] = _elem[j]; // Move element to the position closest to the right one while meet different element.  
  _size = ++i;
  shrink();
  return j-i; // Return the size of the deleted elements.
}

// Within the interval [lo,hi) of the ordered vector,determine a rank of the last node which not greater than e
template <typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const{ 
  return 0;
}

template <typename T>
Rank Vector<T>::binSearch(T* A,T const& e, Rank lo, Rank hi){
  while (lo<hi)
  {
    Rank mi = (lo + hi) >> 1;
    if     (e<A[mi]) hi = mi;
    else             lo = mi+1; 
  }
  return --lo;
}

// template <typename T>
// Rank Vector<T>::fibSearch(T* A,T const& e, Rank lo, Rank hi){
//   while (lo<hi)
//   {
//     mi = (lo + hi) >> 1;
//     if     (e<A[mi]) hi = mi;
//     else if(e>A[mi]) lo = mi+1; 
//     else return mi
//   }
//   return -1;
// }
