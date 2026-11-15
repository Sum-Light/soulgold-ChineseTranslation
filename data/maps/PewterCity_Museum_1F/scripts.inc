.set LOCALID_MUSEUM_ROOTFOSSIL, 5
.set LOCALID_MUSEUM_CLAWFOSSIL, 6

PewterCity_Museum_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "欢迎光临！\p先说一声，所有大型标本\n都已经送到别的博物馆\l去展出了。\p所以现在入场免费！\p请进吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

PewterCity_Museum_1F_Text_FossilWoman:
	.string "你一定是位很强的训练家。\p那边柜台上的化石我们\n用不太上。\p有个银发的奇怪男人往这儿\n丢下了一大堆。\p你想要的话，尽管拿走吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "我们常和阿露福遗迹的\n研究员交流研究。\p连化石都会通过电脑\n和他们交换呢！$"
	.string ""
	.string ""
	.string ""

PewterCity_Museum_1F_Text_Oldman:
	.string "能活这么久，我该知足了。\p我从没想过这辈子能亲眼\n见到龙的骨头！$"
	.string ""
	.string ""
	.string ""

PewterCity_Museum_1F_Text_Bones:
	.string "古代龙属性宝可梦的骨头。$"
	.string ""
