#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

/************************************************************************/
/*  Function Name   : main                                              */
/*  Description     :                                                   */
/*  Input(s)        : argc            - The numbers of input value.     */
/*                  : **argv          - The input specific parameters.  */
/*  Output(s)       : NULL                                              */
/*  Returns         : 0                                                 */
/************************************************************************/
#define For_Debug 1
#define Macro(m) {#m, m}
struct debug_t {
	char *name;
	int value;
};

int main(int argc, const char *argv[])
{
	
	lua_State *L;
	L = luaL_newstate();

	luaL_openlibs(L);

	luaL_dofile(L, "setfield.lua");
	lua_getglobal(L,"cmarco");
	lua_pushinteger(L, 12);
	lua_setfield(L, -2, "abc");
	lua_pop(L, 1);

	lua_getglobal(L, "pp");
	lua_pushstring(L, "abc");
	lua_pcall(L, 1, 0, 0);

	lua_close(L);

	struct debug_t debug = Macro(For_Debug);
	printf("name:%s\n",debug.name);
	return 0;
}
