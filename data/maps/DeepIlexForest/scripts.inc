DeepIlexForest_MapScripts::
	.byte 0


Ilex_Larvesta::
	lock
	faceplayer
	legendaryencounter SPECIES_LARVESTA, 30, LOCALID_ILEX_LARVESTA, FLAG_HIDE_LARVESTA
	release
	end


DeepIlex_Hex::
	msgbox DeepIlex_Hex_Text_0, MSGBOX_NPC
	return


DeepIlex_Hex_Text_0:
	.string "丰缘的工程师曾想\n在这里再建一座\l对战工厂。\p他们还没取得多少\n进展，就被森林的\l守护神赶走了。$"
