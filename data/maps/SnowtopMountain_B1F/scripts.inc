SnowtopMountain_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SnowtopMountain_B1F_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SnowtopMountain_B1F_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_SNOWTOP_REGICE_DOOR, SnowtopMountain_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SnowtopMountain_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 5, 36, 0x414, FALSE
	setmetatile 5, 35, 0x40C, FALSE
	return



Snowtopmountain_BrailleRegice:
	.string "戟刃凝冰指苍穹，\n"
	.string "脊上长锋映雪峰。\l"
	.string "龙已进化至终形。$"

B1F_Snowtopmountain_Bearnese::
	trainerbattle_single TRAINER_BEARNESE, B1F_Snowtopmountain_Bearnese_Text_0, B1F_Snowtopmountain_Bearnese_Text_1
	msgbox B1F_Snowtopmountain_Bearnese_Text_2, MSGBOX_AUTOCLOSE
	return


B1F_Snowtopmountain_Susdoor::
	lock
	msgbox B1F_Snowtopmountain_Susdoor_Text_0
	closemessage
	msgbox Snowtopmountain_BrailleRegice, MSGBOX_DEFAULT
	closemessage
	checkspecies SPECIES_BAXCALIBUR
	compare VAR_RESULT, TRUE
	goto_if_eq B1F_Snowtopmountain_Susdoor_2
B1F_Snowtopmountain_Susdoor_1:
	release
	end

B1F_Snowtopmountain_Susdoor_2:
	setflag FLAG_SNOWTOP_REGICE_DOOR
	setmetatile 5, 36, 0x414, FALSE
	setmetatile 5, 35, 0x40C, FALSE
	playse SE_EXIT
	special DrawWholeMapView
	goto B1F_Snowtopmountain_Susdoor_1


B1F_Snowtopmountain_Bearnese_Text_0:
	.string "快看，我呼出的气都\n结成冰柱了！$"

B1F_Snowtopmountain_Bearnese_Text_1:
	.string "感觉有点冷啊。$"

B1F_Snowtopmountain_Bearnese_Text_2:
	.string "听说古代冰属性宝可梦\n就沉睡在这座山里的\l某处。到底在哪儿呢？$"

B1F_Snowtopmountain_Susdoor_Text_0:
	.string "墙上刻着什么……$"
