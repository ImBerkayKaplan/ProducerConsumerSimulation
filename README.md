# ProducerConsumerProblem

[Producer-consumer problem](https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem) is a problem, where a producer and consumer threads share the same buffer that is a fixed-size array. The gist of the problem is to prevent the consumer from taking an item from the buffer when the array is empty, or the producer from adding an item to the buffer when the array is full. 

## Compilation

Use the make file by simply typing ```make``` in the command line window while in the project directory. This directory will contain the “src” folder. Make will generate an executable named P-Cprogram in the project directory. 

## Execution

To run the program, type ```P-Cprogram <length-of-execution-in-seconds> <number-of-producers> <number-of-consumers>``` in the command line when you are in the project directory. ```<length-of-execution-in-seconds>``` is a positive integer, and the total number of seconds the producers will add an item to the buffer, and the consumers will take an item from the buffer. ```<number-of-producers>``` is a positive integer, and the total number of producers that will add an item to the buffer. ```<number-of-consumers>``` is a positive integer, and the total number of consumers that will take an item from the buffer. The output will be displayed in the command line window.
