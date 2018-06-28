#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static int sub(lua_State *L)
{
	int a = lua_tointeger(L,-2);
	int b = lua_tointeger(L,-1);
	lua_pushinteger(L, a-b);
	return 1;
}
int main(int argc, const char *argv[])
{
	lua_State *L;
	L = luaL_newstate();
	luaL_openlibs(L);

	lua_register(L,"mysub",sub);

	luaL_dofile(L, "calc.lua");
	lua_getglobal(L, "add");
	lua_pushinteger(L, 12);
	lua_pushinteger(L, 34);
	lua_pcall(L,2,1,0);

	printf("target:%d\n",lua_tointeger(L, -1));
	
	lua_getglobal(L,"ssu");
	lua_pushinteger(L,34);
	lua_pushinteger(L,5);
	lua_pcall(L,2,1,0);

	printf("sub target:%d\n",lua_tointeger(L, -1));
	lua_close(L);

	return 0;
		
}
