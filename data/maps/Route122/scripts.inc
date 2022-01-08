
Route122_MapScripts:: @ 81F5DFC
	map_script MAP_SCRIPT_ON_TRANSITION, Route122_OnTransition
	.byte 0

Route122_OnTransition:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	compare VAR_MINIGAME_ID, 4
	call_if_eq DeleteFoxy
	end

DeleteFoxy::
	setflag FLAG_HIDE_FOXY_2
	clearflag FLAG_HIDE_CHICA_SCRAPS
	setflag FLAG_HIDE_CHICA
	clearflag FLAG_HIDE_BONNIE_SCRAPS
	setflag FLAG_HIDE_BONNIE
	clearflag FLAG_HIDE_FREDDY_SCRAPS
	setflag FLAG_HIDE_FREDDY
	return
	end
