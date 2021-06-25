#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    luaL_dofile(L, "./helloworld.lua");


    lua_getglobal(L, "hello");
    lua_pcall(L,0,0,0);

    lua_close(L);
    return 0;
}

