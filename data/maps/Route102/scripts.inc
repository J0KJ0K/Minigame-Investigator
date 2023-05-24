Route102_MapScripts:: @ 81EC0E0
	.byte 0

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
