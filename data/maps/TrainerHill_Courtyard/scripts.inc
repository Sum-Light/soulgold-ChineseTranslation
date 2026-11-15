
TrainerHill_Courtyard_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
	.byte 0

TrainerHill_Courtyard_OnTransition::
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	setflag FLAG_VISITED_BATTLE_TOWER
	goto_if_set FLAG_CAUGHT_ZERAORA, TrainerHill_Courtyard_EventScript_HideZeraora
	specialvar VAR_RESULT, HasBattleTowerStreakForZeraora
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_EventScript_HideZeraora
	clearflag FLAG_HIDE_ZERAORA
	end

TrainerHill_Courtyard_EventScript_HideZeraora::
	setflag FLAG_HIDE_ZERAORA
	end

TrainerHill_Courtyard_EventScript_Zeraora::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_Text_ZeraoraChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_EventScript_DeclineZeraora
	bosslegendaryencounterwithmoves SPECIES_ZERAORA, 80, LOCALID_ZERAORA, FLAG_HIDE_ZERAORA, 4, SPECIES_NONE, 110, MOVE_PLASMA_FISTS, MOVE_CLOSE_COMBAT, MOVE_FIRE_PUNCH, MOVE_GRASS_KNOT
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, TrainerHill_Courtyard_EventScript_ZeraoraEnd
	setflag FLAG_CAUGHT_ZERAORA
	goto TrainerHill_Courtyard_EventScript_ZeraoraEnd

TrainerHill_Courtyard_EventScript_DeclineZeraora::
    playmoncry SPECIES_ZERAORA, 0
	msgbox TrainerHill_Courtyard_Text_ZeraoraDisappointed, MSGBOX_DEFAULT
    waitmoncry
    release
    end

TrainerHill_Courtyard_EventScript_ZeraoraEnd::
	release
	end

TrainerHill_Courtyard_Text_ZeraoraChallenge:
	.string "捷拉奥拉似乎是在\n向你发起挑战。\p你接受它的挑战吗？$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_ZeraoraDisappointed:
	.string "捷拉奥拉失望地嚎叫了一声。$"

TrainerHill_Courtyard_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Factory::
	lock
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Palace::
	lock
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Arena::
	lock
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
	closemessage	
	release
	end
	
TrainerHill_Courtyard_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "哇，训练家之丘真大！\p里面一定有很多种\n宝可梦！$"
	.string ""
	.string ""

BattleTowerOutsideBeautyText:
	.string "在对战帐篷里，只能\n带三只宝可梦上场。\p该派哪三只上场，\n真是好难决定……$"
	.string ""
	.string ""
	.string ""

BattleTowerOutsideSailorText:
	.string "嘿嘿，我是从工作中\n偷溜出来的。\p不赢一场我可回不去！\p我要全部赢下来，一定！$"
	.string ""
	.string ""

BattleTowerOutsideSignText:
	.string "{UP_ARROW} 训练家之丘入口\p“登上高峰吧，\n热血训练家们！”\p{RIGHT_ARROW} 对战帐篷。$"
	.string ""
	.string ""
	.string ""

BattleTower_Battle_Tent_Text_Factory:
	.string "对战帐篷：工厂\n“去发现吧！最强的宝可梦！”$"
	.string ""

BattleTower_Battle_Tent_Text_Palace:
	.string "对战帐篷：宫殿\n“尽情欣赏对战吧！”$"
	.string ""

BattleTower_Battle_Tent_Text_Arena:
	.string "对战帐篷：竞技场\n“愿最强队伍齐聚于此！”$"
	.string ""

BattleTowerOutsideText_Closed:
	.string "训练家之丘目前正在\n维修，暂停开放。$"
	.string ""


TrainerHill_Courtyard_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor
	msgbox TrainerHill_Courtyard_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor::
	msgbox TrainerHill_Courtyard_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
	case 7, TrainerHill_Courtyard_EventScript_Counter
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
	case 7, TrainerHill_Courtyard_EventScript_Counter
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor
	msgbox TrainerHill_Courtyard_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor::
	msgbox TrainerHill_Courtyard_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseRightTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
	case 1, TrainerHill_Courtyard_EventScript_Snore
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
	case 3, TrainerHill_Courtyard_EventScript_Swift
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
	case 5, TrainerHill_Courtyard_EventScript_Endure
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
	case 1, TrainerHill_Courtyard_EventScript_Snore
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
	case 3, TrainerHill_Courtyard_EventScript_Swift
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
	case 5, TrainerHill_Courtyard_EventScript_Endure
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor
	msgbox TrainerHill_Courtyard_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor::
	msgbox TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_EventScript_CancelChooseMon::
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
TrainerHill_Courtyard_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_EventScript_TeachTutorMove
	msgbox TrainerHill_Courtyard_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseNewMove
	end

TrainerHill_Courtyard_EventScript_TeachTutorMove::
	msgbox TrainerHill_Courtyard_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	@special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_EventScript_CancelChooseMon
	msgbox TrainerHill_Courtyard_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

TrainerHill_Courtyard_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove
	goto TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove
	end

TrainerHill_Courtyard_Text_LeftTutorIntro:
	.string "噗哈哈哈！\p现在看不出来，可俺过去\n可是个厉害的训练家。\p当年俺号称这一带\n最强的大姐姐，真的！\p………………\p怎么了？\n你不信俺。\p俺可不像那边那个\n吹牛皮的女人。俺是真有本事！\p俺证明给你看。\n俺能教你的宝可梦又特别\l又可爱的招式。\p不过教课可不能白教。\n拿一点对战点数\l来交学费，怎么样？$"
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

TrainerHill_Courtyard_Text_LeftTutorWelcomeBack:
	.string "噗哈哈哈！\p你又来学又特别\n又可爱的招式了吗？$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_TeachWhichMove:
	.string "好啦好啦，看好了！\n要俺教哪个招式？$"
	.string ""

TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints:
	.string "是{STR_VAR_1}这个招式吧？\n要收{STR_VAR_2}对战点数，行吗？$"
	.string ""

TrainerHill_Courtyard_Text_TeachMoveToWhichMon:
	.string "好啦好啦，那就挑一只\n该学招式的宝可梦吧。$"
	.string ""

TrainerHill_Courtyard_Text_HaventGotEnoughPoints:
	.string "怎么回事……\n你的对战点数不够！$"
	.string ""

TrainerHill_Courtyard_Text_IllTakeBattlePoints:
	.string "现在你见识到俺多厉害了吧？\n那对战点数俺就收下啦！$"
	.string ""

TrainerHill_Courtyard_Text_YouDontWantTo:
	.string "什么？\n你不想学……\p想见识俺的本事，\n随时来找俺！$"
	.string ""
	.string ""
	.string ""

TrainerHill_Courtyard_Text_RightTutorIntro:
	.string "咦嘻嘻嘻！\p现在看不出来，可我过去\n可是个了不起的训练家。\p当年我号称这一带\n最强的比基尼姐姐，真的！\p………………\p怎么了？\n你不信我。\p我可不像那边那个\n冒傻气的女人。我是真有经验！\p我证明给你看。\n我能教你的宝可梦又硬派\l又漂亮的招式。\p不过教课可不能白教。\n拿一点对战点数\l来交学费，怎么样？$"
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

TrainerHill_Courtyard_Text_RightTutorWelcomeBack:
	.string "咦嘻嘻嘻！\p你是来学又硬派\n又漂亮的招式吗？$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_ThinkLadiesDontGetAlong:
	.string "那两位女士互相说坏话的样子，\n你大概会以为她们\l关系不好吧。\p可要是真关系不好，她们\n也不会一起待在这儿了，对吧？$"
	.string ""
	.string ""
	.string ""
	.string ""

TrainerHill_Courtyard_Text_LadiesWereStrongAndBeautiful:
	.string "我还在当短裤小子的时候，\n那两位女士又强又美。\p她们是我们训练家中的偶像。\p就算现在，\n岁月也没让她们的本领变迟钝。\p不如说，她们的宝可梦\n招式磨炼得更加精湛了。\p可是……不知为何，我总\n忍不住觉得……\p时间真是残酷……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

TrainerHill_Courtyard_Text_SoftboiledDesc::
	.string "回复自身\n最大体力的一半。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_SeismicTossDesc::
	.string "给予与自身等级\n相同的伤害。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_DreamEaterDesc::
	.string "睡眠中的对手\n受到的伤害，\n回复其一半。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_MegaPunchDesc::
	.string "以惊人的力量\n挥出的一记\n强力拳击。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_MegaKickDesc::
	.string "威力极强的\n一记踢击，\n带有猛烈劲道。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_BodySlamDesc::
	.string "用整个身体撞击，\n有时会让对手\n陷入麻痹。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_RockSlideDesc::
	.string "抛出巨大的岩石。\n有时会让对手\n畏缩。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_CounterDesc::
	.string "以两倍威力\n反击受到的任何\n物理攻击。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_ThunderWaveDesc::
	.string "微弱的电流，\n会让对手\n陷入麻痹。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_SwordsDanceDesc::
	.string "提高士气的舞蹈，\n大幅提高\n自身的攻击。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_DefenseCurlDesc::
	.string "蜷缩身体，\n藏起弱点，\n提高防御。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_SnoreDesc::
	.string "只有在睡眠时\n才能使用的\n大声攻击。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_MudSlapDesc::
	.string "把泥巴甩到\n对手脸上，\n降低命中率。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_SwiftDesc::
	.string "发射星形的\n光线，必定\n命中。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_IcyWindDesc::
	.string "冰冷的攻击，\n会降低对手的\n速度。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_EndureDesc::
	.string "即使受到攻击，\n也能留下1HP\n撑过1回合。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_PsychUpDesc::
	.string "复制对手的\n效果，\n施加于自身。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_IcePunchDesc::
	.string "冰冷的拳头，\n有时会让对手\n冰冻。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_ThunderPunchDesc::
	.string "带电的拳头，\n有时会让对手\n麻痹。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_FirePunchDesc::
	.string "带火的拳头，\n有时会让对手\n灼伤。$"
	.string ""
	.string ""

TrainerHill_Courtyard_Text_ElementalTutorIntro::
	.string "呼……呼……\p什、什么，怎么了？\p哦，抱歉，我打了个盹。\p我是属性导师。\p我有能力教草、火、水属性\n宝可梦最强的\l招式。\p你是来学这份强大\n力量的吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack:
	.string "呼……呼……\p什、什么，谁啊？\p哦，你是来学我最强\n招式的力量吗？$"
	.string ""
	.string ""
	.string ""

TrainerHill_Courtyard_Text_TeachWhichMoveElemental::
	.string "你觉得哪个招式适合\n你的宝可梦？$"
	.string ""

TrainerHill_Courtyard_Text_StrongElementalMoveDesc::
	.string "威力强大，但使用后\n自身下一回合\n无法行动。$"
	.string ""
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis:
	.string "您已经有这个道具了。$"

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "您好！如果您在找奇迹交换，\n它现在位于每个宝可梦中心。\l玩得开心！$"
	.string ""
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "您好，这里是对战点数兑换\n服务区。\p我们将您收集的对战点数\n兑换成精美的奖品。\p请从这份列表中选择奖品。$"
	.string ""
	.string ""
	.string ""
	.string ""

@ Unused
TrainerHill_Courtyard_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "请从这份列表中选择奖品。$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "您选择了飞吻海报。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "您选择了亲吻靠垫。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "您选择了迷唇娃玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "您选择了波克比玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "您选择了喵喵玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "您选择了皮皮玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "您选择了百变怪玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "您选择了火球鼠玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "您选择了菊草叶玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "您选择了小锯鳄玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "您选择了拉普拉斯玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "您选择了卡比兽玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "您选择了妙蛙花玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "您选择了喷火龙玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "您选择了水箭龟玩偶。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "您选择了攻击增强剂。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "您选择了特攻增强剂。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron:
	.string "您选择了防御增强剂。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "您选择了特防增强剂。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "您选择了速度增强剂。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp:
	.string "您选择了HP增强剂。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "您选择了光粉。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "您选择了白色香草。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "您选择了先制之爪。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "您选择了心灵香草。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "您选择了讲究头带。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "您选择了王者之证。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "您选择了气势头带。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "您选择了焦点镜。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "您选择了吃剩的东西。\n确定吗？$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "谢谢！\n我们这就送到您家里的电脑上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "这是您的奖品！$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "非常抱歉……\n您的对战点数不够……$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull:
	.string "非常抱歉……\n您的电脑好像已经满了……$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "非常抱歉……\n您没有空间拿这个了……$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "非常感谢。\p等您攒够了对战点数，\n请再来光临。$"
	.string ""
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "啊，真好啊！\n好想要啊！\l可爱的靠垫！\l大大的毛绒玩偶！\l小小的毛绒玩偶！\l我全都想要！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "交给妈妈吧！\p只要是你想要的，不管是什么，\n妈妈都会想办法弄到手，宝贝！$"
	.string ""
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "只要弄到这里的道具，\n我的宝可梦就会变强。\p一定会变强！\n这还用说嘛！$"
	.string ""
	.string ""
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "干嘛？\n你盯着看什么看？\p我不喜欢你那样盯着我的\n毛绒玩偶看。\p想要的话，自己去换一个！\n对吧，迷唇娃？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "你知道吗？\p要是在对战设施里刷新记录，\n他们给的对战点数\l就会越来越多。$"
	.string ""
	.string ""
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "印着迷唇娃的大海报。$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "迷唇娃靠垫。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "迷唇娃玩偶。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "波克比玩偶。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "喵喵玩偶。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "皮皮玩偶。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "百变怪玩偶。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "火球鼠玩偶。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "菊草叶玩偶。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "小锯鳄玩偶。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "一个大玩偶。\n可以放在垫子或桌子上。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ProteinDesc::
	.string "一张奇怪的票，能带你\n前往一座废弃的岛屿。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CalciumDesc::
	.string "一张奇怪的票，能带你\n前往一座废弃的岛屿。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_IronDesc::
	.string "一张奇怪的票，能带你\n前往一座废弃的岛屿。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ZincDesc::
	.string "一张……旧地图？也许\n能带你去某个地方。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CarbosDesc::
	.string "努力值获得量变为10倍，\n但速度减半。$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_HPUpDesc::
	.string "西尔佛公司制造的一种\n奇特的盒子。$"
	.string ""  

TrainerHill_Courtyard_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "一件能在对战中逐渐回复\n体力的道具。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "一件能让降低的能力恢复\n原状的道具。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "一件偶尔能抢先发动\n攻击的道具。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "一件能让宝可梦摆脱\n着迷状态的道具。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "一件能发出眩光，降低\n对手命中率的道具。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "提升招式的威力，但只能\n使用那一个招式。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "一件在攻击命中时偶尔\n能让对手畏缩的道具。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "一件偶尔能防止\n濒死的道具。$"
	.string ""

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "一件能提高击中要害率\n的道具。$"
	.string ""
