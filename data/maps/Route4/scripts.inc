Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "我正在培育宝可梦。\n要跟我打一场吗？$"
	.string ""

Route4_Text_BirdKeeperHank_Beaten:
	.string "啊！这局是我输了……$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "有想培育的宝可梦，\n就让它先上场，再马上换下。\p就是这么练的。$"
	.string ""
	.string ""
	.string ""

Route4_Text_PicnickerHope_Seen:
	.string "我感觉自己能赢。\p来看看我猜得对不对！$"
	.string ""

Route4_Text_PicnickerHope_Beaten:
	.string "唉，你太强了。$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "听说皮皮会在月见山出现。\p可它们到底在哪儿呢？$"
	.string ""

Route4_Text_PicnickerSharon_Seen:
	.string "那个……\n我……$"
	.string ""

Route4_Text_PicnickerSharon_Beaten:
	.string "…$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "……我再去多训练一下……$"

Route4_Text_MtMoonSquareSign:
	.string "月见山广场\p沿楼梯上去就是。$"
	.string ""

