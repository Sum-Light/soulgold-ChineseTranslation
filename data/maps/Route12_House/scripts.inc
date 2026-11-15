Route12_House_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "我是钓鱼名人的\n弟弟。\p我看得出来，\n你很喜欢钓鱼。\p我敢肯定，\n绝对错不了！\p怎么样？\n我没说错吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route12_House_Text_GiveSuperRod:
	.string "好，好。果然不出我所料！\p来，钓鱼迷！\n这个给你——这是厉害钓竿。$"
	.string ""
	.string ""

Route12_House_Text_GaveSuperRod:
	.string "有水的地方，\n都可以试试钓鱼。\p记住——不同的钓竿\n能钓到不同的宝可梦。$"
	.string ""
	.string ""
	.string ""

Route12_House_Text_DontWantSuperRod:
	.string "咦？\n难道我看走眼了？$"

