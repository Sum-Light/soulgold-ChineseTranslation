
GoldenrodCity_RadioTower_1F_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "小茜：嗨！\p我叫小茜！\p我听说了播音问答和\n它的特别奖品，\l所以就来参加了……\p可这问答也太难了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

RadioTower1F_Text_Whitney2::
	.string "小茜：哇，你答对了！\p我还以为第三题的答案\n肯定是球果呢！\l哎呀呀！\p该回道馆去了！$"
	.string ""
	.string ""
	.string ""
	.string ""

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	checkitem ITEM_RADIO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ExchangeLegacyRadio
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	goto RadioTowerReceiptionist
	closemessage
	release
	end

RadioTower1F_EventScript_ExchangeLegacyRadio::
	checkitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ExchangeLegacyRadioForBigNugget
	msgbox RadioTower1F_Text_ExchangeLegacyRadioForVsSeeker, MSGBOX_DEFAULT
	removeitem ITEM_RADIO
	giveitem ITEM_VS_SEEKER
	special MigrateLegacyRadioShortcut
	setflag FLAG_ENABLE_RADIO
	msgbox RadioTower1F_Text_LegacyExchangeComplete, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ExchangeLegacyRadioForBigNugget::
	checkitemspace ITEM_BIG_NUGGET
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_LegacyExchangeNoRoom
	msgbox RadioTower1F_Text_ExchangeLegacyRadioForBigNugget, MSGBOX_DEFAULT
	removeitem ITEM_RADIO
	giveitem ITEM_BIG_NUGGET
	special MigrateLegacyRadioShortcut
	setflag FLAG_ENABLE_RADIO
	msgbox RadioTower1F_Text_LegacyExchangeComplete, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_LegacyExchangeNoRoom::
	msgbox RadioTower1F_Text_LegacyExchangeNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGivePrize
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGivePrize::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_QuizPrizeNoRoom
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	createfieldmugshot MUGSHOT_WHITNEY
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

RadioTower1F_EventScript_QuizPrizeNoRoom::
	msgbox RadioTower1F_Text_QuizPrizeNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
    .string "欢迎光临！$"

RadioTower1F_Text_ReceptionistNoTours:
    .string "抱歉，我们今天\n不提供任何参观。$"
    .string ""

RadioTower1F_Text_ExchangeLegacyRadioForVsSeeker:
    .string "哦！您还留着一台\n我们以前的独立收音机。\p现在收音机功能已经内置在\n每台宝可梦装置里了，我们就\l用它给您换一台对战搜寻器吧。$"
    .string ""
    .string ""
    .string ""
    .string ""

RadioTower1F_Text_ExchangeLegacyRadioForBigNugget:
    .string "哦！您还留着一台\n我们以前的独立收音机。\p您已经有它的替换品了，\n就请收下这颗巨大金珠吧。$"
    .string ""
    .string ""
    .string ""

RadioTower1F_Text_LegacyExchangeComplete:
    .string "谢谢您交回旧型号。\n请继续享受我们的广播！$"
    .string ""

RadioTower1F_Text_LegacyExchangeNoRoom:
    .string "我想帮您换掉那台旧收音机，\n可是您的道具口袋满了。\p请腾出空位后\n再来找我。$"
    .string ""
    .string ""
    .string ""

RadioTower1F_Text_RadioCardWomanOfferQuiz:
    .string "我们现在正在举办\n特别的问答活动。\p答对五个问题，\n就能赢得一台对战搜寻器。\p带着它走一走充好电，\n就能再次挑战道路上的训练家。\p您要参加问答吗？$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RadioTower1F_Text_QuizQuestion1:
    .string "第1题：\p只会在白天出现的宝可梦\n存在吗？$"
    .string ""
    .string ""

RadioTower1F_Text_QuizQuestion2:
    .string "答对了！\n第2题：\p这句话对吗？\p在商店买不到树果。$"
    .string ""
    .string ""
    .string ""

RadioTower1F_Text_QuizQuestion3:
    .string "答对了！\n第3题：\p制作精灵球的钢铁，\n用的是球果作材料吗？$"
    .string ""
    .string ""
	.string ""

RadioTower1F_Text_QuizQuestion4:
    .string "进展顺利！\n第4题：\p阿速是使用鸟宝可梦的\n桔梗道馆馆主吗？$"
    .string ""
    .string ""
    .string ""

RadioTower1F_Text_QuizQuestion5:
    .string "哇！又答对了！\n最后一题：\p满金游戏城的老虎机\n图案里有小火龙吗？$"
    .string ""
    .string ""
    .string ""

RadioTower1F_Text_QuizWin:
    .string "全对了！您答对啦！\n恭喜您！\p这是您的奖品，\n一台对战搜寻器！$"
    .string ""
    .string ""

RadioTower1F_Text_TuneIn:
    .string "收音机功能已经内置在\n您的宝可梦装置里了。\p葵妍的密语每天\n晚上6点到深夜播出！$"
    .string ""
    .string ""
	.string ""

RadioTower1F_Text_QuizPrizeNoRoom:
    .string "哎呀，您的关键道具口袋满了。\p请腾出空位后，\n再来挑战一次领取奖品吧。$"
    .string ""
    .string ""

RadioTower1F_Text_WrongAnswer:
    .string "哎呀。\n抱歉，您答错了。\p请再来挑战吧！$"
    .string ""
    .string ""

RadioTower1F_Text_DeclineQuiz:
    .string "哦，这样啊。\n改变主意的话请再来找我。$"
    .string ""

RadioTower1F_Text_Lass:
    .string "靖史是位了不起的DJ。\p他那甜美的声音\n让我心都化了！$"
    .string ""

RadioTower1F_Text_Youngster:
    .string "我喜欢宝可梦讲座的胡桃。\p不过我只知道\n她的声音而已。$"
    .string ""
    .string ""

RadioTower1F_Text_GruntM3Seen:
    .string "我们终于占领了\n播音塔！\p现在，所有人都会体验到\n火箭队的真正恐怖！\p就让你见识见识\n我们有多可怕！$"
    .string ""
    .string ""
    .string ""
    .string ""

RadioTower1F_Text_GruntM3Beaten:
    .string "太强了！老大，对不起……$"

RadioTower1F_Text_GruntM3After:
    .string "你太强了。\p我们的计划可能会泡汤。\n我得去通知其他人……$"
    .string ""
    .string ""

RadioTower1F_Text_Directory:
    .string "1楼　接待处\n2楼　营业部\p3楼　人事部\n4楼　制作部\p5楼　局长室$"
    .string ""
    .string ""
    .string ""
    .string ""


GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	@special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	@special EndLotteryCornerComputerEffect
	delay 10
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "这里是宝可梦彩票中心。\p如果彩票的号码与您任意一只\n宝可梦的ID号码有相同数字，\l就能获得精美的奖品。\p您要抽一张宝可梦\n彩票吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "请明天再来。$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "欢迎您下次再来。$"

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "请抽一张彩票。\n…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"
	.string ""

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "彩票的号码是{STR_VAR_1}。\p我需要核对这个号码，\n看看它与您的宝可梦的\lID号码有没有一致。请稍等。$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "恭喜您！\p您队伍中{STR_VAR_1}的\nID号码与您的\l彩票号码一致！$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "恭喜您！\p您电脑里存放的{STR_VAR_1}\n的ID号码与您的\l彩票号码一致！$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "很抱歉。\n一个号码都没对上。$"
	.string ""

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "对上了两位数字，您获得了\n三等奖！\l您得到了{STR_VAR_1}！$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "对上了三位数字，您获得了\n二等奖！\l您得到了{STR_VAR_1}！$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "对上了四位数字，您获得了\n头等奖！\l您得到了{STR_VAR_1}！$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "哎呀呀，五位数字\n全都对上了！\p您中了头奖！\n您得到了{STR_VAR_1}！$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "哦？\n您好像拿不下这个了。\p请整理好包包，\n然后告诉我。$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "{PLAYER}？\n是的，我一直在等您。\p这是给您留着的奖品。$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "欢迎您下次再来。$"

RadioTowerReceiptionist::
	compare VAR_GOLDENROD_CITY_STATE, 6
	goto_if_ge RadioTowerReceiptionist_4
RadioTowerReceiptionist_3:
	msgbox RadioTowerReceiptionist_Text_1
RadioTowerReceiptionist_1:
	release
	end

RadioTowerReceiptionist_2:
	msgbox RadioTowerReceiptionist_Text_0
	goto RadioTowerReceiptionist_1

RadioTowerReceiptionist_4:
	compare VAR_GOLDENROD_CITY_STATE, 10
	goto_if_lt RadioTowerReceiptionist_2
	goto RadioTowerReceiptionist_3


RadioTowerReceiptionist_Text_0:
	.string "等等，不对，救命！\n警察呢？$"

RadioTowerReceiptionist_Text_1:
	.string "抱歉，我们今天\n不提供任何参观。$"
