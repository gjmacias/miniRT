# MiniRT - ffornes- && gmacias-

## Introducción

**miniRT** es un proyecto que te introduce al fascinante mundo del raytracing. Con este proyecto, aprenderás a renderizar imágenes generadas por ordenador utilizando técnicas básicas de raytracing. ¡Descubre cómo se crean imágenes realistas desde cero!

### Imágenes de Ejemplo

Aquí tienes algunas imágenes renderizadas con **miniRT**:

![Renderizado Ejemplo 1](https://example.com/imagen1.jpg)
*Descripción de la imagen 1.*

![Renderizado Ejemplo 2](https://example.com/imagen2.jpg)
*Descripción de la imagen 2.*

¡Estas imágenes muestran lo que puedes lograr con el proyecto y te dan una idea de cómo se verán los resultados finales!

### ¿Qué es miniRT?

**miniRT** es un proyecto de raytracing que te permite:
- **Renderizar Imágenes 3D:** Crea imágenes generadas por ordenador utilizando técnicas básicas de raytracing.
- **Entender Conceptos Clave:** Aprende sobre la cámara, las luces, y las figuras geométricas como círculos, planos y cilindros.
- **Aplicar Fórmulas Matemáticas:** Implementa fórmulas para la intersección de rayos con diferentes objetos.

Continúa leyendo para obtener más detalles sobre cómo configurar y utilizar **miniRT**, incluyendo cómo definir el mapa, las fórmulas de intersección, y cómo controlar la cámara y el teclado.

## Índice

1. [Introducción](#introducción)
2. [Mapa de Elementos](#mapa-de-elementos)
   - [Ejemplo de Mapa](#ejemplo-de-mapa)
   - [Detalles de los Elementos](#detalles-de-los-elementos)
3. [Fórmulas](#fórmulas)
   - [Esfera en 3D](#esfera-en-3d)
   - [Plano](#plano)
   - [Cilindro](#cilindro)
4. [Intersección de Rayos](#intersección-de-rayos)
   - [Rayo y Esfera](#rayo-y-esfera)
   - [Rayo y Plano](#rayo-y-plano)
   - [Rayo y Cilindro](#rayo-y-cilindro)
   - [Sombreado](#sombreado)
5. [Estructura de Datos y Cámara](#estructura-de-datos-y-cámara)
   - [Estructura General (t_info y t_data)](#estructura-general-t_info-y-t_data)
   - [Estructura de la Cámara (t_camera)](#estructura-de-la-cámara-t_camera)
6. [Teclado](#teclado)
   - [Salir del Programa](#salir-del-programa)
   - [Mover la Cámara](#mover-la-cámara)
   - [Rotar la Cámara](#rotar-la-cámara)
   - [Ajustar el Campo de Visión (FOV)](#ajustar-el-campo-de-visión-fov)
7. [Soporte](#soporte)

## Mapa de elementos

El mapa define los elementos que aparecerán en tu imagen. Aquí te mostramos cómo configurar cada tipo de elemento:

- **Cámara**: Define la perspectiva desde la que verás la imagen.
- **Luz de Ambiente**: Controla la iluminación general en la escena.
- **Luz**: Crea un foco de iluminación en la escena.
- **Figuras**: Puedes añadir círculos, planos y cilindros.

### Ejemplo de Mapa

Aquí tienes un ejemplo de cómo se definen los elementos en el mapa:

```
A    0.3          255,255,255   					(Luz de ambiente: intensidad, color)
C    0,1,-10      0,0,1         70          				(Cámara: posición, vector de dirección, FOV)
L    0,10,-10     0.7           255,255,255 				(Luz: posición, intensidad, color)

pl   0,0,0        0,1,0         100,100,100 				(Plano: posición, vector normal, color)
sp   0,0,0        5             255,0,10   				(Esfera: posición, radio, color)
cy   4,0,0        1,1,0         4            6         10,0,255   	(Cilindro: posición, radio, altura, color)
```

### Detalles de los Elementos

- **Cámara (C)**
  - **Posición**: 0,1,-10 (dónde está ubicada la cámara)
  - **Vector de Dirección**: 0,0,1 (hacia dónde está mirando la cámara)
  - **FOV**: 70 (Campo de Visión, cuánto puedes ver desde la cámara)

- **Luz de Ambiente (A)**
  - **Intensidad**: 0.3 (qué tan fuerte es la luz de ambiente)
  - **Color**: 255,255,255 (color de la luz de ambiente en formato RGB)

- **Luz (L)**
  - **Posición**: 0,10,-10 (dónde está ubicada la fuente de luz)
  - **Intensidad**: 0.7 (qué tan fuerte es la luz)
  - **Color**: 255,255,255 (color de la luz en formato RGB)

- **Plano (pl)**
  - **Posición**: 0,0,0 (dónde está ubicado el plano)
  - **Vector Normal**: 0,1,0 (la dirección en la que el plano está orientado)
  - **Color**: 100,100,100 (color del plano en formato RGB)

- **Esfera (sp)**
  - **Posición**: 0,0,0 (dónde está ubicada la esfera)
  - **Radio**: 5 (tamaño de la esfera)
  - **Color**: 255,0,10 (color de la esfera en formato RGB)

- **Cilindro (cy)**
  - **Posición**: 4,0,0 (dónde está ubicado el cilindro)
  - **Radio**: 1 (tamaño del cilindro)
  - **Altura**: 6 (altura del cilindro)
  - **Color**: 10,0,255 (color del cilindro en formato RGB)

## Fórmulas

### Esfera en 3D

La fórmula de una esfera en 3D es:

\[ (x - h)^2 + (y - k)^2 + (z - l)^2 = r^2 \]

Donde:
- \( (h, k, l) \) son las coordenadas del centro de la esfera.
- \( r \) es el radio de la esfera.
- \( (x, y, z) \) son las coordenadas de un punto en la superficie de la esfera.

Esta fórmula describe todos los puntos \( (x, y, z) \) que están a una distancia \( r \) del centro \( (h, k, l) \).

*Imagen del Esfera:* ![Esfera](https://i.ytimg.com/vi/BuAeDL_F8OE/maxresdefault.jpg)

### Plano
Un plano en 3D se representa como:
\[ ax + by + cz + d = 0 \]
Donde \( (a, b, c) \) es el vector normal al plano y \( d \) es la distancia desde el origen.

*Imagen del Plano:* ![Plano](https://github.com/gjmacias/miniRT/blob/master/README-images/plane.PNG)

### Cilindro
Para un cilindro:
- **Ecuación del Eje:** \( (x - x_0)^2 + (y - y_0)^2 = r^2 \)
- **Altura:** La diferencia en la coordenada z entre la base inferior y superior.

*Imagen del Cilindro:* [Cilindro](https://es.wikipedia.org/wiki/Cilindro#/media/Archivo:Zylinder-senkr-kreis-hr-s.svg)

## Intersección de Rayos

Para renderizar una imagen, trazamos un rayo desde la cámara a través de **cada píxel**. Luego comprobamos si ese rayo interseca con algún objeto en la escena. Aquí te explicamos cómo se calcula:

### 1. **Rayo y Esfera**

Para una Esfera:
- **Rayo:** Imagina una línea que comienza en la cámara y se extiende en una dirección específica.
- **Intersección:** Sustituyendo la ecuación del rayo en la fórmula del círculo te da la distancia a lo largo del rayo donde se produce la intersección.

![InterseccionEsfera](https://github.com/gjmacias/miniRT/blob/master/README-images/InteseccionEsfera.PNG)

### 2. **Rayo y Plano**

Para un plano en 3D:
- **Rayo:** Igual que antes, representado como una línea.
- **Intersección:** Al sustituir la ecuación del rayo en la fórmula del plano, obtienes la distancia al punto de intersección.

![InterseccionEsfera](https://github.com/gjmacias/miniRT/blob/master/README-images/InteseccionPlano.PNG)

### 3. **Rayo y Cilindro**

Para un cilindro:
- **Ecuación del Eje:** Usa la fórmula del cilindro y sustituye la ecuación del rayo para encontrar los puntos de intersección.

![InterseccionEsfera](https://github.com/gjmacias/miniRT/blob/master/README-images/InteseccionCilindro.PNG)

### 4. **Sombreado**

Una vez que encontramos el punto de intersección, calculamos el color final del píxel con estos pasos:

1. **Color Inicial:**
   - Empieza con el color del objeto y añade la luz de ambiente.
   - Fórmula: 
    Color Inicial = Color del Objeto \ Luz de Ambiente

2. **Calcular la Luz:**
   - Traza una línea desde el punto de intersección hacia la fuente de luz.
   - **Intensidad de la Luz:** Se basa en el ángulo entre el vector normal en el punto de intersección y el vector desde la luz al punto de intersección.
     - *Ángulo menor = mayor intensidad de luz.*
   - **Porcentaje de Intensidad:** Determinado por este ángulo.

3. **Sombra:**
   - Verifica si hay un objeto que bloquea la luz entre el punto de intersección y la fuente de luz.
     - Si hay una colisión, el punto de intersección está en sombra y recibe menos luz.

4. **Color Final:**
   - Combina el color inicial con la intensidad de la luz para obtener el color final del píxel.
   - Fórmula:
     Color Final = Color Inicial + Intensidad de la Luz \ Color del Objeto

Esto da lugar a una imagen más realista, ajustando el brillo y el color según cómo interactúa la luz con los objetos en la escena.

![Cálculo de Sombra](https://github.com/gjmacias/miniRT/blob/master/README-images/CalculoSombra.PNG)


Entendido. A continuación, te proporciono una explicación clara y accesible de la estructura de datos y de la cámara para tu README. Esto te permitirá entender cómo se organizan los datos y qué información se almacena en cada estructura sin necesidad de añadir directamente el código al README.

---

## Estructura de Datos y Cámara

En el proyecto, usamos varias estructuras de datos para manejar la información de la escena y la configuración de la cámara. Aquí te explicamos cómo se organizan:

### 1. **Estructura General (`t_info` y `t_data`)**

- **`t_info`**: Esta estructura guarda información sobre la cantidad de cada tipo de elemento en la escena:
  - `ambient_light`: Cantidad de luces ambientales.
  - `camera`: Cantidad de cámaras.
  - `lights`: Cantidad de luces.
  - `planes`: Cantidad de planos.
  - `spheres`: Cantidad de esferas.
  - `cylinders`: Cantidad de cilindros.

- **`t_data`**: Esta estructura contiene toda la información sobre la imagen que se va a renderizar:
  - `width` y `height`: Dimensiones de la imagen (ancho y alto).
  - `info`: Estructura `t_info` que detalla la cantidad de cada tipo de objeto en la escena.
  - `line`: Cuenta las líneas procesadas.
  - `lights`, `planes`, `spheres`, `cylinders`: Listas que contienen los objetos en la escena. Estas listas almacenan la información de luces, planos, esferas y cilindros, respectivamente.
  - `camera`: Información sobre la cámara.
  - `ambient_light`: Información sobre la luz ambiental.

### 2. **Estructura de la Cámara (`t_camera`)**

La cámara se encarga de definir la perspectiva desde la que se renderiza la imagen. Su estructura incluye:

- **`fov`**: El campo de visión (FOV) de la cámara, que determina cuánto se puede ver desde la cámara. Un valor mayor significa un campo de visión más amplio.
- **`center`**: Un vector que representa la posición del centro de la cámara en el espacio.
- **`euler`**: Un vector que contiene los ángulos de Euler, utilizados para orientar la cámara en el espacio 3D.
- **`q`**: Un cuaternión que se utiliza para representar la rotación de la cámara en 3D. Los cuaterniones son útiles para evitar problemas con la interpolación y la rotación en 3D.

## Teclado

En el proyecto, las teclas del teclado permiten controlar la cámara y ajustar la vista de la escena. Aquí está una explicación detallada de cómo funciona cada tecla y por qué utilizamos ciertas técnicas para el manejo de la cámara.

### 1. **Salir del Programa**

- **Tecla ESC:** Cierra la ventana y termina el programa.

### 2. **Mover la Cámara**

- **Teclas W, A, S, D:** Se utilizan para mover la cámara en diferentes direcciones:
  - **W:** Mueve la cámara hacia adelante (en la dirección en la que está mirando).
  - **A:** Mueve la cámara hacia la izquierda (perpendicular a la dirección de la vista).
  - **S:** Mueve la cámara hacia atrás (opuesto a la dirección de la vista).
  - **D:** Mueve la cámara hacia la derecha (perpendicular a la dirección de la vista).

  Estas teclas modifican el **centro** de la cámara, que es el punto desde el que la cámara está viendo la escena. Mover el centro de la cámara cambia la posición de la cámara en el espacio sin rotarla.

- **Tecla SPACE:** Eleva la cámara hacia arriba.
- **Tecla SHIFT:** Baja la cámara hacia abajo.

### 3. **Rotar la Cámara**

- **Teclas de flecha arriba (UP_K) y abajo (DOWN_K):** Ajustan la inclinación vertical de la cámara:
  - **UP_K:** Inclina la cámara hacia arriba, cambiando el ángulo de visión vertical.
  - **DOWN_K:** Inclina la cámara hacia abajo, cambiando el ángulo de visión vertical.

- **Teclas de flecha izquierda (LEFT_K) y derecha (RIGHT_K):** Ajustan la rotación horizontal de la cámara:
  - **LEFT_K:** Rote la cámara hacia la izquierda, cambiando el ángulo de visión horizontal.
  - **RIGHT_K:** Rote la cámara hacia la derecha, cambiando el ángulo de visión horizontal.

  Estas teclas modifican los **ángulos de Euler** de la cámara, que son los ángulos que determinan cómo está orientada la cámara en el espacio. Los ángulos de Euler se utilizan para ajustar la inclinación y la rotación de la cámara de manera simple.

[Ángulos de Euler](https://www.uhu.es/francisco.moreno/gii_ao/docs/Tema_8.pdf)

### 4. **Ajustar el Campo de Visión (FOV)**

- **Tecla + (PLUS_K):** Aumenta el campo de visión de la cámara en 5 grados, hasta un máximo de 180 grados.
- **Tecla - (MINUS_K):** Disminuye el campo de visión de la cámara en 5 grados, hasta un mínimo de 0 grados.

## Soporte

Funciona en **Mac** y **Linux**.

# Quizás pueda interesarte!

### - Perfil de GitHub ffornes-
[AQUÍ](https://github.com/ffornesp)

### - Perfil de GitHub gmacias-
[AQUÍ](https://github.com/gjmacias)

# Contactos 📥

◦ Email ffornes-: ffornes-@student.42barcelona.com

◦ Email gmacias-: gmacias-@student.42barcelona.com

[1]: https://www.42barcelona.com/ "42 BCN"
