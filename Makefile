interpreter.o:
	gcc -c interpreter.c -llua -L/usr/local/Cellar/lua/5.3.5_1/lib -I/usr/local/Cellar/lua/5.3.5_1/include/lua/

interpreter: interpreter.o
	gcc interpreter.o -o interpreter
