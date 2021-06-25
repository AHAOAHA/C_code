.PHONY:all
all:main
main:main.c
	gcc $^ -o $@ -std=c99 -fPIC -shared -o mylib.so
.PHONY:clean
clean:
	rm -rf main
