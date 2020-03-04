all: interpreter

interpreter.o:
	gcc -c interpreter.c -I/usr/local/include/lua

interpreter: interpreter.o
	gcc interpreter.o -o interpreter

clean:
	rm -f *.o interpreter
