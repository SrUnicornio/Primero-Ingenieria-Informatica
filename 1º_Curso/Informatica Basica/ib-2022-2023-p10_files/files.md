# Práctica 10. Ficheros. Visual Studio Code.

# Factor de ponderación: 9

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Sea capaz de resolver problemas sencillos en C++ usando todos los conocimientos adquiridos hasta ahora,
  y en particular utilizando funciones y ficheros de texto
* Diseñe, desarrolle y utilice funciones en sus programas haciendo que sus programas sean modulares
* Configure y practique el uso de Visual Studio Code (VSC) para editar ficheros de forma remota en su VM

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

#### Visual Studio Code
Un
[IDE](https://en.wikipedia.org/wiki/Integrated_development_environment)
(*Integrated development environment*, entorno integrado de desarrollo) es un programa que proporciona
diversos servicios a una programadora para facilitarle la tarea del desarrollo de programas.
Los servicios más comunes que proporciona un IDE son un editor de código fuente (hasta ahora se ha usado vi),
un compilador (se seguirá usando g++), herramientas de construcción automáticas (hasta ahora se ha utilizado
`make`) y un depurador.
La mayoría de los IDE tienen auto-completado inteligente de código (IntelliSense).
Los IDE presentan un único programa en el que se lleva a cabo todo el desarrollo.
Generalmente, este programa (IDE) suele ofrecer muchas funcionalidades para la creación, modificación, compilación, implementación y depuración de programas.
Algunos IDE están orientados específicamente a un determinado lenguaje de programación, mientras que otros  se
pueden utilizar con diferentes lenguajes.

[Visual Studio Code](https://en.wikipedia.org/wiki/Visual_Studio_Code)
(VSC) es un IDE desarrollado por Microsoft
para Windows, Linux, macOS y Web.
Incluye soporte para la depuración, control integrado de Git, resaltado de sintaxis, finalización inteligente de código,
fragmentos y
[refactorización](https://es.wikipedia.org/wiki/Refactorizaci%C3%B3n)
(modificación del código fuente sin cambiar su comportamiento).
El IDE es personalizable, por lo que sus usuarios pueden cambiar el tema del editor, los atajos de teclado y las preferencias.
Es gratuito y de código abierto y es
[uno de los IDEs más utilizados](https://www.geeksforgeeks.org/10-best-ide-for-web-developers-in-2022/)
en la actualidad.
En *Informática Básica* se adoptará VSC como IDE, y se utilizará en la evaluación de las prácticas
restantes de la asignatura.

Para instalar VSC en su instalación Linux particular (no en su máquina virtual, sino en la instalación Linux
desde la que suele trabajar) siga
[estas instrucciones](https://code.visualstudio.com/docs/setup/linux)
descargando el paquete `.deb`.
Una vez haya descargado el paquete, instálelo en su máquina ejecutando:
```
sudo apt install code_1.73.1-1667967334_amd64.deb
```
El comando anterior se refiere al paquete con la versión 1.73.
Asegúrese de usar el nombre del paquete `.deb` que ha descargado.

Una vez haya instalado el paquete, compruebe que puede iniciar VSC en su máquina ejecutando en una terminal:
```
code .
```
En el comando anterior el punto indica que desea Ud. editar ficheros en el directorio actual (`.`).
Una vez arranque el programa, salga del mismo utilizando el menú (*File* -> *Exit*).

Siga a continuación las instrucciones de la página
[Remote Development using SSH](https://code.visualstudio.com/docs/remote/ssh)
para configurar la edición remota usando VSC.

De los tres pasos que se indican en la página anterior:
1. Instalar un cliente OpenSSH
2. Instalar Visual Studio Code
3. Instalar el paquete correspondiente a la extensión *Remote Development extension pack*

Solo tiene que realizar el tercero, puesto que (1) ya se tiene `ssh` tanto en la máquina virtual como en su máquina de
trabajo y la instalación de VSC (2) ya se ha realizado usando `apt install`.

Si sigue el enlace
[Remote Development extension pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack)
le llevará a una página en la que le indica el comando que ha de teclear en VSC (`Ctrl+P`) para instalar la
extensión.

Vuelva de nuevo a la página
[Remote Development using SSH](https://code.visualstudio.com/docs/remote/ssh)
y del apartado *SSH host setup* realice las instrucciones del paso 3 (opcional).
Para ello ha de acceder a la página
[Tips and Tricks](https://code.visualstudio.com/docs/remote/troubleshooting#_improving-security-on-multi-user-servers)
y seguir las instrucciones correspondientes a *Quick start: Using SSH keys*.

Ejecute para ello (sustituyendo la dirección IP por la de su VM):
```
$ ssh-keygen -t rsa -b 4096
$ export USER_AT_HOST=usuario@10.6.131.106
$ export PUBKEYPATH="$HOME/.ssh/id_rsa.pub"
$ ssh-copy-id -i "$PUBKEYPATH" "$USER_AT_HOST"
```
[Esta imagen](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/master/img/VSC-connect-to-host.png)
muestra el paso 2 del apartado "Connect to a remote host" de esas instrucciones mientras que
[esta otra](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/master/img/VSC-password.png)
muestra la ventana de autentificación de VSC para darle acceso a la máquina virtual.
[Este vídeo](https://youtu.be/pAUfwae-eWg) ilustra cómo configurar la edición remota de ficheros alojados en máquinas IaaS-ULL usando VSC.

Una vez instalado en su máquina local, ejecute el Microsoft Visual Studio Code (VSC) y siga
[estas instrucciones](https://code.visualstudio.com/docs/remote/ssh)
para configurar la edición remota de ficheros alojados en su máquina virtual.

Siga a continuación las instrucciones de la página
[C/C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)
para instalar la extensión para C/C++ en VSC.

Se puede comprobar que ya se dispone del compilador `g++` de GNU, que es el que se ha venido utilizando en
*Informática Básica*.

Siga las instrucciones para crear un subdirectorio con nombre `HelloWorld` en el directorio de la práctica 10
y edite dentro de ese directorio de la máquina remota el fichero `helloworld.cc` al que se refiere la página
anterior.

En *Informática Básica* se recomienda en este momento instalar la extensión
[vscodevim](https://marketplace.visualstudio.com/items?itemName=vscodevim.vim)
de emulación de Vim en VSC.
Si instala esa extensión (`ext install vscodevim.vim`) en VSC podrá utilizar en VSC todos los comandos que ya
conoce de `vim`, lo cual le permitirá seguir practicando con este último editor.

El Visual Studio Code está instalado en los ordenadores de las Salas del Centro de Cálculo de la ESIT.
Con antelación a la sesión de evaluación de esta práctica, el alumnado debiera comprobar en uno de esos
ordenadores la conexión hacia su máquina virtual de la asignatura, para comprobar que todo funcione
correctamente antes de la sesión de evaluación.

### Material de estudio complementario
Además de los contenidos revisados en las
[Transparencias de clase](https://docs.google.com/presentation/d/1k2IyoAsmd60a6EzP96eLuhgISdf9e35nPRPIBb92a3E/edit?usp=sharing)
correspondientes al tema de Entrada/Salida así como los
[Ejemplos de código](https://github.com/IB-2022-2023/IB-class-code-examples/tree/master/Functions)
correspondientes a ese material,
estudie del
[tutorial de referencia](https://www.learncpp.com/)
en la asignatura los siguientes apartados:
* [23.1 Input and output (I/O) streams](https://www.learncpp.com/cpp-tutorial/input-and-output-io-streams/)
* [23.2 Input with istream](https://www.learncpp.com/cpp-tutorial/input-with-istream/)
* [23.3 Output with ostream and ios](https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/)
* [23.6 Basic file I/O](https://www.learncpp.com/cpp-tutorial/basic-file-io/)

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

1. Escriba un programa `vowels-and-consonants.cc` que imprima en pantalla la palabra con mayor número de vocales y la palabra con el
mayor número de consonantes (independientemente de si se trata de mayúsculas o minúsculas) que se encuentren
en un fichero de texto que se le pase como parámetro por línea de comandos.
En caso de empate (haya varias palabras con igual número de vocales/consonantes) el programa imprimirá la
palabra que aparezca antes en el fichero de texto.

2. Escriba un programa `rotate.cc` que *rote* las vocales en minúscula que encuentre en el fichero que se le
pase como parámetro por línea de comandos, entendiendo por *rotar* el cambio de
* 'a' por 'e'
* 'e' por 'i'
* 'i' por 'o'
* 'o' por 'u'
* 'u' por 'a'

De modo que un fichero de entrada que contuviera este texto:
```
In an age when acronyms were popular, the Manchester Mark I was
sometimes referred to as MADM (Manchester Automatic Digital Machine)
or MUC (Manchester University Computer).
```
Produciría como salida este otro:
```
In en egi whin ecrunyms wiri pupaler, thi Menchistir Merk I wes
sumitomis rifirrid tu es MADM (Menchistir Aatumetoc Dogotel Mechoni)
ur MUC (Menchistir Unovirsoty Cumpatir).
```

3. Escriba un programa que lea un fichero de texto que se le pase como parámetro y produzca como salida
ficheros con nombre `A.txt`, `B.txt`, ..., `Z.txt`.
Cada uno de esos ficheros ha de contener en líneas separadas todas las palabras del fichero pasado como
parámetro que comiencen por la correspondiente letra.

4. Un autómata finito determinista ([DFA](https://en.wikipedia.org/wiki/Deterministic_finite_automaton)
por sus siglas en inglés) es una máquina abstracta que acepta o rechaza una determinada secuencia de símbolos.
Lea el artículo de
[Wikipedia](https://en.wikipedia.org/wiki/Deterministic_finite_automaton)
si quiere conocer algunos detalles sobre este modelo de cómputo, aunque ello no es estrictamente necesario
para realizar este ejercicio.
Escriba un programa `read_DFA.cc` que lea un fichero de texto `input.dfa` que contiene la especificación de un
DFA e imprima en pantalla las características del mismo.
Los ficheros de especificación de DFAs tienen la siguiente estructura:
* Línea 1: Número total de estados del DFA.
* Línea 2: Estado de arranque del DFA.
* A continuación vendrá una línea para cada uno de los estados.
  Cada línea contendrá los siguientes números, separados entre sí por espacios en blanco:
  * Número identificador del estado.
  Los estados del autómata se representarán mediante números enteros sin signo.
  La numeración de los estados corresponderá a los primeros números naturales comenzando por 0.
  * Un 1 si se trata de un estado de aceptación y un 0 si se trata de un estado de no aceptación.
  * Número de transiciones que posee el estado.
  * A continuación, para cada una de las transiciones, y separados por espacios en blanco, se detallará la información siguiente:
    * Símbolo de entrada necesario para que se produzca la transición.
    * Estado destino de la transición.

A modo de ejemplo, el siguiente sería el contenido del fichero de especificación del DFA de
[esta figura](https://raw.githubusercontent.com/IB-2022-2023/P10-files/main/dfa.png)
```
4
0
0 0 2 a 1 b 3
1 1 2 a 1 b 2
2 1 2 a 1 b 3
3 0 2 a 3 b 3
```
y para este fichero de entrada el programa debería imprimir en pantalla la siguiente información:
```
|Q| = 4
q0 = 0
F = {1, 2}
delta(0, a) = 1
delta(0, b) = 3
delta(1, a) = 1
delta(1, b) = 2
delta(2, a) = 1
delta(2, b) = 3
delta(3, a) = 3
delta(3, b) = 3
```
Es decir en las 3 primeras líneas se imprime el cardinal del conjunto de estados,
El estado de arranque (q0) y el conjunto de estados que son de aceptación (F).
En las líneas sucesivas se imprime el valor de la función de transición (*delta*) para cada estado y símbolo.

5. Lea esta
[introducción a la criptografía](Criptografia.md)
y a continuación, desarrolle en C++ un programa `cripto.cc` cuya finalidad será encriptar y/o desencriptar ficheros de texto.
Si el programa se ejecuta sin pasar parámetros en la línea de comandos, se debiera obtener el siguiente mensaje:
```
./cripto -- Cifrado de ficheros
Modo de uso: ./cripto fichero_entrada fichero_salida método password operación
Pruebe ./cripto --help para más información
```

Si el programa se ejecuta pasando la opción `--help` se ha de obtener:

```
./cripto -- Cifrado de ficheros
Modo de uso: ./cripto fichero_entrada fichero_salida método password operación

fichero_entrada: Fichero a codificar
fichero_salida:  Fichero codificado
método:          Indica el método de encriptado
                   1: Cifrado xor
                   2: Cifrado de César
password:        Palabra secreta en el caso de método 1, Valor de K en el método 2
operación:       Operación a realizar en el fichero
                   +: encriptar el fichero
                   -: desencriptar el fichero
```

El programa solo se ejecutará cuando se le hayan pasado por línea de comandos los parámetros necesarios.
En caso de detectar cualquier inconsistencia en los parámetros, el programa debe abortar su ejecución.
Se indicará asimismo un mensaje de error si el programa no consigue abrir el fichero de entrada.
