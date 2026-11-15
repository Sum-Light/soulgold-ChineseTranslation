VajraPyramidOutside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_RINTO_TRADE_COMPLETE, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_HIDE_PYRAMIDOUT_SCIENTIST
	return

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_PYRAMIDOUT_SCIENTIST
	return

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_IS_CHAMPION, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD_2
	return

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 16, 6, 0x4D5, FALSE
	return

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	goto_if_set FLAG_RINTO_TRADE_COMPLETE, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return


VajraPyramidOutside_Door::
	goto_if_set FLAG_IS_CHAMPION, VajraPyramidOutside_Door_3
VajraPyramidOutside_Door_2:
	msgbox VajraPyramidOutside_Door_Text_1, MSGBOX_SIGN
	return

VajraPyramidOutside_Door_1:
	msgbox VajraPyramidOutside_Door_Text_0, MSGBOX_SIGN
	return

VajraPyramidOutside_Door_3:
	goto_if_set FLAG_RINTO_TRADE_COMPLETE, VajraPyramidOutside_Door_1
	goto VajraPyramidOutside_Door_2


VajraPyramidOutside_ScientistPostgame::
	goto_if_set FLAG_IS_CHAMPION, VajraPyramidOutside_ScientistPostgame_1
	msgbox VajraPyramidOutside_ScientistPostgame_Text_1, MSGBOX_NPC
	return

VajraPyramidOutside_ScientistPostgame_1:
	msgbox VajraPyramidOutside_ScientistPostgame_Text_0, MSGBOX_NPC
	return


VajraPyramidOutside_ScientistsTinkaton::
	lock
	faceplayer
	playmoncry SPECIES_TINKATON, 0
	msgbox VajraPyramidOutside_ScientistsTinkaton_Text_0
	waitmoncry
	msgbox VajraPyramidOutside_ScientistsTinkaton_Text_1
	release
	end


VajraPyramidOutside_RuinManiac::
	msgbox VajraPyramidOutside_RuinManiac_Text_0, MSGBOX_NPC
	return


VajraPyramidOutside_Door_Text_0:
	.string "这扇门是被反复猛撞之后\n才被撞开的。$"

VajraPyramidOutside_Door_Text_1:
	.string "门紧紧地封着。$"

VajraPyramidOutside_ScientistPostgame_Text_0:
	.string "多亏你给我们的巨锻匠，\n我们终于把金字塔的门\l弄开了！\p请吧，你可以先去\n里面探索一下！$"

VajraPyramidOutside_ScientistPostgame_Text_1:
	.string "我们已经开始借助你的\n巨锻匠，着手把那扇门\l弄开了！\p这可能需要一些时间，\n你过一阵子再来吧。$"

VajraPyramidOutside_ScientistsTinkaton_Text_0:
	.string "巨锻匠：锻咿！$"

VajraPyramidOutside_ScientistsTinkaton_Text_1:
	.string "你那只巨锻匠好像\n在这里玩得很开心！$"

VajraPyramidOutside_RuinManiac_Text_0:
	.string "这里有等着被揭开的谜团！\n我能感觉到！$"
