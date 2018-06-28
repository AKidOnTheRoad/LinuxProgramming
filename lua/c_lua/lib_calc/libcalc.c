#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int calc(lua_State *L)
{
	int num = lua_gettop(L);
	printf("argument%d\n", num);

	int a = lua_tointeger(L, -1);
	int b = lua_tointeger(L, -2);

	lua_pushinteger(L,(a+b));
	return 1;
}

int luaopen_libcalc(lua_State* L)
{
	lua_register(L,"add",calc);
	return 1;
}
