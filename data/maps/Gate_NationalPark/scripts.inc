Gate_NationalPark_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_AttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 1
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 1
	waitstate
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::	
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	release
	end	

Gate_NationalPark_EventScript_AttendantCancel::	
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_AttendantExit::
	special LoadPlayerParty
	setvar VAR_BUG_CONTEST_STATE, 0
	release
	end

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_BAttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
	.string "训练家您好！捕虫大赛\n每天举办一次。\p规则很简单。\p用您自己的一只宝可梦\n捉到虫宝可梦来接受评审。\p您要试试看吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route35NationalParkGate_Text_OfficerGiveParkBalls:
	.string "比赛期间宝可梦获得的经验值，\n会在您离开时\l恢复原样。\p这是比赛用的狩猎球。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route35NationalParkGate_Text_ReceivedParkBalls:
	.string "{PLAYER}得到了狩猎球。$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "捉到最强虫宝可梦的人\n就是优胜者。\p狩猎球用完，\n比赛就结束了。\p最多能捉5只宝可梦。\n最后捉到的那只\l才会留下并参加评审。\p去吧，尽量捉到\n最强的虫宝可梦！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "如果您有不止一只宝可梦，\n就得使用队伍里\l第一只宝可梦。\p这样可以吗？$"
	.string ""
	.string ""
	.string ""

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "好的，比赛期间，\n我们会替您保管其他宝可梦。$"
	.string ""

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "{PLAYER}的宝可梦\n交给了大赛工作人员。$"
	.string ""

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "请先选出要参加比赛的\n宝可梦，再来找我。$"
	.string ""

Route35NationalParkGate_Text_TakePartInFuture:
	.string "好的。希望您下次\n来参加。$"
	.string ""

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "哎呀……您队伍里第一只\n宝可梦无法战斗。\p请把它和您想用的宝可梦\n交换位置，再来找我。$"
	.string ""
	.string ""
	.string ""

Route35NationalParkGate_Text_MakeRoom:
	.string "哎呀……您的队伍和\n电脑盒子都满了。\p捉到的虫宝可梦\n没有地方放。\p请先在队伍或电脑盒子里\n腾出空位，再来找我。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "哎呀……您队伍里第一只是蛋。\p请把它和您想用的宝可梦\n交换位置，再来找我。$"
	.string ""
	.string ""
	.string ""

Route35NationalParkGate_Text_ContestIsOver:
	.string "今天的比赛已经结束了。\n希望您下次再来参加。$"
	.string ""

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
	.string "我最喜欢鸟宝可梦了！\n昨晚我在公园里\l发现了一只恶属性的鸟！$"
	.string ""
	.string ""

Route35NationalParkGate_Text_BC2:
	.string "我捉到了一只超大的飞天螳螂！$"

Route35NationalParkGate_Text_Beauty:
	.string "他每次比赛都能赢！$"

Route35NationalParkGate_Text_WeHoldContests:
	.string "公园里会定期举办比赛。\n你也去试试吧。$"
	.string ""

Route35NationalParkGate_Text_YoungsterWonders:
	.string "下一次捕虫大赛\n是什么时候啊？$"
	.string ""

Route35NationalParkGate_Text_ContestExplanation:
	.string "捕虫大赛在周二、周四\n和周六举办。\p不光参赛就有奖品，\p比赛结束时手上的\n虫宝可梦也能带走。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
