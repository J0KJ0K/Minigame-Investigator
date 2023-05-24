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

Route124_OnTransition: @ 81F6572
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_AFTON_X, 7
	setvar VAR_AFTON_Y, 8
	setvar VAR_AFTON_STATE, 0
	end

Route124_OnFrame:
	map_script_2 VAR_AFTON_STATE, 0, Start
	.2byte 0

Start:
	lockall
	@mugshot of Purple Man
	msgbox WHAT, MSGBOX_DEFAULT
	addvar VAR_AFTON_STATE, 1
	releaseall
	end

Trigger::
	setvar VAR_TEMP_0, 1
	call Movement
	end

Trigger20202020::
	setvar VAR_TEMP_0, 0
	call Movement
	end

Movement:
	specialvar VAR_FACING, GetPlayerFacingDirection
		switch VAR_FACING
		@case DIR_NORTH, GoNorth
		@case DIR_SOUTH, ThatEscalatedQuickly
		case DIR_WEST, KanyeController
		case DIR_EAST, YeastController
		return
	end

YeastController:
	compare VAR_AFTON_STATE, 1
	goto_if_eq YouCanGetThisYeast
	compare VAR_AFTON_STATE, 5
	goto_if_eq YouCanGetThisYeast
	end

KanyeController:
	compare VAR_AFTON_STATE, 3
	goto_if_eq KanyeQuest
	compare VAR_AFTON_STATE, 7
	goto_if_eq KanyeQuest
	end

@VAR_AFTON_STATE states
@	0, just entered the room, should activate William being surprised by the ghosts
@	1, walking; William should only walk to the right
@	2, reposition 1, where he is cornered
@	3, walking, William should only walk to the left
@	4, Reposition
@	5, walking; William should only walk to the right
@	6, reposition
@	7, walking, William should only walk to the left
@	8, SpringbonnieDeath

GoNorth:
	compare VAR_AFTON_Y, 4
	goto_if_eq Deletehim
	applymovement LOCALID_PURPLE_MAN, UpYours
	subvar VAR_AFTON_Y, 1
	end

ThatEscalatedQuickly:
	compare VAR_AFTON_Y, 9
	goto_if_eq Deletehim
	applymovement LOCALID_PURPLE_MAN, Downstairs
	addvar VAR_AFTON_Y, 1
	end

KanyeQuest:
	compare VAR_AFTON_X, 1
	goto_if_eq NextStage
	applymovement LOCALID_PURPLE_MAN, Eh
	subvar VAR_AFTON_X, 1
	end

YouCanGetThisYeast:
	compare VAR_AFTON_X, 10
	goto_if_eq NextStage
	applymovement LOCALID_PURPLE_MAN, Yeah
	addvar VAR_AFTON_X, 1
	end

NextStage:
	addvar VAR_AFTON_STATE, 1
	compare VAR_AFTON_STATE, 2
	goto_if_eq Reposition
	compare VAR_AFTON_STATE, 4
	goto_if_eq Reposition2
	compare VAR_AFTON_STATE, 6
	goto_if_eq Reposition3
	compare VAR_AFTON_STATE, 8
	goto_if_eq SpringbonnieDeath
	end

Reposition:
	lockall
	applymovement LOCALID_PURPLE_MAN, Reposition_1
	waitmovement 0
	setvar VAR_AFTON_X, 5
	addvar VAR_AFTON_STATE, 1
	releaseall
	end

Reposition2:
	lockall
	applymovement LOCALID_PURPLE_MAN, Reposition_2
	waitmovement 0
	setvar VAR_AFTON_X, 7
	addvar VAR_AFTON_STATE, 1
	releaseall
	end

Reposition3:
	lockall
	applymovement LOCALID_PURPLE_MAN, Reposition_3
	waitmovement 0
	setvar VAR_AFTON_X, 4
	addvar VAR_AFTON_STATE, 1
	releaseall
	end

Reposition_1:
	walk_faster_left
	walk_faster_up
	walk_faster_left
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

Reposition_2:
	walk_faster_down
	walk_faster_right
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_right
	walk_faster_up
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_right
	step_end

Reposition_3:
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

UpYours:
	walk_up
	step_end

Downstairs:
	walk_down
	step_end

Eh:
	walk_left
	step_end

Yeah:
	walk_right
	step_end















WHAT:
	.string "What?! Ghosts?!\n"
	.string "GET OFF ME!!$"

GET_AWAY:
	.string "GET AWAY FROM ME!!$"


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
	warp MAP_PETALBURG_CITY, 17, 0, 0
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

