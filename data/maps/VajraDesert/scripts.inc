VajraDesert_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_SUS_DESERT_DOOR, VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 37, 6, 0x4AE, FALSE
	return


VajraDesert_ManSighing::
	msgbox VajraDesert_ManSighing_Text_0, MSGBOX_NPC
	return


VajraDesert_TrainerJill::
	trainerbattle_single TRAINER_JILL, VajraDesert_TrainerJill_Text_0, VajraDesert_TrainerJill_Text_1
	msgbox VajraDesert_TrainerJill_Text_2, MSGBOX_AUTOCLOSE
	return


VajraDesert_TrainerRodaros::
	trainerbattle_single TRAINER_RODAROS, VajraDesert_TrainerRodaros_Text_0, VajraDesert_TrainerRodaros_Text_1
	msgbox VajraDesert_TrainerRodaros_Text_2, MSGBOX_AUTOCLOSE
	return


VajraDesert_TrainerBelmare::
	trainerbattle_single TRAINER_BELMARE, VajraDesert_TrainerBelmare_Text_0, VajraDesert_TrainerBelmare_Text_1
	msgbox VajraDesert_TrainerBelmare_Text_2, MSGBOX_AUTOCLOSE
	return


VajraDesert_TrainerKennedy::
	trainerbattle_single TRAINER_KENNEDY, VajraDesert_TrainerKennedy_Text_0, VajraDesert_TrainerKennedy_Text_1
	msgbox VajraDesert_TrainerKennedy_Text_2, MSGBOX_AUTOCLOSE
	return



VajraDesert_BrailleRegirock:
	.string "斑驳岩甲披身，\n"
	.string "基岩踏碎成尘。\l"
	.string "拉起漫天沙暴，\l"
	.string "斯为最终之形。$"

VajraDesert_SusDoor::
	lock
	msgbox VajraDesert_SusDoor_Text_0
	closemessage
	msgbox VajraDesert_BrailleRegirock, MSGBOX_DEFAULT
	closemessage
	checkspecies SPECIES_TYRANITAR
	compare VAR_RESULT, TRUE
	goto_if_eq VajraDesert_SusDoor_2
VajraDesert_SusDoor_1:
	release
	end

VajraDesert_SusDoor_2:
	setflag FLAG_SUS_DESERT_DOOR
	setmetatile 37, 6, 0x4AE, FALSE
	playse SE_EXIT
	special DrawWholeMapView
	goto VajraDesert_SusDoor_1


VajraDesertWest_GrottoDoor::
	msgbox VajraDesertWest_GrottoDoor_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VajraDesertWest_GrottoDoor_2
VajraDesertWest_GrottoDoor_1:
	release
	end

VajraDesertWest_GrottoDoor_2:
	warp MAP_HIDDEN_GROTTO_UNUSED, 0
	waitstate
	goto VajraDesertWest_GrottoDoor_1


VajraDesertWest_WestSign::
	msgbox VajraDesertWest_WestSign_Text_0, MSGBOX_SIGN
	return


VajraDesertWest_EastSign::
	msgbox VajraDesertWest_EastSign_Text_0, MSGBOX_SIGN
	return


VajraDesert_ManSighing_Text_0:
	.string "哎呀……这会儿的沙坑实在\n糟得很。去村里的路\l都堵住了。真希望它快点\l平息下来。$"

VajraDesert_TrainerJill_Text_0:
	.string "我在杂志上读到过，在\n严酷的环境里锻炼\l对身体特别好！$"

VajraDesert_TrainerJill_Text_1:
	.string "我想回家……$"

VajraDesert_TrainerJill_Text_2:
	.string "我该听妈妈的话的，\n那本杂志真不靠谱……$"

VajraDesert_TrainerRodaros_Text_0:
	.string "见识一下沙暴的威力吧！$"

VajraDesert_TrainerRodaros_Text_1:
	.string "呸！满嘴都是沙子！$"

VajraDesert_TrainerRodaros_Text_2:
	.string "这一带会随着月相变化，\n流沙坑不断移动，很不安定。$"

VajraDesert_TrainerBelmare_Text_0:
	.string "让你看看我最可爱的宝可梦！$"

VajraDesert_TrainerBelmare_Text_1:
	.string "哎呀……$"

VajraDesert_TrainerBelmare_Text_2:
	.string "我的沙铃仙人掌绝对是\n最可爱的宝可梦。我们来这儿\l晒太阳！$"

VajraDesert_TrainerKennedy_Text_0:
	.string "和宝可梦一起克服严酷的\n考验，这才是旅行的精神！$"

VajraDesert_TrainerKennedy_Text_1:
	.string "对战本领真了不起！$"

VajraDesert_TrainerKennedy_Text_2:
	.string "我在附近的村子住了\n四十年，从没落下过\l一天训练。$"

VajraDesert_SusDoor_Text_0:
	.string "门上刻着什么……$"

VajraDesertWest_GrottoDoor_Text_0:
	.string "沙子里好像有一条\n小路。要进去吗？$"

VajraDesertWest_WestSign_Text_0:
	.string "金刚沙漠\n{RIGHT_ARROW} 林都村$"

VajraDesertWest_EastSign_Text_0:
	.string "{UP_ARROW}{RIGHT_ARROW} 林都村$"
