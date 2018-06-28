--fun.lua



function add(a)
	return function(h) return print(h) end
end

add(2)(2);
