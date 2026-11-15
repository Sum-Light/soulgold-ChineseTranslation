DarkraiInn1Ruined_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkraiInn1Ruined_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

DarkraiInn1Ruined_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_TEMP_HIDE_FOLLOWER
	return


Inn_RuinedPiano::
	lock
	compare VAR_DARKRAI_INN_PROGRESS, 6
	goto_if_lt Inn_RuinedPiano_2
	compare VAR_DARKRAI_INN_PROGRESS, 6
	goto_if_eq Inn_RuinedPiano_5
	compare VAR_DARKRAI_INN_PROGRESS, 7
	goto_if_ge Inn_RuinedPiano_8
	release
	end

Inn_RuinedPiano_2:
	playse SE_NOTE_G
	msgbox Inn_RuinedPiano_Text_0
	waitse
	release
	end

Inn_RuinedPiano_5:
	msgbox Inn_RuinedPiano_Text_1
	playfanfare MUS_HG_OBTAIN_ITEM
	msgbox Inn_RuinedPiano_Text_2
	waitfanfare
	setvar VAR_DARKRAI_INN_PROGRESS, 7
	release
	end

Inn_RuinedPiano_8:
	msgbox Inn_RuinedPiano_Text_3
	release
	end


Inn_RuinedDrums::
	msgbox Inn_RuinedDrums_Text_0, MSGBOX_SIGN
	return


Inn_RuinedSafe::
	compare VAR_DARKRAI_INN_PROGRESS, 7
	goto_if_lt Inn_RuinedSafe_2
Inn_RuinedSafe_1:
	compare VAR_DARKRAI_INN_PROGRESS, 7
	goto_if_eq Inn_RuinedSafe_5
Inn_RuinedSafe_4:
	release
	end

Inn_RuinedSafe_2:
	msgbox Inn_RuinedSafe_Text_0, MSGBOX_SIGN
	goto Inn_RuinedSafe_1

Inn_RuinedSafe_5:
	msgbox Inn_RuinedSafe_Text_1
	msgbox Inn_RuinedSafe_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Inn_RuinedSafe_7
	goto Inn_RuinedSafe_4

Inn_RuinedSafe_7:
	warp MAP_DARKRAI_INN_FINAL_ROOM, 0
	waitstate
	end


InnHideCresselia::
	setflag FLAG_HIDE_DARKRAI_INN_NPC
	removeobject 1
	setvar VAR_TEMP_0, 1
	return


Inn_RuinedTelephone::
	lock
	compare VAR_DARKRAI_INN_PROGRESS, 4
	goto_if_lt Inn_RuinedTelephone_2
	compare VAR_DARKRAI_INN_PROGRESS, 4
	goto_if_eq Inn_RuinedTelephone_5
Inn_RuinedTelephone_4:
	compare VAR_DARKRAI_INN_PROGRESS, 5
	goto_if_eq Inn_RuinedTelephone_8
Inn_RuinedTelephone_7:
	compare VAR_DARKRAI_INN_PROGRESS, 5
	goto_if_gt Inn_RuinedTelephone_13
	return

Inn_RuinedTelephone_2:
	msgbox Inn_RuinedTelephone_Text_0
	release
	end

Inn_RuinedTelephone_5:
	msgbox Inn_RuinedTelephone_Text_1
	setvar VAR_DARKRAI_INN_PROGRESS, 5
	msgbox Inn_RuinedTelephone_Text_2
	dynmultichoice 20, 4, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, Inn_RuinedTelephone_Text_3, Inn_RuinedTelephone_Text_4, Inn_RuinedTelephone_Text_5
	switch VAR_RESULT
	case 0, Inn_RuinedTelephone_11
	case 2, Inn_RuinedTelephone_11
	case 1, Inn_RuinedTelephone_12
	goto Inn_RuinedTelephone_4

Inn_RuinedTelephone_8:
	msgbox Inn_RuinedTelephone_Text_2
	dynmultichoice 20, 4, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, Inn_RuinedTelephone_Text_3, Inn_RuinedTelephone_Text_4, Inn_RuinedTelephone_Text_5
	switch VAR_RESULT
	case 0, Inn_RuinedTelephone_16
	case 2, Inn_RuinedTelephone_16
	case 1, Inn_RuinedTelephone_17
	goto Inn_RuinedTelephone_7

Inn_RuinedTelephone_11:
	msgbox Inn_RuinedTelephone_Text_6
	release
	end

Inn_RuinedTelephone_12:
	playse SE_CLICK
	turnobject LOCALID_PLAYER, DIR_EAST
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_DARKRAI_INN_PROGRESS, 6
	release
	end

Inn_RuinedTelephone_13:
	msgbox Inn_RuinedTelephone_Text_7
	release
	end

Inn_RuinedTelephone_16:
	msgbox Inn_RuinedTelephone_Text_6
	release
	end

Inn_RuinedTelephone_17:
	playse SE_CLICK
	turnobject LOCALID_PLAYER, DIR_EAST
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_DARKRAI_INN_PROGRESS, 6
	release
	end


Inn_RuinedDoor::
	msgbox Inn_RuinedDoor_Text_0, MSGBOX_SIGN
	return


Inn_NotesOnWall::
	lock
	compare VAR_DARKRAI_INN_PROGRESS, 2
	goto_if_eq Inn_NotesOnWall_2
	msgbox Inn_NotesOnWall_Text_1
Inn_NotesOnWall_1:
	release
	end

Inn_NotesOnWall_2:
	msgbox Inn_NotesOnWall_Text_0
	setvar VAR_DARKRAI_INN_PROGRESS, 3
	goto Inn_NotesOnWall_1


Inn_LuxrayHead::
	lock
	compare VAR_DARKRAI_INN_PROGRESS, 3
	goto_if_eq Inn_LuxrayHead_1
	msgbox Inn_LuxrayHead_Text_2
	release
	end

Inn_LuxrayHead_1:
	msgbox Inn_LuxrayHead_Text_0
	playfanfare MUS_HG_OBTAIN_ITEM
	msgbox Inn_LuxrayHead_Text_1
	waitfanfare
	setvar VAR_DARKRAI_INN_PROGRESS, 4
	release
	end


Inn_RuinedPiano_Text_0:
	.string "钢琴能弹出声音，\n但总觉得哪里不对。$"

Inn_RuinedPiano_Text_1:
	.string "有个琴键松动了。\p……\p下面藏着一把小钥匙！$"

Inn_RuinedPiano_Text_2:
	.string "{PLAYER}得到了小钥匙！$"

Inn_RuinedPiano_Text_3:
	.string "钢琴里已经没剩下什么了。$"

Inn_RuinedDrums_Text_0:
	.string "架子鼓上落满了灰尘。$"

Inn_RuinedSafe_Text_0:
	.string "保险箱锁得严严实实。$"

Inn_RuinedSafe_Text_1:
	.string "你找到的钥匙正好\n插进保险箱的锁里。\p保险箱里面似乎有\n一条挖穿墙壁的密道。$"

Inn_RuinedSafe_Text_2:
	.string "要进去吗？$"

Inn_RuinedTelephone_Text_0:
	.string "一部老式电话。\n拨号盘好像不见了。$"

Inn_RuinedTelephone_Text_1:
	.string "你把拨号盘装到电话上。\p……\p装得严丝合缝！$"

Inn_RuinedTelephone_Text_2:
	.string "要拨哪个号码？$"

Inn_RuinedTelephone_Text_3:
	.string "4114$"

Inn_RuinedTelephone_Text_4:
	.string "1144$"

Inn_RuinedTelephone_Text_5:
	.string "4141$"

Inn_RuinedTelephone_Text_6:
	.string "没有回应……$"

Inn_RuinedTelephone_Text_7:
	.string "电话没有反应。$"

Inn_RuinedDoor_Text_0:
	.string "门锁得紧紧的，\n说不定钥匙就在哪里？$"

Inn_NotesOnWall_Text_0:
	.string "墙上的图纸似乎是\n旅馆的平面图。\p所有家具都标得\n清清楚楚。\p壁灯11盏\n大窗户4扇\l萌芽鹿标本4个\p……$"

Inn_NotesOnWall_Text_1:
	.string "壁灯11盏\n大窗户4扇\l萌芽鹿标本4个\p……$"

Inn_LuxrayHead_Text_0:
	.string "平面图上没有\n这个标本。\p你凑近看了看……\p标本的嘴里，\n有一个拨号盘。$"

Inn_LuxrayHead_Text_1:
	.string "{PLAYER}得到了拨号盘！$"

Inn_LuxrayHead_Text_2:
	.string "一只宝可梦头部的\n填充标本。\p……\p总觉得那双眼睛\n在盯着你。$"
