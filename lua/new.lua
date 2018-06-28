--new.lua
Dog = {}
function Dog.new(self,x)
print("i am a dog")
end

mydog = Dog:new(function() print("What the fuck.") end)
