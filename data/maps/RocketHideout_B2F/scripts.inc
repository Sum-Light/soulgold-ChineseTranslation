.set LOCALID_ROCKETHIDEOUT2_LANCE, 7
.set LOCALID_ROCKETHIDEOUT2_DRAGONITE, 8
.set LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, 15
.set LOCALID_ROCKETHIDEOUT2_MURKROWGATE, 16
.set LOCALID_ROCKETHIDEOUT2_ARIANA, 14
.set LOCALID_ROCKETHIDEOUT2_GRUNT, 12
.set LOCALID_LANCEELECTRODE1, 3
.set LOCALID_LANCEELECTRODE2, 2
.set LOCALID_LANCEELECTRODE3, 1


RocketHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B2F_OnLoad
	.byte 0

RocketHideout_B2F_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT2_GATE, RocketHideout_B2F_HideGate
	call_if_eq VAR_MAHOGANY_TOWN_STATE, 13, RocketHideout_B2F_MoveLanceDragonite
	call_if_ge VAR_ELECTRODES_FAINTED, 4, RockerHideout2_DeactivateGenerator
	end

RockerHideout2_DeactivateGenerator::
	setmetatile 13, 8, 0x483, TRUE
	setmetatile 13, 9, 0x483, TRUE
	setmetatile 13, 10, 0x483, TRUE
	setmetatile 13, 11, 0x483, TRUE
	setmetatile 13, 12, 0x483, TRUE
	setmetatile 13, 13, 0x483, TRUE
	setmetatile 13, 14, 0x483, TRUE
	setmetatile 13, 15, 0x483, TRUE

	setmetatile 14, 8, 0x483, TRUE
	setmetatile 14, 9, 0x483, TRUE
	setmetatile 14, 10, 0x483, TRUE
	setmetatile 14, 11, 0x483, TRUE
	setmetatile 14, 12, 0x483, TRUE
	setmetatile 14, 13, 0x483, TRUE
	setmetatile 14, 14, 0x483, TRUE
	setmetatile 14, 15, 0x483, TRUE

	setmetatile 15, 8, 0x483, TRUE
	setmetatile 15, 9, 0x483, TRUE
	setmetatile 15, 10, 0x483, TRUE
	setmetatile 15, 11, 0x483, TRUE
	setmetatile 15, 12, 0x483, TRUE
	setmetatile 15, 13, 0x483, TRUE
	setmetatile 15, 14, 0x483, TRUE
	setmetatile 15, 15, 0x483, TRUE

	setmetatile 16, 8, 0x483, TRUE
	setmetatile 16, 9, 0x483, TRUE
	setmetatile 16, 10, 0x483, TRUE
	setmetatile 16, 11, 0x483, TRUE
	setmetatile 16, 12, 0x483, TRUE
	setmetatile 16, 13, 0x483, TRUE
	setmetatile 16, 14, 0x483, TRUE
	setmetatile 16, 15, 0x483, TRUE

	setmetatile 17, 8, 0x483, TRUE
	setmetatile 17, 9, 0x483, TRUE
	setmetatile 17, 10, 0x483, TRUE
	setmetatile 17, 11, 0x483, TRUE
	setmetatile 17, 12, 0x483, TRUE
	setmetatile 17, 13, 0x483, TRUE
	setmetatile 17, 14, 0x483, TRUE
	setmetatile 17, 15, 0x483, TRUE

	setmetatile 18, 8, 0x483, TRUE
	setmetatile 18, 9, 0x483, TRUE
	setmetatile 18, 10, 0x483, TRUE
	setmetatile 18, 11, 0x483, TRUE
	setmetatile 18, 12, 0x483, TRUE
	setmetatile 18, 13, 0x483, TRUE
	setmetatile 18, 14, 0x483, TRUE
	setmetatile 18, 15, 0x483, TRUE
	return

RocketHideout_B2F_HideGate::
	setmetatile 14, 19, 0x402, FALSE
	setmetatile 14, 20, 0x402, FALSE
	setmetatile 15, 19, 0x401, FALSE
	setmetatile 15, 20, 0x401, FALSE
	setmetatile 16, 19, 0x401, FALSE
	setmetatile 16, 20, 0x401, FALSE
	return

RocketHideout_B2F_MoveLanceDragonite::
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 20, 16
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 19, 16
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_DRAGONITE, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_LANCE, MOVEMENT_TYPE_FACE_UP
	return

RocketHideout_B2F_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout_B2F_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout_B2F_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setvar VAR_MAHOGANY_TOWN_STATE, 10
	release
	end

RocketHideout_B2F_Movement_MurkrowStairs1:
	jump_in_place_left
	jump_in_place_left
	step_end

RocketHideout_B2F_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B2F_Trigger_MurkrowGate::
	lock
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWGATE, RocketHideout_B2F_Movement_MurkrowGate1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_Murkrow, MSGBOX_DEFAULT
	msgbox RocketHideout_B2F_Text_MurkrowUnlock, MSGBOX_DEFAULT
	playse SE_CLICK
	setmetatile 14, 19, 0x402, FALSE
	setmetatile 14, 20, 0x402, FALSE
	setmetatile 15, 19, 0x401, FALSE
	setmetatile 15, 20, 0x401, FALSE
	setmetatile 16, 19, 0x401, FALSE
	setmetatile 16, 20, 0x401, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT2_GATE
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWGATE, RocketHideout_B2F_Movement_MurkrowGate2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	removeobject LOCALID_ROCKETHIDEOUT2_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 12
	release
	end
RocketHideout_B2F_Movement_MurkrowGate1:
	jump_in_place_up
	jump_in_place_up
	step_end

RocketHideout_B2F_Movement_MurkrowGate2:
	jump_in_place_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RocketHideout_B2F_Text_MurkrowUnlock:
    .string "黑暗鸦模仿着拉姆达的声音，\n喊出了密码。\p……………………\n声音识别系统\l把门锁打开了！$"
    .string ""
    .string ""
    .string ""
    .string ""

@============================================================================================================================================

RocketHideout_B2F_Trigger_PlayerMoveLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return
RocketHideout_B2F_Trigger_PlayerMoveRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

RocketHideout_B2F_Trigger_Ariana::
	lock 
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 6, 26
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 5, 26
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	addobject LOCALID_ROCKETHIDEOUT2_ARIANA
	addobject LOCALID_ROCKETHIDEOUT2_GRUNT
	delay 20
	createfieldmugshot MUGSHOT_ARIANA
	msgbox RocketHideout_B2F_Text_ArianaHoldIt, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 14, RocketHideout_B2F_Trigger_PlayerMoveLeft
	call_if_eq VAR_TEMP_0, 16, 	RocketHideout_B2F_Trigger_PlayerMoveRight
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_PlayerMeetAriana
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, RocketHideout_B2F_Movement_Ariana
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT2_GRUNT, RocketHideout_B2F_Movement_Ariana
	waitmovement LOCALID_ROCKETHIDEOUT2_GRUNT
	createfieldmugshot MUGSHOT_ARIANA
	msgbox RocketHideout_B2F_Text_ArianaChallenge, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	addobject LOCALID_ROCKETHIDEOUT2_LANCE
	addobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_Lance
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_Lance
	waitmovement 0
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B2F_Text_LanceInterrupt, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, Common_Movement_WalkInPlaceFasterUp
	createfieldmugshot MUGSHOT_ARIANA
	msgbox RocketHideout_B2F_Text_ArianaOutraged
	closemessage
	special HealPlayerParty
	goto RocketHideout_B2F_EventScript_ReadyForBattlePrompt
	end
	
RocketHideout_B2F_Movement_PlayerMeetAriana:
	walk_down
	walk_down
	walk_down
	step_end

RocketHideout_B2F_Movement_Ariana:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout_B2F_Movement_Lance:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B2F_Text_ArianaHoldIt:
    .string "雅典娜：站住！$"

RocketHideout_B2F_Text_ArianaChallenge:
    .string "雅典娜：你这种小鬼，\n我们可不能一直放任下去。\p一而再、再而三地伤害\n火箭队的自尊……\l自尊可是会一点点消磨掉的。\p……所以，该跟你做个了断了。\n不管你有多强，\p只要我们两个同时出手，\n你就没有胜算。\l你说是吧？\p呵呵呵！抱歉啦，小朋友。\n准备挨揍吧。$"
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

RocketHideout_B2F_Text_LanceInterrupt:
    .string "阿渡：住手！\n两个人打一个吗？\p这也太不公平了！\n不愧是火箭队，\l净干这种卑鄙的勾当。\p让我也加入战斗吧！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B2F_Text_ArianaOutraged:
    .string "雅典娜：什么？你还有帮手？\n你的尊严都去哪儿了？\p身为代替坂木的代理老大，\n我要让你明白，插手火箭队的事\l是多么错误的决定！$"
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B2F_Text_LanceChooseMons:
    .string "阿渡：快，{PLAYER}，\n选出你的宝可梦！$"
	.string ""

RocketHideout_B2F_EventScript_ReadyForBattlePrompt::
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B2F_Text_LanceChooseMons, MSGBOX_DEFAULT
	removefieldmugshot
	goto RocketHideout_B2F_EventScript_ChoosePartyForMultiBattle
	end

RocketHideout_B2F_EventScript_ChoosePartyForMultiBattle::
	setflag FLAG_ROCKETHIDEOUT2_BATTLE
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, RocketHideout_B2F_EventScript_DoLanceMultiBattle
	special LoadPlayerParty
	goto RocketHideout_B2F_EventScript_ReadyForBattlePrompt

RocketHideout_B2F_EventScript_DoLanceMultiBattle::
	multi_2_vs_2 TRAINER_ARIANA_1, RocketHideout_B2F_Text_ArianaLoss, TRAINER_GRUNT_23, RocketHideout_B2F_Text_GruntLoss, PARTNER_STEVEN
	switch VAR_RESULT
	case 1, RocketHideout_B2F_EventScript_DefeatedAriana
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	special SetCB2WhiteOut
	waitstate

RocketHideout_B2F_EventScript_DoLanceMultiBattle2::
	special ReducePlayerPartyToSelectedMons
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, SPECIAL_BATTLE_LANCE
	setvar VAR_0x8005, 0
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, Common_Movement_WalkUp1
	applymovement LOCALID_ROCKETHIDEOUT2_GRUNT, Common_Movement_WalkUp1
	waitmovement 0
	turnobject LOCALID_ROCKETHIDEOUT2_GRUNT, DIR_WEST
	special DoSpecialTrainerBattle
	waitstate
	frontier_saveparty
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, RocketHideout_B2F_EventScript_DefeatedAriana
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	special SetCB2WhiteOut
	waitstate

RocketHideout_B2F_EventScript_ArianaTrainer::
	trainerbattle_single TRAINER_ARIANA_1, RocketHideout_B2F_Text_ArianaLoss, RocketHideout_B2F_Text_ArianaLoss
	end

RocketHideout_B2F_EventScript_GruntTrainer::
	trainerbattle_single TRAINER_GRUNT_23, RocketHideout_B2F_Text_GruntLoss, RocketHideout_B2F_Text_GruntLoss
	end

RocketHideout_B2F_EventScript_DefeatedAriana::
	clearflag FLAG_ROCKETHIDEOUT2_BATTLE
	createfieldmugshot MUGSHOT_ARIANA
	msgbox RocketHideout_Text_ArianaRetreat, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, Common_Movement_WalkUp1
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, Common_Movement_WalkRight1
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, Common_Movement_WalkRight1
	waitmovement 0
	setflag FLAG_HIDE_MAHOGANY_ROCKETS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	removeobject LOCALID_ROCKETHIDEOUT2_ARIANA
	removeobject LOCALID_ROCKETHIDEOUT2_GRUNT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	fadescreenswapbuffers FADE_FROM_BLACK
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_Text_LanceStepBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceWalkToGenerator
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteWalkToGenerator
	delay 55
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_LanceWalkToGenerator
	waitmovement 0

	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteInvestigateGenerator
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceInvestigateGenerator
	delay 165
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B2F_Text_LanceElectrodeFaint, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceWalkToElectrode
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_LanceWalkToElectrode
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_PlayerWalkToElectrode
	waitmovement 0
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 20, 16
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 19, 16
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_DRAGONITE, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_LANCE, MOVEMENT_TYPE_FACE_UP
	setvar VAR_MAHOGANY_TOWN_STATE, 13
	release
	end

RocketHideout_B2F_Movement_LanceWalkToGenerator:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
RocketHideout_B2F_Movement_DragoniteWalkToGenerator:
	delay_8
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	step_end


RocketHideout_B2F_Movement_LanceInvestigateGenerator:
	walk_up
	walk_left
	face_up
	delay_8
	delay_8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	delay_8
	delay_8
	face_right
	delay_8
	delay_8
	delay_8
	delay_8
	walk_left
	walk_left
	walk_left
	face_down
	step_end

RocketHideout_B2F_Movement_DragoniteInvestigateGenerator:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	delay_16
	delay_16
	delay_8
	delay_8	
	delay_8
	delay_8
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Movement_LanceWalkToElectrode:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RocketHideout_B2F_Movement_PlayerWalkToElectrode:
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Trigger_Electrode::
	lock
	goto_if_eq VAR_ELECTRODES_FAINTED, 3, RocketHideout_B2F_EventScript_ElectrodeDone
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_WEST
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B2F_Text_LanceSide, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	release
	end

RocketHideout_B2F_EventScript_Electrode::
	lock
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ELECTRODE, 40
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RocketHideout_B2F_EventScript_Ran_Electrode
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RocketHideout_B2F_EventScript_Ran_Electrode
	removeobject VAR_LAST_TALKED
	addvar VAR_ELECTRODES_FAINTED, 1
	release
	end

RocketHideout_B2F_EventScript_Ran_Electrode::
	release
	end

RocketHideout_B2F_EventScript_ElectrodeDone::
	playse SE_M_HYPER_BEAM
	removeobject LOCALID_LANCEELECTRODE1
	removeobject LOCALID_LANCEELECTRODE2
	removeobject LOCALID_LANCEELECTRODE3
	waitse
	getplayerxy VAR_TEMP_0, VAR_TEMP_1 
	call_if_eq VAR_TEMP_1, 16, RocketHideout_B2F_Movement_PlayerMeetLanceTop
	call_if_eq VAR_TEMP_1, 18, RocketHideout_B2F_Movement_PlayerMeetLanceBot
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE

	playse SE_CLICK
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_NORTH
	call RockerHideout2_DeactivateGenerator
	special DrawWholeMapView
	delay 55
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B2F_Text_LanceElectrodeDone, MSGBOX_DEFAULT
	removefieldmugshot
	giveitem ITEM_HM_WHIRLPOOL
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B2F_Text_LanceWhirlpool, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_SOUTH
	delay 20
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B2F_Text_LanceMonMaster, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceFinalExit
	delay 20

	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteFinalExit
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE

	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_LANCE
	setvar VAR_ELECTRODES_FAINTED, 4
	setvar VAR_MAHOGANY_TOWN_STATE, 14
	clearflag FLAG_HIDE_MAHOGANY_COP
	setflag FLAG_HIDE_MAHOGANY_TOWN_FATMAN
	setvar VAR_ROCKET_HIDEOUT_STATUE_1, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_2, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_3, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_4, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_5, 2
	release
	end

RocketHideout_B2F_Movement_PlayerMeetLanceTop:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	return

RocketHideout_B2F_Movement_PlayerMeetLanceBot:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	return

RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Movement_LanceFinalExit:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B2F_Movement_DragoniteFinalExit:
	walk_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B2F_Text_GruntLoss:
    .string "....................$"

RocketHideout_B2F_Text_ArianaLoss:
    .string "啧，你还真是强。\n太可惜了。\p要是你愿意加入火箭队，\n说不定能当上干部。$"
    .string ""
    .string ""
    .string ""

RocketHideout_Text_ArianaRetreat:
    .string "雅典娜：不过，也罢。\n电波实验取得了\l圆满成功。\p这个基地接下来会怎样，\n都已经无所谓了。\p我们的计划要宏大得多。\n你很快就会见识到火箭队\l真正的实力。\p趁现在好好享受吧……\n呵呵呵……$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_Text_LanceStepBack:
    .string "抱歉，{PLAYER}。你打得那么\n精彩，我就先按兵不动了。\p接下来只剩下关掉那个\n奇怪的无线电信号了。$"
    .string ""
    .string ""
    .string ""


RocketHideout_B2F_Text_LanceElectrodeFaint:
    .string "造成这一切的，\n就是这台机器。\p我在上面没看到开关……\p没办法了。只能把所有\n顽皮雷弹都弄晕。\p这样这台机器应该就\n不会再发出那种\l奇怪的信号了。\p这不能怪那些宝可梦，\n所以我才觉得过意不去。\p{PLAYER}，我们分头行动吧。$"
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

RocketHideout_B2F_Text_LanceSide:
    .string "阿渡：这边交给我。$"

RocketHideout_B2F_Text_LanceElectrodeDone:
    .string "阿渡：那个奇怪的信号\n终于停了。\p愤怒之湖应该\n恢复原样了。\p你是英雄！让我代表\n所有的宝可梦\l向你道谢。\p对了。这个你拿去吧。\n这是我在这里找到的，\l不过我用不上。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B2F_Text_LanceWhirlpool:
    .string "那是潮旋。让宝可梦学会它，\n就能渡过湍急的水流。\p不过这一点要记住。\p只有在拿到卡吉道馆的徽章后，\n才能在对战外\l使用这招。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B2F_Text_LanceMonMaster:
    .string "{PLAYER}……\p要成为宝可梦大师，\n前方的道路\l漫长而艰险。\p明知如此，你还是要\n走下去吗？\p……\p我明白了。不，你说得对。\p要是这么容易就放弃，\n你从一开始\l就不会去追逐那个梦想了。\p期待与你再次相见！$"
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

RocketHideout_B2F_Text_B2FTransmitter:
    .string "发出邪恶信号的就是这台\n无线电发射装置。\p它正在满负荷运转。$"
    .string ""
    .string ""

RocketHideout_B2F_Text_B2FDeactivateTransmitter:
    .string "无线电发射装置终于\n停止了邪恶的广播。$"
    .string ""


@===========================================================================================================================================

RocketHideout_B2F_EventScript_LanceTriggerLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout_B2F_EventScript_Lance

RocketHideout_B2F_EventScript_LanceTriggerRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout_B2F_EventScript_Lance

RocketHideout_B2F_EventScript_Lance::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B2F_Text_LanceHeals1, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B2F_Text_LanceHeals2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceGoDeeper
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteGoDeeper
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 6
	removeobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	release
	end

RocketHideout_B2F_Movement_LanceGoDeeper:
	walk_right
	walk_right
	delay_2
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B2F_Movement_DragoniteGoDeeper:
	delay_8
	delay_8
	delay_8
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B2F_Text_LanceHeals1:
    .string "阿渡：你没事吧？\p你的宝可梦都受伤了，也累了。\p来，把我带的药\n分给它们吧。$"
    .string ""
    .string ""
    .string ""

RocketHideout_B2F_Text_LanceHeals2:
    .string "阿渡：{PLAYER}，为了宝可梦，\n我们一起加油吧。$"
    .string ""

RocketHideout_B2F_Text_GruntM17Seen:
    .string "门打不开吗？\p那是当然的。\n它得用只有火箭队\l才知道的密码才行。$"
    .string ""
    .string ""
    .string ""

RocketHideout_B2F_Text_GruntM17Beaten:
    .string "什么？我输了？$"

RocketHideout_B2F_Text_GruntM17After:
    .string "嘿，我不过是个手下。\p我才不知道什么密码。\n算你倒霉。$"
    .string ""
    .string ""

RocketHideout_B2F_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_14 RocketHideout_B2F_Text_GruntM17Seen, RocketHideout_B2F_Text_GruntM17Beaten
	msgbox RocketHideout_B2F_Text_GruntM17After, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntM18Seen:
    .string "哦，是个小鬼？虽然不太情愿，\n但我必须把你解决掉。$"
    .string ""

RocketHideout_B2F_Text_GruntM18Beaten:
    .string "我就知道会输……$"

RocketHideout_B2F_Text_GruntM18After:
    .string "上一次任务中，我也是\n栽在一个小鬼手里。\p我们正在掳走宝可梦的时候，\n来了一个红色长头发、\l眼神凶巴巴的小鬼，\l把我狠狠收拾了一顿……$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B2F_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_15 RocketHideout_B2F_Text_GruntM18Seen, RocketHideout_B2F_Text_GruntM18Beaten
	msgbox RocketHideout_B2F_Text_GruntM18After, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntM19Seen:
    .string "你这个可恶的小鬼！$"

RocketHideout_B2F_Text_GruntM19Beaten:
    .string "呜啊啊……$"

RocketHideout_B2F_Text_GruntM19After:
    .string "嘿，那道门的密码\n只有老大知道。\p老大在哪儿？谁知道呢？\n你自己去找吧。$"
    .string ""
    .string ""
    .string ""

RocketHideout_B2F_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_16 RocketHideout_B2F_Text_GruntM19Seen, RocketHideout_B2F_Text_GruntM19Beaten
	msgbox RocketHideout_B2F_Text_GruntM19After, MSGBOX_AUTOCLOSE
	end

