Kitakami_Houses_MapScripts::
	.byte 0


KitakamiHouses_1_Oldman::
	lock
	faceplayer
	goto_if_set FLAG_CANDY_KITAKAMI, KitakamiHouses_1_Oldman_2
	msgbox KitakamiHouses_1_Oldman_Text_1
	random 3
	switch VAR_RESULT
	case 0, KitakamiHouses_1_Oldman_6
	case 1, KitakamiHouses_1_Oldman_7
	case 2, KitakamiHouses_1_Oldman_8
KitakamiHouses_1_Oldman_4:
	setflag FLAG_CANDY_KITAKAMI
	msgbox KitakamiHouses_1_Oldman_Text_0
	release
	end

KitakamiHouses_1_Oldman_2:
	msgbox KitakamiHouses_1_Oldman_Text_0
	release
	end

KitakamiHouses_1_Oldman_6:
	giveitem ITEM_EXP_CANDY_M, 3
	goto KitakamiHouses_1_Oldman_4

KitakamiHouses_1_Oldman_7:
	giveitem ITEM_EXP_CANDY_L, 2
	giveitem ITEM_EXP_CANDY_M, 1
	goto KitakamiHouses_1_Oldman_4

KitakamiHouses_1_Oldman_8:
	giveitem ITEM_EXP_CANDY_XL, 1
	giveitem ITEM_EXP_CANDY_L, 1
	goto KitakamiHouses_1_Oldman_4


KitakamiHouses_3_Sinistea::
	lock
	faceplayer
	playmoncry SPECIES_SINISTEA, CRY_MODE_NORMAL
	msgbox KitakamiHouses_3_Sinistea_Text_0
	waitmoncry
	release
	end


KitakamiHouses_2_Steven::
	lock
	faceplayer
	goto_if_set FLAG_MET_STEVEN, KitakamiHouses_2_Steven_2
	msgbox KitakamiHouses_2_Steven_Text_7
	msgbox KitakamiHouses_2_Steven_Text_8
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 15, ITEM_IRON_BALL, ITEM_LUXURY_BALL
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	setflag FLAG_MET_STEVEN
	createfieldmugshot MUGSHOT_STEVEN
	msgbox KitakamiHouses_2_Steven_Text_9
	waitmessage
	release
	end

KitakamiHouses_2_Steven_2:
	goto_if_set FLAG_IS_CHAMPION, KitakamiHouses_2_Steven_5
	msgbox KitakamiHouses_2_Steven_Text_6
	release
	end

KitakamiHouses_2_Steven_5:
	goto_if_unset FLAG_TEMP_10, KitakamiHouses_2_Steven_9
KitakamiHouses_2_Steven_8:
	msgbox KitakamiHouses_2_Steven_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq KitakamiHouses_2_Steven_11
	release
	end

KitakamiHouses_2_Steven_9:
	playse SE_PIN
	applymovement LOCALID_KITAKAMI_STEVEN, Common_Movement_ExclamationMark
	applymovement LOCALID_KITAKAMI_STEVEN, KitakamiHouses_2_Steven_Movement_0
	waitmovement 0
	waitse
	msgbox KitakamiHouses_2_Steven_Text_0
	setflag FLAG_TEMP_10
	goto KitakamiHouses_2_Steven_8

KitakamiHouses_2_Steven_11:
	msgbox KitakamiHouses_2_Steven_Text_2
	trainerbattle_no_intro TRAINER_STEVEN, KitakamiHouses_2_Steven_Text_3
	msgbox KitakamiHouses_2_Steven_Text_4
	giveitem ITEM_JADE_ORB
	waitmessage
	msgbox KitakamiHouses_2_Steven_Text_5
	waitmessage
	closemessage
	setflag FLAG_BEAT_STEVEN_KITAKAMI
	moveobjecttocoords LOCALID_KITAKAMI_STEVEN, 28, 8, DIR_SOUTH
	waitmovement LOCALID_KITAKAMI_STEVEN
	delay 15
	playse SE_EXIT
	removeobject LOCALID_KITAKAMI_STEVEN
	release
	end


PorygonPC::
	lockall
	playmoncry SPECIES_PORYGON_Z, CRY_MODE_NORMAL
	msgbox PorygonPC_Text_0
	goto EventScript_PCMainMenu
	return


KitakamiHouses_3_Lady::
	msgbox KitakamiHouses_3_Lady_Text_0, MSGBOX_NPC
	return


KitakamiHouses_3_Man::
	msgbox KitakamiHouses_3_Man_Text_0, MSGBOX_NPC
	return


KitakamiHouses_2_Steven_Movement_0:
	face_player
	step_end

KitakamiHouses_1_Oldman_Text_0:
	.string "等我明天做好下一批，\n你再来吧！$"

KitakamiHouses_1_Oldman_Text_1:
	.string "呵呵呵！\p我可是整个城都地区\n最棒的糖果师傅！\p来，尝尝我今天的这一批！$"

KitakamiHouses_3_Sinistea_Text_0:
	.string "来悲茶：嘶——！$"

KitakamiHouses_2_Steven_Text_0:
	.string "那副下定决心的表情……\n你是成为城都的冠军了吗？\p……\p了不起！我没看错\n你作为训练家的潜力。\p如果你不介意，\n我现在就很乐意和你对战。$"

KitakamiHouses_2_Steven_Text_1:
	.string "你准备好面对我了吗？$"

KitakamiHouses_2_Steven_Text_2:
	.string "好极了，我绝不会手下留情，\n也请你全力以赴！$"

KitakamiHouses_2_Steven_Text_3:
	.string "精彩，你确实配得上\n冠军的头衔。$"

KitakamiHouses_2_Steven_Text_4:
	.string "这场对战让我高兴得\n没法形容。\p你是一位技艺出众的训练家。\p我想把这个送给你，\n作为我们相遇的纪念。\p这是我从北方的山里\n挖出来的。\p在47号道路附近，\n也许你能用得上。$"

KitakamiHouses_2_Steven_Text_5:
	.string "我想我该出发，\n去探索新的地方了。\p希望有朝一日能再见到你，\n{PLAYER}。$"

KitakamiHouses_2_Steven_Text_6:
	.string "如果你成了这个地区的冠军，\n就来找我吧。\p我很想用全部实力\n和你对战一场。$"

KitakamiHouses_2_Steven_Text_7:
	.string "哦，你好。你是哪位？\p……\p{PLAYER}？\n幸会。\p我叫大吾，来自丰缘地区，\n正在寻找稀有的石头。$"

KitakamiHouses_2_Steven_Text_8:
	.string "你看起来像个训练家，是在城都\n收集徽章吗？\p嗯……也许……\p对，你或许有\n这个潜力。\p你愿意听听我的请求吗？\p我希望你收下这只铁哑铃。\n它是来自丰缘的稀有宝可梦。\p好好照顾它，如果你成了冠军，\n再来找我。\p到时候，我想和你\n对战一场作为回报。$"

KitakamiHouses_2_Steven_Text_9:
	.string "我对你抱有很高的期望。$"

PorygonPC_Text_0:
	.string "{PLAYER}启动了多边兽\n远程电脑。$"

KitakamiHouses_3_Lady_Text_0:
	.string "和家人在这里生活很平静，\n我别无所求。$"

KitakamiHouses_3_Man_Text_0:
	.string "这座城镇受到厄诡椪的守护，\n它偶尔会来镇上看看。\p我个人从没见过它，\n但孩子们都说见过。$"
