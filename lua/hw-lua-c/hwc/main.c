#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"


static int hello(lua_State *L) {
    printf("hello world");
    return 0;
}


static const struct luaL_Reg mylib [] = {
    {"hello", hello},
    {NULL, NULL}
};

int luaopen_mylib(lua_State *L) {
    luaL_newlib(L, mylib);
    return 1;
}
