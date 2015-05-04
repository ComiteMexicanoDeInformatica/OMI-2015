Te contrataron para estar a cargo del área de exportaciones de la fábrica de salsa “La Pikina”. Te acaba de llegar un pedido del extranjero. Tu cliente quiere la mayor cantidad de botellas de Salsa la Pikina que puedas enviar, sin embargo debido a regulaciones gubernamentales es necesario que todas las botellas que envíes contengan exactamente la misma cantidad de salsa.

El sistema de llenado utilizado por tu fábrica tiene un alto margen de error, lo que hace imposible tener todas las botellas con la misma cantidad de salsa.

Actualmente tienes $N$ botellas de salsa en el almacén, cada una tiene una cierta cantidad de salsa. Cuentas también con un total de $K$ mililitros de salsa, cada uno de los cuales puedes agregar con un máquina a la botella o botellas que desees.

# Problema
Escribe un programa que decida cómo agregar salsa a las botellas de modo que la cantidad de botellas que puedas enviar sea la máxima posible, es decir, que la cantidad de botellas con exactamente la misma cantidad de salsa sea la máxima posible usando a lo más $K$ mililitros extras. 

Tu programa deberá escribir la cantidad de botellas y la cantidad de salsa que contendrán.  En caso de que haya más de una solución con la misma cantidad de botellas deberás elegir aquella en que las botellas tengan la menor cantidad de salsa.

# Entrada

La primera línea contendrá dos enteros $N$ y $K$ respectivamente.
La segunda línea contendrá $N$ enteros representando la cantidad de mililitros que tiene cada una de las botellas.

# Salida

Tu programa deberá escribir dos enteros separados por un espacio representando la cantidad máxima de botellas que puedes enviar y los mililitros que contendrá cada una de ellas.

# Restricciones

* $1 \leq N \leq 2,000,000$ (Número de botellas)
* $0 \leq K \leq 1,000,000,000$ (Cantidad de mililitros)
* $0 \leq c_i \leq 1,000,000$ (Mililitros que contiene la $i$-ésima botella)

# Ejemplo

||input
5 2
1 3 3 4 3
||output
4 3
||description
Es posible agregar 2 mililitros a la primera botella con lo cual esta quedaría con 3 mililitros y se tendrían 4 botellas con esa cantidad.

Si se quisieran dejar 4 mililitros en todas las botellas sería necesario agregar 3 a la primera botella y 1 a todas las botellas de 3 mililitros, en total 6. Cómo sólo cuentas con 2 mililitros para agregar, esta solución no es posible. 
||end

# Evaluación

* Para un grupo de casos con valor de **8** puntos, $N \leq 5$ y $K \leq 10$. 
* Para un grupo de casos con valor de **7** puntos, $N \leq 100,000$ y $K \leq 1$.
* Para un grupo de casos con valor de **14** puntos, $N \leq 1,000$.
* Para un grupo de casos con valor de **40** puntos, $N \leq 100,000$.
* Pala el último grupo de casos con valor de **31** puntos, $N \leq 2,000,000$ y $K \leq 1,000,000,000$.

---

![illustration](illustration.png)
