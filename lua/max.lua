-- max.lua
function max(a,b)
	if (a > b) then
		result = a;
	else
		result = b;
	end

	return result
end

-- call function
   print("The max value of two arguments ", max(43,32));

