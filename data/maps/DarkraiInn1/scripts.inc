DarkraiInn1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_TEMP_HIDE_FOLLOWER
	return

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_OPEN_INN_DOOR, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 24, 3, 0x03C, FALSE
	setmetatile 24, 2, 0x034, FALSE
	return

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_DARKRAI_INN_PROGRESS, 0, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lock
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	closemessage
	moveobjecttocoords LOCALID_PLAYER, 28, 15, DIR_NORTH
	waitmovement 0
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
	playfanfare MUS_HG_OBTAIN_ITEM
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
	waitfanfare
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4
	setvar VAR_DARKRAI_INN_PROGRESS, 1
	release
	end


Inn_Door404::
	lock
	goto_if_set FLAG_OPEN_INN_DOOR, Inn_Door404_2
	msgbox Inn_Door404_Text_1
	setmetatile 24, 3, 0x03C, FALSE
	setmetatile 24, 2, 0x034, FALSE
	playse SE_EXIT
	special DrawWholeMapView
	setflag FLAG_OPEN_INN_DOOR
	release
	end

	release
	end

Inn_Door404_2:
	msgbox Inn_Door404_Text_0
	release
	end


Inn_Keeper::
	msgbox Inn_Keeper_Text_0, MSGBOX_NPC
	return


Inn_AnimalHead::
	msgbox Inn_AnimalHead_Text_0, MSGBOX_NPC
	return


Inn_LockedDoor::
	msgbox Inn_LockedDoor_Text_0, MSGBOX_NPC
	return


FoggyWindow_Inn::
	msgbox FoggyWindow_Inn_Text_0, MSGBOX_NPC
	return


Inn_OrnatePiano::
	msgbox Inn_OrnatePiano_Text_0, MSGBOX_SIGN
	return


Inn_Drums::
	msgbox Inn_Drums_Text_0, MSGBOX_SIGN
	return


Inn_LockedSafe::
	msgbox Inn_LockedSafe_Text_0, MSGBOX_SIGN
	return


Inn_NoteOnWall::
	msgbox Inn_NoteOnWall_Text_0, MSGBOX_SIGN
	return


Inn_PapersOnWall::
	msgbox Inn_PapersOnWall_Text_0, MSGBOX_SIGN
	return


Inn_TryingToExit::
	lock
	turnobject LOCALID_PLAYER, DIR_SOUTH
	msgbox Inn_TryingToExit_Text_0
	closemessage
	applymovement LOCALID_PLAYER, Inn_TryingToExit_Movement_0
	waitmovement
	release
	end


Inn_ReceptionPhone::
	msgbox Inn_ReceptionPhone_Text_0, MSGBOX_SIGN
	return


Inn_TryingToExit_Movement_0:
	walk_up
	step_end

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "欢迎光临，尊贵的客人！$"

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "您肯光临我们这家小旅馆，\n真是我们的荣幸。\p这是您房间的钥匙。$"

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "{PLAYER}得到了月亮钥匙！$"

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
	.string "您的房间是404号，\n从左边楼梯上去，\l就在正前方。$"

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
	.string "祝您入住愉快。$"

Inn_Door404_Text_0:
	.string "您房间的门已经打开了。$"

Inn_Door404_Text_1:
	.string "404号房\p你用钥匙打开了房门，\n可钥匙却卡在了\l锁孔里。$"

Inn_Keeper_Text_0:
	.string "希望您在我们旅馆\n安安稳稳地休息。$"

Inn_AnimalHead_Text_0:
	.string "一只宝可梦头部的\n填充标本。\p……\p总觉得那双眼睛\n在盯着你。$"

Inn_LockedDoor_Text_0:
	.string "你试着开门，\n但门好像锁着。$"

FoggyWindow_Inn_Text_0:
	.string "你朝窗外望去……\p一层浓雾好像遮住了\n你的视线。$"

Inn_OrnatePiano_Text_0:
	.string "你面前放着一架华丽的钢琴。\n看起来保养得很好。$"

Inn_Drums_Text_0:
	.string "看起来崭新的架子鼓。真帅！$"

Inn_LockedSafe_Text_0:
	.string "一个上锁的保险箱，\n不知道里面装着什么。$"

Inn_NoteOnWall_Text_0:
	.string "好像是一张关于旅馆\n停业的通知。真奇怪……$"

Inn_PapersOnWall_Text_0:
	.string "墙上贴满了各种便条，\n字迹模糊，难以辨认。$"

Inn_TryingToExit_Text_0:
	.string "你才刚到，\n没理由这就走吧……$"

Inn_ReceptionPhone_Text_0:
	.string "这大概是用来呼叫\n住客的吧。$"
