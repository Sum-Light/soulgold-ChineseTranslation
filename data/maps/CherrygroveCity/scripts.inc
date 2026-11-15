

CherrygroveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherrygroveCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_LOAD, CherrygroveCity_OnLoad
	.byte 0

CherrygroveCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

CherrygroveCity_OnLoad::
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	end

CherryGroveCity_EventScript_TriggerGent_Top::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Top
	waitmovement 0 
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0 
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Mid::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Bottom::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0 
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Bottom
	waitmovement 0 
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Cancel::
	msgbox CherrygroveCity_Text_GuideGentDecline, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CHERRYGROVE_CITY_STATE, 1 @ CHANGE THIS TO 1 LATER
	release
	end

CherryGroveCity_EventScript_GentTour::
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokecenter
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokecenter
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentPokecenter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokemart
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokemart
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentMart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Route30
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Route30
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentRoute30, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Sea
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Sea
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_House_Gent
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_House_Player
	waitmovement 0
	waitmovement 0
	delay 20
	msgbox CherrygroveCity_Text_GuideGentMap, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Gent_Leave
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 20
	opendoor 42, 14
	waitdooranim
	waitmovement 0
	removeobject LOCALID_GUIDE_GENT
	closedoor 42, 14
	waitdooranim
	
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	setvar VAR_CHERRYGROVE_CITY_STATE, 1
	fadedefaultbgm
	release
	end

CherryGroveCity_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MYSTICWATER, CherryGroveCity_EventScript_Fisherman2
	msgbox CherrygroveCity_Text_MysticWaterGuyBefore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_Fisherman2
	giveitem ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull 
	closemessage
	setflag FLAG_GOT_MYSTICWATER
	release
	end

CherryGroveCity_EventScript_Fisherman2::
	msgbox CherrygroveCity_Text_MysticWaterGuyAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Lass::
	lock
	faceplayer
	msgbox CherrygroveCity_Text_TeacherHaveMapCard, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, CherryGroveCity_EventScript_Boy2
	msgbox CherrygroveCity_Text_YoungsterNoPokedex, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Boy2::
	msgbox CherrygroveCity_Text_YoungsterHavePokedex, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Staryu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARYU, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Staryu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Corsola::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CORSOLA, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Corsola, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Krabby::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Krabby, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Sign::
	lock
	msgbox CherrygroveCity_Text_CitySign, MSGBOX_SIGN
	closemessage
	release
	end	

CherryGroveCity_EventScript_TriggerSilver_Top::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Top
	waitmovement 0
	goto CherryGroveCity_EventScript_TriggerSilver
	end

CherryGroveCity_EventScript_TriggerSilver_Bottom::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Bottom
	waitmovement 0
	goto CherryGroveCity_EventScript_TriggerSilver
	end

CherryGroveCity_EventScript_TriggerSilver::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Enter
	waitmovement 0
	createfieldmugshot MUGSHOT_SILVER
	msgbox CherrygroveCity_Text_RivalSeen, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_STARTER_MON, 0, CherryGroveCity_Silver_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, CherryGroveCity_Silver_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, CherryGroveCity_Silver_Battle_Chikorita
	release
	end

CherryGroveCity_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_1, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_1, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_1, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_AfterBattle::
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	createfieldmugshot MUGSHOT_SILVER
	msgbox CherrygroveCity_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Silver_Leave1Player
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave1
	waitmovement 0
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CHERRYGROVE_SILVER, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_EAST
	delay 60
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_SOUTH
	delay 30
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Return
	waitmovement 0
	createfieldmugshot MUGSHOT_SILVER
	msgbox CherrygroveCity_Text_RivalID, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave2
	waitmovement 0
	removeobject LOCALID_CHERRYGROVE_SILVER
	setflag FLAG_HIDE_SILVER_CHERRYGROVE
	setvar VAR_CHERRYGROVE_CITY_STATE, 4
	fadedefaultbgm
	release
	end

CherrygroveCity_Text_GuideGentIntro:
	.string "你是新手训练家吧？\n我看得出来！\p没关系！谁都有过\n当新手的时候！\p愿意的话，我可以\n教你几样东西。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CherrygroveCity_Text_GuideGentTourStart:
	.string "好嘞！\n跟我来吧！$"
	.string ""

CherrygroveCity_Text_GuideGentPokecenter:
	.string "这里是宝可梦中心。\p他们一下子就能\n治好你的宝可梦。\p你以后会经常依赖它，\n最好先了解清楚。$"
	.string ""
	.string ""
	.string ""
	.string ""

CherrygroveCity_Text_GuideGentMart:
	.string "这里是友好商店。\p他们出售捕捉野生宝可梦的\n精灵球和其他实用道具。$"
	.string ""
	.string ""

CherrygroveCity_Text_GuideGentRoute30:
	.string "30号道路在这边。\p训练家们会在那里\n派出心爱的宝可梦对战。$"
	.string ""
	.string ""

CherrygroveCity_Text_GuideGentSea:
	.string "如你所见，这里是大海。\p有些宝可梦只生活在\n水里。$"
	.string ""
	.string ""

CherrygroveCity_Text_GuideGentMap:
	.string "给……\p这是我家！谢谢你\n陪我走这一趟。\p对了，要是迷路了，就看看\n宝可梦装置上的地图！\p祝你旅途顺利！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CherrygroveCity_Text_GuideGentDecline:
	.string "哦……我还挺喜欢\n给人带路的……\p好吧。想找我的时候\n随时来。$"
	.string ""
	.string ""
	.string ""

CherrygroveCity_Text_RivalSeen:
	.string "………………\p你已经在研究所得到\n宝可梦了吧。\p真是浪费。\n像你这种窝囊废。\p………………\p你听不懂我在说什么吗？\n哼，我也有只好宝可梦。\p我就让你见识见识！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CherrygroveCity_Text_SilverWin:
	.string "哼。赢了就这么高兴？$"

CherrygroveCity_Text_RivalAfter:
	.string "………………\p想知道我是谁吗？\p我将成为全世界\n最厉害的宝可梦训练家。$"
	.string ""
	.string ""
	.string ""

CherrygroveCity_Text_RivalID:
	.string "还给我！\n那是我的训练家卡！\p糟了！\n你看到我的名字了……$"
	.string ""
	.string ""
	.string ""

CherrygroveCity_Text_TeacherHaveMapCard:
	.string "和宝可梦在一起，\n去哪里都开心。$"
	.string ""

CherrygroveCity_Text_YoungsterNoPokedex:
	.string "宝可梦爷爷的家\n还在前面更远处。$"
	.string ""

CherrygroveCity_Text_YoungsterHavePokedex:
	.string "我在路上和训练家们\n打过架。\p我的宝可梦输了，伤得\n一塌糊涂！得带它们去\l宝可梦中心。$"
	.string ""
	.string ""
	.string ""
	.string ""

CherrygroveCity_Text_MysticWaterGuyBefore:
	.string "我抓到的宝可梦身上\n带着道具。\p好像是神秘水滴。\p我用不着，你\n要吗？$"
	.string ""
	.string ""
	.string ""
	.string ""

CherrygroveCity_Text_MysticWaterGuyAfter:
	.string "那我继续去钓鱼吧。$"

CherrygroveCity_Text_CitySign:
	.string "吉花市\p可爱而芬芳的\n花之城镇$"
	.string ""
	.string ""

CherrygroveCity_Text_GuideGentsHouseSign:
	.string "带路爷爷的家$"

CherryGroveCity_Text_Staryu:
	.string "海星星：呜——呜呜呜！$"

CherryGroveCity_Text_Corsola:
	.string "太阳珊瑚：太阳珊瑚！啦！$"

CherryGroveCity_Text_Krabby:
	.string "大钳蟹：库——可可可！$"

CherryGroveCity_Movement_Trigger_Gent:
	walk_down
	walk_left
	walk_down
	face_left
	step_end

CherryGroveCity_Movement_Trigger_Top:
	walk_down
	face_up
	step_end

CherryGroveCity_Movement_Trigger_Bottom:
	walk_up
	face_up
	step_end

CherryGroveCity_Movement_Pokecenter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

CherryGroveCity_Movement_Pokemart:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

CherryGroveCity_Movement_Route30:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

CherryGroveCity_Movement_Sea:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

CherryGroveCity_Movement_House_Gent:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
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
	face_up
	step_end

CherryGroveCity_Movement_House_Player:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
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
	face_up
	step_end

CherryGroveCity_Movement_Gent_Leave:
	walk_up
	step_end

CherryGroveCity_Movement_Trigger_Silver_Top:
	walk_down
	face_right
	step_end

CherryGroveCity_Movement_Trigger_Silver_Bottom:
	walk_up
	face_right
	step_end

CherryGroveCity_Movement_Silver_Enter:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherryGroveCity_Movement_Silver_Leave1:
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherryGroveCity_Movement_Silver_Leave1Player:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

CherryGroveCity_Movement_Silver_Return:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end


CherryGroveCity_Movement_Silver_Leave2:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Cherrygrove_FadedSign::
	msgbox Cherrygrove_FadedSign_Text_0, MSGBOX_SIGN
	return


Cherrygrove_DarkraiEventDoor::
	lock
	getcaughtmon SPECIES_DARKRAI
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 4
	goto_if_eq Cherrygrove_DarkraiEventDoor_2
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 5
	goto_if_ge Cherrygrove_DarkraiEventDoor_7
Cherrygrove_DarkraiEventDoor_3:
	msgbox Cherrygrove_DarkraiEventDoor_Text_7
	release
	end

Cherrygrove_DarkraiEventDoor_2:
	msgbox Cherrygrove_DarkraiEventDoor_Text_0
	checkspecies SPECIES_CRESSELIA
	compare VAR_RESULT, FALSE
	goto_if_eq Cherrygrove_DarkraiEventDoor_12
	msgbox Cherrygrove_DarkraiEventDoor_Text_2
	dynmultichoice 20, 8, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Cherrygrove_DarkraiEventDoor_Text_3, Cherrygrove_DarkraiEventDoor_Text_4
	compare VAR_RESULT, 1
	goto_if_eq Cherrygrove_DarkraiEventDoor_14
	msgbox Cherrygrove_DarkraiEventDoor_Text_6
	release
	end

Cherrygrove_DarkraiEventDoor_6:
	compare VAR_RESULT, FALSE
	goto_if_eq Cherrygrove_DarkraiEventDoor_2
	goto Cherrygrove_DarkraiEventDoor_3

Cherrygrove_DarkraiEventDoor_7:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 10
	goto_if_le Cherrygrove_DarkraiEventDoor_6
	goto Cherrygrove_DarkraiEventDoor_3

Cherrygrove_DarkraiEventDoor_12:
	msgbox Cherrygrove_DarkraiEventDoor_Text_1
	release
	end

Cherrygrove_DarkraiEventDoor_14:
	msgbox Cherrygrove_DarkraiEventDoor_Text_5
	closemessage
	compare VAR_DARKRAI_INN_PROGRESS, 2
	goto_if_ge Cherrygrove_DarkraiEventDoor_18
	warpwhitefade MAP_DARKRAI_INN1, 1
Cherrygrove_DarkraiEventDoor_17:
	waitstate
	end

Cherrygrove_DarkraiEventDoor_18:
	warpwhitefade MAP_DARKRAI_INN1RUINED, 28, 18
	goto Cherrygrove_DarkraiEventDoor_17


Cherrygrove_Littlegirl::
	lock
	faceplayer
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 5
	goto_if_eq Cherrygrove_Littlegirl_2
	msgbox Cherrygrove_Littlegirl_Text_1
	release
	end

Cherrygrove_Littlegirl_2:
	msgbox Cherrygrove_Littlegirl_Text_0
	release
	end


Cherrygrove_Zigzagoon::
	lock
	faceplayer
	playmoncry SPECIES_ZIGZAGOON_GALAR, CRY_MODE_NORMAL
	msgbox Cherrygrove_Zigzagoon_Text_0
	release
	end


Cherrygrove_Rattata::
	lock
	faceplayer
	playmoncry SPECIES_RATTATA_ALOLA, CRY_MODE_NORMAL
	msgbox Cherrygrove_Rattata_Text_0
	release
	end


Cherrygrove_FriendlyTrader::
	lock
	faceplayer
	goto_if_set FLAG_PICKED_ZIGZAGOON, Cherrygrove_FriendlyTrader_2
	goto_if_set FLAG_PICKED_RATTATA, Cherrygrove_FriendlyTrader_2
	goto_if_set FLAG_RECEIVED_FIRST_BALLS, Cherrygrove_FriendlyTrader_7
	msgbox Cherrygrove_FriendlyTrader_Text_7
	release
	end

Cherrygrove_FriendlyTrader_2:
	msgbox Cherrygrove_FriendlyTrader_Text_0
	release
	end

	release
	end

Cherrygrove_FriendlyTrader_7:
	msgbox Cherrygrove_FriendlyTrader_Text_1
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Cherrygrove_FriendlyTrader_Text_2, Cherrygrove_FriendlyTrader_Text_3, Cherrygrove_FriendlyTrader_Text_4
	switch VAR_RESULT
	case 0, Cherrygrove_FriendlyTrader_11
	case 1, Cherrygrove_FriendlyTrader_12
	msgbox Cherrygrove_FriendlyTrader_Text_6
	release
	end

Cherrygrove_FriendlyTrader_11:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZIGZAGOON_GALAR
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON_GALAR
	givemon SPECIES_ZIGZAGOON_GALAR, 5
	showgivemonpic 10, 3
	removeobject LOCALID_CHERRY_ZIGZAGOON
	call Common_EventScript_GiftMon
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON_GALAR
	msgbox Cherrygrove_FriendlyTrader_Text_5
	release
	end

Cherrygrove_FriendlyTrader_12:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RATTATA_ALOLA
	bufferspeciesname STR_VAR_1, SPECIES_RATTATA_ALOLA
	givemon SPECIES_RATTATA_ALOLA, 5
	showgivemonpic 10, 3
	removeobject LOCALID_CHERRY_RATTATA
	call Common_EventScript_GiftMon
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_RATTATA_ALOLA
	msgbox Cherrygrove_FriendlyTrader_Text_5
	release
	end


Cherrygrove_FadedSign_Text_0:
	.string "吉花旅店……\n字迹褪色，看不清了。$"

Cherrygrove_DarkraiEventDoor_Text_0:
	.string "达克莱伊也许就住在这家\n老旧的旅店里。\p最好做足准备，\n以应对任何情况。$"

Cherrygrove_DarkraiEventDoor_Text_1:
	.string "最好也带上\n克雷色利亚。$"

Cherrygrove_DarkraiEventDoor_Text_2:
	.string "你真的准备好了吗？$"

Cherrygrove_DarkraiEventDoor_Text_3:
	.string "先做准备$"

Cherrygrove_DarkraiEventDoor_Text_4:
	.string "进去$"

Cherrygrove_DarkraiEventDoor_Text_5:
	.string "你握住门把手——$"

Cherrygrove_DarkraiEventDoor_Text_6:
	.string "还是先做好准备吧。$"

Cherrygrove_DarkraiEventDoor_Text_7:
	.string "门纹丝不动。好像\n卡住了。$"

Cherrygrove_Littlegirl_Text_0:
	.string "我看到你在那家老旅店\n门口打瞌睡。你没事吧？$"

Cherrygrove_Littlegirl_Text_1:
	.string "那家旅店……我觉得它\n从来没开过门。我妈说，\l她小时候它就是废弃的。$"

Cherrygrove_Zigzagoon_Text_0:
	.string "兹！$"

Cherrygrove_Rattata_Text_0:
	.string "吱！$"

Cherrygrove_FriendlyTrader_Text_0:
	.string "你好！我的宝可梦有帮上忙吗？$"

Cherrygrove_FriendlyTrader_Text_1:
	.string "你好！请问你是新手训练家吗？\p是这样，我叔叔从狩猎地带\n送了我两只稀有的宝可梦，\l可我养不了两只。\p你愿意带走其中一只吗？\p我敢说，无论哪一只都会\n乐意跟你一起去冒险的！$"

Cherrygrove_FriendlyTrader_Text_2:
	.string "蛇纹熊$"

Cherrygrove_FriendlyTrader_Text_3:
	.string "小拉达$"

Cherrygrove_FriendlyTrader_Text_4:
	.string "不用了$"

Cherrygrove_FriendlyTrader_Text_5:
	.string "要好好照顾我的{STR_VAR_1}啊！\p要是去狩猎地带，替我向\n我叔叔巴奥巴问好！$"

Cherrygrove_FriendlyTrader_Text_6:
	.string "哦……那真可惜……$"

Cherrygrove_FriendlyTrader_Text_7:
	.string "喂！能请你帮个忙吗？\p等等……你身上没有\n精灵球啊……\p抱歉，\n我还以为你是训练家。$"
