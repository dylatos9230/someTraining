#define BinNodePosi(T) BinNode<T> *         // Position of the node
#define stature(p) ((p) ? (p)->height : -1) // Height of the node
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x) (HasLChild(x) || HasRChild(x))     //至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))

#define sibling(p) (IsLChild(*(p)) ? (p)->parent->rChild : (p)->parent->lChild) //兄弟

#define uncle(x) (IsLChild(*((x)->parent)) ? (x)->parent->parent->rChild : (x)->parent->parent->lChild) //叔叔

#define FromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lChild : (x).parent->rChild)) //来自父亲的指针

typedef enum
{
    RB_RED,
    RB_BLACK
} RBColor; //The color of the tree

template <typename T>
struct BinNode
{
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) lChild;
    BinNodePosi(T) rChild;

    int height;
    int npl;       // Null Path Length
    RBColor color; // (Only for RB Tree)

    // Constructor
    BinNode() : parent(NULL), lChild(NULL), rChild(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
            int h = 0, int l = 1, RBColor c = RB_RED)
        : data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) {}

    // API

    int size(); // Count the total number of descendants of the current node, that is,the size of the subtree of it;

    BinNodePosi(T) insertAsLC(T const &); // Insert a new node to BinTree as the LC of the current node;
    BinNodePosi(T) insertAsRC(T const &); // Insert a new node to BinTree as the RC of the current node;
    BinNodePosi(T) succ();                // Get the direct successor of the current node
    template <typename VST>
    void travLevel(VTS &); // level order
    template <typename VST>
    void travPre(VST &); //
    template <typename VST>
    void travIn(VST &);

    //
    bool operator<(BinNode const &bn) { return data < bn.data; }  // lt
    bool operator>(BinNode const &bn) { return data > bn.data; }  // gt
    bool operator==(BinNode const &bn) { return data == bn.data } // eq
};

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
{
    return lChild = new BinNode(e, this);
}
template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const &e)
{
    return rChild = new BinNode(e, this);
}

template <typename T>
template <typename VST>
void BinNode<T>::travIn(VST &visit)
{
    switch (rand() % 5)
    {
    case 1:
        travIn_I1(this, visit);
        break;
    case 2:
        travIn_I2(this, visit);
        break;
    case 3:
        travIn_I3(this, visit);
        break;
    case 4:
        travIn_I4(this, visit);
        break;
    default:
        travIn_R(this, visit);
        break;
    }
}