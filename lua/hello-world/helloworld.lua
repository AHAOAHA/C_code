#!lua
package.cpath = "./?.so"

local path = "/home/ahaoo/dev/own/demo-code/lua/hello-world/mylib.so"

local hello = package.loadlib(path,"luaopen_mylib");

local mylib = require("mylib");
mylib.hello(nil);

hello();
