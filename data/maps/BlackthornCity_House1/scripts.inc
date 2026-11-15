BlackthornCity_House1_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "能自由操纵龙的\n训练家一族，\l就住在这烟墨市。\p因此，这座城镇里\n流传着许多龙的传说。$"
	.string ""
	.string ""
	.string ""
	.string ""

BlackthornCity_House1_Text_Dratini:
	.string "迷你龙：嗷嗷！$"
