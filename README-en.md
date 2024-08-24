# MiniRT - ffornes- && gmacias-

## Introduction

**miniRT** is a project that introduces you to the fascinating world of ray tracing. With this project, you will learn how to render computer-generated images using basic ray tracing techniques. Discover how realistic images are created from scratch!

### Example Images

Here are some images rendered with **miniRT**:

| ![Sphere and Cylinder](https://github.com/gjmacias/miniRT/blob/master/README-images/examples/imagen.png) | ![5 Objects](https://github.com/gjmacias/miniRT/blob/master/README-images/examples/5obj.PNG) |
|:------------------------------------------------------------------------------------------------------:|:--------------------------------------------------------------------------------------------:|
| ![Complex Scene](https://github.com/gjmacias/miniRT/blob/master/README-images/examples/Brightness_Complex.PNG) | ![3 Axes](https://github.com/gjmacias/miniRT/blob/master/README-images/examples/Multi%20objetos.png) |

These images show what you can achieve with the project and give you an idea of what the final results will look like!

### What is miniRT?

**miniRT** is a ray tracing project that allows you to:
- **Render 3D Images:** Create computer-generated images using basic ray tracing techniques.
- **Understand Key Concepts:** Learn about the camera, lights, and geometric shapes such as spheres, planes, and cylinders.
- **Apply Mathematical Formulas:** Implement formulas for ray intersection with different objects.

Continue reading for more details on how to set up and use **miniRT**, including how to define the map, intersection formulas, and how to control the camera and keyboard.

## Table of Contents

1. [Introduction](#introduction)
2. [Element Map](#element-map)
   - [Map Example](#map-example)
   - [Element Details](#element-details)
3. [Formulas](#formulas)
   - [3D Sphere](#3d-sphere)
   - [Plane](#plane)
   - [Cylinder](#cylinder)
4. [Ray Intersection](#ray-intersection)
   - [Ray and Sphere](#1-ray-and-sphere)
   - [Ray and Plane](#2-ray-and-plane)
   - [Ray and Cylinder](#3-ray-and-cylinder)
   - [Shading](#4-shading)
5. [Data Structure and Camera](#data-structure-and-camera)
   - [General Structure (t_info and t_data)](#1-general-structure-t_info-and-t_data)
   - [Camera Structure (t_camera)](#2-camera-structure-t_camera)
6. [Keyboard](#keyboard)
   - [Exit the Program](#1-exiting-the-program)
   - [Move the Camera](#2-moving-the-camera)
   - [Rotate the Camera](#3-rotating-the-camera)
   - [Adjust Field of View (FOV)](#4-adjusting-the-field-of-view-fov)
7. [Support](#support)
   - [Key Configuration](#key-configuration)
   - [Library Management](#library-management)
8. [Demo](#demonstration)
   - [Initial Setup and Scene Loading](#1-initial-setup-and-scene-loading)
   - [Camera Interaction and Real-Time Rendering](#2-interaction-with-the-camera-and-real-time-rendering)


## Element Map

The map defines the elements that will appear in your image. Here’s how to configure each type of element:

- **Camera:** Defines the perspective from which you will view the image.
- **Ambient Light:** Controls the overall lighting in the scene.
- **Light:** Creates a spotlight in the scene.
- **Shapes:** You can add spheres, planes, and cylinders.

### Map Example

Here’s an example of how elements are defined in the map:

```
A    0.3          255,255,255   					(Ambient Light: intensity, color)
C    0,1,-10      0,0,1         70          				(Camera: position, direction vector, FOV)
L    0,10,-10     0.7           255,255,255 				(Light: position, intensity, color)

pl   0,0,0        0,1,0         100,100,100 				(Plane: position, normal vector, color)
sp   0,0,0        5             255,0,10   				(Sphere: position, radius, color)
cy   4,0,0        1,1,0         4            6         10,0,255   	(Cylinder: position, radius, height, color)
```

### Element Details

- **Camera (C)**
  - **Position:** 0,1,-10 (where the camera is located)
  - **Direction Vector:** 0,0,1 (the direction the camera is facing)
  - **FOV:** 70 (Field of View, how much you can see from the camera)

- **Ambient Light (A)**
  - **Intensity:** 0.3 (how strong the ambient light is)
  - **Color:** 255,255,255 (color of the ambient light in RGB format)

- **Light (L)**
  - **Position:** 0,10,-10 (where the light source is located)
  - **Intensity:** 0.7 (how strong the light is)
  - **Color:** 255,255,255 (color of the light in RGB format)

- **Plane (pl)**
  - **Position:** 0,0,0 (where the plane is located)
  - **Normal Vector:** 0,1,0 (the direction the plane is oriented)
  - **Color:** 100,100,100 (color of the plane in RGB format)

- **Sphere (sp)**
  - **Position:** 0,0,0 (where the sphere is located)
  - **Radius:** 5 (size of the sphere)
  - **Color:** 255,0,10 (color of the sphere in RGB format)

- **Cylinder (cy)**
  - **Position:** 4,0,0 (where the cylinder is located)
  - **Radius:** 1 (size of the cylinder)
  - **Height:** 6 (height of the cylinder)
  - **Color:** 10,0,255 (color of the cylinder in RGB format)

## Formulas

### 3D Sphere

The formula for a 3D sphere is:

\[ (x - h)^2 + (y - k)^2 + (z - l)^2 = r^2 \]

Where:
- \( (h, k, l) \) are the coordinates of the sphere’s center.
- \( r \) is the radius of the sphere.
- \( (x, y, z) \) are the coordinates of a point on the surface of the sphere.

This formula describes all the points \( (x, y, z) \) that are at a distance \( r \) from the center \( (h, k, l) \).

*Sphere Image:* ![Sphere](https://i.ytimg.com/vi/BuAeDL_F8OE/maxresdefault.jpg)

### Plane

A plane in 3D is represented as:
\[ ax + by + cz + d = 0 \]
Where \( (a, b, c) \) is the normal vector to the plane and \( d \) is the distance from the origin.

*Plane Image:* ![Plane](https://github.com/gjmacias/miniRT/blob/master/README-images/plane.PNG)

### Cylinder

For a cylinder:
- **Axis Equation:** \( (x - x_0)^2 + (y - y_0)^2 = r^2 \)
- **Height:** The difference in the z-coordinate between the bottom and top bases.

*Cylindrical Image:* [Cylinder](https://es.wikipedia.org/wiki/Cilindro#/media/Archivo:Zylinder-senkr-kreis-hr-s.svg)

## Ray Intersection

To render an image, we trace a ray from the camera through **each pixel** and then check if that ray intersects with any objects in the scene. Here’s how it is calculated:

### 1. Ray and Sphere

For a Sphere:
- **Ray:** Imagine a line starting at the camera and extending in a specific direction.
- **Intersection:** Substituting the ray’s equation into the sphere’s formula gives the distance along the ray where the intersection occurs.

![Ray-Sphere Intersection](https://github.com/gjmacias/miniRT/blob/master/README-images/InteseccionEsfera.PNG)

### 2. Ray and Plane

For a plane in 3D:
- **Ray:** Similar to before, represented as a line.
- **Intersection:** Substituting the ray’s equation into the plane’s formula gives the distance to the intersection point.

![Ray-Plane Intersection](https://github.com/gjmacias/miniRT/blob/master/README-images/InteseccionPlano.PNG)

### 3. Ray and Cylinder

For a cylinder:
- **Axis Equation:** Use the cylinder’s formula and substitute the ray’s equation to find the intersection points.

![Ray-Cylinder Intersection](https://github.com/gjmacias/miniRT/blob/master/README-images/InteseccionCilindro.PNG)

### 4. Shading

Once we find the intersection point, we calculate the final color of the pixel using these steps:

1. **Initial Color:**
   - Start with the object's color and add ambient light.
   - Formula: 
     Initial Color = Object Color + Ambient Light

2. **Calculate Light:**
   - Trace a line from the intersection point to the light source.
   - **Light Intensity:** Based on the angle between the normal vector at the intersection point and the vector from the light to the intersection point.
     - *Smaller angle = higher light intensity.*
   - **Intensity Percentage:** Determined by this angle.

3. **Shadow:**
   - Check if there is an object blocking the light between the intersection point and the light source.
     - If there is a blockage, the intersection point is in shadow and receives less light.

4. **Final Color:**
   - Combine the initial color with the light intensity to get the final pixel color.
   - Formula:
     Final Color = Initial Color + Light Intensity × Object Color

This results in a more realistic image, adjusting brightness and color based on how light interacts with objects in the scene.

![Shadow Calculation](https://github.com/gjmacias/miniRT/blob/master/README-images/CalculoSombra.PNG)

## Data Structure and Camera

In the project, we use several data structures to manage scene information and camera configuration. Here’s how they are organized:

### 1. General Structure (`t_info` and `t_data`)

- **`t_info`**: This structure holds information about the quantity of each type of element in the scene:
  - `ambient_light`: Amount of ambient lights.
  - `camera`: Amount of cameras.
  - `lights`: Amount of lights.
  - `planes`: Amount of planes.
  - `spheres`: Amount of spheres.
  - `cylinders`: Amount of cylinders.

- **`t_data`**: This structure contains all the information about the image to be rendered:
  - `width` and `height`: Dimensions of the image (width and height).
  - `info`: `t_info` structure detailing the quantity of each type of object in the scene.
  - `line`: Counts the processed lines.
  - `lights`, `planes`, `spheres`, `cylinders`: Lists containing the objects in the scene. These lists store information about lights, planes, spheres, and cylinders, respectively.
  - `camera`: Information about the camera.
  - `ambient_light`: Information about the ambient light.

### 2. Camera Structure (`t_camera`)

The camera defines the perspective from which the image is rendered. Its structure includes:

- **`fov`**: The camera’s field of view (FOV), which determines how much is visible from the camera. A higher value means a wider field of view.
- **`center`**: A vector representing the position of the camera's center in space.
- **`euler`**: A vector containing the Euler angles used to orient the camera in 3D space.
- **`q`**: A quaternion used to represent the camera’s rotation in 3D. Quaternions are useful to avoid issues with interpolation and rotation in 3D.

## Keyboard

In the project, keyboard keys allow you to control the camera and adjust the scene view. Here’s a detailed explanation of how each key works and why we use certain techniques for camera management.

### 1. Exiting the Program

- **ESC Key / Control + C:** Closes the window and terminates the program.

### 2. Moving the Camera

- **W, A, S, D Keys:** Used to move the camera in different directions:
  - **W:** Moves the camera forward (in the direction it is facing).
  - **A:** Moves the camera to the left (perpendicular to the view direction).
  - **S:** Moves the camera backward (opposite to the view direction).
  - **D:** Moves the camera to the right (perpendicular to the view direction).

  These keys modify the **center** of the camera, which is the point from which the camera is viewing the scene. Moving the camera center changes the camera’s position in space without rotating it.

- **SPACE Key:** Elevates the camera upwards.
- **SHIFT Key:** Lowers the camera downwards.

### 3. Rotating the Camera

- **Up Arrow (UP_K) and Down Arrow (DOWN_K) Keys:** Adjust the camera’s vertical tilt:
  - **UP_K:** Tilts the camera upwards, changing the vertical viewing angle.
  - **DOWN_K:** Tilts the camera downwards, changing the vertical viewing angle.

- **Left Arrow (LEFT_K) and Right Arrow (RIGHT_K) Keys:** Adjust the camera’s horizontal rotation:
  - **LEFT_K:** Rotates the camera to the left, changing the horizontal viewing angle.
  - **RIGHT_K:** Rotates the camera to the right, changing the horizontal viewing angle.

  These keys modify the **Euler angles** of the camera, which are the angles that determine how the camera is oriented in space. Euler angles are used to adjust the camera’s tilt and rotation in a straightforward manner.

[Euler Angles](https://www.uhu.es/francisco.moreno/gii_ao/docs/Tema_8.pdf)

### 4. Adjusting the Field of View (FOV)

- **+ Key (PLUS_K):** Increases the camera’s field of view by 5 degrees, up to a maximum of 180 degrees.
- **- Key (MINUS_K):** Decreases the camera’s field of view by 5 degrees, down to a minimum of 0 degrees.

## Support

This project is designed to be compatible with both **Linux** and **MacOS**, and specific configurations have been implemented to ensure it works smoothly on both operating systems.

### Key Configuration

In graphics and user input projects, such as handling keys, the codes associated with each key can vary depending on the operating system. To handle these differences:

- A configuration file is defined where a specific value is assigned to each relevant key, such as the keys for moving the camera or adjusting the view.
- This file assigns the correct codes for each key depending on whether the project is running on Linux or MacOS.

For example:
- The **ESC** key is used to exit the program.
- The **W, A, S, D** keys move the camera in the corresponding directions.
- The **arrow keys** are used to rotate the camera vertically and horizontally.
- The **+ and -** keys adjust the camera’s field of view (FOV).
- The **SPACE** key moves the camera upwards, and the **SHIFT** key moves it downwards.

### Library Management

The project uses **MiniLibX (MLX)**, a lightweight library for 2D graphics programming, specifically designed for Unix-like environments such as Linux and MacOS. However, due to differences between operating systems, it is necessary to configure the libraries and their paths properly for the project to compile correctly on both systems.

1. **Operating System Detection**:
   - A variable is used to automatically identify whether the project is running in a Linux or MacOS environment.

2. **Library Configuration**:
   - On **Linux**:
     - The Linux-specific **MLX** library is included, which handles window creation, keyboard events, and on-screen drawing.
     - Additionally, system libraries such as **X11** (which manages graphical interactions in Unix environments), **Xext** (an extension of X11), and **math.h** (for mathematical functions needed in graphics) are linked.
   - On **MacOS**:
     - The MacOS-compatible version of **MLX** is used.
     - Instead of the X11 and Xext libraries used in Linux, MacOS-specific frameworks such as **OpenGL** (for 2D and 3D graphics) and **AppKit** (for graphical user interface) are utilized.

3. **Adaptive Compilation**:
   - Depending on the detected operating system, the **Makefile** automatically adjusts the compilation paths and options. This ensures that the project compiles and links all necessary dependencies correctly, regardless of whether you are on Linux or MacOS.

This approach ensures that the project is not only portable across different operating systems but also remains optimized and compatible with the specifics of each environment.

## Demonstration

To illustrate how the project works in practice, we have prepared a series of videos showing various aspects and functionalities of the program in action. These videos cover:

### 1. Initial Setup and Scene Loading:

https://github.com/user-attachments/assets/89b007eb-3e49-41ad-89d9-835514ac6dc6

https://github.com/user-attachments/assets/fb7f2ec8-c4a1-47b0-9e77-1ca5f31f2020

https://github.com/user-attachments/assets/0e1a1be8-d323-4326-9ba2-bf296c1388ef

### 2. Interaction with the Camera and Real-Time Rendering:

*The videos are x4 at a resolution of 800x400*

https://github.com/user-attachments/assets/9629deba-5ecb-416a-9783-d53e36cde98f

https://github.com/user-attachments/assets/c93468b0-f2a6-4bb9-a3c6-c064a3bea923

These clips will provide you with a clear view of how to use the program and what to expect in terms of performance and visualization.

# How to Contribute

If you would like to contribute to the project:

1. **Fork** the repository.
2. **Create a branch** for your changes.
3. **Make the necessary changes**.
4. **Submit a Pull Request** describing the changes you made.

# You Might Be Interested!

### - GitHub Profile ffornes-
[HERE](https://github.com/ffornesp)

### - GitHub Profile gmacias-
[HERE](https://github.com/gjmacias)

# Contacts 📥

◦ Email ffornes-: ffornes-@student.42barcelona.com

◦ Email gmacias-: gmacias-@student.42barcelona.com

[1]: https://www.42barcelona.com/ "42 BCN"
