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
	end

Route118_OnLoad: @ 81F3DF3
	end

Route118_OnFrame: @ 81F3E0A
	.2byte 0

RestartFGGGM::
	compare VAR_MINIGAME_ID, 6
	goto_if_eq RestartMinigame
	compare VAR_MINIGAME_ID, 7
	goto_if_eq RestartMinigame2
	compare VAR_MINIGAME_ID, 8
	goto_if_eq ReturnToEntrance
	end

RestartMinigame:
	lockall
	setvar VAR_MINIGAME_ID, 7
	setvar VAR_COSTUME, 4
	fadescreen FADE_TO_BLACK
	msgbox FGGG, MSGBOX_DEFAULT
	special SwapPlayersCostume
	warp MAP_ROUTE122, 1, 1, 5
	waitstate
	releaseall
	end

RestartMinigame2:
	lockall
	setvar VAR_MINIGAME_ID, 8
	setvar VAR_COSTUME, 4
	fadescreen FADE_TO_BLACK
	msgbox FGGG, MSGBOX_DEFAULT
	special SwapPlayersCostume
	warp MAP_ROUTE122, 1, 1, 5
	waitstate
	releaseall
	end

ReturnToEntrance:
	lockall
	fadescreenspeed FADE_TO_BLACK, 1
	setvar VAR_COSTUME, 0
	releaseall
	warp MAP_PETALBURG_CITY, 17, 0, 0
	waitstate
	releaseall
	end

Night5::
	call DeleteFoxy
	setvar VAR_TEMP_0, 1
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
