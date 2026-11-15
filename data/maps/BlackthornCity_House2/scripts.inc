
BlackthornCity_House2_MapScripts::
	.byte 0

Blackthorn_GabiteTrade::
	lock
	faceplayer
	goto_if_set FLAG_BLACKTHORN_NPC_TRADE_COMPLETED, Blackthorn_GabiteTrade_2
	ingame_trade INGAME_TRADE_GABITE, Blackthorn_GabiteTrade_Text_1, GabiteTrade_Declined, GabiteTrade_NotRequested, Blackthorn_GabiteTrade_Text_2
	setflag FLAG_BLACKTHORN_NPC_TRADE_COMPLETED
Blackthorn_GabiteTrade_1:
	release
	end

Blackthorn_GabiteTrade_2:
	msgbox Blackthorn_GabiteTrade_Text_0
	goto Blackthorn_GabiteTrade_1


GabiteTrade_Declined::
	msgbox GabiteTrade_Declined_Text_0
	release
	end


GabiteTrade_NotRequested::
	msgbox GabiteTrade_NotRequested_Text_0
	release
	end


Blackthorn_GabiteTrade_Text_0:
	.string "我的尖牙陆鲨过得还好吗？$"

Blackthorn_GabiteTrade_Text_1:
	.string "你好。我在收集龙属性宝可梦。\n你有哈克龙吗？我愿意用它\l交换尖牙陆鲨。$"

Blackthorn_GabiteTrade_Text_2:
	.string "非常感谢。$"

GabiteTrade_Declined_Text_0:
	.string "找到的话，就来和我交换吧！$"

GabiteTrade_NotRequested_Text_0:
	.string "那看起来不像是哈克龙啊。$"
