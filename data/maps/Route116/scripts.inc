.set LOCALID_SHADOW_FREDDY, 1

Route116_MapScripts:: @ 81F2C0C
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	.byte 0

Route116_OnTransition: @ 81F2C1C

	end


Route116_OnLoad: @ 81F2C4F
	end

Route116_OnFrame: @ 81F2C66
	map_script_2 VAR_TEMP_0, 0, GoUpInfinetly
	.2byte 0

GoUpInfinetly:
	compare VAR_ANIMATRONIC_ID, 5
	goto_if_eq Reset
	addobject LOCALID_SHADOW_FREDDY
	lockall
	msgbox Follower, MSGBOX_DEFAULT
	releaseall
	lockall
	applymovement LOCALID_SHADOW_FREDDY, GoingUp
	waitmovement 0
	removeobject LOCALID_SHADOW_FREDDY
	setflag FLAG_LAST_IN_KITCHEN
	setvar VAR_TEMP_0, 1
	releaseall
	end
