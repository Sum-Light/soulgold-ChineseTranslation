Route21_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route21_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route21_EventScript_Seth::
	trainerbattle_single TRAINER_SETH Route21_Text_SwimmermSethSeen, Route21_Text_SwimmermSethBeaten
	msgbox Route21_Text_SwimmermSethAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI Route21_Text_SwimmerfNikkiSeen, Route21_Text_SwimmerfNikkiBeaten
	msgbox Route21_Text_SwimmerfNikkiAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Arnold::
	trainerbattle_single TRAINER_ARNOLD Route21_Text_FisherArnoldSeen, Route21_Text_FisherArnoldBeaten
	msgbox Route21_Text_FisherArnoldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_Text_SwimmermSethSeen:
	.string "看到陆地了！\n还得接着游！$"

Route21_Text_SwimmermSethBeaten:
	.string "咕噜……$"

Route21_Text_SwimmermSethAfterBattle:
	.string "在红莲镇的火山那边，\n有个很傲慢的家伙。$"
	.string ""

Route21_Text_SwimmerfNikkiSeen:
	.string "我要是赢了，\n你就得帮我涂防晒霜！$"
	.string ""

Route21_Text_SwimmerfNikkiBeaten:
	.string "我好担心被晒伤……$"

Route21_Text_SwimmerfNikkiAfterBattle:
	.string "我得当心\n被太阳晒出斑来。$"
	.string ""

Route21_Text_FisherArnoldSeen:
	.string "钓鱼我都钓腻了。\n来对战吧！$"

Route21_Text_FisherArnoldBeaten:
	.string "惨败……$"

Route21_Text_FisherArnoldAfterBattle:
	.string "我还是回去钓鱼吧……$"

