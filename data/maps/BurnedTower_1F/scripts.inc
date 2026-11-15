.set LOCALID_BURNED_TOWER_SILVER, 3
.set LOCALID_BURNED_TOWER_EUSINE, 1

BurnedTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x4FE, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	createfieldmugshot MUGSHOT_EUSINE
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "米那君：我叫米那君。\p我正在追寻一只\n名叫水君的宝可梦。\p你是……？\p{PLAYER}？很高兴认识你！\p听说水君可能就在\n这座烧焦塔里，\l所以我过来看看。\p可它到底会在哪里呢？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "米那君：听说水君可能就在\n这座烧焦塔里，\l所以我过来看看。\p可它到底会在哪里呢？$"
	.string ""
	.string ""
	.string ""

BurnedTower_1FMortyText:
	.string "松叶：圆朱的道馆馆主，\n必须研究被称为\l传说的宝可梦的\l水君、炎帝和雷公。\p既然米那君来了，\n我就决定和他一起\l调查这座塔。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	createfieldmugshot MUGSHOT_SILVER
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	createfieldmugshot MUGSHOT_SILVER
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x4FE, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	createfieldmugshot MUGSHOT_SILVER
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	removefieldmugshot
	warphole MAP_BURNED_TOWER_B1F
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	waitstate
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "………………\p……哦，是你啊。\p听说有传说的宝可梦\n栖息在这里，\l我才过来找的。\p可这里什么都没有！\p特地跑到这种破地方来，\n结果却什么都没有？\l开什么玩笑！\p这全都怪你！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BurnedTowerSilver_WinText:
	.string "……哼！\p我会输，只是因为\n我的宝可梦太弱了。\p真没用。$"
	.string ""
	.string ""
	.string ""

BurnedTowerSilver_AfterText1:
	.string "……算了，无所谓。\p反正你也不可能\n抓到传说的宝可梦。$"
	.string ""
	.string ""

BurnedTowerSilver_LossText:
	.string "……哼！\p所以我才讨厌和弱者对战，\n纯粹是浪费时间。$"
	.string ""
	.string ""

BurnedTowerSilver_AfterText2:
	.string "哼！\p居然会掉进洞里，\n你在干什么？真是个天才！\p活该！$"
	.string ""
	.string ""
	.string ""

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "别担心！\p我们喷火人比谁都清楚\n火焰真正的威力！$"
	.string ""
	.string ""
BurnedTower_Text_NardBeaten:
	.string "谢谢你带来这么火热的对战！$"
BurnedTower_Text_NardAfter:
	.string "这座塔之所以会烧毁，\n是因为被雷击中了。\p跟那比起来，\n我喷出的火根本微不足道……$"
	.string ""
	.string ""
	.string ""

BurnedTower_Text_RichardoSeen:
	.string "我正在烧焦塔里\n练习偷东西！\p好孩子可不要模仿哦！$"
	.string ""
	.string ""
BurnedTower_Text_RichardoBeaten:
	.string "噗噗噗噗噗……$"
BurnedTower_Text_RichardoAfter:
	.string "也许我不适合\n走犯罪这条路……$"
	.string ""
