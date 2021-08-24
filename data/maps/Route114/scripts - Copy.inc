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

ShadowFreddyCutscene:
	compare VAR_ANIMATRONIC_ID, 5
	goto_if_eq Reset
	goto_if_set FLAG_LAST_IN_BATHROOMS, Reset
	setvar VAR_KEEP_AT_0, 1
	lockall
	getplayerxy VAR_PLAYER_X, VAR_PLAYER_Y
	setflag	FLAG_SPAWN_INVISIBLE
	fadescreenspeed FADE_TO_BLACK, 1
	warpsilent MAP_ROUTE114, 0xFF, 3, 5
	waitstate
	end

ContinueShadowFreddyCutscene:
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
	call GototheDoor
	fadescreenspeed FADE_TO_BLACK, 1
	applymovement OBJ_EVENT_ID_PLAYER, MakeVisible
	setflag FLAG_LAST_IN_BATHROOMS
	setflag FLAG_LAST_IN_ROOM_R
	warpsilent MAP_ROUTE114, 0xFF, VAR_PLAYER_X, VAR_PLAYER_Y
	releaseall
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
	applymovement LOCALID_SHADOW_FREDDY, GoingDoor
	waitmovement 0
	removeobject LOCALID_SHADOW_FREDDY
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

Route114_OnLoad: @ 81F256
	end

Route114_OnTransition:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	compare VAR_ANIMATRONIC_ID, 5
	goto_if_eq Deletehim
	clearflag FLAG_LAST_IN_ROOM_R
	end

TrueReset::
	setvar VAR_KEEP_AT_0, 0
	return
	end

MotionTrigger::
	lockall
	compare VAR_ANIMATRONIC_ID, 1
	goto_if_eq ItsFreddy
	compare VAR_ANIMATRONIC_ID, 2
	goto_if_eq ItsBonnie
	compare VAR_ANIMATRONIC_ID, 3
	goto_if_eq ItsChica
	compare VAR_ANIMATRONIC_ID, 4
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