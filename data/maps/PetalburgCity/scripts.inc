.set LOCALID_WALLY, 2
.set LOCALID_BOY, 3
.set LOCALID_WALLYS_DAD, 5
.set LOCALID_GYM_BOY, 8
.set LOCALID_SCOTT, 9

PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition: @ 81DC2D7
	end

PetalburgCity_OnFrame: @ 81DC31C
	.2byte 0

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