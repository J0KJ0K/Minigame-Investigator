.set LOCALID_SHADOW_FREDDY, 1


Route121_MapScripts:: @ 81F5DFC
	map_script MAP_SCRIPT_ON_TRANSITION, Route121_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_OnFrame
	.byte 0

Route121_OnTransition:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	compare VAR_ANIMATRONIC_ID, 5
	goto_if_eq Deletehim
	setvar VAR_ROOM_IN_NOW, 5
	setvar VAR_SFREDDY_FACING, 0
	compare VAR_KEEP_AT_0, 2
	goto_if_eq CheckBeenIn121
	end

Route121_OnFrame:
	map_script_2 VAR_KEEP_AT_0, 0, ShadowFreddyCutscene
	map_script_2 VAR_KEEP_AT_0, 1, ContinueShadowFreddyCutscene
	.2byte 0
	


