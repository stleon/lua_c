#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "luaxlib.h"
#include "lualib.h"

int main(void) {
        char buff[256];
        int error;
        lua_State *L = luaL_newstate(); /* open Lua */
        luaL_openlibs(L); /* open std libs */

        while (fgets(buff, sizeof(buff), stdin) != NULL) {
                error = liaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);
                if (error) {
                        fprintf(stderr, "%s\n", lua_tostring(L, -1));
                        lua_pop(L, 1); /* pop error message from stack */
                }
        }
        lua_close(L);
        return 0;
}
