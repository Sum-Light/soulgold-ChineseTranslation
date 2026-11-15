GoldenrodShore_MapScripts::
	.byte 0


GoldenrodShore_Expert::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENRODSHORE_EXPERT, GoldenrodShore_Expert_2
	msgbox GoldenrodShore_Expert_Text_1
	goto_if_set FLAG_GOLDENRODSHORE_EXPERT_QUALIFIED, GoldenrodShore_Expert_5
	checktrainerflag TRAINER_SAMUEL
	goto_if 1, GoldenrodShore_Expert_9
GoldenrodShore_Expert_4:
	release
	end

GoldenrodShore_Expert_2:
	setflag FLAG_GOLDENRODSHORE_EXPERT_QUALIFIED
	msgbox GoldenrodShore_Expert_Text_0
	release
	end

GoldenrodShore_Expert_5:
	setflag FLAG_GOLDENRODSHORE_EXPERT_QUALIFIED
	applymovement LOCALID_GOLDENRODSHORE_EXPERT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	msgbox GoldenrodShore_Expert_Text_2
	trainerbattle_no_intro TRAINER_GOLDENROD_SHORE_EXPERT, GoldenrodShore_Expert_Text_3
	msgbox GoldenrodShore_Expert_Text_4
	giveitem ITEM_LOADED_DICE
	setflag FLAG_GOLDENRODSHORE_EXPERT
	addvar VAR_ROUTE_EXPERTS_DEFEATED, 1
	special Achievement_CheckAll
	msgbox GoldenrodShore_Expert_Text_5
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_8:
	checktrainerflag TRAINER_TODD
	goto_if 1, GoldenrodShore_Expert_13
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_9:
	checktrainerflag TRAINER_BRANDON
	goto_if 1, GoldenrodShore_Expert_8
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_12:
	checktrainerflag TRAINER_GINA
	goto_if 1, GoldenrodShore_Expert_17
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_13:
	checktrainerflag TRAINER_IAN
	goto_if 1, GoldenrodShore_Expert_12
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_16:
	checktrainerflag TRAINER_ELLIOT
	goto_if 1, GoldenrodShore_Expert_21
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_17:
	checktrainerflag TRAINER_KIM
	goto_if 1, GoldenrodShore_Expert_16
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_20:
	checktrainerflag TRAINER_IVAN
	goto_if 1, GoldenrodShore_Expert_25
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_21:
	checktrainerflag TRAINER_BROOKE
	goto_if 1, GoldenrodShore_Expert_20
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_24:
	checktrainerflag TRAINER_WALT
	goto_if 1, GoldenrodShore_Expert_29
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_25:
	checktrainerflag TRAINER_IRWIN
	goto_if 1, GoldenrodShore_Expert_24
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_28:
	checktrainerflag TRAINER_BRYAN
	goto_if 1, GoldenrodShore_Expert_33
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_29:
	checktrainerflag TRAINER_ARNIE
	goto_if 1, GoldenrodShore_Expert_28
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_32:
	checktrainerflag TRAINER_ALAN
	goto_if 1, GoldenrodShore_Expert_5
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_33:
	checktrainerflag TRAINER_MARK
	goto_if 1, GoldenrodShore_Expert_32
	goto GoldenrodShore_Expert_4


GoldenrodShore_Sign::
	msgbox GoldenrodShore_Sign_Text_0, MSGBOX_SIGN
	return


GoldenrodShore_Engineer::
	msgbox GoldenrodShore_Engineer_Text_0, MSGBOX_NPC
	return


GoldenrodShore_HiddenGrotto::
	msgbox GoldenrodShore_HiddenGrotto_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodShore_HiddenGrotto_2
GoldenrodShore_HiddenGrotto_1:
	release
	end

GoldenrodShore_HiddenGrotto_2:
	warp MAP_HIDDEN_GROTTO_GOLDENROD_SHORE, 0
	waitstate
	goto GoldenrodShore_HiddenGrotto_1


MareaniesGoldenrodShore::
	msgbox MareaniesGoldenrodShore_Text_0, MSGBOX_NPC
	return


GoldenrodShore_Expert_Text_0:
	.string "既然不用再守着\n这个道路名人头衔了，\l我想我总算能回家了。$"

GoldenrodShore_Expert_Text_1:
	.string "嗨！我是这一带的道路名人！\p如果你能把34号、35号\n和36号道路上的训练家全部打败，\l就来和我一较高下吧。$"

GoldenrodShore_Expert_Text_2:
	.string "你获胜的消息，我已经听说了！\p那就来比一场吧，我让你见识\n一种全新的战术！$"

GoldenrodShore_Expert_Text_3:
	.string "被你看穿了！$"

GoldenrodShore_Expert_Text_4:
	.string "面对我这如潮水般连绵不绝的攻势，\n你竟然还是赢了。\p请收下这个，它能让你\n更容易保持\l连胜的势头。$"

GoldenrodShore_Expert_Text_5:
	.string "机变骰子能提高连续招式的\n最低攻击次数，\l你可以配合种子机关枪这类招式！$"

GoldenrodShore_Sign_Text_0:
	.string "满金海岸，请勿乱扔垃圾！$"

GoldenrodShore_Engineer_Text_0:
	.string "好，就在这儿开始挖一条路吧。\n宝可梦全能竞技赛的工程\l就从这里动工！$"

GoldenrodShore_HiddenGrotto_Text_0:
	.string "树后好像有条小路。\n要进去吗？$"

MareaniesGoldenrodShore_Text_0:
	.string "好坏星群似乎挡住了去路。\p也许还有别的路能\n通往浅葱市？$"
