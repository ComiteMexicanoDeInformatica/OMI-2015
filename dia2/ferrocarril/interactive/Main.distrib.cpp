#include <stdio.h>
#include <algorithm>
#include "ferrocarril.h"

// COMENTARIO:
// Implementacion del evaluador de prueba para
// la tarea "Ferrocarril", incluye algunos mensajes
// informativos para facilitar las pruebas a tu funcion.
// Recuerda que el evaluador oficial no es necesariamente
// similar al que se presenta a continuacion.

// AVISO IMPORTANTE:
// En el evaluador oficial, la complejidad de las funciones
// IntercambiarVagones, EncontrarVagon y VagonEnPosicion
// se encuentran en el orden de O(log n), por lo que si tu
// solucion está bien implementada no debe juzgarse como TLE.

const int kMaxN = 40002;

int intercambios_usados = 0;
int encontrar_usados = 0;
int posicion_usados = 0;
int n, vagones[kMaxN];

void ImprimirFerrocarril() {
  printf("Ferrocarril:");
  for (int i = 1; i <= n; ++i)
    printf(" %d", vagones[i]);
  printf("\n"); fflush(stdout);
}

int EncontrarVagon(int v) {
  printf("Llamaste a EncontrarVagon(%d).\n", v);
  fflush(stdout); ++encontrar_usados;
  
  int retorno = 0;
  // Numero de vagon invalido.
  if (v < 1 || n < v) retorno = 0;
  // Busqueda lineal del vagon.
  for (int i = 1; i <= n; ++i)
    if (vagones[i] == v) retorno = i;
  
  if (retorno == 0)
    puts("Hiciste una llamada invalida.");
  puts(""); fflush(stdout); return retorno;
}

int VagonEnPosicion(int p) {
  printf("Llamaste a VagonEnPosicion(%d).\n", p);
  fflush(stdout); ++posicion_usados;
  
  int retorno = 0;
  // Indice fuera de rango.
  if (1 <= p && p <= n)
    retorno = vagones[p];
  
  if (retorno == 0)
    puts("Hiciste una llamada invalida.");
  puts(""); fflush(stdout); return retorno;
}

int IntercambiarVagones(int a, int b) {
  printf("Llamaste a IntercambiarVagones(%d, %d).\n", a, b);
  fflush(stdout); ++intercambios_usados;
  
  int retorno = 1;
  if (b < a) retorno = 0;
  // Indices fuera de rango.
  if (a < 1 || n < b) retorno = 0;
  // El tamaño del intervalo es impar.
  if ((b - a + 1) % 2 == 1) retorno = 0;
  
  if (retorno == 1) {
    int t = (b - a + 1) / 2;
    // Efectuar el intercambio.
    for (int i = a; i < a + t; ++i)
      std::swap(vagones[i], vagones[i + t]);
    ImprimirFerrocarril();
  } else puts("Hiciste una llamada invalida.");
  puts(""); fflush(stdout); return retorno;
}

int main() {
  // Leer de entrada estandar
  // el numero de vagones.
  scanf("%d", &n);
  // Leer la permutacion de los
  // n vagones del ferrocarril.
  for (int i = 1; i <= n; ++i)
    scanf("%d", &vagones[i]);

  // Llamada a tu funcion.
  // No olvides implementarla!
  AcomodarFerrocarril(n);

  bool esta_ordenado = true;
  for (int i = 1; i < n; ++i)
    if (vagones[i] > vagones[i + 1])
      esta_ordenado = false;

  if (esta_ordenado)
    puts("El ferrocarril fue ordenado correctamente :)");
  else puts("El ferrocarril no fue ordenado correctamente :(");
  printf("Usaste %d vez/veces la funcion EncontrarVagon\n", encontrar_usados);
  printf("Usaste %d vez/veces la funcion VagonEnPosicion\n", posicion_usados);
  printf("Usaste %d vez/veces la funcion IntercambiarVagones\n", intercambios_usados);
  fclose(stdout);
  return 0;
}
