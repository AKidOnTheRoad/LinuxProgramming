#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
int main(int argc, char *argv[])
{
	lua_State *L ;//= lua_open();
	L = luaL_newstate();//create lua state

	luaL_openlibs(L); //打开lua状态机L中的所有Lua标准库
	luaL_dofile(L, "test.lua");//load target script,create a mapping table about lua
	lua_getglobal(L,"showinfo");//get function from the global varriable table , push the function
	lua_pcall(L,0,0,0);//excute function "showinfo"


	lua_getglobal(L,"lua_add");//get function lua_add
	lua_pushinteger(L,1);//push lua stack argument 1
	lua_pushinteger(L,5);//push lua stack argument 5
	lua_pcall(L,2,1,0);//excute function "lua_add"

	printf("lua add function return val is %d \n",lua_tointeger(L,-1));//get the return value from the top of stack

	lua_close(L);

	return 0;
}
