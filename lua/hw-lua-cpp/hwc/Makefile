.PHONY:all
all:main
main:main.cpp
	g++ $^ -o $@ -std=c++11 -fPIC -shared -o mylib.so
.PHONY:clean
clean:
	rm -rf main
