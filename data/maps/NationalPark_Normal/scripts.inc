
NationalPark_Normal_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "看！看看我的包！\p我把宝可梦图鉴里最喜欢的\n宝可梦打印出来，贴在包上了。$"
	.string ""
	.string ""

NationalPark_Normal_Text_PokefanF:
	.string "这是我女儿寄给我的邮件。\n看到它我就有精神了。$"
	.string ""

NationalPark_Normal_Text_Teacher1:
	.string "请专心听讲！\p……啊，糟了，我老是改不掉\n老师的口气。\p你一定是宝可梦训练家吧。\p看你这么努力，\n这个就送给你吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "让宝可梦带上先制之爪吧。\p有时在对战中，它能让宝可梦\n抢先出手。$"
	.string ""
	.string ""

NationalPark_Normal_Text_Youngster1:
	.string "我正在用宝可梦图鉴里\n打印出来的贴纸玩。$"
	.string ""

NationalPark_Normal_Text_Youngster2:
	.string "赢了的话，我就能拿到\n对方的宝可梦图鉴贴纸。$"
	.string ""

NationalPark_Normal_Text_Teacher2:
	.string "我常在自然公园散步，但\n从不走进草丛。\p因为训练家们总是\n一见人就要求对战……\p你一定经历过很多对战吧。\n我来帮你治疗宝可梦吧。$"
	.string ""
	.string ""
	.string ""
	.string ""

NationalPark_Normal_Text_Persian:
	.string "猫老大：呼呜吓——！$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "宝可梦的世界深不可测。\p还有很多我们\n不知道的事情。\p可我知道的比你多！$"
	.string ""
	.string ""
	.string ""

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "什、什、什么？$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "要学的还有很多。\p比如说……\p招式学习器一共有100种。\p交换来的宝可梦\n升级更快。$"
	.string ""
	.string ""
	.string ""

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "我的宝可梦们实在太可爱了。\p让我跟你说说，我的宝贝们\n有多让我骄傲吧。$"
	.string ""
	.string ""

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "论骄傲我可不会输，\n可是……$"

NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "不得不说，你的宝可梦\n也相当可爱呢。$"
	.string ""

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "我们一心宠爱着自己的宝可梦，\n哪怕它们讨厌我们。\p所谓发烧友，就是这么回事。$"
	.string ""
	.string ""

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "我、我的宝可梦！$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "对战是输了，但论可爱，\n我的宝可梦可是能拿冠军的。$"
	.string ""

NationalPark_Normal_Text_LassKrise_Seen:
	.string "嗯？你为什么一直盯着我看？\p哦，要打一场？$"
	.string ""

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "……嗯……$"

NationalPark_Normal_Text_LassKrise_After:
	.string "我还以为你盯着我看，\n是因为我可爱呢！$"
	.string ""

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "休息广场\n自然公园$"
	.string ""

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "这是什么告示？\p请只在草丛中\n进行对战。\p自然公园管理处$"
	.string ""
	.string ""

NationalPark_Normal_Text_TrainerTips:
	.string "训练家提示\p打开邮件后按START键，\n就能把邮件打印出来。$"
	.string ""
	.string ""

NationalPark_BugsyRematch::
	lock
	faceplayer
	msgbox NationalPark_BugsyRematch_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq NationalPark_BugsyRematch_2
NationalPark_BugsyRematch_1:
	release
	end

NationalPark_BugsyRematch_2:
	trainerbattle_no_intro TRAINER_BUGSY_2, NationalPark_BugsyRematch_Text_1
	msgbox NationalPark_BugsyRematch_Text_2
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_NATIONAL_BUGSY
	removeobject LOCALID_NATIONAL_BUGSY
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	goto NationalPark_BugsyRematch_1


NationalPark_BugsyRematch_Text_0:
	.string "哟，{PLAYER}！\p我在查看栎树林这里的\n虫宝可梦，确认没有坏家伙\l来欺负它们。\p自从上次交手后我变强了\n不少，要不要\l给你展示一下？$"

NationalPark_BugsyRematch_Text_1:
	.string "干得好！你强得离谱！$"

NationalPark_BugsyRematch_Text_2:
	.string "看来要想赢过你，我的队伍\n还差得远呢。\p等大家再聚齐了，\n我们再像这样打一场吧。\p在那之前，回见！$"
