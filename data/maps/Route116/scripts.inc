Route116_MapScripts:: @ 81F2C0C
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	.byte 0

Route116_OnTransition: @ 81F2C1C
	call_if_set FLAG_LAST_IN_ROOM_R, TrueReset
	call_if_set FLAG_LAST_IN_ROOM_S, TrueReset
	call_if_set FLAG_LAST_IN_CORRIDOR_R, TrueReset
	clearflag FLAG_LAST_IN_CORRIDOR_R
	clearflag FLAG_LAST_IN_ROOM_S
	clearflag FLAG_LAST_IN_ROOM_R
	end


Route116_OnLoad: @ 81F2C4F
	end

Route116_OnFrame: @ 81F2C66
	map_script_2 VAR_KEEP_AT_0, 0, ShadowFreddyYee
	map_script_2 VAR_KEEP_AT_0, 1, ContinueShadowFreddyYee
	.2byte 0

ShadowFreddyYee:
	compare VAR_ANIMATRONIC_ID, 5
	goto_if_eq Reset
	goto_if_set FLAG_LAST_IN_KITCHEN, Reset
	setvar VAR_KEEP_AT_0, 1
	lockall
	getplayerxy VAR_PLAYER_X, VAR_PLAYER_Y
	setflag	FLAG_SPAWN_INVISIBLE
	fadescreenspeed FADE_TO_BLACK, 1
	warpsilent MAP_ROUTE116, 0xFF, 5, 5
	waitstate
	end

ContinueShadowFreddyYee:
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
	setflag FLAG_LAST_IN_KITCHEN
	warpsilent MAP_ROUTE116, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	setvar VAR_KEEP_AT_0, 0
	releaseall
	end


WelcomeToTheFazZone::
	addobject LOCALID_SHADOW_FREDDY
	lockall
	msgbox Follower, MSGBOX_DEFAULT
	releaseall
	lockall
	applymovement LOCALID_SHADOW_FREDDY, GoingDown
	waitmovement 0
	removeobject LOCALID_SHADOW_FREDDY
	return
	end

ToInfinityAndBeyond::
	addobject LOCALID_SHADOW_FREDDY
	lockall
	msgbox Follower, MSGBOX_DEFAULT
	releaseall
	lockall
	applymovement LOCALID_SHADOW_FREDDY, GoingUp
	waitmovement 0
	removeobject LOCALID_SHADOW_FREDDY
	return
	end

GoRightToThePoint::
	addobject LOCALID_SHADOW_FREDDY
	lockall
	msgbox Follower, MSGBOX_DEFAULT
	releaseall
	lockall
	applymovement LOCALID_SHADOW_FREDDY, GoingRight
	waitmovement 0
	removeobject LOCALID_SHADOW_FREDDY
	return
	end