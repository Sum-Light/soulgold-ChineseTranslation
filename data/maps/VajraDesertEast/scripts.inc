VajraDesertEast_MapScripts::
	.byte 0


VajraDesertEast_TrainerSirocco::
	trainerbattle_single TRAINER_VAJRA_EAST_SIROCCO, VajraDesertEast_TrainerSirocco_Text_0, VajraDesertEast_TrainerSirocco_Text_1
	msgbox VajraDesertEast_TrainerSirocco_Text_2, MSGBOX_AUTOCLOSE
	end


VajraDesertEast_TrainerSol::
	trainerbattle_double TRAINER_VAJRA_EAST_SOL, VajraDesertEast_TrainerSol_Text_0, VajraDesertEast_TrainerSol_Text_1, VajraDesertEast_TrainerSol_Text_2
	msgbox VajraDesertEast_TrainerSol_Text_3, MSGBOX_AUTOCLOSE
	end


VajraDesertEast_TrainerDune::
	trainerbattle_single TRAINER_VAJRA_EAST_DUNE, VajraDesertEast_TrainerDune_Text_0, VajraDesertEast_TrainerDune_Text_1
	msgbox VajraDesertEast_TrainerDune_Text_2, MSGBOX_AUTOCLOSE
	end


VajraDesertEast_TrainerNori::
	trainerbattle_double TRAINER_VAJRA_EAST_NORI, VajraDesertEast_TrainerNori_Text_0, VajraDesertEast_TrainerNori_Text_1, VajraDesertEast_TrainerNori_Text_2
	msgbox VajraDesertEast_TrainerNori_Text_3, MSGBOX_AUTOCLOSE
	end


VajraDesertEast_TrainerAtlas::
	trainerbattle_double TRAINER_VAJRA_EAST_ATLAS, VajraDesertEast_TrainerAtlas_Text_0, VajraDesertEast_TrainerAtlas_Text_1, VajraDesertEast_TrainerAtlas_Text_2
	msgbox VajraDesertEast_TrainerAtlas_Text_3, MSGBOX_AUTOCLOSE
	end


VajraDesertEast_LadyofLake::
	msgbox VajraDesertEast_LadyofLake_Text_0, MSGBOX_NPC
	return


VajraDesertEastSign::
	msgbox VajraDesertEastSign_Text_0, MSGBOX_SIGN
	return


VajraDesertEast_TrainerSirocco_Text_0:
	.string "让我看看你有多少本事！$"

VajraDesertEast_TrainerSirocco_Text_1:
	.string "看来还挺能打……$"

VajraDesertEast_TrainerSirocco_Text_2:
	.string "最严酷的环境造就\n最强的训练家。\p总有一天，我也要\n成为最厉害的！$"

VajraDesertEast_TrainerSol_Text_0:
	.string "呼哧，呼哧！再跑一圈！$"

VajraDesertEast_TrainerSol_Text_1:
	.string "水……给我水……！$"

VajraDesertEast_TrainerSol_Text_2:
	.string "嘿，你得带两只\n能对战的宝可梦才行！$"

VajraDesertEast_TrainerSol_Text_3:
	.string "那些棕榈树后面有片绿洲，\n可你不能直接穿过去！$"

VajraDesertEast_TrainerDune_Text_0:
	.string "全速前进！$"

VajraDesertEast_TrainerDune_Text_1:
	.string "你攻得我措手不及……$"

VajraDesertEast_TrainerDune_Text_2:
	.string "有两只我从没见过的宝可梦\n从这儿飞了过去。它们已经\l回来过好几次了。\p它们到底是什么呢？$"

VajraDesertEast_TrainerNori_Text_0:
	.string "你就是打赢了阿渡的训练家？$"

VajraDesertEast_TrainerNori_Text_1:
	.string "不是吧！冠军居然打赢了我！$"

VajraDesertEast_TrainerNori_Text_2:
	.string "冠军怎么会没带\n两只宝可梦来对战？$"

VajraDesertEast_TrainerNori_Text_3:
	.string "我一定要把这事\n告诉所有朋友！$"

VajraDesertEast_TrainerAtlas_Text_0:
	.string "你觉得你能到达绿洲吗？$"

VajraDesertEast_TrainerAtlas_Text_1:
	.string "看来你是不会在\n树林里迷路了！$"

VajraDesertEast_TrainerAtlas_Text_2:
	.string "抱歉啦，伙计，你得带两只\n宝可梦来才能对战。$"

VajraDesertEast_TrainerAtlas_Text_3:
	.string "这地方简直就像热带草原，\n虽然它其实是沙漠的一部分！$"

VajraDesertEast_LadyofLake_Text_0:
	.string "这条水流对这里的生命\n至关重要。希望它永远不干涸。$"

VajraDesertEastSign_Text_0:
	.string "金刚沙漠东部$"
