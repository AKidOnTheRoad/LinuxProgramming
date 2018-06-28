co = coroutine.create(
	function()
		for i=1,10 do
			print("___________________")
			print(i)
			if i == 3 then
				print(coroutine.status(co))
				print(coroutine.running())
				break
			end
			coroutine.yield(i)
		end
	end
)

print(coroutine.resume(co))
print(coroutine.resume(co))
print(coroutine.resume(co))

print(coroutine.status(co))
