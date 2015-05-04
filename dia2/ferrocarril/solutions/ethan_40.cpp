#include "ferrocarril.h"

void AcomodarFerrocarril(int n) {
  for (int i = 1; i < n; ++i) {
    int indice = EncontrarVagon(i);
    int tamanio = n - i + 1;
    
    while (tamanio > 1) {
      if (tamanio % 2 && indice == i + tamanio - 1) {
        IntercambiarVagones(indice - 1, indice);
        indice -= 1, tamanio -= 1;
      }
      tamanio = (tamanio / 2) * 2;
      if (i + tamanio / 2 <= indice) {
        IntercambiarVagones(i, i + tamanio - 1);
        indice -= tamanio / 2;
      }
      tamanio /= 2;
    }
  }
}
