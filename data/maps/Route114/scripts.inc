.set LOCALID_AFTON, 6
.set LOCALID_SCRAP_FREDDY, 2
.set LOCALID_SCRAP_BONNIE, 4
.set LOCALID_SCRAP_CHICA, 3
.set LOCALID_SCRAP_FOXY, 5
.set LOCALID_SHADOW_FREDDY, 1
.set LOCALID_FREDDY, 7
.set LOCALID_BONNIE, 8
.set LOCALID_CHICA, 9
.set LOCALID_FOXY, 10

Route114_OnFrame: @ 81F2578
	map_script_2 VAR_TURNED_HIMSELF_INTO_SCRAPS, 1, TurnedHimselfIntoScraps
	map_script_2 VAR_KEEP_AT_0, 0, ShadowFreddyCutscene
	map_script_2 VAR_KEEP_AT_0, 1, ContinueShadowFreddyCutscene
	.2byte 0

Route114_OnLoad: @ 81F256
	end

Route114_OnTransition:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	compare VAR_MINIGAME_ID, 5
	goto_if_eq Deletehim
	setvar VAR_ROOM_IN_NOW, 0
	setvar VAR_SFREDDY_FACING, 1
	compare VAR_KEEP_AT_0, 2
	goto_if_eq CheckBeenIn114
	end

CheckBeenIn114::
	goto_if_unset FLAG_BEEN_IN_BATHROOMS, StartRoom
	end

CheckBeenIn115::
	goto_if_unset FLAG_BEEN_IN_ROOM_R, StartRoom
	end

CheckBeenIn116::
	goto_if_unset FLAG_BEEN_IN_KITCHEN, StartRoom
	end

CheckBeenIn117::
	goto_if_unset FLAG_BEEN_IN_ROOM_S, StartRoom
	end

CheckBeenIn119::
	goto_if_unset FLAG_BEEN_IN_CORRIDOR_L, StartRoom
	end

CheckBeenIn121::
	goto_if_unset FLAG_BEEN_IN_CORRIDOR_R, StartRoom
	end

StartRoom::
	setvar VAR_KEEP_AT_0, 0
	end

Reset::
	setvar VAR_KEEP_AT_0, 2
	end

Follower::
	.string "FOLLOW ME$"

GoingUp::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

GoingDown::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	step_end

GoingRight::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	step_end

TrueReset::
	setvar VAR_KEEP_AT_0, 0
	return
	end

Deletehim::
	end


ShadowFreddyCutscene::
	compare VAR_MINIGAME_ID, 5
	goto_if_eq Reset
	setvar VAR_KEEP_AT_0, 1
	lockall
	getplayerxy VAR_PLAYER_X, VAR_PLAYER_Y
	setflag	FLAG_SPAWN_INVISIBLE
	fadescreenspeed FADE_TO_BLACK, 1
	switch VAR_ROOM_IN_NOW
	case 0, SF114
	case 1, SF115
	case 2, SF116
	case 3, SF117
	case 4, SF119
	case 5, SF121
	waitstate
	end

SF114:
	setflag FLAG_BEEN_IN_BATHROOMS
	warpsilent MAP_ROUTE114, 0xFF, 3, 5
	waitstate
	end

SF115:
	setflag FLAG_BEEN_IN_ROOM_R
	warpsilent MAP_ROUTE115, 0xFF, 8, 5
	waitstate
	end

SF116:
	setflag FLAG_BEEN_IN_KITCHEN
	warpsilent MAP_ROUTE116, 0xFF, 8, 5
	waitstate
	end

SF117:
	setflag FLAG_BEEN_IN_ROOM_S
	warpsilent MAP_ROUTE117, 0xFF, 8, 5
	waitstate
	end

SF119:
	setflag FLAG_BEEN_IN_CORRIDOR_L
	warpsilent MAP_ROUTE119, 0xFF, 8, 6
	waitstate
	end

SF121:
	setflag FLAG_BEEN_IN_CORRIDOR_R
	warpsilent MAP_ROUTE121, 0xFF, 3, 14
	waitstate
	end

ContinueShadowFreddyCutscene::
	lockall
	setvar VAR_KEEP_AT_0, 2
	compare VAR_MINIGAME_ID, 1
	call_if_eq RemoveNotFreddy
	compare VAR_MINIGAME_ID, 2
	call_if_eq RemoveNotBonnie
	compare VAR_MINIGAME_ID, 3
	call_if_eq RemoveNotChica
	compare VAR_MINIGAME_ID, 4
	call_if_eq RemoveNotFoxy
	fadescreenspeed FADE_FROM_BLACK, 1
	call GototheDoor
	fadescreenspeed FADE_TO_BLACK, 1
	applymovement OBJ_EVENT_ID_PLAYER, MakeVisible
	switch VAR_ROOM_IN_NOW
	case 0, WarpBack114
	case 1, WarpBack115
	case 2, WarpBack116
	case 3, WarpBack117
	case 4, WarpBack119
	case 5, WarpBack121
	releaseall
	end

WarpBack114:
	warpsilent MAP_ROUTE114, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	waitstate
	end

WarpBack115:
	warpsilent MAP_ROUTE115, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	waitstate
	end

WarpBack116:
	warpsilent MAP_ROUTE116, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	waitstate
	end

WarpBack117:
	warpsilent MAP_ROUTE117, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	waitstate
	end

WarpBack119:
	warpsilent MAP_ROUTE119, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	waitstate
	end

WarpBack121:
	warpsilent MAP_ROUTE121, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	waitstate
	end

RemoveNotFreddy::
	lockall
	addobject LOCALID_FREDDY
	setobjectxy LOCALID_FREDDY, VAR_PLAYER_X, VAR_PLAYER_Y
	return
	end

RemoveNotBonnie::
	lockall
	addobject LOCALID_BONNIE
	setobjectxy LOCALID_BONNIE, VAR_PLAYER_X, VAR_PLAYER_Y
	return
	end

RemoveNotChica::
	lockall
	addobject LOCALID_CHICA
	setobjectxy LOCALID_CHICA, VAR_PLAYER_X, VAR_PLAYER_Y
	return
	end

RemoveNotFoxy::
	lockall
	addobject LOCALID_FOXY
	setobjectxy LOCALID_FOXY, VAR_PLAYER_X, VAR_PLAYER_Y
	return
	end

GototheDoor:
	addobject LOCALID_SHADOW_FREDDY
	lockall
	msgbox Follower, MSGBOX_DEFAULT
	releaseall
	lockall
	compare VAR_SFREDDY_FACING, 0
	call_if_eq GoUpwards
	compare VAR_SFREDDY_FACING, 1
	call_if_eq GoDoor
	compare VAR_SFREDDY_FACING, 2
	call_if_eq GoDown
	compare VAR_SFREDDY_FACING, 3
	call_if_eq GoRight
	waitmovement 0
	removeobject LOCALID_SHADOW_FREDDY
	return
	end

GoDoor:
	applymovement LOCALID_SHADOW_FREDDY, GoingDoor
	return
	end

GoUpwards:
	applymovement LOCALID_SHADOW_FREDDY, GoingUp
	return
	end

GoDown:
	applymovement LOCALID_SHADOW_FREDDY, GoingDown
	return
	end

GoRight:
	applymovement LOCALID_SHADOW_FREDDY, GoingRight
	return
	end

GoingDoor:
	walk_up
	walk_up
	walk_up
	step_end

Route114_MapScripts:: @ 81F252F
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_OnFrame
	.byte 0

ItsBonnie:
	msgbox YOURE_GOING_TO_HORNY_JAIL, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, BonnieWalk
	waitmovement 0
	msgbox RESTARTING, MSGBOX_DEFAULT
	addobject LOCALID_AFTON
	applymovement LOCALID_AFTON, Movement_From_Door_Afton_Bo
	waitmovement 0
	fadescreenspeed FADE_TO_BLACK, 1
	setflag FLAG_SPAWN_INVISIBLE
	clearflag FLAG_HIDE_BONNIE_SCRAPS
	call OhShit
	end

OhShit:
	getplayerxy VAR_PLAYER_X, VAR_PLAYER_Y
	setvar VAR_TURNED_HIMSELF_INTO_SCRAPS, 1
	clearflag FLAG_BEEN_IN_BATHROOMS
	setvar VAR_KEEP_AT_0, 0
	releaseall
	warpsilent MAP_ROUTE114, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	waitstate
	end


TurnedHimselfIntoScraps:
	lockall
	delay 24
	fadescreenspeed FADE_TO_BLACK, 1
	applymovement OBJ_EVENT_ID_PLAYER, MakeVisible
	waitmovement 0
	setvar VAR_TURNED_HIMSELF_INTO_SCRAPS, 0
	setvar VAR_COSTUME, 0
	releaseall
	warp MAP_PETALBURG_CITY, 17, 0, 0
	waitstate
	end

MotionTrigger::
	lockall
	compare VAR_MINIGAME_ID, 1
	goto_if_eq ItsFreddy
	compare VAR_MINIGAME_ID, 2
	goto_if_eq ItsBonnie
	compare VAR_MINIGAME_ID, 3
	goto_if_eq ItsChica
	compare VAR_MINIGAME_ID, 4
	goto_if_eq ItsFoxy
	releaseall
	end

ItsFreddy:
	msgbox YOURE_GOING_TO_HORNY_JAIL, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, FreddyWalk
	waitmovement 0
	msgbox RESTARTING, MSGBOX_DEFAULT
	addobject LOCALID_AFTON
	applymovement LOCALID_AFTON, Movement_From_Door_Afton_Fd
	waitmovement 0
	fadescreenspeed FADE_TO_BLACK, 1
	setflag FLAG_SPAWN_INVISIBLE
	clearflag FLAG_HIDE_FREDDY_SCRAPS
	call OhShit
	end

ItsChica:
	msgbox YOURE_GOING_TO_HORNY_JAIL, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ChicaWalk
	waitmovement 0
	msgbox RESTARTING, MSGBOX_DEFAULT
	addobject LOCALID_AFTON
	applymovement LOCALID_AFTON, Movement_From_Door_Afton_Ch
	waitmovement 0
	fadescreenspeed FADE_TO_BLACK, 1
	setflag FLAG_SPAWN_INVISIBLE
	clearflag FLAG_HIDE_CHICA_SCRAPS
	call OhShit
	end

ItsFoxy:
	msgbox YOURE_GOING_TO_HORNY_JAIL, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, FoxyWalk
	waitmovement 0
	msgbox RESTARTING, MSGBOX_DEFAULT
	addobject LOCALID_AFTON
	applymovement LOCALID_AFTON, Movement_From_Door_Afton_Fx
	waitmovement 0
	fadescreenspeed FADE_TO_BLACK, 1
	setflag FLAG_SPAWN_INVISIBLE
	clearflag FLAG_HIDE_FOXY_SCRAPS
	call OhShit
	end


MakeVisible:
	set_visible
	step_end

FreddyWalk:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BonnieWalk:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

ChicaWalk:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

FoxyWalk:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

Movement_From_Door_Afton_Bo:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

Movement_From_Door_Afton_Ch:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	step_end

Movement_From_Door_Afton_Fx:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

Movement_From_Door_Afton_Fd:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

YOURE_GOING_TO_HORNY_JAIL: @ 81F2809
	.string "ERROR\n"
	.string "Attempted to enter\l"
	.string "UNKNOWN area.\p"
	.string "Executing autonomous protocol.$"

RESTARTING:
	.string "Restarting BIOS.$"
