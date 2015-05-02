# Historia

Karel se inscribió en una carrera de campo traviesa. La carrera se corre en un circuito, cada sección del circuito tiene un nivel de dificultad. Los participantes deben iniciar en algún punto del circuito y recorrer las siguientes ***K*** secciones del mismo. **Un corredor siempre recorre *K* secciones a partir de donde empiece, no importa el largo total del circuito.** 

La *dificultad* total del recorrido se calcula sumando el nivel de dificultad de las ***K*** secciones. Para un circuito, la dificultad total varía dependiendo de la posición dónde se inicia la carrera. Karel es muy competitivo y le gustan los retos, por lo tanto quiere buscar la **dificultad total máxima** posible del circuito.

En el mundo de Karel está dibujado el circuito con montones de zumbadores.  Cada montón es una sección.  El número de zumbadores en el montón representa la dificultad de esa sección. El mundo es rectangular sin paredes intermedias.  El circuito puede tener cualquier forma pero puedes estar seguro de que ninguna sección toca la pared y que cada sección del circuito está conectada exactamente a otras dos secciones.  El número ***K*** de secciones a recorrer en el circuito estará representado por un montón de zumbadores en la posición (1,1) del mundo.

# Problema

Escribe un programa que dado un circuito y el número ***K*** de secciones a recorrer le ayude a Karel a determinar la **dificultad total máxima posible** del mismo. Tu programa deberá dejar un montón de zumbadores en la posición (1,1) igual a la dificultad total máxima del circuito.

# Consideraciones

* Karel inicia en la posición (1,1) orientado al norte.
* El número ***K*** de secciones a recorrer está representado por un montón en la posición (1,1) y será un valor entre 1 y 100.
* Karel inicia con **infinitos zumbadores en la mochila**.
* El mundo de Karel siempre será un cuadro de 100 filas por 100 columnas.
* El circuito nunca tendrá más de 160 secciones de largo.
* No importan la dirección ni la orientación final de Karel, únicamente los zumbadores que dejes en la posición (1,1)

# Ejemplo

#input
![Entrada Ejemplo](entrada.png)
#output
![Salida Ejemplo](salida.png)

El mundo de ejemplo muestra un circuito y el número **K=7** de secciones a recorrer en la posición (1,1). En el mundo de salida Karel dejó un montón de 20 zumbadores en la posición (1,1) ya que esa es la **dificultad total máxima** del circuito. En el mundo se muestra también dónde tiene que iniciar el recorrido para lograr esa dificultad. **La posición de Karel NO IMPORTA, sólo el montón de zumbadores que representa la dificultad total máxima del circuito.**

---

![ilustración](illustration.jpg)
