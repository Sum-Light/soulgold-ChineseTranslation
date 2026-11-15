.set LOCALID_MAHOGANYSHOP_LANCE, 3
.set LOCALID_MAHOGANYSHOP_DRAGONITE,4
.set LOCALID_MAHOGANYSHOP_ROCKET, 2

MahoganyTown_Shop_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MahoganyTown_Shop_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MahoganyTown_Shop_OnFrame
	.byte 0

MahoganyTown_Shop_OnLoad:
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 5, MahoganyTown_Shop_SetStairs
	end

MahoganyTown_Shop_SetStairs::
	setmetatile 8, 4, 0x40D, FALSE
	end

MahoganyTown_Shop_OnFrame::
	map_script_2 VAR_MAHOGANY_TOWN_STATE, 4, MahoganyTown_Shop_EventScript_Raid
	.2byte 0

MahoganyTown_Shop_EventScript_Raid::
	playbgm MUS_HG_TEAM_ROCKET_HQ, TRUE
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	createfieldmugshot MUGSHOT_LANCE
	msgbox MahoganyMart1F_Text_Lance_HyperBeam, MSGBOX_DEFAULT
	closemessage
	playse SE_M_HYPER_BEAM
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, MahoganyTown_Shop_Movement_Dragonite1
	delay 10
	applymovement LOCALID_MAHOGANYSHOP_ROCKET, MahoganyTown_Shop_Movement_Rocket1
	waitmovement LOCALID_MAHOGANYSHOP_ROCKET
	waitse
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitmovement LOCALID_MAHOGANYSHOP_DRAGONITE
	waitse
	delay 10
	turnobject LOCALID_MAHOGANYSHOP_LANCE, DIR_SOUTH
	delay 50
	applymovement LOCALID_MAHOGANYSHOP_LANCE, MahoganyTown_Shop_Movement_LanceGreetPlayer
	waitmovement 0
	createfieldmugshot MUGSHOT_LANCE
	msgbox MahoganyMart1F_Text_Lance_Radio, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, Common_Movement_QuestionMark
	delay 10
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, MahoganyTown_Shop_Movement_DragoniteGotoBox
	waitmovement 0
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	waitmovement 0
	applymovement LOCALID_MAHOGANYSHOP_LANCE, MahoganyTown_Shop_Movement_LanceGotoBox
	applymovement OBJ_EVENT_ID_PLAYER, MahoganyTown_Shop_Movement_PlayerGotoBox
	waitmovement LOCALID_MAHOGANYSHOP_LANCE
	waitmovement OBJ_EVENT_ID_PLAYER

	playse SE_M_HYPER_BEAM
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, MahoganyTown_Shop_Movement_Dragonite2
	delay 20
	waitse
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera

	waitmovement 0
	
	setmetatile 8, 4, 0x40D, FALSE
	special DrawWholeMapView
	delay 40
	msgbox MahoganyMart1F_Text_Lance_Stairs, MSGBOX_DEFAULT
	turnobject LOCALID_MAHOGANYSHOP_DRAGONITE, DIR_WEST
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	waitmoncry
	turnobject LOCALID_MAHOGANYSHOP_DRAGONITE, DIR_EAST

	turnobject LOCALID_MAHOGANYSHOP_LANCE, DIR_SOUTH
	msgbox MahoganyMart1F_Text_Lance_SplitUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAHOGANYSHOP_DRAGONITE, Common_Movement_WalkRight1
	waitmovement 0
	removeobject LOCALID_MAHOGANYSHOP_DRAGONITE
	playse SE_EXIT
	applymovement LOCALID_MAHOGANYSHOP_LANCE, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LOCALID_MAHOGANYSHOP_LANCE, Common_Movement_WalkRight1
	waitmovement 0
	removeobject LOCALID_MAHOGANYSHOP_LANCE
	playse SE_EXIT
	delay 50

	playse SE_PIN
	applymovement LOCALID_MAHOGANYSHOP_ROCKET Common_Movement_ExclamationMark
	delay 20
	applymovement LOCALID_MAHOGANYSHOP_ROCKET MahoganyTown_Shop_Movement_RocketLeave
	waitmovement 0
	removeobject LOCALID_MAHOGANYSHOP_ROCKET
	playse SE_EXIT
	setflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS


	setvar VAR_MAHOGANY_TOWN_STATE, 5
	release
	end

MahoganyTown_Shop_Movement_RocketLeave:
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	step_end

MahoganyTown_Shop_Movement_Dragonite1:
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	walk_fast_left
	walk_fast_left
	unlock_facing_direction
	step_end

MahoganyTown_Shop_Movement_Dragonite2:
	lock_facing_direction
	walk_fast_right
	walk_fast_left
	unlock_facing_direction
	step_end

MahoganyTown_Shop_Movement_Rocket1:
	lock_facing_direction
	slide_right
	slide_right
	unlock_facing_direction
	step_end

MahoganyTown_Shop_Movement_LanceGreetPlayer:
	walk_down
	walk_right
	walk_right
	face_down
	step_end

MahoganyTown_Shop_Movement_DragoniteGotoBox:
	face_up
	delay_2
	face_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MahoganyTown_Shop_Movement_LanceGotoBox:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

MahoganyTown_Shop_Movement_PlayerGotoBox:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MahoganyTown_Shop_EventScript_Granny::
	lock
	faceplayer
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 5, MahoganyTown_Shop_EventScript_GrannyDuring
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, MahoganyTown_Shop_EventScript_GrannyShop
	msgbox MahoganyTown_Shop_Text_Granny, MSGBOX_NPC
	release
	end

MahoganyTown_Shop_EventScript_GrannyDuring::
	msgbox MahoganyMart1F_Text_Pharmacist_Lance, MSGBOX_DEFAULT
	closemessage
	release
	end


MahoganyTown_Shop_EventScript_GrannyShop::
	message gText_HowMayIServeYou
	waitmessage
	pokemart MahoganyTown_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MahoganyTown_Pokemart:
	.2byte ITEM_TM_PAYBACK
	.2byte ITEM_TM_SUBSTITUTE
	.2byte ITEM_METAL_COAT
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end

MahoganyTown_Shop_Text_Granny:
	.string "请您改天再来。\n本店现在……\l暂停营业。$"
	.string ""
	.string ""

MahoganyMart1F_Text_Pharmacist_Lance:
    .string "火箭队占领了我的地下室！$"

MahoganyMart1F_Text_BlackBelt:
    .string "嘿嘿！实验\n大获成功。\p鲤鱼王毫无价值，\n可暴鲤龙就是摇钱树了。$"
    .string ""
    .string ""
    .string ""

MahoganyMart1F_Text_BlackBelt_Lance:
    .string "唔……\p那家伙的宝可梦\n好强……$"
    .string ""

MahoganyMart1F_Text_Lance_HyperBeam:
    .string "阿渡：快龙，破坏光线。$"

MahoganyMart1F_Text_Lance_Radio:
    .string "{PLAYER}，你怎么这么慢？\p果然和我们想的一样，那段\n古怪的电波就是从这里发出的。$"
    .string ""
    .string ""

MahoganyMart1F_Text_Lance_Stairs:
    .string "找到楼梯了，干得好，\n快龙！$"
	.string ""

MahoganyMart1F_Text_Lance_SplitUp:
    .string "阿渡：{PLAYER}，我们分头\n调查这里吧。\p我先走一步。$"
    .string ""
    .string ""

MahoganyMart_LowBadgeCountWarning::
	setvar VAR_TEMP_0, 1
	goto_if_ge VAR_NUM_BADGES, 6, MahoganyMart_LowBadgeCountWarning_End
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 5, MahoganyMart_LowBadgeCountWarning_End
	goto_if_set FLAG_ROCKETWARNING_SET, MahoganyMart_LowBadgeCountWarning_End
	lock
	msgbox MahoganyMart_Text_LowBadgeCountWarning, MSGBOX_DEFAULT
	setflag FLAG_ROCKETWARNING_SET
	release
MahoganyMart_LowBadgeCountWarning_End:
	end

MahoganyMart_Text_LowBadgeCountWarning:
	.string "你觉得以你现在的经验，\n前方区域可能会\l很棘手。\p如果不放心，先多收集几枚\n徽章或许会有帮助。$"
	.string ""
	.string ""
	.string ""
	.string ""
