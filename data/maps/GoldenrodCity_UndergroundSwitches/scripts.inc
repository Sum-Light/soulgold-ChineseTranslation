.set LOCALID_GOLDENROD_UNDERGROUND_SILVER, 7

GoldenrodCity_UndergroundSwitches_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodUnderground1_OnLoad
	.byte 0

GoldenrodUnderground1_OnLoad::
	call GoldenrodCity_UndergroundSwitches_EventScript_ClearSwitchState
	goto_if_set FLAG_COMPLETED_SWITCHES, GoldenrodUnderground1_LoadSolved
	clearflag FLAG_GOLDENROD_ALL_SHUTTERS_OPEN
	call GoldenrodCity_UndergroundSwitches_EventScript_CloseAllShutters
	goto GoldenrodUnderground1_RescuePlayerInShutter

GoldenrodUnderground1_LoadSolved::
	goto_if_set FLAG_GOLDENROD_ALL_SHUTTERS_OPEN, GoldenrodUnderground1_LoadAllShuttersOpen
	call GoldenrodUnderground1_ClearTheWay
	goto GoldenrodUnderground1_RescuePlayerInShutter

GoldenrodUnderground1_LoadAllShuttersOpen::
	call GoldenrodCity_UndergroundSwitches_EventScript_OpenAllShutters
	goto GoldenrodUnderground1_RescuePlayerInShutter

GoldenrodUnderground1_RescuePlayerInShutter::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 7, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_1, 8, GoldenrodUnderground1_RescuePlayerInUpperShutter
	goto_if_lt VAR_TEMP_1, 11, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_1, 12, GoldenrodUnderground1_RescuePlayerInLowerShutter

GoldenrodUnderground1_EndLoad::
	end

GoldenrodUnderground1_RescuePlayerInUpperShutter::
	goto_if_lt VAR_TEMP_0, 5, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 7, GoldenrodUnderground1_RescuePlayerInShutter1
	goto_if_lt VAR_TEMP_0, 14, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 16, GoldenrodUnderground1_RescuePlayerInShutter2
	goto_if_lt VAR_TEMP_0, 23, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 25, GoldenrodUnderground1_RescuePlayerInShutter3
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInLowerShutter::
	goto_if_lt VAR_TEMP_0, 5, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 7, GoldenrodUnderground1_RescuePlayerInShutter4
	goto_if_lt VAR_TEMP_0, 14, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 16, GoldenrodUnderground1_RescuePlayerInShutter5
	goto_if_lt VAR_TEMP_0, 23, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 25, GoldenrodUnderground1_RescuePlayerInShutter6
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter1::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter2::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter3::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter4::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter5::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter6::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall6
	goto GoldenrodUnderground1_EndLoad

GoldenrodCity_UndergroundSwitches_EventScript_ClearSwitchState::
	clearflag FLAG_GOLDENROD_SWITCH_1
	clearflag FLAG_GOLDENROD_SWITCH_2
	clearflag FLAG_GOLDENROD_SWITCH_3
	return

GoldenrodUnderground1_ClearTheWay::
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	return

@Added and antisoft lock, using wall panels

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock::
	lock
	msgbox GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_TP
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_TP::
	warp MAP_GOLDENROD_CITY_UNDERGROUND_SWITCHES, 2, 25, 5
	waitstate
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text::
	.string "要回到入口，\n重新设置开关吗？$"
	.string ""

@ The sequence is deliberately strict: 3 -> 2 -> 1.
@ Pressing any other switch resets both the visible shutters and the switch flags.
GoldenrodCity_UndergroundSwitches_EventScript_Panel1::
	lock
	goto_if_set FLAG_COMPLETED_SWITCHES, GoldenrodCity_UndergroundSwitches_EventScript_AlreadySolved
	goto_if_set FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_unset FLAG_GOLDENROD_SWITCH_2, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_unset FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	setflag FLAG_GOLDENROD_SWITCH_1
	playse SE_CLICK
	setflag FLAG_COMPLETED_SWITCHES
	msgbox GoldenrodUnderground_Text_SequenceComplete, MSGBOX_DEFAULT
	closemessage
	call GoldenrodUnderground1_ClearTheWay
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel2::
	lock
	goto_if_set FLAG_COMPLETED_SWITCHES, GoldenrodCity_UndergroundSwitches_EventScript_AlreadySolved
	goto_if_set FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_set FLAG_GOLDENROD_SWITCH_2, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_unset FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	setflag FLAG_GOLDENROD_SWITCH_2
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_SequenceStep2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel3::
	lock
	goto_if_set FLAG_COMPLETED_SWITCHES, GoldenrodCity_UndergroundSwitches_EventScript_AlreadySolved
	goto_if_set FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_set FLAG_GOLDENROD_SWITCH_2, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_set FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	setflag FLAG_GOLDENROD_SWITCH_3
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_SequenceStep1, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence::
	call GoldenrodCity_UndergroundSwitches_EventScript_ClearSwitchState
	clearflag FLAG_GOLDENROD_ALL_SHUTTERS_OPEN
	playse SE_FAILURE
	msgbox GoldenrodUnderground_Text_SequenceReset, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CloseAllShutters
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_EmergencyRelease::
	lock
	goto_if_unset FLAG_COMPLETED_SWITCHES, GoldenrodCity_UndergroundSwitches_EventScript_EmergencyReleaseLocked
	goto_if_set FLAG_GOLDENROD_ALL_SHUTTERS_OPEN, GoldenrodCity_UndergroundSwitches_EventScript_AllShuttersAlreadyOpen
	setflag FLAG_GOLDENROD_ALL_SHUTTERS_OPEN
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_EmergencyRelease, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_OpenAllShutters
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_EmergencyReleaseLocked::
	msgbox GoldenrodUnderground_Text_EmergencyReleaseLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AllShuttersAlreadyOpen::
	msgbox GoldenrodUnderground_Text_AllShuttersAlreadyOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AlreadySolved::
	msgbox GoldenrodUnderground_Text_AlreadySolved, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_CloseAllShutters::
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	return

GoldenrodCity_UndergroundSwitches_EventScript_OpenAllShutters::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall6
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1::
	setmetatile 5, 7, 0x519, FALSE
	setmetatile 6, 7, 0x51A, FALSE
	setmetatile 7, 7, 0x51B, FALSE

	setmetatile 5, 8, 0x521, FALSE
	setmetatile 6, 8, 0x522, FALSE
	setmetatile 7, 8, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2::
	setmetatile 14, 7, 0x519, FALSE
	setmetatile 15, 7, 0x51A, FALSE
	setmetatile 16, 7, 0x51B, FALSE

	setmetatile 14, 8, 0x521, FALSE
	setmetatile 15, 8, 0x522, FALSE
	setmetatile 16, 8, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3::
	setmetatile 23, 7, 0x519, FALSE
	setmetatile 24, 7, 0x51A, FALSE
	setmetatile 25, 7, 0x51B, FALSE

	setmetatile 23, 8, 0x521, FALSE
	setmetatile 24, 8, 0x522, FALSE
	setmetatile 25, 8, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4::
	setmetatile 5, 11, 0x519, FALSE
	setmetatile 6, 11, 0x51A, FALSE
	setmetatile 7, 11, 0x51B, FALSE

	setmetatile 5, 12, 0x521, FALSE
	setmetatile 6, 12, 0x522, FALSE
	setmetatile 7, 12, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5::
	setmetatile 14, 11, 0x519, FALSE
	setmetatile 15, 11, 0x51A, FALSE
	setmetatile 16, 11, 0x51B, FALSE

	setmetatile 14, 12, 0x521, FALSE
	setmetatile 15, 12, 0x522, FALSE
	setmetatile 16, 12, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6::
	setmetatile 23, 11, 0x519, FALSE
	setmetatile 24, 11, 0x51A, FALSE
	setmetatile 25, 11, 0x51B, FALSE

	setmetatile 23, 12, 0x521, FALSE
	setmetatile 24, 12, 0x522, FALSE
	setmetatile 25, 12, 0x523, FALSE
	return
@======================================================================================================================

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1::
	setmetatile 5, 7, 0x4F8, FALSE
	setmetatile 6, 7, 0x4F9, FALSE
	setmetatile 7, 7, 0x4FA, FALSE
	
	setmetatile 5, 8, 0x500, FALSE
	setmetatile 6, 8, 0x501, FALSE
	setmetatile 7, 8, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2::
	setmetatile 14, 7, 0x4F8, FALSE
	setmetatile 15, 7, 0x4F9, FALSE
	setmetatile 16, 7, 0x4FA, FALSE
	
	setmetatile 14, 8, 0x500, FALSE
	setmetatile 15, 8, 0x501, FALSE
	setmetatile 16, 8, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3::
	setmetatile 23, 7, 0x4F8, FALSE
	setmetatile 24, 7, 0x4F9, FALSE
	setmetatile 25, 7, 0x4FA, FALSE
	
	setmetatile 23, 8, 0x500, FALSE
	setmetatile 24, 8, 0x501, FALSE
	setmetatile 25, 8, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4::
	setmetatile 5, 11, 0x4F8, FALSE
	setmetatile 6, 11, 0x4F9, FALSE
	setmetatile 7, 11, 0x4FA, FALSE
	
	setmetatile 5, 12, 0x500, FALSE
	setmetatile 6, 12, 0x501, FALSE
	setmetatile 7, 12, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5::
	setmetatile 14, 11, 0x4F8, FALSE
	setmetatile 15, 11, 0x4F9, FALSE
	setmetatile 16, 11, 0x4FA, FALSE
	
	setmetatile 14, 12, 0x500, FALSE
	setmetatile 15, 12, 0x501, FALSE
	setmetatile 16, 12, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall6::
	setmetatile 23, 11, 0x4F8, FALSE
	setmetatile 24, 11, 0x4F9, FALSE
	setmetatile 25, 11, 0x4FA, FALSE
	
	setmetatile 23, 12, 0x500, FALSE
	setmetatile 24, 12, 0x501, FALSE
	setmetatile 25, 12, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerTop::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	@clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	createfieldmugshot MUGSHOT_SILVER
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	createfieldmugshot MUGSHOT_SILVER
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	setvar VAR_GOLDENROD_CITY_STATE, 9
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerBot::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	createfieldmugshot MUGSHOT_SILVER
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	createfieldmugshot MUGSHOT_SILVER
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	setvar VAR_GOLDENROD_CITY_STATE, 9
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_4, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_4, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_4, GoldenrodUnderground_Text_SilverWin
	return



GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_right
	step_end


GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end	

GoldenrodCity_UndergroundSwitches_EventScript_Grunt10::
    trainerbattle_single TRAINER_GRUNT_10, GoldenrodUnderground_Text_GruntM11Seen, GoldenrodUnderground_Text_GruntM11Beaten
	msgbox GoldenrodUnderground_Text_GruntM11After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt20::
    trainerbattle_single TRAINER_GRUNT_20, GoldenrodUnderground_Text_GruntM25Seen, GoldenrodUnderground_Text_GruntM25Beaten
	msgbox GoldenrodUnderground_Text_GruntM25After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Duncan::
    trainerbattle_single TRAINER_DUNCAN, GoldenrodUnderground_Text_BurglarDuncanSeen, GoldenrodUnderground_Text_BurglarDuncanBeaten
	msgbox GoldenrodUnderground_Text_BurglarDuncanAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Eddie::
    trainerbattle_single TRAINER_EDDIE, GoldenrodUnderground_Text_BurglarEddieSeen, GoldenrodUnderground_Text_BurglarEddieBeaten
	msgbox GoldenrodUnderground_Text_BurglarEddieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt11::
    trainerbattle_single TRAINER_GRUNT_11, GoldenrodUnderground_Text_GruntM13Seen, GoldenrodUnderground_Text_GruntM13Beaten
	msgbox GoldenrodUnderground_Text_GruntM13After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt27::
    trainerbattle_single TRAINER_GRUNT_27, GoldenrodUnderground_Text_GruntF3Seen, GoldenrodUnderground_Text_GruntF3Beaten
	msgbox GoldenrodUnderground_Text_GruntF3After, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_Text_SilverBefore:
    .string "站住！\p我看到你了，就一直跟着。\p我要去收拾火箭队，\n可不需要你在旁边碍事。\p……等等。你以前打赢过我，\n对吧？\p那不过是碰巧。\p我一直在锻炼我的队伍，\n现在该还这笔账了！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

GoldenrodUnderground_Text_SilverWin:
    .string "……为什么……\n我为什么会输？\p我明明集齐了最强的宝可梦。\p我也一点没有松劲。\p那我为什么还会输？$"
    .string ""
    .string ""
    .string ""

GoldenrodUnderground_Text_SilverAfter:
    .string "……我不明白……\p那个叫阿渡的家伙说的，\n是真的吗？\p说我没有好好对待宝可梦？\p爱……\p信任……\p我缺少的，真的是这些吗？\p就是这些让我赢不了吗？\p我……我实在不明白。\p但事情不会就这样结束。\p不会是现在。不会因为这种事。\p我不会放弃成为世界第一\n宝可梦训练家的梦想！$"
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

GoldenrodUnderground_Text_SilverLoss:
    .string "哼。这才是我的真正实力，\n废物。\p我会让火箭队成为历史。\p我还要把那个阿渡，\n踩在我的脚下。$"
    .string ""
    .string ""
    .string ""

GoldenrodUnderground_Text_GruntM11Seen:
    .string "打开一扇卷帘门，\n另一扇就会关上。\p你肯定到不了想去的地方！$"
    .string ""

GoldenrodUnderground_Text_GruntM11Beaten:
    .string "可恶！我居然因为犹豫栽了！$"

GoldenrodUnderground_Text_GruntM11After:
    .string "我也搞糊涂了……\p得先按最里面的开关，\n然后再往回按。$"
    .string ""
    .string ""

GoldenrodUnderground_Text_GruntM25Seen:
    .string "哇哈哈！\p被卷帘门搞得晕头转向了吧？\p你要是能打赢我，\n我就告诉你一个秘密！$"
    .string ""
    .string ""
    .string ""

GoldenrodUnderground_Text_GruntM25Beaten:
    .string "呜……我搞砸了。$"

GoldenrodUnderground_Text_GruntM25After:
    .string "好吧，给你个提示！\p按错开关，整套系统就会\n重新启动。\p开始之前，先确认三个开关\n全都在关闭状态。$"
    .string ""
    .string ""
    .string ""
    .string ""

GoldenrodUnderground_Text_BurglarDuncanSeen:
    .string "把好东西都交出来！$"

GoldenrodUnderground_Text_BurglarDuncanBeaten:
    .string "饶了我吧！$"

GoldenrodUnderground_Text_BurglarDuncanAfter:
    .string "偷来东西再卖掉！\n这是犯罪的基本，小鬼！$"
    .string ""

GoldenrodUnderground_Text_BurglarEddieSeen:
    .string "这工程没完工，\n他们就不要了。\p我在找有没有剩下值钱的东西。$"
    .string ""
    .string ""

GoldenrodUnderground_Text_BurglarEddieBeaten:
    .string "真是太厉害了！$"

GoldenrodUnderground_Text_BurglarEddieAfter:
    .string "地下仓库？\p你去那儿干什么？\p下面什么都没有。$"
    .string ""
    .string ""

GoldenrodUnderground_Text_GruntM13Seen:
    .string "我管你是不是迷路了。\p落到这儿来，你就只能\n当个活靶子！$"
    .string ""
    .string ""

GoldenrodUnderground_Text_GruntM13Beaten:
    .string "呃！哼，你以为自己很帅吗？$"

GoldenrodUnderground_Text_GruntM13After:
    .string "敢看不起火箭队，\n你还真是胆大包天。$"
    .string ""

GoldenrodUnderground_Text_GruntF3Seen:
    .string "迷路了？不对，不可能。\p你脸上可没有害怕的样子。\p那我就让你知道\n什么叫害怕！$"
    .string ""
    .string ""
    .string ""

GoldenrodUnderground_Text_GruntF3Beaten:
    .string "你怎么能这样？$"

GoldenrodUnderground_Text_GruntF3After:
    .string "爱去哪去哪！滚吧！\n我才不管呢！$"
    .string ""

GoldenrodUnderground_Text_SequenceStep1:
    .string "3号开关已启动。\p第一道卷帘门锁\n已经解开。$"
    .string ""
    .string ""

GoldenrodUnderground_Text_SequenceStep2:
    .string "2号开关已启动。\p第二道卷帘门锁\n已经解开。$"
    .string ""
    .string ""

GoldenrodUnderground_Text_SequenceComplete:
    .string "1号开关已启动。\p所有卷帘门锁均已解开！$"
    .string ""

GoldenrodUnderground_Text_SequenceReset:
    .string "按错开关了！\p顺序和卷帘门都已复位。$"
    .string ""

GoldenrodUnderground_Text_AlreadySolved:
    .string "卷帘门已经解开了。$"

GoldenrodUnderground_Text_EmergencyRelease:
    .string "紧急解锁装置\n启动了！\p所有卷帘门都已打开。$"
    .string ""
    .string ""

GoldenrodUnderground_Text_EmergencyReleaseLocked:
    .string "紧急解锁装置已被锁住。$"

GoldenrodUnderground_Text_AllShuttersAlreadyOpen:
    .string "所有卷帘门都已经打开了。$"
