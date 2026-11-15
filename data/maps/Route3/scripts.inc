Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "啊！天气还是这么好。$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "明明是大晴天，我却浑身是水……$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "一下雨，就很难\n点着火……$"
	.string ""

Route3_Text_YoungsterWarren_Seen:
	.string "嗯……我该怎么办呢……$"

Route3_Text_YoungsterWarren_Beaten:
	.string "果然还是输了……$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "你看起来很强。\p我都不敢跟你打了……$"
	.string ""

Route3_Text_YoungsterJimmy_Seen:
	.string "我跑起来像风一样快！$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "被吹飞了！$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "我一年到头都穿短裤。\p这就是我的穿衣之道。$"
	.string ""

Route3_Text_FirebreatherBurt_Seen:
	.string "快来看一看！$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "哎哟！好烫！$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "关都第一的喷火人，\n就是我。\p不过，最强训练家\n可轮不到我……$"
	.string ""
	.string ""

Route3_Text_MtMoonSquareSign:
	.string "月见山广场\p沿楼梯上去就是。$"
	.string ""

