CianwoodCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CianwoodCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CianwoodCity_EventScript_InitializeSuicune
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CianwoodCity_RemoveEusine::
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	end

CianwoodCity_OnFrame::
	map_script_2 VAR_GETFLY, 1, CianwoodCity_EventScript_Flytrigger
	map_script_2 VAR_TEMP_F, 1, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

CianwoodCity_EventScript_CityEnter::
	call Common_EventScript_CheckElmRocketCall
	setflag FLAG_VISITED_CIANWOOD_CITY
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

CianwoodCity_EventScript_InitializeSuicune::
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 2, CianwoodCity_EventScript_InitializeNothing
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	setvar VAR_TEMP_0, 1
	end

CianwoodCity_EventScript_InitializeNothing::
	setvar VAR_TEMP_0, 1
	end

CianwoodCity_EventScript_Flytrigger::
	lock
	playse SE_PIN
	applymovement LOCALID_CIANWOOD_CHUCKSWIFE, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_CIANWOOD_CHUCKSWIFE, CianwoodCity_Movement_ChucksWife
	waitmovement 0
	msgbox CianwoodCity_Text_ChucksWifeGiveHM, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLY
	msgbox CianwoodCity_Text_ChucksWifeFlySpeech, MSGBOX_DEFAULT
	closemessage
	setvar VAR_GETFLY, 2
	release
	end

CianwoodCity_Movement_ChucksWife:
	walk_left
	walk_left
	walk_up
	walk_left
	face_up
	step_end

CianwoodCity_EventScript_Test::
	lock
	random 2
	call_if_eq VAR_RESULT, 1, EventScript_RockSmashHeartscale
	release
	end

CianwoodCity_EventScript_ChucksWife::
	lock
	faceplayer
	checkitem ITEM_HM_FLY
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_ChucksWifeAlreadyHasFly
	msgbox CianwoodCity_Text_ChucksWifeEasierToFly, MSGBOX_DEFAULT
	goto_if_set FLAG_BADGE05_GET, CianwoodCity_EventScript_ChucksWifeGiveFly
	msgbox CianwoodCity_Text_ChucksWifeBeatChuck, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_ChucksWifeGiveFly::
	msgbox CianwoodCity_Text_ChucksWifeGiveHM, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLY
	msgbox CianwoodCity_Text_ChucksWifeFlySpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_ChucksWifeAlreadyHasFly::
	msgbox CianwoodCity_Text_ChucksWifeChubby, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_ChucksWifeEasierToFly:
	.string "你是渡海来这儿的？\p那一定很辛苦吧。\p要是宝可梦会飞翔，\n就轻松多了……$"
	.string ""
	.string ""
	.string ""

CianwoodCity_Text_ChucksWifeBeatChuck:
	.string "可是没有本市的道馆徽章，\n是用不了飞翔的。\p你要是打赢了这里的道馆馆主，\n就来找我。\p我会送你好东西。$"
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodCity_Text_ChucksWifeGiveHM:
	.string "那是湛蓝市的道馆徽章！\p那你该收下这个秘传学习器。$"
	.string ""

CianwoodCity_Text_ChucksWifeFlySpeech:
	.string "让宝可梦学会飞翔吧。\p这样就能一下子飞到你\n去过的任何地方。$"
	.string ""
	.string ""

CianwoodCity_Text_ChucksWifeChubby:
	.string "我丈夫输给了你，所以\n得加倍修行才行。\p这样也好，他最近\n本来有点发福了。$"
	.string ""
	.string ""
	.string ""

CianwoodCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Youngster:
	.string "用飞翔的话，一下子就能\n回到浅葱市。$"
	.string ""

CianwoodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokefanM:
	.string "城镇北边的岩石可以打碎。\p里面也许藏着什么。\p让宝可梦用碎岩，\n就能把它们打破。$"
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Lass:
	.string "道馆馆主阿四会和他的\n格斗宝可梦对练。$"
	.string ""

CianwoodCity_EventScript_SuicuneTrigger::
	lock
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune3
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	delay 30
	playbgm MUS_HG_EUSINE, TRUE
	clearflag FLAG_HIDE_CIANWOOD_EUSINE
	addobject LOCALID_CIANWOOD_EUSINE
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine1
	waitmovement 0
	delay 55
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine2
	waitmovement 0 
	createfieldmugshot MUGSHOT_EUSINE
	msgbox CianwoodCity_Text_EusineSuicune, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_EUSINE, CianwoodCity_Text_EusineBeaten
	playbgm MUS_HG_EUSINE, TRUE
	createfieldmugshot MUGSHOT_EUSINE
	msgbox CianwoodCity_Text_EusineAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine3
	waitmovement 0
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setflag FLAG_HIDE_CIANWOOD_SUICUNE
	removeobject LOCALID_CIANWOOD_SUICUNE
	removeobject LOCALID_CIANWOOD_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 2
	setvar VAR_CIANWOOD_CITY_STATE, 2
	fadedefaultbgm
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, CianwoodCity_EventScript_DoneJohtoSuicune
	release
	end

CianwoodCity_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

CianwoodCity_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	face_down
	step_end

CianwoodCity_Movement_Suicune2:
	jump_down
	jump_2_down
	jump_right
	face_up
	step_end

CianwoodCity_Movement_Suicune3:
	jump_2_down
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

CianwoodCity_Movement_Eusine1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	step_end

CianwoodCity_Movement_Eusine2:
	face_up
	walk_up
	walk_up
	step_end

CianwoodCity_Movement_Eusine3:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CianwoodCity_Text_EusineSuicune:
	.string "米那君：哟，{PLAYER}。\p刚才那是水君吧？\p我只看到一眼，不过\n我觉得我看见水君在\l浪尖上奔跑。\p水君既美丽又威严。\p它以惊人的速度，\n穿梭于城镇和道路之间。\p真是太棒了……\p我想近距离看看水君……\p我决定了。\p我要作为训练家和你对战，\n以此赢得水君的尊敬！\p来吧，{PLAYER}。\n现在就一决胜负！$"
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

CianwoodCity_Text_EusineBeaten:
	.string "虽然不甘心，但我输了。$"

CianwoodCity_Text_EusineAfter:
	.string "你太厉害了，{PLAYER}！\p难怪宝可梦都被你吸引。\p我明白了。\p我会继续寻找\n水君。\p我们一定还会再见的。\p回头见！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodCity_EventScript_CitySign::
	lock
	msgbox CianwoodCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_Sign:
	.string "湛蓝市\p被汹涌大海环绕的港口$"
	.string ""

CianwoodCity_EventScript_GymSign::
	lock
	msgbox CianwoodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_GymSign:
	.string "湛蓝市宝可梦道馆\p馆主：阿四\p怒吼的拳头会说话$"
	.string ""
	.string ""

CianwoodCity_EventScript_Pharmacy::
	lock
	msgbox CianwoodCity_Text_PharmacySign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_PharmacySign:
	.string "五百年传统\p湛蓝市药房\p医药咨询，恭候光临$"
	.string ""
	.string ""

CianwoodCity_EventScript_CaveSign::
	lock
	msgbox CianwoodCity_Text_Safari, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_EventScript_Engineer::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Engineer, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Safari:
	.string "断崖洞窟\n通往狩猎地带。$"
	.string ""

CianwoodCity_Text_Engineer:
	.string "这条路正在施工。\n我们正在建设新的狩猎地带，\l马上就要开张了！$"
	.string ""
	.string ""
