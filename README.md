# portal
# TP4 - Taller de programación

## Manual provisorio

### ¿Como correr el juego?
Una vez descargado el repositorio, se debe instalar sdl, para la instalación del mismo se debe escribir en una terminal los siguientes comandos:

		sudo apt-get install libsdl2-dev


		sudo apt-get install libsdl2-image-dev

Una vez instalado sdl, se debe descomprimir el archivo Box2d.zip, y copiar su contenido en la siguiente ruta ../src/server/modelo/3rdparty/Box2D-cmake

Ya realizados estos pasos se debe abrir una terminal en la ruta ./portal los siguiente comandos:

		cmake 	CMakeLists.txt


		make -j4

Si no ocurrio ningun error, ya se puede correr el juego, para esto primero se debe correr en una terminar el comando: 

		./Server <puerto>

Seguido de este, en otra ventana de una terminal, se debe ingresar el siguiente comnado:

		./Client <host> <puerto> new/join nombre_sala nombre_usuario

El comando new se utiliza para crear una nueva partida con el nombre_sala que se le asigna, en caso que querer unirse a una partida se debe utilizar el comando join con el nombre * de la sala previamente creada.
Una vez ejecutado este comando se debería abrir una ventana de color negro, para comenzar el juego se tocar la tecla con la flecha para abajo. Y luego de unos segundos el juego comienza.

### ¿Como jugar?
Para mover el usuario se deben utilizar las teclas “d” y “a” que mueven al personaje a la derecha o la izquierda. Con el botón “w” se puede saltar.
Para disparar portales se debe utilizar el mouse donde  se debe ingresar con un click la ubicación de donde se quiere crear el portal. Para crear portales de entrada (de color azul) se debe utilizar el click izquierdo, y para crear portales de salida (de color naranja) se debe utilizar el click derecho. Se pueden crear la cantidad deseada de portales.

El personaje puede morir si toca un ácido o si es tocado por una bola de energia, asi que hay que tener cuidado

El objetivo del juego es poder llegar al pastel que se encuentra en algún lugar del mapa. Asi que buena suerte.

## Manual provisorio

