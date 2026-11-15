Route12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_NewFisher:
	.string "小心，这片水域里\n住着凶猛的家伙。$"
	.string ""

Route12_Text_FisherMartinSeen:
	.string "钓鱼和宝可梦\n都讲究耐心。$"
	.string ""

Route12_Text_FisherMartinBeaten:
	.string "哇啊啊！$"

Route12_Text_FisherMartinAfterBattle:
	.string "我这急性子\n实在不适合钓鱼……$"

Route12_Text_FisherStephenSeen:
	.string "一边钓鱼，\n一边听着收音机里的音乐，\l真是太惬意了。$"
	.string ""
	.string ""

Route12_Text_FisherStephenBeaten:
	.string "都怪这破收音机\n分了我的心！$"

Route12_Text_FisherStephenAfterBattle:
	.string "你听过关都的电台节目吗？\n这边的节目\l种类可丰富了。$"
	.string ""
	.string ""

Route12_Text_FisherBarneySeen:
	.string "日常生活中\n最重要的是什么？$"
	.string ""

Route12_Text_FisherBarneyBeaten:
	.string "答案马上揭晓！$"

Route12_Text_FisherBarneyAfterBattle:
	.string "我觉得日常生活中\n最重要的东西\l就是电。\p不然的话，\n发电厂停摆时\l大家也不会这么\l大惊小怪。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route12_Text_FisherKyleSeen:
	.string "你还记得吗？$"

Route12_Text_FisherKyleBeaten:
	.string "你真的记得？$"

Route12_Text_FisherKyleAfterBattle:
	.string "钓上宝可梦时，\n钓竿传来的拉扯感……\p对钓鱼迷来说，\n那可是最棒的感觉。$"
	.string ""
	.string ""
	.string ""

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "12号道路\p北　紫苑镇$"
	.string ""

Route12_Text_FishingSpotSign:
	.string "钓鱼点$"

