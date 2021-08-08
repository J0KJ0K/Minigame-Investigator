.set LOCALID_SHADOW_FREDDY, 1


Route121_MapScripts:: @ 81F5DFC
	map_script MAP_SCRIPT_ON_TRANSITION, Route121_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_OnFrame
	.byte 0

Route121_OnTransition:
	end
Route121_OnFrame:
	map_script_2 VAR_TEMP_0, 0, ShadowFreddyGoinUp
		.2byte 0
	
ShadowFreddyGoinUp:
	compare VAR_ANIMATRONIC_ID, 5
	goto_if_eq Reset
	addobject LOCALID_SHADOW_FREDDY
	lockall
	msgbox Follower, MSGBOX_DEFAULT
	releaseall
	lockall
	applymovement LOCALID_SHADOW_FREDDY, GoingUp
	applymovement LOCALID_SHADOW_FREDDY, GoingUp
	waitmovement 0
	removeobject LOCALID_SHADOW_FREDDY
	setflag FLAG_LAST_IN_CORRIDOR_R
	setvar VAR_TEMP_0, 1
	releaseall
	end
