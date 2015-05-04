#include <vector>
#include "ferrocarril.h"

class SplayTree {
 public:
  struct Node {
    typedef Node* Ptr;

    Node(int data_t)
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
    int data;
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
    const std::vector<int>& v,
    int s, int e, Ptr parent) {
    if(e - s <= 0) return nullptr;

    int m = (s + e) >> 1;
    Ptr u = new Node(v[m]); u->parent = parent;
    u->left_child = BuildFromSortedVector(v, s, m, u);
    u->right_child = BuildFromSortedVector(v, m + 1, e, u);
    u->CalculateSize(); return u;
  }

  void BuildFromSortedVector(
    const std::vector<int>& v) {
    root = BuildFromSortedVector(
      v, 0, v.size(), nullptr);
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
} vagones;

std::vector<SplayTree::Ptr> punteros;

int MiEncontrarVagon(int v) {
  return vagones.Index(punteros[v - 1]);
}

void MiIntercambiarVagones(int a, int b) {
  IntercambiarVagones(a, b);
  vagones.Invert(a, b);
}

void AcomodarFerrocarril(int n) {
  std::vector<int> orden(n);
  for (int i = 0; i < n; ++i)
    orden[i] = VagonEnPosicion(i + 1) - 1;
  vagones.BuildFromSortedVector(orden);
  punteros = vagones.GetPointers();

  for (int i = 1; i < n; ++i) {
    int indice = MiEncontrarVagon(i) - i;
    if (indice == 0) continue;

    int tamanio = n - i + 1;
    if (indice * 2 > tamanio) {
      int punto_medio = tamanio / 2 + 1;
      int mitad_tamanio = (tamanio - 1) / 2;
      MiIntercambiarVagones(i + punto_medio - mitad_tamanio,
                            i + punto_medio + mitad_tamanio - 1);
      indice -= mitad_tamanio;
    }
    MiIntercambiarVagones(i, i + indice * 2 - 1);
  }
}
