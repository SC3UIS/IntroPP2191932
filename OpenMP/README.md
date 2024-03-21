# IntroPP2191932

## Contenido

Dentro de cada directorio, encontrarás los siguientes archivos:

- **BinarySearch.c**: Este archivo contiene el código fuente en C de una implementación de búsqueda binaria.
- **omp_BinarySearch.c**: Este archivo contiene una versión paralelizada del código de búsqueda binaria utilizando OpenMP.
- **BinarySearch.sbatch**: Este archivo de secuencia de comandos SLURM se utiliza para ejecutar el programa en el clúster
- **output_BinarySearch.txt**: Este archivo contiene la salida generada por la ejecución del programa.

## Explicación del código

# Algoritmo de búsqueda binaria

La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en una lista ordenada. Funciona dividiendo repetidamente el espacio de búsqueda por la mitad y comparando el elemento buscado con el elemento en el medio de la lista. Si el elemento buscado es igual al elemento en el medio, se ha encontrado. Si el elemento buscado es menor, la búsqueda continúa en la mitad inferior de la lista. Si el elemento buscado es mayor, la búsqueda continúa en la mitad superior de la lista. Este proceso se repite hasta que se encuentre el elemento deseado o se determine que no está presente en la lista.

# pragma omp parallel for

`pragma omp parallel for` paraleliza el bucle externo del algoritmo de ordenamiento de burbuja, distribuyendo la ejecución del bucle entre múltiples hilos, mientras que las cláusulas `private` y `shared` se utilizan para gestionar las variables privadas y compartidas entre los hilos, respectivamente. Esto permite que el algoritmo de ordenamiento se ejecute más rápido al utilizar múltiples hilos para procesar los datos en paralelo.


Ten en cuenta que para ejecutar el
