Un artesano rarámuri desea hacer un tapete conmemorativo de la OMI. Para hacerlo utilizará un gran tapete blanco de tamaño $N \times N$.

Al artesano le gustan los diseños con cuadros, para este tapete hizo un diseño de cuadrados concéntricos que se alternan de colores negro y blanco.  Es importante notar que el **cuadrado exterior siempre será de color negro**.  A continuación se muestra una figura ejemplo del diseño del artesano.

![pattern](pattern.png)

Recordarás que el tapete original es blanco, para obtener los cuadros negros, el artesano deberá teñir secciones de la palma con la que se tejió el tapete. Teñir palma es más difícil que teñir tela ya que para **teñir cada sección** de la palma se requiere **distinta cantidad de tinta**.

Por desgracia, el artesano tiene una cantidad $T$ de tinta y por el momento no puede conseguir más.  Debido a esto, es posible que la tinta que tiene **no le alcance para teñir todo el tapete**. 

El artesano quiere mantener el diseño y hacer el tapete más grande posible que le alcance con la tinta que tiene (lo que le sobre de tapete será recortado).  El artesano sabe **cuánta tinta requiere para teñir cada sección del tapete**.

El artesano te ha pedido tu ayuda para que hagas un programa que dado el tamaño del tapete original, la cantidad de tinta requerida para teñir cada sección y la cantidad total $T$ de tinta calcule cuál es el tapete más grande que puede hacer respetando su diseño original.

**IMPORTANTE: Recuerda que el cuadro exterior del tapete siempre debe ser de color negro.  El cuadro interno será negro o blanco dependiendo del tamaño del tapete.**

# Problema

Escribe un programa que dado el tamaño del tapete original, la cantidad de tinta necesaria para teñir cada sección y la cantidad $T$ de tinta que tiene el artesano calcule el tamaño máximo de tapete que puede hacer el artesano respetando su diseño.

# Entrada

Tu programa debe leer del teclado la siguiente información:

En la primer línea los números $N$ y $T$, el tamaño del tapete original y la cantidad total de tinta que tiene el artesano. 

En las siguientes $N$ líneas habrá $N$ números separados por espacio que representan la cantidad necesaria de tinta para teñir cada sección del tapete.

# Salida

Tu programa deberá escribir a la pantalla un único número entero que representa el largo, en secciones, del cuadro exterior del tapete más grande que pueda hacer el artesano.

# Restricciones

* $1 \leq N \leq 1,000$, El tamaño del tapete original.
* $1 \leq T \leq 1,000,000,000$, Cantidad total de tinta que tiene el artesano.
* $1 \leq c_{ij} \leq 1,000$, Cantidad de tinta necesaria para teñir la sección $i,j$.

||input
8 80
9 5 3 6 9 1 6 9
9 7 3 3 1 4 7 5
6 4 7 7 5 2 5 8
3 6 6 6 1 3 8 4
3 9 4 7 5 2 3 7
9 5 2 9 7 8 7 9
1 4 5 2 8 5 2 1
6 2 6 3 8 1 7 5
||output
5
||description
![grid](grid.png)

La figura muestra el tapete original y el costo de teñir cada sección del mismo. Recuerda que el artesano desea crear el tapete más grande que respete el diseño original. Y de acuerdo al ejemplo, la cantidad total de tinta que tiene es 80.

![solvedgrid](solvedgrid.png)
||end

# Evaluación

* Para un grupo de casos con valor de 10 puntos, $N \leq 30$.
* Para un grupo de casos con valor de 14 puntos, $N \leq 120$.
* Para un grupo de casos con valor de 37 puntos, $N \leq 300$.
* Para un grupo de casos con valor de 39 puntos, $N \leq 1,000$.

---

![illustration](illustration.jpg)
