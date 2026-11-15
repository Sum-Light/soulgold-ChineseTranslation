
GoldenrodCity_DepartmentStore_6F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_Whitney::
	lock
	faceplayer
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	removeobject LOCALID_STORE_WHITNEY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_WHITNEY
	release
	end

GoldenrodDeptStore6_Text_Whitney:
	.string "{PLAYER}！真巧啊！\p我来给我的大奶罐\n买点东西。\p还想再打一场的话，\n就到格斗道场来吧！$"
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
	.string "我在收集宝可梦！\n你有{STR_VAR_1}吗？\p要用它换我的\n{STR_VAR_2}吗？$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
	.string "太好了！我得到{STR_VAR_1}了！\p{STR_VAR_2}，你要保重哦！$"
	.string ""

GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
	.string "呃，不，好像不对。\n那不是{STR_VAR_1}。$"
	.string ""

GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
	.string "你不愿意交换吗？唉……$"

GoldenrodCity_DepartmentStore_6F_Text_After:
	.string "嗨，我以前那只腕力\n还好吗？$"


GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
    .string "你听幸运频道吗？\p想中奖的话，就尽量多\n和别人交换宝可梦，\l多拿几个训练家编号吧。$"
    .string ""
    .string ""
    .string ""

GoldenrodDeptStore_Text_6FSuperNerd:
    .string "累了的话，就尝尝自动\n售货机的饮料吧。\p宝可梦也爱喝呢。$"
    .string ""
    .string ""

GoldenrodDeptStore_Text_6FDirectory:
    .string "购物之余歇一歇吧！\p6楼　休息广场$"
    .string ""

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_Jose_2
	ingame_trade INGAME_TRADE_HONEDGE, GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_1, HonedgeTrade_Declined, HonedgeTrade_NotRequested, GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_2
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
GoldenrodCity_DepartmentStore_6F_EventScript_Jose_1:
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_2:
	msgbox GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_0
	goto GoldenrodCity_DepartmentStore_6F_EventScript_Jose_1


HonedgeTrade_Declined::
	msgbox HonedgeTrade_Declined_Text_0
	release
	end


HonedgeTrade_NotRequested::
	msgbox HonedgeTrade_NotRequested_Text_0
	release
	end


GoldenrodDEpt6F_WhitneyRematch::
	lock
	msgbox GoldenrodDEpt6F_WhitneyRematch_Text_0
	applymovement LOCALID_STORE_WHITNEY, Common_Movement_ExclamationMark
	applymovement LOCALID_STORE_WHITNEY, GoldenrodDEpt6F_WhitneyRematch_Movement_0
	waitmovement 0
	msgbox GoldenrodDEpt6F_WhitneyRematch_Text_1
	msgbox GoldenrodDEpt6F_WhitneyRematch_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodDEpt6F_WhitneyRematch_2
GoldenrodDEpt6F_WhitneyRematch_1:
	release
	end

GoldenrodDEpt6F_WhitneyRematch_2:
	trainerbattle_no_intro TRAINER_WHITNEY_2, GoldenrodDEpt6F_WhitneyRematch_Text_3
	msgbox GoldenrodDEpt6F_WhitneyRematch_Text_4
	closemessage
	moveobjecttocoords LOCALID_STORE_WHITNEY, 24, 5, DIR_WEST
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	playse SE_EXIT
	removeobject LOCALID_STORE_WHITNEY
	delay 30
	goto GoldenrodDEpt6F_WhitneyRematch_1


GoldenrodDEpt6F_WhitneyRematch_Movement_0:
	face_player
	step_end

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_0:
	.string "再次谢谢你送我皮皮！\n希望我的宝可梦对你有用！$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_1:
	.string "我一直在找稀有的宝可梦\n皮皮，你有吗？\l我会用稀有的东西跟你换！$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_2:
	.string "太感谢了！$"

HonedgeTrade_Declined_Text_0:
	.string "真可惜，听说34号道路\n"
	.string "有时候能遇到皮皮。$"

HonedgeTrade_NotRequested_Text_0:
	.string "那好像不是皮皮……$"

GoldenrodDEpt6F_WhitneyRematch_Text_0:
	.string "唔……这个好吗……？\n不对……那个更便宜……\l等等，那要是买两个的话……$"

GoldenrodDEpt6F_WhitneyRematch_Text_1:
	.string "哦，你好！\n你也来这儿买东西吗？我今天\l是来看新出的宝可梦发烧友\l杂志的。上面的皮皮\l可爱极了！$"

GoldenrodDEpt6F_WhitneyRematch_Text_2:
	.string "嘿，对了，来对战吧？\n这次我保证让你\l哭出来！$"

GoldenrodDEpt6F_WhitneyRematch_Text_3:
	.string "不能哭……不能哭……！$"

GoldenrodDEpt6F_WhitneyRematch_Text_4:
	.string "啊啊啊！我还以为赢定了！\n真不甘心……\p那真是场很棒的对战，可我\n一输就懊恼得想哭。我一直\l在努力改掉这个毛病。\p我决定了，下次对战时我会\n更加拼命，把你们打得\l落花流水！在那之前，\l你可要好好训练啊！$"
