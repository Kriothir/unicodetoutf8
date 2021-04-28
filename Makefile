all: build run

build:
	 gcc -m32 main.c pretvori.c -o demo_pretvori

run:
	./demo_pretvori 221A

test:
	echo "A to sploh dela?"

setup:
	main.c pretvori.c pretvori.h 

clean:
	rm -f demo_pretvori


