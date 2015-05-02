# Historia

Karel se inscribi� en una carrera de campo traviesa. La carrera se corre en un circuito, cada secci�n del circuito tiene un nivel de dificultad. Los participantes deben iniciar en alg�n punto del circuito y recorrer las siguientes ***K*** secciones del mismo. **Un corredor siempre recorre *K* secciones a partir de donde empiece, no importa el largo total del circuito.** 

La *dificultad* total del recorrido se calcula sumando el nivel de dificultad de las ***K*** secciones. Para un circuito, la dificultad total var�a dependiendo de la posici�n d�nde se inicia la carrera. Karel es muy competitivo y le gustan los retos, por lo tanto quiere buscar la **dificultad total m�xima** posible del circuito.

En el mundo de Karel est� dibujado el circuito con montones de zumbadores.  Cada mont�n es una secci�n.  El n�mero de zumbadores en el mont�n representa la dificultad de esa secci�n. El mundo es rectangular sin paredes intermedias.  El circuito puede tener cualquier forma pero puedes estar seguro de que ninguna secci�n toca la pared y que cada secci�n del circuito est� conectada exactamente a otras dos secciones.  El n�mero ***K*** de secciones a recorrer en el circuito estar� representado por un mont�n de zumbadores en la posici�n (1,1) del mundo.

# Problema

Escribe un programa que dado un circuito y el n�mero ***K*** de secciones a recorrer le ayude a Karel a determinar la **dificultad total m�xima posible** del mismo. Tu programa deber� dejar un mont�n de zumbadores en la posici�n (1,1) igual a la dificultad total m�xima del circuito.

# Consideraciones

* Karel inicia en la posici�n (1,1) orientado al norte.
* El n�mero ***K*** de secciones a recorrer est� representado por un mont�n en la posici�n (1,1) y ser� un valor entre 1 y 100.
* Karel inicia con **infinitos zumbadores en la mochila**.
* El mundo de Karel siempre ser� un cuadro de 100 filas por 100 columnas.
* El circuito nunca tendr� m�s de 160 secciones de largo.
* No importan la direcci�n ni la orientaci�n final de Karel, �nicamente los zumbadores que dejes en la posici�n (1,1)

# Ejemplo

#input
![Entrada Ejemplo](entrada.png)
#output
![Salida Ejemplo](salida.png)

El mundo de ejemplo muestra un circuito y el n�mero **K=7** de secciones a recorrer en la posici�n (1,1). En el mundo de salida Karel dej� un mont�n de 20 zumbadores en la posici�n (1,1) ya que esa es la **dificultad total m�xima** del circuito. En el mundo se muestra tambi�n d�nde tiene que iniciar el recorrido para lograr esa dificultad. **La posici�n de Karel NO IMPORTA, s�lo el mont�n de zumbadores que representa la dificultad total m�xima del circuito.**

---

![ilustraci�n](illustration.jpg)
