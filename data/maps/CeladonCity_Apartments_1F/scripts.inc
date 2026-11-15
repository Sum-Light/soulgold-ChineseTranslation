CeladonCity_Apartments_1F_MapScripts::
	.byte 0

CeladonCity_Apartments_1F_EventScript_Manager::
	msgbox CeladonMansion_Text_Manager, MSGBOX_NPC
	end

CeladonCity_Apartments_1F_EventScript_Sign::
	msgbox CeladonMansion_Text_ManagersSuiteSign, MSGBOX_SIGN
	end

CeladonMansion_Text_Manager:
	.string "我可爱的宝可梦们陪着我，\n所以我从不觉得孤单。\p喵喵甚至还会把\n钱带回家来。$"
	.string ""
	.string ""

CeladonMansion_Text_ManagersSuiteSign:
	.string "玉虹大厦　管理员室$"
