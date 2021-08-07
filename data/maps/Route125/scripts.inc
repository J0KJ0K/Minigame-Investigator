Route125_MapScripts:: @ 81F6748
	map_script MAP_SCRIPT_ON_TRANSITION, Route125_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route125_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route125_OnFrame
	.byte 0

Route125_OnTransition: @ 81F6758
	setflag FLAG_HIDE_FREDDY_SCRAPS
	setflag FLAG_HIDE_BONNIE_SCRAPS
	setflag FLAG_HIDE_CHICA_SCRAPS
	setflag FLAG_HIDE_FOXY_SCRAPS
	setflag FLAG_HIDE_AFTON
	clearflag  FLAG_TURNED_HIMSELF_INTO_SCRAPS
	clearflag FLAG_HIDE_FREDDY
	clearflag FLAG_HIDE_BONNIE
	clearflag FLAG_HIDE_CHICA
	clearflag FLAG_HIDE_FOXY
	end

Route125_OnLoad: @ 81F6783
	end

Route125_OnFrame: @ 81F679A
	.2byte 0

Trigger1::
	msgbox Night_1, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_ANIMATRONIC_ID, 1
	setvar VAR_COSTUME, 1
	special SwapPlayersCostume
	warp MAP_ROUTE110, 0, 0, 0
	waitstate
	end

Trigger2::
	msgbox Night_2, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_ANIMATRONIC_ID, 2
	setvar VAR_COSTUME, 2
	special SwapPlayersCostume
	warp MAP_ROUTE110, 1, 0, 0
	waitstate
	end

Trigger3::
	msgbox Night_3, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_ANIMATRONIC_ID, 3
	setvar VAR_COSTUME, 3
	special SwapPlayersCostume
	warp MAP_ROUTE110, 2, 0, 0
	waitstate
	end

Trigger4::
	setvar VAR_ANIMATRONIC_ID, 4
	setvar VAR_COSTUME, 3
	msgbox Night_4, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special SwapPlayersCostume
	warp MAP_ROUTE118, 0, 1, 5
	waitstate
	end

Trigger5::
	setvar VAR_ANIMATRONIC_ID, 5
	setvar VAR_COSTUME, 5
	msgbox Night_5, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special SwapPlayersCostume
	warp MAP_ROUTE118, 0, 1, 5
	waitstate
	end

Night_1:
	.string "Night 1$"

Night_2:
	.string "Night 2$"

Night_3:
	.string "Night 3$"

Night_4:
	.string "Night 4$"

Night_5:
	.string "Night 5$"