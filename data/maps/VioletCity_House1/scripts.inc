
VioletCity_House1_MapScripts::
	.byte 0

VioletCity_House1_EventScript_Kyle::
	lock
	faceplayer
	msgbox VioletCity_House1_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House1_Text_PokefanM:
	.string "交换来的宝可梦\n成长得很快。\p但如果没有相应的\n道馆徽章，它可能会不听话。$"
	.string ""
	.string ""
	.string ""

Violet_PawmiTrade::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_NPC_TRADE_COMPLETED, Violet_PawmiTrade_2
	ingame_trade INGAME_TRADE_PAWMI, Violet_PawmiTrade_Text_1, PawmiTrade_Declined, PawmiTrade_NotRequested, Violet_PawmiTrade_Text_2
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
Violet_PawmiTrade_1:
	release
	end

Violet_PawmiTrade_2:
	msgbox Violet_PawmiTrade_Text_0
	goto Violet_PawmiTrade_1


PawmiTrade_Declined::
	msgbox PawmiTrade_Declined_Text_0
	release
	end


PawmiTrade_NotRequested::
	msgbox PawmiTrade_NotRequested_Text_0
	release
	end


Violet_PawmiTrade_Text_0:
	.string "你好，我那只布拨过得还好吗？$"

Violet_PawmiTrade_Text_1:
	.string "我在收集宝可梦\n你有木棉球吗？\l要不要拿它换\l我的布拨？$"

Violet_PawmiTrade_Text_2:
	.string "太好了！我得到木棉球了！\n布拨，你要保重哦！$"

PawmiTrade_Declined_Text_0:
	.string "不想换吗？唉……$"

PawmiTrade_NotRequested_Text_0:
	.string "呃，这个不行。\n那看起来不像木棉球。$"
