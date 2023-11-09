# Práctica 07. Iteraciones

# Factor de ponderación: 7

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Sea capaz de resolver problemas sencillos en C++ usando todos los conocimientos adquiridos hasta ahora, 
y en particular haciendo uso de sentencias iterativas
* Comience a utilizar funciones en sus programas y modularice sus programas en diferentes funciones
* Conozca los fundamentos de la documentación de código
* Conozca la herramienta Doxygen, las etiquetas definidas en JSDoc y sepa cómo utilizarlas para documentar su
código

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva) que se tendrán en cuenta a la hora de evaluar esta práctica.
Se comprobará que el alumnado:
* Es capaz de escribir programas simples en C++ que resuelvan problemas de
  complejidad similar a los que se han propuesto para esta práctica
* Hace que sus programas se estructuren en torno a diferentes funciones (sean modulares)
* Utiliza en todos sus programas comentarios adecuados en el formato requerido por
[Doxygen](https://www.doxygen.nl/index.html)
* Ha automatizado la compilación de sus programas usando un fichero `Makefile`
  para cada uno de los programas que desarrolle 
* Acredita que todas las prácticas realizadas hasta la fecha se encuentran alojadas en repositorios
  privados de [GitHub](https://github.com/).
* Acredita que es capaz de subir programas a la plataforma 
[Jutge](https://jutge.org/)
para su evaluación
* Ha incluido un comentario prólogo en todos los ficheros (`*.cc`, `*.h`) de sus ejercicios
* Hace que todos los programas de sus prácticas se ajusten a la
[Guía de estilo de Google para C++](https://google.github.io/styleguide/cppguide.html) 
* Acredita que es capaz de editar ficheros remotos en su VM usando vi
* Demuestra que es capaz de ejecutar comandos Linux en su VM

### Documentación de código 
La documentación de una aplicación es cualquier texto que describa el programa a los usuarios del mismo.
El usuario puede ser desde un programador hasta un usuario final del programa.
Hay diferentes tipos de documentación: especificación de requisitos, manual de usuario, documento de diseño,
documentación técnica, ...
En esta asignatura nos centraremos en la documentación del código, que es parte de la documentación técnica.

Hay diversos motivos por los que escribir documentación es importante:
* La documentación posibilita el seguimiento de todas las partes de un programa
* Facilita el mantenimiento de la aplicación. Durante el ciclo de vida de una aplicación es muy frecuente que
  haya que introducir cambios en la misma.
* Posibilita que programadores que no sean el desarrollador puedan entender todos los aspectos del programa
* Mejora la calidad general del software
* Ayuda a la formación de otros programadores
* En una organización, garantiza la descentralización del conocimiento, reduciendo los costes y el esfuerzo si los desarrolladores abandonan el proyecto de forma imprevista 

Todos los programas deben estar comentados de modo que describan fácilmente la finalidad del código y cualquier 
algoritmo utilizado para lograr el propósito. 
Un usuario debería ser capaz de utilizar un programa (o función) previamente escrito sin tener que estudiar 
en detalle el código, simplemente leyendo los comentarios.

Los comentarios son el "arte" de describir en lenguaje natural (inglés, español, etc.) lo que el programa
hace.
Lo mejor es comentar **antes** de escribir el código del programa.

Los comentarios son líneas de texto especialmente marcadas en el programa que no se evalúan. 
Tal como se ha estudiado, los comentarios en C++ son eliminados por el preprocesador: el programa que el compilador
evalúa (compila) carece de comentarios. Dicho de otro modo: los comentarios se escriben para ser leídos por
personas, no para el compilador.
Tal como se ha estudiado, hay dos formas sintácticas de comentar. 
La primera se llama comentario de una sola línea y sólo se aplica a una única línea en el código fuente. 
La segunda se denomina comentario de bloque y suele referirse a un párrafo de texto (como los comentarios
"prólogo" que se colocan al principio de cualquier fichero con código fuente).
Un comentario de bloque tiene un símbolo de inicio y un símbolo de fin y todo lo que hay entre ellos es ignorado por compilador.

#### Dónde comentar
Los comentarios deben aparecer en los siguientes puntos de un programa:
* Al comienzo de cualquier fichero de código.
A estos se les llama "Comentarios de cabecera". 
Debe incluir toda la información definitoria sobre quién escribió el código, por qué, cuándo, y qué debe hacer el programa. 
* Previo a cada función del programa.
Se denomina cabecera de la función y proporciona información sobre el propósito de la función en cuestión.
Si sólo hay una función en un fichero, los comentarios de la cabecera de la función y de la cabecera del fichero
deben fusionarse en un único comentario. 
* Comentarios de línea.
Cualquier código "complicado" en el que no sea inmediatamente obvio lo que está tratando de lograr, debería tener 
comentarios justo encima o en la misma línea que él.

#### Cómo no comentar
Los comentarios deben ser descripciones útiles de lo que hace el programa. 
No deben repetir algo que es "obvio" leyendo el código. 
Utilizando identificadores adecuados, la mayor parte de un programa no precisa comentarios adicionales.
Particularmente se minimiza en este caso la necesidad de comentarios "de línea".

### Doxygen
[Doxygen](https://en.wikipedia.org/wiki/Doxygen) 
es una herramienta de código abierto que permite generar documentación de referencia para proyectos de desarrollo software. 
Una ventaja de Doxygen es que la documentación está escrita en el propio código fuente de los programas, y por lo tanto es relativamente fácil de mantener actualizada. 
Doxygen puede hacer referencias cruzadas entre la documentación y el código, de modo que el lector de un documento puede referirse fácilmente al código fuente.
La herramienta extrae la documentación de los comentarios presentes en los ficheros de código fuente y puede generar la salida en diferentes formatos entre los cuales están HTML, PDF, LaTeX o páginas `man` de Unix.

En *Informática Básica* no se propone un uso exhaustivo de Doxygen pero **sí se requiere que la
documentación de los programas desarrollados se realice en el formato reconocido por Doxygen**, que se ha
convertido en un estándar de facto.

Comience por instalar Doxygen en su máquina virtual de la asignatura:
```
$ sudo apt install doxygen
```
Instale también los siguientes paquetes:
```
$ sudo apt install texlive-latex-base
$ sudo apt install texlive-latex-recommended
$ sudo apt install texlive-latex-extra
```
Estos paquetes son necesarios para compilar ficheros en formato [LaTeX](https://es.wikipedia.org/wiki/LaTeX).
Más adelante en este documento se justifica la necesidad de los programas que suministran estos paquetes.

En el [manual de Doxygen](https://www.doxygen.nl/manual/starting.html) se indica cómo comenzar a trabajar con la herramienta.
Si, ubicados en un directorio de trabajo, se invoca:
```
doxygen -g <config-file>
```
la herramienta creará un fichero de configuración.
Si no se le pasa el nombre del fichero (*config-file*) como parámetro, creará un fichero con nombre `Doxyfile` preconfigurado para su uso.
En el directorio de trabajo de esta práctica (`src`) se encuentra un fichero `Doxyfile` ya listo para usarse con proyectos de C++.
Se ha incluído asimismo en ese directorio el código fuente de un programa para ilustrar con el mismo el uso de documentación con Doxygen.
Si revisa el fichero `Doxyfile` (es un fichero de texto) verá un conjunto de opciones que el programa permite.
Cada opción va precedida de una explicación de su finalidad y funcionamiento, de modo que puede probar a modificar algunas de ellas si lo desea.
En [esta página](https://www.doxygen.nl/manual/config.html) puede consultarse la finalidad y funcionamiento de cada una de las etiquetas (tags) que se usan en el fichero de configuración de Doxygen.

Para generar la documentación de su aplicación, colóquese en el directorio de su proyecto (`src` en esta práctica) y ejecute:
```
doxygen Doxyfile
```
Con el fichero `Doxyfile` que se suministra, la herramienta creará un subdirectorio `doc` en el directorio 
raíz de su proyecto en el que alojará toda la documentación generada.
El directorio donde Doxygen genera su salida se especifica con la etiqueta `OUTPUT_DIRECTORY` 
(línea `61` del fichero `Doxyfile` suministrado).
Con la configuración suministrada se generan 2 subdirectorios dentro de `doc`: `html` y `latex`.
Si se coloca en el directorio `doc/latex/` y ejecuta `make` el sistema "compila" el código LaTeX y 
genera un fichero `refman.pdf` que contiene la documentación generada.
Observe en este caso el uso de `make` con un fichero `Makefile` no para compilar un programa sino para generar
un fichero `pdf` a partir del código (texto) LaTeX.
Si trabaja en su máquina virtual, traiga el fichero `refman.pdf` hacia su máquina local y visualice su
contenido.

Si abre con un navegador el fichero `doc/html/index.html` accederá a la página principal de la documentación generada para el programa.
En su máquina virtual no va a poder abrir un navegador para explorar los ficheros del directorio `doc/html`.
Lo que ha de hacer es o bien generarlos en su instalación Linux local o bien traer el contenido del directorio `doc` desde
su máquina virtual IaaS hacia su máquina local y en la máquina local abrir con un navegador el fichero `doc/html/index.html`.

Tal como se ha indicado, HTML o LaTeX son solo 2 de los formatos que permite generar Doxygen.
Tanto HTML como LaTeX (también 
[Markdown](https://es.wikipedia.org/wiki/Markdown)) 
son lo que se conoce como 
[lenguajes de marcas](https://es.wikipedia.org/wiki/Lenguaje_de_marcado).
HTML es el lenguaje que se utiliza para componer los textos que se muestran en las páginas web.
[Latex](https://en.wikipedia.org/wiki/LaTeX) 
es un sistema de composición de textos que cuida el formato en especial en el ámbito de la tipografía y que es especialmente adecuado para textos de carácter científico.
No se pretende aquí que profundice en conocer HTML o LaTeX.

La sección [Documenting the code](https://www.doxygen.nl/manual/config.html) del manual de Doxygen indica cómo comentar el código fuente de modo que los comentarios sean procesados por Doxygen para incorporarlos a la documentación generada.

La guía [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html) de documentación de código del proyecto LLST es la referencia que se adoptará en la asignatura para documentar el código de los programas que se desarrollen.
Se utilizarán comentarios de tipo JavaDoc para comentarios de bloque:
```
/**
 * ... text comment ...
 */
```
[JavaDoc](https://en.wikipedia.org/wiki/Javadoc) es otro sistema de documentación ideado para Java y que también es muy popular. 
Doxygen soporta el uso de etiquetas "al estilo Javadoc" en el código.

Los bloques de comentarios multi-línea deben comenzar con 
```
/** 
```
y finalizar con
```
*/
```
Los comentarios de una única línea deben comenzar con `///`.
Por consistencia no use las opciones 

```
/*!
```
o
```
//!
```
permitidas en Doxygen.

Así el 
[bloque de comentarios](https://jsdoc.app/tags-description.html)
que debe preceder a cualquier función (o método) debiera tener una apariencia similar a esta:
```
/**
 * Sum numbers in a vector
 *
 * @param values Container whose values are summed
 * @return sum of `values`, or 0.0 if `values` is empty
 */
double SumValues(const std::vector<double>& values) {
  ...
}
```
En el ejemplo anterior `@param` y `@return` son etiquetas de tipo Javadoc.
En 
[Overview of supported JavaDoc style tags](http://www.time2help.com/doc/online_help/idh_java_doc_tag_support.htm) 
pueden consultarse este tipo de etiquetas.

El siguiente es un ejemplo (plantilla) de comentario de bloque que debería incluirse al comienzo de todos los ficheros (`*.cc`, `*.h`) de un proyecto de programación en el ámbito de esta asignatura:
``` .cpp
/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Albert Einstein aeinstein@ull.edu.es
  * @date Oct 12 2022
  * @brief El programa calcula la suma de todos los términos de valor par de la serie
  *        de Fibonacci que sean menores que un valor dado.
  *        Cada nuevo término de la serie se genera sumando los dos anteriores.
  *        Comenzando con 0 y 1, los primeros 10 términos serán: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */
```
Todo fichero debiera contener (etiqueta `@brief`) una breve descripción del contenido del fichero.
Si fuera necesario se incluirá a continuación una descripción más detallada.
Obviamente el comentario específico debiera particularizarse para cada caso concreto.

### Material de estudio complementario
Estudie todo lo que se indica en el epígrafe 
[Comments](https://google.github.io/styleguide/cppguide.html#Comments) 
de la Guía de Estilo de Google y ponga en práctica todo lo que en ella se propone, usando el formato Doxygen y
etiquetas JSDoc para todos los comentarios de su código fuente.

Estudie del
[tutorial de referencia](https://www.learncpp.com/)
en la asignatura los siguientes apartados:
* [Comments](https://www.learncpp.com/cpp-tutorial/comments/)
* El capítulo 2
[Basics: Functions and Files](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)
(completo)
* [Command line arguments](https://www.learncpp.com/cpp-tutorial/command-line-arguments/)

### Diseño de los programas
Recuerde las que se han estudiado como *Buenas Prácticas* a la hora de diseñar sus funciones:
* El código deberá organizarse en diferentes funciones 
* Cada función deberá realizar una única tarea y hacerlo correctamente 
* El identificador de una función debe reflejar claramente lo que la función hace 

Tal como se indica en 
[How to design your first programs](https://www.learncpp.com/cpp-tutorial/how-to-design-your-first-programs/)
su código debiera estar organizado en torno a funciones que se invocan desde la función *main()*.
Así la apariencia habitual de la función principal de cualquier programa debiera ser algo similar a:
``` .cpp
int main(int argc, char* argv[]) {
  PrintProgramPurpose();
  if (!CheckCorrectParameters(argc, argv, 3)) {
    return 1;
  }
  GetUserInput();
  GetMathematicalOperation();
  GetUserInput();
  CalculateResult();
  PrintResult();

  return 0;
}
```
en el sentido de que la función *main()* es una mera *orquestadora* de las funciones que componen el programa.
*main()* pasa a esas funciones los parámetros necesarios para su funcionamiento y las diferentes funciones
devuelven a *main()* el valor que calculan (si fuera el caso).

Incluya en todos sus programas sendas funciones cuya declaración sería:
```
void PrintProgramPurpose();
bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber);
```
La primera de ella se invocará al comienzo de la ejecución para imprimir un mensaje explicativo de
la finalidad del programa en cuestión.
La función *CheckCorrectParameters()* devolverá `true` si al programa se le han pasado el número adecuado de
parámetros por línea de comandos (3 en el ejemplo anterior) y `false` en caso contrario.
Estude el programa 
[check-correct-parameters.cc](https://github.com/IB-2022-2023/IB-class-code-examples/blob/master/Functions/check-correct-parameters.cc)
de los ejemplos de código de las clases de teoría que ilustra el uso de estas dos funciones.

### Ejercicios
* Al realizar los ejercicios cree dentro de su repositorio de esta práctica un directorio diferente
para cada uno de los ejercicios.
Asigne a cada uno de esos directorios nombres significativos. 
* Automatice la compilación del programa correspondiente a cada ejercicio con un fichero `Makefile`
independiente para cada programa e inclúyalo en el correspondiente directorio.

1. Escriba un programa que lea un número natural e imprima como salida la suma de los dígitos del número en cuestión. 
```
Public test cases
Input           Output
2022              6
1492             16
0                 0
```

2. Desarrolle un programa que imprima los N primeros términos de la 
[Serie de Fibonacci](https://en.wikipedia.org/wiki/Fibonacci_number). 
Los primeros términos de la serie son: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
```
Public test cases
Input           Output
5                 0 1 1 2 3
9                 0 1 1 2 3 5 8 13 21
1                 0
```

3. Estudie en el tutorial Learn C++ los epígrafes
[Numeral systems (decimal, binary, hexadecimal, and
octal)](https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/)
y
[Converting between binary and
decimal](https://www.learncpp.com/cpp-tutorial/converting-between-binary-and-decimal/).

Escriba un programa `binary-to-decimal.cc` que convierta números binarios en decimal.
No utilice los tipos `std::string`, `std::vector` o `std::array`.
Si la entrada no fuera un número binario, el programa debe imprimir en pantalla un mensaje de error y
finalizar la ejecución.
```
Public test cases
Input           Output
1111              15
1011110           94
1018110        Wrong Input
10010111         151
```

4. Escriba un programa `decimal-to-binary.cc` que convierta números de decimal a binario.
No utilice los tipos `std::string`, `std::vector` o `std::array`.
```
Public test cases
Input           Output
15              1111
94              1011110
151             10010111
```

5. Escriba un programa `leap-year.cc` que indique si un año es o no 
[bisiesto](https://en.wikipedia.org/wiki/Leap_year)
Un año bisiesto tiene 366 días. 
Después de la reforma gregoriana, los años bisiestos son aquellos múltiplos de cuatro que no terminan con dos ceros, 
y también los años que terminan con dos ceros tales que, después de eliminar estos dos ceros, son divisibles por cuatro. 
Así, 1800 y 1900, a pesar de ser múltiplos de cuatro, no fueron años bisiestos; por el contrario, 2000 fue un año bisiesto. 

```
Public test cases
Input        Output
1999           NO
1968          YES
2000          YES
1800           NO
```

Tenga en cuenta que en la evaluación de las prácticas de *Informática Básica* se utlizarán ejercicios de Jutge, 
de modo que resolver problemas en esa plataforma mejorará sus capacidades como programadora. 
Realice todos los ejercicios del curso Informática Básica de Jutge que sea capaz. 

Recuerde siempre que Jutge solo evalúa la corrección de su programa desde un punto de vista de su correcto funcionamiento. 
Su código ha de cumplir adicionalmente con los requisitos de modularidad, formato y estilo.
