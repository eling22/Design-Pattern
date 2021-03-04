FILES = $(wildcard *.c)
FILES_H = $(FILES:.c=.h)
all: run

get_h_file: $(FILES_H)

$(FILES_H):$(FILES)
	python ../create_h_file/create_h_file.py $*

compile: $(FILES)
	gcc -o test $(FILES)

run: compile
	.\test.exe

clean:
	del test.exe