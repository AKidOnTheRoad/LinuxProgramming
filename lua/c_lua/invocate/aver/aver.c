#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static int add(lua_State *L)
{
	int a = lua_tointeger(L, -2);
	int b = lua_tointeger(L, -1);

	printf("a:%d\n   b:%d\n", a, b);
	lua_pushinteger(L, a+b);
	return 1;

}


int main(int argc, const char *argv[])
{
	lua_State *L;
	L = luaL_newstate();
	luaL_openlibs(L);

	lua_register(L, "add", add);

	luaL_dofile(L, "aver.lua");
	lua_getglobal(L,"aver");
	lua_pushinteger(L,12);
	lua_pushinteger(L,12);
	lua_pushinteger(L,12);
	lua_pcall(L,3,1,0);

	int num  = lua_tointeger(L,-1);
	printf("num:%d\n",num);

	lua_getglobal(L,"myadd");
	lua_pushinteger(L,12);
	lua_pushinteger(L,1);
	lua_pcall(L,2,1,0);

	printf("num:%d\n",lua_tointeger(L, -1));
	lua_close(L);

}
