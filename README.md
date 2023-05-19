# ProducerConsumerSimulation

[Producer-consumer problem](https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem) is a multithreaded problem, where a producer and consumer threads share the same buffer that is a fixed-size array. The gist of the problem is to prevent the consumer from taking an item from the array when the array is empty, or the producer from adding an item to the array when the array is full. This project is a simulation of a certain number of producers putting values into the array while consumers taking it out without an error. 

## Running The Project In Linux

Use the make file by typing ```make``` in the terminal while in the project's root directory. The makefile will generate an executable named ```main``` in the project directory. 

To run the program, type ```main <length-of-execution-in-seconds> <number-of-producers> <number-of-consumers>``` in the terminal when you are in the project's root directory. 

## Input Parameters

All input parameters are positive integers.<br />
```<length-of-execution-in-seconds>```: the number of seconds the simulation will last.<br />
```<number-of-producers>```: the total number of producers that will add items to the array.<br />
```<number-of-consumers>```: the number of consumers that will take items from the array.<br />

## How Does The Program Work

```buffer.h``` and ```buffer.c``` files implement the shared circular array, which will be accessed by producer and consumer threads. The functions ```insert_item``` and ```remove_item``` inserts or removes items into/from the array.

```producer``` simulates the producer and sleeps for random periods of time. It generates random items, which is a large integer. It uses the semaphore to be the only thread performing operations on the buffer array. It locks the mutex, places an item to the array, then unlocks the mutex. 

```consumer``` simulates the consumer and sleeps for random periods of time. It removes items from the buffer array. It locks the mutex, removes an item from the array, then unlocks the mutex.

Each action in the simulation will be displayed to the terminal.