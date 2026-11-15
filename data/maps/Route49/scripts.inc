Route49_MapScripts::
	.byte 0


Route49_Desert_Sign::
	msgbox Route49_Desert_Sign_Text_0, MSGBOX_SIGN
	return


Route49_RoadSign::
	msgbox Route49_RoadSign_Text_0, MSGBOX_SIGN
	return


Route49_FisherJo::
	trainerbattle_single TRAINER_JO, Route49_FisherJo_Text_0, Route49_FisherJo_Text_1
	msgbox Route49_FisherJo_Text_2, MSGBOX_AUTOCLOSE
	return


Route49_Girl::
	msgbox Route49_Girl_Text_0, MSGBOX_NPC
	return


Route49_Stantler::
	lock
	faceplayer
	playmoncry SPECIES_STANTLER, CRY_MODE_NORMAL
	msgbox Route49_Stantler_Text_0
	waitmoncry
	release
	end


Route49_CooltrainerEma::
	trainerbattle_single TRAINER_EMA, Route49_CooltrainerEma_Text_0, Route49_CooltrainerEma_Text_1
	msgbox Route49_CooltrainerEma_Text_2, MSGBOX_AUTOCLOSE
	return


Route49_Fatman::
	msgbox Route49_Fatman_Text_0, MSGBOX_NPC
	return


Route49_Hiker::
	msgbox Route49_Hiker_Text_0, MSGBOX_NPC
	return


Route49_Desert_Sign_Text_0:
	.string "{RIGHT_ARROW}金刚沙漠\n{UP_ARROW}雪顶山$"

Route49_RoadSign_Text_0:
	.string "49号道路\n前方气候严酷。$"

Route49_FisherJo_Text_0:
	.string "这是我的秘密钓点，看\n我刚钓上来的东西！$"

Route49_FisherJo_Text_1:
	.string "等等，你有几枚徽章？$"

Route49_FisherJo_Text_2:
	.string "我钓鱼时会把女儿\n带上，好一家人聚聚。\l很高兴她有惊角鹿\l陪着一起玩。$"

Route49_Girl_Text_0:
	.string "爸爸钓鱼的时候，\n我喜欢和惊角鹿到处爬。$"

Route49_Stantler_Text_0:
	.string "惊角鹿：咩啊啊啊！$"

Route49_CooltrainerEma_Text_0:
	.string "我来检验你\n有没有准备好面对前方\l更严酷的环境！$"

Route49_CooltrainerEma_Text_1:
	.string "你合格了！$"

Route49_CooltrainerEma_Text_2:
	.string "不管是沙漠还是雪顶山，\n都会考验你作为\l训练家的实力。$"

Route49_Fatman_Text_0:
	.string "山上冰冷的雪化成水\n流到这儿来。真是\l清澈啊！$"

Route49_Hiker_Text_0:
	.string "这里叫作千级台阶。\n爬到顶上，就到\l雪顶山脚下了。\p最近有传闻说，\n有人目击一只威严的蓝色鸟\l在山周围飞翔。$"
