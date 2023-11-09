# Práctica 11. Introducción a la Programación Orientada a Objetos. Depuración.

# Factor de ponderación: 10

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Desarrolle programas sencillos en C++ utilizando programación orientada a objetos, así como todas las características del lenguaje estudiadas anteriormente

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva) que se tendrán en cuenta a la hora de evaluar esta práctica.
Se comprobará que el alumnado:
* Conoce los conceptos expuestos en el material de referencia de esta práctica.
* Ha realizado todos los ejercicios propuestos en este enunciado
* Es capaz de escribir programas simples en C++ que resuelvan problemas de complejidad similar a los que se proponen en este documento
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

### Introducción a la depuración
Probar un programa con un conjunto bien elegido de pruebas de entrada da a la programadora la seguridad 
de que el programa es correcto. 
Durante el proceso de prueba, el programador observa las relaciones entrada-salida, es decir, la salida 
que produce el programa para cada caso de prueba de entrada. 
Si el programa produce la salida esperada y obedece la especificación para cada caso de prueba, entonces 
el programa se ha probado con éxito.

Pero si la salida de uno de los casos de prueba no es la esperada, entonces el programa es incorrecto: 
contiene errores (también conocidos como "*bugs*"). 
En tales situaciones, las pruebas sólo revelan la presencia de errores, pero no indican cuáles son ni cómo 
hay que corregir el código. 
En otras palabras, las pruebas revelan los efectos (o síntomas) de los errores, no su causa. 
La programadora debe entonces acometer un proceso de depuración, para identificar las causas y solucionar los errores.

Tal vez le resulte sorprendete saber que el proceso de depuración consume habitualmente más tiempo que la escritura del código. 
La mayor parte del tiempo de desarrollo de una aplicación se dedica a depurar y mantener el código, más que a escribirlo.

Es por ello que lo mejor es evitar el fallo al escribir el programa. 
Es importante sentarse y pensar antes de codificar: decidir exactamente qué se necesita conseguir, cómo se planea conseguirlo, 
diseñar el algoritmo de alto nivel de forma limpia, convencerse de que es correcto y decidir cuáles son las estructuras de datos 
concretas que se planea utilizar. 
Todo el esfuerzo invertido en diseñar y pensar el código antes de escribirlo valdrá la pena más adelante. 
Las ventajas son dobles. 
Primero, tener un diseño limpio reducirá la probabilidad de defectos del programa. 
En segundo lugar, incluso si un error aparece durante las pruebas, un diseño limpio 
hará que sea mucho más fácil de rastrear y corregir el error.

Puede ser muy tentador escribir el programa lo más rápido posible, dejando poco o ningún tiempo para pensar en ello antes. 
La programadora estará contenta de ver el programa funcionando en poco tiempo. 
Pero es probable que se frustre poco después: sin una buena reflexión, el programa será complejo y poco claro, 
por lo que el mantenimiento y la corrección de errores se convertirán en un proceso interminable.

Una vez que el programador empieza a codificar, debe utilizar una programación defensiva. 
Esto es similar a la conducción defensiva, que significa conducir evitando los escenarios adversos
(por ejemplo, otros conductores que violan las leyes de tráfico, acontecimientos u obstáculos inesperados, etc.). 
Del mismo modo, programar a la defensiva significa desarrollar código de forma que funcione correctamente en 
los peores escenarios de su entorno. 
Por ejemplo, al escribir una función, hay que suponer las entradas del peor caso para esa función, es decir, 
entradas demasiado grandes, demasiado pequeñas o entradas que violen alguna propiedad, condición o invariante; 
el código debe tratar estos casos, aunque el programador no espere que ocurran en circunstancias normales.

Recuerde que el objetivo no es convertirse en un experto en la corrección de errores, 
sino mejorar en la escritura de programas robustos y (mayoritariamente) libres de errores. 
Como cuestión de actitud, los programadores no deben sentirse orgullosos cuando arreglan errores, 
sino más bien avergonzados de que su código contenga errores. 
Si hay un fallo en un programa, es sólo porque su autor cometió errores.

Existen varias aproximaciones para la depuración de programas simples.
Puede revisar esas diferentes opciones en las transparencias de clase
[Debugging your source code](https://docs.google.com/presentation/d/1-vU5UF1ruhHWMp-lJsoYsq8s8B9ZvJvBsdDUu4wVgDU/edit?usp=sharing)
pero es indudable que utilizar un depurador es la mejor opción en cuanto el programa que se pretende depurar
tiene una cierta entidad.

La depuración es una de las tareas más importantes a la hora de programar. 
Saber cómo utilizar un depurador para establecer puntos de interrupción, cómo pasar por encima y entrar en las funciones 
que se están utilizando ahorra horas de desarrollo. 
La depuración no sólo ahorra un valioso tiempo de desarrollo, sino que también ayuda a comprender mejor la lógica del código 
y el flujo de su ejecución, que no es el objetivo principal de la depuración, pero es un gran efecto adicional.

Se reproducen a continuación algunos consejos extraídos del 
[tutorial de referencia](https://www.learncpp.com/cpp-tutorial/finding-issues-before-they-become-problems/)
de la asignatura, orientados a evitar los errores de programación.
Se trata de una lista incompleta pero que puede ser de gran valor:
* Siga siempre las *Buenas prácticas* de programación
Todas esas prácticas están pensadas para minimizar el número de potenciales errores.
* No deje que sus funciones sean demasiado largas (aproximadamente las líneas que caben en una pantalla, a lo sumo)
* Comente razonablemente su código allí donde sea pertinente
* Simplifique los programas
* Siempre que sea posible, prefiera utilizar la biblioteca estándar (STL) a escribir su propio código. 
En particular en *Informática Básica*, utilice `std::vector`/`std::array` o `std::string` en lugar de arrays o cadenas 
"al estilo de C"
* No programe cuando esté cansada
* Entienda dónde están las trampas comunes en un lenguaje (todo lo que se le advierte no hacer)

A modo de conclusión diremos que **todo el tiempo que dedique a aprender a usar un depurador será tiempo que
ganará en el futuro como profesional**.

### Depuración con Visual Studio Code
Una de las grandes ventajas de utilizar un entorno integrado de desarrollo como VSC es que integra un
depurador avanzado. 
En *Informática Básica* se propone utilizar el depurador 
[gdb](https://www.sourceware.org/gdb/)
a través de su interfaz de Visual Studio Code.

Si no lo ha hecho así, en *Informática Básica* se le recomienda que al instalar Visual Studio Code mantenga el
programa en su versión en inglés (se puede personalizar para español) porque de ese modo podrá seguir mejor
los diferentes tutoriales en inglés sobre el programa.

Para aprender a utilizar el depurador en VSC comience por seguir las instrucciones de la página
[Using C++ on Linux in VS Code](https://code.visualstudio.com/docs/cpp/config-linux)
de la documentación oficial.
En esa página se indica cómo editar, compilar, ejecutar y depurar el fichero `hello_world_debug.cc` que tiene
disponible en el directorio de esta práctica.
Preste particular atención al apartado
[Debug helloworld.cc](https://code.visualstudio.com/docs/cpp/config-linux#_debug-helloworldcpp)
en el que se explican los comandos básicos de depuración.

A continuación, visualice y siga las instrucciones que se presentan en el vídeo
[Depuración con VSC y GDG](https://www.youtube.com/watch?v=MZK9U8GOaao)
que puede encontrar en el Aula Virtual de *Informática Básica*.
El el directorio principal de esta práctica hallará el fichero `fibonacci_sum.tar.gz` que contiene el código
que se utiliza en el vídeo y que ya ha estudiado en una práctica anterior.

A continuación visualice y siga igualmente las instrucciones del vídeo también disponible en el aula virtual
[Depuración de un proyecto C++](https://www.youtube.com/watch?v=O1GhRC3ECWo)
que muestra como compilar, ejecutar y depurar un programa estructurado en varios ficheros.
Los ficheros que se utilizan en ese vídeo están disponibles en el directorio `debug-VSC-multiple-files/` de
esta práctica.

Como ejercicio, trate a continuación de utilizar el depurador para encontrar el error del programa `debug.cc`
que encontrará en el directorio de esta práctica.

A partir de este punto se propone que utilice *siempre* el depurador para identificar errores en todos los
programas que desarrolle.

### Material de estudio complementario
Comience por estudiar el material contenido en las transparencias
[Debugging your source code](https://docs.google.com/presentation/d/1-vU5UF1ruhHWMp-lJsoYsq8s8B9ZvJvBsdDUu4wVgDU/edit?usp=sharing)
que puede encontrar en el aula virtual de la asignatura.

Estudie del
[tutorial de referencia](https://www.learncpp.com/)
en la asignatura todos los apartados del capítulo 3 (teniendo en cuenta las especificidades de VSC).

La introducción a la depuración que figura en este enunciado ha sido extraído de la lección
[Debugging Techniques](https://www.cs.cornell.edu/courses/cs312/2006fa/lectures/lec26.html)
de la universidad de Cornell.

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
* El código de cada uno de los programas deberá organizarse de forma modular, es decir haciendo uso de funciones
* Cada función deberá realizar una única tarea y hacerlo correctamente
* El identificador de una función debe reflejar claramente la finalidad de la función

1. Desarrolle una clase `Point2D` para representar puntos en el espacio bidimensional a través de sus
coordenadas. 
Incluya al menos los siguientes métodos:
* *Show()* para mostrar en pantalla las coordenadas del punto
* *Move* para cambiar las coordenadas del punto
* *Distance* para calcular la 
[distancia](https://www.mathwarehouse.com/algebra/distance_formula/index.php)
entre dos puntos
* *Middle* para calcular el 
[punto medio](https://en.wikipedia.org/wiki/Midpoint)
del segmento que une dos puntos

2. Diseñe una clase `Circulo` que permita representar círculos utilizando como atributos el centro,
el radio y el color del círculo.
Utilice una
[enumeración](https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/)
(`enum`) para representar el color del círculo.
Incluya métodos *Area*, *Perimetro* y *Print* que permitan respectivamente calcular el área, el perímetro del
círculo así como imprimir en pantalla la información relativa al círculo en cuestión.
Incluya asimimsmo un método *EsInterior* que determine si un punto del espacio cartesiano `(x, y)` está o no
dentro del círculo.

3. La clase `Complejo`.

Todo
[número complejo](https://es.wikipedia.org/wiki/N%C3%BAmero_complejo)
puede representarse como la suma de un número real y un número imaginario, de la forma `a + bi` donde el
término `a` es la parte real, `b` la parte imaginaria e `i` la
[unidad imaginaria](https://es.wikipedia.org/wiki/Unidad_imaginaria).

En este ejercicio se propone desarrollar una clase `Complejo` que permita representar y operar con números complejos.

Separe el diseño de su clase `Complejo` en dos ficheros, `complejo.h` y `complejo.cc` conteniendo
respectivamente la declaración y la definición de la clase.
Siga las indicaciones del tutorial 
[Class code and header files](https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)
para realizar esta separación de su clase en dos ficheros.
Siga igualmente las indicaciones del tutorial 
[Header guards](https://www.learncpp.com/cpp-tutorial/header-guards/)
para incluir *header guards* (guardas de cabecera) en sus ficheros de
definiciones (`*.h`) de modo que se evite la inclusión múltiple del mismo fichero.

Desarrolle un programa cliente `complejos.cc` que permita operar con números complejos y haga uso de la clase `Complejo` que diseñe.
La clase `Complejo` ha de contener al menos métodos que implementen la sobrecarga de los operadores de suma y
resta de números complejos así como de los operadores de inserción y extracción en flujos (*streams*).
Así la función `main` del programa `complejos.cc` podría contener (entre otras) sentencias como las siguientes:

```
main() {
  Complejo complejo1{4, 5}, complejo2{7, -8};
  Complejo resultado;
  resultado = complejo1 + complejo2;
  std::cout << resultado;
  resultado = complejo1 - complejo2;
  std::cout << resultado;
}
```
Incluya (discrecionalmente) cualesquiera otras operaciones que considere adecuadas como métodos en la clase `Complejo`.

4. Utilice su clase `Complejo` del ejercicio anterior para resolver el ejercicio
[Complex Numbers](https://exercism.org/tracks/cpp/exercises/complex-numbers)
de Exercism. 
En Exercism el nombre de la clase ha de ser *Complex*.
Es posible que tenga que realizar alguna otra modificación sobre su implementación de la 
clase *Complejo*.
Estudie el fichero `complex_numbers_test.cpp` que contiene los tests de ese problema en Exercism.

5. La clase Fecha.

Desarrolle una clase `Fecha` que permita representar y gestionar fechas.
Incorpore en la clase los miembros de datos y métodos que considere adecuados para la finalidad que se
persigue en este ejercicio.
Incluya un método que permita determinar si el año correspondiente a una fecha es un año bisiesto o
no.
Resuelva el problema 
[Valid Dates](https://jutge.org/problems/P58459_en)
de Jutge y súbalo a la plataforma para su evaluación.
A partir de la solución de ese problema haga que el constructor de la clase `Fecha` solo admita una fecha si
es válida.

Realice un programa cliente `fechas.cc` que permita declarar, leer y escribir (pantalla, teclado o ficheros)
objetos fecha.
