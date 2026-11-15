RailwayCave_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_SUS_RAILWAY_DOOR, RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 73, 10, 0x45A, FALSE
	setmetatile 73, 9, 0x452, FALSE
	return



RailwayCave_BrailleRegisteel:
	.string "杖影随尾舞，\n"
	.string "尾振百鳞鸣。\l"
	.string "鳞声如金铁，\l"
	.string "甲坚护其身。\l"
	.string "龙吟震四方。$"

RailwayCave_SusDoor::
	lock
	msgbox RailwayCave_SusDoor_Text_0
	closemessage
	msgbox RailwayCave_BrailleRegisteel, MSGBOX_DEFAULT
	closemessage
	checkspecies SPECIES_KOMMO_O
	compare VAR_RESULT, TRUE
	goto_if_eq RailwayCave_SusDoor_2
RailwayCave_SusDoor_1:
	release
	end

RailwayCave_SusDoor_2:
	setflag FLAG_SUS_RAILWAY_DOOR
	setmetatile 73, 10, 0x45A, FALSE
	setmetatile 73, 9, 0x452, FALSE
	playse SE_EXIT
	special DrawWholeMapView
	goto RailwayCave_SusDoor_1


RailwayCave_TrainerBob::
	trainerbattle_single TRAINER_RAILWAYBOB, RailwayCave_TrainerBob_Text_0, RailwayCave_TrainerBob_Text_1
	msgbox RailwayCave_TrainerBob_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave_TrainerMason::
	trainerbattle_single TRAINER_RAILWAYMASON, RailwayCave_TrainerMason_Text_0, RailwayCave_TrainerMason_Text_1
	msgbox RailwayCave_TrainerMason_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave_TrainerYoda::
	trainerbattle_single TRAINER_RAILWAYYODA, RailwayCave_TrainerYoda_Text_0, RailwayCave_TrainerYoda_Text_1
	msgbox RailwayCave_TrainerYoda_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave_TrainerSanada::
	trainerbattle_single TRAINER_RAILWAYSANADA, RailwayCave_TrainerSanada_Text_0, RailwayCave_TrainerSanada_Text_1
	msgbox RailwayCave_TrainerSanada_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave_SusDoor_Text_0:
	.string "门上刻着什么……$"

RailwayCave_TrainerBob_Text_0:
	.string "你知道吗？地鼠和三地鼠\n帮我们挖了这些隧道。$"

RailwayCave_TrainerBob_Text_1:
	.string "你知道吗？可即便如此，\n也花了好多年才完成！$"

RailwayCave_TrainerBob_Text_2:
	.string "你知道吗？这里的岩壁\n比普通的山岩硬多了。\l里面混了很多金属，\l挖起来特别费时间。$"

RailwayCave_TrainerMason_Text_0:
	.string "哇！有东西咬住我的脚了！$"

RailwayCave_TrainerMason_Text_1:
	.string "哦，原来是我的泥巴鱼！$"

RailwayCave_TrainerMason_Text_2:
	.string "泥巴鱼喜欢钻到这里的\n地下。它们似乎很中意\l这儿的气氛。$"

RailwayCave_TrainerYoda_Text_0:
	.string "哈！空气里流动的电流，\n对我的肌肉很有好处！$"

RailwayCave_TrainerYoda_Text_1:
	.string "我们还得继续锻炼！$"

RailwayCave_TrainerYoda_Text_2:
	.string "这里流动的电流，对长时间\n锻炼后的肌肉放松\l很有好处！$"

RailwayCave_TrainerSanada_Text_0:
	.string "这里是铁轨的维护隧道，\n你到底是怎么进来的？$"

RailwayCave_TrainerSanada_Text_1:
	.string "我要把这事报告给上级！$"

RailwayCave_TrainerSanada_Text_2:
	.string "就算你能带着宝可梦\n闯进任何地方，\l也不代表你就可以这么做！$"
