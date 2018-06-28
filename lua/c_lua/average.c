#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static int average(lua_State *L)
{
	int n = lua_gettop(L);
	double sum = 0;
	int i;
    /* loop through each argument */
	for (i = 1; i <= n; i++)
	{
		if (!lua_isnumber(L, i))
		{
			lua_pushstring(L, "Incorrect argument to 'average'");
			lua_error(L);
		}
		/* total the arguments */
		sum += lua_tonumber(L, i);
	}
	/* push the average */
	lua_pushnumber(L, sum / n); //第一个返回值
	/* push the sum */
	lua_pushnumber(L, sum); //第二个返回值
	/* return the number of results */
	return 2;
}

int main(int argc, const char *argv[])
{
	/*Initial lua stack*/
	lua_State *L ;//= lua_open();
	L = luaL_newstate();
	/*Load lua base library*/
	luaL_openlibs(L);

	/*register the c function*/
	lua_register(L, "average", average);

	/*run the script*/
	luaL_dofile(L, "average.lua");

	lua_close(L);
}
