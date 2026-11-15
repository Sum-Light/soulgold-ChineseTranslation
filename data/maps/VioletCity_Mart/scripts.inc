
VioletCity_Mart_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "刚收服的宝可梦，\n一开始也许很弱。\p但它总有一天会\n变得强大。\p用爱心对待宝可梦\n是很重要的。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

VioletCity_Mart_Text_CooltrainerM:
	.string "宝可梦能携带伤药\n和解毒药之类的道具。\p但它们好像不懂得\n怎么使用人造的道具。$"
	.string ""
	.string ""
	.string ""

Violetcity_Mart2::
	lock
	faceplayer
	message Violetcity_Mart2_Text_0
	waitmessage
	pokemart Violetcity2
	msgbox Violetcity_Mart2_Text_1
	release
	end


	.align 2
Violetcity2:
	.2byte ITEM_TM_HONE_CLAWS
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE

Violetcity_Mart2_Text_0:
	.string "欢迎光临！您需要些什么？$"

Violetcity_Mart2_Text_1:
	.string "欢迎您再来！$"
