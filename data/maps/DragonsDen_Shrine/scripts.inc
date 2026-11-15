.set LOCALID_DRAGONSDEN3_CLAIR, 4
.set LOCALID_DRAGONSDEN3_ELDER, 1

DragonsDen_Shrine_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Shrine_OnFrame
	.byte 0

DragonsDen_Shrine_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 2, DragonsDen_Shrine_Trigger_ElderQuizTop
	.2byte 0

DragonsDen_Shrine_EventScript_Elder::
	lock
	faceplayer
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, DragonsDen_Shrine_EventScript_ElderChooseDratini
	msgbox DragonsDen_Shrine_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_Trigger_ElderQuizLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_MonWalkToElderLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz

DragonsDen_Shrine_Trigger_ElderQuizTop::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderTop
	applymovement OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_PlayerWalkToElderTop
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz

DragonsDen_Shrine_Trigger_ElderQuizRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderRight
	applymovement OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_MonWalkToElderRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz


DragonsDen_Shrine_Movement_PlayerWalkToElderLeft:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_MonWalkToElderLeft:
	walk_left
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_PlayerWalkToElderTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_PlayerWalkToElderRight:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
DragonsDen_Shrine_Movement_MonWalkToElderRight:
	walk_right
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_EventScript_ElderOfferQuiz::
	msgbox DragonsDen_Shrine_Text_ElderGreeting, MSGBOX_DEFAULT
	setvar VAR_DRAGONS_DEN_QUIZ, 0
	goto DragonsDen_Shrine_EventScript_ElderQuiz1

DragonsDen_Shrine_EventScript_ElderQuiz1::
	message DragonsDen_Shrine_Text_Question1
	multichoice 20, 6, MULTI_ELDERQUIIZ1, FALSE 
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz1Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz1Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz1
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz1

DragonsDen_Shrine_EventScript_ElderQuiz1Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz2

DragonsDen_Shrine_EventScript_ElderQuiz2::
	message DragonsDen_Shrine_Text_Question2
	multichoice 20, 6, MULTI_ELDERQUIIZ2, FALSE 
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz2Correct
	case 1, DragonsDen_Shrine_EventScript_ElderQuiz2Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz2
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz2

DragonsDen_Shrine_EventScript_ElderQuiz2Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz3

DragonsDen_Shrine_EventScript_ElderQuiz3::
	message DragonsDen_Shrine_Text_Question3
	multichoice 20, 6, MULTI_ELDERQUIIZ3, FALSE 
	switch VAR_RESULT
	case 1, DragonsDen_Shrine_EventScript_ElderQuiz3Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz3Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz3
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz3

DragonsDen_Shrine_EventScript_ElderQuiz3Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz4

DragonsDen_Shrine_EventScript_ElderQuiz4::
	message DragonsDen_Shrine_Text_Question4
	multichoice 20, 6, MULTI_ELDERQUIIZ4, FALSE 
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz4Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz4Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz4
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz4

DragonsDen_Shrine_EventScript_ElderQuiz4Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz5

DragonsDen_Shrine_EventScript_ElderQuiz5::
	message DragonsDen_Shrine_Text_Question5
	multichoice 20, 6, MULTI_ELDERQUIIZ5, FALSE 
	switch VAR_RESULT
	case 2, DragonsDen_Shrine_EventScript_ElderQuizFinish
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz5
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz5

DragonsDen_Shrine_EventScript_ElderWrong::
	msgbox DragonsDen_Shrine_Text_WrongAnswer1, MSGBOX_DEFAULT
	addvar VAR_DRAGONS_DEN_QUIZ, 1
	return

DragonsDen_Shrine_EventScript_ElderQuizFinish::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	delay 20
	msgbox DragonsDen_Shrine_Text_PassedTest, MSGBOX_DEFAULT
	closemessage
	goto DragonsDen_Shrine_EventScript_ClairEnter


DragonsDen_Shrine_Text_ElderGreeting:
    .string "嗯……很高兴你能来。\p不必解释你的来意。\n是小椿让你来的吧？\p那孩子真叫人头疼……\n抱歉，我必须考验你一下。\p不必担心，\n你只需回答几个问题。\l准备好了吗？$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

DragonsDen_Shrine_Text_Question1:
    .string "对你来说，宝可梦是什么？$"

DragonsDen_Shrine_Text_Question2:
    .string "是什么帮助你赢得对战？$"

DragonsDen_Shrine_Text_Question3:
    .string "你希望和什么样的训练家\n对战？$"
    .string ""

DragonsDen_Shrine_Text_Question4:
    .string "培育宝可梦，\n最重要的是什么？$"
    .string ""

DragonsDen_Shrine_Text_Question5:
    .string "强大的宝可梦，弱小的宝可梦。\n哪一个更重要？$"
    .string ""

DragonsDen_Shrine_Text_WrongAnswer1:
    .string "啊？我没太听清……$"

DragonsDen_Shrine_Text_WrongAnswer2:
    .string "你刚才说什么？$"

DragonsDen_Shrine_Text_RightAnswer:
    .string "哦，我明白了……$"

DragonsDen_Shrine_Text_PassedTest:
    .string "嗯……原来如此……\p你非常珍惜宝可梦。\p很值得称赞。\p这份信念才是\n最重要的！\p{PLAYER}，不要丢掉这份信念。\p它会帮助你\n闯过宝可梦联盟。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

DragonsDen_Shrine_EventScript_ClairEnter::
	clearflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	addobject LOCALID_DRAGONSDEN3_CLAIR
	playse SE_DOOR
	delay 40
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_SOUTH
	applymovement LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairEnter
	waitmovement 0
	turnobject LOCALID_DRAGONSDEN3_ELDER, DIR_WEST	
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Shrine_Text_ClairYouPassed, MSGBOX_DEFAULT
	applymovement LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairBackup1
	waitmovement 0
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Shrine_Text_ClairThatCantBe, MSGBOX_DEFAULT
	applymovement LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairBackup2
	waitmovement 0
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Shrine_Text_ClairYoureLying, MSGBOX_DEFAULT
	removefieldmugshot
	applymovement LOCALID_DRAGONSDEN3_ELDER, DragonsDen_Shrine_Movement_ElderWalkToClair
	waitmovement 0
	turnobject LOCALID_DRAGONSDEN3_CLAIR, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_MustIInformLance, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_DRAGONSDEN3_CLAIR, Common_Movement_ExclamationMark
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Shrine_Text_IUnderstand, MSGBOX_DEFAULT
	removefieldmugshot
	applymovement LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairReturnToPlayer
	waitmovement 0
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Shrine_Text_HereRisingBadge, MSGBOX_DEFAULT
	removefieldmugshot
	message DragonsDen_Shrine_Text_PlayerReceivedRisingBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Shrine_Text_RisingBadgeExplanation, MSGBOX_DEFAULT
	removefieldmugshot
	setflag FLAG_BADGE08_GET
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	addvar VAR_NUM_BADGES, 1

	applymovement LOCALID_DRAGONSDEN3_ELDER, DragonsDen_Shrine_Movement_ElderReturnToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_DRAGONSDEN3_CLAIR, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_ElderScoldsClair, MSGBOX_DEFAULT
	closemessage
	delay 20
	createfieldmugshot MUGSHOT_CLAIR
	msgbox DragonsDen_Shrine_Text_Speechless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairLeave
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	removeobject LOCALID_DRAGONSDEN3_CLAIR
	clearflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	setvar VAR_BLACKTHORN_CITY_STATE, 3
	release
	end

DragonsDen_Shrine_Movement_ClairEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

DragonsDen_Shrine_Movement_ClairBackup1:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

DragonsDen_Shrine_Movement_ClairBackup2:
	lock_facing_direction
	walk_slow_left
	unlock_facing_direction
	step_end

DragonsDen_Shrine_Movement_ElderWalkToClair:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

DragonsDen_Shrine_Movement_ClairReturnToPlayer:
	walk_right
	walk_right
	step_end

DragonsDen_Shrine_Movement_ElderReturnToPlayer:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	face_down
	step_end

DragonsDen_Shrine_Movement_ClairLeave:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

DragonsDen_Shrine_Text_ClairYouPassed:
    .string "结果怎么样？\p我看也用不着问了。\n你没通过吧？\p………………\p……什么？你通过了？$"
    .string ""
	.string ""
    .string ""
    .string ""

DragonsDen_Shrine_Text_ClairThatCantBe:
    .string "这不可能！$"

DragonsDen_Shrine_Text_ClairYoureLying:
    .string "你骗人！\p连我都还没得到认可呢！$"
    .string ""

DragonsDen_Shrine_Text_MustIInformLance:
    .string "小椿！\p这孩子无论实力还是心性，\n都无可挑剔！\p认输吧，\n把升龙徽章颁给这孩子！\p……还是要我把这事告诉阿渡？$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

DragonsDen_Shrine_Text_IUnderstand:
    .string "我、我明白了……$"

DragonsDen_Shrine_Text_HereRisingBadge:
    .string "给，这就是升龙徽章……\p快点！拿去！$"
    .string ""

DragonsDen_Shrine_Text_PlayerReceivedRisingBadge:
    .string "{PLAYER}得到了升龙徽章。$"

DragonsDen_Shrine_Text_RisingBadgeExplanation:
    .string "有了升龙徽章，\n你的宝可梦就能使用\l攀登瀑布的招式。\p另外，所有的宝可梦都会\n认可你这位训练家，\l无条件服从你的每一个命令。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

DragonsDen_Shrine_Text_ElderScoldsClair:
    .string "小椿……\p好好反省一下，这孩子拥有\n而你所欠缺的究竟是什么。$"
    .string ""
    .string ""

DragonsDen_Shrine_Text_Speechless:
    .string "..................................$"

DragonsDen_Shrine_Text_ComeAgain:
    .string "若你愿意，随时可以再来。$"

DragonsDen_Shrine_Text_SilverIsInTraining:
    .string "有个和你年纪相仿的少年\n正在这里修行。\p他很像年轻时的小椿，\n让人有些担心……$"
    .string ""
    .string ""
    .string ""

DragonsDen_Shrine_EventScript_Elder2::
	msgbox DragonsDen_Shrine_Text_Elder2, MSGBOX_NPC
	end

DragonsDen_Shrine_EventScript_Elder3::
	lock
	faceplayer
	msgbox DragonsDen_Shrine_Text_DracoMeteorTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DragonsDen_Shrine_EventScript_DracoMeteorDeclined
	msgbox DragonsDen_Shrine_Text_DracoMeteorWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_DRACO_METEOR
	call MoveTutor_EventScript_OpenBox
	goto_if_eq VAR_RESULT, FALSE, DragonsDen_Shrine_EventScript_DracoMeteorDeclined
	goto DragonsDen_Shrine_EventScript_DracoMeteorTaught
	end

DragonsDen_Shrine_Text_Elder2:
    .string "已经很久没有训练家\n能得到长老\l难得的认可了。\p事实上，上一位还是阿渡大人。$"
    .string ""
    .string ""
    .string ""

DragonsDen_Shrine_EventScript_DracoMeteorDeclined::
	msgbox DragonsDen_Shrine_Text_DracoMeteorDeclined, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_EventScript_DracoMeteorTaught::
	msgbox DragonsDen_Shrine_Text_DracoMeteorTaught, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_Text_DracoMeteorTeach:
    .string "只有最强的龙属性宝可梦\n才能掌握流星群。\p要我把它教给\n你的一只宝可梦吗？$"
    .string ""
    .string ""
    .string ""

DragonsDen_Shrine_Text_DracoMeteorWhichMon:
    .string "要让哪只宝可梦\n学习流星群？$"
    .string ""

DragonsDen_Shrine_Text_DracoMeteorDeclined:
    .string "想掌握龙属性的终极招式时，\n随时再来吧。$"
    .string ""

DragonsDen_Shrine_Text_DracoMeteorTaught:
    .string "愿流星群能助你一臂之力。$"

DragonsDen_Shrine_EventScript_ElderChooseDratini::
	goto_if_eq VAR_DRAGONS_DEN_QUIZ, 0, DragonsDen_Shrine_EventScript_ElderGiveSpecialDratini
	goto DragonsDen_Shrine_EventScript_ElderGiveBasicDratini

DragonsDen_Shrine_EventScript_ElderGiveBasicDratini::
	goto_if_set FLAG_GOT_DRATINI, DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini
	msgbox DragonsDen_Shrine_Text_TakeThisDratini, MSGBOX_DEFAULT

	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	givemon SPECIES_DRATINI, 15, move1=MOVE_EXTREME_SPEED
	call Common_EventScript_GiftMon

	msgbox DragonsDen_Shrine_Text_SymbolicDragon, MSGBOX_DEFAULT
	setflag FLAG_GOT_DRATINI
	release
	end

DragonsDen_Shrine_EventScript_ElderGiveSpecialDratini::
	goto_if_set FLAG_GOT_DRATINI, DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini
	msgbox DragonsDen_Shrine_Text_TakeThisDratini, MSGBOX_DEFAULT

	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	givemon SPECIES_DRATINI, 15, move1=MOVE_EXTREME_SPEED, move2=MOVE_SPACIAL_REND, shinyMode=SHINY_MODE_ALWAYS
	call Common_EventScript_GiftMon

	msgbox DragonsDen_Shrine_Text_SymbolicDragon, MSGBOX_DEFAULT
	setflag FLAG_GOT_DRATINI
	release
	end

DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini::
	msgbox DragonsDen_Shrine_Text_ClairsGrandfather, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_Text_TakeThisDratini:
    .string "嗯……很高兴你能来。\p你来得正是时候。\p我有东西要给你。\p收下这只迷你龙吧，\n作为我认可你的证明。$"
    .string ""
    .string ""
    .string ""
    .string ""

DragonsDen_Shrine_Text_SymbolicDragon:
    .string "龙属性宝可梦是\n我们一族的象征。\p你已经证明，\n自己值得托付一只。$"
    .string ""
    .string ""
    .string ""

DragonsDen_Shrine_Text_ClairsGrandfather:
    .string "小椿似乎从你身上\n学到了宝贵的一课。\p作为她的祖父，我要谢谢你。$"
    .string ""
    .string ""
