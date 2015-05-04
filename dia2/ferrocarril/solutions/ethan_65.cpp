#include "ferrocarril.h"

void AcomodarFerrocarril(int n) {
  for (int i = 1; i < n; ++i) {
    int indice = EncontrarVagon(i) - i;
    if (indice == 0) continue;
    
    int tamanio = n - i + 1;
    if (indice * 2 > tamanio) {
      int punto_medio = tamanio / 2 + 1;
      int mitad_tamanio = (tamanio - 1) / 2;
      IntercambiarVagones(i + punto_medio - mitad_tamanio,
                          i + punto_medio + mitad_tamanio - 1);
      indice -= mitad_tamanio;
    }
    IntercambiarVagones(i, i + indice * 2 - 1);
  }
}