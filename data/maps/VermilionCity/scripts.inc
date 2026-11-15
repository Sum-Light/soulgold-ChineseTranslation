.set LOCALID_VERMILION_EUSINE, 24
.set LOCALID_VERMILION_SUICUNE, 23
.set LOCALID_VERMILION_SNORLAX, 1

VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_OnLoad
	.byte 0

VermilionCity_OnLoad::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_MapScript_OnTransition::
	setflag FLAG_VISITED_VERMILION_CITY
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 3, VermilionCity_EventScript_SetSuicuneScene
	setflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE
	callnative SetTimeBasedEncounters
	end

VermilionCity_EventScript_SetSuicuneScene::
	clearflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE
	callnative SetTimeBasedEncounters
	end

VermilionCity_TriggerSuicuneTop::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailTop
	delay 60
	applymovement LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode
VermilionCity_TriggerSuicuneMid::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailMid
	delay 60
	applymovement LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode
VermilionCity_TriggerSuicuneBot::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailBot
	delay 60
	applymovement LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode

VermilionCity_EventScript_SuicuneEpisode::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_SuicuneLeave
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	msgbox VermilionCity_Text_Eusine, MSGBOX_DEFAULT
	turnobject LOCALID_VERMILION_EUSINE, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox VermilionCity_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_VERMILION_EUSINE
	removeobject LOCALID_VERMILION_SUICUNE
	setflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE

	setvar VAR_SUICUNE_ENCOUNTERS, 4
	clearflag FLAG_HIDE_ROUTE14_SUICUNE
	release
	end

VermilionCity_EventScript_Teacher::
	msgbox VermilionCity_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_EventScript_Oldman::
	msgbox VermilionCity_Text_MachopOwner, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop1, MSGBOX_DEFAULT
	waitmoncry
	msgbox VermilionCity_Text_Machop2, MSGBOX_DEFAULT
	release
	end

VermilionCity_EventScript_Nerd::
	msgbox VermilionCity_Text_SuperNerd, MSGBOX_NPC
	end

VermilionCity_EventScript_Snorlax::
	lock
	goto_if_set FLAG_KANTO_RADIO_GOT, VermilionCity_EventScript_SnorlaxWakeUp
	msgbox VermilionCity_Text_SnorlaxSleeping, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_EventScript_SnorlaxWakeUp::
	playse MUS_HG_RADIO_POKE_FLUTE
	msgbox VermilionCity_Text_RadioNearSnorlax, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SNORLAX, 50
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VermilionCity_EventScript_SnorlaxRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_VERMILION_SNORLAX
	removeobject 8
	removeobject 9
	removeobject 10
	removeobject 11
	setflag FLAG_HIDE_VERMILION_SNORLAX
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD
	release
	end

VermilionCity_EventScript_SnorlaxRan::
	release
	end

VermilionCity_EventScript_BadgeGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VERMILION_HP_UP, VermilionCity_EventScript_BadgeGuyAfter
	goto_if_ge VAR_NUM_BADGES, 16, VermilionCity_EventScript_BadgeGuyAll
	goto_if_ge VAR_NUM_BADGES, 12, VermilionCity_EventScript_BadgeGuyMost
	goto_if_ge VAR_NUM_BADGES, 9, VermilionCity_EventScript_BadgeGuySome
	msgbox VermilionCity_Text_BadgeGuy_Trainer, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuySome::
	msgbox VermilionCity_Text_BadgeGuy_SomeBadges, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyMost::
	msgbox VermilionCity_Text_BadgeGuy_MostBadges, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyAll::
	msgbox VermilionCity_Text_BadgeGuy_AllBadges, MSGBOX_DEFAULT
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_VERMILION_HP_UP
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyAfter::
	msgbox VermilionCity_Text_BadgeGuy_BattleEdge, MSGBOX_DEFAULT
	closemessage
	release
	end


VermilionCity_Movement_Suicune1:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

VermilionCity_Movement_PlayerWalkToRailTop:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	step_end
VermilionCity_Movement_PlayerWalkToRailMid:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	step_end
VermilionCity_Movement_PlayerWalkToRailBot:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

VermilionCity_Movement_EusineWalkToRail:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

VermilionCity_Movement_SuicuneLeave:
	jump_in_place_left
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

VermilionCity_Movement_EusineLeave:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

VermilionCity_Text_Eusine:
	.string "米那君：只差一点点了！\n我本以为在这里埋伏，\l就能把它逼进死角。\p可是在水上奔跑，\n我可实在办不到。\p不过，我渐渐看出\n它的规律了。\p水君喜欢水！\p也就是说……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

VermilionCity_Text_Eusine2:
	.string "抱歉，{PLAYER}！我先走了！$"

VermilionCity_Text_Teacher:
	.string "枯叶港是关都的\n海上大门。\p世界各地的豪华客船\n都在这里靠岸。$"
	.string ""
	.string ""
	.string ""

VermilionCity_Text_MachopOwner:
	.string "我的宝可梦正在平整土地，\n准备施工。\p可我拿不出开工的\n钱……$"
	.string ""
	.string ""
	.string ""

VermilionCity_Text_Machop1:
	.string "腕力：咕哦，咕噜噜！$"

VermilionCity_Text_Machop2:
	.string "一只腕力一边低吼，\n一边把地面踩平。$"
	.string ""

VermilionCity_Text_SuperNerd:
	.string "关都有八家道馆。\p那栋大楼就是枯叶市的\n宝可梦道馆。$"
	.string ""
	.string ""

VermilionCity_Text_SnorlaxSleeping:
	.string "卡比兽睡得很香……$"

VermilionCity_Text_RadioNearSnorlax:
	.string "收音机放到了睡着的\n卡比兽旁边……\p……\p卡比兽醒了！$"
	.string ""
	.string ""
	.string ""

VermilionCity_Text_BadgeGuy_Trainer:
	.string "关都聚集着厉害的训练家。\p道馆馆主尤其强。\p他们可没那么容易打赢。$"
	.string ""
	.string ""

VermilionCity_Text_BadgeGuy_SomeBadges:
	.string "你开始收集关都的\n道馆徽章了？\p你不觉得这里的训练家\n都很强吗？$"
	.string ""
	.string ""
	.string ""

VermilionCity_Text_BadgeGuy_MostBadges:
	.string "我看你很快就能\n称霸关都的道馆了。\p集齐八枚徽章以后，\n记得来告诉我。$"
	.string ""
	.string ""
	.string ""

VermilionCity_Text_BadgeGuy_AllBadges:
	.string "恭喜！\p你集齐了关都的所有道馆徽章。\p我要送你一份努力的奖励。$"
	.string ""
	.string ""

VermilionCity_Text_BadgeGuy_BattleEdge:
	.string "多准备几种属性的宝可梦，\n对战时才占优势。\p关都的道馆徽章\n一定会帮上你的忙。$"
	.string ""
	.string ""
	.string ""

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_Sign, MSGBOX_SIGN
	end
VermilionCity_EventScript_GymSign::
	msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
	end
VermilionCity_EventScript_FanClubSign::
	msgbox VermilionCity_Text_FanClubSign, MSGBOX_SIGN
	end
VermilionCity_EventScript_DiglettsCaveSign::
	msgbox VermilionCity_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

VermilionCity_Text_Sign:
	.string "枯叶市\p夕阳绝美的港口$"
	.string ""

VermilionCity_Text_GymSign:
	.string "枯叶市\n宝可梦道馆\p馆主：马志士\p闪电美国人！$"
	.string ""
	.string ""
	.string ""

VermilionCity_Text_FanClubSign:
	.string "宝可梦发烧友俱乐部\p欢迎所有宝可梦发烧友！$"
	.string ""

VermilionCity_Text_DiglettsCaveSign:
	.string "地鼠洞穴$"

VermilionCity_Text_PortSign:
	.string "枯叶港入口$"
	.string ""
