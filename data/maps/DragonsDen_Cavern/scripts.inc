
.set LOCALID_DRAGONSDEN2_CLAIR, 5
.set LOCALID_DEN_CLAIR, 35

DragonsDen_Cavern_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
    .string "{PLAYER}……你来了啊。\p要是觉得自己跟得上我，\n就到金黄市的\l格斗道场来吧。$"
	.string ""
	.string ""
	.string ""



DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	applymovement LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	approachobject LOCALID_DRAGONSDEN2_CLAIR, LOCALID_PLAYER, DIR_EAST, DIR_WEST
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_WEST
	call DragonsDen_Cavern_EventScript_Clair
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	delay 45
	fadescreen FADE_FROM_BLACK
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Cavern_Text_ClairGiveDragonclaw, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_CLAW
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Cavern_Text_ClairDescribeDragonclaw, MSGBOX_DEFAULT
	closemessage
	delay 30
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_ClairGiveDragonclaw:
    .string "小椿：等一下！\p这次的事，对不起。\n这个你拿着，就当是我的赔礼。$"
	.string ""
    .string ""

DragonsDen_Cavern_Text_ClairDescribeDragonclaw:
    .string "那里面是龙爪。\p不，这跟我的指甲\n一点关系也没有。\p你要是不想要，\n不拿也行。$"
    .string ""
    .string ""
    .string ""
    .string ""

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
    .string "怎么了？\n你不是要去\l宝可梦联盟吗？\p等你当上冠军以后，\n想和哪位道馆馆主再战\l都可以。\p去宝可梦联盟吧。\p你知道该怎么去吗？\p从这里先去若叶镇。\p再用冲浪往东前往宝可梦联盟。\p那条路非常艰险。\p你可不许在宝可梦联盟\n输掉！\p要是输了，输给你的我\n心里只会更不是滋味！\p拿出你的全部实力来吧。$"
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

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_Text_DragonShrineSign:
    .string "龙之祠堂\p这座祠堂纪念着龙宝可梦，\p相传它们曾经栖息在\n龙穴之中。$"
    .string ""
    .string ""
    .string ""
    .string ""

DragonsDen_Cavern_Text_SilverTraining1:
    .string "……\n什么？{PLAYER}？\p……不，我现在不会和你对战……\p我的宝可梦\n还没强到能打赢你。\p现在不能太勉强它们。\p要成为最强的宝可梦训练家，\n我就必须严格要求自己……$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

DragonsDen_Cavern_Text_SilverTraining2:
    .string "……\p呼……\p学着别来碍我的事……$"
    .string ""
    .string ""

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
    .string "你！竟敢擅自闯进来！$"
    .string ""

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
    .string "好、好强！$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
    .string "前面的祠堂里，住着我们\n驭龙一族的长老。\p不许你随便进去！$"
    .string ""
    .string ""

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
    .string "你不该进到这里来！$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
    .string "哎呀，我输了！$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
    .string "再过不久，我就能得到\n长老的许可，可以使用龙了。\p到那时，\n我要成为出色的驭龙训练家，\l赢得长老的认可。$"
    .string ""
    .string ""
    .string ""
    .string ""

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
    .string "是我们不认识的陌生人。$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
    .string "好痛哦。$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
    .string "简直就像在和\n阿渡对战一样。$"
    .string ""

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
    .string "你是谁呀？$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
    .string "坏蛋。$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
    .string "我们要去告状。\p长老会生你的气的。$"
    .string ""

DragonsDen_ClairRematch::
	lock
	faceplayer
	msgbox DragonsDen_ClairRematch_Text_0
	msgbox DragonsDen_ClairRematch_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq DragonsDen_ClairRematch_2
DragonsDen_ClairRematch_1:
	release
	end

DragonsDen_ClairRematch_2:
	trainerbattle_no_intro TRAINER_CLAIR_2, DragonsDen_ClairRematch_Text_2
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_ClairRematch_Text_3
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEN_CLAIR
	setflag FLAG_CLAIR_ON_TRIP
	removeobject LOCALID_CLAIR_REMATCH
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	goto DragonsDen_ClairRematch_1


DragonsDen_ClairRematch_Text_0:
	.string "嘿，{PLAYER}。\n我听阿渡说，你当上了新的冠军。\l看来长老们说得没错，\l我只是被自己的傲慢蒙蔽了双眼。\l对不起。$"

DragonsDen_ClairRematch_Text_1:
	.string "能在这里再和我对战一次吗？\n我想和新冠军\l毫无顾忌地较量一场。$"

DragonsDen_ClairRematch_Text_2:
	.string "这么短的时间里，\n竟能变强这么多，真不可思议。$"

DragonsDen_ClairRematch_Text_3:
	.string "想要超越你，甚至超越阿渡，\n我还有很长的路要走。\l我打算过不久就出去旅行，\l到各地去看看，\l希望能向形形色色的人学习。\l然后带着学到的一切再来挑战你。\l谢谢你在对战中给我上的这一课，\l我不会忘记的。$"
