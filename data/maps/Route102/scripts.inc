Route102_MapScripts:: @ 81EC0E0
	.byte 0

Route102_EventScript_LittleBoy:: @ 81EC0E1
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale:: @ 81EC0EA
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg:: @ 81EC0F3
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy:: @ 81EC0FC
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

CandyCadet::
	lockall
	@mugshot of Candy Cadet
	msgbox CC_Theseus, MSGBOX_DEFAULT
	releaseall
	end

Mike_Talk_Body::
	lockall
	@mugshot of Mike, maybe divide Mike_NewBody_1 and Mike_NewBody_2 in order to change expressions more often
	msgbox Mike_NewBody_1, MSGBOX_NPC
	@mugshot of Scott, worried about friend
	msgbox Player_Newbody_Reaction, MSGBOX_NPC
	msgbox Mike_NewBody_2, MSGBOX_NPC
	releaseall
	end

Mike_NewBody_1:
	.string "Uncle Henry offered to make me\n"
	.string "a newer, stronger body,\l"
	.string "after what happened.\p"
	.string "The remnant of the missing children\n"
	.string "allowed me to barely survive, even\l"
	.string "after getting my innards scooped out,\l"
	.string "but that wasn't enough if I wanted\l"
	.string "to live normally.$"

Player_Newbody_Reaction:
	.string "So... What did you say?$"

Mike_NewBody_2:
	.string "I feel horrible for this, but...\p"
	.string "I asked him to keep the skin.\n"
	.string "It's the only part I can confidently\l"
	.string "say it's mine.\p"
	.string "So he would build me an endoskeleton\n"
	.string "from the inside out, he gave me a\l"
	.string "new body, and I am grateful for it...\p"
	.string "But I don't feel human.\p"
	.string "I'm not who this skin once\n"
	.string "belonged to anymore.\p"
	.string "I can only hope to be the one to end this.$"

CC_Theseus:
	.string "Now I will tell you the story\n"
	.string "of a greek hero whose ship was\l"
	.string "preserved after his death.\p"
	.string "Since the ship was made of wood,\n"
	.string "it didn't take long for the sea\l"
	.string "to wither its parts, one by one.\p"
	.string "To fix this, the people replaced\l"
	.string "each part that gave in to decay.\p"
	.string "eventually, the ship was made of\n"
	.string "only renewed parts, leaving no\l"
	.string "remnant of the original ship.\p"
	.string "So now I ask you, is this still\n"
	.string "the same ship we started with?$"





Route102_EventScript_Calvin:: @ 81EC105
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle:: @ 81EC146
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall:: @ 81EC157
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister:: @ 81EC170
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister:: @ 81EC183
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch:: @ 81EC19C
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick:: @ 81EC1B3
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana:: @ 81EC1CA
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen:: @ 81EC1E1
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon: @ 81EC1F8
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt: @ 81EC271
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack: @ 81EC297
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route102_Text_ImNotVeryTall: @ 81EC2C0
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon: @ 81EC32E
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale: @ 81EC35B
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg: @ 81EC373
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"
