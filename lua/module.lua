module = {};

module.var = "This is a variable"

function module.func1()
	print("This is a public function")
end

local function func2()
	print("This is a private function")
end

return module
