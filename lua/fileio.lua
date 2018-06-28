file = io.open("debug.txt","a+");
while true do
	string = io.read();
	io.write(string)
	if (string == "q") then
		break
	end
	file:write(string)
end
file:close()
