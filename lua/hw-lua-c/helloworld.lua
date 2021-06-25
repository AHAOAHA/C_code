#!lua

-- lua -> C

function hello()
    print("lua hello world");
end

local mylib = require("mylib");
mylib.hello(nil);
hello();
