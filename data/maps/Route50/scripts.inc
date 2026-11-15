Route50_MapScripts::
	.byte 0


Route50_TrainerRowan::
	trainerbattle_single TRAINER_ROUTE50_ROWAN, Route50_TrainerRowan_Text_0, Route50_TrainerRowan_Text_1
	msgbox Route50_TrainerRowan_Text_2, MSGBOX_AUTOCLOSE
	end


Route50_TrainerCaspian::
	trainerbattle_double TRAINER_ROUTE50_CASPIAN, Route50_TrainerCaspian_Text_0, Route50_TrainerCaspian_Text_1, Route50_TrainerCaspian_Text_2
	msgbox Route50_TrainerCaspian_Text_3, MSGBOX_AUTOCLOSE
	end


Route50_TrainerIgnis::
	trainerbattle_single TRAINER_ROUTE50_IGNIS, Route50_TrainerIgnis_Text_0, Route50_TrainerIgnis_Text_1
	msgbox Route50_TrainerIgnis_Text_2, MSGBOX_AUTOCLOSE
	end


Route50_Virizion::
	lock
	faceplayer
	bosslegendaryencounter SPECIES_VIRIZION, 80, LOCALID_VIRIZION, FLAG_HIDE_VIRIZION, 2, SPECIES_NONE, 110
	release
	end


Route50_ObservingWoman::
	lock
	goto_if_unset FLAG_HIDE_VIRIZION, Route50_ObservingWoman_2
	msgbox Route50_ObservingWoman_Text_1
	release
	end

Route50_ObservingWoman_2:
	msgbox Route50_ObservingWoman_Text_0
	release
	end


Route50CafeSign::
	msgbox Route50CafeSign_Text_0, MSGBOX_SIGN
	return


Route50_TrainerRowan_Text_0:
	.string "让我看看你还有没有\n力气来对付我！$"

Route50_TrainerRowan_Text_1:
	.string "你一步都没踏错！$"

Route50_TrainerRowan_Text_2:
	.string "愤怒之湖离这儿不远。\n这一带气候说变就变。$"

Route50_TrainerCaspian_Text_0:
	.string "我正在把所有的道路\n都巡游一遍！$"

Route50_TrainerCaspian_Text_1:
	.string "你也许是我遇到过的\n最强的训练家。$"

Route50_TrainerCaspian_Text_2:
	.string "带上两只宝可梦来对战！$"

Route50_TrainerCaspian_Text_3:
	.string "你有在利用天气吗？\n天气能在一瞬间\l扭转战局。$"

Route50_TrainerIgnis_Text_0:
	.string "这地方练喷火\n再合适不过了！$"

Route50_TrainerIgnis_Text_1:
	.string "不！我的火焰！$"

Route50_TrainerIgnis_Text_2:
	.string "在这儿不会不小心\n把什么东西点着。$"

Route50_ObservingWoman_Text_0:
	.string "那边那个东西\n是什么宝可梦？$"

Route50_ObservingWoman_Text_1:
	.string "哦，你抓住那家伙了！干得好！$"

Route50CafeSign_Text_0:
	.string "对战咖啡馆\n欢迎所有挑战者！$"
