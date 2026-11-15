Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route18_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route18_EventScript_Boris::
	trainerbattle_single TRAINER_BORIS Route18_Text_BirdKeeperBorisSeen, Route18_Text_BirdKeeperBorisBeaten
	msgbox Route18_Text_BirdKeeperBorisAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Bob::
	trainerbattle_single TRAINER_BOB Route18_Text_BirdKeeperBobSeen, Route18_Text_BirdKeeperBobBeaten
	msgbox Route18_Text_BirdKeeperBobAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Sign::
	msgbox Route18_Text_Sign, MSGBOX_SIGN
	end

Route18_Text_BirdKeeperBorisSeen:
	.string "要找宝可梦，\n就得往高草里找。$"
	.string ""

Route18_Text_BirdKeeperBorisBeaten:
	.string "呀啊啊！$"

Route18_Text_BirdKeeperBorisAfterBattle:
	.string "你这么强，\n和你对战一定很有趣。$"
	.string ""

Route18_Text_BirdKeeperBobSeen:
	.string "自行车道是去玉虹市的\n近路。$"
	.string ""

Route18_Text_BirdKeeperBobBeaten:
	.string "……呼！$"

Route18_Text_BirdKeeperBobAfterBattle:
	.string "要是没有自行车，\n就不能走这条近路。$"
	.string ""
	.string ""

Route18_Text_Sign:
	.string "18号道路\p玉虹市——浅红市$"
	.string ""
