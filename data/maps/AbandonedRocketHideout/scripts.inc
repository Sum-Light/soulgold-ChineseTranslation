AbandonedRocketHideout_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_ARH_PUZZLE1, AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_2
AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	goto_if_set FLAG_ARH_PUZZLE3, AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setmetatile 17, 10, 0x500, FALSE
	setmetatile 18, 10, 0x500, FALSE
	setmetatile 19, 10, 0x500, FALSE
	setmetatile 17, 11, 0x500, FALSE
	setmetatile 18, 11, 0x500, FALSE
	setmetatile 19, 11, 0x500, FALSE
	goto AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_1

AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_4:
	setmetatile 10, 10, 0x500, FALSE
	setmetatile 11, 10, 0x500, FALSE
	setmetatile 12, 10, 0x500, FALSE
	setmetatile 10, 11, 0x500, FALSE
	setmetatile 11, 11, 0x500, FALSE
	setmetatile 12, 11, 0x500, FALSE
	return


ARH_Note1::
	msgbox ARH_Note1_Text_0, MSGBOX_SIGN
	return


ARH_MiddleDoor::
	goto_if_set FLAG_ARH_PUZZLE3, ARH_MiddleDoor_1
	msgbox ARH_MiddleDoor_Text_1, MSGBOX_SIGN
	return

ARH_MiddleDoor_1:
	msgbox ARH_MiddleDoor_Text_0, MSGBOX_SIGN
	return


ARH_RightDoor::
	goto_if_set FLAG_ARH_PUZZLE1, ARH_RightDoor_1
	msgbox ARH_RightDoor_Text_1, MSGBOX_SIGN
	return

ARH_RightDoor_1:
	msgbox ARH_RightDoor_Text_0, MSGBOX_SIGN
	return


ARH_Note2::
	msgbox ARH_Note2_Text_0, MSGBOX_SIGN
	return


ARH_Computer1::
	lock
	goto_if_set FLAG_ARH_PUZZLE1, ARH_Computer1_2
	playse SE_PC_ON
	msgbox ARH_Computer1_Text_1
	waitse
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, ARH_Computer1_Text_2, ARH_Computer1_Text_3, ARH_Computer1_Text_4, ARH_Computer1_Text_5, ARH_Computer1_Text_6
	switch VAR_RESULT
	case 3, ARH_Computer1_6
	case 4, ARH_Computer1_7
	playse SE_FAILURE
	msgbox ARH_Computer1_Text_8
ARH_Computer1_4:
	release
	return

ARH_Computer1_2:
	msgbox ARH_Computer1_Text_0, MSGBOX_SIGN
	release
	end

ARH_Computer1_6:
	playse SE_SUCCESS
	msgbox ARH_Computer1_Text_7
	setflag FLAG_ARH_PUZZLE1
	setmetatile 17, 10, 0x500, FALSE
	setmetatile 18, 10, 0x500, FALSE
	setmetatile 19, 10, 0x500, FALSE
	setmetatile 17, 11, 0x500, FALSE
	setmetatile 18, 11, 0x500, FALSE
	setmetatile 19, 11, 0x500, FALSE
	playse SE_EXIT
	special DrawWholeMapView
	goto ARH_Computer1_4

ARH_Computer1_7:
	playse SE_PC_OFF
	goto ARH_Computer1_4


ARH_BoxLeft::
	msgbox ARH_BoxLeft_Text_0, MSGBOX_SIGN
	return


ARH_BoxRight1::
	msgbox ARH_BoxRight1_Text_0, MSGBOX_SIGN
	return


ARH_BoxRightRoomRightOne2::
	goto_if_set FLAG_ARH_PUZZLE2, ARH_BoxRightRoomRightOne2_2
	lock
	msgbox ARH_BoxRightRoomRightOne2_Text_1
	playfanfare MUS_HG_OBTAIN_ITEM
	msgbox ARH_BoxRightRoomRightOne2_Text_2
	waitfanfare
	setflag FLAG_ARH_PUZZLE2
	release
	return

ARH_BoxRightRoomRightOne2_2:
	msgbox ARH_BoxRightRoomRightOne2_Text_0, MSGBOX_SIGN
	end


ARH_BoxWrong::
	random 6
	switch VAR_RESULT
	case 0, ARH_BoxWrong_2
	case 1, ARH_BoxWrong_3
	case 2, ARH_BoxWrong_4
	case 3, ARH_BoxWrong_5
	case 4, ARH_BoxWrong_6
	case 5, ARH_BoxWrong_7
	return

ARH_BoxWrong_2:
	msgbox ARH_BoxWrong_Text_0, MSGBOX_SIGN
	return

ARH_BoxWrong_3:
	msgbox ARH_BoxWrong_Text_1, MSGBOX_SIGN
	return

ARH_BoxWrong_4:
	msgbox ARH_BoxWrong_Text_2, MSGBOX_SIGN
	return

ARH_BoxWrong_5:
	msgbox ARH_BoxWrong_Text_3, MSGBOX_SIGN
	return

ARH_BoxWrong_6:
	msgbox ARH_BoxWrong_Text_4, MSGBOX_SIGN
	return

ARH_BoxWrong_7:
	msgbox ARH_BoxWrong_Text_5, MSGBOX_SIGN
	return


ARH_MachineRight::
	goto_if_set FLAG_ARH_PUZZLE3, ARH_MachineRight_2
	goto_if_unset FLAG_ARH_PUZZLE2, ARH_MachineRight_5
	lock
	msgbox ARH_MachineRight_Text_2
	playse SE_CLICK
	waitse
	setflag FLAG_ARH_PUZZLE3
	setmetatile 10, 10, 0x500, FALSE
	setmetatile 11, 10, 0x500, FALSE
	setmetatile 12, 10, 0x500, FALSE
	setmetatile 10, 11, 0x500, FALSE
	setmetatile 11, 11, 0x500, FALSE
	setmetatile 12, 11, 0x500, FALSE
	playse SE_EXIT
	special DrawWholeMapView
	msgbox ARH_MachineRight_Text_3
	release
	return

ARH_MachineRight_2:
	msgbox ARH_MachineRight_Text_0, MSGBOX_SIGN
	end

ARH_MachineRight_5:
	msgbox ARH_MachineRight_Text_1, MSGBOX_SIGN
	end


ARH_MachineRight2::
	msgbox ARH_MachineRight2_Text_0, MSGBOX_SIGN
	return


ARH_Note1_Text_0:
	.string "尘土下压着一张\n脆弱的便条……\p黑暗计划——关闭命令\p所有黑暗实验体\n即刻废弃。\p烧毁研究成果。\p不留痕迹。$"

ARH_MiddleDoor_Text_0:
	.string "中央的卷帘门已经打开了。$"

ARH_MiddleDoor_Text_1:
	.string "中央档案室\p未检测到电力继电器\p卷帘门锁死了。$"

ARH_RightDoor_Text_0:
	.string "R号仓储区\p已获准进入$"

ARH_RightDoor_Text_1:
	.string "R号仓储区\p已由黑暗协议封锁\p需要远程授权。$"

ARH_Note2_Text_0:
	.string "报告已被粉碎，\n只剩一段文字……\p“戴鲁比是首个\n保持稳定黑暗反应的\l实验体。\p此前的小拉达和超音蝠\n实验体被判定为不可用。”$"

ARH_Computer1_Text_0:
	.string "终端显示着一行字：\pR号仓储区——已解封$"

ARH_Computer1_Text_1:
	.string "旧终端断断续续地启动了。\p黑暗保险机制\n请输入首个可用\l实验体的图鉴编号。$"

ARH_Computer1_Text_2:
	.string "019$"

ARH_Computer1_Text_3:
	.string "041$"

ARH_Computer1_Text_4:
	.string "198$"

ARH_Computer1_Text_5:
	.string "228$"

ARH_Computer1_Text_6:
	.string "取消$"

ARH_Computer1_Text_7:
	.string "实验体228：戴鲁比\n授权已确认\pR号仓储区已解封。$"

ARH_Computer1_Text_8:
	.string "实验体记录遭到拒绝。$"

ARH_BoxLeft_Text_0:
	.string "箱子内衬与箱壁之间\n卡着一块写字板。\p实验体索引\n019——小拉达\l041——超音蝠\l198——黑暗鸦\l228——戴鲁比$"

ARH_BoxRight1_Text_0:
	.string "箱子里有一件火箭队制服，\n还有一张用红墨水写的便条……\p“我的寄存柜密码是041。\n马尔科夫，这次别碰。”$"

ARH_BoxRightRoomRightOne2_Text_0:
	.string "隔层是空的。$"

ARH_BoxRightRoomRightOne2_Text_1:
	.string "假底下面有\n沉重的东西挪动了一下。$"

ARH_BoxRightRoomRightOne2_Text_2:
	.string "{PLAYER}找到了磁力继电器！\p这东西好像是装在\n仓库里某台机器上的。$"

ARH_BoxWrong_Text_0:
	.string "只剩压扁的精灵球\n碎壳。每一个都被\l盖上了“不合格”的印章。$"

ARH_BoxWrong_Text_1:
	.string "数百只左手用的\n黑色手套。\p没有一只是右手的。$"

ARH_BoxWrong_Text_2:
	.string "一张出货单上写着：\p邪恶披风——40\n戏剧效果鼓风机——40$"

ARH_BoxWrong_Text_3:
	.string "包装纸上粘着一块\n石化了的愤怒馒头。$"

ARH_BoxWrong_Text_4:
	.string "箱子里塞满了假胡子，\n标签上写着“干部应急包”。$"

ARH_BoxWrong_Text_5:
	.string "箱子上写着\n“大量霹雳电球”。\p里面是空的……\p你松了一口气。$"

ARH_MachineRight_Text_0:
	.string "恢复运转的继电器\n平稳地嗡鸣着。\p中央档案室——通道已启用$"

ARH_MachineRight_Text_1:
	.string "中央卷帘门控制\p错误：未检测到磁力继电器\p继电器形状的插槽是空的。$"

ARH_MachineRight_Text_2:
	.string "磁力继电器正好\n嵌进空插槽里。$"

ARH_MachineRight_Text_3:
	.string "旧机器嗡嗡地运转起来。\p走廊里的中央卷帘门\n好像打开了。$"

ARH_MachineRight2_Text_0:
	.string "暗影测量监视器\p最后的读数定格在\n昏暗的显示屏上。\p心率：220\n攻击性：错误\l情绪：0%$"
