SaffronCity_FightingDojoVIP_MapScripts::
	.byte 0

SaffronCity_FightingDojoVIP_EventScript_Declined::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Falkner_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_FALKNER_2, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BUGSY_2, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Whitney_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_WHITNEY_2, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Morty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MORTY_2, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Chuck_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CHUCK_2, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JASMINE_2, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Pryce_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_PRYCE_2, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Clair_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CLAIR_2, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Brock_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BROCK, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Misty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MISTY, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Surge_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_LTSURGE, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Erika_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_ERIKA, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Janine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JANINE, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_SABRINA, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blaine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLAINE, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blue_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLUE, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

@===============MONS===============================================================================================================

SaffronCity_FightingDojoVIP_EventScript_Scizor::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SCIZOR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Scizor, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Scizor:
	.string "巨钳螳螂：钳——！$"

SaffronCity_FightingDojoVIP_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Miltank:
	.string "大奶罐：哞——！$"

SaffronCity_FightingDojoVIP_EventScript_Poliwhirl::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWHIRL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Poliwhirl, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Poliwhirl:
	.string "蚊香君：转转！$"

SaffronCity_FightingDojoVIP_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Dewgong:
	.string "白海狮：咕——！$"

SaffronCity_FightingDojoVIP_EventScript_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Steelix:
	.string "大钢蛇：嘎啊啊！$"

SaffronCity_FightingDojoVIP_EventScript_Kingdra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGDRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kingdra, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kingdra:
	.string "刺龙王：呜啦……$"

SaffronCity_FightingDojoVIP_EventScript_Onix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ONIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Onix, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Onix:
	.string "大岩蛇：岩——！$"

SaffronCity_FightingDojoVIP_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Starmie, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Starmie:
	.string "宝石海星：吓呀！$"

SaffronCity_FightingDojoVIP_EventScript_Victreebel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTREEBEL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Victreebel, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Victreebel:
	.string "大食花：咿——！$"

SaffronCity_FightingDojoVIP_EventScript_Muk::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Muk, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Muk:
	.string "臭臭泥：呜咕……$"

SaffronCity_FightingDojoVIP_EventScript_Kadabra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KADABRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kadabra, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kadabra:
	.string "勇基拉：勇基拉！$"

SaffronCity_FightingDojoVIP_EventScript_Magmar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGMAR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Magmar, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Magmar:
	.string "鸭嘴火兽：熔岩——！$"

SaffronCity_FightingDojoVIP_EventScript_Raichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Raichu, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Raichu:
	.string "雷丘：雷——丘！$"

SaffronCity_FightingDojoVIP_EventScript_Machamp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Machamp, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
BattleTower_Outside_MapScripts::
	.byte 0

BattleTower_Outside_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

BattleTower_Outside_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTower_Outside_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTower_Outside_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end



BattleTower_Outside_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleTower_Outside_EventScript_AlreadyMetLeftTutor
	msgbox BattleTower_Outside_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleTower_Outside_EventScript_ChooseLeftTutorMove
	end

BattleTower_Outside_EventScript_AlreadyMetLeftTutor::
	msgbox BattleTower_Outside_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleTower_Outside_EventScript_ChooseLeftTutorMove
	end

BattleTower_Outside_EventScript_ChooseLeftTutorMove::
	message BattleTower_Outside_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_Softboiled
	case 1, BattleTower_Outside_EventScript_SeismicToss
	case 2, BattleTower_Outside_EventScript_DreamEater
	case 3, BattleTower_Outside_EventScript_MegaPunch
	case 4, BattleTower_Outside_EventScript_MegaKick
	case 5, BattleTower_Outside_EventScript_BodySlam
	case 6, BattleTower_Outside_EventScript_RockSlide
	case 7, BattleTower_Outside_EventScript_Counter
	case 8, BattleTower_Outside_EventScript_ThunderWave
	case 9, BattleTower_Outside_EventScript_SwordsDance
	case 10, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_ChooseNewLeftTutorMove::
	message BattleTower_Outside_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_Softboiled
	case 1, BattleTower_Outside_EventScript_SeismicToss
	case 2, BattleTower_Outside_EventScript_DreamEater
	case 3, BattleTower_Outside_EventScript_MegaPunch
	case 4, BattleTower_Outside_EventScript_MegaKick
	case 5, BattleTower_Outside_EventScript_BodySlam
	case 6, BattleTower_Outside_EventScript_RockSlide
	case 7, BattleTower_Outside_EventScript_Counter
	case 8, BattleTower_Outside_EventScript_ThunderWave
	case 9, BattleTower_Outside_EventScript_SwordsDance
	case 10, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleTower_Outside_EventScript_AlreadyMetRightTutor
	msgbox BattleTower_Outside_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleTower_Outside_EventScript_ChooseRightTutorMove
	end

BattleTower_Outside_EventScript_AlreadyMetRightTutor::
	msgbox BattleTower_Outside_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleTower_Outside_EventScript_ChooseRightTutorMove
	end

BattleTower_Outside_EventScript_ChooseRightTutorMove::
	message BattleTower_Outside_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_DefenseCurl
	case 1, BattleTower_Outside_EventScript_Snore
	case 2, BattleTower_Outside_EventScript_MudSlap
	case 3, BattleTower_Outside_EventScript_Swift
	case 4, BattleTower_Outside_EventScript_IcyWind
	case 5, BattleTower_Outside_EventScript_Endure
	case 6, BattleTower_Outside_EventScript_PsychUp
	case 7, BattleTower_Outside_EventScript_IcePunch
	case 8, BattleTower_Outside_EventScript_ThunderPunch
	case 9, BattleTower_Outside_EventScript_FirePunch
	case 10, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_ChooseNewRightTutorMove::
	message BattleTower_Outside_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_DefenseCurl
	case 1, BattleTower_Outside_EventScript_Snore
	case 2, BattleTower_Outside_EventScript_MudSlap
	case 3, BattleTower_Outside_EventScript_Swift
	case 4, BattleTower_Outside_EventScript_IcyWind
	case 5, BattleTower_Outside_EventScript_Endure
	case 6, BattleTower_Outside_EventScript_PsychUp
	case 7, BattleTower_Outside_EventScript_IcePunch
	case 8, BattleTower_Outside_EventScript_ThunderPunch
	case 9, BattleTower_Outside_EventScript_FirePunch
	case 10, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, BattleTower_Outside_EventScript_AlreadyMetElementalTutor
	msgbox BattleTower_Outside_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto BattleTower_Outside_EventScript_ChooseElementalTutorMove
	end

BattleTower_Outside_EventScript_AlreadyMetElementalTutor::
	msgbox BattleTower_Outside_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleTower_Outside_EventScript_ChooseElementalTutorMove
	end

BattleTower_Outside_EventScript_ChooseElementalTutorMove::
	message BattleTower_Outside_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_FrenzyPlant
	case 1, BattleTower_Outside_EventScript_BlastBurn
	case 2, BattleTower_Outside_EventScript_HydroCannon
	case 3, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_ChooseNewElementalTutorMove::
	message BattleTower_Outside_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_FrenzyPlant
	case 1, BattleTower_Outside_EventScript_BlastBurn
	case 2, BattleTower_Outside_EventScript_HydroCannon
	case 3, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleTower_Outside_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleTower_Outside_EventScript_CancelChooseMon::
	msgbox BattleTower_Outside_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleTower_Outside_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleTower_Outside_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleTower_Outside_EventScript_TeachTutorMove
	msgbox BattleTower_Outside_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleTower_Outside_EventScript_ChooseNewMove
	end

BattleTower_Outside_EventScript_TeachTutorMove::
	msgbox BattleTower_Outside_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	@special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Outside_EventScript_CancelChooseMon
	msgbox BattleTower_Outside_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleTower_Outside_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleTower_Outside_EventScript_ChooseNewLeftTutorMove
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, BattleTower_Outside_EventScript_ChooseNewElementalTutorMove
	goto BattleTower_Outside_EventScript_ChooseNewRightTutorMove
	end

BattleTower_Outside_Text_LeftTutorIntro:
	.string "哇哈哈哈！\p现在看不出来，可当年\n我可是个强悍的训练家。\p大家都说我是附近\n最厉害的大姐姐呢！\p………………\p怎么了？\n你不信我。\p我可不像那边那个\n爱吹牛的女人。我是有真本事的！\p让我证明给你看。\n我能教你的宝可梦既特别\l又可爱的招式。\p不过我可不白教。\n用一点点对战点数来换\l我教的招式，怎么样？$"
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

BattleTower_Outside_Text_LeftTutorWelcomeBack:
	.string "哇哈哈哈！\p你又来学特别又可爱的\n宝可梦招式了？$"
	.string ""
	.string ""

BattleTower_Outside_Text_TeachWhichMove:
	.string "好啦好啦，看这边！\n要教哪一招？$"
	.string ""

BattleTower_Outside_Text_MoveWillBeXBattlePoints:
	.string "要教{STR_VAR_1}这招是吧？\n收费{STR_VAR_2}对战点数，可以吗？$"
	.string ""

BattleTower_Outside_Text_TeachMoveToWhichMon:
	.string "好啦好啦，接下来选\n要学招式的宝可梦。$"
	.string ""

BattleTower_Outside_Text_HaventGotEnoughPoints:
	.string "什么……\n你的对战点数不够！$"
	.string ""

BattleTower_Outside_Text_IllTakeBattlePoints:
	.string "见识到我的本事了吧？\n那我就收下对战点数啦！$"
	.string ""

BattleTower_Outside_Text_YouDontWantTo:
	.string "什么？\n你不想学了……\p想看我的本事，\n随时来找我！$"
	.string ""
	.string ""
	.string ""

BattleTower_Outside_Text_RightTutorIntro:
	.string "嘻嘻嘻！\p现在看不出来，可当年\n我可是个了不起的训练家。\p大家都说我是\n最无敌的比基尼姐姐呢！\p………………\p怎么了？\n你不信我。\p我可不像那边那个\n滑稽的女人。我是有经验的！\p我能证明给你看。\n我能教你的宝可梦又强硬\l又漂亮的招式。\p不过我可不白教。\n用一点点对战点数来换\l我教的招式，怎么样？$"
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

BattleTower_Outside_Text_RightTutorWelcomeBack:
	.string "嘻嘻嘻！\p你是来学又强硬又漂亮的\n宝可梦招式的吗？$"
	.string ""
	.string ""

BattleTower_Outside_Text_ThinkLadiesDontGetAlong:
	.string "那两位大姐，彼此之间\n说起话来可难听了，你大概\l会以为她们关系不好。\p可要是真关系不好，她们\n也不会一起待在这儿了吧？$"
	.string ""
	.string ""
	.string ""
	.string ""

BattleTower_Outside_Text_LadiesWereStrongAndBeautiful:
	.string "我还是个小毛孩的时候，\n那两位大姐就又强又美。\p她们是我们训练家中的偶像。\p就算现在，岁月\n也没让她们的本事有半点生锈。\p不如说，她们宝可梦的\n招式反而更加精纯了。\p可是……不知为何，我总\n忍不住觉得……\p时间真是无情……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleTower_Outside_Text_SoftboiledDesc::
	.string "回复自身\n最大HP的一半。$"
	.string ""
	.string ""

BattleTower_Outside_Text_SeismicTossDesc::
	.string "给予对手与自身\n等级相同的伤害。$"
	.string ""
	.string ""

BattleTower_Outside_Text_DreamEaterDesc::
	.string "回复对睡眠中对手\n造成伤害的一半。$"
	.string ""
	.string ""

BattleTower_Outside_Text_MegaPunchDesc::
	.string "以惊人的力量\n打出的强力一拳。$"
	.string ""
	.string ""

BattleTower_Outside_Text_MegaKickDesc::
	.string "以强烈的力道\n使出的强大踢击。$"
	.string ""
	.string ""

BattleTower_Outside_Text_BodySlamDesc::
	.string "用整个身体压击，\n有时会让对手麻痹。$"
	.string ""
	.string ""

BattleTower_Outside_Text_RockSlideDesc::
	.string "投掷大石块攻击，\n有时会让对手畏缩。$"
	.string ""
	.string ""

BattleTower_Outside_Text_CounterDesc::
	.string "以双倍威力\n反击物理攻击。$"
	.string ""
	.string ""

BattleTower_Outside_Text_ThunderWaveDesc::
	.string "用微弱电流\n使对手陷入麻痹。$"
	.string ""
	.string ""

BattleTower_Outside_Text_SwordsDanceDesc::
	.string "以战舞\n大幅提高攻击。$"
	.string ""
	.string ""

BattleTower_Outside_Text_DefenseCurlDesc::
	.string "蜷缩身体藏起弱点，\n同时提高防御。$"
	.string ""
	.string ""

BattleTower_Outside_Text_SnoreDesc::
	.string "只能在睡眠时\n使用的巨响攻击。$"
	.string ""
	.string ""

BattleTower_Outside_Text_MudSlapDesc::
	.string "向对手脸上扔泥，\n降低其命中率。$"
	.string ""
	.string ""

BattleTower_Outside_Text_SwiftDesc::
	.string "射出星形光线，\n攻击必定命中。$"
	.string ""
	.string ""

BattleTower_Outside_Text_IcyWindDesc::
	.string "冰冷的攻击，\n降低对手的速度。$"
	.string ""
	.string ""

BattleTower_Outside_Text_EndureDesc::
	.string "在1回合内\n忍受攻击，留下1HP。$"
	.string ""
	.string ""

BattleTower_Outside_Text_PsychUpDesc::
	.string "复制对手的\n能力效果，加于自身。$"
	.string ""
	.string ""

BattleTower_Outside_Text_IcePunchDesc::
	.string "冰冷的拳头，\n有时会让对手冰冻。$"
	.string ""
	.string ""

BattleTower_Outside_Text_ThunderPunchDesc::
	.string "带电的拳头，\n有时会让对手麻痹。$"
	.string ""
	.string ""

BattleTower_Outside_Text_FirePunchDesc::
	.string "灼热的拳头，\n有时会让对手灼伤。$"
	.string ""
	.string ""

BattleTower_Outside_Text_ElementalTutorIntro::
	.string "呼……呼……\p啊？怎么了？\p哦，抱歉，我刚打了个盹。\p我是属性专家。\p我有能力把最强的招式\n教给草、火、水属性的\l宝可梦。\p你是来学这种强大\n力量的？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleTower_Outside_Text_ElementalTutorWelcomeBack:
	.string "呼……呼……\p啊？怎么了，谁呀？\p哦，你是来学我最强\n招式的力量的？$"
	.string ""
	.string ""
	.string ""

BattleTower_Outside_Text_TeachWhichMoveElemental::
	.string "你觉得哪一招适合\n你的宝可梦？$"
	.string ""

BattleTower_Outside_Text_StrongElementalMoveDesc::
	.string "威力强大，\n但下一回合无法行动。$"
	.string ""
	.string ""

BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleTower_Outside_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleTower_Outside_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleTower_Outside_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Outside_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Outside_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleTower_Outside_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleTower_Outside_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleTower_Outside_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleTower_Outside_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleTower_Outside_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleTower_Outside_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleTower_Outside_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleTower_Outside_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleTower_Outside_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleTower_Outside_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleTower_Outside_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleTower_Outside_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleTower_Outside_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleTower_Outside_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleTower_Outside_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleTower_Outside_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleTower_Outside_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleTower_Outside_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleTower_Outside_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleTower_Outside_ExchangeServiceCorner_EventScript_HpUp
	case 6, BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	release
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Protein::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Calcium::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Iron::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Zinc::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Carbos::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_HpUp::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmHpUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleTower_Outside_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleTower_Outside_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleTower_Outside_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleTower_Outside_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleTower_Outside_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleTower_Outside_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleTower_Outside_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleTower_Outside_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleTower_Outside_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleTower_Outside_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleTower_Outside_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleTower_Outside_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox BattleTower_Outside_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

BattleTower_Outside_ExchangeServiceCorner_Text_YouAlreadyHaveThis:
	.string "您已经有这个道具了。$"

BattleTower_Outside_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "您好！您要是找奇迹交换，\n它现在已经搬到\l每一间宝可梦中心了。玩得开心！$"
	.string ""
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "您好，这里是对战点数\n兑换服务区。\p您积攒的对战点数，可以\n在这里换成精美的奖品。\p请从这张单子上挑选奖品。$"
	.string ""
	.string ""
	.string ""
	.string ""

@ Unused
BattleTower_Outside_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "请从这张单子上挑选奖品。$"

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "您选的是亲吻海报。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "您选的是亲吻靠垫。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "您选的是迷唇娃玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "您选的是波克比玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "您选的是喵喵玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "您选的是皮皮玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "您选的是百变怪玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "您选的是火球鼠玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "您选的是菊草叶玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "您选的是小锯鳄玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "您选的是拉普拉斯玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "您选的是卡比兽玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "您选的是妙蛙花玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "您选的是喷火龙玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "您选的是水箭龟玩偶。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "您选的是攻击增强剂。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "您选的是特攻增强剂。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmIron:
	.string "您选的是防御增强剂。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "您选的是特防增强剂。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "您选的是速度增强剂。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmHpUp:
	.string "您选的是HP增强剂。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "您选的是光粉。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "您选的是白色香草。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "您选的是先制之爪。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "您选的是心灵香草。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "您选的是讲究头带。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "您选的是王者之证。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "您选的是气势头带。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "您选的是焦点镜。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "您选的是吃剩的东西。\n确认吗？$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "谢谢惠顾！\n我们会把它送到您家里的电脑。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "这是您的奖品！$"

BattleTower_Outside_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "非常抱歉……\n您的对战点数不够……$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_PCIsFull:
	.string "非常抱歉……\n您的电脑似乎已经满了……$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "非常抱歉……\n您的包包已经没有空位了……$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "非常感谢。\p您攒够对战点数以后，\n再来光顾吧。$"
	.string ""
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "哇，都好棒啊！\n真想把它们全收下！\l可爱的靠垫！\l大大的毛绒玩偶！\l小小的毛绒玩偶！\l全都想要！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "交给妈妈吧！\p不管你想要什么，\n妈妈都会想办法弄来，宝贝！$"
	.string ""
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "要是能弄到这里的道具，\n我的宝可梦就会变强。\p那是一定的！\n毫无疑问！$"
	.string ""
	.string ""
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "嗯？\n你在看什么？\p我不喜欢你那样盯着\n我的毛绒玩偶。\p想要就自己去换啊！\n对吧，迷唇娃？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "你知道吗？\p只要在对战设施刷新纪录，\n他们给的对战点数就会\l越来越多。$"
	.string ""
	.string ""
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "印着迷唇娃的大海报。$"

BattleTower_Outside_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "迷唇娃靠垫。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "迷唇娃玩偶。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "波克比玩偶。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "喵喵玩偶。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "皮皮玩偶。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "百变怪玩偶。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "火球鼠玩偶。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "菊草叶玩偶。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "小锯鳄玩偶。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "大号玩偶。\n可以放在垫子或桌子上。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ProteinDesc::
	.string "能提高宝可梦的\n攻击基础点数。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_CalciumDesc::
	.string "能提高宝可梦的\n特攻基础点数。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_IronDesc::
	.string "能提高宝可梦的\n防御基础点数。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ZincDesc::
	.string "能提高宝可梦的\n特防基础点数。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_CarbosDesc::
	.string "能提高宝可梦的\n速度基础点数。$"

BattleTower_Outside_ExchangeServiceCorner_Text_HPUpDesc::
	.string "能提高宝可梦的\nHP基础点数。$"
	.string ""  

BattleTower_Outside_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "携带后，对战中\n会逐渐回复HP。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "携带后，能复原\n降低的能力。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "携带后，有时能\n率先发动攻击。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "携带后，能让宝可梦\n从着迷状态恢复。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "携带后，会发出强光\n降低对手命中率。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "提高招式威力，\n但只能使出那一招。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "携带后，攻击命中时\n有时会让对手畏缩。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "携带后，有时能\n防止濒死。$"
	.string ""

BattleTower_Outside_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "携带后，提高\n击中要害的概率。$"
	.string ""


SaffronCity_FightingDojoVIP_Text_Machamp:
	.string "怪力：恰姆！$"

SaffronCity_FightingDojo_EventScript_Chased::
	msgbox SaffronCity_FightingDojoVIP_Text_Chased, MSGBOX_NPC
	end

SaffronCity_FightingDojoVIP_Text_Chased:
	.string "救命！$"

SaffronCity_FightingDojoVIP_EvetScript_Statue::
	msgbox SaffronCity_FightingDojoVIP_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_FightingDojoVIP_Text_Statue:
	.string "格斗道场VIP休息室$"

SaffronCity_FightingDojoVIP_Text_Falkner_Rematch:
	.string "恭喜你战胜了\n四天王！\p我一直在更刻苦地训练\n我的飞行属性宝可梦。\p还想再挑战一次\n天空的力量吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat:
	.string "哇……我又输给你了。\p我会更加刻苦地训练，\n成为最了不起的鸟类大师！$"
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch:
	.string "哇，你现在已经是\n城都冠军了！\p你的实力真让人佩服！\p我一直忙着做研究。\p现在我准备好向你展示\n新的研究成果了。\p要再和我对战一次吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat:
	.string "哇，你一定是一位\n专家级训练家。\p我的研究一定还\n没有完成……$"
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Whitney_Rematch:
	.string "嗨！是你呀！\p哇，你现在是\n城都冠军了？\p你真的好厉害！\p我想看看你有多强。\p要再和我对战一次吗？$"
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat:
	.string "哇啊啊啊！\p哇啊啊啊！\p……呜呜，抽噎……你太过分了！$"
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Morty_Rematch:
	.string "啊，城都冠军！\n感谢你前来。\p你已经展示了实力和\n技巧，比起上次对战\l你有进步了吗？\p我一直在和幽灵属性\n宝可梦一起修行。\p让我看看你能否再次\n战胜那些影子。\p要再和我对战一次吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat:
	.string "我还不够强……\p你见识过的\n比我多得多。\p我好羡慕你……$"
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Chuck_Rematch:
	.string "哇哈哈！城都冠军！\p你又回来求战了！\p看得出你的本事长进了！\p准备好分个高下了吗？$"
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat:
	.string "啥？啊？我输了？又输了？$"

SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch:
	.string "……恭喜你，城都\n冠军。\p你变得这么强了……\p不知道我有没有进步。\p你愿意来验证一下吗？\p要再和我对战一次吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat:
	.string "……你是一位比我\n更好的训练家，\p无论技巧还是温柔。$"
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Pryce_Rematch:
	.string "啊，城都冠军！\p你的本事确实\n不同凡响。\p老夫很佩服。\p不过就算到现在，我们\n仍能互相学到很多。\p老夫柳伯——\n冬之训练家——\p还有几手绝活。\p要再和我对战一次吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat:
	.string "啊，你的身手又一次\n让老夫佩服。\p有这份坚强的意志，\n我知道你一定能跨过\l人生的一切障碍。$"
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Clair_Rematch:
	.string "你做到了啊。\p你现在是城都冠军了。\p你证明了自己的实力，\n可还能应付我吗？\p身为驯龙师，我不会\n手下留情。\p这次不会了。\p要再和我对战一次吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat:
	.string "我输了？\p又输了？\p难以置信。一定是哪里\n搞错了……$"
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Brock_Rematch:
	.string "小刚：嘿，{PLAYER}！\p听说你现在是关都冠军了。\p真是太厉害了！\p你一定变得更强了。\p要不要再和我打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat:
	.string "小刚：你的宝可梦又一次\n攻破了我坚如磐石的防守……$"
	.string ""

SaffronCity_FightingDojoVIP_Text_Misty_Rematch:
	.string "小霞：哇，你现在是\n关都冠军了！\p太厉害了！你一路成长了\n好多啊，{PLAYER}。\p但我可不会退缩。\p要不要再和我打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat:
	.string "小霞：你还真有两下子……$"

SaffronCity_FightingDojoVIP_Text_Surge_Rematch:
	.string "马志士：这么说，你现在是\n关都冠军了！\p干得漂亮，小家伙！但别以为\n我就到此为止了！\p再来一决胜负怎么样？$"
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat:
	.string "马志士：可恶！你还是\n这么强！$"
	.string ""

SaffronCity_FightingDojoVIP_Text_Erika_Rematch:
	.string "莉佳：哎呀，你好。\p真没想到，冠军！\p能再见到你真是太好了。\p你的旅程一定非常\n精彩吧。\p就算是冠军也乐于挑战。\p要不要再和我打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat:
	.string "莉佳：输了还是让人\n有点不甘心……\p但知道有强大的训练家\n存在，反倒让我更想努力……$"
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch:
	.string "娜姿：啊，冠军。\p我感应到你的归来了。\p你的力量已经大幅成长。\p直到现在，我仍能感到你的气场。\p要不要再和我打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat:
	.string "娜姿：你对宝可梦的爱\n又一次压过了我的\l超能力……$"
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Janine_Rematch:
	.string "嘻嘻嘻……\p哇，你做到了！\p你现在是冠军了！\p我真为你骄傲！但别以为\n我会手下留情。\p要不要再和我打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat:
	.string "阿杏：你还是那么\n厉害！\p这次确实是你赢了……$"
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Blaine_Rematch:
	.string "夏伯：哇哦！\p我看你已经成了关都冠军！\p真是火热啊！\p你的本事是一流的。\p我随时都乐意来一场。\p要不要再和我打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat:
	.string "夏伯：你的本事真是\n炽热如火！\p我的防线都被你\n烧穿了。$"
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Blue_Rematch:
	.string "青绿：呵，呵。冠军！\p看来你一路成长了不少。\p我以前也拿过那个头衔。\n不过我可不会放水。\p让我看看你能守住多久。\p要不要再和我打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat:
	.string "青绿：什么？\p我怎么又输了？$"
	.string ""

