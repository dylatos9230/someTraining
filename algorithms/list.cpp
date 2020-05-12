#include "listNode.h"
#include <stdlib.h>
using namespace std;

template <typename T>
class List
{
private:
  // Size;Sentinel node;
  int _size;
  ListNodePosi(T) header;
  ListNodePosi(T) trailer;

protected:
  void init();
  int clear();
  void copyNodes(ListNodePosi(T), int);
  // merge an ordered list in the section;
  void merge(ListNodePosi(T) &, int, List<T> &, ListNodePosi(T), int);
  void mergeSort(ListNodePosi(T), int);
  void selectionSort(ListNodePosi(T), int);
  void insertionSort(ListNodePosi(T), int);

public:
  // Constructor
  List() { init(); }                     // Default
  List(List<T> const &L);                //Copy a list as a whole;
  List(List<T> const &L, Rank r, int n); // Copy L within a section into a new list
  List(ListNodePosi(T) p, int n);        // Copy n items from the position p in the list.
  ~List();
  // Read-only API
  Rank size() const { return _size; };
  bool empty() const { return _size <= 0; }; // Judge if empty or not.
  T &operator[](Rank r) const;
  ListNodePosi(T) first() const { return header->succ; };
  ListNodePosi(T) last() const { return trailer->pred; };
  ListNodePosi(T) find(T const &e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) search(T const &e, int n, ListNodePosi(T) p) const;

  // Writable API
  ListNodePosi(T) insertAsFirst(T const &e);
  ListNodePosi(T) insertAsLast(T const &e);
  ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const &e);
  ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const &e);
  T remove(ListNodePosi(T) p);
  int deduplicate();
  int uniquify();
  void sort(ListNodePosi(T) p, int n);
  // Traverse
  void traverse(void (*visit)(T &));
  template <typename VST>
  void traverse(VST &);
};

template <typename T>
void List<T>::init()
{
  header = new ListNode<T>;  // Sentinel header
  trailer = new ListNode<T>; // Sentinel trailer
  header->succ = trailer;
  header->pred = NULL;
  trailer->succ = NULL;
  trailer->pred = header;
  _size = 0;
}

template <typename T>
T &List<T>::operator[](Rank r) const
{ //Overwrite operator to visit a node by the rank
  ListNodePosi(T) p = first();
  while (0 < r--)
    p = p->succ;
  return p->data;
}

template <typename T>
ListNodePosi(T) List<T>::find(T const &e, int n, ListNodePosi(T) p) const
{
  while (0 < n--)
    if (e == (p = p->pred)->data)
      return p;
  return NULL;
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const &e)
{
  _size++;
  return header->insertAsSucc(e); // Insert e as the first node.
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const &e)
{
  _size++;
  return trailer->insertAsPred(e); // Insert e as the last node.
}
template <typename T>
ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T const &e)
{
  _size++;
  return p->insertAsPred(e); // Insert e as the pred node.
}
template <typename T>
ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const &e)
{
  _size++;
  return p->insertAsSucc(e); // Insert e as the succ node
}

template <typename T>
// Copy the n of nodes start with the p;
void List<T>::copyNodes(ListNodePosi(T) p, int n)
{
  init();
  while (n--)
  {
    insertAsLast(p); // Attach the current node
    p = p->succ;     // Point to the next node we wanna to copy.
  }
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n)
{
  copyNodes(p, n);
}

template <typename T> // Copy a whole list into the new list.
List<T>::List(List<T> const &L)
{
  copyNodes(L.first(), L._size);
}

template <typename T> // Copy the n of items from r from the list
List<T>::List(List<T> const &L, int r, int n)
{
  copyNodes(L[r], n);
}
template <typename T>
T List<T>::remove(ListNodePosi(T) p)
{                // Delete the node at the legal position
  T e = p->data; // Backup the data of the node into a T type variable e.
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  delete p;
  _size--;
  return e;
}
template <typename T>
List<T>::~List()
{
  clear();
  delete header;
  delete trailer;
}

template <typename T>
int List<T>::clear()
{
  int oldSize = _size;
  while (0 < _size)
  {
    remove(header->succ);
  }
  return oldSize;
}

template <typename T>
int List<T>::deduplicate()
{ // uniquify
  if (_size < 2)
    return 0; // It is must be an unique list;
  int oldSize = _size;
  ListNodePosi(T) p = h0= p->succ)) // loop util traverse the last node before the sentinel
  {List<T>::merge(ListNodePosi(T)&
    ListNodePosi(T) q = find(p->data, r, p);
    q ? remove(q) : r++;
  }
  return oldSize - _size;
}

template <typename T>
void List<T>::traverse(void (*visit)(T &)) // Using feature of function pointer to implement the traversal;
{
  for (ListNodePosi(T) p = header; p != trailer; p = p->succ)
  {
    /* code */
    visit(p->data);
  }
}
template <typename T>
template <typename VST>
void List<T>::traverse(VST &visit) // Using feature of function pointer to implement the traversal;
{
  for (ListNodePosi(T) p = header; p != trailer; p = p->succ)
  {
    visit(p->data);
  }
}

template <typename T>
int List<T>::uniquify()
{
  if (_size < 2)
    return 0;
  int oldSize = _size;
  ListNodePosi(T) p, q; // The Pointers is used to tag the two nodes next with each other in turn.
  for (p = header, q = p->succ; q != trailer; p = q, q = q->succ)
  {
    if (p->data == q->data)
    {
      remove(q);
      q = p;
    }
  }
  return oldSize - _size;
}

template <typename T>
ListNodePosi(T) List<T>::search(T const &e, int n, ListNodePosi(T) p) const
{
  while (0 <= n--)
  {
    if (e >= ((p = p->pred)->data))
      break;
  }
  return p;
}

template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n)
{
  switch (rand() % 3)
  {
  case 1:
    insertionSort(p, n);
    break;
  case 2:
    selectionSort(p, n);
    break;
  default:
    mergeSort(p, n);
    break;
  }
}

template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n)
{
  for (int r = 0; r < n; r++)
  {
    insertAfter(search(p->data, r, p), p->data);
    p = p->succ;
    remove(p->pred);
  }
}

template <typename T>
ListNodePosi(T) selectMax(ListNodePosi(T) p, int n)
{
  ListNodePosi(T) max = p; // Consider the first p as the maxium value for the time being.
  for (ListNodePosi(T) cur = p; 1 < n; n--)
  {
    if ((cur = cur->succ)->data > (max->data))
    {
      max = cur;
    }
  }
  return max;
}

template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n)
{
  ListNodePosi(T) head = p;
  ListNodePosi(T) tail = p->succ;
  for (int r = 0; r < n; r++)
    tail = tail->succ;
  while (1 < n)
  {
    ListNodePosi(T) max = selectMax(head->succ, n); // Find out the maxium within the section [0,n)
    insertBefore(tail, remove(max));
    n--;
  }
}

template <typename T>
void List<T>::merge(ListNodePosi(T) & p, int n, List<T> &L, ListNodePosi(T) q, int m)
{
  ListNodePosi(T) pp = p->pred;
  while (0 < m)
  {
    if ((0 < n) && (p->data <= q->data))
    {
      if (q == (p = p->succ))
        break;
      n--;
    }
    else
    {
      insertBefore(p, L.remove((q = q->succ)->pred));
      m--;
    }
  }
  p = pp->succ;
}

template <typename T>
void List<T>::mergeSort(ListNodePosi(T) p, int n)
{
  if (n < 2)
    return;
  int m = n >> 1; // Find out the position at the middle;
  // Splite the sublist evenly in two;
  ListNodePosi(T) q = p;
  for (int i = 0; i < m; i++)
  {
    /* code */
    q = q->succ;
  }
  mergeSort(p, m);
  mergeSort(q, n - m);
  merge(p, m * this, q, n - m) //  Merging;
}
