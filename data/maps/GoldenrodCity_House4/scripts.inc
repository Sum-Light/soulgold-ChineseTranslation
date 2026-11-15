GoldenrodCity_House4_MapScripts::
	.byte 0


Golderod_House4_Fatman::
	msgbox Golderod_House4_Fatman_Text_0, MSGBOX_NPC
	return


Goldenrod_House4_Venipede::
	lock
	faceplayer
	playmoncry SPECIES_VENIPEDE, CRY_MODE_NORMAL
	msgbox Goldenrod_House4_Venipede_Text_0
	waitmoncry
	release
	end


Golderod_House4_Fatman_Text_0:
	.string "听说宝可梦到了一定等级，\n"
	.string "就会获得更多特性。\l"
	.string "这是真的吗？$"

Goldenrod_House4_Venipede_Text_0:
	.string "嘶——！$"
