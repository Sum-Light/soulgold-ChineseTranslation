
Route31_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	msgbox Route31_Text_DescribeNightmare, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "黑暗洞穴……\p要是宝可梦能照亮这里，\n我就去里面探险。$"
	.string ""
	.string ""

Route31_Text_BugCatcherWade1_Seen:
	.string "我抓了好多宝可梦。\n来和我对战吧！$"
	.string ""

Route31_Text_BugCatcherWade1_Beaten:
	.string "呜……$"

Route31_Text_BugCatcherWade1_After:
	.string "就算身上带了六只宝可梦，\n也还能继续捕捉。\p抓到的那只会自动\n送到你的电脑盒子里。$"
	.string ""
	.string ""
	.string ""

Route31_Text_SleepyMan:
	.string "……唔嗯……嗯？\p今天为了找宝可梦，\n走了太多的路。\p脚也疼，人也困……\p要是我变成野生宝可梦，\n一定很容易被抓到……\p……呼噜……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route31_Text_SleepyManGotMail:
	.string "……呼噜……嗯？\p什么？你有邮件\n要交给我？$"
	.string ""
	.string ""

Route31_Text_SleepyManFail:
	.string "……呼噜……$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER}把拿着邮件的\n宝可梦交了出去。$"
	.string ""

Route31_Text_ReadingMail:
	.string "让我看看……\p谢谢你特地把它\n送来给我。\p我的朋友是个好人，\n你也是个热心人！\p我也想为你做点\n什么作为回报！\p我知道了！这个\n就送给你吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route31_Text_DescribeNightmare:
	.string "招式学习器里装的是无理取闹。\p这是个非常刁钻的招式，\n会让对手心神不宁，\l无法连续出招。\p它就无法连续使出同一招式。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route31_Text_WrongMail:
	.string "这封邮件不是给我的。$"

Route31_Text_MissingMail:
	.string "这只宝可梦有什么特别的？\p它身上根本没带邮件。$"
	.string ""

Route31_Text_DeclinedToHandOverMail:
	.string "什么？你什么都不要吗？$"
	.string ""

Route31_Text_CantTakeLastMon:
	.string "我要是把那只宝可梦\n拿走了，\p你对战的时候\n要用什么？$"
	.string ""
	.string ""
	.string ""

Route31_Text_Youngster:
	.string "我在黑暗洞穴\n找到了一只不错的宝可梦。\p我打算把它培育好，\n去挑战阿速。\p他是桔梗市\n道馆的馆主。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route31_Text_Sign:
	.string "31号道路\p桔梗市——吉花市$"
	.string ""

Route31_Text_DarkCaveSign:
	.string "黑暗洞穴$"

Route31_Expert::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE31_EXPERT, Route31_Expert_2
	msgbox Route31_Expert_Text_1
	goto_if_set FLAG_ROUTE31_EXPERT_QUALIFIED, Route31_Expert_5
	checktrainerflag TRAINER_WADE
	goto_if 1, Route31_Expert_9
Route31_Expert_4:
	release
	end

Route31_Expert_2:
	setflag FLAG_ROUTE31_EXPERT_QUALIFIED
	msgbox Route31_Expert_Text_0
	release
	end

Route31_Expert_5:
	setflag FLAG_ROUTE31_EXPERT_QUALIFIED
	msgbox Route31_Expert_Text_2
	trainerbattle_no_intro TRAINER_ROUTE_31_EXPERT, Route31_Expert_Text_3
	createfieldmugshot MUGSHOT_COOLTRAINER_M
	msgbox Route31_Expert_Text_4
	giveitem ITEM_AIR_BALLOON
	setflag FLAG_ROUTE31_EXPERT
	addvar VAR_ROUTE_EXPERTS_DEFEATED, 1
	special Achievement_CheckAll
	createfieldmugshot MUGSHOT_COOLTRAINER_M
	msgbox Route31_Expert_Text_0
	goto Route31_Expert_4

Route31_Expert_8:
	checktrainerflag TRAINER_MIKEY
	goto_if 1, Route31_Expert_12
	goto Route31_Expert_4

Route31_Expert_9:
	checktrainerflag TRAINER_JOEY
	goto_if 1, Route31_Expert_8
	goto Route31_Expert_4

Route31_Expert_12:
	checktrainerflag TRAINER_DON
	goto_if 1, Route31_Expert_5
	goto Route31_Expert_4


Route31_Expert_Text_0:
	.string "气球能让宝可梦\n在受到攻击前\l避开地面属性的招式。\p也许会在\n接下来的对战中\l派上用场。\p和它类似的携带道具\n每场对战只能\l发动一次。\p对战结束后\n就会恢复。$"

Route31_Expert_Text_1:
	.string "人们都叫我道路专家。\p如果你能打败30号和31号\n道路上的所有训练家，\l就再来找我，我们比一场。\p要是你能赢，\n我不会让你白忙一场。$"

Route31_Expert_Text_2:
	.string "哦，你确实打败了这条路上\n所有的训练家。\p那就按约定，\n和我一战吧。$"

Route31_Expert_Text_3:
	.string "撑不住了……$"

Route31_Expert_Text_4:
	.string "你比我想象的更强。\p这个就当作你胜利的奖品，\n拿去吧。$"
