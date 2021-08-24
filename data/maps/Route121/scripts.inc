.set LOCALID_SHADOW_FREDDY, 1


Route121_MapScripts:: @ 81F5DFC
	map_script MAP_SCRIPT_ON_TRANSITION, Route121_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_OnFrame
	.byte 0

Route121_OnTransition:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	compare VAR_ANIMATRONIC_ID, 5
	goto_if_eq Deletehim
	end

Route121_OnFrame:
		.2byte 0
	


