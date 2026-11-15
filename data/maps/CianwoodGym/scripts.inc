.set LOCALID_CIANWOOD_CHUCK, 1
.set LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, 10
.set LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, 9

CianwoodGym_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "湛蓝市宝可梦道馆$"

CianwoodGym_Text_GymStatueCertified:
	.string "湛蓝市宝可梦道馆\p阿四认证训练家：\n{PLAYER}$"
	.string ""
	.string ""

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_SOUTHPASSAGE_ARIANA
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_BULK_UP
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "哇哈哈，{PLAYER}！\n我正修炼到一半呢！\p想再打一场的话，就来\n金黄市的格斗道场吧！$"
	.string ""
	.string ""
	.string ""	

CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "我在道场等你！\n哇哈哈哈哈$"
	.string ""

CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1, CianwoodGym_Text_ChuckIntro2
	setflag FLAG_RECEIVED_BADGE_5
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2, CianwoodGym_Text_ChuckIntro2
	setflag FLAG_RECEIVED_BADGE_6
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3, CianwoodGym_Text_ChuckIntro2
	setflag FLAG_RECEIVED_BADGE_7
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "哇哈哈！\p你终于来到这里了！\p告诉你，我可是很强的！\p我的宝可梦能碎石断骨！\p看好了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodGym_Text_ChuckIntro2:
	.string "阿四：唔唔！\n……\p嗷嗷——！$"
	.string ""
	.string ""

CianwoodGym_Text_ChuckIntro3:
	.string "怎么样！吓到了吧？\p什么？跟宝可梦没关系？\p说得也是！\p来吧。我们来对战！$"
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodGym_Text_ChuckLoss:
	.string "咦？啊？我输了？\p真没想到！\n你有资格拿打击徽章！$"
	.string ""
	.string ""

CianwoodGym_Text_GetStormBadge:
	.string "{PLAYER}得到了打击徽章。$"

CianwoodGym_Text_ChuckBadgeSpeech:
	.string "有了打击徽章，70级以下的宝可梦\n都会听话，交换来的也一样。\p对战之外，还能让你的宝可梦\n使用飞翔。\p这个也拿去吧！$"
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodGym_Text_ChuckTMSpeech:
	.string "那是健美。\p能同时提升宝可梦的\n攻击和防御！$"
	.string ""
	.string ""

CianwoodGym_Text_ChuckAfter:
	.string "哇哈哈！跟你对战真开心！\p不过输就是输！\p从今天起，我要每天\n24小时地修炼！$"
	.string ""
	.string ""
	.string ""

CianwoodGym_Text_ChuckRematch:
	.string "哇哈哈！城都冠军！\p你又来挑战了啊！\p看得出你的实力又精进了！\p准备好比一比谁更强了吗？$"
	.string ""
	.string ""
	.string ""

CianwoodGym_Text_ChuckRematchDefeat:
	.string "咦？啊？我输了？\n又输了？$"
	.string ""

CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "我和宝可梦靠友谊\n紧紧相连。\p这份纽带绝不会断！$"
	.string ""
	.string ""

CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "这不是真的！$"

CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "看来你也和宝可梦\n有着牢固的纽带！$"
	.string ""

CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "我们格斗家无所畏惧！$"

CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "真叫人震惊！$"

CianwoodGym_Text_BlackbeltLaoAfter:
	.string "格斗宝可梦很怕\n超能力……$"
	.string ""


CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "废话少说。\n用拳头说话吧！$"
	.string ""

CianwoodGym_Text_BlackbeltNobBeaten:
	.string "…$"

CianwoodGym_Text_BlackbeltNobAfter:
	.string "我输了！\n我无话可说！$"

CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "我狂暴的拳头\n会把你的宝可梦击碎！$"
	.string ""

CianwoodGym_Text_BlackbeltLungBeaten:
	.string "我被击碎了！$"

CianwoodGym_Text_BlackbeltLungAfter:
	.string "我的宝可梦输了……\n我……我的自尊也被击碎了……$"
	.string ""
