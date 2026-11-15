.set LOCALID_ROUTE10_SURGE, 8
.set LOCALID_ROUTE10_ZAPDOS, 2

Route10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route10_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route10_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route10_OnLoad::
	goto_if_set FLAG_VISITED_ROUTE10, Route10_OnLoad2
	end

Route10_OnLoad2::
	setrespawn HEAL_LOCATION_ROUTE10
	end

Route10_Trigger::
	setflag FLAG_VISITED_ROUTE10
	end

Route10_EventScript_Surge::
    lock
    faceplayer
    msgbox Route10_Text_Surge, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_PLANT_SURGE
    removeobject LOCALID_ROUTE10_SURGE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_SURGE
    release
    end

Route10_Text_Surge:
    .string "嘿，小家伙！\p在这地方可得打起精神，\n这里可是电力十足！\p想再打一场的话，就到\n格斗道场来报到！$"
	.string ""
	.string ""
	.string ""
	.string ""

Route10_EventScript_Jim::
	trainerbattle_single TRAINER_JIM Route10_Text_HikerJimSeen, Route10_Text_HikerJimBeaten
	msgbox Route10_Text_HikerJimAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Robert::
	trainerbattle_single TRAINER_ROBERT Route10_Text_PokefanmRobertSeen, Route10_Text_PokefanmRobertBeaten
	msgbox Route10_Text_PokefanmRobertAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Sign::
	msgbox Route10_Text_Sign, MSGBOX_SIGN
	end

Route10_EventScript_PPSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_EventScript_Zapdos::
	lock
	faceplayer
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
	delay 40
	waitmoncry
	seteventmon SPECIES_ZAPDOS, 50
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route10_EventScript_ZapdosRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE10_ZAPDOS
	setflag FLAG_HIDE_ZAPDOS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Route10_EventScript_ZapdosRan::
	release
	end


Route10_Text_HikerJimSeen:
	.string "哈哈哈！$"

Route10_Text_HikerJimBeaten:
	.string "哈哈哈——啊嚏！$"

Route10_Text_HikerJimAfter:
	.string "花粉症害得我直打喷嚏！\n啊哈哈——嚏！$"
	.string ""

Route10_Text_PokefanmRobertSeen:
	.string "你喜欢宝可梦，对吧？\p我也是！$"
	.string ""

Route10_Text_PokefanmRobertBeaten:
	.string "只能说我输了。$"

Route10_Text_PokefanmRobertAfter:
	.string "看看你把我的宝可梦\n打成什么样了……\p我不会忘记这件事的……$"
	.string ""

Route10_Text_PowerPlant:
	.string "无人发电厂$"

Route10_Text_Sign:
	.string "10号道路\p华蓝市——紫苑镇$"
	.string ""
