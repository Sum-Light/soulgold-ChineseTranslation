Gate_AzaleaTown_IlexForest_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
	.string "栎树林很大。\n要小心！别迷路了。$"
	.string ""
	.string ""

Gate_AzaleaTown_IlexForest_Text_Granny:
	.string "森林有守护神\n看守着。\p可别做坏事哦！$"
	.string ""
	.string ""
