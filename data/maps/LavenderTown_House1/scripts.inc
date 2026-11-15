LavenderTown_House1_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "你能相信吗？\p居然有人会照顾宝可梦\n照顾到腻烦。\p爷爷收留了那些无家可归的\n可怜宝可梦，照顾它们。$"
	.string ""
	.string ""
	.string ""
	.string ""
LavenderTown_House1_Text_Guy:
	.string "富士老人确实住在这里，不过\n他现在出去了。他应该在\l灵魂之家。$"
	.string ""
	.string ""
LavenderTown_House1_Text_Marowak:
	.string ".............................$"

LavenderTown_House1_Text_Marowak2:
	.string "嘎啦嘎啦很安静，不过看起来\n相当开心。$"
	.string ""

