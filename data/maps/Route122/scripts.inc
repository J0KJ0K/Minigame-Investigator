Route122_MapScripts:: @ 81F5DFC
	map_script MAP_SCRIPT_ON_TRANSITION, Route122_OnTransition
	.byte 0

Route122_OnTransition:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	compare VAR_MINIGAME_ID, 4
	call_if_eq DeleteFoxy
	compare VAR_MINIGAME_ID, 6
	call_if_eq AllGood
	compare VAR_MINIGAME_ID, 7
	call_if_eq AllGood
	compare VAR_MINIGAME_ID, 8
	call_if_eq NotGood
	end

DeleteFoxy::
	setflag FLAG_HIDE_FOXY_2
	clearflag FLAG_HIDE_CHICA_SCRAPS
	setflag FLAG_HIDE_CHICA
	clearflag FLAG_HIDE_BONNIE_SCRAPS
	setflag FLAG_HIDE_BONNIE
	clearflag FLAG_HIDE_FREDDY_SCRAPS
	setflag FLAG_HIDE_FREDDY
	setflag FLAG_HIDE_CHILDREN
	setflag FLAG_HIDE_GHOSTS
	return
	end

AllGood::
	setflag FLAG_HIDE_FOXY_2
	setflag FLAG_HIDE_GHOSTS
	clearflag FLAG_HIDE_CHILDREN
	return
	end

NotGood::
	setflag FLAG_HIDE_FOXY_2
	clearflag FLAG_HIDE_GHOSTS
	setflag FLAG_HIDE_CHILDREN
	return
	end

FoxySign::
	lockall
	goto_if_set FLAG_HIDE_CHILDREN, FoxySign_2
	msgbox FoxySign_Text_1
FoxySign_1:
	releaseall
	return

FoxySign_2:
	msgbox FoxySign_Text_0
	goto FoxySign_1


FoxySign_Text_0:
	.string "OUT OF ORDER$"

FoxySign_Text_1:
	.string "Foxy, the pirate fox!$"