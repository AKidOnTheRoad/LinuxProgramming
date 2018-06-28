--calc.lua

function add(...)
	local sum = 0
	for k, v in pairs{...} do
		sum = sum + v;
	end
	return sum
end

function ssu(a,b)
	return mysub(a,b)
end
