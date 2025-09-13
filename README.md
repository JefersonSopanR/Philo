# Philo

A C implementation of the classic Dining Philosophers problem. This project demonstrates process/thread synchronization and resource sharing using mutexes and timing functions.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Files](#files)
- [License](#license)

## Description
The Dining Philosophers problem is a classic synchronization problem involving philosophers sitting at a table, alternating between thinking and eating. Each philosopher needs two forks to eat, and the challenge is to prevent deadlocks and starvation.

This project solves the problem using C, pthreads, and mutexes.

## Features
- Multi-threaded simulation of philosophers
- Mutex-based fork management
- Deadlock avoidance
- Configurable parameters (number of philosophers, time to die/eat/sleep)

## Requirements
- GCC or Clang
- Make
- Linux (tested)

## Installation
1. Clone the repository:
   ```bash
   git clone <repo-url>
   cd Philo
   ```
2. Build the project:
   ```bash
   make
   ```

## Usage
Run the program with the following arguments:
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
Example:
```
./philo 5 800 200 200
```

## Files
- `main.c`: Entry point and argument parsing
- `ft_init.c`: Initialization functions
- `ft_routine.c`: Philosopher routine logic
- `ft_helpers.c`: Helper functions
- `ft_free_data.c`: Memory management
- `utils.c`: Utility functions
- `philo.h`: Header file
- `Makefile`: Build instructions

## License
MIT License
