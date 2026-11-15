LakeOfRage_House2_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_ge VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	goto LakeOfRage_House2_EventScript_ChooseMagikarp

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo

LakeOfRage_House2_EventScript_ChooseMagikarp::
	setvar VAR_0x8009, SPECIES_MAGIKARP
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNo
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_REMOVE_IS_EGG, LakeOfRage_House2_EventScript_FisherEgg
	goto_if_eq VAR_RESULT, MON_REMOVE_LAST_USABLE, LakeOfRage_House2_EventScript_LastMon
	goto_if_eq VAR_RESULT, MON_REMOVE_HAS_HELD_ITEM, LakeOfRage_House2_EventScript_FisherHeldItem
	goto_if_eq VAR_RESULT, MON_REMOVE_NO_PAYMENT_ROOM, LakeOfRage_House2_EventScript_FisherNoPaymentRoom
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp
	goto LakeOfRage_House2_EventScript_FisherNotMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherEgg::
	msgbox LakeOfRage_House2_Text_CantAcceptEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherHeldItem::
	msgbox LakeOfRage_House2_Text_RemoveHeldItem, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoPaymentRoom::
	msgbox LakeOfRage_House2_Text_NoPaymentRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	goto_if_ge VAR_LAKE_OF_RAGE_FISHERMAN, 3, LakeOfRage_House2_EventScript_PayForSmallMagikarp
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
LakeOfRage_House2_EventScript_PayForSmallMagikarp::
	callnative UpdateFollowingPokemon
	showmoneybox 0, 0
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end
LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 3
	callnative UpdateFollowingPokemon
	showmoneybox 0, 0
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
    .string "愤怒之湖其实是暴鲤龙\n发狂时留下的坑。\p坑里积蓄了雨水，\n就形成了这座湖。\p这是从我爷爷的曾祖父那代\n传下来的故事。\p以前还能在这里钓到\n活蹦乱跳的鲤鱼王，可是……\p我不明白到底发生了什么。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

LakeOfRage_House2_Text_MenInBlack:
    .string "自从那些穿黑衣的男人来了\n以后，湖就不太正常了。$"
    .string ""

LakeOfRage_House2_Text_LastMon:
    .string "哎，可别让我拿走你最后\n一只宝可梦啊！$"
    .string ""

LakeOfRage_House2_Text_WorldsLargest:
    .string "愤怒之湖恢复正常了。\p鲤鱼王也都回来了。\p我还说不定能实现梦想，\n拥有世界上最大的鲤鱼王。\p其实，你每给我一条鲤鱼王，\n我就付你¥2000，\l大号的鲤鱼王付你¥100,000！$"
    .string ""
    .string ""
    .string ""
    .string ""
	.string ""
	.string ""

LakeOfRage_House2_Text_ForMe:
	.string "那么……你有鲤鱼王\n要给我吗？$"
	.string ""

LakeOfRage_House2_Text_HaveMagikarp:
    .string "啊，你有鲤鱼王！让我看看\n那家伙有多大。$"
    .string ""

LakeOfRage_House2_Text_BigPayout:
    .string "哇！这条真是极品！\p我向你脱帽致敬！\p这点小意思，就当是\n谢礼了。$"
    .string ""
    .string ""
	.string ""

LakeOfRage_House2_Text_Bonus:
    .string "记录才是最重要的。\p就把这个当成额外的奖励吧！$"
    .string ""

LakeOfRage_House2_Text_TooShort:
    .string "哇！这条真是极品！\p……我本想这么说，\n不过我见过更大的。\p我看它也就值这么点吧。$"
    .string ""
    .string ""
    .string ""

LakeOfRage_House2_Text_NotMagikarp:
    .string "什么？这可不是鲤鱼王！$"

LakeOfRage_House2_Text_CantAcceptEgg:
	.string "我不能收下宝可梦的蛋。$"

LakeOfRage_House2_Text_RemoveHeldItem:
	.string "这条鲤鱼王身上带着东西。\p请你先把它取回来。$"
	.string ""

LakeOfRage_House2_Text_NoPaymentRoom:
	.string "你带不了这么多钱。\p请先花掉一些，再回来吧。$"
	.string ""

LakeOfRage_House2_Text_Refused:
    .string "哦……这么说，你没找到\n能让我满意的？那下次吧。$"
    .string ""
