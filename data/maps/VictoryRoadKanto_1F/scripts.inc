.set LOCALID_VICTORYROAD_SILVER, 13

VictoryRoadKanto_1F_MapScripts::
	.byte 0

VictoryRoadKanto_1F_Trigger::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	delay 5
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	addobject LOCALID_VICTORYROAD_SILVER
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 27, VictoryRoadKanto_1F_EventScript_SilverEnterLeft
	call_if_eq VAR_TEMP_0, 28, VictoryRoadKanto_1F_EventScript_SilverEnterMid
	call_if_eq VAR_TEMP_0, 29, VictoryRoadKanto_1F_EventScript_SilverEnterRight
	createfieldmugshot MUGSHOT_SILVER
	msgbox VictoryRoad_Text_RivalBefore, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, VictoryRoadKanto_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, VictoryRoadKanto_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, VictoryRoadKanto_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	createfieldmugshot MUGSHOT_SILVER
	msgbox VictoryRoad_Text_RivalAfter, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_CLIMB
	closemessage
	applymovement LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverLeave
	waitmovement 0
	removeobject LOCALID_VICTORYROAD_SILVER
	fadedefaultbgm
	release
	setvar VAR_ROUTE27_STATE, 2
	end

VictoryRoadKanto_1F_EventScript_SilverEnterLeft::
	applymovement LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return

VictoryRoadKanto_1F_EventScript_SilverEnterMid::
	applymovement LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterMid
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return

VictoryRoadKanto_1F_EventScript_SilverEnterRight::
	applymovement LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return


VictoryRoadKanto_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_5, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_5, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_5, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Movement_SilverEnterLeft:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverEnterMid:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverEnterRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverLeave:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VictoryRoad_Text_RivalBefore:
    .string "站住。\p……你打算去\n挑战宝可梦联盟？\p……别逗我笑了。\p你比我弱太多了。\p我早已不是以前的我了。\p现在的我，拥有\n最棒的、最强的宝可梦！\p我是无敌的！\p{PLAYER}！\n我要向你挑战！$"
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

VictoryRoad_Text_RivalDefeat:
    .string "……我赢不了……\p我已经使出了\n浑身解数……\p你拥有，而我没有的东西……\p我好像开始明白\n那个驯龙师说的话了……$"
    .string ""
    .string ""
    .string ""
    .string ""

VictoryRoad_Text_RivalAfter:
    .string "……我还没放弃成为\n最强的训练家……\p我会找出自己\n赢不了的原因，变得更强……\p到那时，我会再来\n向你挑战。\p并且，我会用全部的\n力量打倒你。\p……哼！到那时你也别松懈。\p这个你拿去吧。我现在\n有别的要优先处理。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
	.string ""
	.string ""
