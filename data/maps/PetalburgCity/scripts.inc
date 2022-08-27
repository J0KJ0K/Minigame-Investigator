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
	
Miles_Normal::
	lockall
	faceplayer
	msgbox Wassup, MSGBOX_DEFAULT
	closemessage
	multichoicegrid 0, 1, MULTI_MILES_MENU, 1, FALSE
	switch VAR_RESULT
	case 0, Miles_Story
	case 1, ThisUpdate_Description
	case 2, NextUpdate
	case 3, Remember
	case 4, WeSuck
	case 5, Goodnight
	case MULTI_B_PRESSED, Goodnight
	releaseall
	end

Remember:
	compare VAR_GAME_VERSION, 2
	goto_if 0 DistantPast
	goto_if 1 PizzeriaUpdate
	goto_if_eq Present
	goto_if_gt Future
	releaseall
	end

PizzeriaUpdate:
	lockall
	msgbox Pizzaaa, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Pizzaaa:
	.string "Oh, hey!\n"
	.string "Back from the\l"
	.string "Pizzeria Update, right?\p"
	.string "Well, what do you think?\p"
	.string "We improved a few things\n"
	.string "regarding contrast and\l"
	.string "saturation, but there's\l"
	.string "still a long way to go!\p"
	.string "I wonder what the next\n"
	.string "update will bring?$"

Future:
	lockall
	msgbox Futa, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Futa:
	.string "Hey, future boy,\n"
	.string "did you miss me that much?\p"
	.string "I mean, why are you looking\n"
	.string "into old versions of the game?\p"
	.string "Maybe curiosity?\n"
	.string "Maybe ignorance...$"

Present:
	lockall
	msgbox Gift, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Gift:
	.string "Nope, I met you today.\n"
	.string "Still, it's nice to meet you!$"
	
DistantPast:
	lockall
	msgbox Past, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Past:
	.string "Well, last time you were here,\n"
	.string "I was wandering in my lab, so...\l"
	.string "Yeah, today is my first day with you!$"


NextUpdate:
	lockall
	msgbox NextUpdate_Miles, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

NextUpdate_Miles:
	.string "Oh, about the next one?\p"
	.string "We'll try to fix whatever\n"
	.string "bugs and glitches you find,\l"
	.string	"we'll add Pirate Cove here,\l"
	.string "and probably a few more known\l"
	.string "characters, like the Puppet!\p"
	.string "Expect to see more\n"
	.string "expressions as well!$"


Goodnight:
	lockall
	releaseall
	end

WeSuck:
	lockall
	msgbox Succ, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Succ:
	.string "Ouch...\n"
	.string "You could have at least been\l"
	.string "polite about it, you know?$"

ThisUpdate_Description:
	lockall
	msgbox ThisUpdate, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Miles_Story:
	subvar VAR_STORIES_TO_TELL, 1
	compare VAR_STORIES_TO_TELL, 0
	call_if_le NoStoriesForYouNoo
	compare VAR_STORIES_TO_TELL, 1
	call_if_eq Story1Noo
	compare VAR_STORIES_TO_TELL, 2
	call_if_eq Story2Noo
	compare VAR_STORIES_TO_TELL, 3
	call_if_eq Story3Noo
	compare VAR_STORIES_TO_TELL, 4
	call_if_eq Story4Noo
	end

NoStoriesForYouNoo:
	lockall
	msgbox NoStoriesForYou, MSGBOX_DEFAULT
	setvar VAR_STORIES_TO_TELL, 5
	closemessage
	releaseall
	end

Story1Noo:
	lockall
	msgbox Story1, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Story2Noo:
	lockall
	msgbox Story2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Story3Noo:
	lockall
	msgbox Story3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Story4Noo:
	lockall
	msgbox Story4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end


NoStoriesForYou:
	.string "Sorry, that was all my stories.\p"
	.string "I can repeat them to you, though.$"

Story1:
	.string "This is my last story today.\p"
	.string "SNAP usually comes around\n"
	.string "this very lab some times during\l"
	.string "the day to hang out.\p"
	.string "He's a good sport, I wonder\n"
	.string "if you'll ever get to meet?$"

Story2:
	.string "In order to decompress from this\n"
	.string "update's glitches, we will stream\l"
	.string "some character designs on YouTube\l"
	.string "later today!\p"
	.string "I might even make a little\n"
	.string "appearence hehe ;)$"

Story3:
	.string "We have considered for a long\n"
	.string "time to have developer comentary\l"
	.string "in Minigame Investigator.\p"
	.string "It is almost as fun as telling\n"
	.string "you about the development this way!$"

Story4:
	.string "This update was small, but\n"
	.string "it really did take its time\l"
	.string "to be complete!\p"
	.string "(About 20 days, more or less)\p"
	.string "JK's house is now on repairs,\n"
	.string "and we are helping him from\l"
	.string "time to time.\p"
	.string "There's also Shadow Freddy.\p"
	.string "That thing presented to many\n"
	.string "glitches that demotivated us\l"
	.string "to the point of procrastination.\p"
	.string "Hell, the last parts of the code\n"
	.string "were added at 2:40 AM today!\p"
	.string "We even got to write some lore\n"
	.string "episodes during the weeks, but\l"
	.string "it was all just an attempt\l"
	.string "at not having to fix S. Freddy.$"

Wassup:
	.string "Hey, {PLAYER}!\n"
	.string "What's up?$"





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
	closemessage
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
	closemessage
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
	closemessage
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
	closemessage
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
	closemessage
	msgbox ThisUpdate, MSGBOX_DEFAULT
	closemessage
	msgbox IfYouNeedMe, MSGBOX_DEFAULT
	closemessage
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
	closemessage
	applymovement LOCALID_MILES, MilesMoveForward
	applymovement OBJ_EVENT_ID_PLAYER, LookatMiles1
	waitmovement 0
	msgbox Miles_Notice, MSGBOX_DEFAULT
	closemessage
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
	.string "I hope you like it, and we sincerely\n"
	.string "hope to never work on this update's\l"
	.string "glitches again!\p"
	.string "(Bloody things drained our motivation\n"
	.string "these past few weeks)$"

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
	.string "PLAYER'S ROOM$"
City:
	.string "Hurricane, Utah$"
Prision:
	.string "Pyromaniac's Cell$"
Phone_Dude:
	.string "A really nice\n"
	.string "dude's house$"
