# BinarySearch

<img width="226" alt="titleImage" src="https://github.com/SC3UIS/IntroPP2191932/assets/91171649/6272d2de-ab09-40c3-b6f3-480b2496818c">



## Algoritmo de búsqueda binaria

La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en una lista ordenada. Funciona dividiendo repetidamente el espacio de búsqueda por la mitad y comparando el elemento buscado con el elemento en el medio de la lista. Si el elemento buscado es igual al elemento en el medio, se ha encontrado. Si el elemento buscado es menor, la búsqueda continúa en la mitad inferior de la lista. Si el elemento buscado es mayor, la búsqueda continúa en la mitad superior de la lista. Este proceso se repite hasta que se encuentre el elemento deseado o se determine que no está presente en la lista.

| Paso | Descripción |
|------|-------------|
| 1.   | **Inicialización y Declaración de Variables:** Se definen diversas variables, como la constante de difusión `a`, los campos `current` y `previous` que indican la temperatura actual y previa, y otras variables para controlar el tiempo y la paralelización. |
| 2.   | **Inicialización de MPI:** Se inicia MPI (Message Passing Interface) para habilitar la comunicación y coordinación entre múltiples procesos que trabajan en paralelo. |
| 3.   | **Inicialización de Campos y Parámetros:** Se inicializan los campos de temperatura `current` y `previous`, y se establece el número de pasos de tiempo `nsteps` y otros parámetros relevantes. También se inicializa información sobre la paralelización. |
| 4.   | **Salida Inicial:** Se genera una salida que representa el campo de temperatura inicial y se escribe en un archivo. |
| 5.   | **Cálculo del Paso de Tiempo:** Se calcula el tamaño del paso de tiempo `dt` basado en las dimensiones de la malla y la constante de difusión `a`. Esto asegura que el proceso sea estable. |
| 6.   | **Evolución Temporal:** Se inicia un bucle que ejecuta la evolución de la temperatura a lo largo del tiempo. Durante cada iteración, se realiza una serie de pasos, incluyendo operaciones de intercambio de información, evolución del interior del dominio, actualización de la temperatura, operaciones de intercambio para sincronizar información, evolución del borde del dominio, guardar el campo de temperatura en archivos de imagen, guardar un "checkpoint" del estado actual y el intercambio de campos `current` y `previous`. |
| 7.   | **Medición del Tiempo:** Se mide el tiempo que ha tardado la iteración de la simulación. |
| 8.   | **Salida de Resultados Finales:** Se imprime el tiempo que tomó la simulación y se muestra un valor de referencia en la posición (5, 5) del campo de temperatura final. |
| 9.   | **Finalización y Limpieza:** Se escribe el campo de temperatura final en un archivo y se realiza una limpieza de recursos. MPI se cierra con `MPI_Finalize()`. |
