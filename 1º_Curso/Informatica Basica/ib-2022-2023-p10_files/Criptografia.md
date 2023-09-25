## Introducción a la criptografía

Durante la segunda guerra mundial, el ejército alemán utilizó la máquina conocida como *Enigma*
para codificar sus mensajes. 
Básicamente dada una *semilla* la máquina generaba una secuencia de números pseudoaleatorios que era 
difícil de reproducir, incluso aunque los detalles técnicos de la máquina pudieran ser descubiertos.
Los aliados habían capturado algunas de las máquinas *Enigma*, de modo que conocían la forma
en que la máquina trabajaba, pero los trabajos que se realizaron para descubrir los códigos de *Enigma* fueron
los fundamentos de la criptografía moderna. 
Alan Turing participó en este tipo de trabajos.
Si está interesado en conocer más sobre esta historia vea la película
[The Imitation Game](https://en.wikipedia.org/wiki/The_Imitation_Game)
(*Descifrando Enigma* en español).

La criptología es la rama de conocimiento que se ocupa del estudio y diseño de sistemas que permiten 
comunicaciones secretas entre un emisor de un mensaje y uno o varios receptores del mismo. 
Inicialmente las únicas aplicaciones de la criptología fueron militares, pero hoy en día son muchísimas otras.
Por ejemplo, en los ordenadores multiusuario, cada usuario mantiene sus ficheros de una forma 
que no sean legibles para otros usuarios "indiscretos". 
Para conseguir esto, los ficheros se codifican (encriptan) utilizando una clave que sólo conoce su propietario. 
Mucha de la información que enviamos a través de internet viaja también de forma codificada para protegerla de receptores no deseados.

Para encriptar un fichero hay muchas alternativas. 
Todas ellas consisten en transformar cada uno de los caracteres del fichero original en otro carácter
diferente siguiendo una determinada transformación. 
Indicaremos dos métodos diferentes de encriptado. 

### Encriptado xor (or exclusiva)
El 
[Cifrado XOR](https://es.wikipedia.org/wiki/Cifrado_XOR)
requiere una clave secreta de encriptado/desencriptado.
A cada uno de los caracteres del fichero se le hará una transformación, 
que consistirá en hacerle la operación `xor` con un carácter de la clave secreta. 
Estudie el capítulo 
[Bitwise operators](https://www.learncpp.com/cpp-tutorial/bitwise-operators/)
del tutorial y recuerde que el operador (de bits) en C/C++ es `^`

El carácter de la clave secreta con el que se transforma el carácter original, se variará de forma cíclica. 
P. ej. si suponemos que la clave secreta es la palabra `alfa`, y las primeras palabras del texto son 
*Informática Básica* los primeros caracteres del fichero de salida serán:

```
carácter 1  I xor a
carácter 2  n xor l
carácter 3  f xor f
carácter 4  o xor a
carácter 5  r xor a
carácter 6  m xor l
carácter 7  á xor f
carácter 8  t xor a
carácter 9  i xor a
carácter 9  c xor l
carácter 10 a xor f
carácter 11   xor a
carácter 12 B xor a
carácter 13 á xor l
carácter 14 s xor f
   ...
```

Es decir, se va haciendo la operación `xor` de cada uno de los caracteres del 
texto de entrada con cada uno de los caracteres de la clave secreta, 
tomando la clave de forma cíclica (cuando se acaba con el último carácter de la clave, se comienza de nuevo con el primero).

Antes de operar de este modo se procesará la clave secreta haciendo `xor` a cada uno de sus caracteres con la constante 128.

Una ventaja de este método es su especial aptitud para ser utilizado en un ordenador 
puesto que la operación o exclusiva se realiza muy eficientemente en un ordenador. 
Otra ventaja del método es que la operación de desencriptado consiste en hacer exactamente 
lo mismo al texto que se ha encriptado (con la misma clave secreta, por supuesto).

### Cifrado de César
Como se deduce de su nombre, 
[este método](https://es.wikipedia.org/wiki/Cifrado_C%C3%A9sar)
era usado ya en tiempos de los romanos. 
En este caso, la codificación es como sigue: si una letra en el texto a codificar es la N-ésima 
letra del alfabeto, sustitúyase esa letra por la (N + K)-ésima letra del alfabeto. 
(César utilizaba el valor K = 3).
Se muestra a continuación un texto encriptado siguiendo este método y utilizando K = 1:

```
Texto original:  Navidad, Navidad, dulce navidad
Texto encriptado:  Obwjebe-!Obwjebe-!evmdf!obwjebe
```

Se puede optar por hacer fijo el valor de K o bien solicitarlo al usuario.

Evidentemente, el desencriptado del fichero consistirá en realizar la operación inversa, 
y en este caso, el valor de K a utilizar debería solicitarse al usuario para garantizar que está autorizado a leer el fichero.