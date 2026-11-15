
MahoganyTown_Gym_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "卡吉镇宝可梦道馆$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "卡吉镇宝可梦道馆\p柳伯认证训练家：\n{PLAYER}$"
	.string ""
	.string ""


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
    setflag FLAG_SOUTHPASSAGE_ARIANA
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANYTOWN
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1, MahoganyTown_Gym_Text_PryceImpressed
    setflag FLAG_RECEIVED_BADGE_5
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2, MahoganyTown_Gym_Text_PryceImpressed
    setflag FLAG_RECEIVED_BADGE_6
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3, MahoganyTown_Gym_Text_PryceImpressed
    setflag FLAG_RECEIVED_BADGE_7
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
    .string "宝可梦和我们一样，\n一生中会经历许多事。\p我这一生也见过、\n吃过不少苦。\p既然我是你的前辈，\n就让我来示范给你看。\p你还没出生的时候，\n我就已经和宝可梦在一起了。\p我可不会轻易认输。\p我，柳伯，冬天的训练家，\n这就让你见识我的力量！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_PryceImpressed:
    .string "啊，你的本领确实\n让我佩服。\p有这样坚强的意志，\n你一定能克服生活的一切障碍。\p你配得上这枚徽章！$"
    .string ""
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_ReceivedBadge:
    .string "{PLAYER}得到了冰雪徽章。$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
    .string "有了这枚徽章，\n你的宝可梦就能用潮旋\l越过真正的漩涡。\p还有这个……这是我\n给你的礼物！$"
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_HailSpeech:
    .string "那个招式学习器里\n装的是冰雹。\p它会在5个回合里\n每回合造成伤害。\p它展现了冬天的严酷。$"
    .string ""
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_CherishPokemon:
    .string "冰雪融化之时，\n春天就会到来。\p你和你的宝可梦还会\n一起度过许多年。\p好好珍惜在一起的时光！$"
    .string ""
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_PryceRematch:
    .string "啊，城都的冠军！\p你的身手确实出众。\p真令人钦佩。\p不过即便到了现在，\n我们仍能互相学到很多。\p我，柳伯，冬天的训练家，\n还留了几手。\p要再和我较量一场吗？$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_PryceRematchDefeat:
    .string "啊，你的本领又一次\n让我佩服。\p有这样坚强的意志，\n你一定能克服生活的一切障碍。$"
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_Guide:
    .string "柳伯是训练了宝可梦\n大约50年的老手。\p他的队伍十分扎实，\n无论你带什么来\l都能应付。\p用火属性来开局不错，\n不过要小心他的降雨！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_GuideWin:
    .string "柳伯真有两下子，\n不过你更了不起！\p那是一场跨越了代沟的\n火热对战！$"
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_BoarderRonaldSeen:
    .string "我要把你的宝可梦冻住，\n让你动弹不得！$"
    .string ""

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
    .string "可恶。我一点都动不了。$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
    .string "我觉得宝可梦在被冻住时\n也有能用的\l招式。$"
    .string ""
    .string ""

MahoganyTown_Gym_Text_BoarderBradSeen:
    .string "这个道馆的地板很滑。\p挺有意思的吧？\p不过说真的，\n我们可不是在闹着玩！$"
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_BoarderBradBeaten:
    .string "你看出我们有多认真了吧？$"

MahoganyTown_Gym_Text_BoarderBradAfter:
    .string "这个道馆太棒了。\n我最喜欢和宝可梦\l一起滑行了！$"
    .string ""
    .string ""

MahoganyTown_Gym_Text_BoarderDouglasSeen:
    .string "我知道柳伯的秘密。$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
    .string "好吧。我就把柳伯的秘密\n告诉你。$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
    .string "柳伯强大背后的秘密……\p他每天在瀑布下冥想，\n用这样的方式\l磨练身心。$"
    .string ""
    .string ""
    .string ""

MahoganyTown_Gym_Text_SkierRoxanneSeen:
    .string "要想到达馆主柳伯那里，\n滑冰之前得先动脑筋。$"
    .string ""

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
    .string "比滑冰我可不会输给你！$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
    .string "滑冰时若不精准，\n在这个道馆里走不远。$"
    .string ""

MahoganyTown_Gym_Text_SkierClarissaSeen:
    .string "看看我这个平行转弯！$"

MahoganyTown_Gym_Text_SkierClarissaBeaten:
    .string "不！你害我摔了个大跟头！$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
    .string "我本不该炫耀\n自己的滑雪技术……$"
    .string ""

MahoganyTown_Gym_EventScript_Froslass::
	playmoncry SPECIES_FROSLASS, CRY_MODE_NORMAL
	msgbox MahoganyTown_Gym_EventScript_Froslass_Text_0, MSGBOX_NPC
	return


MahoganyTown_Gym_EventScript_Froslass_Text_0:
	.string "呜嘶嘶！！$"
