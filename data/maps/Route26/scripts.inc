Route26_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "我正在为宝可梦联盟\n做最后的准备。$"
    .string ""

Route26_Text_CooltrainermJakeBeaten:
    .string "搞砸了！$"

Route26_Text_CooltrainermJakeAfter:
    .string "想赢下联盟的比赛\n会很艰难。\p我还得再多训练训练。\p听说联盟的四天王\n比道馆馆主更强。$"
    .string ""
    .string ""
    .string ""
    .string ""

Route26_Text_CooltrainermGavenSeen:
    .string "经历过艰苦的对战，\n才能获得力量。$"
    .string ""

Route26_Text_CooltrainermGavenBeaten:
    .string "唉！人生更难啊！$"

Route26_Text_CooltrainermGavenAfter:
    .string "要前往宝可梦联盟，\n就必须穿过冠军之路。\p可冠军之路很艰险。\p基本上没人会去那里！$"
    .string ""
    .string ""
    .string ""

Route26_Text_CooltrainerfJoyceSeen:
    .string "你能走到这里，\n实力一定不差。\p这场对战，我会\n使出全力！$"
    .string ""
    .string ""
    .string ""

Route26_Text_CooltrainerfJoyceBeaten:
    .string "不！我不相信！$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "我打赢了八个道馆馆主，\n本来还很有自信。\p下次得再加把劲。$"
    .string ""
    .string ""

Route26_Text_CooltrainerfBethSeen:
    .string "我输给了一个叫小银的训练家。\p他确实很强，可是……\p那样子简直像是\n无论如何都非赢不可。\p我替他的宝可梦感到难过。$"
    .string ""
    .string ""
    .string ""
    .string ""

Route26_Text_CooltrainerfBethBeaten:
    .string "宝可梦不是战争的工具。$"

Route26_Text_CooltrainerfBethAfter:
    .string "宝可梦是无价的\n终生伙伴。$"
    .string ""

Route26_Text_PsychicRichardSeen:
    .string "哇，这么多徽章！\n真让人佩服。\p不过你想要的\n不只是收集徽章吧？$"
    .string ""
    .string ""
    .string ""

Route26_Text_PsychicRichardBeaten:
    .string "打得漂亮！$"

Route26_Text_PsychicRichardAfter:
    .string "人和宝可梦都会在经历中\n成长。\p别偷懒，也别自满。$"
    .string ""
    .string ""

Route26_Text_Sign:
    .string "26号道路\p宝可梦联盟\n接待大门$"
    .string ""
    .string ""

