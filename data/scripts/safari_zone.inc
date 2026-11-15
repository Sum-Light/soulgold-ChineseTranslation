SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	setwarp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE, 9, 3
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE, 9, 3
	waitstate
	end

SafariZone_EventScript_ExitKanto::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 5, 6
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "要现在就退出\n狩猎地带吗？$"
	.string ""

SafariZone_Text_TimesUp:
	.string "叮——咚！时间到！\n狩猎游戏结束了。$"
	.string ""

SafariZone_Text_OutOfBalls:
	.string "狩猎球用完了，\n狩猎游戏结束了。$"
	.string ""

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "要在宝可方块喂食器里\n放置宝可方块吗？$"
	.string ""

SafariZone_Text_PokeblockStillHere:
	.string "之前放进去的{STR_VAR_1}\n还在里面。$"
	.string ""

SafariZone_Text_PokeblockWasPlaced:
	.string "把{STR_VAR_1}放进了\n宝可方块喂食器里。$"
	.string ""

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "欢迎来到狩猎地带！\p在这里，您可以见到许多\n来自其他地区的宝可梦。\p而且，它们都以野生的姿态\n生活在自然的栖息地里。\p不仅如此，我们还向\n宝可梦训练家敞开了大门。\p欢迎各位把宝可梦\n捕捉回去！\p请进，尽情享受狩猎地带的乐趣吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "欢迎来到狩猎地带！\n请问是第一次来这里吗？$"
	.string ""

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "尽情享受狩猎地带的乐趣吧！$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "进入狩猎地带以后，\n会给您30只狩猎球用来捕捉宝可梦，\p狩猎球用完或者您走满500步以后，\n狩猎游戏就会结束。\p尽情享受狩猎地带的乐趣吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "欢迎来到狩猎地带！\p花¥500就可以尽情地捕捉宝可梦！\n要不要参加狩猎游戏呢？$"
	.string ""
	.string ""

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "好的，\n欢迎下次再来！$"
	.string ""

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "抱歉，\n您带的钱不够。$"
	.string ""

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "那么，收您¥500。$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "请收下狩猎球！$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER}得到了\n30个狩猎球。$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "要是时间到了，我们会通知您的。\n所以在那之前，请您尽情享受吧！\l祝您野外探险玩得开心！$"
	.string ""
	.string ""
	.string ""

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "很抱歉，\n您的电脑盒子满了。$"
	.string ""

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "很抱歉，\n似乎您还没有宝可方块盒。\p使用宝可方块的话会让\n您的狩猎游戏更有收获的。\p请带上宝可方块盒再来吧。\p您可以在水静市华丽大赛\n会场获取宝可方块盒。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SafariZone_South_Text_StillHaveTimeExit:
	.string "时间还有剩余，\n确定要结束狩猎游戏吗？$"
	.string ""

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "是吗，那就请您尽情\n享受狩猎游戏吧！$"
	.string ""

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "好的，那么请将剩下的\n狩猎球交给我们吧。\p辛苦了！\n期待您再次参加。$"
	.string ""
	.string ""
	.string ""
	.string ""

SafariZone_South_Text_GoodLuck:
	.string "祝您好运！\p如果您需要什么，\n请随时告诉我！$"
	.string ""
	.string ""

SafariZone_South_Text_Boy:
	.string "知道吗？如果在那个\p方方的箱子里放进宝可方块，\n宝可梦就会聚集到那附近。$"
	.string ""
	.string ""

SafariZone_South_Text_Man:
	.string "我本来想走得更深入一些，\n但我忘记带自行车了。\p直觉告诉我有稀有宝可梦\n生活在比较偏僻的地方。$"
	.string ""
	.string ""
	.string ""

SafariZone_Southwest_Text_Woman:
	.string "有的时候，宝可梦会无视\n我扔出去的宝可方块。\p是不是宝可梦们对于食物\n也有不同的喜好呢？$"
	.string ""
	.string ""
	.string ""

SafariZone_Northwest_Text_Man:
	.string "呼……呼……\n我……终于到这儿了……不过……\p我已经累了……\n没力气去捕捉宝可梦了……$"
	.string ""
	.string ""
	.string ""

SafariZone_North_Text_Fisherman:
	.string "我需要找到一些丰缘地区\n所没有的水属性宝可梦，\p你知道湖泊在哪儿吗？$"
	.string ""
	.string ""

SafariZone_North_Text_Man:
	.string "我要在这里捕捉好多稀有宝可梦，\n然后跟我的朋友们交换！$"
	.string ""

SafariZone_South_Text_Youngster:
	.string "我把宝可方块放到了宝可方块\n喂食器里，但它很快就消失了。\p可能是在我没注意的时候\n被宝可梦吃掉了。$"
	.string ""
	.string ""
	.string ""

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "狩猎地带公告牌！\p向野生宝可梦投掷宝可方块，\n可以降低它们逃跑的可能性。$"
	.string ""
	.string ""

SafariZone_Southwest_Text_RestHouseSign:
	.string "“放松一下你疲惫的双脚吧”\n休息小屋$"
	.string ""

SafariZone_RestHouse_Text_Youngster:
	.string "我没有宝可方块，\n但我还是捕捉了很多宝可梦。\p先小心地接近，\n然后再扔出狩猎球，\l就更有可能捕捉到它们。$"
	.string ""
	.string ""
	.string ""
	.string ""

SafariZone_RestHouse_Text_PsychicM:
	.string "如果使用宝可方块，野生宝可梦\n就不会那么容易逃跑。\p而对那些本就不太容易逃跑的宝可梦，\n使用宝可方块效果不大。$"
	.string ""
	.string ""
	.string ""

SafariZone_RestHouse_Text_FatMan:
	.string "放在喂食器里的宝可方块\n能够把宝可梦吸引来。\p我想有相似性格的宝可梦\n会被同一种宝可方块吸引。$"
	.string ""
	.string ""
	.string ""

SafariZone_South_Text_AreaOffLimits1:
	.string "此处正在建设中，\n禁止入内。$"
	.string ""

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "狩猎地带的扩建\n已经完工。\p希望您能喜欢新的区域。$"
	.string ""
	.string ""

SafariZone_South_Text_AreaOffLimits2:
	.string "此处正在建设中，\n禁止入内。$"
	.string ""

SafariZone_Southeast_Text_LittleGirl:
	.string "呀～嗬！这些宝可梦\n都是我从来没见过的！$"
	.string ""

SafariZone_Southeast_Text_FatMan:
	.string "这些宝可梦\n我还是第一次见到，\p而且我还能捕捉这些\n稀有宝可梦！太棒了！$"
	.string ""
	.string ""
	.string ""

SafariZone_Southeast_Text_RichBoy:
	.string "这里的宝可梦好像是从\n丰缘以外的地区来的。$"
	.string ""

SafariZone_Northeast_Text_Boy:
	.string "我的狩猎球不剩几个了，\p我得好好考虑一下\n要捕捉什么样的宝可梦。$"
	.string ""
	.string ""

SafariZone_Northeast_Text_Woman:
	.string "据说有人在这附近发现过皮卡丘，\n究竟在哪儿呢？$"
	.string ""

SafariZone_Northeast_Text_Girl:
	.string "啊，真烦！\n怎么都抓不到宝可梦！\p要是再不捕捉些什么的话\n我就不在这儿浪费钱了！$"
	.string ""
	.string ""
	.string ""

Route121_SafariZoneEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_SafariZoneEntrance_OnFrame
	.byte 0

Route121_SafariZoneEntrance_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, Route121_SafariZoneEntrance_EventScript_ExitSafariZone
	.2byte 0

Route121_SafariZoneEntrance_EventScript_ExitSafariZone::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route121_SafariZoneEntrance_EventScript_WelcomeAttendant::
	msgbox Route121_SafariZoneEntrance_Text_WelcomeToSafariZone, MSGBOX_NPC
	end

Route121_SafariZoneEntrance_EventScript_InfoAttendant::
	lock
	faceplayer
	msgbox Route121_SafariZoneEntrance_Text_WelcomeFirstTime, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_FirstTimeInfo
	msgbox Route121_SafariZoneEntrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_FirstTimeInfo::
	msgbox Route121_SafariZoneEntrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NoPokeblockCase
	call Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NotEnoughMoney
	playse SE_SHOP
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_SAFARI_ZONE_SOUTH, 32, 33
	waitstate
	end

Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

Route121_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_right
	step_end

Route121_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	delay_16
	step_end

Route121_SafariZoneEntrance_EventScript_TrainerTipSign::
	msgbox Route121_SafariZoneEntrance_Text_TrainerTip, MSGBOX_SIGN
	end
