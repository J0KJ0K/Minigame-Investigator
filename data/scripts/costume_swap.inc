EventScript_CostumeSwap::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_COSTUME, VAR_COMPLETIONIST_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	releaseall
	end

ReturnFromMinigame::
	lockall
	fadescreenspeed FADE_TO_BLACK, 1
	setvar VAR_COSTUME, VAR_COMPLETIONIST_COSTUME
	releaseall
	warp MAP_PETALBURG_CITY, 17, 0, 0
	waitstate
	releaseall
	end

PrepareForMinigame::
	getplayerxy VAR_PLAYER_X_STORED, VAR_PLAYER_Y_STORED
	return