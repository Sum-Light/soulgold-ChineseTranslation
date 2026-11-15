CeladonCity_Gym_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_ErikaExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE12_GET
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "莉佳：你好……天气真好，\n不是吗？真让人舒服……\p……我恐怕要打瞌睡了……\p我叫莉佳，是玉虹道馆的\n馆主。\p……哦？你是从城都\n远道而来的？真好啊……\p啊，抱歉，我刚才没注意到\n你是来挑战我的。\p好吧，不过我是不会输的。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeladonCity_Gym_Text_ErikaBeaten:
	.string "莉佳：哦！我认输了……\p你真是强得惊人……\p这枚彩虹徽章\n就交给你吧……$"
	.string ""
	.string ""

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER}得到了彩虹徽章。$"

CeladonCity_Gym_Text_ErikaExplainTM:
	.string "莉佳：刚才真是场\n愉快的对战。\p我很受触动。这枚招式学习器\n请你收下。\p里面是终极吸取。\p这是个很棒的招式，能把造成\n伤害的一半\l吸收来治疗宝可梦。\p如果你喜欢，就用用看吧……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "莉佳：输了总会留下\n苦涩的余味……\p但知道有强大的训练家\n存在，反而让我更想进步……$"
	.string ""
	.string ""
	.string ""

CeladonCity_Gym_Text_ErikaRematch:
	.string "莉佳：哦，你好。\p真没想到，关都的冠军！\p又见到你真好。\p你的旅途一定\n很精彩吧。\p就算是冠军，也喜欢挑战。\p要不要和我再打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "莉佳：输了还是留下\n苦涩的余味……\p但知道有强大的训练家\n存在，反而让我更想进步……$"
	.string ""
	.string ""
	.string ""

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "你觉得只有女孩子的道馆\n很少见吗？$"
	.string ""

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "啊啊，真不甘心！$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "我只是大意了而已！$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "哦，要对战？有点吓人，\n不过好吧！$"
	.string ""

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "哦，这就完了？$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "哦，看看你那一身的徽章。\n难怪我赢不了！$"
	.string ""

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "你刚才是在看花，\n还是在看我？$"
	.string ""

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "真讨厌！$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "我要怎么做才能变得\n像莉佳那样有淑女气质呢？$"
	.string ""

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "让你见识见识莉佳教给\n我们的宝可梦招式！$"
	.string ""

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "唉……我们输了……$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "莉佳会替我们报仇的！$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "我们要保护莉佳！$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "我们赢不了……$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "莉佳要强得多得多！$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "玉虹宝可梦道馆\n馆主：莉佳\p优胜训练家：\n青绿、赤红$"
    .string ""
	.string ""
	.string ""

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "玉虹宝可梦道馆\n馆主：莉佳\p优胜训练家：\n青绿、赤红、{PLAYER}$"
    .string ""
    .string ""
	.string ""
