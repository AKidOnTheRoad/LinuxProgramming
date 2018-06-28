#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
static int l_add(lua_State *L)
{
	double a = lua_tonumber(L, 1);
	double b = lua_tonumber(L, 2);
	lua_pushnumber(L, a+b);
	return 1;
}

int luaopen_libtest(lua_State *L)
{
	lua_register(L, "add", l_add);
	//lua_pushcfunction(L, l_add);
	//lua_setglobal(L, "add");

	return 1;
}
