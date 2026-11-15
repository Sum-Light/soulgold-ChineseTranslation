Route39_FarmHouse_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_ECHOED_VOICE
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "我的大奶罐\n再不下奶了。\p俺们哞哞牧场的奶可有名了。\p大伙儿都想喝上一口。\p俺寻思，只要多喂它\n橙橙果，\l它就能挤出好多奶。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route39_Text_FarmerMBuyMilk:
	.string "要不要来瓶俺的哞哞鲜奶？\p这可是俺的骄傲。\p给宝可梦喝能回复体力！\p俺就卖你\n¥500。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route39_Text_FarmerMGotMilk:
	.string "拿好嘞！\n使劲喝，喝个痛快！$"
	.string ""

Route39_Text_FarmerMNoMoney:
	.string "对不住啦。\n没钱就不卖喽！$"
	.string ""

Route39_Text_FarmerMNoRoom:
	.string "俺瞧你的背包已经满了。$"

Route39_Text_FarmerMNoSale:
	.string "不要啦？\n那下次再来啊！$"
	.string ""

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "再来一瓶怎么样？$"

Route39_Text_GotMilk:
	.string "{PLAYER}得到了哞哞鲜奶。$"

Route39_Text_FarmerMMilking:
	.string "俺得去挤奶了。$"

Route39_Text_FarmerFInTrouble:
	.string "俺们的奶还卖到\n关都去呢。\p要是自家的大奶罐\n不下奶，俺们可就难办了。$"
	.string ""
	.string ""
	.string ""

Route39_Text_FarmerFHealedMiltank:
	.string "你治好了俺们的大奶罐，\n好孩子，它又能出哞哞鲜奶了。\p这是给你的谢礼。$"
	.string ""
	.string ""

Route39_Text_FarmerFSnatchSpeech:
	.string "这是回声。\n孩子，多用几次吧。\p威力会越来越大。$"
	.string ""
	.string ""
