-- filesample.lua
file = io.open("test.txt","a+")
io.output(file);
string = io.read();
io.write(string .. "\n");
