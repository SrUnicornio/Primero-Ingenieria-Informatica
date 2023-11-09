# Práctica 04. Primeros programas

# Factor de ponderación: 5

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Conozca algunos detalles del proceso de compilación en C++
* Escriba sus primeros programas simples en C++
* Conozca algunos tipos de datos simples, así como la forma de declarar variables de esos tipos y operar con
  esas variables
* Sepa cómo crear un fichero de configuración para vim en su máquina virtual
* Entienda la finalidad de los comentarios en sus programas, y en particular los comentarios de cabecera de
  los ficheros
* Cree una cuenta en la plataforma Jutge y conozca el funcionamiento básico de la misma

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva) que se tendrán en cuenta a la hora de evaluar esta práctica:
* Ha de demostrar que conoce el proceso de compilación de programas usando el compilador de C++ de GNU
* Ha de demostrar su capacidad para establecer un fichero de configuración de vim para sus tareas de edición
  en la asignatura
* Ha de acreditar que dispone de una cuenta de usuario en la plataforma Jutge y que conoce los fundamentos de
  trabajo en esa plataforma
* Se comprobará que todos los ficheros (`*.cc`, `*.h`) de sus prácticas incluyen un comentario de cabecera
* Ha de acreditar que es capaz de editar ficheros remotos en su VM usando vi
* Ha de demostrar que es capaz de ejecutar comandos Linux en su VM
* Ha de acreditarse que se es capaz de conectarse a su máquina virtual (VM) de la asignatura 

### Repositorio GitHub correspondiente a esta práctica
Para cada una de las prácticas de *Informática Básica* el profesorado de la asignatura creará un repositorio
público en GitHub que contendrá, además del enunciado de la práctica que se propone realizar, algunos ficheros
que pudieran ser necesarios para el trabajo propuesto.

El repositorio correspondiente a esta práctica está accesible a través de
[este enlace](https://github.com/IB-2022-2023/P04-first-programs)
de modo que la primera tarea a desarrollar es clonar (copiar) ese repositorio en un directorio adecuado de su
máquina virtual de la asignatura.
La dirección que ha de usar para clonar el directorio la puede hallar en la pestaña *Code* de la página
anterior, seleccionando la opción *SSH* en el desplegable que se abre en esa opción.
Así pues, el comando para clonar el repositorio de esta práctica es
``` 
git clone git@github.com:IB-2022-2023/P04-first-programs.git <directorio en mi máquina virtual>
```
Comience su trabajo en esta práctica clonando el repositorio anterior.

En el futuro se utilizará GitHub Classroom (una plataforma relacionada con GitHub) para gestionar las
prácticas de *Informática Básica*.
En esa plataforma, para la realización de cada práctica recibirá una invitación a una tarea que tendrá que
aceptar.
Una vez acepte la invitación tendrá que clonar un repositorio asociado a la tarea.
Ese repositorio privado será el punto de partida y tendrá Ud. que añadir en él directorios con los programas
que realice.

### El fichero `.vimrc`
En vim se pueden modificar muchos parámetros del editor mientras se editan los ficheros. 
Por ejemplo, tecleando en modo comando `:set number` vim activará la numeración de líneas, algo que puede ser útil para programar.
Tecleando `:syntax on`, se activa para el fichero actual el coloreado de sintaxis, es decir, que las palabras especiales que el editor 
entienda que tienen un significado concreto aparecerán en diferentes colores. 
Si se está programando en C++, por ejemplo, las palabras reservadas de ese lenguaje (ya aprenderá lo que son) aparecerán de un color, 
las cadenas de otro, etc (algo realmente útil a la hora de programar).

Cualquier tipo de opción, macro, comando o función que vim entienda puede ser incluída en el fichero `.vimrc` 
en el directorio `$HOME` del usuario de modo que se aplique como opción por defecto cuando se lance Vim. 
Pruebe a crear un fichero `.vimrc` (por defecto normalmente no existirá) en el directorio HOME de su máquina
virtual, que contenga lo siguiente:
``` .bash
set nocompatible
set number
set ruler
syntax on
```

Esto hará que siempre que edite un fichero, aparezca numeración de líneas (`set number`), 
un indicador de fila y columna en la barra de estado (`set ruler`) y resaltado de sintaxis 
(si está definida para el tipo de fichero que esté editando) activado. 
Es algo así como el fichero de opciones de vim para nuestro usuario.

Así, se puede utilizar este fichero de configuración de vim para indicar aquellas configuraciones con las que estemos más cómodos, 
de forma que se adapte vim a nuestras necesidades. 
Para comenzar se recomienda un fichero `.vimrc` con el siguiente contenido:
``` 
" Fichero .vimrc de mi usuario
" Los comentarios en este fichero se ponen con comillas dobles

" Esta opción debe estar la primera porque cambia otras opciones
" nocompatible permite funciones que VI no soporta
set nocompatible

set number

" Muestra la posición del cursor en todo momento
set ruler

" Al presionar tab, inserta 2 espacios (Guía de estilo de Google)
set expandtab

" Muestra los tabs existente con 2 espacios
set tabstop=2

" shiftwidth (el número de espacios a usar cuando se indenta)
set sw=2

syntax on

" Volver a la última posición al abrir un fichero
" https://stackoverflow.com/questions/7894330/preserve-last-editing-position-in-vim
autocmd BufReadPost *
     \ if line("'\"") > 0 && line("'\"") <= line("$") |
     \   exe "normal! g`\"" |
     \ endif
```
Es fácil hallar en internet ejemplos de ficheros `.vimrc` escritos por usuarios expertos.
[Este](https://gist.github.com/simonista/8703722)
por ejemplo podría ser uno de esos ficheros.
Puede Ud. tomar del mismo (o de otros) aquellas opciones que le parezcan interesantes pero la recomendación es
que comience con uno simple, como el que se ha propuesto, y que no introduzca en él una opción salvo que
entienda bien la finalidad de la misma.

### Comentarios de cabecera
Estudie en la
*[Guía de Estilo de Google para C++](https://google.github.io/styleguide/cppguide.html)*
el apartado dedicado a los comentarios
([Comments](https://google.github.io/styleguide/cppguide.html#Comments)).

Tal como en esa guía se indica, una buena práctica consiste en incluir un bloque de comentarios al comienzo
de todos los ficheros de un proyecto de programación.
El siguiente es un ejemplo de comentario de bloque que debería incluirse al comienzo de todos los ficheros
(`*.cc`, `*.h`) de sus proyectos de programación en el ámbito de esta asignatura:

```
/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @file integer_division_and_reminder.cc
  * @author Albert Einstein aeinstein@ull.edu.es
  * @date Oct 12 2022
  * @brief The program reads two natural numbers a and b, with b > 0, and prints 
  *        the integer division d and the remainder r of a divided by b.
  *        By definition, d and r must be the only integer numbers such that 0=<r<b and db+r=a.
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */
```

Todo fichero debiera contener (etiqueta `@brief`) una breve descripción del contenido del fichero.
Si fuera necesario se incluirá a continuación una descripción más detallada.
Obviamente el comentario específico así como el nombre del fichero debieran particularizarse para cada caso
concreto.

Incluya siempre un bloque de comentarios similar al anterior en todos sus ficheros.
Preste cuidado a la práctica habitual de "copiar y pegar" estos comentarios de un proyecto a otro, puesto que parte de la
información cambiará.

En proyectos de desarrollo de software de cierta entidad es común que este bloque de comentarios de cabecera de los ficheros
incluya además la licencia de software bajo la que se publica el programa en cuestión.
A título de ejemplo, 
[consulte el texto](https://www.gnu.org/licenses/gpl-3.0.html)
que se debiera incluir en los ficheros para publicarlos bajo licencia GPLv3.

### Primeros programas
Además de estudiar todo el material expuesto en clases de teoría hasta la actualidad, estudie detenidamente
los contenidos del tema
[Primeros Programas](http://www.minidosis.org/#/temas/Cpp.PrimerosProgramas)
del tutorial MiniDosis.
En ese tema hallará vídeos y textos explicativos, ejercicios en los que tendrá que copiar programas,
escribirlos usando vim, compilarlos y ejecutarlos. También hallará ejercicios para evaluar los conocimientos
adquiridos.

Tenga en cuenta que en ese tutorial se utiliza CodeBlocks mientras que en *Informática Básica* se utiliza vim
para escribir programas.

Cree un subdirectorio con nombre `primeros_programas` en el directorio de trabajo de esta práctica y escriba en el
mismo todos los programas que se le propone en el tema.
En el tutorial para los ficheros con código C++ se utiliza la extensión `.cpp`, mientras que en *Informática
Básica*, siguiendo la 
[Guía de Estilo de Google para C++](https://google.github.io/styleguide/cppguide.html#File_Names)
se utilizará la extensión `.cc`

Tome nota de todas las dudas que le surjan al estudiar este material, para estudiarlas con el profesorado en
las sesiones de Problemas de *Informática Básica*.

### La plataforma Jutge
[Jutge](https://jutge.org/) 
es una plataforma que ha sido desarrollada en la
[UPC](https://www.upc.edu/en) 
para uso docente en asignaturas de programación.
La plataforma ofrece una gran cantidad de problemas que los estudiantes han de resolver y el Jutge (juez en catalán) asigna un 
[veredicto](https://jutge.org/documentation/verdicts) 
a cada solución que se suba a la plataforma.

Jutge solo evalúa los programas desde el punto de vista de la corrección del resultado que ofrecen, 
no evalúa la calidad del código en cuanto a otros aspectos: diseño, estilo, formato, etc.
Para determinar si un programa es correcto o no, Jutge aplica varios tests al programa (tests unitarios)
que tratan de acreditar la bondad de la solución, que podría ser parcialmente correcta.
Algunos de esos tests son públicos y la programadora debiera encargarse de asegurar que su programa pasa
esos tests públicos (ofrece los resultados esperados) antes de enviar el programa al juez.

Para la realización de futuras prácticas de la asignatura deberá Ud. registrarse en la plataform Jutge. 
Recibirá para ello un mensaje de correo con asunto similar a: "Jutge.org - You have been invited to a course". 
Acepte esa invitación y regístrese en el curso *Informática Básica* en la plataforma Jutge usando para ello su
cuenta de correo electrónico institucional.
Es importante que se registre en Jutge con esa cuenta y no otra.

[Este documento](https://docs.google.com/presentation/d/1k53XMnI6Z9DTlBHRJ0cBqix0KZyVIFUgD61XAcsgA9Y/edit?usp=sharing)
contiene información algo más detallada sobre el uso de la plataforma Jutge. 
Estúdielo para preparse a usar Jutge en el futuro.

Compile el programa `squares.cc` que hallará en el subdiretorio `jutge` de esta práctica.
Ejecute el programa resultante de la compilación introduciendo los datos de entrada a través del teclado.
Aprenda a conseguir que el programa tome la entrada de datos desde un fichero de texto, de modo que pueda
ejecutar el programa como:
``` 
$ ./squares < fichero_entrada.txt
``` 
Consiga igualmente que su programa tome la entrada desde un fichero y escriba la salida en otro:
``` 
$ ./squares < entrada.txt > salida.txt
``` 

El programa `hello_world.cc` que hallará en el subdirectorio `jutge` de la práctica soluciona el problema
[P68688](https://jutge.org/problems/P68688_en) de Jutge.
Modifique convenientemente el programa para que escriba la solución que Jutge espera y
[suba su solución](https://jutge.org/problems/P68688_en/submissions)
a la plataforma para su evaluación.

### Comandos Linux útiles a la hora de procesar ficheros de texto
Por último, aprenda a utilizar el comando
[diff](https://ss64.com/bash/diff.html).
Los ejemplos y explicaciones de 
[este tutorial](https://www.computerhope.com/unix/udiff.htm) 
pueden resultarle útiles para conocer `diff`.
