
GoldenrodCity_BillsHouse_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_EeveeMayEvolve:
    .string "正辉：空木博士说，\n伊布可能会用未知的新方式进化。$"
    .string ""

BillHouse_Text_PartyFull:
    .string "等等。你没法再带\n更多宝可梦了。$"
    .string ""

BillHouse_Text_NoEevee:
    .string "哎呀……这可怎么办？$"

BillHouse_Text_PopWontWork:
    .string "正辉：我爸爸他不肯干活，\n整天就知道偷懒。\p真是越来越让人头疼……$"
    .string ""
    .string ""

BillHouse_Text_MomBeforeEcruteak:
    .string "哦，你在收集宝可梦啊？\n我儿子正辉可是专家。\p他刚被叫去缘朱市的\n宝可梦中心。\p我丈夫没接到叫唤就\n自己跑去游戏城了……$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

BillHouse_Text_MomAfterEcruteak:
    .string "我丈夫以前可是个出了名的\n宝可梦狂热迷。\p正辉一定是随了他\n爸爸吧。$"
    .string ""
    .string ""
    .string ""

BillHouse_Text_SisterUsefulNumber:
    .string "你是训练家吗？\p我这有个很有用的\n电话号码给你。$"
    .string ""
    .string ""

BillHouse_Text_RecordedBillsNumber:
    .string "{PLAYER}记下了正辉的号码。$"

BillHouse_Text_SisterRefusedNumber:
    .string "电脑的宝可梦寄放系统\n是我哥哥做的。\p我本来想把正辉的\n电话号码给你的……$"
    .string ""
    .string ""
    .string ""

BillHouse_Text_SisterPhoneFull:
    .string "没法再记录更多号码了。$"

BillHouse_Text_SisterStorageSystem:
    .string "电脑的宝可梦寄放系统\n是我哥哥正辉做的。$"
    .string ""

GoldenrodCity_Bill_GiveEeveeOrPikachu::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_BILL_GIFTMON, GoldenrodCity_Bill_GiveEeveeOrPikachu_2
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_6
	release
	end

GoldenrodCity_Bill_GiveEeveeOrPikachu_2:
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_0
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_1, GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_2, GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_3
	switch VAR_RESULT
	case 0, GoldenrodCity_Bill_GiveEeveeOrPikachu_5
	case 1, GoldenrodCity_Bill_GiveEeveeOrPikachu_6
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_5
	release
	end

GoldenrodCity_Bill_GiveEeveeOrPikachu_5:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE_STARTER
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE_STARTER
	givemon SPECIES_EEVEE_STARTER, 25
	setflag FLAG_GOT_BILL_GIFTMON
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE_STARTER
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_4
	release
	end

GoldenrodCity_Bill_GiveEeveeOrPikachu_6:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PIKACHU_STARTER
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU_STARTER
	givemon SPECIES_PIKACHU_STARTER, 25
	setflag FLAG_GOT_BILL_GIFTMON
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU_STARTER
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_4
	release
	end


GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_0:
	.string "正辉：嗨，{PLAYER}！帮个忙，\n收下这两只宝可梦中的一只吧。\p这两只都是我在调整\n时光胶囊的时候过来的。\p我实在没时间同时\n照顾这两只，有家里人帮忙也不行。\p我觉得这两只都有点\n特别之处，能拜托你收下\l其中一只吗，{PLAYER}？$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_1:
	.string "伊布$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_2:
	.string "皮卡丘$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_3:
	.string "不用了$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_4:
	.string "正辉：我就知道你会答应！\n干得好！那就拜托你\l好好照顾它了！$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_5:
	.string "哎呀……这可怎么办？$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_6:
	.string "说起来，我听说游戏城里\n会派发稀有的宝可梦。$"
