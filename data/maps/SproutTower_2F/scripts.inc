SproutTower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_Text_SageNico_Seen:
	.string "不管我们怎么对战，\n这塔都巍然不动。$"
	.string ""

SproutTower_Text_SageNico_Beaten:
	.string "我拼尽全力，\n还是太弱了。$"

SproutTower_Text_SageNico_AfterBattle:
	.string "那根柔软的柱子守护着塔，\n连地震也不怕。$"
	.string ""

SproutTower_Text_SageEdmond_Seen:
	.string "……我就像风中的\n树叶一样摇曳……$"

SproutTower_Text_SageEdmond_Beaten:
	.string "唉，我太弱了！$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "我想学喇叭芽\n那轻柔的动作来对战……\p可我修行得还不够。$"
	.string ""
	.string ""

SproutTower_Text_2F_Statue:
	.string "一座宝可梦雕像……\p看起来非常庄严肃穆。$"
	.string ""
