Route112_MapScripts:: @ 81F1DA8
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition: @ 81F1DAE
	setflag FLAG_HIDE_MAP_NAME_POPUP
	end
