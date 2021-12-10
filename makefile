all: user_interface.o worker.o
	gcc -o user_interface user_interface.o
	gcc -o worker worker.o

user_interface.o: user_interface.c
	gcc -c user_interface.c

worker.o: worker.c
	gcc -c worker.c

run:
	./user_interface
	./worker

clean:
	rm *.o
	rm user_interface
	rm worker
