
BlackthornCity_House3_MapScripts::
	.byte 0

BlackthornCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox BlackthornCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "呃……\n哦，对，我是遗忘爷爷。\p我能让宝可梦忘记招式。\p你要我帮忙吗？$"
	.string ""
	.string ""
	.string ""

BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "要让哪只宝可梦忘记招式？$"

BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "要忘记哪个招式呢？$"

BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1}只会一个招式，\n所以不能忘记……$"
	.string ""

BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "哦！{STR_VAR_1}的{STR_VAR_2}？\n要让这个招式被忘记吗？$"
	.string ""

BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "完美成功！\p{STR_VAR_1}完全忘记了\n{STR_VAR_2}。$"
	.string ""
	.string ""

BlackthornCity_MoveDeletersHouse_Text_ComeAgain:
	.string "有招式要忘记的话，\n请再过来。$"
	.string ""

BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "什么？\n蛋不该会任何招式啊。$"
	.string ""

BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "嗯！\p你的{STR_VAR_1}好像不愿意\n忘记冲浪。$"
	.string ""
	.string ""

BlackthornCity_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	faceplayer
	goto_if_set FLAG_TEMP_1, BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "我是招式教学狂。\p宝可梦能学会的招式——\n所有的招式——我全都知道，\l还能把它们教给宝可梦。\p如果你愿意，我可以教\n你的宝可梦一个招式。\p学费是一枚心之鳞片。\n我正在收集呢。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "哦！就是它！这真是一枚\n货真价实的心之鳞片！\p让我猜猜，你是想让我\n教它一个招式？$"
	.string ""
	.string ""
	.string ""

BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "要让哪只宝可梦学习招式？$"

BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "要教它哪个招式呢？$"

BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "抱歉……\p看来我没有能教给\n这只宝可梦的招式。$"
	.string ""
	.string ""

BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER}作为交换，\n交出了1枚心之鳞片。$"
	.string ""

BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "宝可梦需要学招式的话，\n请带着心之鳞片再来。$"
	.string ""

BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "嗯？蛋没有任何招式\n可以让我教啊。$"
	.string ""

EggMoveMaster::
	lock
	faceplayer
	goto_if_set FLAG_EGG_MOVES_UNLOCKED, EggMoveMaster_2
	msgbox EggMoveMaster_Text_1
	showmoneybox 0, 0
	msgbox EggMoveMaster_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EggMoveMaster_5
	hidemoneybox
	msgbox EggMoveMaster_Text_6
	release
	end

EggMoveMaster_2:
	msgbox EggMoveMaster_Text_0
	release
	end

EggMoveMaster_4:
	release
	end

EggMoveMaster_5:
	checkmoney 88888
	compare VAR_RESULT, FALSE
	goto_if_eq EggMoveMaster_9
	removemoney 88888
	updatemoneybox 0
	playse SE_SHOP
	waitse
	setflag FLAG_EGG_MOVES_UNLOCKED
	special Achievement_CheckAll
	msgbox EggMoveMaster_Text_4
	hidemoneybox
	closemessage
	fadescreen FADE_TO_BLACK
	delay 60
	fadescreen FADE_FROM_BLACK
	delay 20
	playfanfare MUS_OBTAIN_ITEM
	msgbox EggMoveMaster_Text_5
	waitse
	msgbox EggMoveMaster_Text_0
	goto EggMoveMaster_4

EggMoveMaster_9:
	msgbox EggMoveMaster_Text_3
	hidemoneybox
	release
	end


EggMoveMaster_Text_0:
	.string "在查看能力画面的\n对战招式页按下START键，\l切换到蛋招式页，\l就能教蛋招式了。$"

EggMoveMaster_Text_1:
	.string "我是蛋招式大师。\p有关蛋招式的事，\n我全都知道。\p如果你愿意，只要付一次\n¥88,888，我就把我知道的\l全部教给你。$"

EggMoveMaster_Text_2:
	.string "怎么样？你想把蛋招式的\n一切全都学走吗？$"

EggMoveMaster_Text_3:
	.string "看来你的钱不够学习。\n真遗憾。$"

EggMoveMaster_Text_4:
	.string "谢谢惠顾！\p现在，让我把蛋招式的\n伟大秘密教给你吧。$"

EggMoveMaster_Text_5:
	.string "现在你可以教自己的宝可梦\n蛋招式了！$"

EggMoveMaster_Text_6:
	.string "原来如此。$"
