
.set LOCALID_DIRECTOR_OFFICE, 1
.set LOCALID_GOLDENROD_ARCHER, 2
.set LOCALID_GOLDENROD_ARIANA, 3
.set LOCALID_PETREL_OFFICE, 4

GoldenrodCity_RadioTower_5F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

@ During Rocket Takeover, hide Petrel and show the Director (Petrel in disguise)
GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	@ After Rocket Takeover, this is the real Director
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	playse SE_SELECT
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
    removeobject LOCALID_RADIOTOWER_OAK
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

@ Modified in 1.2.2 to retroactively fix the Baoba Sequence Break on a 1.2.1 save file
GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	playse SE_SELECT
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorPath
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_DirectorDone::
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_DirectorWest::
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorWest, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "你、你！你是来救我的吗？$"

GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "怎么样？和你期待的一样吗？\p错！我是冒牌货！\p我假扮成真正的局长，\n是为了准备接管这里。\p你想知道我们把真正的\n局长藏在哪儿了吗？\p好啊，我这就告诉你。\n不过，你得先打赢我！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "好，好。我告诉你他在哪儿。$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "老大把局长关在了\n地下仓库里。\p就在地下通道的\n最深处。\p我是个好人，就给你\n去地下仓库用的\l地下钥匙吧。\p不过，我看你到不了那么远。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "老大把局长关在了\n地下仓库里。\p就在地下通道的\n最深处。\p用那把地下钥匙，就能\n进到地下仓库。\p不过，我看你到不了那么远。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2 GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_HIDE_RADIOF5DUDE
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "还记得卡吉镇基地里的\n那个我吗？\p老大训了我一顿，可我变强了。\p上次是我输了，这次不会了。$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "怎么可能！\p我已经拼尽全力，\n却还是输了……\p坂木大人，真是对不起……$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "{PLAYER}，是吧？\p像你这种小鬼，是不会懂\n火箭队的伟大的。\p真可惜。我其实很欣赏\n你的实力。$"
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "哦？你竟然能走到这里？\p看来你是个相当厉害的\n训练家。\p我们打算占领这座广播站，\n宣布我们的复活。\p这样一来，在某个地方独自\n修行的老大坂木就会回来。\p我们要夺回昔日的荣光……\p我绝不允许你妨碍\n我们周密的计划！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "不！坂木大人，请原谅我！$"

GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "怎么会这样？\p我们的梦想全都落空了。\p看来我终究还是力不从心。\p就像坂木大人曾经做过的那样，\n我今日就在此解散火箭队。\p永别了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "局长：{PLAYER}，谢谢你！\p你的英勇行动，拯救了\n全国的宝可梦。\p虽然不算什么，\n还请收下这个。$"
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_DirectorThanksAgain:
	.string "局长：{PLAYER}，再次谢谢你！\p刚才飞过的那只大翅膀\n宝可梦提醒了我，我要为你的\l英勇行动准备一份谢礼。\p虽然不算什么，\n还请收下这个。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "这里以前有一座塔，\n就在满金市。\p但那座塔又旧又破。\p于是我们就把它改建成了\n播音塔。\p那片羽毛，就是施工时\n挖出来的。\p听说在很久以前，满金\n生活着各种各样的宝可梦。\p说不定……\p那片羽毛和缘朱市的\n铃铛塔有些什么渊源……\p好，我还是回局长室去吧。$"
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

@ 1.2.1 Sequence Break version - slightly different text
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation2:
	.string "这里以前有一座塔，\n就在满金市。\p但那座塔又旧又破。\p于是我们就把它改建成了\n播音塔。\p那片羽毛，就是施工时\n挖出来的。\p听说在很久以前，满金\n生活着各种各样的宝可梦。\p说不定……\p那片羽毛和缘朱市的\n铃铛塔有些什么渊源……$"
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

GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "这里以前有一座塔，\n就在满金市。\p但那座塔又旧又破。\p于是我们就把它改建成了\n播音塔。\p那片羽毛，就是施工时\n挖出来的。\p听说在很久以前，满金\n生活着各种各样的宝可梦。\p说不定……\p那片羽毛和湛蓝市附近的\n漩涡岛有些什么渊源……\p好，我还是回局长室去吧。$"
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

@ 1.2.1 Sequence Break version - slightly different text
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation2:
	.string "这里以前有一座塔，\n就在满金市。\p但那座塔又旧又破。\p于是我们就把它改建成了\n播音塔。\p那片羽毛，就是施工时\n挖出来的。\p听说在很久以前，满金\n生活着各种各样的宝可梦。\p说不定……\p那片羽毛和湛蓝市附近的\n漩涡岛有些什么渊源……$"
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

GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "啊！\p对了，我想起来了……\p我给你的那片羽毛……\n我觉得它和\l传说的宝可梦有关。\p不过！只有那片羽毛，\n传说的宝可梦是不会出现的……\p据说还需要别的东西……\n好像是这么说的。\p那到底是什么来着……\p我记不起来了。$"
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

GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "你在期待什么？\n这就叫击掌奇袭。\p这次我是真的得回局长室了。\n再见啦！$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "局长：你好，{PLAYER}！\p你知道吗，我很喜欢宝可梦。\p我建这座播音塔，就是为了\n表达我对宝可梦的喜爱。\p要是大家能喜欢我们的节目，\n那就太好了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

@ 1.2.1 Sequence Break - Directs player toward Baoba
GoldenrodCity_RadioTower_5F_Text_DirectorWest:
	.string "局长：你好，{PLAYER}！\p你看到刚才飞过去的\n那只大翅膀宝可梦了吗？\p它成了全城的话题！\n还是该说，是播音塔的话题？\p它好像是往西飞的，\n朝39号道路的方向去了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "靖史：你听我们的音乐吗？$"

GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "5楼　局长室$"

GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "5楼　第1演播室$"

OakRadioTowerF5::
	moveobjecttocoords OBJ_EVENT_ID_PLAYER, 28, 11, DIR_NORTH
	waitmovement 0
	playbgm MUS_HG_OAK, TRUE
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 28, 10, DIR_SOUTH
	waitmovement 0
	msgbox OakRadioTowerF5_Text_0
	msgbox OakRadioTowerF5_Text_1
	giveitem ITEM_MEGA_RING
	clearflag FLAG_SOUTHPASSAGE_ARIANA
	msgbox OakRadioTowerF5_Text_2
	msgbox OakRadioTowerF5_Text_3
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_RADIOTOWER_OAK
	fadedefaultbgm
	delay 100
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


RadioTower_5F_Archer::
	lock
	faceplayer
	msgbox RadioTower_5F_Archer_Text_0
	trainerbattle_no_intro TRAINER_ARCHER, RadioTower_5F_Archer_Text_1
	createfieldmugshot MUGSHOT_ARCHER
	msgbox RadioTower_5F_Archer_Text_2
	closemessage
	fadescreen FADE_TO_BLACK
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_F5_DIRECTOR_2
	addobject LOCALID_RADIOTOWER_OAK
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 60
	fadescreen FADE_FROM_BLACK
	approachobject LOCALID_F5_DIRECTOR_2, LOCALID_PLAYER, DIR_WEST, DIR_EAST
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_EAST
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox RadioTower_5F_Archer_Text_3
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, RadioTower_5F_Archer_Text_4, RadioTower_5F_Archer_Text_5
	switch VAR_RESULT
	case 0, RadioTower_5F_Archer_3
	case 1, RadioTower_5F_Archer_4
RadioTower_5F_Archer_1:
	msgbox RadioTower_5F_Archer_Text_8
	closemessage
	applymovement LOCALID_F5_DIRECTOR_2, RadioTower_5F_Archer_Movement_0
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_F5_DIRECTOR_2, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_F5_DIRECTOR_2, DIR_WEST
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox RadioTower_5F_Archer_Text_9
	closemessage
	moveobjecttocoords LOCALID_F5_DIRECTOR_2, 29, 5, DIR_NORTH
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_F5_DIRECTOR_2
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	moveobjecttocoords OBJ_EVENT_ID_PLAYER, 28, 11, DIR_NORTH
	waitmovement 0
	playbgm MUS_HG_OAK, TRUE
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 28, 10, DIR_SOUTH
	waitmovement 0
	createfieldmugshot MUGSHOT_OAK
	msgbox OakRadioTowerF5_Text_0
	msgbox OakRadioTowerF5_Text_1
	giveitem ITEM_MEGA_RING
	createfieldmugshot MUGSHOT_OAK
	msgbox RadioTower_5F_Archer_Text_10
	msgbox RadioTower_5F_Archer_Text_11
	closemessage
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 24, 5, DIR_WEST
	waitmovement 0
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	setflag FLAG_ROCKET_TAKEOVER_CAP
	playse SE_EXIT
	removeobject LOCALID_RADIOTOWER_OAK
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

RadioTower_5F_Archer_3:
	setvar VAR_LUGIA_OR_HOOH, 2
	giveitem ITEM_RAINBOW_WING
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox RadioTower_5F_Archer_Text_6
	goto RadioTower_5F_Archer_1

RadioTower_5F_Archer_4:
	setvar VAR_LUGIA_OR_HOOH, 1
	giveitem ITEM_SILVER_WING
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox RadioTower_5F_Archer_Text_7
	goto RadioTower_5F_Archer_1


GoldenrodCity_RadioTower_5F_EventScript_DirectorPath::
	goto_if_set FLAG_IS_CHAMPION, GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_2
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorDone
GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_1:
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_2:
	goto_if_set FLAG_BEAT_DIRECTOR, GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_5
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_0
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_1
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_2
	trainerbattle_no_intro TRAINER_DIRECTOR, GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_3
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_4
	compare VAR_LUGIA_OR_HOOH, 1
	goto_if_eq GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_9
	giveitem ITEM_SILVER_WING
	setvar VAR_COMPLETED_LUGIA, 4
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_8:
	setflag FLAG_BEAT_DIRECTOR
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_5
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_5:
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorDone
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_1

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_9:
	giveitem ITEM_RAINBOW_WING
	setvar VAR_COMPLETED_HO_OH, 4
	setflag FLAG_HIDE_TINTOWER_GUARD
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_8


DirectorGotSilver::
	msgbox DirectorGotSilver_Text_0
	release
	end


DirectorGotRainbow::
	msgbox DirectorGotRainbow_Text_0
	release
	end


RadioTower_5F_Archer_Movement_0:
	walk_right
	walk_right
	step_end

OakRadioTowerF5_Text_0:
	.string "{PLAYER}！你击溃了火箭队，\n"
	.string "真是创造了奇迹！$"

OakRadioTowerF5_Text_1:
	.string "把宝可梦图鉴托付给你，\n"
	.string "果然是没错的。这个给你，\l"
	.string "我觉得你完全配得上。$"

OakRadioTowerF5_Text_2:
	.string "这是超级环。只要和超级石\n"
	.string "配合使用，训练家和宝可梦\l"
	.string "之间的羁绊就能完全显现。\l"
	.string "我相信你一定能做到。$"

OakRadioTowerF5_Text_3:
	.string "现在我该回关都去了。\n"
	.string "希望你以后能来真新镇看看！\l"
	.string "替我向空木博士问好。$"

RadioTower_5F_Archer_Text_0:
	.string "阿波罗：哦？你竟然能走到\n这一步……？\p看来你是个相当厉害的\n训练家。\p我们打算占领这座\n播音塔，正式宣布\l我们的复活。\p这样，在某个地方独自修行\n的老大坂木就会回来。\p我们要夺回昔日的\n荣光……\p我绝不允许你妨碍\n我们周密的计划！$"

RadioTower_5F_Archer_Text_1:
	.string "不！坂木大人，请原谅我！$"

RadioTower_5F_Archer_Text_2:
	.string "阿波罗：怎么会这样……？\p看来我终究还是力不从心……\n不过，只是还不到时候。\p这次我们先撤退。但你要知道，\n火箭队在这个地区的根，\l比你想象的埋得更深。\p我们还会再见的，{PLAYER}。\n再会了……$"

RadioTower_5F_Archer_Text_3:
	.string "局长：哦……\p你已经把他们打倒了？\n谢谢你！\p你的英勇行动，拯救了\n全国的宝可梦。\p你的行动理应得到回报！\p我让你从我们珍藏的\n宝物里挑一件！\p好，挑一件吧！$"

RadioTower_5F_Archer_Text_4:
	.string "虹色之羽$"

RadioTower_5F_Archer_Text_5:
	.string "银色之羽$"

RadioTower_5F_Archer_Text_6:
	.string "这里以前有一座塔。\p这座塔改建为播音塔时，\n那片虹色之羽，\l就是在塔顶被发现的。\p我从湛蓝市的朋友那里听说，\n只要带着虹色之羽，\l就能登上缘朱市的\l铃铛塔。$"

RadioTower_5F_Archer_Text_7:
	.string "这里以前有一座塔。\p这座塔改建为播音塔时，\n那片银色之羽，\l就是在塔顶被发现的。\p我从湛蓝市的朋友那里听说，\n只要带着银色之羽，\l就能下到漩涡岛的\l洞窟里去。$"

RadioTower_5F_Archer_Text_8:
	.string "我得回局长室去了。\n再见！$"

RadioTower_5F_Archer_Text_9:
	.string "对了，差点儿忘了！\p据我在湛蓝市的朋友说，\n只去我刚才说的那个地方，\l传说的宝可梦是不会出现的。\l好像还需要别的什么东西……\l就是这么说的。\p那到底是什么来着……\n我记不起来了。$"

RadioTower_5F_Archer_Text_10:
	.string "这是超级环。\p只要和超级石配合，\n训练家和宝可梦之间的羁绊\l就能完全显现。\p我相信你一定能做到。$"

RadioTower_5F_Archer_Text_11:
	.string "现在我该回去工作了。\n"
	.string "希望你下次也收听我的广播节目！$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_0:
	.string "啊，{PLAYER}！\p听说你当上了冠军，\n恭喜你！$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_1:
	.string "我猜，你是为另一片羽毛\n来的吧？呵呵呵！\p我可以把它交给你，\n只要你答应我一个条件。\p我一直很想好好打一场，\n已经等很久了。\p火箭队偷袭我的时候，\n我身边一只宝可梦都没有。\p要是我的宝贝队伍在，\n他们根本不是对手。$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_2:
	.string "就让你见识一下，前四天王\n的实力！呵呵呵！$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_3:
	.string "真是怀念的感觉！$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_4:
	.string "你真是远超城都其他\n训练家的存在，{PLAYER}！\p我很乐意把这个\n交给你。$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_5:
	.string "去吧，去续写你的传说吧！$"

DirectorGotSilver_Text_0:
	.string "你选择了银色之羽$"

DirectorGotRainbow_Text_0:
	.string "你选择了虹色之羽$"
