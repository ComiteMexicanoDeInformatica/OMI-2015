# Historia

Karel fue seleccionado para el servicio militar en el batallón de ingenieros zapadores. Parte de su entrenamiento es aprender a recorrer campos minados (y salir vivo, por supuesto).

El día de hoy, Karel debe recorrer un campo minado.  El campo se representa como un mundo rectangular que no tiene paredes internas.  Las minas se representan como montones de zumbadores, la cantidad de zumbadores en el montón determina **el segundo en el que explotará la mina**, es decir, un montón de 5 zumbadores representa una mina que explotará en el segundo 5 a partir de que se inicia el ejercicio. Si al momento en que explota la mina Karel se encuentra **sobre ella, en la casilla de la izquierda o en la casilla de la derecha**, Karel explotará. Cuando una mina explota **no detona** ninguna de las minas a su alrededor.

Karel inicia el recorrido en la posición (1,1) en el segundo cero. Siempre debe recorrer el campo fila por fila como se muestra en la figura:

![Figura el camino minado](bombas1.png)

Karel avanza 1 casilla por segundo, no importa la dirección en la que se esté moviendo.  Por ejemplo, inicia en la casilla (1,1) en el segundo cero, en el segundo uno estará en la columna 2 de la fila 1 y para el ejemplo de la figura en el segundo 6 estará en la columna 6 de la fila 2.

# Problema

Escribe un programa que reciba el mundo que representa el campo minado y que ayude a Karel a saber si sobrevivirá o no al recorrido. Si Karel explota durante el recorrido, tu programa deberá apagarlo en la posición donde estaba cuando murió. Si Karel sobrevive al recorrido deberá apagarse en la última posición del recorrido. Para que te quede más claro te recomendamos revisar el ejemplo.

# Consideraciones

* Karel inicia en la posición (1,1) del mundo orientado al Este.
* Karel inicia con **0 zumbadores en la mochila**.
* No importan la orientación final de Karel, ni los zumbadores que queden en el mundo. **Sólo importa la posición final de Karel**.
* En este problema se agruparán casos de prueba, para obtener los puntos de un grupo, tu programa deberá resolver de manera correcta **todos los casos del grupo**.
* **IMPORTANTE**
  * Para un conjunto de casos con valor de 33 puntos tu programa deberá ejecutar la instrucción **avanza/move** un máximo de **N+1** veces (donde **N** es la cantidad de segundos que se requiere para hacer el recorrido completo).  Es decir, si en alguno de estos casos tu programa ejecuta la instrucción **avanza/move** más de **N** veces **obtendrás 0 puntos**.
  * Para el resto de los casos de prueba **no tienes límite en la cantidad de veces que puedes ejecutar la instrucción avanza/move**.

# Ejemplos

# Ejemplo 1
Entrada
![Entrada ejemplo 1](entrada1.png)

Salida
![Salida ejemplo 1](salida1.png)

La primera mina por la que pasa Karel es la que está en la fila 1, columna 4. Esa mina explota en el segundo 5. Cuando esa mina explota Karel no está sobre ella ni a su izquierda ni a su derecha. 
La segunda mina es la de la fila 2, columna 6. Esta mina explota en el segundo 6, justo cuando Karel pasa sobre ella, por lo tanto Karel explota y debe apagarse en esa posición.
# Ejemplo 2
Entrada
![Entrada ejemplo 2](entrada2.png)

Salida
![Salida ejemplo 2](salida2.png)

El mundo es similar al anterior, pero esta vez la segunda mina explota en el segundo 5, en ese momento Karel no está sobre ella ni a su izquierda ni a su derecha.  La tercera mina (fila 2, columna 2) explota en el segundo 9.  En ese momento Karel está a su derecha y por lo tanto explota.  **Karel debe apagarse en la posición donde se encontraba al momento de la explosión.**
# Ejemplo 3
Entrada
![Entrada ejemplo 3](entrada3.png)

Salida
![Salida ejemplo 3](salida3.png)

Esta vez la tercera mina explota cuando Karel está a su izquierda.  Por lo tanto Karel debe a la izquierda de la mina.
# Ejemplo 4
Entrada
![Entrada ejemplo 4](entrada4.png)

Salida
![Salida ejemplo 4](salida4.png)

En este último ejemplo Karel sobrevive al recorrido sin que ninguna mina explote sobre o junto a él y por lo tanto debe apagarse en la última posición del recorrido.

---

![ilustración](illustration.png)
