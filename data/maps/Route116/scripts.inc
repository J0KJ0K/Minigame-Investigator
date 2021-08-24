Route116_MapScripts:: @ 81F2C0C
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	.byte 0

Route116_OnTransition: @ 81F2C1C
	setflag FLAG_HIDE_MAP_NAME_POPUP
	compare	VAR_ANIMATRONIC_ID, 5
	goto_if_eq Deletehim
	end

Route116_OnLoad: @ 81F2C4F
	end

Route116_OnFrame: @ 81F2C66
	.2byte 0


