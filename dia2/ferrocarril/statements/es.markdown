Una de las grandes atracciones turísticas de Chihuahua es el legendario ferrocarril “El Chepe”, en esta ocasión está preparándose para salir en busca de una nueva aventura. Como presidente de la Comisión de Ordenamiento de Maquinaria Interestatal (COMI) estás a cargo de preparar todo para que el viaje sea un éxito.

El Chepe tiene $N$ vagones, numerados del $1$ al $N$. Los vagones están colocados sobre las vías del ferrocarril, pero desconoces su orden. La COMI te ha encargado ordenar los vagones del $1$ al $N$ para garantizar la integridad del ferrocarril.

Para ordenar los vagones tienes a tu disposición una máquina de intercambios. Esta máquina te permite realizar las siguientes operaciones:

* Para un segmento continuo de vagones de tamaño par, la máquina puede intercambiar la mitad izquierda con la mitad derecha del segmento. Ambas mitades mantienen su orden original (observa la imagen de abajo).
* Buscar la posición actual del vagón con número $v$.
* Saber cuál es el número del vagón en la posición $p$.

![ferrocarril](train.jpg)

La COMI ha sido muy estricta al aprobar el presupuesto de tu trabajo, por lo que te ha autorizado una cantidad muy limitada de operaciones de cada tipo que puedes realizar para completar el reacomodo.

# Problema

Dado el número $N$ de vagones del Chepe, tu tarea es ordenarlos haciendo uso de las operaciones que autorizó la COMI. **Este problema es interactivo**, por lo que no tendrás que leer entrada ni imprimir salida, en vez de eso, tienes que implementar la función `AcomodarFerrocarril` (**revisa la sección “Implementación”**).

# Implementación
**Función del evaluador**: ``EncontrarVagon()``  
C / C++		``int EncontrarVagon(int v);``  
Pascal		``function EncontrarVagon(var v: LongInt): LongInt;``  
***Descripción***: Llama a esta función para saber la posición actual del vagón numero $v$. Si existe el vagón con número $v$ la función devolverá un entero indicando su posición, en caso de que pases un número de vagón que no existe, devolverá ``0``.  
***Parámetros***: ``v`` – El número del vagón a encontrar.

**Función del evaluador**: ``VagonEnPosicion()``  
C / C++		``int VagonEnPosicion(int p);``  
Pascal		``function VagonEnPosicion(var p: LongInt): LongInt;``  
***Descripción***: Llama a esta función para conocer el número del vagón que se encuentra en la posición $p$ de la vía. En caso de que la posición $p$ sea menor a $1$ o mayor a $N$, la función devolverá ``0``.  
***Parámetros***: ``p`` – La posición que se quiere consultar.

**Función del evaluador**: ``IntercambiarVagones()``  
C / C++		``int IntercambiarVagones(int a, int b);``  
Pascal		``function IntercambiarVagones(var a, b: LongInt): LongInt;``  
***Descripción***: Llama a esta función para intercambiar el segmento $[a, b]$ de vagones. Si $a$ y $b$ definen un segmento inválido la función NO intercambiará ningún vagón y devolverá ``0``. Si fue posible realizar el intercambio devolverá ``1``. Un segmento es inválido si su tamaño es impar, si $b < a$ o algún índice es menor a $1$ o mayor a $N$.  
***Parámetros***: ``a`` – El índice de inicio del segmento a intercambiar. ``b`` – El índice de termino inclusivo del segmento a intercambiar.  

**Tu procedimiento**: ``AcomodarFerrocarril()``  
C / C++		``void AcomodarFerrocarril(int n);``  
Pascal		``procedure AcomodarFerrocarril(var n: LongInt);``  
***Descripción***: Esta función recibe el entero $N$ y debe usar las operaciones anteriores para acomodar el ferrocarril.  
***Parámetros***: $N$ – Un entero indicando el número de vagones del Chepe.

# Ejemplo

Supón que el Chepe tiene 5 vagones y están acomodados de la siguiente manera: 1, 4, 5, 3, 2.

A continuación se muestra cómo se pueden ordenar los vagones del Chepe utilizando las funciones autorizadas por la COMI:

||input
Función llamada
||output
Valor devuelto
||description
Explicación
||input
AcomodarFerrocarril(5)
||output
-
||description
Esta es la llamada que el evaluador realiza a tu función e inicia tu procedimiento para acomodar.
||input
BuscarVagon(1)
||output
1
||description
El vagón número 1 se encuentra en la posición 1, por lo tanto este vagón ya se encuentra ordenado.
||input
VagonEnPosicion(2)
||output
4
||description
El vagón que se encuentra en la posición 2 es el 4.
||input
IntercambiarVagones(2,5)
||output
1
||description
Se realiza un intercambio de todos los vagones desde la posición 2 hasta la posición 5.  
Los vagones quedarían de la forma: 1, 3, 2, 4, 5.
||input
BuscarVagon(6)
||output
0
||description
El vagón 6 no existe porque el Chepe tiene sólo 5 vagones. Por lo tanto, la función
devuelve 0.
||input
BuscarVagon(2)
||output
3
||description
El vagón número 2 se encuentra en la posición 3.
||input
IntercambiarVagones(3,2)
||output
0
||description
No es posible realizar un intercambio cuando el índice de termino es menor al índice de inicio.
||input
IntercambiarVagones(2,3)
||output
1
||description
Después de esta operación los vagones quedarían acomodados de la forma: 1, 2, 3, 4, 5.

Una vez que los vagones del tren estén ordenados, tu función debe terminar.
||end

# Evaluador

El evaluador de prueba recibe del archivo ``sample.in`` un entero $N$, el número de vagones por acomodar, seguido de una línea con $N$ enteros entre el $1$ y el $N$ describiendo el orden inicial de los vagones del ferrocarril.

Durante la ejecución, el evaluador de prueba imprimirá algunos mensajes para ayudarte a depurar tu solución. Al finalizar la ejecución de tu función, el evaluador de prueba imprimirá la cantidad de veces que llamaste a las funciones ``EncontrarVagon``, ``VagonEnPosicion`` e ``IntercambiarVagon`` y te dirá si el ferrocarril fue ordenado correctamente.

# Restricciones

* Subtarea 1 [17 puntos]
  * $1 \leq N \leq 200$, el número de vagones del Chepe.
  * Puedes llamar a ``EncontrarVagon``, ``VagonEnPosicion`` e ``IntercambiarVagones`` a lo más 40,000 veces cada una.

* Subtarea 2 [23 puntos]
  * $1 \leq N \leq 2,000$, el número de vagones del Chepe.
  * Puedes llamar a ``IntercambiarVagones`` a lo más 50,000 veces. Puedes llamar a ``EncontrarVagon`` y ``VagonEnPosicion`` a lo más 5,000 veces cada una.

* Subtarea 3 [25 puntos]
  * $1 \leq N \leq 20,000$, el número de vagones del Chepe.
  * Puedes llamar a ``IntercambiarVagones`` a lo más 40,000 veces. Puedes llamar a ``EncontrarVagon`` y ``VagonEnPosicion`` a lo más 20,000 veces cada una.

* Subtarea 4 [11 puntos]
  * $1 \leq N \leq 24,000$, el número de vagones del Chepe.
  * Puedes llamar a ``IntercambiarVagones`` a lo más 36,000 veces. Puedes llamar a ``EncontrarVagon`` y ``VagonEnPosicion`` a lo más 24,000 veces cada una.

* Subtarea 5 (NO AGRUPADA) [12 puntos]
  * $1 \leq N \leq 5,000$, el número de vagones del Chepe.
  * Puedes llamar a ``IntercambiarVagones`` a lo más 7,500 veces. Puedes llamar a ``VagonEnPosicion`` a lo más 5,000 veces. No puedes hacer ninguna llamada a ``EncontrarVagon.``

* Subtarea 6 (NO AGRUPADA) [12 puntos]
  * $1 \leq N \leq 40,000$, el número de vagones del Chepe.
  * Puedes llamar a ``IntercambiarVagones`` a lo más 60,000 veces. Puedes llamar a ``VagonEnPosicion`` a lo más 40,000 veces. No puedes hacer ninguna llamada a ``EncontrarVagon.``

# Evaluación

Si durante la ejecución de tu función ``AcomodarFerrocarril`` excedes el límite de llamadas permitidas para cualquiera de las funciones del evaluador, recibirás un puntaje de 0 puntos. Si al finalizar la ejecución de tu función el ferrocarril no se encuentra ordenado, tu puntaje será de 0 puntos. Recibirás los puntos completos para un caso si el ferrocarril es acomodado correctamente, no excedes el límite de llamadas para ninguna de las funciones del evaluador y tu código no excede el límite de tiempo de ejecución permitido.

# Experimentación
{{libinteractive:download}}

---

![illustration](illustration.png)
