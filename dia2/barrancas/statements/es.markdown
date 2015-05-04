Las barrancas del cobre son uno de los puntos de interés turístico más famosos de Chihuahua.  Una agencia de viajes te ha pedido ayuda para diseñar un recorrido a través de ellas.

El recorrido a través de las barrancas tiene $N$ vistas espectaculares numeradas de $1$ a $N$.  Por supuesto, hay algunas más llamativas que otras.  Los expertos de la agencia han calificado cada una de las $N$ vistas de acuerdo a su espectacularidad. 

Los recorridos que vende la agencia llevan a los turistas a un punto de inicio y a partir de ahí visitan las siguientes $K$ vistas.  La agencia tiene una preocupación.  Cuando llevas un turista de una vista a la siguiente, si la segunda vista es **más espectacular** el turista se siente **emocionado**, sin embargo si la segunda vista es **menos espectacular** el turista se siente **decepcionado**.

La emoción y decepción del turista pueden medirse. Cuando el turista pasa de una vista a la siguiente, su emoción total cambia de acuerdo a las siguientes reglas:

* Si la nueva vista es **más espectacular** la emoción total **aumenta** una cantidad igual a la diferencia de espectacularidad entre ambas barrancas.

* Si la nueva vista es **menos espectacular** la emoción total **disminuye** una cantidad igual a la diferencia de espectacularidad entre ambas barrancas.

Obviamente la agencia no puede reacomodar las barrancas, así que en un recorrido el turista pasará por vistas que aumenten su emoción y vistas que disminuyan su emoción.

La agencia quiere que le ayudes a encontrar el recorrido con el cual el turista quedará más emocionado. 

**NOTA: Te recomendamos ampliamente revisar la explicación del ejemplo para que el problema te quede más claro**.

# Problema

Escribe un programa que dada la espectacularidad de cada una de las $N$ vistas y el número $K$ de vistas que se van a incluir en el recorrido encuentre cuál es la emoción total máxima que se puede lograr.

# Entrada

Tu programa debe leer del teclado la siguiente información:

* En la primera línea los número $N$ y $K$, el número de vistas y la longitud del recorrido.

* En la siguiente línea habrá $N$ números no negativos separados por un espacio que indican la espectacularidad de las $N$ vistas.

# Salida

Tu programa debe escribir en la pantalla un único número que representa la emoción total máxima posible para un recorrido de $K$ vistas.

# Restricciones

$2 \leq N \leq 50,000$, el número de vistas.

$2 \leq K \leq N$, la cantidad de vistas en el recorrido.

$0 \leq e_i \leq 10,000$, la espectacularidad de la $i$-ésima vista.

# Ejemplo

||input
6 4
2 1 3 2 6 2
||output
5
||description
El recorrido será de 4 vistas. Si se inicia en la primera vista, la emoción total se calcula como sigue:

* De la primera vista a la segunda se disminuye la espectacularidad. La emoción total **disminuye** por 1 porque 2–1=1 y la emoción total va en -1.

* De la segunda a la tercera la espectacularidad aumenta. La emoción total **aumenta** por 2 porque 3-1=2. La emoción total queda en 1 ya que -1+2=1.

* Finalmente de la tercera a la cuarta la espectacularidad disminuye, la emoción total **disminuye** en 1 porque 3-2=1 y queda en 0 porque 1-1=0.

Las operaciones para calcular la emoción total iniciando
desde la primera vista serían:

$$(1 – 2) + (3 – 1) + (2 – 3) = -1 + 2 - 1 = 0$$

Si se inicia en la segunda vista, la emoción total se calcula como sigue:

$$(3 – 1) + (2 – 3) + (6 – 2) = 2 – 1 + 4 = 5$$

Revisa con cuidado el cálculo anterior con el ejemplo hasta que entiendas cómo se hizo.

Por último si se inicia en la tercera vista, la emoción total se calcula:

$$(2 – 3) + (6 – 2) + (2 – 6) = -1 + 4 – 4 = -1$$

No es posible empezar en la cuarta, quinta o sexta vistas ya que sería imposible realizar las 4 vistas del recorrido.

**La respuesta del problema es la emoción total máxima la cual se obtiene iniciando en la segunda vista y su total es 5**. 
||end

#Evaluación

* Para un conjunto de casos de prueba con valor de **70** puntos, $N \leq 10,000$.
* Para el resto de los casos de prueba se cumplirá que $N \leq 50,000$.

---

![illustration](illustration.jpg)
