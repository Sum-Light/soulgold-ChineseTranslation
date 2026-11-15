
.set LOCALID_ICEPATH1_KIMONO, 9
IcePath_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IcePath_1F_OnTransition: 
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_HIDE_ICEPATH_RIVAL
	goto_if_ne VAR_RIVAL_STATE, 9, IcePath_1F_OnTransition_SetTime
	clearflag FLAG_HIDE_ICEPATH_RIVAL

IcePath_1F_OnTransition_SetTime:
	callnative SetTimeBasedEncounters
	end

IcePath_1F_EventScript_KimonoGirl::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	goto_if_eq VAR_FACING, DIR_SOUTH, IcePath_1F_EventScript_KimonoGirlPushPrompt
	msgbox IcePath_1F_Text_Stuck1, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

IcePath_1F_Trigger_KimonoGirl::
	lock
	msgbox IcePath_1F_Text_Leave, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

IcePath_1F_EventScript_KimonoGirlPushPrompt::
	msgbox IcePath_1F_Text_Stuck2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused
IcePath_1F_EventScript_KimonoGirlPush::
	msgbox IcePath_1F_Text_Shove, MSGBOX_AUTOCLOSE
	closemessage
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_Movement_PlayerJump
	waitmovement 0
	waitse
	playse SE_M_ICY_WIND
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoSlide
	waitmovement 0
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox IcePath_1F_Text_Thanks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoLeave
	waitmovement LOCALID_ICEPATH1_KIMONO
	setflag FLAG_HIDE_ICE_PATH_KIMONO
	removeobject LOCALID_ICEPATH1_KIMONO
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_ICE_PATH_STATE, 2
	release
	end

IcePath_1F_EventScript_KimonoGirlRefused::
	msgbox IcePath_1F_Text_Cruel, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, IcePath_1F_EventScript_KimonoGirlPush
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused

IcePath_Movement_PlayerJump:
	jump_in_place_down
	step_end

IcePath_Movement_KimonoSlide:
	slide_down
	slide_down
	slide_down
	slide_down
	walk_in_place_fast_down
	face_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

IcePath_Movement_KimonoLeave:
	walk_down
	walk_down
	walk_down
	step_end

IcePath_1F_Text_Leave:
	.string "和服女孩：………………$"

IcePath_1F_Text_Stuck1:
    .string "哎呀呀……这不是{PLAYER}吗？\n真没想到会在这里遇见你！\p说实话……我的草鞋\n冻在冰上了，我动不了了。\p也就是说，我的人字拖\n被速冻在地面上了。\p嘻嘻。\p不过，这可不是好笑的事。\p能请你绕到我身后，\n推一下我的后背吗？$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

IcePath_1F_Text_Stuck2:
    .string "哎呀呀……这不是{PLAYER}吗？\n真没想到会在这里遇见你！\p说实话……我的草鞋\n冻在冰上了，我动不了了。\p也就是说，我的人字拖\n和地面速冻在一起了。\p嘻嘻。\p不过，这可不是好笑的事。\n能请你推一下我的后背吗？$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

IcePath_1F_Text_Shove:
    .string "……用力一推！……$"

IcePath_1F_Text_Cruel:
    .string "请别这么狠心嘛。\n你会帮我推一下后背的，对吧？$"
    .string ""

IcePath_1F_Text_Thanks:
    .string "你真是个好心人。\n太感谢你了！$"
    .string ""

IcePath_1F_Rival::
	compare VAR_RIVAL_STATE, 9
	goto_if_eq IcePath_1F_Rival_2
IcePath_1F_Rival_1:
	end

IcePath_1F_Rival_2:
	lock
	playse SE_PIN
	applymovement LOCALID_ICEPATH_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ICEPATH_RIVAL, IcePath_1F_Rival_Movement_0
	waitmovement 0
	waitse
	approachobject LOCALID_PLAYER, LOCALID_ICEPATH_RIVAL, DIR_EAST, DIR_WEST
	waitmovement 0
	delay 30
	createfieldmugshotrival
	msgbox IcePath_1F_Rival_Text_0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq IcePath_1F_Rival_5
	trainerbattle_no_intro TRAINER_RIVAL_GOLD_ICEPATH, IcePath_1F_Rival_Text_1
IcePath_1F_Rival_4:
	createfieldmugshotrival
	msgbox IcePath_1F_Rival_Text_2
	closemessage
	applymovement LOCALID_ICEPATH_RIVAL, IcePath_1F_Rival_Movement_1
	waitmovement 0
	delay 30
	createfieldmugshotrival
	msgbox IcePath_1F_Rival_Text_3
	removefieldmugshot
	closemessage
	applymovement LOCALID_ICEPATH_RIVAL, IcePath_1F_Rival_Movement_2
	waitmovement 0
	setvar VAR_RIVAL_STATE, 10
	setflag FLAG_HIDE_ICEPATH_RIVAL
	clearflag FLAG_HIDE_VICTORYROAD_RIVAL
	removeobject LOCALID_ICEPATH_RIVAL
	release
	goto IcePath_1F_Rival_1

IcePath_1F_Rival_5:
	trainerbattle_no_intro TRAINER_RIVAL_CRYSTAL_ICEPATH, IcePath_1F_Rival_Text_1
	goto IcePath_1F_Rival_4


IcePath_1F_Rival_Movement_0:
	face_left
	step_end

IcePath_1F_Rival_Movement_1:
	walk_in_place_left
	step_end

IcePath_1F_Rival_Movement_2:
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

IcePath_1F_Rival_Text_0:
	.string "你也走到这里了啊……\n还带着那么多徽章……\p我倒不意外，\n大概你天生就有这份才能吧。\p可是！\n我现在也在拼命地训练！\p这一点你是绝对弥补不了的。\n就在此时此地，\l让我证明给你看吧，{PLAYER}！$"

IcePath_1F_Rival_Text_1:
	.string "怎么会……？$"

IcePath_1F_Rival_Text_2:
	.string "从这里到湛蓝市，\n每一条道路我都训练过了，\l一刻也没休息。\p而你却毫不费力就做到了，\n好像这一切对你来说\l只是个有趣的小游戏。$"

IcePath_1F_Rival_Text_3:
	.string "我只是……\n对自己的进步太不甘心了。\p不管我怎么训练……\p我必须继续努力下去。$"
