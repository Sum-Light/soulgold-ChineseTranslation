
Gate_Route31_VioletCity_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Gate_Route31_VioletCity_OnTransition
	.byte 0

Gate_Route31_VioletCity_OnTransition::
    call Common_EventScript_SetupRivalGfxId
    end

Gate_Route31_VioletCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_Text_Policeman:
	.string "你好！你去过\n喇叭芽之塔了吗？$"
	.string ""

Gate_Route31_VioletCity_Text_CooltrainerF:
	.string "我在外面看到一只\n超可爱的宝可梦。\p它长得特别像皮卡丘！$"
	.string ""
	.string ""

Gate_Route31_VioletCity_RivalExpShare::
	lock
	playse SE_EXIT
	playbgm MUS_HG_LYRA, TRUE
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_0
	closemessage
	moveobjecttocoords LOCALID_PLAYER, 6, 5, DIR_EAST
	clearflag FLAG_HIDE_RIVAL_VIOLETGATEHOUSE
	addobject LOCALID_GATEHOUSE_RIVAL
	applymovement LOCALID_GATEHOUSE_RIVAL, Gate_Route31_VioletCity_RivalExpShare_Movement_0
	waitmovement 0
	createfieldmugshotrival
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_1
	giveitem ITEM_EXP_SHARE
	setflag FLAG_RECEIVED_EXP_SHARE
	setflag FLAG_EXP_SHARE_OPTION
	createfieldmugshotrival
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_2
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_3
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_4
	closemessage
	setflag FLAG_HIDE_RIVAL_VIOLETGATEHOUSE
	setvar VAR_RIVAL_STATE, 4
	applymovement LOCALID_GATEHOUSE_RIVAL, Gate_Route31_VioletCity_RivalExpShare_Movement_1
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GATEHOUSE_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end


Gate_Route31_VioletCity_RivalExpShare_Movement_0:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Gate_Route31_VioletCity_RivalExpShare_Movement_1:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Gate_Route31_VioletCity_RivalExpShare_Text_0:
	.string "{PLAYER}！等一下！$"

Gate_Route31_VioletCity_RivalExpShare_Text_1:
	.string "空木博士忘了\n把这个交给你。$"

Gate_Route31_VioletCity_RivalExpShare_Text_2:
	.string "能让多只宝可梦同时\n接受训练，相当方便！$"

Gate_Route31_VioletCity_RivalExpShare_Text_3:
	.string "要是还没用过，就用那些\n精灵球多捉些新宝可梦吧。$"

Gate_Route31_VioletCity_RivalExpShare_Text_4:
	.string "我得回家去了。\n希望很快再见到你，{PLAYER}！$"
