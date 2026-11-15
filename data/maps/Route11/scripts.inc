Route11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end


Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_Text_Engineer:
	.string "我看见一只奇怪的宝可梦\n在树上爬，可它\l不像猴怪……$"
	.string ""
	.string ""

Route11_Text_YoungsterOwenSeen:
	.string "宝可梦对战里没有作弊。\p让我们堂堂正正地打！$"
	.string ""

Route11_Text_YoungsterOwenBeaten:
	.string "咦？\n怎么会这样？$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "我是带着荣誉\n堂堂正正战斗的。\p我一点都不后悔。$"
	.string ""
	.string ""

Route11_Text_YoungsterJasonSeen:
	.string "穿着短裤走进草丛，\n腿有点痒痒的。$"
	.string ""

Route11_Text_YoungsterJasonBeaten:
	.string "哎呀啊啊！\n我被打得落花流水！$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "我要在草丛里\n多抓些宝可梦。$"
	.string ""

Route11_Text_PsychicHermanSeen:
	.string "…$"

Route11_Text_PsychicHermanBeaten:
	.string "…$"

Route11_Text_PsychicHermanAfterBattle:
	.string "……\p我闭着眼睛就输了……$"
	.string ""

Route11_Text_PsychicFidelSeen:
	.string "我看得见……\p关于你的一切……$"
	.string ""

Route11_Text_PsychicFidelBeaten:
	.string "我没能预知到\n你的强大……$"

Route11_Text_PsychicFidelAfterBattle:
	.string "信念的力量……\p你很强，因为你相信\n自己的宝可梦。$"
	.string ""
	.string ""

Route11_Text_Sign:
	.string "11号道路$"

