.set LOCALID_MILES, 1

PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition: @ 81DC2D7
	setvar VAR_COSTUME, 0
	special	SwapPlayersCostume
	end

PetalburgCity_OnFrame: @ 81DC31C
	.2byte 0

Miles_Resetposition1:
	walk_down
	walk_left
	walk_left
	walk_up
	step_end

Resetpositionpart2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

Miles_Resetposition2:
	walk_up
	walk_left
	walk_left
	step_end

Miles_ResetpositionPlayer2:
	walk_up
	step_end

Miles_ResetpositionPlayer3:
	walk_up
	walk_up
	step_end

Miles_ResetpositionPlayer4:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

Miles_Resetposition3:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

Miles_Resetposition4:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

Miles_Intro1::
	lockall
	call Miles_Introduction
	setvar VAR_MILES_STATE, 1
	applymovement LOCALID_MILES, WalkupToPlayer1
	waitmovement 0
	msgbox Miles_Intro, MSGBOX_DEFAULT
	applymovement LOCALID_MILES, Miles_Resetposition1
	waitmovement 0
	applymovement LOCALID_MILES, Resetpositionpart2
	applymovement OBJ_EVENT_ID_PLAYER, Resetpositionpart2
	waitmovement 0
	call Miles_Intro_Normal
	releaseall
	end

Miles_Intro2::
	lockall
	call Miles_Introduction
	setvar VAR_MILES_STATE, 1
	applymovement LOCALID_MILES, WalkupToPlayer2
	waitmovement 0
	msgbox Miles_Intro, MSGBOX_DEFAULT
	applymovement LOCALID_MILES, Miles_Resetposition2
	waitmovement 0
	applymovement LOCALID_MILES, Resetpositionpart2
	applymovement OBJ_EVENT_ID_PLAYER, Miles_ResetpositionPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Resetpositionpart2
	waitmovement 0
	call Miles_Intro_Normal
	releaseall
	end

Miles_Intro3::
	lockall
	call Miles_Introduction
	setvar VAR_MILES_STATE, 1
	applymovement LOCALID_MILES, WalkupToPlayer3
	waitmovement 0
	msgbox Miles_Intro, MSGBOX_DEFAULT
	applymovement LOCALID_MILES, Miles_Resetposition3
	waitmovement 0
	applymovement LOCALID_MILES, Resetpositionpart2
	applymovement OBJ_EVENT_ID_PLAYER, Miles_ResetpositionPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Resetpositionpart2
	waitmovement 0
	call Miles_Intro_Normal
	releaseall
	end

Miles_Intro4::
	lockall
	call Miles_Introduction
	setvar VAR_MILES_STATE, 10
	applymovement LOCALID_MILES, WalkupToPlayer4
	waitmovement 0
	msgbox Miles_Intro, MSGBOX_DEFAULT
	applymovement LOCALID_MILES, Miles_Resetposition4
	waitmovement 0
	applymovement LOCALID_MILES, Resetpositionpart2
	applymovement OBJ_EVENT_ID_PLAYER, Miles_ResetpositionPlayer4
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Resetpositionpart2
	waitmovement 0
	call Miles_Intro_Normal
	releaseall
	end

ToBacktrack:
	walk_left
	step_end

ToBack:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

ToBackMiles:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_down
	step_end

Miles_Out:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Miles_Intro_Normal:
	msgbox Miles_View, MSGBOX_DEFAULT
	applymovement LOCALID_MILES, ToBackMiles
	applymovement OBJ_EVENT_ID_PLAYER, ToBacktrack
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ToBack
	waitmovement 0
	msgbox Miles_Back, MSGBOX_DEFAULT
	msgbox ThisUpdate, MSGBOX_DEFAULT
	msgbox IfYouNeedMe, MSGBOX_DEFAULT
	applymovement LOCALID_MILES, Miles_Out
	waitmovement 0
	removeobject LOCALID_MILES
	setflag FLAG_HIDE_MILES_2
	clearflag FLAG_HIDE_MILES
	return
	releaseall

Miles_Introduction:
	lockall
	addobject LOCALID_MILES
	msgbox Miles_Tired, MSGBOX_DEFAULT
	applymovement LOCALID_MILES, MilesMoveForward
	applymovement OBJ_EVENT_ID_PLAYER, LookatMiles1
	waitmovement 0
	msgbox Miles_Notice
	return
	end
	
LookatMiles1:
	face_right
	step_end

	Miles_Tired:
	.string "Oof... Th-that was...\n"
	.string "a lot of stairs...$"

Miles_Notice:
	.string "Oh, you're already here!$"

Miles_Intro:
	.string "Name's Miles.\n"
	.string "Welcome to my room!\p"
	.string "I'm one of the developers\n"
	.string "for Minigame Investigator,\l"
	.string "so we use my room as a\l"
	.string "testing hub of sorts.\p"
	.string "You're welcome to test as well!\p"
	.string "Here, let me show you around!$"
	
Miles_View:
	.string "Here you can see all the\n"
	.string "animatronics we've put into the game.\l"
	.string "They don't move, though.\p"
	.string "Creepy.$"

Miles_Back:
	.string "And here's the star of the show!\n"
	.string "These doors will lead to the areas\l"
	.string "we've been testing.$"

ThisUpdate:
	.string "This update is centred around the\n"
	.string "end of night minigames of FNaF 3,\l"
	.string	"which happen in the FNaF 1 location!\p"
	.string "I hope you like it, a lot of effort was\n"
	.string "put into it during the past week!$"

IfYouNeedMe:
	.string "I'll be in the entrance\n"
	.string "if you need me.\l"
	.string "We can talk more in depth then!$"

MilesMoveForward:
	walk_down
	step_end

WalkupToPlayer1:
	walk_left
	walk_left
	step_end

WalkupToPlayer2:
	walk_down
	walk_left
	walk_left
	step_end

WalkupToPlayer3:
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

WalkupToPlayer4:
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Door_FNaF1::
	lockall
	msgbox FNaF1, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_COSTUME, 1
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	releaseall
	end

Door_FNaF2::
	lockall
	msgbox FNaF2, MSGBOX_DEFAULT
	release
	end

Door_FNaF4::
	lockall
	msgbox FNaF4, MSGBOX_DEFAULT
	release
	end

Door_FNaF6::
	lockall
	msgbox FNaF6, MSGBOX_DEFAULT
	release
	end

Door_GoBack::
	lockall
	msgbox GoBack, MSGBOX_DEFAULT
	release
	end

Door_PhoneDude::
	lockall
	msgbox Phone_Dude, MSGBOX_DEFAULT
	release
	end

Door_Arson::
	lockall
	msgbox Prision, MSGBOX_DEFAULT
	release
	end

Door_City::
	lockall
	msgbox City, MSGBOX_DEFAULT
	release
	end

FNaF1:
	.string "Old Freddy Fazbear's$"
FNaF2:
	.string "Freddy Fazbear's -\n"
	.string "- 1987$"
FNaF4:
	.string "Fredbear's Family Diner$"
FNaF6:
	.string "NEW Freddy Fazbear's$"
GoBack:
	.string "PETALBURG TOWN$"
City:
	.string "Hurricane, Utah$"
Prision:
	.string "Pyromaniac's Cell$"
Phone_Dude:
	.string "A really nice\n"
	.string "dude's house$"
