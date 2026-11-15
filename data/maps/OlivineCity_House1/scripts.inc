
OlivineCity_House1_MapScripts::
	.byte 0

Olivine_VoltorbTrade::
	lock
	faceplayer
	goto_if_set FLAG_OLIVINE_NPC_TRADE_COMPLETED, Olivine_VoltorbTrade_2
	ingame_trade INGAME_TRADE_VOLTORB, Olivine_VoltorbTrade_Text_1, VoltorbTrade_Declined, VoltorbTrade_NotRequested, Olivine_VoltorbTrade_Text_2
	setflag FLAG_OLIVINE_NPC_TRADE_COMPLETED
Olivine_VoltorbTrade_1:
	release
	end

Olivine_VoltorbTrade_2:
	msgbox Olivine_VoltorbTrade_Text_0
	goto Olivine_VoltorbTrade_1


VoltorbTrade_Declined::
	msgbox VoltorbTrade_Declined_Text_0
	release
	end


VoltorbTrade_NotRequested::
	msgbox VoltorbTrade_NotRequested_Text_0
	release
	end


Olivine_VoltorbTrade_Text_0:
	.string "我那只霹雳电球还好吗？$"

Olivine_VoltorbTrade_Text_1:
	.string "我在收集宝可梦。\n你有好坏星吗？\l愿意用它换我的\l洗翠的霹雳电球吗？$"

Olivine_VoltorbTrade_Text_2:
	.string "太好了！我换到好坏星了！\n霹雳电球，你要保重哦！$"

VoltorbTrade_Declined_Text_0:
	.string "你不愿意交换？哎呀……$"

VoltorbTrade_NotRequested_Text_0:
	.string "呃，不行，我不换。\n那看起来不像好坏星。$"
