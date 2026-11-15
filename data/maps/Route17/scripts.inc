Route17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_BikerRileySeen:
	.string "喂，你！\n是从城都来的吧？$"

Route17_Text_BikerRileyBeaten:
	.string "哇，你真有本事！$"

Route17_Text_BikerRileyAfterBattle:
	.string "别得意，\n城都来的小鬼！$"

Route17_Text_BikerJoelSeen:
	.string "哇。\n你这自行车真帅！$"

Route17_Text_BikerJoelBeaten:
	.string "可你不只是看着帅……$"

Route17_Text_BikerJoelAfterBattle:
	.string "我虽然看着帅，可是很弱，\n所以其实一点也不帅。\p我得再好好锻炼。$"
	.string ""
	.string ""

Route17_Text_BikerGlennSeen:
	.string "喂！\n想来场速度对决吗？$"

Route17_Text_BikerGlennBeaten:
	.string "哇！你的脚力\n真够劲！$"

Route17_Text_BikerGlennAfterBattle:
	.string "在自行车道上\n撒把骑车才叫酷。$"
	.string ""

Route17_Text_BikerCharlesSeen:
	.string "我们是不怕死的\n公路之星！$"

Route17_Text_BikerCharlesBeaten:
	.string "呃啊啊！\n彻底完蛋了！$"

Route17_Text_BikerCharlesAfterBattle:
	.string "乱骑车会出事故的！\n悠着点！$"
	.string ""

