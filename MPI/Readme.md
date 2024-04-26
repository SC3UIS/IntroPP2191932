# BinarySearch

![pngwing com (5)](https://github.com/SC3UIS/IntroPP2191932/assets/91171649/948c674f-8988-41e3-b65c-39ff8b185708)


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

Contenido
=========

Dentro de cada directorio, encontrarás los siguientes archivos:

`BinarySearch.c`: Este archivo contiene la implementación del algoritmo de búsqueda binaria.

`makefile`: Este archivo es un script de Makefile utilizado para compilar y construir el proyecto.

`mpi_BinarySearch`: Este archivo es un ejecutable compilado que implementa la búsqueda binaria utilizando MPI (Message Passing Interface).

`mpi_BinarySearch.c`: Este archivo contiene la implementación de la búsqueda binaria utilizando MPI.

`mpi_BinarySearch.sbatch`: Este archivo es un script de lotes utilizado para enviar trabajos MPI al cluster.

`omp_BinarySearch`: Este archivo es un ejecutable compilado que implementa la búsqueda binaria utilizando OpenMP.

`omp_BinarySearch.c`: Este archivo contiene la implementación de la búsqueda binaria utilizando OpenMP.

Instrucciones de Compilación
=========
A continuación se describen los pasos necesarios para compilar el código proporcionado en el archivo `BinarySearch.c`. 

### 1. Ingresar al Entorno de MPI

Para comenzar, es necesario acceder a un entorno que sea compatible con MPI. En general, esto involucra el uso de comandos como `srun` para iniciar procesos MPI. Como ejemplo, puedes iniciar un entorno con 24 procesos de la siguiente manera:

```bash
srun -n X --pty /bin/bash
```	

Siendo `X` el numero de hilos a utilizar del cluster de GUANE 

### 2. Cargar los Módulos Necesarios

Luego, debemos cargar los módulos necesarios, o sea, el módulo OpenMPI:

```bash
module load devtools/mpi/openmpi/3.1.4
```

### 3. Limpieza y Compilación

Para compilar el programa, podemos utilizar el archivo Makefile que se proporciona. Pero debemos eliminar archivos temporales generados previamente, para eso ejecutamos un make clean:

```bash
make clean
```

Luego de la limpieza, procede a compilar el código utilizando el siguiente comando:

```bash
make
```

Podemos utilizar las flags que deseemos para diferentes niveles de optimización, como: `-O1`, `-O2`, `-O3`, `-Ofast`, `-Og`, etc.

## Ejecución Interactiva

Tenemos la posibilidad de ejecutar el programa de manera interactiva utilizando el comando `mpirun`. A continuación, se explican diversas alternativas para ejecutar el programa con distintas configuraciones iniciales y valores de tiempo. Asegúrate de haber seguido las indicaciones de compilación proporcionadas anteriormente antes de proceder.

###  Valores Predeterminados

Para iniciar el programa con la configuración estándar, emplea los siguientes comandos:

```bash
mpic++ mpi_BinarySearch.c -o mpi_BinarySearch
```
```bash
mpirun -np 4 ./mpi_BinarySearch ./time
```

## Ejecución en Modo Pasivo

Para llevar a cabo la ejecución del programa en modo pasivo mediante sbatch y asegurar la carga del módulo MPI recomendado antes de la ejecución, es necesario seguir este procedimiento:

### 1. Elaborar un Script de Trabajo

Generar un archivo de script de trabajo, por ejemplo, denominado `mpi_BinarySearch.sbatch`, utilizando un editor de texto. El contenido del archivo debe ser similar al siguiente ejemplo:
```bash
#!/bin/bash
#SBATCH --job-name=MPI_BinarySearch
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=8
#SBATCH --output=output_mpi_BinarySearch.txt%j.out
#SBATCH --error=error_mpi_BinarySearch.err%j.err

# Cargar módulos de gcc y mpi
module load devtools/gcc/6.2.0
module load devtools/mpi/openmpi/3.1.4

# Compilar el archivo mpi_BinarySearch.c
mpicc mpi_BinarySearch.c -o mpi_BinarySearch

# Ejecutar el programa
mpiexec -np 2 ./mpi_BinarySearch
```

### 2. Envío del Trabajo a Slurm

Emplear el comando "sbatch" para enviar el trabajo a Slurm. El script será sometido y ejecutado de acuerdo con las configuraciones especificadas en el script de trabajo. Asegúrate de estar en el directorio donde el script se encuentra ubicado:

```bash 
sbatch mpi_BinarySearch.sbatch
```

Comparativa en tiempos de ejecución
=========

Se realizará una comparativa de tiempos de ejecución entre el archivo original, la versión usando openMP y la versión usando MPI.

`BinarySearch.c`
Output:
```
Automatically chosen key: 4511
Key found at index 4555

Time taken: 0.213603 seconds
```
`omp_BinarySearch.c`

Output:
```
Generating random elements...

Randomly selected key: 2566
Key not found
Total execution time: 0.019076 seconds

```

`mpi_BinarySearch.c`

Output:
```
Generating random elements...
Automatically chosen key: 1882
Key not found

Time taken: 0.018498 seconds
```

### Versión secuencial (BinarySearch.c):

Tiempo de ejecución: 0.213603 segundos.
Esta es la versión más lenta de las tres, ya que se ejecuta de manera secuencial en un solo hilo/proceso.


### Versión OpenMP (omp_BinarySearch.c):

Tiempo de ejecución: 0.019076 segundos.
Esta versión paralela utilizando OpenMP es significativamente más rápida que la versión secuencial, con un tiempo de ejecución aproximadamente 11 veces más rápido.
OpenMP aprovecha el paralelismo a nivel de subprocesos (threads).


### Versión MPI (mpi_BinarySearch.c):

Tiempo de ejecución: 0.018498 segundos.
Esta versión paralela utilizando MPI es ligeramente más rápida que la versión OpenMP, con un tiempo de ejecución aproximadamente 1.03 veces más rápido.
MPI aprovecha el paralelismo a nivel de procesos, lo que permite una mayor escalabilidad al distribuir el trabajo en varios nodos/máquinas.











