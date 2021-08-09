.set LOCALID_PURPLE_MAN, 6
.set LOCALID_SPRINGBONNIE, 5
.set LOCALID_GHOST1, 1
.set LOCALID_GHOST2, 2
.set LOCALID_GHOST3, 3
.set LOCALID_GHOST4, 4

Route124_MapScripts:: @ 81F656C
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route124_OnFrame
	.byte 0

Route124_OnFrame:
	map_script_2 VAR_AFTON_STATE, 0, Running1
	@map_script_2 VAR_AFTON_STATE, 1, RunningAlways
	@map_script_2 VAR_AFTON_STATE, 2, ResetPositionY1
	@map_script_2 VAR_AFTON_STATE, 3, RunningAlways2
	@map_script_2 VAR_AFTON_STATE, 4, ResetPositionY2
	@map_script_2 VAR_AFTON_STATE, 5, Running4
	.2byte 0

Running1::
	lockall
	msgbox GET_AWAY, MSGBOX_DEFAULT
	releaseall
	setvar VAR_AFTON_STATE, 1
	end

RunningAlways:
	compare VAR_AFTON_X, 10
	goto_if_eq Change
	end

RunningAlways2:
	compare VAR_AFTON_X, 1
	goto_if_eq Change2
	end

Triggers::
	lockall
	getplayerxy VAR_PLAYER_X, VAR_PLAYER_Y
	setvar VAR_PLAYER_Y2, VAR_PLAYER_Y
	call Afton_Check_Y
	setvar VAR_PLAYER_X2, VAR_PLAYER_X
	call Afton_Check_X
	releaseall
	end

Afton_Check_X:
	compare VAR_PLAYER_X, VAR_PLAYER_X2
	call_if_eq Ok
	compare VAR_PLAYER_X, VAR_PLAYER_X2
	call_if_lt Afton_Decrease_X
	compare VAR_PLAYER_X, VAR_PLAYER_X2
	call_if_gt Afton_Increase_X
	releaseall
	end

Afton_Check_Y:
	compare VAR_PLAYER_Y, VAR_PLAYER_Y2
	call_if_eq Ok2
	compare VAR_PLAYER_Y, VAR_PLAYER_Y2
	call_if_gt Afton_Increase_Y
	compare VAR_PLAYER_Y, VAR_PLAYER_Y2
	call_if_lt Afton_Decrease_Y
	return
	end

Ok:
	lockall
	msgbox OKI, MSGBOX_DEFAULT
	releaseall
	setvar VAR_PLAYER_X2, VAR_PLAYER_X
	return
	end

Ok2:
	lockall
	msgbox OKI2, MSGBOX_DEFAULT
	setvar VAR_PLAYER_Y2, VAR_PLAYER_Y
	releaseall
	return
	end

OKI:
	.string "Check on X is equal$"

OKI2:
	.string "Check on Y is equal$"

Change:
	setvar VAR_AFTON_STATE, 2
	end

Change2:
	setvar VAR_AFTON_STATE, 4
	end

ResetPositionY1:
	compare VAR_AFTON_Y, 5
	goto_if_gt Afton_Decrease_Y
	goto_if_eq ResetPositionX1
	goto_if_lt Afton_Increase_Y
	end

ResetPositionX1:
	compare VAR_AFTON_X, 5
	goto_if_gt Afton_Decrease_X
	goto_if_eq FinalRun
	goto_if_lt Afton_Increase_X
	end

ResetPositionY2:
	compare VAR_AFTON_Y, 7
	goto_if_gt Afton_Decrease_Y
	goto_if_eq ResetPositionX2
	goto_if_lt Afton_Increase_Y
	end

ResetPositionX2:
	compare VAR_AFTON_X, 9
	goto_if_gt Afton_Decrease_X
	goto_if_eq FinalRun
	goto_if_lt Afton_Increase_X
	end

Afton_Decrease_X:
	lockall
	msgbox DecreaseInXDetected, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PURPLE_MAN, WalkLeftOnce
	subvar VAR_AFTON_X, 1
	setvar VAR_PLAYER_X2, VAR_PLAYER_X
	return
	end

WalkLeftOnce:
	walk_left
	step_end

WalkDownOnce:
	walk_down
	step_end

WalkUpOnce:
	walk_up
	step_end

WalkRightOnce:
	walk_right
	step_end

Afton_Decrease_Y:
	lockall
	msgbox DecreaseInYDetected, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PURPLE_MAN, WalkUpOnce
	subvar VAR_AFTON_Y, 1
	setvar VAR_PLAYER_Y2, VAR_PLAYER_Y
	return
	end

Afton_Increase_X:
	lockall
	msgbox IncreaseInXDetected, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PURPLE_MAN, WalkRightOnce
	addvar VAR_AFTON_X, 1
	setvar VAR_PLAYER_X2, VAR_PLAYER_X
	return
	end

Afton_Increase_Y:
	lockall
	msgbox IncreaseInYDetected, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PURPLE_MAN, WalkDownOnce
	addvar VAR_AFTON_Y, 1
	setvar VAR_PLAYER_Y2, VAR_PLAYER_Y
	return
	end

DecreaseInXDetected:
	.string  "Decrease in X detected$"
DecreaseInYDetected:
	.string  "Decrease in Y detected$"
IncreaseInXDetected:
	.string  "Increase in X detected$"
IncreaseInYDetected:
	.string  "Increase in Y detected$"

FinalRun:
	setvar VAR_AFTON_STATE, 5
	msgbox GET_AWAY, MSGBOX_DEFAULT
	end

GET_AWAY:
	.string "GET AWAY FROM ME!!$"


Route124_OnTransition: @ 81F6572
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	setvar VAR_AFTON_STATE, 1
	setvar VAR_AFTON_X, 3
	setvar VAR_AFTON_Y, 6
	@setvar VAR_PLAYER_X, 6
	setvar VAR_PLAYER_Y, 7
	@setvar VAR_PLAYER_X2, 6
	setvar VAR_PLAYER_Y2, 6
	end

AintAfraidOfNoGhosts:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SpringbonnieDeath::
	lockall
	msgbox GET_AWAY, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PURPLE_MAN, AintAfraidOfNoGhosts
	waitmovement 0
	removeobject LOCALID_PURPLE_MAN
	applymovement LOCALID_SPRINGBONNIE, LaughEvil
	waitmovement 0
	delay 30
	applymovement LOCALID_SPRINGBONNIE, LaughEvil
	waitmovement 0
	delay 30
	applymovement LOCALID_SPRINGBONNIE, LaughEvil
	waitmovement 0
	delay 30
	applymovement LOCALID_SPRINGBONNIE, LaughEvil
	waitmovement 0
	delay 30
	applymovement LOCALID_SPRINGBONNIE, CrushCrush
	waitmovement 0
	delay 50
	applymovement LOCALID_SPRINGBONNIE, ImminentDeath
	waitmovement 0
	applymovement LOCALID_GHOST1, GhostDisappear
	applymovement LOCALID_GHOST2, GhostDisappear
	applymovement LOCALID_GHOST3, GhostDisappear
	applymovement LOCALID_GHOST4, GhostDisappear
	applymovement LOCALID_SPRINGBONNIE, ImminentDeath
	waitmovement 0
	applymovement LOCALID_SPRINGBONNIE, ImminentDeath
	fadescreenspeed FADE_TO_BLACK, 1
	setvar VAR_COSTUME, 0
	releaseall
	warp MAP_PETALBURG_CITY, 1, 0, 0
	waitstate
	releaseall
	end

LaughEvil:
	walk_in_place_down
	step_end

CrushCrush:
	face_left
	step_end

ImminentDeath:
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	step_end

GhostDisappear:
	set_invisible
	step_end



Route124_EventScript_HuntersHouseSign:: @ 81F657C
	msgbox Route124_Text_HuntersHouse, MSGBOX_SIGN
	end

Route124_EventScript_Spencer:: @ 81F6585
	trainerbattle_single TRAINER_SPENCER, Route124_Text_SpencerIntro, Route124_Text_SpencerDefeat
	msgbox Route124_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roland:: @ 81F659C
	trainerbattle_single TRAINER_ROLAND, Route124_Text_RolandIntro, Route124_Text_RolandDefeat
	msgbox Route124_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Jenny:: @ 81F65B3
	trainerbattle_single TRAINER_JENNY_1, Route124_Text_JennyIntro, Route124_Text_JennyDefeat, Route124_EventScript_RegisterJenny
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route124_EventScript_RematchJenny
	msgbox Route124_Text_JennyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterJenny:: @ 81F65DF
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route124_Text_JennyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JENNY_1
	release
	end

Route124_EventScript_RematchJenny:: @ 81F65FE
	trainerbattle_rematch TRAINER_JENNY_1, Route124_Text_JennyRematchIntro, Route124_Text_JennyRematchDefeat
	msgbox Route124_Text_JennyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Grace:: @ 81F6615
	trainerbattle_single TRAINER_GRACE, Route124_Text_GraceIntro, Route124_Text_GraceDefeat
	msgbox Route124_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Chad:: @ 81F662C
	trainerbattle_single TRAINER_CHAD, Route124_Text_ChadIntro, Route124_Text_ChadDefeat
	msgbox Route124_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Lila:: @ 81F6643
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaIntro, Route124_Text_LilaDefeat, Route124_Text_LilaNotEnoughMons, Route124_EventScript_RegisterLila
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route124_EventScript_RematchLila
	msgbox Route124_Text_LilaPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterLila:: @ 81F6673
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchLila:: @ 81F668C
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaRematchIntro, Route124_Text_LilaRematchDefeat, Route124_Text_LilaRematchNotEnoughMons
	msgbox Route124_Text_LilaPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roy:: @ 81F66A7
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyIntro, Route124_Text_RoyDefeat, Route124_Text_RoyNotEnoughMons, Route124_EventScript_RegisterRoy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route124_EventScript_RematchRoy
	msgbox Route124_Text_RoyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterRoy:: @ 81F66D7
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchRoy:: @ 81F66F0
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyRematchIntro, Route124_Text_RoyRematchDefeat, Route124_Text_RoyRematchNotEnoughMons
	msgbox Route124_Text_RoyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Declan:: @ 81F670B
	trainerbattle_single TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Isabella:: @ 81F6722
	trainerbattle_single TRAINER_ISABELLA, Route124_Text_IsabellaIntro, Route124_Text_IsabellaDefeat
	msgbox Route124_Text_IsabellaPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_Text_HuntersHouse: @ 81F6739
	.string "HUNTER'S HOUSE$"

