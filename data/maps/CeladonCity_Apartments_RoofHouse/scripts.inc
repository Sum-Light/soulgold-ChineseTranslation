CeladonCity_Apartments_RoofHouse_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_REST, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_REST
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "让我来讲一个\n吓人的故事……$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "不过话说回来，外面还亮着，\n听起来也没那么吓人。\p太阳下山后再来吧，好吗？$"
	.string ""
	.string ""

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "从前，有个小男孩得到了\n一辆崭新的\l自行车……\p他想马上骑出去试试……\p他骑得太开心，都没发现\n太阳已经下山了……\p在漆黑的夜里骑车回家时，\n自行车突然\l慢了下来！\p脚踏板变得沉重无比！\p他停止踩踏板后，\n自行车开始向后滑动！\p就好像这辆车被诅咒了，\n正试图把他拖进\l无底的深渊！\p……\p……\p嘎啊啊啊！\p原来男孩骑的是\n自行车道的上坡路！\p……\n扑通、扑通！\p你这么耐心地听完了故事，\n这个就送给你——招式学习器44！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "招式学习器44里是睡觉。\p它能让你的宝可梦在对战中\n打个盹，恢复体力。\p不过听完这么吓人的故事，\n你还睡得着吗！$"
	.string ""
	.string ""
	.string ""
	.string ""

