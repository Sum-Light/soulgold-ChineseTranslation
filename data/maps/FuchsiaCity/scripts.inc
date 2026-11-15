FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, FuchsiaCity_OnLoad
	.byte 0

FuchsiaCity_OnFrame::
	map_script_2 VAR_FUCHSIA_CITY_STATE, 0,  FuchsiaCity_EventScript_BaobaCall
	.2byte 0

FuchsiaCity_EventScript_CityEnter::
	end

FuchsiaCity_OnLoad::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	end

FuchsiaCity_Text_Baoba:
	.string "园长巴奥巴：{PLAYER}！\p我是园长巴奥巴。\p出大事了！\n我在浅红市的狩猎地带\l被人买下，重新开业了！\p听说那里还有稀奇的\n新宝可梦！\p这害得我生意都做不下去了！\p{PLAYER}，你去新的狩猎地带\n抓一只宝可梦回来给我看。\l我得弄清楚那些\l“稀奇”的宝可梦。\p求你了，{PLAYER}，我的生意\n就全靠你了！$"
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

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "四天王里有一位，\n曾经是浅红道馆的馆主。$"
	.string ""

FuchsiaCity_Text_PokefanM:
	.string "阿桔成为四天王之后，\n他的女儿就接替他，\l当上了道馆馆主。$"
	.string ""
	.string ""

FuchsiaCity_Text_Teacher:
	.string "狩猎地带换了新的\n经营者。\p而且还有好多\n新宝可梦！$"
	.string ""
	.string ""

FuchsiaCity_Text_Sign:
	.string "浅红市\p看哪！热情的粉红色！$"
	.string ""

FuchsiaCity_Text_GymSign:
	.string "浅红市宝可梦道馆\n馆主：阿杏\p毒之忍者大师$"
	.string ""
	.string ""

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "这里贴着一张告示……\p狩猎地带办事处暂停营业，\n恢复时间另行通知。$"
	.string ""
	.string ""

FuchsiaCity_Text_SafariZone:
	.string "狩猎地带\n现已由得文公司\l接手经营$"
	.string ""
	.string ""

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "园长目前正在国外旅行。\p因此，狩猎地带\n暂停开放。$"
	.string ""
	.string ""

FuchsiaCity_Text_NoLitteringSign:
	.string "请勿乱扔垃圾。\p请把垃圾随身带走。$"
	.string ""

