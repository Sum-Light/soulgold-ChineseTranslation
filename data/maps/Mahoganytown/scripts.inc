.set LOCALID_MAHOGANY_MERCHANT, 3

Mahoganytown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Mahoganytown_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Mahoganytown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Mahoganytown_OnFrame
	.byte 0

Mahoganytown_OnLoad::
	call_if_ge VAR_MAHOGANY_TOWN_STATE, 13, MahoganyTown_EventScript_FixTree
	setrespawn HEAL_LOCATION_MAHOGANYTOWN
	end

MahoganyTown_EventScript_FixTree::
	setmetatile 18, 8, 0x4F8, FALSE
	setmetatile 19, 8, 0x4F9, FALSE
	end

Mahoganytown_OnFrame::
	map_script_2 VAR_TEMP_F, 1, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

Mahoganytown_OnTransition::
	call Common_EventScript_CheckElmRocketCall
	end

Common_EventScript_CheckElmRocketCall::
	setvar VAR_TEMP_F, 0
	goto_if_ne VAR_MAHOGANY_TOWN_STATE, 15, Common_EventScript_CheckElmRocketCall_Done
	goto_if_lt VAR_NUM_BADGES, 7, Common_EventScript_CheckElmRocketCall_Done
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 6, Common_EventScript_CheckElmRocketCall_Done
	setvar VAR_TEMP_F, 1
Common_EventScript_CheckElmRocketCall_Done:
	return

Mahoganytown_EventScript_RocketTrigger::
	lock
	setvar VAR_TEMP_F, 0
	pokenavcall ElmPhoneRadioTowerRocketTakeoverText
	waitmessage
	setvar VAR_GOLDENROD_CITY_STATE, 6
	clearflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	setflag FLAG_HIDE_GOLDENROD_NPCS
	setflag FLAG_HIDE_RADIOF5DUDE
	clearflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setvar VAR_MAHOGANY_TOWN_STATE, 16
	delay 10
	release
	end

MahoganyTown_EventScript_TownTrigger::
	clearflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_HIDE_MAHOGANY_TOWN_FATMAN
	clearflag FLAG_HIDE_MAHOGANY_ROCKETS
	clearflag FLAG_GOT_TM_FROM_MAHOGANY_COP
	clearflag FLAG_GOT_BLACK_BELT
	clearflag FLAG_ROCKETHIDEOUT_SWITCH
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_GATE
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GATE
	clearflag FLAG_GOT_PASSWORD_FROM_ETO
	clearflag FLAG_GOT_PASSWORD_FROM_GRUNTF 
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROW
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	clearflag FLAG_HIDE_ROCKETHIDEOUT_ELECTRODE1 
	clearflag FLAG_HIDE_ROCKETHIDEOUT_ELECTRODE2
	clearflag FLAG_HIDE_ROCKETHIDEOUT_ELECTRODE3 
	clearflag FLAG_GOT_HIDDEN_POWER
	clearflag FLAG_HIDE_ICE_PATH_KIMONO

	setflag FLAG_VISITED_MAHOGANY_TOWN
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	setflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	setflag FLAG_HIDE_MAHOGANY_COP
	setflag FLAG_HIDE_ROCKETHIDEOUT_ROCKETS
	setflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT

	setvar VAR_ROCKET_HIDEOUT_STATUE_1, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_2, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_3, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_4, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_5, 0
	setvar VAR_ROCKET_PASSWORD, 0
	setvar VAR_ELECTRODES_FAINTED, 0
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 0
	setvar VAR_ICE_PATH_STATE, 0
	setvar VAR_ROUTE27_BAOBA_CALL, 0

	setvar VAR_MAHOGANY_TOWN_STATE, 1

	@blackthorn flagheap
	setvar VAR_BLACKTHORN_CITY_STATE, 1
    setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_SILVER
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_LANCE
	setflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	clearflag FLAG_GOT_SPELL_TAG
	clearflag FLAG_GOT_DRATINI
	setvar VAR_BLACKTHORN_GYM_STATE, 0
	setvar VAR_DRAGONS_DEN_QUIZ, 0
	end

MahoganyTown_EventScript_MerchantTrigger::
	lock
	turnobject LOCALID_MAHOGANY_MERCHANT, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_MAHOGANY_MERCHANT, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 14, MahoganyTown_EventScript_WalkUp2
	call_if_eq VAR_TEMP_1, 13, MahoganyTown_EventScript_WalkUp1
	showmoneybox 0, 0
	msgbox MahoganyTown_Text_RageCandyBarMerchantTryOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantRefused
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantBroke
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	waitse
	hidemoneybox
	msgbox MahoganyTown_Text_RageCandyBarMerchantSavorIt, MSGBOX_DEFAULT
	giveitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	end

MahoganyTown_EventScript_WalkUp1::
	applymovement OBJ_EVENT_ID_PLAYER, MahoganyTown_Movement_PlayerMerchant1
	waitmovement 0
	return

MahoganyTown_EventScript_WalkUp2::
	applymovement OBJ_EVENT_ID_PLAYER, MahoganyTown_Movement_PlayerMerchant2
	waitmovement 0
	return

MahoganyTown_EventScript_Merchant::
	lock
	faceplayer
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 17, MahoganyTown_EventScript_MerchantAfter
	showmoneybox 0, 0
	msgbox MahoganyTown_Text_RageCandyBarMerchantTryOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantRefused
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantBroke
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	waitse
	hidemoneybox
	msgbox MahoganyTown_Text_RageCandyBarMerchantSavorIt, MSGBOX_DEFAULT
	giveitem ITEM_RAGE_CANDY_BAR
	hidemoneybox
	closemessage
	release
	end

MahoganyTown_EventScript_MerchantRefused::
	msgbox MahoganyTown_Text_RageCandyBarMerchantRefused, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	end

MahoganyTown_EventScript_MerchantBroke::
	msgbox MahoganyTown_Text_RageCandyBarMerchantNotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	end

MahoganyTown_EventScript_NotEnoughSpace:
	msgbox MahoganyTown_Text_RageCandyBarMerchantRefused, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	return

MahoganyTown_EventScript_MerchantAfter::
	msgbox MahoganyTown_Text_RageCandyBarMerchantSoldOut, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_PushPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

MahoganyTown_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 6, MahoganyTown_EventScript_GrampsAfter
	msgbox MahoganyTown_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_GrampsAfter::
	msgbox MahoganyTown_Text_GrampsClearedRocketHideout, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_Fisher::
	lock
	faceplayer
	msgbox MahoganyTown_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_Lass::
	lock
	faceplayer
	msgbox MahoganyTown_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_Sign::
	lock
	msgbox MahoganyTown_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

MahoganyTown_EventScript_CandybarSign::
	lock
	msgbox MahoganyTown_Text_RagecandybarSign, MSGBOX_SIGN
	closemessage
	release
	end

MahoganyTown_EventScript_GymSign::
	lock
	msgbox MahoganyTown_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

MahoganyTown_Movement_PlayerMerchant1:
	walk_up
	step_end

MahoganyTown_Movement_PlayerMerchant2:
	walk_up
	walk_up
	step_end

MahoganyTown_Text_RageCandyBarMerchantTryOne:
	.string "哟，小家伙！\p我看你是刚到卡吉镇吧。\p既然是新来的，就该尝尝\n美味的愤怒馒头！\p现在只要¥300\n就能买到一个！要来一个吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MahoganyTown_Text_RageCandyBarMerchantSavorIt:
    .string "好！慢慢享用吧！$"

MahoganyTown_Text_RageCandyBarMerchantNotEnoughMoney:
    .string "您的钱不够啊。$"

MahoganyTown_Text_RageCandyBarMerchantRefused:
    .string "啊，这样啊……$"

MahoganyTown_Text_RageCandyBarMerchantSoldOut:
    .string "愤怒馒头卖完了。\p我正收拾摊子呢。小家伙，\n别来烦我。$"
    .string ""
    .string ""

MahoganyTown_Text_Gramps:
    .string "你是要去看湖里\n暴鲤龙大肆闹腾吗？$"
    .string ""

MahoganyTown_Text_GrampsClearedRocketHideout:
    .string "鲤鱼王又回到了愤怒之湖。\p对在那儿钓鱼的人来说，\n这可是个好消息。$"
    .string ""
    .string ""
    .string ""

MahoganyTown_Text_Fisher:
    .string "既然你都大老远来了，就花点时间\n四处逛逛吧。\p你现在就该往北走，\n去愤怒之湖看看。$"
    .string ""
    .string ""
    .string ""

MahoganyTown_Text_Lass:
    .string "去奶奶的店里转转吧。\n她卖的东西别处可没有。$"
    .string ""

MahoganyTown_Text_Sign:
    .string "卡吉镇\p欢迎来到忍者之乡$"
    .string ""

MahoganyTown_Text_RagecandybarSign:
    .string "来到卡吉镇，\n请尝尝愤怒馒头！$"
    .string ""

MahoganyTown_Text_GymSign:
    .string "卡吉镇宝可梦道馆\p馆主：柳伯\p严冬的教导者$"
    .string ""
    .string ""

ElmPhoneRadioTowerRocketTakeoverText:
	.string "空木博士：{PLAYER}，\n最近还好吗？\p我打电话来，\n是因为广播节目里\l出了些怪事。\p节目里提到了火箭队。\p{PLAYER}，这件事\n你知道些什么吗？\p难道是火箭队又回来了。\n不会吧，这怎么可能。\p抱歉打扰你了。\n保重！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

ElmPhoneRoute39LegendaryText:
	.string "空木博士：哎呀！\n{PLAYER}，你看见了吗？！\p一只巨大的宝可梦刚刚飞过了\n缘朱市！\l我在研究所里都看见了！\p难道是传说的\n宝可梦？？\p它好像朝西边飞去了，\n往39号道路那边。\p{PLAYER}！\n这可是难得的好机会，\l快去追吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
