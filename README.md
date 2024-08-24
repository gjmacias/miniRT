# MiniRT - ffornes- && gmacias-

miniRT es un proyecto para aprender sobre Raytracing, donde renderizamos imágenes generadas por ordenador usando fórmulas matemáticas. Aquí te explicamos cómo empezar con el proyecto y qué necesitas saber.

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

### Círculo
La fórmula de un círculo en 2D es:
\[ (x - h)^2 + (y - k)^2 = r^2 \]
Donde \( (h, k) \) es el centro y \( r \) es el radio.

*Imagen del Círculo:* ![Círculo](https://i.ytimg.com/vi/JPnNdV3lZH4/maxresdefault.jpg)

### Plano
Un plano en 3D se representa como:
\[ ax + by + cz + d = 0 \]
Donde \( (a, b, c) \) es el vector normal al plano y \( d \) es la distancia desde el origen.

*Imagen del Plano:* ![Plano](https://github.com/gjmacias/miniRT/blob/master/README-images/plane.PNG)

### Cilindro
Para un cilindro:
- **Ecuación del Eje:** \( (x - x_0)^2 + (y - y_0)^2 = r^2 \)
- **Altura:** La diferencia en la coordenada z entre la base inferior y superior.

*Imagen del Cilindro:* ![Cilindro](https://es.wikipedia.org/wiki/Cilindro#/media/Archivo:Zylinder-senkr-kreis-hr-s.svg)

## Intersección de Rayos

Para renderizar una imagen, trazamos un rayo desde la cámara a través de **cada píxel**. Luego comprobamos si ese rayo interseca con algún objeto en la escena. Aquí te explicamos cómo se calcula:

### 1. **Rayo y Círculo**

Para un círculo en 2D:
- **Rayo:** Representado como una línea que pasa por el origen de la cámara y sigue una dirección específica.
  \[ \text{Rayo}: \mathbf{P} = \mathbf{O} + t \cdot \mathbf{D} \]
  Donde \( \mathbf{O} \) es el origen del rayo, \( \mathbf{D} \) es la dirección del rayo, y \( t \) es un parámetro que indica la distancia a lo largo del rayo.

- **Intersección:** Sustituyendo la ecuación del rayo en la fórmula del círculo y resolviendo para \( t \):
  \[ (O_x + t \cdot D_x - h)^2 + (O_y + t \cdot D_y - k)^2 = r^2 \]

### 2. **Rayo y Plano**

Para un plano en 3D:
- **Rayo:** Igual que antes, representado como una línea.
  \[ \text{Rayo}: \mathbf{P} = \mathbf{O} + t \cdot \mathbf{D} \]

- **Intersección:** Sustituyendo la ecuación del rayo en la fórmula del plano:
  \[ a(O_x + t \cdot D_x) + b(O_y + t \cdot D_y) + c(O_z + t \cdot D_z) + d = 0 \]
  Resolviendo para \( t \) te da la distancia al punto de intersección.

### 3. **Rayo y Cilindro**

Para un cilindro:
- **Ecuación del Eje:** \( (x - x_0)^2 + (y - y_0)^2 = r^2 \)
- **Intersección:** La solución se obtiene sustituyendo la ecuación del rayo en la ecuación del cilindro y resolviendo el sistema de ecuaciones para encontrar los valores de \( t \) que dan puntos de intersección.

### 4. **Sombreado**

Una vez que encontramos el punto de intersección:
- **Calcular la Luz:** Desde el punto de intersección, traza una línea hasta la fuente de luz.
  - **Sombra:** Si el punto de intersección está en la sombra, el color es más oscuro.
  - **Intensidad:** La intensidad de la luz se calcula en base al ángulo entre la dirección de la luz y la superficie.

- **Color Final:** Se combina el color del objeto con la luz calculada para determinar el color final del píxel.

## Estructura

_(Aquí se añadirá información sobre la estructura del proyecto.)_

## Teclado

_(Aquí se añadirá información sobre el uso del teclado.)_

## Cómo Calculamos el Rayo

Para calcular el rayo, seguimos estos pasos:
1. **Definir el origen del rayo**: Es la posición de la cámara.
2. **Calcular la dirección del rayo**: Dependiendo del punto de la imagen en la que estamos mirando.

Esto se hace usando el FOV, el punto central y los ángulos de Euler para ajustar la dirección del rayo desde la cámara hacia los objetos en la escena.

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
