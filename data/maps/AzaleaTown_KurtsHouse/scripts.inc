

AzaleaTown_KurtsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_KurtsHouse_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_OnTransition
	.byte 0

AzaleaTown_KurtsHouse_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup
	end

AzaleaTown_KurtsHouse_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWell
	.2byte 0

AzaleaTown_KurtsHouse_EventScript_KurtBefore::
	lock
	faceplayer
	msgbox KurtsHouse_Text_KurtMakingBallsMustWait, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_PlayerMove
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	setvar VAR_AZALEA_TOWN_STATE, 2
	release
	end

AzaleaTown_KurtsHouse_EventScript_PlayerMove::
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_KurtsHouse_Movement_Player
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_KURT_2, AzaleaTown_KurtsHouse_EventScript_Girl2
	goto_if_set FLAG_HIDE_KURT_1, AzaleaTown_KurtsHouse_EventScript_Girl3
	msgbox KurtsHouse_Text_GranddaughterSlowpokeGone, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl2::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 4, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_Girl5
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_Girl5

	msgbox KurtsHouse_Text_GranddaughterDad, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl3::
	msgbox KurtsHouse_Text_GranddaughterLonely, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl4::
	msgbox KurtsHouse_Text_GranddaughterSlowpokeBack, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_Girl5::
	msgbox KurtsHouse_Text_GranddaughterSound, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup::
	setobjectmovementtype LOCALID_AZALEA_TOWN_KURT, MOVEMENT_TYPE_FACE_DOWN
	end

AzaleaTown_KurtsHouse_EventScript_ReturnFromWell::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox KurtsHouse_Text_KurtHonoredToMakeBalls, MSGBOX_DEFAULT
	giveitem ITEM_FAST_BALL
	setflag FLAG_DAILY_KURT_FREE_BALLS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call KurtMakesBallsDaily
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	setvar VAR_AZALEA_TOWN_STATE, 4
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall::
	checkitem ITEM_GS_BALL
	goto_if_eq VAR_RESULT, TRUE, AzaleaTown_KurtsHouse_EventScript_KurtGsBall
	return

AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_KurtGsBall2
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_KurtGsBall3
	call_if_unset FLAG_CAUGHT_CELEBI, AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall
	goto KurtDaily

	AzaleaTown_KurtsHouse_EventScript_Kurt2::
		multichoice 20, 0, MULTI_KURT_BALLS, FALSE
		switch VAR_RESULT
		case 0, AzaleaTown_KurtsHouse_EventScript_Kurt_Love
		case 1, AzaleaTown_KurtsHouse_EventScript_Kurt_Lure
		case 2, AzaleaTown_KurtsHouse_EventScript_Kurt_Friend
		case 3, AzaleaTown_KurtsHouse_EventScript_Kurt_Heavy
		case 4, AzaleaTown_KurtsHouse_EventScript_Kurt_Moon
		case 5, AzaleaTown_KurtsHouse_EventScript_Kurt_Fast
		case 6, AzaleaTown_KurtsHouse_EventScript_Kurt_Level
		case 7, AzaleaTown_KurtsHouse_EventScript_KurtCancel
		case MULTI_B_PRESSED, AzaleaTown_KurtsHouse_EventScript_KurtCancel
		closemessage

AzaleaTown_KurtsHouse_EventScript_Kurt_Love::
	closemessage
	bufferitemname STR_VAR_1, ITEM_PECHA_BERRY
	checkitem ITEM_PECHA_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_LOVE_BALL, 5
	removeitem ITEM_PECHA_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Lure::
	closemessage
	bufferitemname STR_VAR_1, ITEM_RAWST_BERRY
	checkitem ITEM_RAWST_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_LURE_BALL, 5
	removeitem ITEM_RAWST_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Friend::
	closemessage
	bufferitemname STR_VAR_1, ITEM_CHERI_BERRY
	checkitem ITEM_CHERI_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_FRIEND_BALL, 5
	removeitem ITEM_CHERI_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Heavy::
	closemessage
	bufferitemname STR_VAR_1, ITEM_ORAN_BERRY
	checkitem ITEM_ORAN_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_HEAVY_BALL, 5
	removeitem ITEM_ORAN_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Moon::
	closemessage
	bufferitemname STR_VAR_1, ITEM_CHESTO_BERRY
	checkitem ITEM_CHESTO_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_MOON_BALL, 5
	removeitem ITEM_CHESTO_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Fast::
	closemessage
	bufferitemname STR_VAR_1, ITEM_ASPEAR_BERRY
	checkitem ITEM_ASPEAR_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_FAST_BALL, 5
	removeitem ITEM_ASPEAR_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end
AzaleaTown_KurtsHouse_EventScript_Kurt_Level::
	closemessage
	bufferitemname STR_VAR_1, ITEM_PERSIM_BERRY
	checkitem ITEM_PERSIM_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_LEVEL_BALL, 5
	removeitem ITEM_PERSIM_BERRY, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_DontHaveBerry::
	msgbox KurtsHouse_Text_KurtThatsALetdown, MSGBOX_DEFAULT
	closemessage
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
	release
	end
	
AzaleaTown_KurtsHouse_EventScript_KurtCancel::
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall::
	msgbox KurtsHouse_Text_KurtWhatIsThat, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GS_BALL
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtThisBallStartedToShake, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_AZALEA_TOWN_KURT, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	waitse
	playse SE_M_PETAL_DANCE
	waitse
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Look_Around
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTownKurt_Movement_Look_Around
	waitmovement 0
	waitmovement 0
AzaleaTown_KurtsHouse_EventScript_KurtGsBall2::
	msgbox KurtsHouse_Text_Kurt_Whatwasthat, MSGBOX_DEFAULT
	setvar VAR_AZALEA_TOWN_STATE, 8
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall3::
	msgbox KurtsHouse_Text_Forest, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox KurtsHouse_Text_BallAnyway, MSGBOX_DEFAULT
	closemessage
	goto KurtDaily
	release
	end
KurtsHouse_Text_BallAnyway:
	.string "话说回来，要我给您做些球吗？$"

AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox KurtsHouse_Text_OakPhoto, MSGBOX_SIGN
	closemessage
	end

AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox KurtsHouse_Text_CelebiStatue, MSGBOX_SIGN
	closemessage
	end

AzaleaTownKurt_Movement_Look_Around:
	face_left
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_down
	delay_8
	face_left
	step_end

AzaleaTownKurt_Movement_Making_Ball:
	face_up
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	step_end

AzaleaTown_KurtsHouse_Movement_Player:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

AzaleaTown_KurtsHouse_Movement_KurtWalkDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

KurtsHouse_Text_KurtGetStarted:
	.string "钢铁：我这就开工！$"

KurtsHouse_Text_KurtMakingBallsMustWait:
	.string "嗯？你是谁？\p{PLAYER}啊。你想让我\n给你做些球？\p抱歉，那得先等等。\p你知道火箭队吗？\n啊，不知道也没关系。\p我来告诉你。\p火箭队是一群利用宝可梦\n干坏事的邪恶团伙。\p听说他们三年前\n就已经解散了。\p总之，他们现在就在井里，\n砍下呆呆兽的尾巴拿去卖！\p所以我要去给他们\n一点苦头尝尝！\p等着我，呆呆兽！\n老钢铁这就来救你们！$"
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

KurtsHouse_Text_KurtHonoredToMakeBalls:
	.string "钢铁：嗨，{PLAYER}！\p你在井边干得\n真像个英雄。\p我喜欢你这种作风！\p能为像你这样的训练家做球，\n是我的荣幸。\p现在我手上只有这个，\n不过拿去吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

KurtsHouse_Text_KurtBallsFromApricorns:
	.string "钢铁：我用树果做球。\p从树上收集树果，\n5个一批拿来给我。\p我就用它们给你做球。$"
	.string ""
	.string ""
	.string ""

KurtsHouse_Text_KurtAskYouHaveAnApricorn:
	.string "钢铁：你带了5个树果给我？\p好！我这就把它们做成球。$"
	.string ""

KurtsHouse_Text_KurtThatsALetdown:
	.string "钢铁：我没看到5个{STR_VAR_1}！$"

KurtsHouse_Text_KurtJustFinishedYourBall:
	.string "钢铁：啊，{PLAYER}！\p你的球刚做好。\n给你！$"
	.string ""

KurtsHouse_Text_KurtTurnedOutGreat:
	.string "钢铁：做得真不错。\p拿它去抓宝可梦试试吧。$"
	.string ""

KurtsHouse_Text_KurtWhatIsThat:
	.string "这、这是什么？\p我从没见过这种东西。\p看起来像精灵球，\n但好像又不是。\p让我帮你检查一下吧。$"
	.string ""
	.string ""
	.string ""
	.string ""

KurtsHouse_Text_KurtImCheckingItNow:
	.string "我现在正在检查。$"

KurtsHouse_Text_KurtAhHaISee:
	.string "啊哈！我明白了！那么……$"

KurtsHouse_Text_KurtThisBallStartedToShake:
	.string "{PLAYER}！\p我检查的时候，这个球\n突然开始摇晃了。\p这里面一定有什么名堂！$"
	.string ""
	.string ""
	.string ""

KurtsHouse_Text_Kurt_Whatwasthat:
	.string "那是什么声音？！\p我们出去看看吧！$"
	.string ""

KurtsHouse_Text_GranddaughterSlowpokeGone:
	.string "呆呆兽不见了……\n是被坏人抓走了吗？$"
	.string ""

KurtsHouse_Text_GranddaughterLonely:
	.string "爷爷走了……我好孤单……$"

KurtsHouse_Text_GranddaughterSlowpokeBack:
	.string "爸爸送我的那只呆呆兽回来了！\p它的尾巴也正在长回来！$"
	.string ""

KurtsHouse_Text_GranddaughterDad:
	.string "爸爸在西尔佛公司上班，\n研究精灵球。\p我得和爷爷还有呆呆兽\n一起看家。$"
	.string ""
	.string ""
	.string ""

KurtsHouse_Text_GranddaughterHelp:
	.string "现在我也可以帮爷爷的忙了！\p我们会为你做好球的，\n请等着吧！$"
	.string ""
	.string ""

KurtsHouse_Text_GranddaughterFun:
	.string "做球真好玩！$"

KurtsHouse_Text_GranddaughterSound:
	.string "刚才那个声音是从\n栎树林传来的吗？？？？$"
	.string ""

KurtsHouse_Text_Forest:
	.string "你去栎树林看过了吗？\n那里好像很不安宁。$"
	.string ""

KurtsHouse_Text_Slowpoke:
	.string "呆呆兽：……哈欠？$"

KurtsHouse_Text_OakPhoto:
	.string "……年轻时候的大木博士？$"

KurtsHouse_Text_CelebiStatue:
	.string "这是森林守护神的\n雕像。$"
	.string ""

KurtMakesBallsDaily::
	msgbox KurtMakesBallsDaily_Text_0
	closemessage
	return


KurtDaily::
	goto_if_set FLAG_DAILY_KURT_FREE_BALLS, KurtDaily_2
	msgbox KurtDaily_Text_1
	compare VAR_KURT_PROFICIENCY, 4
	goto_if_ge KurtDaily_5
	random 15
KurtDaily_4:
	switch VAR_RESULT
	case 0, KurtDaily_10
	case 1, KurtDaily_11
	case 2, KurtDaily_12
	case 3, KurtDaily_13
	case 4, KurtDaily_14
	case 5, KurtDaily_15
	case 6, KurtDaily_16
	case 7, KurtDaily_17
	case 8, KurtDaily_18
	case 9, KurtDaily_19
	case 10, KurtDaily_20
	case 11, KurtDaily_21
	case 12, KurtDaily_22
	case 13, KurtDaily_23
	case 14, KurtDaily_24
	case 15, KurtDaily_25
KurtDaily_8:
	setflag FLAG_DAILY_KURT_FREE_BALLS
	compare VAR_KURT_PROFICIENCY, 255
	goto_if_lt KurtDaily_27
KurtDaily_26:
	release
	end

KurtDaily_2:
	msgbox KurtDaily_Text_0
	release
	end

KurtDaily_5:
	random 16
	goto KurtDaily_4

KurtDaily_10:
	giveitem ITEM_LUXURY_BALL, 5
	goto KurtDaily_8

KurtDaily_11:
	giveitem ITEM_LEVEL_BALL, 5
	goto KurtDaily_8

KurtDaily_12:
	giveitem ITEM_LURE_BALL, 5
	goto KurtDaily_8

KurtDaily_13:
	giveitem ITEM_MOON_BALL, 5
	goto KurtDaily_8

KurtDaily_14:
	giveitem ITEM_FRIEND_BALL, 5
	goto KurtDaily_8

KurtDaily_15:
	giveitem ITEM_LOVE_BALL, 5
	goto KurtDaily_8

KurtDaily_16:
	giveitem ITEM_FAST_BALL, 5
	goto KurtDaily_8

KurtDaily_17:
	giveitem ITEM_HEAVY_BALL, 5
	goto KurtDaily_8

KurtDaily_18:
	giveitem ITEM_DREAM_BALL, 5
	goto KurtDaily_8

KurtDaily_19:
	giveitem ITEM_SAFARI_BALL, 5
	goto KurtDaily_8

KurtDaily_20:
	giveitem ITEM_SPORT_BALL, 5
	goto KurtDaily_8

KurtDaily_21:
	giveitem ITEM_PARK_BALL, 5
	goto KurtDaily_8

KurtDaily_22:
	giveitem ITEM_BEAST_BALL, 5
	goto KurtDaily_8

KurtDaily_23:
	giveitem ITEM_CHERISH_BALL, 5
	goto KurtDaily_8

KurtDaily_24:
	giveitem ITEM_STRANGE_BALL, 5
	goto KurtDaily_8

KurtDaily_25:
	msgbox KurtDaily_Text_2
	giveitem ITEM_MASTER_BALL, 1
	setflag FLAG_KURT_CRAFTED_MASTER_BALL
	special Achievement_CheckAll
	goto KurtDaily_8

KurtDaily_27:
	addvar VAR_KURT_PROFICIENCY, 1
	goto KurtDaily_26


KurtMakesBallsDaily_Text_0:
	.string "我每天多做出来的精灵球\n都会送给你，记得常来啊！$"

KurtDaily_Text_0:
	.string "等我再多做几个，\n明天再来吧。$"

KurtDaily_Text_1:
	.string "这是今天给你的份。\n明天再来拿吧。$"

KurtDaily_Text_2:
	.string "这回可是杰作！\p我都不敢相信\n这是我自己做出来的。$"
