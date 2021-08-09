.set LOCALID_SHADOW_FREDDY, 1


Route121_MapScripts:: @ 81F5DFC
	map_script MAP_SCRIPT_ON_TRANSITION, Route121_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_OnFrame
	.byte 0

Route121_OnTransition:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	compare VAR_ANIMATRONIC_ID, 5
	goto_if_eq Deletehim
	call_if_set FLAG_LAST_IN_KITCHEN, TrueReset
	call_if_set FLAG_LAST_IN_OFFICE, TrueReset
	clearflag FLAG_LAST_IN_KITCHEN
	clearflag FLAG_LAST_IN_OFFICE
	end

Route121_OnFrame:
	map_script_2 VAR_KEEP_AT_0, 0, ShadowFreddyNEEET
	map_script_2 VAR_KEEP_AT_0, 1, ContinueShadowFreddyNEEET
		.2byte 0
	

ShadowFreddyNEEET:
	compare VAR_ANIMATRONIC_ID, 5
	goto_if_eq Reset
	goto_if_set FLAG_LAST_IN_CORRIDOR_R, Reset
	setvar VAR_KEEP_AT_0, 1
	lockall
	getplayerxy VAR_PLAYER_X, VAR_PLAYER_Y
	setflag	FLAG_SPAWN_INVISIBLE
	fadescreenspeed FADE_TO_BLACK, 1
	warpsilent MAP_ROUTE121, 0xFF, 3, 14
	waitstate
	end

ContinueShadowFreddyNEEET:
	lockall
	setvar VAR_KEEP_AT_0, 2
	compare VAR_ANIMATRONIC_ID, 1
	call_if_eq RemoveNotFreddy
	compare VAR_ANIMATRONIC_ID, 2
	call_if_eq RemoveNotBonnie
	compare VAR_ANIMATRONIC_ID, 3
	call_if_eq RemoveNotChica
	compare VAR_ANIMATRONIC_ID, 4
	call_if_eq RemoveNotFoxy
	fadescreenspeed FADE_FROM_BLACK, 1
	call ToInfinityAndBeyond
	fadescreenspeed FADE_TO_BLACK, 1
	applymovement OBJ_EVENT_ID_PLAYER, MakeVisible
	setflag FLAG_LAST_IN_CORRIDOR_R
	warpsilent MAP_ROUTE121, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	setvar VAR_KEEP_AT_0, 0
	releaseall
	end