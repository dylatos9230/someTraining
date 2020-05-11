/*
 * @Description: Do not edit
 * @Date: 2020-05-06 18:28:31
 * @LastEditors: dylatos
 * @LastEditTime: 2020-05-11 07:01:56
 */

typedef int Rank;
#define ListNodePosi(T) ListNode<T> * // The current position.

template <typename T>
struct ListNode
{
  // Member variable
  T data;
  ListNodePosi(T) pred;
  ListNodePosi(T) succ; //Data,predecessor,successor
  // Contructor
  ListNode(){};
  ListNode(T e, ListNodePosi(T) p = Null, ListNodePosi(T) s = Null)
      : data(e), pred(p), succ(s) {} // Default constructor.

  // Operation API

  ListNodePosi(T) insertAsPred(T const &e); //Insert a new node into list before the current one.
  ListNodePosi(T) insertAsSucc(T const &e); // Insert a new node into list after the current one.
};

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const &e)
{
  ListNodePosi(T) x = new ListNode(e, pred, this);
  pred->succ = x;
  pred = x;
  return x;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const &e)
{
  ListNodePosi(T) x = new ListNode(e, this, succ);
  succ->pred = x;
  succ = x;
  return x;
}