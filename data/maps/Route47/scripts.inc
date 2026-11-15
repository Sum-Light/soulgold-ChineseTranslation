
Route47_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "盼望别人来找我……\n也就这么回事。\p不过对战就是对战，\n来吧！$"
	.string ""
	.string ""
	.string ""

Route47_Text_HikerBeaten::
	.string "哇哈哈！$"

Route47_Text_HikerAfter::
	.string "对战之后，就该笑着\n道别才对！$"
	.string ""

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "我不太擅长应付人群，\n所以就和宝可梦\l一起在这里露营！$"
	.string ""
	.string ""

Route47_Text_CamperBeaten::
	.string "我该往山里\n更深处走走吧……$"
	.string ""

Route47_Text_CamperAfter::
	.string "回见！$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "汤姆：一加一等于二。可我们\n两个人在一起，可比\l二强多了！\p凯：我们俩可不是\n普普通通的一对！$"
	.string ""
	.string ""
	.string ""
	.string ""

Route47_Text_Couple1Beaten::
	.string "汤姆：这可出乎我的意料。\l凯：你也真不一般！$"
	.string ""

Route47_Text_Couple1After1::
	.string "汤姆：你的实力似乎\n根本没法预测！$"
	.string ""

Route47_Text_Couple1After2::
	.string "凯：我还以为你只是一个\n普通的独身训练家。真没想到！$"
	.string ""

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "势山：看着女朋友，\n我的心就飞了起来！\p萌海：我对男朋友的心意，\n像大海一样\l又宽又深！$"
	.string ""
	.string ""
	.string ""
	.string ""

Route47_Text_Couple2Beaten::
	.string "势山：我完全不是你的对手……\l萌海：你真是了不起……$"
	.string ""

Route47_Text_Couple2After1::
	.string "势山：谢谢你，\n这场对战真让人感动！再见！$"
	.string ""

Route47_Text_Couple2After2::
	.string "萌海：你也该去找个\n出色的伴侣才对！$"
	.string ""

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "你好啊！\p据说这个洞窟的前方，\n曾经有一座高耸入云的\l巨大宝塔。\p据说那座塔有一半\n嵌在悬崖里，\l模样十分奇特。\p它不只有高耸入云，\n还一直延伸到\l地底深处！\p传说它甚至\n一直通到了海底！\p总之，这座遗迹曾经\n把天空、大地和\l海洋连接在一起……\p如今塔大部分都崩塌了，\n只剩入口和内部，\l还能在里面看到\l奇妙的纹样。$"
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
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "灯笼鱼：啾！$"

Route47_HiddenGrotto::
	msgbox Route47_HiddenGrotto_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route47_HiddenGrotto_2
Route47_HiddenGrotto_1:
	release
	end

Route47_HiddenGrotto_2:
	warp MAP_HIDDEN_GROTTO_ROUTE47, 0
	waitstate
	goto Route47_HiddenGrotto_1


Route47_ChuckRematch::
	lock
	msgbox Route47_ChuckRematch_Text_0
	waitmessage
	faceplayer
	msgbox Route47_ChuckRematch_Text_1
	msgbox Route47_ChuckRematch_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq Route47_ChuckRematch_2
Route47_ChuckRematch_1:
	release
	end

Route47_ChuckRematch_2:
	trainerbattle_no_intro TRAINER_CHUCK_2, Route47_ChuckRematch_Text_3
	msgbox Route47_ChuckRematch_Text_4
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_R47_CHUCK
	removeobject LOCALID_R47_CHUCK
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Route47_ChuckRematch_1


Route47OrbExpert::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE47_EXPERT, Route47OrbExpert_2
	msgbox Route47OrbExpert_Text_1
	goto_if_set FLAG_ROUTE47_EXPERT_QUALIFIED, Route47OrbExpert_5
	checktrainerflag TRAINER_DEVIN
	goto_if 1, Route47OrbExpert_9
Route47OrbExpert_4:
	release
	end

Route47OrbExpert_2:
	setflag FLAG_ROUTE47_EXPERT_QUALIFIED
	msgbox Route47OrbExpert_Text_0
	release
	end

Route47OrbExpert_5:
	setflag FLAG_ROUTE47_EXPERT_QUALIFIED
	playse SE_PIN
	applymovement LOCALID_R47_EXPERT, Common_Movement_ExclamationMark
	waitse
	msgbox Route47OrbExpert_Text_2
	trainerbattle_no_intro TRAINER_ORB_EXPERT, Route47OrbExpert_Text_3
	msgbox Route47OrbExpert_Text_4
	giveitem ITEM_FLAME_ORB
	giveitem ITEM_TOXIC_ORB
	setflag FLAG_ROUTE47_EXPERT
	addvar VAR_ROUTE_EXPERTS_DEFEATED, 1
	special Achievement_CheckAll
	msgbox Route47OrbExpert_Text_0
	goto Route47OrbExpert_4

Route47OrbExpert_8:
	checktrainerflag TRAINER_THOM_AND_KAE
	goto_if 1, Route47OrbExpert_12
	goto Route47OrbExpert_4

Route47OrbExpert_9:
	checktrainerflag TRAINER_GRANT
	goto_if 1, Route47OrbExpert_8
	goto Route47OrbExpert_4

Route47OrbExpert_12:
	checktrainerflag TRAINER_DUFF_AND_EDA
	goto_if 1, Route47OrbExpert_5
	goto Route47OrbExpert_4


Route47_HiddenGrotto_Text_0:
	.string "树后面好像有条小路。\n要进去吗？$"

Route47_ChuckRematch_Text_0:
	.string "唔，这里的水流\n不够急啊……$"

Route47_ChuckRematch_Text_1:
	.string "{PLAYER}！我一直在找\n一条水流够急的河，\l好用来锻炼对战本领！\l哇哈哈！$"

Route47_ChuckRematch_Text_2:
	.string "什么？这跟对战\n有什么关系？哼！那好，\l我有个咱们都认可的办法！\l就在这里、现在，打一场！$"

Route47_ChuckRematch_Text_3:
	.string "就是这样！$"

Route47_ChuckRematch_Text_4:
	.string "完美的姿态，巅峰的体能，\n理想的宝可梦对战！\p我要为最强的训练家\n办一座道场！好主意，\l{PLAYER}！等建好了\l我请你来！到时见！$"

Route47OrbExpert_Text_0:
	.string "从这些宝珠里引出潜力的\n方法有很多种，希望你\l能全部找到。$"

Route47OrbExpert_Text_1:
	.string "宝珠！它们蕴藏着无穷的力量！\p可你知道该如何\n正确运用它们吗？\p打败这条道路上的所有\n训练家，证明你配得上\l这份智慧，我们再谈。$"

Route47OrbExpert_Text_2:
	.string "你果然配得上这份\n宝珠的知识！让我来为你\l演示一下吧！$"

Route47OrbExpert_Text_3:
	.string "漂亮的招式。$"

Route47OrbExpert_Text_4:
	.string "现在，你更配得上\n这些宝珠了。我把它们交给你。$"
