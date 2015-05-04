#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "ferrocarril.h"

template<class Type>
class SplayTree {
 public:
  struct Node {
    typedef Node* Ptr;
    
    Node(Type data_t)
      : right_child(nullptr),
        left_child(nullptr),
        parent(nullptr),
        data(data_t),
        size(1) {}
    
    ~Node() {
      delete left_child;
      delete right_child;
    }
    
    void CalculateSize() {
      size = 1;
      if (left_child)
        size += left_child->size;
      if (right_child)
        size += right_child->size;
    }
    
    int size;
    Type data;
    Ptr parent;
    Ptr left_child;
    Ptr right_child;
  };
  
  typedef Node* Ptr;
  
  SplayTree() : root(nullptr) {}
  ~SplayTree() { delete root; }
  
  int Size() const {
    if (!root) return 0;
    return root->size;
  }
  
  Ptr Min(Ptr u) {
    if (!u) return nullptr;
    while (u->left_child)
      u = u->left_child;
    Splay(u); return u;
  }
  
  Ptr Get(int index) {
    if (Size() < index)
      return nullptr;
    Ptr u = root;
    while (u) {
      int lsize = 1;
      if (u->left_child)
        lsize += u->left_child->size;
      if (lsize == index) break;
      if (lsize < index) {
        index -= lsize;
        u = u->right_child;
      } else u = u->left_child;
    }
    Splay(u);
    return u;
  }
  
  int Index(Ptr u) {
    if (!u) return -1; Splay(u);
    if (!u->left_child) return 1;
    return u->left_child->size + 1;
  }
  
  void Invert(int a, int b) {
    int size = (b - a + 1) >> 1;
    Ptr B = Get(a);
    Ptr A = B->left_child;
    B->left_child = nullptr;
    B->CalculateSize();
    
    Ptr C = Get(size << 1);
    Ptr D = C->right_child;
    C->right_child = nullptr;
    C->CalculateSize();
    
    B = Get(size);
    Ptr E = B->right_child;
    E->parent = nullptr;
    B->right_child = D;
    if (D) D->parent = B;
    B->CalculateSize();
    
    C->right_child = B;
    B->parent = C;
    C->CalculateSize();
    
    C = Min(E);
    C->left_child = A;
    if (A) A->parent = C;
    C->CalculateSize();
  }
  
  Ptr BuildFromSortedVector(
    const std::vector<Type>& v,
    int s, int e, Ptr parent) {
    if(e - s <= 0) return nullptr;
    
    int m = (s + e) >> 1;
    Ptr u = new Node(v[m]); u->parent = parent; 
    u->left_child = BuildFromSortedVector(v, s, m, u);
    u->right_child = BuildFromSortedVector(v, m + 1, e, u);
    u->CalculateSize(); return u;
  }
  
  void BuildFromSortedVector(
    const std::vector<Type>& v) {
    root = BuildFromSortedVector(
      v, 0, v.size(), nullptr);
  }
  
  bool IsSorted(Ptr u, Type** l) const {
    if (!u) return true;
    if (!IsSorted(u->left_child, l)) return false;
    if(*l && u->data < **l) return false; *l = &u->data;
    return IsSorted(u->right_child, l);
  }
  
  bool IsSorted() const {
    Type** last = new Type*(nullptr);
    bool sorted = IsSorted(root, last);
    delete last; return sorted;
  }
  
  void RecurseForPointers(Ptr u,
    std::vector<Ptr>* ptrs) const {
    if (!u) return; (*ptrs)[u->data] = u;
    RecurseForPointers(u->left_child, ptrs);
    RecurseForPointers(u->right_child, ptrs);
  }
  
  std::vector<Ptr> GetPointers() const {
    std::vector<Ptr> pointers(Size());
    RecurseForPointers(root, &pointers);
    return pointers;
  }
  
 private:
  void RotateLeft(Ptr u) {
    if (!u) return;
    Ptr p = u->parent;
    if (!p) return;
    
    u->parent = p->parent;
    if (p->parent) {
      if (u->parent->right_child == p)
        u->parent->right_child = u;
      else u->parent->left_child = u;
    }
    p->right_child = u->left_child;
    if (u->left_child)
      u->left_child->parent = p;
    u->left_child = p;
    p->parent = u;
    
    p->CalculateSize();
    u->CalculateSize();
  }
  
  void RotateRight(Ptr u) {
    if (!u) return;
    Ptr p = u->parent;
    if (!p) return;
    
    u->parent = p->parent;
    if (p->parent) {
      if (u->parent->right_child == p)
        u->parent->right_child = u;
      else u->parent->left_child = u;
    }
    p->left_child = u->right_child;
    if (u->right_child)
      u->right_child->parent = p;
    u->right_child = p;
    p->parent = u;
    
    p->CalculateSize();
    u->CalculateSize();
  }
  
  void Splay(Ptr u) {
    if (!u) return;
    while (u->parent) {
      Ptr p = u->parent;
      if (!p->parent) {
        if (p->left_child == u) RotateRight(u);
        if (p->right_child == u) RotateLeft(u);
      } else {
        Ptr g = p->parent;
        if (p->left_child == u) {
          if (g->left_child == p)
            RotateRight(p), RotateRight(u);
          else RotateRight(u), RotateLeft(u);
        } else {
          if (g->left_child == p)
            RotateLeft(u), RotateRight(u);
          else RotateLeft(p), RotateLeft(u);
        }
      }
    }
    root = u;
  }
  
  Ptr root;
};

SplayTree<int> order;
int n, swaps, searchs, positions;
std::vector<SplayTree<int>::Ptr> pointers;

void Abort(const char* type) { puts("0.0"); fclose(stdout); 
  fprintf(stderr, "%s Calls Exceeded\n", type); exit(0); }
void DecreasePositions() { if (!positions--) Abort("Position"); }
void DecreaseSearchs() { if (!searchs--) Abort("Search"); }
void DecreaseSwaps() { if (!swaps--) Abort("Swap"); }

// FUNCTIONS FOR INTERACTION
int EncontrarVagon(int v) {
  DecreaseSearchs();
  if (v < 1 || n < v) return 0;
  return order.Index(pointers[v - 1]);
}

int VagonEnPosicion(int p) {
  DecreasePositions();
  if (p < 1 || n < p) return 0;
  return order.Get(p)->data + 1;
}

int IntercambiarVagones(int a, int b) {
  DecreaseSwaps();
  if (b < a) return 0;
  if (a < 1 || n < b) return 0;
  if (!(b - a & 1)) return 0;
  order.Invert(a, b);
  return 1;
}
// FUNCTIONS FOR INTERACTION

int main() {
  scanf("%d", &n);
  scanf("%d", &swaps);
  scanf("%d", &searchs);
  scanf("%d", &positions);
  std::vector<int> P(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &P[i]);
  fclose(stdin);
  order.BuildFromSortedVector(P);
  pointers = order.GetPointers();
  
  AcomodarFerrocarril(n);
  if (order.IsSorted())
    printf("1.0\n");
  else puts("0.0");
  fclose(stdout);
  return 0;
}