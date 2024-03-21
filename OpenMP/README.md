# IntroPP2191932
# BinarySearch
![image](https://github.com/SC3UIS/IntroPP2191932/assets/91171649/a68b128b-d767-4fe8-bfd8-c4c1f0f1fe6e)


# Contenido

Dentro de cada directorio, encontrarás los siguientes archivos:

- **BinarySearch.c**: Este archivo contiene el código fuente en C de una implementación de búsqueda binaria.
- **omp_BinarySearch.c**: Este archivo contiene una versión paralelizada del código de búsqueda binaria utilizando OpenMP.
- **BinarySearch.sbatch**: Este archivo de secuencia de comandos SLURM se utiliza para ejecutar el programa en el clúster
- **output_BinarySearch.txt**: Este archivo contiene la salida generada por la ejecución del programa.

# Explicación del código

## Algoritmo de búsqueda binaria

La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en una lista ordenada. Funciona dividiendo repetidamente el espacio de búsqueda por la mitad y comparando el elemento buscado con el elemento en el medio de la lista. Si el elemento buscado es igual al elemento en el medio, se ha encontrado. Si el elemento buscado es menor, la búsqueda continúa en la mitad inferior de la lista. Si el elemento buscado es mayor, la búsqueda continúa en la mitad superior de la lista. Este proceso se repite hasta que se encuentre el elemento deseado o se determine que no está presente en la lista.

## pragma omp parallel for

`pragma omp parallel for` paraleliza el bucle externo del algoritmo de ordenamiento de burbuja, distribuyendo la ejecución del bucle entre múltiples hilos, mientras que las cláusulas `private` y `shared` se utilizan para gestionar las variables privadas y compartidas entre los hilos, respectivamente. Esto permite que el algoritmo de ordenamiento se ejecute más rápido al utilizar múltiples hilos para procesar los datos en paralelo.

# Resultados obtenidos

Para las pruebas de rendimiento se usaron un tamaño de 5000 elementos y así mismo se uso ese tamaño para la generación aleatoria de números.

## Secuencial
Para la ejecución del programa se usó la siguiente secuencia de comandos:
```
[amalvareza@guaneExa OpenMP]$ srun -n 10 -w ExaDELL --pty /bin/bash
[amalvareza@ExaDELL OpenMP]$ gcc -fopenmp BinarySearch.c -o BinarySearch
[amalvareza@ExaDELL OpenMP]$ ./BinarySearch
```

Como output se tiene la `Lista Generada` y la `Lista ordenada` luego se tiene la key que se eligió aleatoriamente seguido de esto está la respuesta de si se encontró o no la Key, en este caso sí se encontró.
el tiempo empleado en la ejecución es el siguiente: 
```
Automatically chosen key: 615
Key found at index 607

Time taken: 0.042287 seconds

```
## Paralelo
Para la ejecución y visualización de resultados se usaron los siguientes comandos:
```
[amalvareza@ExaDELL OpenMP]$ sbatch BinarySearch.sbatch
[amalvareza@ExaDELL OpenMP]$ cat output_BinarySearch.txt
```
Como output se obtuvo lo siguiente:
```
Generating random elements...

Randomly selected key: 2104
Key not found
Total execution time: 0.015812 seconds
```
# Lo que se concluyó
Teniendo en cuenta que inicialmente se probó con los valores propuestos por el profesor (50 elementos) pero este número era muy pequeño y no se pudó notar una diferencia entre tiempos significativa, por lo cual
se optó por usar una lista de 5000 elementos(aunque se pudieron usar más) 

La paralelización del algoritmo mediante OpenMP ha permitido reducir significativamente el tiempo de ejecución. Aunque en este caso particular la clave no se encontró, el tiempo de ejecución fue menor en comparación con la ejecución secuencial.





