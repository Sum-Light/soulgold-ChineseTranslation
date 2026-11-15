
Route38_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_Text_BirdKeeperTobySeen:
	.string "展翅高飞吧，\n我心爱的鸟宝可梦！$"
	.string ""

Route38_Text_BirdKeeperTobyBeaten:
	.string "我现在真想就这么\n飞走算了。$"
	.string ""

Route38_Text_BirdKeeperTobyAfter:
	.string "我打算去湛蓝市修行，\n教宝可梦学会飞翔。$"
	.string ""

Route38_Text_SchoolboyChad1Seen:
	.string "让我试试今天\n学到的东西。$"
	.string ""

Route38_Text_SchoolboyChad1Beaten:
	.string "看来是我学得\n还不够啊。$"
	.string ""

Route38_Text_SchoolboyChadAfter:
	.string "我要考的试太多了，\n没什么时间\l玩宝可梦。\p所以每次能玩的时候，\n我都特别投入。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route38_Text_LassDana1Seen:
	.string "你好像很擅长\n宝可梦。\p既然这样，能不能\n给我点建议？$"
	.string ""
	.string ""
	.string ""

Route38_Text_LassDana1Beaten:
	.string "原来如此。还可以\n那样对战啊。$"
	.string ""

Route38_Text_LassDanaAfter:
	.string "我告诉你个好消息！\p哞哞牧场的牛奶\n以味道好而闻名。$"
	.string ""
	.string ""

Route38_Text_BeautyValerieSeen:
	.string "嗨！你真是个\n可爱的训练家！\p让我看看你的宝可梦吧？$"
	.string ""
	.string ""

Route38_Text_BeautyValerieBeaten:
	.string "能看到你的宝可梦，\n我很开心！$"
	.string ""

Route38_Text_BeautyValerieAfter:
	.string "一看到宝可梦，\n我的心情就会平静下来。$"
	.string ""

Route38_Text_SailorHarrySeen:
	.string "我出过国，所以各种\n宝可梦我都\l知道！$"
	.string ""
	.string ""

Route38_Text_SailorHarryBeaten:
	.string "你的实力是世界级的！$"

Route38_Text_SailorHarryAfter:
	.string "世界各地的人们\n都和宝可梦一起\l幸福地生活着。$"
	.string ""
	.string ""

Route38_Text_BeautyOliviaSeen:
	.string "你不觉得我和我的\n宝可梦都很美吗？$"
	.string ""

Route38_Text_BeautyOliviaBeaten:
	.string "我们每天都喝哞哞鲜奶。$"
	.string ""

Route38_Text_BeautyOliviaAfter:
	.string "哞哞鲜奶对美容和健康\n都很好。\p可麻烦的是，每次\n只能买一瓶。$"
	.string ""
	.string ""
	.string ""

Route38_Text_Sign:
	.string "38号道路\p浅葱市——缘朱市$"
	.string ""

Route38_Text_TrainerTips:
	.string "训练家提示\p宝可梦快要进化的时候，\n你是可以阻止的。\p在进化途中按下B键\n就能取消这次进化。\p宝可梦会受到惊吓，\n进化也就停止了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""


Route38_Text_WaterSign:
	.string "禁止游泳和钓鱼。\n水域仅用于农业。\p——缘朱市议会$"
	.string ""
	.string ""

Route38_HiddenGrotto::
	msgbox Route38_HiddenGrotto_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route38_HiddenGrotto_2
Route38_HiddenGrotto_1:
	release
	end

Route38_HiddenGrotto_2:
	warp MAP_HIDDEN_GROTTO_ROUTE38, 0
	waitstate
	goto Route38_HiddenGrotto_1


Route38_HiddenGrotto_Text_0:
	.string "树丛后面好像有一条路。\n要进去吗？$"
