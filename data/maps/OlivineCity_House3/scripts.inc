OlivineCity_House3_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "浅葱市就在海边！\p既然靠着海，\n就一定有鱼！\p我在这里钓了30年鱼。\p你要不要面向大海，\n也来试试钓鱼？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OlivineCity_Text_GiveGoodRod:
	.string "啊，哈哈！我们这儿\n又出了一位新钓手！$"
	.string ""

OlivineCity_Text_GaveGoodRod:
	.string "鱼不只在海里——\n有水的地方\l就有鱼。\p对了，你的宝可梦图鉴\n会按钓点显示宝可梦。\p不同钓点，\n也可能有相似的鱼类。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OlivineCity_Text_DontWantGoodRod:
	.string "什——么？你不喜欢钓鱼！？\n真是难以置信！$"
	.string ""

OlivineCity_Text_HaveGoodRod:
	.string "最近怎么样？\n钓到大家伙了吗？$"
	.string ""
