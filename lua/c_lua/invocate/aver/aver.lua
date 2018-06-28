--aver.lua 
function aver(...)
	sum = 0;
	for k,v in ipairs{...}
		do
			sum = sum + v;
		end
		return sum;
end

function myadd(...)
	print("DEBUG")
	print("arg[1]:" .. arg[1])
	return add(arg[1],arg[2]);
end
