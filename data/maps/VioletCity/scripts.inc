

VioletCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VioletCity_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_LOAD, VioletCity_OnLoad
	.byte 0

VioletCity_OnFrame::
	map_script_2 VAR_VIOLET_CITY_KIMONO_GIRL, 1, VioletCity_EventScript_Kimono_Girl
	map_script_2 VAR_VIOLET_CITY_STATE, 3, VioletCity_EventScript_ElmCall_Trigger
	.2byte 0

VioletCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

VioletCity_OnLoad::
	setrespawn HEAL_LOCATION_VIOLET_CITY
	setflag FLAG_VISITED_VIOLET_CITY
	end

VioletCity_EventScript_Trigger::
	@LOCAL FLAGHEAP
	clearflag FLAG_RECEIVED_TOGEPI_EGG
	clearflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	clearflag FLAG_HIDE_SPROUT_TOWER_SILVER
	clearflag FLAG_HIDE_JOHTO_GYM_LEADERS
	clearflag FLAG_HOOH_BROUGHT
	clearflag FLAG_OMANYTE_BROUGHT
	clearflag FLAG_AERODACTYL_BROUGHT
	clearflag FLAG_KABUTO_BROUGHT
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_GOT_HARD_STONE
	clearflag FLAG_GOT_POISON_BARB
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_GOT_BLACK_GLASSES
	
	setvar VAR_SLOWPOKE_TAIL, 0
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 0
	setvar VAR_RUINSOFALPH_STATE, 0
	
	setflag FLAG_HIDE_TRAINER_SCHOOL_EARL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	
	setvar VAR_SPROUT_TOWER, 0
	setvar VAR_VIOLET_CITY_STATE, 1
	end

VioletCity_EventScript_Earl::
	lock
	faceplayer
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	waitmovement 0
	faceplayer
	msgbox VioletCity_Text_EarlAsksIfYouBeatFalkner MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_EventScript_EarlTrainerSchool
	msgbox VioletCity_Text_VeryNiceIndeed, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_EarlTrainerSchool::
	msgbox VioletCity_Text_FollowEarl, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	switch VAR_FACING
	case DIR_NORTH, VioletCity_EventScript_EarlTrainerSchoolSouth
	case DIR_WEST, VioletCity_EventScript_EarlTrainerSchoolEast
	release
	end

VioletCity_EventScript_EarlTrainerSchoolSouth::
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_South_Adjustment
	waitmovement 0
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_South_Adjustment
	waitmovement 0
	waitmovement 0
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
	release
	end

VioletCity_EventScript_EarlTrainerSchoolEast::
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_East_Adjustment
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_East_Adjustment
	waitmovement 0
	waitmovement 0
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
	release
	end

VioletCity_EventScript_EarlTrainerSchoolTransition:
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Walk_To_School
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Walk_To_School
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	waitmovement 0
	turnobject LOCALID_VIOLETCITY_EARL, DIR_WEST
	msgbox VioletCity_Text_HereTeacherIAm, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Walk_Inside
	delay 20
	opendoor 39, 36
	waitdooranim
	waitmovement 0
	setflag FLAG_HIDE_VIOLET_CITY_EARL
	removeobject LOCALID_VIOLETCITY_EARL
	closedoor 39, 36
	waitdooranim
	clearflag FLAG_HIDE_TRAINER_SCHOOL_EARL
	fadedefaultbgm
	release
	end

VioletCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox VioletCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Boy::
	lock
	faceplayer
	msgbox VioletCity_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox VioletCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Lass::
	lock
	faceplayer
	msgbox VioletCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Pichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PICHU, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Pichu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_Bellsprout::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BELLSPROUT, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Bellsprout, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_Rattata::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Rattata, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_ElmCall_Trigger::
	lock
	pokenavcall VioletCity_Text_Elm_Call
	waitmessage
	delay 30
	clearflag FLAG_HIDE_VIOLET_CITY_AIDE
	setflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	setvar VAR_VIOLET_CITY_STATE, 4
	release
	end

VioletCity_EventScript_Kimono_Girl::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	playse SE_PIN
	applymovement LOCALID_VIOLET_KIMONO, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_1
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_2
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_3
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl3, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_4
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_5
	waitmovement 0
	fadedefaultbgm
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 2
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	removeobject LOCALID_VIOLET_KIMONO
	release
	end


VioletCity_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

VioletCity_EventScript_ItemPechaBerry::
	finditem ITEM_PECHA_BERRY
	end

VioletCity_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

VioletCity_Movement_Earl_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

VioletCity_Movement_Earl_East_Adjustment:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VioletCity_Movement_Player_East_Adjustment:
	walk_down
	walk_down
	walk_left
	walk_down
	face_right
	step_end

VioletCity_Movement_Earl_South_Adjustment:
	walk_right
	walk_down
	walk_down
	walk_down
	face_right
	step_end

VioletCity_Movement_Player_South_Adjustment:
	walk_down
	walk_down
	step_end

VioletCity_Movement_Walk_To_School:
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

VioletCity_Movement_Walk_To_School_Player:
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
	step_end

VioletCity_Movement_Earl_Walk_Inside:
	walk_up
	walk_up
	step_end

VioletCity_Movement_Kimono_Girl_1:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

VioletCity_Movement_Kimono_Girl_2:
	walk_up
	step_end

VioletCity_Movement_Kimono_Girl_3:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

VioletCity_Movement_Kimono_Girl_4:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	step_end

VioletCity_Movement_Kimono_Girl_5:
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
	walk_up
	walk_up
	walk_up
	step_end	

VioletCity_EventScript_LiquidJustice::
	msgbox VioletCity_Text_LiquidJustice, MSGBOX_NPC
	end

VioletCity_EventScript_GymSign::
	msgbox VioletCity_Text_GymSign, MSGBOX_SIGN
	end

VioletCity_Text_LiquidJustice:
	.string "到处看看吧！\p很容易就能看出，\n这片区域里\l能抓到什么宝可梦，\l不用整天在草丛里跑来跑去！$"
	.string ""
	.string ""
	.string ""
	.string ""

VioletCity_Text_EarlAsksIfYouBeatFalkner:
	.string "嗨！你是训练家？\p道馆馆主，\n打赢过没有？$"
	.string ""
	.string ""
	.string ""

VioletCity_Text_VeryNiceIndeed:
	.string "哦啦啦！\n真是厉害，实在厉害！$"
	.string ""

VioletCity_Text_FollowEarl:
	.string "原来如此！那你就\n学一学吧！跟我来！$"
	.string ""

VioletCity_Text_HereTeacherIAm:
	.string "我就是老师，老师！\n你在这里学习，好！$"
	.string ""

VioletCity_Text_Lass:
	.string "听说喇叭芽之塔里\n会闹幽灵。\p据说幽灵属性招式\n能绕过防御，\p对大岩蛇、小拳石\n这类结实的宝可梦有效。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

VioletCity_Text_Boy:
	.string "嘿，你是宝可梦训练家？\p去学院看看，\n说不定能学到点新东西！$"
	.string ""
	.string ""

VioletCity_Text_Gramps:
	.string "桔梗宝可梦道馆的阿速，\n是个了不起的训练家！\p他继承了父亲的\n道馆，\l经营得有声有色。$"
	.string ""
	.string ""
	.string ""
	.string ""

VioletCity_Text_Youngster:
	.string "我看见前面有一棵\n摇来摇去的树！\p一碰它就会扭来扭去，\n还会跳舞！真酷！$"
	.string ""
	.string ""

VioletCity_Text_Sign:
	.string "桔梗市\p怀古飘香的城市$"
	.string ""

VioletCity_Text_GymSign:
	.string "桔梗市宝可梦道馆\p馆主：阿速\n优雅的飞行宝可梦使者$"
	.string ""
	.string ""

VioletCity_Text_SproutTowerSign:
	.string "喇叭芽之塔\p体验宝可梦之道$"
	.string ""

VioletCity_Text_EarlsAcademySign:
	.string "虎男的宝可梦学院$"

VioletCity_Text_Pichu:
	.string "皮丘：啾——！$"

VioletCity_Text_Bellsprout:
	.string "喇叭芽：芽——。$"

VioletCity_Text_Rattata:
	.string "小拉达：拉达拉达！$"

VioletCity_Text_Elm_Call:
	.string "空木博士：你好，{PLAYER}？\n关于那颗蛋，我们有了新发现！\p我的助手在桔梗市的\n宝可梦中心。\p你能去见见他吗？$"
	.string ""
	.string ""
	.string ""
	.string ""

VioletCity_Text_Kimono_Girl1:
.string "哎呀呀……\n那枚蛋一定是……！$"
.string ""

VioletCity_Text_Kimono_Girl2:
.string "我想想……\p这枚蛋从宝可梦爷爷那里\n交到空木博士手上，\l又从空木博士交到你手上。\p原来如此……$"
.string ""
.string ""
.string ""
.string ""

VioletCity_Text_Kimono_Girl3:
.string "那枚蛋真是很重要的蛋。\p请替我好好照顾它。\n明白了吗？$"
.string ""
.string ""

VioletCity_Text_Kimono_Girl4:
.string "就拜托你了。$"

berrytrader_juggler::
	lock
	faceplayer
	msgbox berrytrader_juggler_Text_0
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, berrytrader_juggler_Text_1, berrytrader_juggler_Text_2, berrytrader_juggler_Text_3, berrytrader_juggler_Text_4, berrytrader_juggler_Text_5
	switch VAR_RESULT
	case 0, berrytrader_juggler_3
	case 1, berrytrader_juggler_4
	case 2, berrytrader_juggler_5
	case 3, berrytrader_juggler_6
	msgbox berrytrader_juggler_Text_11, MSGBOX_DEFAULT
	waitmessage
	release
	end

	release
	end

berrytrader_juggler_3:
	checkitem ITEM_RED_SHARD
	compare VAR_RESULT, TRUE
	goto_if_eq berrytrader_juggler_9
	msgbox berrytrader_juggler_Text_7
	release
	end

berrytrader_juggler_4:
	checkitem ITEM_BLUE_SHARD
	compare VAR_RESULT, TRUE
	goto_if_eq berrytrader_juggler_12
	msgbox berrytrader_juggler_Text_7
	release
	end

berrytrader_juggler_5:
	checkitem ITEM_YELLOW_SHARD
	compare VAR_RESULT, TRUE
	goto_if_eq berrytrader_juggler_15
	msgbox berrytrader_juggler_Text_7
	release
	end

berrytrader_juggler_6:
	checkitem ITEM_GREEN_SHARD
	compare VAR_RESULT, TRUE
	goto_if_eq berrytrader_juggler_18
	msgbox berrytrader_juggler_Text_7
	release
	end

berrytrader_juggler_9:
	msgbox berrytrader_juggler_Text_6
	removeitem ITEM_RED_SHARD, 1
	giveitem ITEM_CHERI_BERRY
	giveitem ITEM_PECHA_BERRY
	giveitem ITEM_LEPPA_BERRY
	waitmessage
	release
	end

berrytrader_juggler_12:
	msgbox berrytrader_juggler_Text_8
	removeitem ITEM_BLUE_SHARD, 1
	giveitem ITEM_ORAN_BERRY
	giveitem ITEM_CHESTO_BERRY
	giveitem ITEM_WIKI_BERRY
	waitmessage
	release
	end

berrytrader_juggler_15:
	msgbox berrytrader_juggler_Text_9
	removeitem ITEM_YELLOW_SHARD, 1
	giveitem ITEM_ASPEAR_BERRY
	giveitem ITEM_SITRUS_BERRY
	giveitem ITEM_IAPAPA_BERRY
	waitmessage
	release
	end

berrytrader_juggler_18:
	msgbox berrytrader_juggler_Text_10
	removeitem ITEM_GREEN_SHARD, 1
	giveitem ITEM_RAWST_BERRY
	giveitem ITEM_LUM_BERRY
	giveitem ITEM_AGUAV_BERRY
	waitmessage
	release
	end


DexnavDude::
	msgbox DexnavDude_Text_0, MSGBOX_NPC
	return


berrytrader_juggler_Text_0:
	.string "呀呀！我最喜欢彩色碎片！\n"
	.string "有碎片就跟我换吧，\l"
	.string "一块换三颗树果。$"

berrytrader_juggler_Text_1:
	.string "红色碎片$"

berrytrader_juggler_Text_2:
	.string "蓝色碎片$"

berrytrader_juggler_Text_3:
	.string "黄色碎片$"

berrytrader_juggler_Text_4:
	.string "绿色碎片$"

berrytrader_juggler_Text_5:
	.string "取消$"

berrytrader_juggler_Text_6:
	.string "那我就把树果组合A\n"
	.string "送给你，呀！$"

berrytrader_juggler_Text_7:
	.string "你身上好像没有那种碎片。$"

berrytrader_juggler_Text_8:
	.string "那我就把树果组合B\n"
	.string "送给你，呀！$"

berrytrader_juggler_Text_9:
	.string "那我就把树果组合C\n"
	.string "送给你，呀！$"

berrytrader_juggler_Text_10:
	.string "那我就把树果组合D\n"
	.string "送给你，呀！$"

berrytrader_juggler_Text_11:
	.string "没兴趣吗？真可惜……$"

DexnavDude_Text_0:
	.string "要是你有宝可梦装置，\n就该用用里面的图鉴导航功能。$"
