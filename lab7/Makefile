1_producer_consumer: 1_producer_consumer.o stack.o
	gcc  -pthread 1_producer_consumer.o stack.o -o 1_producer_consumer

1_producer_consumer.o: 1_producer_consumer.c ../main.h stack.h
	gcc -g3 -O0 -Wall -c 1_producer_consumer.c

stack.o: stack.c ../main.h
	gcc -g3 -O0 -Wall -c stack.c

clean:
	rm -rf *.o 1_producer_consumer