PewterCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, PewterCity_OnLoad
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_BATTLE_TOWER
	end

PewterCity_OnLoad::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "你去过深灰道馆了吗？\p那里的馆主使用的是\n岩石属性宝可梦。$"
	.string ""

PewterCity_Text_BugCatcher:
	.string "到了晚上，皮皮会到\n月见山来玩。\p不过也不是每晚都来。$"
	.string ""
	.string ""

PewterCity_Text_Gramps:
	.string "哦，你从城都大老远\n跑到这儿来了？\p真是让人怀念。\n我年轻时也去过城都修行。\p你让我想起了\n自己年轻时的样子。\p来，这个是我在城都找到的\n东西，送给你吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

PewterCity_Text_Gramps_GotSilverWing:
	.string "到陌生的新地方去，\n结识新的人……\p这才是旅行的乐趣。$"
	.string ""
	.string ""

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "深灰市\n石头灰色的城市$"
	.string ""

PewterCity_Text_GymSign:
	.string "深灰市宝可梦道馆\n馆主：小刚\p坚如磐石的宝可梦训练家$"
	.string ""
	.string ""

PewterCity_Text_MuseumSign:
	.string "这里贴着一张告示……\p深灰科学博物馆正在\n翻修，暂停开放……$"
	.string ""
	.string ""

PewterCity_Text_MtMoonGiftShopSign:
	.string "这里贴着一张告示……\p月见山礼品店开业了！$"
	.string ""

PewterCity_Text_WelcomeSign:
	.string "欢迎来到深灰市！$"

