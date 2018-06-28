--require.lua
local m_path = package.path;
--package.path = string.format("%s;./1/?.lua", m_path);

print(package.path)

require("debug.test");
test.mm(arg[1])

