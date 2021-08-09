Route118_MapScripts:: @ 81F3DBC
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition: @ 81F3DCC
	compare VAR_ANIMATRONIC_ID, 4
	call_if_eq DeleteFoxy
	compare VAR_ANIMATRONIC_ID, 5
	call_if_eq Night5
	end

Route118_OnLoad: @ 81F3DF3
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setflag FLAG_LAST_IN_PIRATE_COVE
	clearflag FLAG_LAST_IN_STAGE
	clearflag FLAG_LAST_IN_CORRIDOR_L
	clearflag FLAG_LAST_IN_ROOM_S
	end

Route118_OnFrame: @ 81F3E0A
	.2byte 0


DeleteFoxy:
	setflag FLAG_HIDE_FOXY_2
	clearflag FLAG_HIDE_CHICA_SCRAPS
	setflag FLAG_HIDE_CHICA
	clearflag FLAG_HIDE_BONNIE_SCRAPS
	setflag FLAG_HIDE_BONNIE
	clearflag FLAG_HIDE_FREDDY_SCRAPS
	setflag FLAG_HIDE_FREDDY
	return
	end

Night5:
	call DeleteFoxy
	clearflag FLAG_HIDE_FOXY_SCRAPS
	setflag FLAG_LAST_IN_KITCHEN
	setflag FLAG_LAST_IN_BATHROOMS
	setflag FLAG_LAST_IN_ROOM_S
	setflag FLAG_LAST_IN_ROOM_R
	setflag FLAG_LAST_IN_OFFICE
	setflag FLAG_LAST_IN_CORRIDOR_R
	end