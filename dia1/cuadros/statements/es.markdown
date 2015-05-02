# Historia

Karel está experimentando con su lado artístico. Está OMI está decidido a hacer un gran mural, pero Karel tiene una fobia hacia los cuadros y desea que su pintura no contenga ningún cuadro.

El mundo de Karel representa un lienzo en blanco. El mundo es un rectángulo sin paredes intermedias y sin zumbadores. 

Si en cualquier lugar del lienzo es posible encontrar un conjunto de posiciones sin zumbadores que formen un cuadrado, se considera que la pintura tiene un cuadro.  Al inicio ninguna posición tiene zumbadores, por lo tanto, al inicio la pintura contiene muchos cuadros.  

Karel piensa poner zumbadores en algunas posiciones del lienzo para que este no contenga ningún cuadro.  Karel quiere poner los menos zumbadores posibles para eliminar todos los cuadros de la pintura. Ayuda a Karel a lograrlo.

**Es importante que revises el ejemplo para que te quede claro cómo son
los cuadros que desea eliminar Karel.**
 
# Problema	

Escribe un programa que dado el lienzo inicial coloque zumbadores dentro del mismo de modo que la pintura no contenga cuadros.  

Hay muchas formas de lograr el objetivo anterior, la mejor solución es aquella que coloca **el menor número de zumbadores**, sin embargo, para obtener puntos, no es necesario que tu solución sea la menor posible.

# Consideraciones
<ul>
  <li>Karel inicia en la posición (1,1) del mundo orientado al norte.</li>
  <li>Karel inicia con infinitos zumbadores en la mochila.</li>
  <li>El mundo es un cuadrado sin paredes internas.
No importa la posición ni la orientación final de Karel.</li>
  <li>Para obtener puntos, tu programa deberá colocar zumbadores de modo que <b>sea imposible formar cuadros</b>, buscando siempre colocar la menor cantidad de zumbadores posible.</li>
  <li>
    <b>IMPORTANTE</b>
    <ul>
      <li><b>El número de puntos que obtengas en este problema dependerá de la cantidad de zumbadores que coloques</b>.</li>
      <li>Si al terminar la ejecución, la pintura contiene algún cuadro, obtendrás <b>0 puntos en ese caso</b>.</li>
      <li>Si tu programa coloca zumbadores en más del 50% de las posiciones obtendrás <b>0 puntos</b>.</li>
      <li>Para un conjunto de casos con valor de 21 puntos tu programa deberá colocar zumbadores en  a lo más el 50% de las posiciones.</li>
      <li>Para otro conjunto de casos con valor de 23 puntos tu programa deberá colocar zumbadores en a lo más el 35% de las posiciones.</li>
      <li>Para otro conjunto de casos con valor de 27 puntos tu programa deberá colocar zumbadores en a lo más el 31% de las posiciones.</li>
      <li>Para un último conjunto de casos con valor de 29 puntos tu programa obtendrá una cantidad de puntos determinada por la siguiente regla:
        <ul>
          <li> 0% si tu programa coloca zumbadores en más del 31% de las posiciones</li>
          <li> 100% si tu programa coloca el número mínimo de zumbadores posible.</li>
          <li> Si tu programa coloca una cantidad de zumbadores que está entre el mínimo posible y el 30% obtendrá una cantidad de puntos proporcional.</li>
        </ul>
      </li> 
    </ul>
  </li>
</ul>

# Ejemplos
 
![Entrada](entrada.png)

El mundo de entrada es un lienzo de 5 x 5 que inicialmente no tiene zumbadores. En total hay 25 posiciones.

![Salida](salida.png)

Este es un ejemplo posible de salida, todos los cuadros, de todas las longitudes han sido eliminados. En total se colocaron 9 zumbadores lo que corresponde a un 36% de las posiciones originales. Para este lienzo es posible encontrar arreglos que quitan todos los cuadros colocando únicamente 6 zumbadores lo que representa el 24% de las posiciones originales.

A continuación se muestran algunos ejemplos de resultados inválidos que no eliminan todos los cuadros del lienzo.

![Mala salida 1](malaSalida1.png)

En la imagen se muestra que aún hay un cuadro de 2 x 2 que puede formarse.

![Mala salida 2](malaSalida2.png)

Esta solución deja dos cuadros de 1 x 1 y uno de 4 x 4 y por tanto es inválida.

## Nota

En la parte de hasta arriba hay un link para validar tus soluciones con la versión en línea
de Karel (karel.js). Te recomendamos utilizarlo para que no pierdas tiempo validando si tus
soluciones tienen o no cuadros.

---

![ilustración](illustration.jpg)
