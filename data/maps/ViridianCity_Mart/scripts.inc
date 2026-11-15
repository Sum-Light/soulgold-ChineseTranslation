ViridianCity_Mart_MapScripts::
	.byte 0

ViridianCity_Mart_EventScript_Lass::
	msgbox ViridianMart_Text_Lass, MSGBOX_NPC
	end

ViridianCity_Mart_EventScript_Cooltrainer::
	msgbox ViridianMart_Text_CooltrainerM, MSGBOX_NPC
	end

ViridianMart_Text_Lass:
	.string "这里的道馆馆主\n超级酷。$"

ViridianMart_Text_CooltrainerM:
	.string "您去过红莲吗？\p那是这南边很远的一座岛。$"
	.string ""

