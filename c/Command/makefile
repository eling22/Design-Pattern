DIR = interface
all: run

compile: *.c $(DIR)/*.c
	gcc -o test *.c $(DIR)/*.c

run: compile
	.\test.exe

clean:
	del test.exe