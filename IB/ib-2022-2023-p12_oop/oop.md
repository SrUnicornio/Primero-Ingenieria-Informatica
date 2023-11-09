# Práctica 12. Programación Orientada a Objetos. 

# Factor de ponderación: 10

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Desarrolle programas sencillos en C++ utilizando programación orientada a objetos, así como todas las características del lenguaje estudiadas anteriormente
* Aprenda a sobrecargar operadores en C++
* Ponga en práctica diferentes formas de relacionar clases en C++

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva) que se tendrán en cuenta a la hora de evaluar esta práctica.
Se comprobará que el alumnado:
* Conoce los conceptos expuestos en el material de referencia de esta práctica.
* Ha realizado todos los ejercicios propuestos en este enunciado
* Es capaz de escribir programas simples en C++ que resuelvan problemas de complejidad similar a los que se proponen en este documento
* Sabe cómo implementar la sobrecarga de diferentes tipos de operadores en los programas que desarrolle
* Es capaz de escribir programas orientados a objetos que involucren a diferentes clases con diversas formas
  de realación entre las mismas
* Sea capaz de utilizar VSC para editar y compilar programas de forma remota en su Máquina Virtual
* Conoce la plataforma Exercism y es capaz de descargar y realizar problemas sencillos interaccionando con ella.
* Es capaz de escribir un fichero `CMakeLists.txt` para automatizar el proceso de compilación de sus programas con `cmake` y `make`
* Ha automatizado la compilación de sus programas usando un fichero `Makefile` para cada uno de los programas que desarrolle
* Hace que sus programas se estructuren en torno a diferentes funciones (sean modulares)
* Todos sus programas se estructuran en directorios diferentes para cada "proyecto" haciendo que cada uno de
  ellos contenga un fichero `CMakeLists.txt` con la configuración de despliegue del proyecto.
* Utiliza en todos sus programas comentarios adecuados en el formato requerido por
[Doxygen](https://www.doxygen.nl/index.html)
* Acredita que todas las prácticas realizadas hasta la fecha se encuentran alojadas en repositorios privados de
[GitHub](https://github.com/).
* Acredita que es capaz de subir programas a la plataforma
[Jutge](https://jutge.org/)
para su evaluación
* Ha incluido un comentario prólogo en todos los ficheros (`*.cc`, `*.h`) de sus ejercicios
* Que todos los programas que desarrolla, antes de su ejecución imprimen en pantalla un mensaje indicando la
  finalidad del programa así como la información que precisará del usuario para su correcta ejecución.
* Hace que todos los programas que se presentan para su evaluación cumplan con los estándares definidos en la
[Guía de estilo de Google para C++](https://google.github.io/styleguide/cppguide.html)
* Utiliza siempre identificadores significativos en su programa (para constantes, variables, etc.) y
  no utiliza nunca identificadores de una única letra, tal vez con la excepción de las variables que utilice para iterar en un bucle.
* Acredita que es capaz de editar ficheros remotos en su VM usando vi
* Ha realizado todos sus ejercicios en la máquina virtual Ubuntu de la asignatura.
* Demuestra que es capaz de ejecutar comandos Linux en su VM

### Material de estudio complementario
Como parte de las tareas de esta práctica deberá entregar un fichero de texto con nombre `Good-Practices.txt`
en el que recopile traducidas a español el conjunto de buenas prácticas de programación que se proponen en el 
[tutorial de referencia](https://www.learncpp.com/)
que hemos usado en *Informática Básica*.

Para recopilar esa relación de buenas prácticas, revise los capítulos 0-18 localizando en el texto aquellas
partes con la etiqueta *Best Practice* y resaltadas en color verde.
Por ejemplo en el capítulo 
[1.2 Comments](https://www.learncpp.com/cpp-tutorial/comments/)
hallará este recuadro:
![Best Practice](https://raw.githubusercontent.com/IB-2022-2023/P12-OOP/main/best-prctice.png "Best Practice")

Así que su fichero `Good-Practices.txt` deberá incluir un párrafo:

* *Comente su código abundantemente, y escriba sus comentarios como si hablara con alguien que no tiene ni idea de lo que hace el código. 
No de por sentado que recordará por qué ha tomado determinadas decisiones.*

Si conforme recopila estas buenas prácticas encuentra alguna que no entienda, precise alguna explicación
o que tenga dudas sobre si ha estudiado el correspondiente concepto, publíquela en el foro del aula virtual 
de *Informática Básica* para tratar de aclararlo.

### Ejercicios
* Al realizar los ejercicios cree dentro de su repositorio de esta práctica un directorio diferente
para cada uno de los ejercicios.
Asigne a cada uno de esos directorios nombres significativos.
* Automatice la compilación del programa correspondiente a cada ejercicio con un fichero `Makefile`
independiente para cada programa e inclúyalo en el correspondiente directorio. 
Alternativamente podría también usarse `cmake` con un fichero `CMakeLists`, si se prefiere.
* Haga que todos los programas tomen su entrada por la línea de comandos y en caso de que se ejecuten sin
  pasarles el número adecuado de parámetros impriman en pantalla un mensaje indicando el modo correcto de
  ejecutar el programa.
* El código de cada uno de los programas deberá organizarse de forma modular, es decir haciendo uso de funciones.
* Cada función deberá realizar una única tarea y hacerlo correctamente.
* El identificador de una función debe reflejar claramente la finalidad de la función.

1. Desarrolle una clase `ComputeInt` que permita la realización de diferentes cálculos con números enteros.
Incluya al menos los siguientes métodos en la clase:
* *Factorial* que permita calcular el factorial de un número (Problema
[Factorial](https://jutge.org/problems/P48997_es)
de Jutge).
* *SumSerie* que calcule la suma de los primeros `n` términos de la serie: `1 + 2 + 3 + ... + n`.
* *IsPrime* que permita determinar si un determinado número es primo (Problema
[Primality](https://jutge.org/problems/P48713)
de Jutge).
* *IsPerfectPrime* que permita determinar si un determinado número es un primo perfecto (Problema
[Perfect primes](https://jutge.org/problems/P90664_en) 
de Jutge).
* *AreRelativePrimes* que permita determinar si dos números son
[mutuamente primos](https://en.wikipedia.org/wiki/Coprime_integers),
es decir, si su único divisor común es el 1

La función *main* del programa que usara esta clase podría contener, entre otras, sentencias como:
```
main() {
  ComputeInt computation; 
  std::cout << computation.Factorial(5) << std::endl; 
  std::cout << computation.SumSerie(100) << std::endl; 
  std::cout << computation.IsPrime(13) << std::endl; 
  std::cout << computation.AreRelativePrimes(13, 17) << std::endl; 
}
```

2. La clase Racional.

Un 
[número racional](https://en.wikipedia.org/wiki/Rational_number)
tiene un numerador y un denominador de la forma `p/q` donde `p` es el numerador y `q` el denominador.
Por ejemplo, 1/3, 3/4 y 10/4 son números racionales.

Un número racional no puede tener denominador 0, pero sí puede ser cero el numerador.
Todo número entero `n` es equivalente al racional `n/1`.
Los números racionales se utilizan en cálculos precisos que involucran fracciones.
Por ejemplo, `1/3 = 0.33333 ...`.
Este número no puede ser representado de forma precisa en formato de punto flotante utilizando los tipos float o double.
Para obtener resultados precisos es conveniente usar números racionales.

C++ dispone de tipos de datos para enteros y números en punto flotante, pero no para racionales.
En este ejercicio se propone el diseño de una clase para representar números racionales.

Desarrolle un programa cliente `racionales.cc` que permita operar con números racionales y haga uso
de la clase `Racional` que ha de diseñarse.

Las siguientes deben tomarse como especificaciones del programa a desarrollar:
* Separe el diseño de su clase `Racional` en dos ficheros, `racional.h` y `racional.cc` conteniendo
  respectivamente la declaración y la definición de la clase.
* La clase `Racional` incluirá al menos métodos para:
    * Crear objetos de tipo `Racional`. Se debe implementar un constructor por defecto y uno parametrizado.
    * Escribir (a fichero o a pantalla) un objeto de tipo `Racional`.
    * Leer (por teclado o desde fichero) un objeto de tipo `Racional`.
    * Sumar dos objetos de tipo `Racional`.
    * Restar dos objetos de tipo `Racional`.
    * Multiplicar dos objetos de tipo `Racional`.
    * Dividir dos objetos de tipo `Racional`.
    * Comparar objetos de tipo `Racional`.
* El programa ha de permitir leer un fichero de texto en el que figuran pares de números racionales
separados por espacios de la forma:

```
a/b c/d
e/f g/h
  ...
```

y para cada par de números racionales, el programa ha de imprimir en otro fichero de salida todas las operaciones posibles
con cada uno de los pares de números del fichero de entrada, de la forma:

```
a/b + c/d = n/m
  ...
```

Si el programa se ejecuta sin pasar parámetros en la línea de comandos, debemos obtener el siguiente mensaje:

```
./racionales -- Números Racionales
Modo de uso: ./racionales fichero_entrada fichero_salida
Pruebe ./racionales --help para más información
```

Si el programa se ejecuta pasando como parámetro la opción `--help` se ha de obtener:

```
./racionales -- Números Racionales
Modo de uso: ./racionales fichero_entrada fichero_salida 

fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: `a/b c/d` separados por un espacio
fichero_salida:  Fichero de texto que contendrá líneas con las operaciones realizadas: `a/b + c/d = n/m`
```

3. Descargue y estudie el problema 
[Robot Simulator](https://exercism.org/tracks/cpp/exercises/robot-simulator)
de Exercism y lea también el enunciado del problema siguiente (número 4) de esta relación.
El propósito de estudiar el problema de Exercism antes de resolver éste es que utilice aquí los mismos
identificadores para los métodos que necesite que los que utilizará en el problema siguiente (4).
Teniendo en mente ese problema de Exercism (*Robot Simulator*), diseñe una solución orientada a objetos para el problema
[Movements on the ground](https://jutge.org/problems/P79784) de Jutge.
Suba el problema a Jutge para su evaluación.

Su progama deberá basarse en una clase `Robot` a la que dotará de la funcionalidad necesaria para resolver el
probleja de Jutge.
Para que Jutge evalúe su solución tendrá que (contrariamente a lo habitual) escribir todo su código en un
único fichero.
Incluya en un fichero `robot_simulator_jutge.cc` tanto el código de la clase `Robot` como la función `main()`
que instancia un objeto `robot`.

El código de la función `main()` podría ser similar a este:
```cpp
 1 /** @brief Robot Client main function */
 2 int main() {
 3   const std::pair<int, int> kPosition{0, 0};
 4   const Bearing kBearing {Bearing::NORTH};
 5   Robot robot{kPosition, kBearing};
 6   std::string sequence;
 7   getline(std::cin, sequence);
 8   for (const auto& movement : sequence) {
 9     ...
10   }
11   std::pair<int, int> final_position = robot.get_position();
12   std::cout << "(" << final_position.first << ", " << final_position.second  << ")" << std::endl;
13   return 0;
14 }
```
En la función `main()` se declara (línea 5) un objeto `robot` que se inicializa con una posición (*position*) y una
orientación (*bearing*) que han sido definidas anteriormentei (líneas 3 y 4).
Para trabajar con las posiciones se utiliza un objeto `position` que se define en la clase `std::pair` de la
STL y que en este caso se utiliza para almacenar un par de números enteros, que definen la posición del robot.
Los ejemplos de
[este tutorial](https://www.geeksforgeeks.org/pair-in-cpp-stl/)
de Geeksforgeeks pueden servirle de ejemplo para iniciarse en el estudio de `std::pair`.
Al revisar ese tutorial y reproducir sus ejemplos, ¡tenga en cuenta las consideraciones de estilo que se usan
en *Informática Básica*!.

Las orientaciones que utiliza el robot (norte, sur, este, oeste) se definen en el programa en una clase
`Bearing` cuya definición es la siguiente:
```cpp
enum class Bearing { 
  NORTH, 
  EAST,
  SOUTH, 
  WEST
};
```
Es decir, se trata de una clase que simplemente define una enumeración con los valores correspondientes a los
puntos cardinales.

La función `main()` anterior lee una secuencia de movimientos (línea 7) y en el bucle `for` de la línea 8 hace que el robot ejecute
cada uno de los movimientos de la secuencia.
Al final del bucle (línea 12) se imprime la posición final del robot.

4.  Realice un programa orientado a objetos que resuelva el ejercicio 
[Robot Simulator](https://exercism.org/tracks/cpp/exercises/robot-simulator)
de Exercism. 
Consiga que su solución pase todos los tests y envíe su solución a la plataforma.
Si estudia el fichero `robot_simulator_test.cpp` de tests del problema observará que la clase `Robot` a
diseñar ha de contener al menos los métodos:
* *get_bearing()*
* *get_position()*
* *turn_right()*
* *turn_left()*
* *advance()*
* *execute_sequence()*

El directorio `robot-simulator-initial/` de esta práctica contiene código que puede servirle de ayuda para la
resolución del problema.

Comience por descargar el ejercicio de exercism, que se alojará en un directorio con nombre `robot-simulator/`.
Sustituya en ese directorio los ficheros `robot_simulator.cpp` y `robot_simulator.h` por los del directorio
`robot-simulator-initial/`. Habiendo hecho esos cambios, ejecute `cmake` en el directorio
`robot-simulator-initial/build` y compruebe que el programa pasa los primeros tests.

El el directorio `robot-simulator-initial` se han añadido los ficheros `robot_simulator_main.cc` y `Makefile`
que no son necesarios para Exercism, pero pueden resultarle útiles para depurar su programa de forma
independiente de Exercism.
Copie esos ficheros en `robot-simulator/` y ejecute `make`, que generará un fichero ejecutable que puede
depurar con el VSC si lo necesita.

Continúe añadiendo el código necesario en `robot_simulator.cpp` y `robot_simulator.h` para pasar los tests de
forma incremental.

Recuerde que la estrategia a seguir en la solución del problema consiste en ir "desbloqueando" progresivamente
los distintos tests que ha de pasar el programa.

5.- La realización de este ejercicio es opcional.
Se recomienda realizarlo a aquél alumnado que considere que ha realizado progresos significativos en cuanto a
su capacidad de realizar programas cada vez más complejos en C++.

La clase `Automata`.

En la práctica 10 de la asignatura se propuso un ejercicio en el que se leía desde un fichero la
especificación de un autómata finito determinista.
En este ejercicio se pide realizar una clase `Automata` para representar este tipo de autómatas.
El constructor de la clase debería recibir como parámetro el nombre del fichero de texto en el que se
especifica el autómata, y a partir de esa especificación el constructor construye los diferentes elementos que
caracterizan al autómata.

Tanga en cuenta que un autómata se caracteriza por un conjunto de estados (que pueden almacenarse en un
vector) en el que cada estado tiene un nombre (una etiqueta) y puede ser de aceptación o no y tiene un número determinado de transiciones.
Uno de los estados del autómata es un estado especial y se conoce como estado de arranque.

A modo de ejemplo, describiremos a continuación los diferentes elementos de este autómata:
![este autómata](https://raw.githubusercontent.com/IB-2022-2023/P10-files/main/dfa.png)

El autómata de la figura tiene 4 estados.
Sus etiquetas son `q0`, `q1`,`q2` y `q3`.
Los estados de aceptación están indicados con círculos de doble trazo y son `q1` y `q2`.
El estado de arranque se indica con una flecha (triángulo) sobre él y es `q0`.
Todos los estados del autómata de la figura tienen 2 transiciones (dos flechas que salen del estado en
dirección a otro estado) y está etiquetadas con símbolos que en este ejemplo son `a` y `b`.

En el directorio `p12-Automaton-class/src/` de esta práctica tiene un código inicial que puede servirle como punto
de partida para su desarrollo.
En el diseño que se propone intervienen las clases `Automaton`, `State` y `Transition` relacionadas de modo
que un Autómata se caracteriza por un conjunto de estados (se utiliza un vector de estados, `states_`).
Uno de esos estados es el estado inicial y algunos de los estados (pudieran ser todos ellos) son estados de
aceptación y por tanto figuran en otro conjunto (otro vector).
El autómata posee también un alfabeto, que es el conjunto de símbolos ({a, b} en el autómata de ejemplo) que
producen las transiciones (aparecen como etiquetas de los arcos del diagrama).

Por otra parte la clases `State` y `Transition` representan los estados y transiciones del autómata
respectivamente.
Los identificadores que se utilizan en ambas clases indican la finalidad tanto de los miembros de datos como
de los métodos de las mismas.
Así por ejemplo un objeto `Transtion` se caracteriza por el símbolo (caracter) de la transición y el estado de
destino de la misma.

El programa principal `automatons.cc` simplemente declara un objeto `Automaton` que invoca el método *Print()*
para imprimir en pantalla la información correspondiente. 
La ejecución de ese programa:

`$ ./automatons ../example.dfa`

debería imprimir en pantalla una salida como la siguiente:
```
DFA constructor. File name: ../example.dfa
Autómata impreso:
=================

Número de Estados:4
Estado de arranque: 0
Alfabeto: {a, b}
Estados de aceptación: {1, 2}
delta(0, a) = 1
delta(0, b) = 3
delta(1, a) = 1
delta(1, b) = 2
delta(2, a) = 1
delta(2, b) = 3
delta(3, a) = 3
delta(3, b) = 3

```




