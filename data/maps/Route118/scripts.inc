Route118_MapScripts:: @ 81F3DBC
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition: @ 81F3DCC
	compare VAR_MINIGAME_ID, 4
	call_if_eq DeleteFoxy
	compare VAR_MINIGAME_ID, 5
	call_if_eq Night5
	compare VAR_MINIGAME_ID, 6
	goto_if_eq IsFoxyGoGoGo1
	compare VAR_MINIGAME_ID, 7
	goto_if_eq IsFoxyGoGoGo1
	compare VAR_MINIGAME_ID, 8
	goto_if_eq IsFoxyGoGoGo
	setflag FLAG_HIDE_GHOSTS
	setflag FLAG_HIDE_CHILDREN
	end

Route118_OnLoad: @ 81F3DF3
	end

Route118_OnFrame: @ 81F3E0A
	.2byte 0

IsFoxyGoGoGo1:
	clearflag FLAG_HIDE_CHILDREN
	setflag FLAG_HIDE_GHOSTS
	end

IsFoxyGoGoGo:
	clearflag FLAG_HIDE_GHOSTS
	setflag FLAG_HIDE_CHILDREN
	end

Night5::
	call DeleteFoxy
	setflag FLAG_HIDE_GHOSTS
	setflag FLAG_HIDE_CHILDREN
	clearflag FLAG_HIDE_FOXY_SCRAPS
	setflag FLAG_BEEN_IN_KITCHEN
	setflag FLAG_BEEN_IN_BATHROOMS
	setflag FLAG_BEEN_IN_ROOM_S
	setflag FLAG_BEEN_IN_ROOM_R
	setflag FLAG_BEEN_IN_OFFICE
	setflag FLAG_BEEN_IN_CORRIDOR_R
	end
