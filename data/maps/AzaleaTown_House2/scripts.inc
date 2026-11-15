AzaleaTown_House2_MapScripts::
	.byte 0


Azalea_SlowpokeTrade::
	lock
	faceplayer
	goto_if_set FLAG_SLOWPOKE_TRADE, Azalea_SlowpokeTrade_2
	ingame_trade INGAME_TRADE_SLOWPOKE, Azalea_SlowpokeTrade_Text_1, SlowpokeTrade_Declined, SlowpokeTrade_NotRequested, Azalea_SlowpokeTrade_Text_2
	setflag FLAG_SLOWPOKE_TRADE
Azalea_SlowpokeTrade_1:
	release
	end

Azalea_SlowpokeTrade_2:
	msgbox Azalea_SlowpokeTrade_Text_0
	goto Azalea_SlowpokeTrade_1


SlowpokeTrade_Declined::
	msgbox SlowpokeTrade_Declined_Text_0
	release
	end


SlowpokeTrade_NotRequested::
	msgbox SlowpokeTrade_NotRequested_Text_0
	release
	end


Azalea_SlowpokeTrade_Text_0:
	.string "你又攒了更多呆呆兽吗？$"

Azalea_SlowpokeTrade_Text_1:
	.string "我最喜欢呆呆兽了！\n它们又可爱又软乎乎，\l又萌又甜，了不起又超级棒！\l要不要我证明给你看？\l只要你给我一只你的呆呆兽，\l我就把我最棒的呆呆兽送给你。$"

Azalea_SlowpokeTrade_Text_2:
	.string "呆呆兽教又多了一位信徒。$"

SlowpokeTrade_Declined_Text_0:
	.string "咦？你难道不明白\n呆呆兽有多棒吗？！$"

SlowpokeTrade_NotRequested_Text_0:
	.string "喂！这可不是真正的呆呆兽！\n你是想拿差劲的宝可梦\l来糊弄我吗？$"
