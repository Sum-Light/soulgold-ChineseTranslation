GoldenrodApartment_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodApartment_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

GoldenrodApartment_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_MAGERNA_DOOR_OPENED, GoldenrodApartment_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

GoldenrodApartment_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 62, 8, 0x401, FALSE
	return


GoldenrodApartments_BasementGuard::
	msgbox GoldenrodApartments_BasementGuard_Text_0
	checkspecies SPECIES_ROTOM
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodApartments_BasementGuard_2
	msgbox GoldenrodApartments_BasementGuard_Text_1
	closemessage
	setflag FLAG_HIDE_GROD_APARTMENTS_GUARD
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_APARTMENT_GUARD
	delay 60
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

GoldenrodApartments_BasementGuard_2:
	release
	end


GoldenrodApartments_OldLady::
	msgbox GoldenrodApartments_OldLady_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Child::
	msgbox GoldenrodApartments_Child_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Girl::
	msgbox GoldenrodApartments_Girl_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Breloom::
	lock
	playmoncry SPECIES_BRELOOM, CRY_MODE_NORMAL
	waitmoncry
	msgbox GoldenrodApartments_Breloom_Text_0
	waitmessage
	release
	end


GoldenrodApartments_Gameboykid::
	msgbox GoldenrodApartments_Gameboykid_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_ScientistF::
	msgbox GoldenrodApartments_ScientistF_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_ScientistM::
	msgbox GoldenrodApartments_ScientistM_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_LockedDoor::
	lock
	goto_if_set FLAG_MAGERNA_DOOR_OPENED, GoldenrodApartments_LockedDoor_2
	goto_if_set FLAG_GOT_MAGERNA_KEY, GoldenrodApartments_LockedDoor_5
	msgbox GoldenrodApartments_LockedDoor_Text_3
	release
	end

GoldenrodApartments_LockedDoor_2:
	msgbox GoldenrodApartments_LockedDoor_Text_0
	release
	end

GoldenrodApartments_LockedDoor_5:
	msgbox GoldenrodApartments_LockedDoor_Text_1
	closemessage
	playse SE_UNLOCK
	setmetatile 62, 8, 0x401, FALSE
	special DrawWholeMapView
	setflag FLAG_MAGERNA_DOOR_OPENED
	waitse
	setflag FLAG_HIDE_MAGERNA_POLICE
	removeobject LOCALID_M_POLICE1
	removeobject LOCALID_M_POLICE2
	msgbox GoldenrodApartments_LockedDoor_Text_2
	release
	end


GoldenrodApartments_Apartment1::
	msgbox GoldenrodApartments_Apartment1_Text_0, MSGBOX_SIGN
	return


GoldenrodApartments_Apartment2::
	msgbox GoldenrodApartments_Apartment2_Text_0, MSGBOX_SIGN
	return


GoldenrodApartments_Apartment3::
	msgbox GoldenrodApartments_Apartment3_Text_0, MSGBOX_SIGN
	return


MagearnaEncounter::
	lock
	faceplayer
	bosslegendaryencounterwithmoves SPECIES_MAGEARNA, 75, LOCALID_MAGEARNA, FLAG_HIDE_MAGEARNA, 4, SPECIES_NONE, 110, MOVE_SHIFT_GEAR, MOVE_CALM_MIND, MOVE_DRAINING_KISS, MOVE_STORED_POWER
	release
	end


MadScientistEvent::
	lock
	msgbox MadScientistEvent_Text_0
	msgbox MadScientistEvent_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MadScientistEvent_2
	closemessage
	moveobjecttocoords LOCALID_PLAYER, 53, 14, DIR_NORTH
	waitmovement 0
	delay 15
	playbgm MUS_HG_TEAM_ROCKET_HQ, FALSE
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_1
	waitmovement 0
	msgbox MadScientistEvent_Text_2
	playse SE_LEDGE
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_2
	playse SE_LEDGE
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_2
	waitmovement
	msgbox MadScientistEvent_Text_3
	msgbox MadScientistEvent_Text_4
	delay 30
	turnobject LOCALID_MADSC, DIR_SOUTH
	msgbox MadScientistEvent_Text_5
	msgbox MadScientistEvent_Text_6
	closemessage
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_3
	waitmovement 0
	trainerbattle_no_intro TRAINER_MAD_SCIENTIST, MadScientistEvent_Text_7
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_4
	msgbox MadScientistEvent_Text_8
	closemessage
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_5
	waitmovement 0
	msgbox MadScientistEvent_Text_9
	closemessage
	playmoncry SPECIES_MAGEARNA, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_MAGEARNA, MadScientistEvent_Movement_6
	waitmovement 0
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_7
	waitmovement 0
	bosslegendaryencounterwithmoves SPECIES_MAGEARNA, 75, LOCALID_MAGEARNA, FLAG_HIDE_MAGEARNA, 4, SPECIES_NONE, 110, MOVE_SHIFT_GEAR, MOVE_CALM_MIND, MOVE_DRAINING_KISS, MOVE_STORED_POWER
	playbgm MUS_HG_TEAM_ROCKET_HQ, FALSE
	msgbox MadScientistEvent_Text_10
	msgbox MadScientistEvent_Text_11
	closemessage
	playse SE_PIN
	applymovement LOCALID_MADSC, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	turnobject LOCALID_PLAYER, DIR_SOUTH
	turnobject LOCALID_MADSC, DIR_SOUTH
	waitse
	clearflag FLAG_HIDE_MAGERNA_POLICE
	addobject LOCALID_M_POLICE1
	addobject LOCALID_M_POLICE2
	applymovement LOCALID_M_POLICE1, MadScientistEvent_Movement_8
	applymovement LOCALID_M_POLICE2, MadScientistEvent_Movement_9
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_EAST
	msgbox MadScientistEvent_Text_12
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_4
	waitmovement 0
	msgbox MadScientistEvent_Text_13
	applymovement LOCALID_M_POLICE2, MadScientistEvent_Movement_10
	waitmovement
	msgbox MadScientistEvent_Text_14
	turnobject LOCALID_M_POLICE1, DIR_WEST
	fadedefaultbgm
	msgbox MadScientistEvent_Text_15
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MADSC
	removeobject LOCALID_M_POLICE1
	removeobject LOCALID_M_POLICE2
	setflag FLAG_HIDE_MAGERNA_POLICE
	setflag FLAG_HIDE_MAD_SCIENTIST
	delay 45
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAD_SCIENTIST_EVENT_STATE, 1
	release
	end

MadScientistEvent_2:
	applymovement LOCALID_PLAYER, MadScientistEvent_Movement_0
	waitmovement 0
	release
	end


MadScientistEvent_Movement_0:
	walk_right
	step_end

MadScientistEvent_Movement_1:
	walk_in_place_up
	step_end

MadScientistEvent_Movement_2:
	jump_in_place_up
	step_end

MadScientistEvent_Movement_3:
	walk_down
	step_end

MadScientistEvent_Movement_4:
	walk_in_place_down
	step_end

MadScientistEvent_Movement_5:
	walk_right
	face_up
	step_end

MadScientistEvent_Movement_6:
	walk_down
	delay_16
	walk_down
	step_end

MadScientistEvent_Movement_7:
	face_left
	step_end

MadScientistEvent_Movement_8:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MadScientistEvent_Movement_9:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	face_left
	step_end

MadScientistEvent_Movement_10:
	walk_in_place_left
	step_end

GoldenrodApartments_BasementGuard_Text_0:
	.string "抱歉，这道楼梯通往\n公寓的储藏室。再说，\l我想也不会有哪个训练家\l会想去看那些因为过度消费\l而被丢在这里的\l旧家电吧。$"

GoldenrodApartments_BasementGuard_Text_1:
	.string "……什么？你的洛托姆\n想去看看那些家电？好吧……\l反正住客也不会\l再用它们了。要是有人问起，\l我们就当没见过。我要去\l喝杯咖啡歇歇了。$"

GoldenrodApartments_OldLady_Text_0:
	.string "这几年这座城市\n一直在不断扩张。\l我真怕自己被这飞速的\l变化甩在了后头。$"

GoldenrodApartments_Child_Text_0:
	.string "妈妈总是很晚才回家……$"

GoldenrodApartments_Girl_Text_0:
	.string "我们妈妈在播音塔工作，\n所以总是很忙。还好\l有妈妈的斗笠菇帮忙\l料理一切！$"

GoldenrodApartments_Breloom_Text_0:
	.string "斗笠菇正开开心心地洗着碗！$"

GoldenrodApartments_Gameboykid_Text_0:
	.string "这上面那层楼\n总会传来奇怪的声音。\l可我从来没见过\l住在那里的人，真奇怪。$"

GoldenrodApartments_ScientistF_Text_0:
	.string "满金市最近邀请了\n其他地区的研究员\l到播音塔开商务会议。$"

GoldenrodApartments_ScientistM_Text_0:
	.string "这些天空民宿公寓\n只勉强配有最基本的\l工具……真让人烦心。$"

GoldenrodApartments_LockedDoor_Text_0:
	.string "门已经开了。$"

GoldenrodApartments_LockedDoor_Text_1:
	.string "前路似乎被一道金属门\n挡住了。能看见一个小锁孔。\p你使用了公寓钥匙。$"

GoldenrodApartments_LockedDoor_Text_2:
	.string "路已经通了。$"

GoldenrodApartments_LockedDoor_Text_3:
	.string "前路被一道金属门\n挡住了。能看见一个小锁孔，\l可你身上没有能配上的东西。$"

GoldenrodApartments_Apartment1_Text_0:
	.string "满金天空公寓1楼$"

GoldenrodApartments_Apartment2_Text_0:
	.string "满金天空公寓2楼$"

GoldenrodApartments_Apartment3_Text_0:
	.string "满金天空公寓3楼$"

MadScientistEvent_Text_0:
	.string "你感到这个方向有麻烦。$"

MadScientistEvent_Text_1:
	.string "你准备好继续往前了吗？$"

MadScientistEvent_Text_2:
	.string "科学家：哈哈！机器就快\n完成了！\p我要向那些夺走我\n研究经费的火箭队干部\l报仇！$"

MadScientistEvent_Text_3:
	.string "科学家：还有！还有那些\n自以为是的科学委员会成员！\p这将是我的究极之作！\n啊哈哈哈哈哈哈哈哈——！$"

MadScientistEvent_Text_4:
	.string "首先……$"

MadScientistEvent_Text_5:
	.string "科学家：你是谁？\n你是怎么进来的？！$"

MadScientistEvent_Text_6:
	.string "我没空搭理\n讨债的，也没空搭理推销员！\p我这就把你打发走！$"

MadScientistEvent_Text_7:
	.string "不！这我可付不起！$"

MadScientistEvent_Text_8:
	.string "科学家：看来这次税务局\n派来了个硬茬子。\p不过没关系！\p我正想找志愿者呢，\n这反倒正好！\p就让你第一个见识\n我这只机械宝可梦的\l真正力量！$"

MadScientistEvent_Text_9:
	.string "科学家：玛机雅娜！\n消灭这个愚蠢的闯入者！$"

MadScientistEvent_Text_10:
	.string "科学家：这……这不可能！\p我的作品……没了？就这样没了？\p它本该是无敌的！\p这还没完！我还能——$"

MadScientistEvent_Text_11:
	.string "？？？：站住别动！$"

MadScientistEvent_Text_12:
	.string "警察：你因逃税、与火箭队\n有牵连，以及开发非法宝可梦\l而被捕了。$"

MadScientistEvent_Text_13:
	.string "科学家：可、可我是\n被火箭队抛弃的人啊！\p我是无辜的！我只是想\n证明他们错了！$"

MadScientistEvent_Text_14:
	.string "留着去跟法官说吧。$"

MadScientistEvent_Text_15:
	.string "警察：谢谢你帮忙\n制服了这个坏家伙。\p他躲在这里好一阵子了，\n到处惹是生非。\p只要你守口如瓶，\n那只宝可梦就归你了。\p我们相信你会好好\n照顾它的。$"
