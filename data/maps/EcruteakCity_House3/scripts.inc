EcruteakCity_House3_MapScripts::
	.byte 0


EcruteakCity_House3_HexLady::
	lock
	faceplayer
	goto_if_set FLAG_TM_HEX, EcruteakCity_House3_HexLady_2
	msgbox EcruteakCity_House3_HexLady_Text_1
	waitmessage
	giveitem ITEM_TM_HEX
	setflag FLAG_TM_HEX
	msgbox EcruteakCity_House3_HexLady_Text_0
	release
	end

EcruteakCity_House3_HexLady_2:
	msgbox EcruteakCity_House3_HexLady_Text_0
	release
	end


EcruteakCity_House3_Lampent::
	lock
	faceplayer
	playmoncry SPECIES_LAMPENT, CRY_MODE_NORMAL
	msgbox EcruteakCity_House3_Lampent_Text_0
	release
	end


EcruteakCity_House3_HexLady_Text_0:
	.string "祸不单行……威力会翻倍……\n命中陷入异常状态的\l对手时……$"

EcruteakCity_House3_HexLady_Text_1:
	.string "趁对手陷入异常状态时攻击……\n这是赢得对战的关键……\p来……拿去吧……$"

EcruteakCity_House3_Lampent_Text_0:
	.string "灯火幽灵：啦唔！$"
