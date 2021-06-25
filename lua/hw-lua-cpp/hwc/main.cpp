#include <iostream>
#include <lua.hpp>

using namespace std;

static int hello(lua_State *L) {
    cout << "hello world" << endl;
    return 0;
}


static const struct luaL_Reg mylib [] = {
    {"hello", hello},
    {NULL, NULL}
};

extern "C" int luaopen_mylib(lua_State *L) {
    luaL_newlib(L, mylib);
    return 1;
}
