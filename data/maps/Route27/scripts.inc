

Route27_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route27_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route27_EventScript_BaobaCall::
	pokenavcall BlackthornCity_Text_BaobaCall
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
    setvar VAR_ROUTE27_BAOBA_CALL, 1
	end

Route27_Movement_WalkTop:
    face_left
    walk_left
    step_end

Route27_Movement_WalkBot:
    walk_down
    walk_left
    step_end

Route27_EventScript_Fatman::
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
    end

Route27_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Reena::
	trainerbattle_single TRAINER_REENA Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Scott::
	trainerbattle_single TRAINER_SCOTT Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_TohjoFallsSign::
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
    end

Route27_Text_FisherHey:
    .string "喂！$"

Route27_Text_FisherMessage:
    .string "你知道你刚才做了什么吗？\p你迈出了踏入\n关都的第一步。\p看看宝可梦装置的地图吧。$"
    .string ""
    .string ""
    .string ""

Route27_Text_CooltrainermBlakeSeen:
    .string "你看起来挺强。\n来跟我打一场吧！$"
    .string ""

Route27_Text_CooltrainermBlakeBeaten:
    .string "哟！$"

Route27_Text_CooltrainermBlakeAfter:
    .string "若能走完这段艰险路程，\p真相自会显现！\p嘿，抱歉，我只是想说句\n帅气的话。$"
    .string ""
    .string ""
    .string ""

Route27_Text_CooltrainermBrianSeen:
    .string "嗯？你很能打嘛？$"

Route27_Text_CooltrainermBrianBeaten:
    .string "果然如此！$"

Route27_Text_CooltrainermBrianAfter:
    .string "好训练家\n认得出别的好训练家。$"
    .string ""

Route27_Text_CooltrainerfReenaSeen:
    .string "这一带的野生宝可梦\n可小看不得。$"
    .string ""

Route27_Text_CooltrainerfReenaBeaten:
    .string "哎呀！你太强了！$"

Route27_Text_CooltrainerfReenaAfter:
    .string "你虽然还是个孩子，\n但也小看不得。$"
    .string ""

Route27_Text_CooltrainerfMeganSeen:
    .string "很少有人会来这里。\p你是在独自修行吗？$"
    .string ""

Route27_Text_CooltrainerfMeganBeaten:
    .string "哦！你真的很强！$"

Route27_Text_CooltrainerfMeganAfter:
    .string "我在观察进化前和\n进化后的宝可梦。\p进化确实会让\n宝可梦变强。\p但进化后的形态\n学招式也更晚。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

Route27_Text_PsychicGilbertSeen:
    .string "什么都别说！\p让我猜猜你在想什么。\p嗯嗯嗯嗯……\p我知道了！你是在挑战\n宝可梦联盟！$"
    .string ""
    .string ""
    .string ""
    .string ""

Route27_Text_PsychicGilbertBeaten:
    .string "你太强了！$"

Route27_Text_PsychicGilbertAfter:
    .string "凭你的实力，在联盟\n也会有好成绩。\p我的预感是这么说的。$"
    .string ""
    .string ""

Route27_Text_BirdKeeperJoseSeen:
    .string "啾！啾！啾啾！$"

Route27_Text_BirdKeeperJoseBeaten:
    .string "啾！$"

Route27_Text_BirdKeeperJoseAfter:
    .string "像我这样的驱鸟使，会模仿\n鸟叫来命令宝可梦。$"
    .string ""

TohjoFalls_Text_Sign:
    .string "都城瀑布\p通往石英高原的道路！$"
    .string ""

Route27_Text_FisherScottSeen:
    .string "我今天状态绝佳！\p感觉连联盟冠军\n都能踢飞！$"
    .string ""
    .string ""

Route27_Text_FisherScottBeaten:
    .string "不行！这场不算！$"

Route27_Text_FisherScottAfter:
    .string "就像钓鱼一样，\n宝可梦的事，一放弃就完了。$"
    .string ""

Route27_RouteExpert::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE27_EXPERT, Route27_RouteExpert_2
	msgbox Route27_RouteExpert_Text_1
	goto_if_set FLAG_ROUTE27_EXPERT_QUALIFIED, Route27_RouteExpert_5
	checktrainerflag TRAINER_BLAKE
	goto_if 1, Route27_RouteExpert_9
Route27_RouteExpert_4:
	release
	end

Route27_RouteExpert_2:
	setflag FLAG_ROUTE27_EXPERT_QUALIFIED
	msgbox Route27_RouteExpert_Text_0
	release
	end

Route27_RouteExpert_5:
	setflag FLAG_ROUTE27_EXPERT_QUALIFIED
	playse SE_PIN
	applymovement LOCALID_ROUTE27_EXPERT, Common_Movement_ExclamationMark
	waitse
	msgbox Route27_RouteExpert_Text_2
	trainerbattle_no_intro TRAINER_CHOICE_BAND_EXPERT, Route27_RouteExpert_Text_3
	msgbox Route27_RouteExpert_Text_4
	giveitem ITEM_CHOICE_BAND
	setflag FLAG_ROUTE27_EXPERT
	addvar VAR_ROUTE_EXPERTS_DEFEATED, 1
	special Achievement_CheckAll
	msgbox Route27_RouteExpert_Text_0
	goto Route27_RouteExpert_4

Route27_RouteExpert_8:
	checktrainerflag TRAINER_REENA
	goto_if 1, Route27_RouteExpert_13
	goto Route27_RouteExpert_4

Route27_RouteExpert_9:
	checktrainerflag TRAINER_BRIAN
	goto_if 1, Route27_RouteExpert_8
	goto Route27_RouteExpert_4

Route27_RouteExpert_12:
	checktrainerflag TRAINER_GILBERT
	goto_if 1, Route27_RouteExpert_17
	goto Route27_RouteExpert_4

Route27_RouteExpert_13:
	checktrainerflag TRAINER_MEGAN
	goto_if 1, Route27_RouteExpert_12
	goto Route27_RouteExpert_4

Route27_RouteExpert_16:
	checktrainerflag TRAINER_SCOTT
	goto_if 1, Route27_RouteExpert_21
	goto Route27_RouteExpert_4

Route27_RouteExpert_17:
	checktrainerflag TRAINER_JOSE
	goto_if 1, Route27_RouteExpert_16
	goto Route27_RouteExpert_4

Route27_RouteExpert_20:
	checktrainerflag TRAINER_GAVEN
	goto_if 1, Route27_RouteExpert_25
	goto Route27_RouteExpert_4

Route27_RouteExpert_21:
	checktrainerflag TRAINER_JAKE
	goto_if 1, Route27_RouteExpert_20
	goto Route27_RouteExpert_4

Route27_RouteExpert_24:
	checktrainerflag TRAINER_BETH
	goto_if 1, Route27_RouteExpert_28
	goto Route27_RouteExpert_4

Route27_RouteExpert_25:
	checktrainerflag TRAINER_JOYCE
	goto_if 1, Route27_RouteExpert_24
	goto Route27_RouteExpert_4

Route27_RouteExpert_28:
	checktrainerflag TRAINER_RICHARD
	goto_if 1, Route27_RouteExpert_5
	goto Route27_RouteExpert_4


Route27_RouteExpert_Text_0:
	.string "讲究道具会锁定一个招式，\n但会以大幅提升战斗力\l来弥补这一代价。$"

Route27_RouteExpert_Text_1:
	.string "强大的四天王\n就在前方这段最后的路上了。\p在这里，你只会遇到城都\n最有实力、渴望挑战的\l训练家们。\p如果你能战胜他们所有人，\n再来找我，我会给你\l最后一次考验。$"

Route27_RouteExpert_Text_2:
	.string "你闯过了这条长路上的\n每一道关卡。现在就让我看看，\l你究竟有没有资格\l挑战四天王！$"

Route27_RouteExpert_Text_3:
	.string "如今再没有什么能阻挡你了。$"

Route27_RouteExpert_Text_4:
	.string "你的选择无可挑剔，\n看得出是发自本心。收下它，\l让它增强你最强的攻击。$"
