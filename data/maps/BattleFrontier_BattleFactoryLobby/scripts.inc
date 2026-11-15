
BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 2, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LEVEL_CHOICE_INNATES, BattleFrontier_BattleFactoryLobby_EventScript_Innates
	case FRONTIER_LEVEL_CHOICE_INFO, BattleFrontier_BattleFactoryLobby_EventScript_LevelInfo
	case FRONTIER_LEVEL_CHOICE_BGM, BattleFrontier_BattleFactoryLobby_EventScript_Bgm
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LevelInfo::
	call BattleFrontier_EventScript_ShowLevelModeInfo
	goto BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_Innates::
	call BattleFrontier_EventScript_ChooseInnates
	goto BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_Bgm::
	call BattleFrontier_EventScript_ChooseBattleBgm
	goto BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "训练家的才智\n将在此接受考验！\p欢迎来到对战工厂！\p我是您的交换式对战\n单打锦标赛向导。$"
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "您要挑战交换式对战\n单打锦标赛吗？$"
	.string ""

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "交换式对战单打锦标赛\n是一项只使用租借宝可梦的\l单打对战比赛。\p首先，您会领到三只\n专为本活动准备的宝可梦。\p请用领到的租借宝可梦，\n进行单打对战。\p获胜后，您可以交换\n其中一只租借宝可梦。\p重复对战与交换的过程——\n连续获胜七次，\l就能获得对战点数。\p如果想中断挑战，\n请先保存游戏。\p若没有保存，\n您的挑战将被取消资格。$"
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
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "期待您的再次光临。$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "您想挑战哪个等级？\n经典还是混沌？$"
	.string ""

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "在您开始挑战之前，\n我需要保存游戏。可以吗？$"
	.string ""

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "好的，在您比赛期间，\n您的宝可梦由我保管。$"
	.string ""

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "请往这边走。$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "感谢您参加！\p我会把租借的宝可梦收回，\n将您的宝可梦还给您。\p我还需要保存活动结果。\n请稍等。$"
	.string ""
	.string ""
	.string ""
	.string ""

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "我会把租借的宝可梦收回，\n将您的宝可梦还给您。$"
	.string ""

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "恭喜！您在交换式对战中\n赢得了七连胜！$"
	.string ""

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "为表彰您的七连胜，\n特此授予您这些对战点数。$"
	.string ""

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "哦，哦，哦！\p您的对战点数已经满了。\p请用掉一些对战点数\n后再来吧。$"
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "我们一直在等您！\p在继续您的挑战之前，\n我需要先保存游戏。$"
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "很抱歉，上次您退出游戏前\n没有保存。\p因此，您的挑战\n已被取消资格。$"
	.string ""
	.string ""
	.string ""

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "现在把您自己的宝可梦还给您。$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER}得到了奖品\n{STR_VAR_1}。$"
	.string ""

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "训练家的才智\n将在此接受考验！\p欢迎来到对战工厂！\p我是您的交换式对战\n双打锦标赛向导。$"
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "您要挑战交换式对战\n双打锦标赛吗？$"
	.string ""

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "交换式对战双打锦标赛\n是一项只使用租借宝可梦的\l双打对战比赛。\p首先，您会领到三只\n专为本活动准备的宝可梦。\p请用领到的租借宝可梦，\n进行双打对战。\p获胜后，您可以交换\n其中一只租借宝可梦。\p重复对战与交换的过程——\n连续获胜七次，\l就能获得对战点数。\p如果想中断挑战，\n请先保存游戏。\p中断前若没有保存，\n将被取消资格。$"
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
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "击败工厂头目\n并拿下七连胜，\l恭喜您！$"
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "为表彰您渊博的学识\n与敏锐的才智，\l特此授予您这些对战点数。$"
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "让我把您的宝可梦\n换成租借宝可梦。\p我需要保存对战数据，\n请稍等。$"
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "要把您上一场对战工厂的比赛\n记录到\l开拓通行证上吗？$"
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "嗨！\n那边那位！\p您是不是觉得，这里不用带\n自己练好的队伍，\l活动都很轻松？\p我可不敢说赢起来\n真那么容易。\p要是对宝可梦和招式没有\n充分的了解，\l想一直赢下去可不容易。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "我换了一只很弱的宝可梦……\n还以为那是个不错的种类……\p结果我们被打得一败涂地……$"
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "我最近事事都不顺。\p对战时得仔细观察\n对手的宝可梦，\l看看强不强。$"
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "您知道吗，这里的工作人员会\n给您一些下一位对手的提示？\p唉，我都这么大个人了，\n可还是琢磨不透那些提示。$"
	.string ""
	.string ""
	.string ""

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "我啊，其实挺强的，\n可就是很容易腻，\l于是一直不停地交换和对战。\p后来我一次次参加\n交换式对战活动，\l发现租借的宝可梦每次都不一样。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "上面列出了交换式对战的规则。$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "您想读哪个标题？$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "在交换式对战活动中，\n只能使用三只宝可梦。\p无论是租借还是交换，\n队伍里都不能有两只以上\l同种的宝可梦。$"
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "只能和您刚刚击败的训练家\n交换宝可梦。\p能交换的，也只有那位被击败的\n训练家用过的宝可梦。$"
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "每赢下一场对战，您就可以\n交换一只被击败的\l对手的宝可梦。\p活动中，您不能与第七位\n训练家交换宝可梦。$"
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "交换宝可梦时，有两点\n需要特别注意。\p第一，交换时无法查看\n即将收下的宝可梦的\l能力数据。\p第二，队伍中的宝可梦会按照\n您租借它们的顺序\l依次排列。\p即使进行了交换，\n这个顺序也不会改变。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "在混沌模式中，租借的宝可梦\n和对手训练家的宝可梦\l全都是100级。$"
	.string ""
	.string ""

FactoryBpLady::
	lock
	faceplayer
	msgbox FactoryBpLady_Text_0
	goto_if_set FLAG_BADGE08_GET, FactoryBpLady_2
	bpmart FactoryBpMart
FactoryBpLady_1:
	msgbox FactoryBpLady_Text_1
	release
	end

FactoryBpLady_2:
	bpmart FactoryBpMart8Badges
	goto FactoryBpLady_1


	.align 2
FactoryBpMart:
	.2byte ITEM_HEALTH_FEATHER
	.2byte ITEM_MUSCLE_FEATHER
	.2byte ITEM_RESIST_FEATHER
	.2byte ITEM_GENIUS_FEATHER
	.2byte ITEM_CLEVER_FEATHER
	.2byte ITEM_SWIFT_FEATHER
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_BECKONING_BELL
	.2byte ITEM_NONE

	.align 2
FactoryBpMart8Badges:
	.2byte ITEM_NUGGET
	.2byte ITEM_BIG_NUGGET
	.2byte ITEM_HEALTH_FEATHER
	.2byte ITEM_MUSCLE_FEATHER
	.2byte ITEM_RESIST_FEATHER
	.2byte ITEM_GENIUS_FEATHER
	.2byte ITEM_CLEVER_FEATHER
	.2byte ITEM_SWIFT_FEATHER
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_BECKONING_BELL
	.2byte ITEM_NONE

FactoryBpLady_Text_0:
	.string "欢迎光临！$"

FactoryBpLady_Text_1:
	.string "谢谢惠顾！$"
