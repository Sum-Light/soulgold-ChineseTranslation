.set LOCALID_ROCKETHIDEOUT3_LANCE, 3
.set LOCALID_ROCKETHIDEOUT3_DRAGONITE, 2
.set LOCALID_ROCKETHIDEOUT3_SILVER, 5
.set LOCALID_ROCKETHIDEOUT3_GIOVANNI, 16
.set LOCALID_ROCKETHIDEOUT3_PETREL, 15
.set LOCALID_ROCKETHIDEOUT3_MURKROW, 14
.set LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, 17

RocketHideout_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RocketHideout_B3F_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B3F_OnLoad
	.byte 0

RocketHideout_B3F_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_HideGate
	call_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_HidePetrel
	end
	
RocketHideout_B3F_HideGate::
	setmetatile 11, 11, 0x402, FALSE
	setmetatile 11, 12, 0x402, FALSE
	setmetatile 12, 11, 0x401, FALSE
	setmetatile 12, 12, 0x401, FALSE
	setmetatile 13, 11, 0x401, FALSE
	setmetatile 13, 12, 0x401, FALSE
	return
RocketHideout_B3F_HidePetrel::
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	return

RocketHideout_B3F_OnFrame::
	map_script_2 VAR_MAHOGANY_TOWN_STATE, 6, RocketHideout_B3F_EventScript_LancePassword
	.2byte 0

RocketHideout_B3F_EventScript_LancePassword::
	lock
	delay 55
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_ExclamationMark
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_WalkRight1
	createfieldmugshot MUGSHOT_LANCE
	msgbox RocketHideout_B3F_Text_LanceGetPassword, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, RocketHideout_B3F_Movement_LanceLeave
	applymovement LOCALID_ROCKETHIDEOUT3_DRAGONITE, RocketHideout_B3F_Movement_DragoniteLeave
	waitmovement LOCALID_ROCKETHIDEOUT3_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT3_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 7
	release
	end

RocketHideout_B3F_Movement_LanceLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	delay_2
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B3F_Movement_DragoniteLeave:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	delay_8
	delay_8
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

RocketHideout_B3F_Text_LanceGetPassword:
    .string "阿渡：要进老大的房间，\n需要两个密码。\p知道密码的只有\n极少数火箭队成员。\p那边那个火箭队的人\n很爽快就告诉我了。\p{PLAYER}，我们去\n把密码找出来吧。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B3F_EventScript_RocketKO::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_B3FRocket, MSGBOX_DEFAULT
	release
	end

RocketHideout_B3F_Text_B3FRocket:
    .string "唔呃……那个穿斗篷的家伙\n强得离谱……$"
    .string ""


RocketHideout_B3F_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 11
	release
	end

RocketHideout_B3F_Movement_MurkrowStairs1:
	jump_in_place_right
	jump_in_place_right
	step_end

RocketHideout_B3F_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B3F_Trigger_Silver::
	lock
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	addobject LOCALID_ROCKETHIDEOUT3_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RocketHideout_B3F_Text_Rival, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverLeave
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	removeobject LOCALID_ROCKETHIDEOUT3_SILVER
	setvar VAR_MAHOGANY_TOWN_STATE, 8
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

RocketHideout_B3F_Movement_SilverEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B3F_Movement_SilverLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout_B3F_EventScript_Door::
	lock
	goto_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_EventScript_DoorIsOpen
	goto_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_EventScript_OpenDoor
	msgbox RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword, MSGBOX_DEFAULT
	closemessage
	release
	end

RocketHideout_B3F_EventScript_OpenDoor::
	msgbox RocketHideout_B3F_Text_B3FLockedDoorOpenSesame, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 11, 11, 0x402, FALSE
	setmetatile 11, 12, 0x402, FALSE
	setmetatile 12, 11, 0x401, FALSE
	setmetatile 12, 12, 0x401, FALSE
	setmetatile 13, 11, 0x401, FALSE
	setmetatile 13, 12, 0x401, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GATE
	release
	end

RocketHideout_B3F_EventScript_DoorIsOpen::
	end

RocketHideout_B3F_EventScript_GruntF5::
	trainerbattle_single TRAINER_GRUNT_29 RocketHideout_B3F_Text_GruntF5Seen, RocketHideout_B3F_Text_GruntF5Beaten
	msgbox RocketHideout_B3F_Text_GruntF5After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_GRUNTF, RocketHideout_B3F_EventScript_IncrementPasswordGruntF
	end

RocketHideout_B3F_EventScript_IncrementPasswordGruntF::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_GRUNTF
	end

RocketHideout_B3F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_2 RocketHideout_B3F_Text_GruntM28Seen, RocketHideout_B3F_Text_GruntM28Beaten
	msgbox RocketHideout_B3F_Text_GruntM28After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_ETO, RocketHideout_B3F_EventScript_IncrementPasswordEto
	end

RocketHideout_B3F_EventScript_IncrementPasswordEto::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_ETO
	end

RocketHideout_B3F_EventScript_Ross::
	trainerbattle_single TRAINER_ROSS RocketHideout_B3F_Text_ScientistRossSeen, RocketHideout_B3F_Text_ScientistRossBeaten
	msgbox RocketHideout_B3F_Text_ScientistRossAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Mitch::
	trainerbattle_single TRAINER_MITCH RocketHideout_B3F_Text_ScientistMitchSeen, RocketHideout_B3F_Text_ScientistMitchBeaten
	msgbox RocketHideout_B3F_Text_ScientistMitchAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword:
    .string "门关着……\p要打开它需要两个密码。$"
    .string ""

RocketHideout_B3F_Text_B3FLockedDoorOpenSesame:
    .string "门关着……\p{PLAYER}输入了两个密码。\p门打开了！$"
    .string ""
    .string ""

RocketHideout_B3F_Text_Rival:
    .string "……\p我不是跟你说过，\n我要毁掉火箭队吗？\p……我问你，那个穿着斗篷、\n使用龙宝可梦的家伙是谁？\p我的宝可梦完全不是对手。\p让我在意的，\n是他说的那番话……\p他说我对宝可梦的爱和信任\n还不够。\p我的队伍这么没用，\n又不是我的错。\p输给那种心软的家伙，\n我实在咽不下这口气。\p但我也不得不去想。\p是不是我自己\n有哪里做错了？\p难道说，是爱让他的队伍\n变得那么强？$"
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
    .string ""
    .string ""
    .string ""

@=======[PETREL]==============================================================================================================================

RocketHideout_B3F_EventScript_Giovanni::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_PetrelIntro, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, Common_Movement_QuestionMark
	delay 60
	msgbox RocketHideout_B3F_Text_PetrelDisbelief MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, RocketHideout_B3F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	removeobject LOCALID_ROCKETHIDEOUT3_GIOVANNI
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	addobject LOCALID_ROCKETHIDEOUT3_PETREL
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_Spin2
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWest
	createfieldmugshot MUGSHOT_PETREL
	msgbox RocketHideout_B3F_Text_PetrelReveal, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_1, RocketHideout_B3F_Text_PetrelBeaten
	createfieldmugshot MUGSHOT_PETREL
	msgbox RocketHideout_B3F_Text_PetrelAfterBattle, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_LeaveEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_LeaveWest
	call_if_eq VAR_FACING, DIR_NORTH, RocketHideout_B3F_EventScript_LeaveEast
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_PETREL
	
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow1

	delay 120

	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEastMurkrow
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWestMurkrow

	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	msgbox RocketHideout_B3F_Text_MurkrowMimic, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow2
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW

	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROW
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROW
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	setvar VAR_ROCKET_PASSWORD, 3
	setvar VAR_MAHOGANY_TOWN_STATE, 9
	release
	end

RocketHideout_B3F_EventScript_FacingEastMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingWestMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingEast::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_WEST
	return

RocketHideout_B3F_EventScript_FacingWest::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_EAST
	return

RocketHideout_B3F_EventScript_FacingNorth::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_SOUTH
	return

RocketHideout_B3F_EventScript_LeaveEast::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveEast
	waitmovement 0
	return

RocketHideout_B3F_EventScript_LeaveWest::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveWest
	waitmovement 0
	return

RocketHideout_B3F_Movement_Murkrow1:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	jump_in_place_right
	jump_in_place_left
	jump_in_place_down
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

RocketHideout_B3F_Movement_Murkrow2:
	jump_in_place_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	step_end

RocketHideout_B3F_Movement_LeaveEast:
	lock_facing_direction
	walk_slow_right
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end
RocketHideout_B3F_Movement_LeaveWest:
	lock_facing_direction
	walk_slow_left
	walk_slow_left
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B3F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Text_PetrelIntro:
    .string "哇哈哈哈，我们一直在等\n你。你就是{PLAYER}吗……\p我？你不知道我是谁？\n我就是坂木。\p威风凛凛的坂木大人！\n哇哈哈哈！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B3F_Text_PetrelDisbelief:
    .string "……咦？\n你说我的声音\l一点都不像坂木？\p我连长相都不像坂木？\n怎么会？我可是拼了命\l在模仿他啊！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B3F_Text_PetrelReveal:
    .string "拉姆达：我可是火箭队的\n干部！\p你一定是想偷偷溜进\n无线电发射室吧。\p哼，别做梦了。\n那个房间上着\l特别的密码锁。\p密码就是“坂木大人万岁”。\n从我嘴里听到它，很吃惊吧？\p不过，就算知道了密码\n你也进不去。\p那道门只有我亲口说出密码\n才会打开。它只认\l我的声音。$"
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

RocketHideout_B3F_Text_PetrelBeaten:
    .string "我……我什么都做不了……\p坂木大人，请原谅我……$"
    .string ""

RocketHideout_B3F_Text_PetrelAfterBattle:
    .string "拉姆达：三年前火箭队解散之后，\n我们的坂木大人就一直\l下落不明。\p但他一定在某个地方等待着，\n等待我们东山再起的\l时机……哇哈哈哈！\p就算输给你，也改变不了\n你进不去无线电发射室\l这件事！\p要打开那道门，\n需要我的声音！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B3F_EventScript_Murkrow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RocketHideout_B3F_Text_MurkrowSpeak1:
    .string "黑暗鸦：坂木大人万岁。$"

RocketHideout_B3F_Text_MurkrowMimic:
    .string "黑暗鸦在模仿\n拉姆达的声音！\p说不定能行……！？$"
    .string ""
    .string ""

RocketHideout_B3F_Text_Murkrow:
    .string "黑暗鸦：密码是……\p坂木大人万岁。$"
    .string ""

RocketHideout_B3F_Text_GruntF5Seen:
    .string "问我知不知道密码？\p也许吧。\p但我可不会告诉\n弱小的人！$"
    .string ""
    .string ""
    .string ""

RocketHideout_B3F_Text_GruntF5Beaten:
    .string "好吧，住手。我告诉你。$"

RocketHideout_B3F_Text_GruntF5After:
    .string "老大房间的密码\n就是呆呆兽的尾巴。\p不过，只拿到一个密码\n是没用的。$"
    .string ""
    .string ""
    .string ""

RocketHideout_B3F_Text_GruntM28Seen:
    .string "哼哼哼！\p我还记得你在井边干的好事！\p又来挑战我了？\p哈！你这人是疯了吧，\n不过挺有胆量！\p先跟你说好，我可变强了！\p你要是能打赢我，我就把\l老大房间的其中一个密码\n告诉你！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B3F_Text_GruntM28Beaten:
    .string "哼哼哼！你挺有两下子嘛！$"

RocketHideout_B3F_Text_GruntM28After:
    .string "哼哼哼！\n老大房间的密码……\p呃……我记得是拉达的尾巴。$"
    .string ""
    .string ""

RocketHideout_B3F_Text_ScientistRossSeen:
    .string "我以前在西尔佛公司做事，现在\n在为火箭队做研究。\p像你这样爱捣乱的孩子，\n就该受点教训。$"
    .string ""
    .string ""
    .string ""

RocketHideout_B3F_Text_ScientistRossBeaten:
    .string "只是一次战术失误就输了……$"

RocketHideout_B3F_Text_ScientistRossAfter:
    .string "能让宝可梦发狂的\n无线电波……\p我的实验完全\n成功了。\p我的晋升已经稳了。这点\n失败根本算不了什么。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RocketHideout_B3F_Text_ScientistMitchSeen:
    .string "实验让宝可梦受了多少苦，\n我一点都不在乎。$"
    .string ""

RocketHideout_B3F_Text_ScientistMitchBeaten:
    .string "我擅长的是动脑子，\n可不是对战。$"
    .string ""

RocketHideout_B3F_Text_ScientistMitchAfter:
    .string "要是把无线电信号的功率\n调高，向全国\l播送……\p光是想想就让我兴奋不已！$"
    .string ""
    .string ""
    .string ""
