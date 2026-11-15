
AzaleaTown_Mart_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_BugCatcher:
	.string "用超级球抓宝可梦，\n比用精灵球更容易。\p不过有时候，\n钢铁做的球会更好用。$"
	.string ""
	.string ""
	.string ""

AzaleaTownMart2::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE04_GET, AzaleaTownMart2_2
	message AzaleaTownMart2_Text_2
	waitmessage
	pokemart GalaricaVendor
	msgbox AzaleaTownMart2_Text_1
	release
	end

AzaleaTownMart2_2:
	msgbox AzaleaTownMart2_Text_0
	waitmessage
	pokemart GalaricaNoneVendor
	msgbox AzaleaTownMart2_Text_1
	release
	end


	.align 2
GalaricaVendor:
	.2byte ITEM_TM_INFESTATION
	.2byte ITEM_TM_GIGA_DRAIN
	.2byte ITEM_TM_X_SCISSOR
	.2byte ITEM_GALARICA_WREATH
	.2byte ITEM_GALARICA_CUFF
	.2byte ITEM_NEST_BALL
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_NONE

	.align 2
GalaricaNoneVendor:
	.2byte ITEM_TM_GIGA_DRAIN
	.2byte ITEM_NEST_BALL
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_NONE

AzaleaTownMartNpc::
	lock
	faceplayer
	goto_if_set FLAG_BADGE04_GET, AzaleaTownMartNpc_2
	msgbox AzaleaTownMartNpc_Text_1
	release
	end

AzaleaTownMartNpc_2:
	msgbox AzaleaTownMartNpc_Text_0
	release
	end


AzaleaTownMart2_Text_0:
	.string "伽勒豆蔻花圈和\n伽勒豆蔻手环暂时缺货。\p我们很快会补货的。\n总之，欢迎光临！$"

AzaleaTownMart2_Text_1:
	.string "欢迎下次再来！$"

AzaleaTownMart2_Text_2:
	.string "欢迎光临！\n伽勒尔的道具\l已经补货了！$"

AzaleaTownMartNpc_Text_0:
	.string "伽勒尔的进化道具\n补货了！$"

AzaleaTownMartNpc_Text_1:
	.string "听说火箭队把伽勒尔\n呆呆兽用的进化道具\l全都抢走了。$"
