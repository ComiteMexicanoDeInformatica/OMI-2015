#include "ferrocarril.h"

void AcomodarFerrocarril(int n) {
  for (int i = 1; i < n; ++i) {
    int indice = EncontrarVagon(i);
    for (int j = indice; j > i; --j)
      IntercambiarVagones(j - 1, j);
  }
}
