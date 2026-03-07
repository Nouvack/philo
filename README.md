*This project has been created as part of the 42 curriculum by
nsantand.*

# Philosophers

## Description

The **Philosophers** project is an implementation of the classical
*Dining Philosophers Problem*, a well-known synchronization problem in
computer science. The goal of the project is to simulate philosophers
sitting around a table who alternately think, eat, and sleep while
sharing a limited number of forks.

The challenge of the problem lies in managing **concurrent access to
shared resources** (forks) using **threads and mutexes**, while avoiding
common concurrency issues such as:

-   Deadlocks
-   Race conditions
-   Starvation

Each philosopher is represented by a thread and must take two forks
(mutexes) before eating. A monitoring system continuously checks if a
philosopher dies (i.e., does not eat within a certain time limit) or if
all philosophers have eaten the required number of times.

The simulation stops when: - A philosopher dies, or - All philosophers
have eaten the required number of times (if specified).

This project focuses on **thread management, synchronization primitives,
and concurrency control using POSIX threads (pthreads).**

------------------------------------------------------------------------

## Instructions

### Compilation

Clone the repository and compile the program using:

    make

This will generate the executable:

    philo

### Usage

Run the program with the following arguments:

    ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

Example:

    ./philo 4 410 200 200 5

Parameters:

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
-   Central **monitor thread** to detect philosopher death
-   Custom **precision sleep function** to improve simulation timing
-   Protection against **race conditions**
-   Deadlock prevention strategy based on fork acquisition order
-   Optional termination when all philosophers are full

------------------------------------------------------------------------

## Technical Decisions

Several design choices were made to ensure safe and predictable
concurrency:

-   Each philosopher runs in an independent thread.
-   Forks are represented as **mutexes shared between adjacent
    philosophers**.
-   A dedicated **monitor thread** checks philosopher states and stops
    the simulation if a death is detected.
-   Access to shared data (e.g., `last_meal`, `stop` flag) is protected
    using mutexes.
-   A custom `ft_usleep()` function allows threads to wake early if the
    simulation stops.

These decisions aim to minimize CPU usage while maintaining accurate
timing and avoiding data races.

------------------------------------------------------------------------

## Resources

The following resources were consulted during the development of this
project:

-   The Dining Philosophers Problem --- Edsger W. Dijkstra
-   POSIX Threads Programming documentation
-   Linux pthreads manual pages
-   Operating Systems concepts on concurrency and synchronization

Documentation: -
https://man7.org/linux/man-pages/man3/pthread_create.3.html -
https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html
https://www.youtube.com/watch?v=LOfGJcVnvAk
https://www.youtube.com/watch?v=ldJ8WGZVXZk
https://es.wikipedia.org/wiki/Problema_de_la_cena_de_los_fil%C3%B3sofos
https://pacoportillo.es/informatica-avanzada/programacion-multiproceso/la-cena-de-los-filosofos/

### Use of AI

Artificial Intelligence tools were used during the development of this
project for:

-   Concept clarification regarding thread synchronization and mutex
    usage
-   Debugging assistance for race conditions and deadlocks
-   Explanations of Helgrind and Valgrind diagnostics
-   General code review and conceptual validation

All core implementation and design decisions were written and
implemented manually.
