.PHONY:all
all:main
main:main.c
	gcc $^ -std=c99 -llua -lm -ldl -o $@
.PHONY:clean
clean:
	rm -rf main
