# Práctica 06. Alternativas e Iteraciones

# Factor de ponderación: 6

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Sea capaz de resolver problemas sencillos en C++ usando todos los conocimientos adquiridos
  hasta ahora, y en particular haciendo uso de sentencias alternativas y de iteración
* Conozca la herramienta `make` y que sea capaz de configurar ficheros `Makefile` sencillos
  para la automatización de la compilación de sus ejercicios.
* Comience a gestionar sus asignaciones de trabajos prácticos usando [GitHub Classroom](https://classroom.github.com)

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva) que se tendrán en cuenta a la hora de evaluar esta práctica.
Se comprobará que el alumnado:
* Es capaz de escribir programas simples en C++ que resuelvan problemas de
  complejidad similar a los que se han propuesto para esta práctica
* Ha automatizado la compilación de sus programas usando un fichero `Makefile`
  para cada uno de los programas que desarrolle 
* Acredita que todas las prácticas realizadas hasta la fecha se encuentran alojadas en repositorios
  privados de [GitHub](https://github.com/).
* Acredita que es capaz de subir programas a la plataforma [Jutge](https://jutge.org/) para su evaluación
* Ha incluido un comentario prólogo en todos los ficheros (`*.cc`, `*.h`) de sus ejercicios
* Hace que todos los programas de sus prácticas se ajusten a la
[Guía de estilo de Google para C++](https://google.github.io/styleguide/cppguide.html) 
* Acredita que es capaz de editar ficheros remotos en su VM usando vi
* Demuestra que es capaz de ejecutar comandos Linux en su VM

### GitHub Classroom
En el futuro se utilizará GitHub Classroom (una plataforma relacionada con GitHub) para gestionar las
prácticas de *Informática Básica*.
En esa plataforma, para la realización de cada práctica recibirá una invitación a una tarea que tendrá que
aceptar.
Una vez acepte la invitación tendrá que clonar con `git` un repositorio asociado a la tarea.
Ese repositorio privado será el punto de partida y tendrá Ud. que añadir en él directorios con los programas
que realice.

El enlace de invitación a la tarea que se le comunicará tiene una apariencia similar a
`https://classroom.github.com/a/uNbth9vD`
Si lo introduce en un navegador, se le solicitará que se autentifique en su cuenta de GitHub,
y una vez autentificada/o le llevará a una pantalla
[como esta](https://raw.githubusercontent.com/IB-2022-2023/P06-alternatives-iterations/main/join-the-classroom-22-23.png?token=GHSAT0AAAAAAB2KIDMDGVFSGV5ZPKCEIPJQY2WOHQQ)
en la que se le solicitará que se una a la "*classroom*" IB-2022-2023.
Para ello ha de seleccionar su nombre de la lista de identificadores (*Identifiers*) que figura en esa página.
A continuación se le solicitará que "Acepte la tarea Practica-Nombre"
Habrá una tarea asociada con cada una de las prácticas de la asignatura.

Cuando lo haya hecho aparecerá una pantalla 
[como esta](https://raw.githubusercontent.com/IB-2022-2023/P06-alternatives-iterations/main/accepted.png?token=GHSAT0AAAAAAB2KIDMCQ75PHT2TCKF2HUPSY2WOOPQ)
que indica que ha aceptado Ud. la tarea asignada y
cuando refresque la pantalla le mostrará 
[otra pantalla](https://raw.githubusercontent.com/IB-2022-2023/P06-alternatives-iterations/main/ready.png?token=GHSAT0AAAAAAB2KIDMDZNDJL6P5KDO3N4OEY2WOPIA)
en la que figura el enlace al repositorio que ha sido creado
para su trabajo en la práctica.

A través de ese enlace accederá Ud. en GitHub al repositorio privado que se ha creado para que desarrolle en
él los programas correspondientes a la práctica en cuestión.
[El enlace que figura en ese repositorio](https://raw.githubusercontent.com/IB-2022-2023/P06-alternatives-iterations/main/link.png?token=GHSAT0AAAAAAB2KIDMCQ4Z4HTEU2RJWWXDCY2WOQCA)
(elija la opción SSH para el enlace) es el que ha de entregar Ud. en la tarea del aula virtual correspondiente a la práctica.

Recuerde que para cada práctica tiene que entregar 2 elementos: 
* Este enlace a su repositorio. Ese enlace lo puede ya escribir en la tarea correspondiente del aula virtual: 
no es necesario que espere a la sesión de evaluación para subirlo.
* Un fichero `.tar.gz` conteniendo todos los programas que desarrolle tanto antes como durante la sesión de evaluación.
Sí ha de esperar a la sesión de evaluación para subir el fichero .tar.gz conteniendo sus programas.

Ese mismo enlace es el que ha de utilizar para realizar una copia local (clone) del repositorio en su máquina
virtual y comenzar a trabajar en los ejercicios de la práctica:

```
git clone https://github.com/IB-2022-2023/P06-alternatives-iterations <DirectorioLocal>
```

### La utilidad `make`
Hasta ahora en la asignatura se han compilado los programas que se desarrollan de forma manual, invocando al
compilador con un comando como
```
$ g++ -std=c++17 -Wall -o hello_world hello_world.cc
```
Tal como se ha explicado en las clases de teoría, por lo general, la compilación manual de programas es bastante tediosa, 
especialmente cuando el programa consta de varios ficheros con código fuente y es necesario especificar opciones 
adicionales del compilador.
En la práctica, lo más común es usar herramientas para automatizar el proceso de compilación, y `make` es una
de las herramientas mas usadas para tal propósito.

[make](https://en.wikipedia.org/wiki/Make_(software)) 
es una herramienta que permite automatizar el proceso de desarrollo de software.
La función de `make` es determinar automáticamente qué ficheros de un programa necesitan ser recompilados, 
y ejecutar los comandos necesarios para realizar esa tarea.

Comience su estudio de `make` estudiando 
[este tutorial](https://makefiletutorial.com/) 
y reproduciendo en su máquina virtual y entendiendo cada uno de los ejemplos.
Estudie solamente hasta el apartado *Static Pattern Rules* del tutorial.
En 
[este
directorio](https://github.com/IB-2022-2023/IB-class-code-examples/tree/master/IntroductionToC%2B%2B/make_tutorial2)
del repositorio de programas que acompañan a las transparencias de clase puede encontrar los ejercicios de ese
tutorial.

Prosiga su estudio a continuación con las transparencias de clase 
[Make
utility](https://docs.google.com/presentation/d/1lYXrFHkka5VPkVukszQZq3VS9LNS5TOrA5m8fgkoQJQ/edit?usp=sharing).

Estudie por último el tutorial 
[A Simple Makefile Tutorial](https://cs.colby.edu/maxwell/courses/tutorials/maketutor/).
En ese tutorial se utiliza el compilador `gcc`, pero puede Ud. sustituirlo por `g++` puesto que el compilador
de C++ compila igualmente el código en C (como se ha explicado, C++ es un superconjunto de C).
En 
[este
directorio](https://github.com/IB-2022-2023/IB-class-code-examples/tree/master/IntroductionToC%2B%2B/make_tutorial)
del repositorio de programas que acompañan a las transparencias de clase puede encontrar los ejercicios de ese
tutorial, adaptados al compilador `g++`.

En ese tutorial, el programa que se compila está compuesto de tres ficheros:
* *hellomake.cc*, el programa principal,
* *hellofunc.cc*, un fichero en el que figura el código de la función *myPrintHelloMake()*
* *hellomake.h*, el fichero en el que figura la definición de la función
Esta es la situación habitual en la que una aplicación desarrollada en C++ consta no de tres sino, en general,
de decenas de ficheros que hay que compilar.

Una compilación manual de ese programa se realizaría con los comandos:
```
g++ -std=c++17 -Wall -c hellomake.cc
g++ -std=c++17 -Wall -c hellofunc.cc
g++ -o hellomake hellomake.o hellofunc.o
```
de los cuales, los dos primeros compilan el correspondiente código fuente generando solamente el código objeto
(ficheros `*.o`) y el tercero invoca al enlazador (*linker*) para construir el fichero binario ejecutable
*hellomake* a partir de los ficheros objetos generados por los dos primeros comandos.

Estudie cuidadosamente las explicaciones de ese tutorial.
En el
[directorio](https://github.com/IB-2022-2023/IB-class-code-examples/tree/master/IntroductionToC%2B%2B/make_tutorial)
puede hallar las 5 versiones del fichero `Makefile` que se estudian en ese tutorial.
Para utilizar (por ejemplo) el fichero Makefile.2 ejecute el comando
```
make -f Makefile.2
```
Recuerde que para que `make` utilice el fichero por defecto, éste ha de llamarse `Makefile`, en cuyo caso
basta con ejecutar
```
make 
```

Para finalizar, en el directorio `make-example` que ha recibido Ud. con esta práctica puede estudiar un fichero
[Makefile](https://github.com/IB-2022-2023/P06-alternatives-iterations/blob/main/make-example/Makefile)
que se utiliza para compilar el programa `dni.cc`
Ese fichero `Makefile` contiene comentarios indicando la finalidad de cada una de las líneas que figuran en el
mismo.
Debería Ud. estudiar cada una de esas líneas y comprender su finalidad y formato.
Se comentan a continuación algunos de los aspectos más destacados.

Tenga en cuenta en primer lugar (como habrá estudiado en los tutoriales) que el formato del fichero `Makefile` requiere que en algunos puntos del mismo
haya un caracter tabulador (*tab*, `\t`) y no acepta espacios en su lugar.
Así, el primer carácter en las líneas 19 o 29 del fichero ha de ser forzosamente un tabulador (no espacios).

La línea 16 es la que especifica el nombre del fichero ejecutable que ha de construir `make`, y que en este
caso es *dni*. 
Se indica en la línea 18 que el fichero *dni* depende de su código objeto *dni.o*.
La línea 19 indica cómo "construir" el fichero *dni* a partir de *dni.o*: se invocaría el compilador con una
línea como:
```
g++ -std=c++17 -Wall -o dni dni.o
```
(Observe que esa, efectivamente es el segundo comando que se ejecuta cuando se invoca a `make`).
Es decir, se invoca al enlazador (*linker*) para que produzca el código binario (*dni*) a partir del código
objeto (*dni.o*).


La línea 29 indica cómo construir los ficheros objeto (*.o*) a partir de su correspondientes ficheros fuente
(*.cc*). 
En este ejemplo, esa línea será la primera que se ejecute produciendo:
```
g++ -std=c++17 -Wall -c -o dni.o dni.cc
```
Que invoca al compilador con la opción `-c` (solo compilar, sin enlazar) para producir el código objeto
(*dni.o*) a partir del fichero fuente (*dni.cc*).
Observe que ese comando es el primero que se ejecuta al invocar a `make`.

La línea 27 (comentada) indicaría que el fichero *dni.o* depende de *dni.cc* pero tal como indica el
comentario, esa regla no necesita especificarse explícitamente porque `make` la contempla por defecto.

Por último, indicar que los comandos que figuran después de la línea `34` se ejecutan al invocar:
```
make clean
```
Se puede utilizar *clean* o cualquier otra etiqueta, pero se ha convertido en una costumbre utilizar la
etiqueta *clean*.
La finalidad de estos comandos (que puede Ud. configurar a su gusto) es borrar todos aquellos ficheros que,
siendo producto de la compilación/edición del proyecto, no se desea retener.
Así por ejemplo los ficheros `*.o` con código objeto o el fichero ejecutable (`dni` en este caso) no conviene
conservarlos puesto que ocupan espacio y no son necesarios, puesto que se pueden obtener a partir del codigo
fuente.

### Material de estudio complementario
Estudie del [tutorial de referencia](https://www.learncpp.com/) en la asignatura los siguientes apartados:
* 2.1 [Introduction to functions](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)
* Del capítulo 7 los apartados 7.1 al 7.11

### Ejercicios
* Escriba programas que solucionen los siguientes problemas y evalúe su solución utilizando Jutge.
* Al realizar los ejercicios cree dentro de su repositorio de esta práctica un directorio diferente
para cada uno de los ejercicios.
Asigne a cada uno de esos directorios nombres significativos. Por ejemplo `P34279_add-one-second` para el
tercer ejercicio.
* Automatice la compilación del programa correspondiente a cada ejercicio con un fichero `Makefile`
independiente para cada programa y que ha de incluir en el correspondiente directorio.

1. [P98960](https://jutge.org/problems/P98960_en) Uppercase and lowercase letters
2. [P90615](https://jutge.org/problems/P90615_en) Maximum of three integer numbers
3. [P34279](https://jutge.org/problems/P34279_en) Add one second
4. [P97156](https://jutge.org/problems/P97156_en) Numbers in an interval
5. [P59539](https://jutge.org/problems/P59539_en) Harmonic numbers (1)

Tenga en cuenta que en la evaluación de las prácticas de *Informática Básica* se utlizarán ejercicios de
Jutge, de modo que resolver problemas en esa plataforma mejorará sus capacidades como programadora.
Realice todos los ejercicios del curso 
[Informática Básica](https://jutge.org/courses/FranciscoDeSande:IB_ULL)
de Jutge que sea capaz.
Resuelva los problemas atendiendo al orden que figura en ese curso, puesto que están seleccionados con
complejidad creciente.
No se preocupe demasiado si no consigue solucionar alguno de los problemas concretos: es preferible que centre
sus esfuerzos en realizar muchos programas que en solucionar algunoconcreto.

Recuerde siempre que Jutge solo evalúa la corrección de su programa desde un punto de vista de su correcto funcionamiento.
Su código ha de cumplir adicionalmente con los requisitos de modularidad, formato y estilo.
