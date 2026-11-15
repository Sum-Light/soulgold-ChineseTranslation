UnionCave_B2F_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_CooltrainerNick::
	trainerbattle_single TRAINER_NICK, UnionCave_B2F_Text_CooltrainermNickSeen, UnionCave_B2F_Text_CooltrainermNickBeaten
	msgbox UnionCave_B2F_Text_CooltrainermNickAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfGwen::
	trainerbattle_single TRAINER_GWEN, UnionCave_B2F_Text_CooltrainerfGwenSeen, UnionCave_B2F_Text_CooltrainerfGwenBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfGwenAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfEmma::
	trainerbattle_single TRAINER_EMMA, UnionCave_B2F_Text_CooltrainerfEmmaSeen, UnionCave_B2F_Text_CooltrainerfEmmaBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfEmmaAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_Lapras::
	lock
	faceplayer
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_LAPRAS, 45
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnionCave_B2F_EventScript_LaprasRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_UNION_CAVE_LAPRAS
	setflag FLAG_HIDE_UNION_CAVE_LAPRAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

UnionCave_B2F_EventScript_LaprasRan::
	release
	end


UnionCave_B2F_Text_CooltrainermNickSeen:
	.string "世上有两种人。\p有品位的，\n和没有品位的。\p你是哪一种？$"
	.string ""
	.string ""
	.string ""

UnionCave_B2F_Text_CooltrainermNickBeaten:
	.string "你的风格真是耀眼！$"

UnionCave_B2F_Text_CooltrainermNickAfter:
	.string "你的宝可梦风格\n华丽又多彩，我承认。\p你会越来越强的！$"
	.string ""
	.string ""

UnionCave_B2F_Text_CooltrainerfGwenSeen:
	.string "我正在特训。\n要不要来一场？$"

UnionCave_B2F_Text_CooltrainerfGwenBeaten:
	.string "啊，不行！\n你实在太强了。$"

UnionCave_B2F_Text_CooltrainerfGwenAfter:
	.string "我要一个人\n特训变强。$"
	.string ""

UnionCave_B2F_Text_CooltrainerfEmmaSeen:
	.string "只要有我喜欢的\n宝可梦在，我哪里都会去。\p真正的训练家\n就是这么做的。$"
	.string ""
	.string ""

UnionCave_B2F_Text_CooltrainerfEmmaBeaten:
	.string "与其这样，\n我宁可去摸摸我的宝贝们！$"

UnionCave_B2F_Text_CooltrainerfEmmaAfter:
	.string "每周会有一次，宝可梦\n会来到水边。\p我一直想见见\n那只宝可梦……$"
	.string ""
	.string ""
