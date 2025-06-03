# 🧱 So_long

Proyecto realizado como parte del programa 42. El objetivo es crear un pequeño videojuego 2D en C utilizando la librería gráfica MiniLibX, donde el jugador debe recoger todos los objetos y llegar a la salida, evitando errores en la lógica del mapa y en la interacción.

---

## 🧠 Descripción

- Juego en 2D en el que controlas un personaje que debe recorrer un mapa recogiendo todos los objetos (`C`) y alcanzando la salida (`E`) sin atravesar paredes (`1`).
- El mapa es leído desde un archivo `.ber`, que debe cumplir ciertos requisitos de validez (bordes cerrados, número correcto de elementos, etc).
- El proyecto refuerza conocimientos sobre estructuras de datos, validación de entrada, manejo de imágenes y eventos gráficos básicos.

---

## ⚙️ Compilación

Para compilar el juego, asegúrate de tener instalado **MiniLibX** y luego ejecuta:

bash
make
---

## 🚀 Uso

bash
./so_long maps/map.ber

---

## 📁 Estructura

- **check_map.c** – Valida el mapa: formato rectangular, cerrado por muros, y que contenga los elementos mínimos (P, E, C).
- **image_map.c** – Renderiza el mapa cargando los sprites correspondientes desde archivos `.xpm`.
- **move.c** – Gestiona el movimiento del jugador y actualiza los pasos y el estado del juego.
- **read.c** – Lee el contenido del archivo `.ber` y lo transforma en una estructura de mapa jugable.
- **start.c** – Inicializa la ventana, las imágenes y las estructuras del juego con MiniLibX.
- **utils.c** – Funciones auxiliares generales (errores, memoria, contadores).
- **utils_map.c** – Funciones de apoyo específicas para trabajar con el mapa (copias, comparaciones, conteo de elementos).
- **close.c** – Libera memoria y cierra correctamente el juego cuando el jugador sale o ocurre un error.
- **so_long.h** – Archivo de cabecera con las estructuras, macros y prototipos usados en el proyecto.
- **maps/** – Carpeta que contiene mapas `.ber` de ejemplo para probar el juego.

---

## ✅ Reglas

- El mapa debe ser **rectangular**, estar completamente **cerrado por muros** (`1`), y contener exactamente:
  - **1 jugador (P)**
  - **1 salida (E)**
  - **Al menos 1 coleccionable (C)**
- El mapa debe tener solo los caracteres válidos: `0`, `1`, `C`, `E`, `P`, y salto de línea `\n`.
- El jugador no puede acceder a la salida sin recoger todos los objetos.
- No se permiten **leaks de memoria** ni cuelgues: el programa debe liberar correctamente todos los recursos.
- Solo se permite usar la **MiniLibX** como librería gráfica (sin SDL, OpenGL, etc.).
