VajraDesertEastCave_MapScripts::
	.byte 0


VajraDesertEastCave_TrainerDylan::
	trainerbattle_single TRAINER_VAJRA_EAST_DYLAN, VajraDesertEastCave_TrainerDylan_Text_0, VajraDesertEastCave_TrainerDylan_Text_1
	msgbox VajraDesertEastCave_TrainerDylan_Text_2, MSGBOX_AUTOCLOSE
	end


VajraDesertEastCave_TrainerDylan_Text_0:
	.string "你是在找那座隐藏的\n神殿吗？$"

VajraDesertEastCave_TrainerDylan_Text_1:
	.string "无尽的财宝在等着你！$"

VajraDesertEastCave_TrainerDylan_Text_2:
	.string "从下层区域两侧\n根本没法到达绿洲。\p也许从上面\n就能过去了？$"
