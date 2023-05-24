.set LOCALID_RIVAL, 16
.set LOCALID_RIVAL_ON_BIKE, 25
.set LOCALID_SCOTT, 43

Route119_MapScripts:: @ 81F4424
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route119_OnFrame
	.byte 0

Route119_OnTransition: @ 81F444D
	setflag FLAG_HIDE_MAP_NAME_POPUP
	compare VAR_MINIGAME_ID, 5
	goto_if_eq Deletehim
	setvar VAR_ROOM_IN_NOW, 4
	setvar VAR_SFREDDY_FACING, 2
	compare VAR_KEEP_AT_0, 2
	goto_if_eq CheckBeenIn119
	end

Route119_OnFrame: @ 81F2C66
	map_script_2 VAR_KEEP_AT_0, 0, ShadowFreddyCutscene
	map_script_2 VAR_KEEP_AT_0, 1, ContinueShadowFreddyCutscene
	.2byte 0
