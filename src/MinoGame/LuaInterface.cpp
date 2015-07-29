/*
** Lua binding: LuaInterface
** Generated automatically by tolua++-1.0.93 on Thu Sep 25 21:29:14 2014.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_LuaInterface_open (lua_State* tolua_S);

#include <MinoGL/GUI.hpp>
#include <MinoGame/Game.hpp>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_MinoGL__GUI (lua_State* tolua_S)
{
 MinoGL::GUI* self = (MinoGL::GUI*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"MinoGL::GUI");
}

/* method: getInstance of class  MinoGL::GUI */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_MinoGL_GUI_getInstance00
static int tolua_LuaInterface_MinoGL_GUI_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MinoGL::GUI",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MinoGL::GUI tolua_ret = (MinoGL::GUI)  MinoGL::GUI::getInstance();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((MinoGL::GUI)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"MinoGL::GUI");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(MinoGL::GUI));
     tolua_pushusertype(tolua_S,tolua_obj,"MinoGL::GUI");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: notifyEvent of class  MinoGL::GUI */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_MinoGL_GUI_notifyEvent00
static int tolua_LuaInterface_MinoGL_GUI_notifyEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MinoGL::GUI",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MinoGL::GUI* self = (MinoGL::GUI*)  tolua_tousertype(tolua_S,1,0);
  std::string event = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'notifyEvent'", NULL);
#endif
  {
   self->notifyEvent(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'notifyEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LuaInterface_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"MinoGL",0);
  tolua_beginmodule(tolua_S,"MinoGL");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GUI","MinoGL::GUI","",tolua_collect_MinoGL__GUI);
   #else
   tolua_cclass(tolua_S,"GUI","MinoGL::GUI","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GUI");
    tolua_function(tolua_S,"getInstance",tolua_LuaInterface_MinoGL_GUI_getInstance00);
    tolua_function(tolua_S,"notifyEvent",tolua_LuaInterface_MinoGL_GUI_notifyEvent00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaInterface (lua_State* tolua_S) {
 return tolua_LuaInterface_open(tolua_S);
}
#endif

