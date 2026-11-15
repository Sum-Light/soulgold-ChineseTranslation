

OlivineCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, OlivineCity_OnLoad
	.byte 0

OlivineCity_OnLoad::
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	end

OlivineCity_MapScript_OnTransition::
	call Common_EventScript_CheckElmRocketCall
	call Common_EventScript_SetupRivalGfxId
	goto OlivineCity_MapScript_CheckWeather

OlivineCity_MapScript_CheckWeather::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_OnFrame::
	map_script_2 VAR_TEMP_F, 1, Mahoganytown_EventScript_RocketTrigger
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
	.2byte 0

OlivineCity_EventScript_BaobaCall::
	lock
	pokenavcall OlivineCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
	release
	end

OlivineCity_Text_Baoba:
	.string "{PLAYER}！\p我是园长巴奥巴。\p抱歉让您久等了。\n我们终于开张了\l狩猎地带！\p您知道它在哪儿吗？\p您知道湛蓝市的洞穴里\n有扇大门吗？\p穿过那里再走一小段，\n就能看到\l狩猎地带了！\p地方虽然有点偏，\n但还请一定来玩！$"
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

OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_VISITED_OLIVINE_CITY
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_GETFLY, 0

	setvar VAR_OLIVINE_CITY_STATE, 1

	@cianwood flags
	setvar VAR_SUICUNE_ENCOUNTERS, 1
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_CIANWOOD_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	delay 20
	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	createfieldmugshot MUGSHOT_SILVER
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_HIDE_MAREANIES
	removeobject LOCALID_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
	.string "又是你？\n不必那么戒备。\p我懒得理会\n像你这样的弱者。\p说起弱者，\n这里的道馆馆主\l也不在。听说\l那位正待在浅葱灯塔\l照顾生病的宝可梦。\p……哼！哭哭啼啼！\n生病的宝可梦，扔掉算了！\p不能战斗的宝可梦\n根本毫无价值！\p你怎么不去灯塔\n修行修行？\p谁知道呢？说不定\n能让你稍微像样点！$"
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

OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_EonTicketWoman::
	lock
	faceplayer
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanChamp::
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanAfter::
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSign:
	.string "浅葱咖啡馆\n强壮的水手也爱吃的\l营养大餐就在这儿$"
	.string ""
	.string ""

OlivineCity_Text_EonTicketWoman1:
	.string "我叫胡桃！\p开玩笑啦，不过我最爱听\n胡桃的播音节目了！$"
	.string ""
	.string ""

OlivineCity_Text_EonTicketWoman2:
	.string "您一定就是{PLAYER}！！！\p天哪！冠军！\p我是从胡桃的播音节目里\n听说您的！\p这个，请您收下！$"
	.string ""
	.string ""
	.string ""
	.string ""

OlivineCity_Text_EonTicketWoman3:
	.string "真不敢相信我竟然见到了\n冠军！！！$"
	.string ""

OlivineCity_Text_Sailor1:
	.string "夜里的道路很危险。\p可是在黑漆漆的夜里，\n大海要更加\l凶险得多！\p要是没有浅葱灯塔的\n灯光指引，\l任何船只都无法航行。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OlivineCity_Text_YoungsterPokegear:
	.string "你身上那个——\n是宝可梦装置吧？\l哇，好酷啊。$"
	.string ""
	.string ""

OlivineCity_Text_YoungsterPokedex:
	.string "哇，你有宝可梦图鉴！\p那真是太棒了。$"
	.string ""

OlivineCity_Text_Sailor2:
	.string "联盟把阿蜜评为\n第六强的\l道馆馆主！\p哈！纯属胡说八道。\p柳伯怎么可能\n伤得了阿蜜的\l钢属性宝可梦！\p要我说，全是官僚作风。\p她确实是个\n让人畏惧的对手！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OlivineCity_Text_Sign:
	.string "浅葱市\p距离异国最近的海港$"
	.string ""

OlivineCity_Text_PortSign:
	.string "浅葱港\n高速船码头$"
	.string ""

OlivineCity_Text_GymSign:
	.string "浅葱市宝可梦道馆\n馆主：阿蜜\p身披钢铁的防御少女$"
	.string ""
	.string ""

OlivineCity_Text_LighthouseSign:
	.string "浅葱灯塔\n也被称为\l光辉灯塔$"
	.string ""
	.string ""

OlivineCity_Text_BattleTowerSign:
	.string "前方是对战塔\n现已开业！$"
	.string ""

OlivineCity_Text_Machoke:
	.string "豪力：吼！$"

OlivineCity_Littlegirl_Warf::
	lock
	faceplayer
	msgbox OlivineCity_Littlegirl_Warf_Text_0
	release
	end


MareanieOlivine::
	lock
	faceplayer
	playmoncry SPECIES_MAREANIE, CRY_MODE_NORMAL
	msgbox MareanieOlivine_Text_0
	waitmoncry
	release
	end


OlivineSouvenirMart::
	lock
	faceplayer
	message OlivineSouvenirMart_Text_0
	waitmessage
	pokemart SouvenirMart
	msgbox OlivineSouvenirMart_Text_1
	release
	end


	.align 2
SouvenirMart:
	.2byte ITEM_STRANGE_SOUVENIR
	.2byte ITEM_UNREMARKABLE_TEACUP
	.2byte ITEM_MASTERPIECE_TEACUP
	.2byte ITEM_UTILITY_UMBRELLA
	.2byte ITEM_RED_NECTAR
	.2byte ITEM_YELLOW_NECTAR
	.2byte ITEM_PINK_NECTAR
	.2byte ITEM_PURPLE_NECTAR
	.2byte ITEM_NONE

OlivineCity_RivalPier::
	lock
	faceplayer
	createfieldmugshotrival
	msgbox OlivineCity_RivalPier_Text_0
	msgbox OlivineCity_RivalPier_Text_1
	msgbox OlivineCity_RivalPier_Text_2
	msgbox OlivineCity_RivalPier_Text_3
	msgbox OlivineCity_RivalPier_Text_4
	msgbox OlivineCity_RivalPier_Text_5
	removefieldmugshot
	closemessage
	moveobjecttocoords LOCALID_OLIVINE_RIVAL, 19, 49, DIR_NORTH
	waitmovement 0
	setvar VAR_RIVAL_STATE, 9
	setflag FLAG_HIDE_OLIVINE_RIVAL
	removeobject LOCALID_OLIVINE_RIVAL
	clearflag FLAG_HIDE_ICEPATH_RIVAL
	release
	end


OlivineCity_Littlegirl_Warf_Text_0:
	.string "我每天都来喂好坏星！\n它们有时候会让我一起玩！$"

MareanieOlivine_Text_0:
	.string "好坏！$"

OlivineSouvenirMart_Text_0:
	.string "欢迎光临！您需要点什么？$"

OlivineSouvenirMart_Text_1:
	.string "欢迎您再来！$"

OlivineCity_RivalPier_Text_0:
	.string "哦。\n嘿……$"

OlivineCity_RivalPier_Text_1:
	.string "你有没有想过，有些人\n天生就不适合这种事？$"

OlivineCity_RivalPier_Text_2:
	.string "就好像有些人天生就会，\n而有些人却怎样都……$"

OlivineCity_RivalPier_Text_3:
	.string "算了。\n我问了个蠢问题。$"

OlivineCity_RivalPier_Text_4:
	.string "阿蜜的道馆关门了。\n你已经在办了吧，我想。$"

OlivineCity_RivalPier_Text_5:
	.string "回头见。$"
