RintoHouse3_MapScripts::
	.byte 0


RintoHouse3_Guard::
	msgbox RintoHouse3_Guard_Text_0, MSGBOX_NPC
	return


RintoHouse3_ResearchGuide::
	msgbox RintoHouse3_ResearchGuide_Text_0, MSGBOX_NPC
	return


RintoHouse3_Hiker::
	msgbox RintoHouse3_Hiker_Text_0, MSGBOX_NPC
	return


RintoHouse3_Researcher::
	msgbox RintoHouse3_Researcher_Text_0, MSGBOX_NPC
	return


RintoHouse3_Excadrill::
	lock
	faceplayer
	playmoncry SPECIES_EXCADRILL, CRY_MODE_NORMAL
	msgbox RintoHouse3_Excadrill_Text_0
	waitmoncry
	release
	end


RintoHouse3_TraderResearcher::
	lock
	faceplayer
	goto_if_set FLAG_RINTO_TRADE_COMPLETE, RintoHouse3_TraderResearcher_2
	ingame_trade INGAME_TRADE_MELTAN, RintoHouse3_TraderResearcher_Text_1, MeltanTrade_Declined, MeltanTrade_NotRequested, RintoHouse3_TraderResearcher_Text_2
	setflag FLAG_RINTO_TRADE_COMPLETE
RintoHouse3_TraderResearcher_1:
	release
	end

RintoHouse3_TraderResearcher_2:
	msgbox RintoHouse3_TraderResearcher_Text_0
	goto RintoHouse3_TraderResearcher_1


MeltanTrade_Declined::
	msgbox MeltanTrade_Declined_Text_0
	release
	end


MeltanTrade_NotRequested::
	msgbox MeltanTrade_NotRequested_Text_0
	release
	end


RintoHouse3_Plaque::
	msgbox RintoHouse3_Plaque_Text_0, MSGBOX_SIGN
	return


RintoHouse3_PlaqueBall::
	msgbox RintoHouse3_PlaqueBall_Text_0, MSGBOX_SIGN
	return


RintoHouse3_Bookshelf::
	msgbox RintoHouse3_Bookshelf_Text_0, MSGBOX_SIGN
	return


RintoHouse3_Painting::
	msgbox RintoHouse3_Painting_Text_0, MSGBOX_SIGN
	return


RintoHouse3_Guard_Text_0:
	.string "楼下只限研究人员\n进入。$"

RintoHouse3_ResearchGuide_Text_0:
	.string "您可以在这里看到\n我们的发掘成果！$"

RintoHouse3_Hiker_Text_0:
	.string "我们在金字塔附近有不少\n发现，可谁也进不去。$"

RintoHouse3_Researcher_Text_0:
	.string "通往金字塔的那扇门……\p它用一种奇怪的金属制成，\n连龙头地鼠的攻击都能弹开。$"

RintoHouse3_Excadrill_Text_0:
	.string "龙头地鼠：咔啊啊啊啊！$"

RintoHouse3_TraderResearcher_Text_0:
	.string "多亏了你的巨锻匠，我们\n也许终于能打穿金字塔的墙！$"

RintoHouse3_TraderResearcher_Text_1:
	.string "我正在研究别的进入\n西边金字塔的办法。\p你手头会不会正好有只巨锻匠？\p它那威力十足的锤击，也许\n能打穿金字塔的一面墙。\p作为回报，我可以送你这只\n稀有的美录坦。怎么样？$"

RintoHouse3_TraderResearcher_Text_2:
	.string "太棒了！我代表整个研究\n团队谢谢你！$"

MeltanTrade_Declined_Text_0:
	.string "哦……这样啊……\p那我只好请人去互连洞里\n找一只来养了……$"

MeltanTrade_NotRequested_Text_0:
	.string "那看起来可不像\n巨锻匠啊。$"

RintoHouse3_Plaque_Text_0:
	.string "这似乎是附近发掘出的\n某种化石。$"

RintoHouse3_PlaqueBall_Text_0:
	.string "一只古老的精灵球。\p它和古代洗翠地区\n使用的很像。$"

RintoHouse3_Bookshelf_Text_0:
	.string "装满历史书的书架。\n有些看起来非常古老！$"

RintoHouse3_Painting_Text_0:
	.string "一幅描绘千年前这片土地\n的画家想象的画。\p你很难辨认出\n画上的落款。$"
