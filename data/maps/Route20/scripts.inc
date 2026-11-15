Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	msgbox Route20_Text_Headlocker, MSGBOX_NPC
	end

Route20_Text_Headlocker:
	.string "这条水路有一种\n稀有的宝可梦。\p而且它有时还会带着\n稀有的进化道具。\p那可是稀上加稀！\p为了完成宝可梦图鉴，\n我在这儿钓了好几个小时！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route20_Text_Seel:
	.string "小海狮：呜啾呜啾！$"

Route20_Text_Dewgong:
	.string "白海狮：咕嗷——！$"

Route20_Text_SeafoamSign:
	.string "双子岛$"

Route20_Text_SwimmerfNicoleSeen:
	.string "一到水里，\n我就觉得身体轻多了。$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "哎呀，糟了！$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "游泳能活动全身。\p对身体真的很好。$"
	.string ""

Route20_Text_SwimmerfLoriSeen:
	.string "你的道馆徽章收集得\n真多啊。我们来对战吧！$"
	.string ""

Route20_Text_SwimmerfLoriBeaten:
	.string "No!$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "在水里能用的秘传招式，\n可不只有冲浪了。$"
	.string ""

Route20_Text_SwimmermCameronSeen:
	.string "我看光靠游泳\n是游不到城都地区的。$"
	.string ""

Route20_Text_SwimmermCameronBeaten:
	.string "哎哟！$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "除了大海，池子、河流里\n我也都能游。$"
	.string ""

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "这块牌子上写着\n什么？\p红莲道馆馆主：夏伯$"
	.string ""

