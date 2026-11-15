.set LOCALID_SAFARIZONEGATE_BAOBA, 1

SafariZoneGate_SafariZoneEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZoneGate_SafariZoneEntrance_OnFrame
	.byte 0

SafariZoneGate_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 3, SafariZoneGate_SafariZoneEntrance_MeetBaoba
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZoneGate_SafariZoneEntrance_EventScript_ExitSafari
	.2byte 0

SafariZoneGate_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_ReenterSafari
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	warp MAP_SAFARI_ZONE_ENTERANCE, 0
	delay 120
	end

SafariZoneGate_SafariZoneEntrance_MeetBaoba::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, SafariZoneGate_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEGATE_BAOBA
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaWelcome, MSGBOX_DEFAULT
	closemessage
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaPokeblocks, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, SafariZoneGate_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	setvar VAR_SAFARI_ZONE_GATE_STATE, 4
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Baoba::
	lock
	faceplayer
	goto_if_eq VAR_BAOBA_QUEST_STATE, 1, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBeach
	goto_if_eq VAR_BAOBA_QUEST_STATE, 2, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBrush
	goto_if_eq VAR_BAOBA_QUEST_STATE, 3, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaMountain
	goto_if_eq VAR_BAOBA_QUEST_STATE, 4, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaCave
	goto_if_ge VAR_BAOBA_QUEST_STATE, 5, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDone
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Baoba, MSGBOX_DEFAULT 
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBeach::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 1
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBeachDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 200000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 2
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBrush::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBrush, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 2
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBrushDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 300000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 3
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaMountain::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaMountain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 3
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaMountainDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 400000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 4
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaCave::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaCave, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 4
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaCaveDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 400000
	delay 20
	playse SE_SHOP
	updatemoneybox
	delay 20
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 5
	release
	end

SafarioneEntrance_EventScript_BaobaWrong::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaWrong, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined:
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDone::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaDone, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Test::
	givemon SPECIES_BELDUM, 5
	givemon SPECIES_CASTFORM, 5
	givemon SPECIES_MEDICHAM, 5
	givemon SPECIES_BAGON, 5
	end

SafariZoneGate_SafariZoneEntrance_Text_BaobaBeachDone:
	.string "谢谢你，{PLAYER}！\n这钱给你，用来提升\l你的狩猎等级，\l下次再让我看看\l灌木区来的特别的宝可梦吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	
SafariZoneGate_SafariZoneEntrance_Text_BaobaBrushDone:
	.string "谢谢你，{PLAYER}！\n这钱给你，用来提升\l你的狩猎等级，\l下次再让我看看\l山区来的特别的宝可梦吧！$"
	.string ""
	.string ""
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_BaobaMountainDone:
	.string "谢谢你，{PLAYER}！\n这钱给你，用来提升\l你的狩猎等级，\l下次再让我看看\l洞窟区来的特别的宝可梦吧！$"
	.string ""
	.string ""
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_BaobaCaveDone:
	.string "谢谢你，{PLAYER}！\n我想看的都看过了。\p既然知道得文公司在搞\n什么名堂，我的狩猎地带\l就能保持竞争力。\l这点钱就当是辛苦费。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_BaobaWrong:
	.string "这不可能啊！$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaBeach:
	.string "啊，{PLAYER}！\p你从浅红狩猎地带的沙滩区\n带来了特别的宝可梦\l给我看吗？$"
	.string ""
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_BaobaBrush:
	.string "啊，{PLAYER}！\p你从浅红狩猎地带的灌木区\n带来了特别的宝可梦\l给我看吗？$"
	.string ""
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_BaobaMountain:
	.string "啊，{PLAYER}！\p你从浅红狩猎地带的山区\n带来了特别的宝可梦\l给我看吗？$"
	.string ""
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_BaobaCave:
	.string "啊，{PLAYER}！\p你从浅红狩猎地带的洞窟区\n带来了特别的宝可梦\l给我看吗？$"
	.string ""
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_BaobaDeclined:
	.string "我该怎么办啊？\n这样可追不上得文公司！$"
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_BaobaLastMon:
	.string "我不能收下你最后一只宝可梦！$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaDone:
	.string "啊，{PLAYER}！\p多亏了你，狩猎地带\n才这么兴旺！\p也许我该封你做\n狩猎地带的主人……\p不，那也太荒唐了。\n啊哈哈哈哈。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZoneGate_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, SafariZoneGate_SafariZoneEntrance_EventScript_NoPokeblockCase
	call SafariZoneGate_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, SafariZoneGate_SafariZoneEntrance_EventScript_NotEnoughMoney
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_SAFARI_ZONE_ENTERANCE, 0
	waitstate
	end

SafariZoneGate_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

SafariZoneGate_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Engineer::
	lock
	faceplayer
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Engineer, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SafariZoneGate_SafariZoneEntrance_Text_BaobaWelcome:
	.string "你好，{PLAYER}！\n我一直在等你，你觉得怎么样？\p顺便说一下，这是全新的\n狩猎地带……\p而且还在扩建！\p目前已经开放了两个区域，\n还有4个在建设中！\p好好享受狩猎地带吧！\n等别的区域建好了\l我再叫你！$"
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

SafariZoneGate_SafariZoneEntrance_Text_BaobaPokeblocks:
	.string "哦！我差点忘了。\p宝可方块是我这狩猎地带\n不可或缺的东西，\l这个你可得收下！$"
	.string ""
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_Baoba:
	.string "你好，{PLAYER}！\p狩猎地带玩得\n开心吗？$"
	.string ""
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_Boy:
	.string "听说他们正在建的新区域\n有龙宝可梦！$"
	.string ""

SafariZoneGate_SafariZoneEntrance_Text_Engineer:
	.string "对不起，训练家，这片区域\n还在施工中。\l请您过些时候再来！$"
	.string ""
	.string ""
