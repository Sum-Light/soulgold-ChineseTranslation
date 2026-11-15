BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3
	
	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	special ValidateBugContestSelectedMon
	goto_if_eq VAR_RESULT, FALSE, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 5
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third

BugContestEventScript_JudgingFinish::
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	call BugContest_EventScript_ChooseFirstPlaceReward
	closemessage
	goto BugContestEventScript_JudgingFinish

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	call BugContest_EventScript_ChooseSecondPlaceReward
	closemessage
	goto BugContestEventScript_JudgingFinish

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	goto BugContestEventScript_JudgingFinish

BugContest_EventScript_ChooseFirstPlaceReward::
	msgbox BugContest_Text_FirstPlaceRewardPrompt, MSGBOX_DEFAULT
	call BugContest_EventScript_ChooseFirstPlaceRewardLoop
	return

BugContest_EventScript_ChooseFirstPlaceRewardLoop::
	dynmultichoice 0, 0, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, BugContest_Text_FirstRewardMoonStone, BugContest_Text_FirstRewardSunStone, BugContest_Text_FirstRewardLeafStone, BugContest_Text_FirstRewardDawnStone, BugContest_Text_FirstRewardShinyStone, BugContest_Text_FirstRewardDuskStone, BugContest_Text_FirstRewardIceStone
	switch VAR_RESULT
	case 0, BugContest_EventScript_SetFirstPlaceMoonStone
	case 1, BugContest_EventScript_SetFirstPlaceSunStone
	case 2, BugContest_EventScript_SetFirstPlaceLeafStone
	case 3, BugContest_EventScript_SetFirstPlaceDawnStone
	case 4, BugContest_EventScript_SetFirstPlaceShinyStone
	case 5, BugContest_EventScript_SetFirstPlaceDuskStone
	case 6, BugContest_EventScript_SetFirstPlaceIceStone
	return

BugContest_EventScript_SetFirstPlaceMoonStone::
	setvar VAR_0x8005, ITEM_MOON_STONE
	return

BugContest_EventScript_SetFirstPlaceSunStone::
	setvar VAR_0x8005, ITEM_SUN_STONE
	return

BugContest_EventScript_SetFirstPlaceLeafStone::
	setvar VAR_0x8005, ITEM_LEAF_STONE
	return

BugContest_EventScript_SetFirstPlaceDawnStone::
	setvar VAR_0x8005, ITEM_DAWN_STONE
	return

BugContest_EventScript_SetFirstPlaceShinyStone::
	setvar VAR_0x8005, ITEM_SHINY_STONE
	return

BugContest_EventScript_SetFirstPlaceDuskStone::
	setvar VAR_0x8005, ITEM_DUSK_STONE
	return

BugContest_EventScript_SetFirstPlaceIceStone::
	setvar VAR_0x8005, ITEM_ICE_STONE
	return

BugContest_EventScript_ChooseSecondPlaceReward::
	msgbox BugContest_Text_SecondPlaceRewardPrompt, MSGBOX_DEFAULT
	call BugContest_EventScript_ChooseSecondPlaceRewardLoop
	return

BugContest_EventScript_ChooseSecondPlaceRewardLoop::
	dynmultichoice 0, 0, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, BugContest_Text_SecondRewardFireStone, BugContest_Text_SecondRewardThunderStone, BugContest_Text_SecondRewardWaterStone
	switch VAR_RESULT
	case 0, BugContest_EventScript_SetSecondPlaceFireStone
	case 1, BugContest_EventScript_SetSecondPlaceThunderStone
	case 2, BugContest_EventScript_SetSecondPlaceWaterStone
	return

BugContest_EventScript_SetSecondPlaceFireStone::
	setvar VAR_0x8005, ITEM_FIRE_STONE
	return

BugContest_EventScript_SetSecondPlaceThunderStone::
	setvar VAR_0x8005, ITEM_THUNDER_STONE
	return

BugContest_EventScript_SetSecondPlaceWaterStone::
	setvar VAR_0x8005, ITEM_WATER_STONE
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special ExitBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSafariBalls
	setflag FLAG_DAILY_BUG_DONE
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK, 18, 2
	waitstate
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK, 35, 7
	releaseall
	end

BugContest_Text_Judging0::
	.string "大赛到此结束。\n请选择要留下并参加评审的\l宝可梦。$"
	.string ""
	.string ""

BugContest_Text_Judging1::
	.string "现在开始评审\n各位捕捉到的宝可梦。\p…… …… ……\n…… …… ……\p获奖者已经决定了！\n准备好了吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BugContest_Text_WrongChoiceMon:
	.string "请选择要留下并参加评审的\n宝可梦。$"
	.string ""

BugContest_Text_DidntCatch:
	.string "哎呀！您没有捉到宝可梦。\n本次大赛视为弃权。\p现在将同行宝可梦归还给您。$"
	.string ""
	.string ""

BugContest_Text_TimesUp:
	.string "叮咚！时间到！$"

BugContest_Text_WhiteOut:
	.string "{PLAYER}没有能战斗的宝可梦了。\n{PLAYER}退出了大赛。$"
	.string ""

BugContest_Text_First1:
	.string "第3名是精英训练家贝琳达，\n捉到的是一只扭来扭去的\l巴大蝶！$"
	.string ""
	.string ""
BugContest_Text_First2:
	.string "第2名是捕虫少年肖恩，\n捉到的是一只扭动不停的\l凯罗斯！$"
	.string ""
	.string ""
BugContest_Text_First3:
	.string "本届捕虫大赛的优胜者是……\p{PLAYER}！\n捉到了个头惊人的{STR_VAR_1}！$"
	.string ""
	.string ""
	.string ""

BugContest_Text_Second1:
	.string "第3名是精英训练家贝琳达，\n捉到的是一只扭来扭去的\l巴大蝶！$"
	.string ""
	.string ""
BugContest_Text_Second2:
	.string "第2名是{PLAYER}，\n捉到了扭动不停的{STR_VAR_1}！$"
	.string ""
BugContest_Text_Second3:
	.string "本届捕虫大赛的优胜者是……\p捕虫少年肖恩！\n捉到了个头惊人的凯罗斯！$"
	.string ""
	.string ""
	.string ""


BugContest_Text_Third1:
	.string "第3名是{PLAYER}，\n捉到了扭来扭去的{STR_VAR_1}！$"
	.string ""
BugContest_Text_Third2:
	.string "第2名是精英训练家贝琳达，\n捉到的是一只扭动不停的\l巴大蝶！$"
	.string ""
	.string ""
BugContest_Text_Third3:
	.string "本届捕虫大赛的优胜者是……\p捕虫少年肖恩！\n捉到了个头惊人的凯罗斯！$"
	.string ""
	.string ""
	.string ""

BugContest_Text_TakePartInFuture:
	.string "感谢您的参与！\n欢迎您今后\l再次参加大赛。$"
	.string ""
	.string ""

BugContest_Text_TransferAndReturn:
	.string "您选择的虫属性宝可梦\n将传送到电脑中，\l同行宝可梦会归还给您。$"
	.string ""
	.string ""

BugContest_Text_FirstPlaceRewardPrompt:
	.string "作为优胜者，\n您可以选择1件特别奖品。$"
	.string ""

BugContest_Text_SecondPlaceRewardPrompt:
	.string "作为第2名的奖品，\n请从这些石头中选择1个。$"
	.string ""

BugContest_Text_FirstRewardMoonStone:
	.string "月之石$"

BugContest_Text_FirstRewardSunStone:
	.string "日之石$"

BugContest_Text_FirstRewardLeafStone:
	.string "叶之石$"

BugContest_Text_FirstRewardDawnStone:
	.string "觉醒之石$"

BugContest_Text_FirstRewardShinyStone:
	.string "光之石$"

BugContest_Text_FirstRewardIceStone:
	.string "冰之石$"

BugContest_Text_FirstRewardDuskStone:
	.string "暗之石$"

BugContest_Text_SecondRewardFireStone:
	.string "火之石$"

BugContest_Text_SecondRewardThunderStone:
	.string "雷之石$"

BugContest_Text_SecondRewardWaterStone:
	.string "水之石$"
