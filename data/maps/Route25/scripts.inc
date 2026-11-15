.set LOCALID_ROUTE25_MISTY, 10
.set LOCALID_ROUTE25_MAN, 11
.set LOCALID_ROUTE25_SUICUNE, 16
.set LOCALID_ROUTE25_EUSINE, 15
.set LOCALID_CAPE_MISTY, 20

Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route25_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 7, Route25_EventScript_SetSuicuneSceneMid
	end

Route25_EventScript_SetSuicuneSceneMid::
	setobjectxyperm LOCALID_ROUTE25_EUSINE, 65, 9
	end

Route25_EventScript_MistyRematch::
    lock
    faceplayer
    msgbox Route25_Text_Misty, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CAPE_MISTY
    removeobject LOCALID_CAPE_MISTY
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_MISTY
    release
    end

Route25_Text_Misty:
    .string "小霞：我好喜欢这里的夕阳！\n它给了我继续\l前进的勇气，你懂吗？\p没错！\p要是想来一场真正痛快的\n较量，就到格斗道场来找我吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route25_EventScript_Dudley::
	trainerbattle_single TRAINER_DUDLEY Route25_Text_SchoolboyDudleySeen, Route25_Text_SchoolboyDudleyBeaten
	msgbox Route25_Text_SchoolboyDudleyAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Ellen::
	trainerbattle_single TRAINER_ELLEN Route25_Text_LassEllenSeen, Route25_Text_LassEllenBeaten
	msgbox Route25_Text_LassEllenAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Joe::
	trainerbattle_single TRAINER_JOE Route25_Text_SchoolboyJoeSeen, Route25_Text_SchoolboyJoeBeaten
	msgbox Route25_Text_SchoolboyJoeAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA Route25_Text_LassLauraSeen, Route25_Text_LassLauraBeaten
	msgbox Route25_Text_LassLauraAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Lloyd::
	trainerbattle_single TRAINER_LLOYD Route25_Text_CamperLloydSeen, Route25_Text_CamperLloydBeaten
	msgbox Route25_Text_CamperLloydAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON Route25_Text_LassShannonSeen, Route25_Text_LassShannonBeaten
	msgbox Route25_Text_LassShannonAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Pat::
	trainerbattle_single TRAINER_PAT Route25_Text_SupernerdPatSeen, Route25_Text_SupernerdPatBeaten
	msgbox Route25_Text_SupernerdPatAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Kevin::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE25_GOT_NUGGET, Route25_EventScript_KevinAfter
	msgbox Route25_Text_CooltrainerKevinNugget, MSGBOX_DEFAULT
	giveitem ITEM_BIG_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE25_GOT_NUGGET
	msgbox Route25_Text_CooltrainerKevinSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KEVIN, Route25_Text_CooltrainerKevinBeaten
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_DEFAULT
	closemessage
	release
	end
Route25_EventScript_KevinAfter::
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_NPC
	end

Route25_EventScript_BillsHouseSign::
	msgbox Route25_Text_BillsHouseSign, MSGBOX_SIGN
	end

Route25_Trigger_MistyRight::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveRight
	waitmovement 0
	applymovement LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route25_EventScript_Misty
Route25_Trigger_MistyLeft::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveLeft
	waitmovement 0
	applymovement LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route25_EventScript_Misty
Route25_EventScript_Misty::
	msgbox Route25_Text_MistyDate, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE25_MISTY, Route25_Movement_MistyLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_MISTY
	removeobject LOCALID_ROUTE25_MAN
	setflag FLAG_HIDE_ROUTE25_MISTY
	clearflag FLAG_HIDE_CERULEAN_GYM_TRAINERS
	setflag FLAG_HIDE_CERULEAN_GYM_POKEMON
	setvar VAR_CERULEAN_CITY_STATE, 3
	release
	end

Route25_Trigger_SuicuneLeft::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_Trigger_SuicuneRight::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_EventScript_SuicuneMerge::
	clearflag FLAG_HIDE_ROUTE25_EUSINE
	addobject LOCALID_ROUTE25_EUSINE
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox Route25_Text_Eusine1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineSide
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox Route25_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SUICUNE_ENCOUNTERS, 7
	release
	end
	
Route25_Text_Eusine1:
	.string "米那君：呼，呼……\n我……完全不是你的对手。\p……果然如我所料。\n………………\l……去吧。\p自从在缘朱市的烧焦塔\n遇见你，我就隐约\l觉得水君一定会\l选中你。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route25_Text_Eusine2:
	.string "你看吧！\p水君在等着你！\n它一直在等一场战斗，\l等一位值得\l它托付的训练家来交手。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route25_Text_Eusine3:
	.string "{PLAYER}……\n你们俩真是太厉害了……\p我从没见过这么\n激烈的对战！\l我没什么遗憾了……\p再见了，水君！\n再见了……{PLAYER}！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route25_EventScript_Eusine::
	msgbox Route25_Text_Eusine2, MSGBOX_NPC
	end

Route25_EventScript_Suicune::
	lock
	faceplayer
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_SUICUNE, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route25_EventScript_SuicuneRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE25_SUICUNE
	setflag FLAG_HIDE_ROUTE25_SUICUNE
	fadescreenswapbuffers FADE_FROM_BLACK
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 8, Route25_EventScript_SuicunePostGame
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 66, Route25_AdjustPlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject LOCALID_ROUTE25_EUSINE, DIR_NORTH
	msgbox Route25_Text_Eusine3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_EUSINE
	setflag FLAG_HIDE_ROUTE25_EUSINE
	clearflag FLAG_HIDE_CELADON_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 8
	release
	end

Route25_EventScript_SuicuneRan::
	release
	end

Route25_AdjustPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

Route25_EventScript_SuicunePostGame::
	release
	end

Route25_Movement_EusineLeave:
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route25_Movement_EusineSide:
	walk_slow_left
	walk_slow_up
	step_end

Route25_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_slow_up
	step_end

Route25_Movement_Suicune1:
	jump_in_place_down
	step_end

Route25_Movement_WalkToSuicune:
	walk_up
	walk_up
	step_end

Route25_Movement_MistyLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route25_Movement_ManLeaveRight:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
Route25_Movement_ManLeaveLeft:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route25_Movement_MistyWalkToPlayerRight:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end
Route25_Movement_MistyWalkToPlayerLeft:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Route25_Text_MistyDate:
	.string "小霞：哎呀！你为什么\n偏偏这时候来捣乱？\p你知道大家怎么称呼\n你这种人吗？\p捣乱鬼！听到了吗，\n捣乱鬼！\p……\p……哦？你那些徽章……\n是城都地区的道馆徽章？\p要是集齐了八个，\n你就算有本事了。\p好，那就这样。\n到华蓝道馆来吧。\p我很乐意当你的对手。\p我是小霞，\n华蓝道馆的馆主。$"
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

Route25_Text_SchoolboyDudleySeen:
	.string "打赢我们六个训练家，\n就能拿到豪华奖品！\p你觉得你行吗？$"
	.string ""
	.string ""

Route25_Text_SchoolboyDudleyBeaten:
	.string "嚯！打得不错。$"

Route25_Text_SchoolboyDudleyAfter:
	.string "我已尽力，\n没有遗憾。$"
	.string ""

Route25_Text_LassEllenSeen:
	.string "我是第二个。\n接下来是动真格的了！$"
	.string ""

Route25_Text_LassEllenBeaten:
	.string "我怎么可能会输？$"

Route25_Text_LassEllenAfter:
	.string "我已尽力，\n没有遗憾。$"
	.string ""

Route25_Text_SchoolboyJoeSeen:
	.string "3号登场！\n我可不会轻易输。$"
	.string ""

Route25_Text_SchoolboyJoeBeaten:
	.string "哎哟！被踩扁了！$"

Route25_Text_SchoolboyJoeAfter:
	.string "我已尽力，\n没有遗憾。$"
	.string ""

Route25_Text_LassLauraSeen:
	.string "我是4号！\n开始累了吧？$"
	.string ""

Route25_Text_LassLauraBeaten:
	.string "我也输了……$"

Route25_Text_LassLauraAfter:
	.string "我已尽力，\n没有遗憾。$"
	.string ""

Route25_Text_CamperLloydSeen:
	.string "好！我是5号。\n我要把你踩扁！$"
	.string ""

Route25_Text_CamperLloydBeaten:
	.string "哇！太强了。$"

Route25_Text_CamperLloydAfter:
	.string "我已尽力，\n没有遗憾。$"
	.string ""

Route25_Text_LassShannonSeen:
	.string "我是排在最后的，\n不过我告诉你，我很强！$"
	.string ""

Route25_Text_LassShannonBeaten:
	.string "骗人的吧。$"

Route25_Text_LassShannonAfter:
	.string "我已尽力，\n没有遗憾。$"
	.string ""

Route25_Text_SupernerdPatSeen:
	.string "呋呋呋……\p我跟那六个训练家\n没有半点关系。\p我是等在这里，趁你\n被他们打得精疲力尽，\l再来打倒你的。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route25_Text_SupernerdPatBeaten:
	.string "你就一点都不累吗？$"

Route25_Text_SupernerdPatAfter:
	.string "对不起……我再也不\n耍诈了……$"
	.string ""

Route25_Text_CooltrainerKevinNugget:
	.string "你比预想的多打了\n一场对战，\l可还是赢了。\p按约定，奖品归你了。$"
	.string ""
	.string ""
	.string ""

Route25_Text_CooltrainerKevinSeen:
	.string "可是看了你的对战，\n我也想试试身手了。\p怎么样？让我来做\n你的对手吧。$"
	.string ""
	.string ""
	.string ""

Route25_Text_CooltrainerKevinBeaten:
	.string "我从没打过\n这么精彩的对战！$"
	.string ""

Route25_Text_CooltrainerKevinAfter:
	.string "真是一场精彩的对战！\p你和你的宝可梦\n真的很出色！$"
	.string ""
	.string ""

Route25_Text_BillsHouseSign:
	.string "海角的小屋\n正辉的家$"
	.string ""

