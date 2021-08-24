
Route122_MapScripts:: @ 81F5DFC
	map_script MAP_SCRIPT_ON_TRANSITION, Route122_OnTransition
	.byte 0

Route122_OnTransition:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	end