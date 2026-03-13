*This project has been created as part of the 42 curriculum by nsantand.*

# Philosophers

## Description

The **Philosophers** project is an implementation of the classical
*Dining Philosophers Problem*, a well-known synchronization problem in
computer science.

The objective of the project is to simulate philosophers sitting around
a table who alternately **think, eat, and sleep** while sharing a
limited number of forks.

The main challenge is managing **concurrent access to shared resources**
using **threads and mutexes**, while avoiding typical concurrency
problems such as:

-   Deadlocks
-   Race conditions
-   Starvation

Each philosopher is represented by a thread and must acquire two forks
(mutexes) before eating. A monitoring system continuously checks if a
philosopher dies (i.e., does not eat within a given time limit) or if
all philosophers have eaten the required number of times.

The simulation stops when:

-   A philosopher dies
-   All philosophers have eaten the required number of times (if
    specified)

This project focuses on **thread management, synchronization primitives,
and concurrency control using POSIX threads (pthreads).**

------------------------------------------------------------------------

## Instructions

### Compilation

Clone the repository and compile the program:

``` bash
make
```

This will generate the executable:

philo

### Usage

Run the program with:

``` bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

``` bash
./philo 4 410 200 200 5
```

  Argument                                    Description
  ------------------------------------------- -------------------------------------------------
  number_of_philosophers                      Number of philosophers (and forks)
  time_to_die                                 Time (ms) a philosopher can live without eating
  time_to_eat                                 Time (ms) a philosopher spends eating
  time_to_sleep                               Time (ms) a philosopher spends sleeping
  number_of_times_each_philosopher_must_eat   Optional limit for meals

------------------------------------------------------------------------

## Features

-   Multithreaded simulation using **POSIX threads**
-   Fork synchronization using **mutexes**
-   Dedicated **monitor thread** to detect philosopher death
-   Custom **precision sleep function**
-   Protection against **race conditions**
-   Deadlock prevention using different fork acquisition orders
-   Optional termination when all philosophers are full

------------------------------------------------------------------------

## Resources

The following resources were used while developing this project:

-   Edsger W. Dijkstra -- *Dining Philosophers Problem*
-   POSIX Threads documentation
-   Linux pthread manual pages

Documentation:

-   https://man7.org/linux/man-pages/man3/pthread_create.3.html
-   https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html
-   https://es.wikipedia.org/wiki/Problema_de_la_cena_de_los_fil%C3%B3sofos
-   https://pacoportillo.es/informatica-avanzada/programacion-multiproceso/la-cena-de-los-filosofos/

### Use of AI

Artificial Intelligence tools were used during the development of this
project for:

-   Clarifying concepts related to thread synchronization
-   Debugging race conditions and deadlocks
-   Interpreting Valgrind and Helgrind diagnostics
-   Reviewing code structure and concurrency logic

All core implementation and design decisions were written and
implemented manually.
