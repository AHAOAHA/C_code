#include "t.h"

void f(struct A* stu) {
    stu->x = 10;
    int i = 0;
    for (i = 0; i < 10; i++) {
        stu->arc[i] = 'x';
    }
    for (i = 0; i < 10; i++) {
        stu->ari[i] = 9;
    }
}