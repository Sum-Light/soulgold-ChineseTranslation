.set LOCALID_ROUTE14_SUICUNE, 5
.set LOCALID_ROUTE14_EUSINE, 6
.set LOCALID_ROUTE14_PIDGEOTTO, 9

Route14_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route14_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route14_TriggerSuicune_5::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_5
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_4::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_4
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_3::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_3
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_2::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_1::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	goto Route14_EventScript_Suicune

Route14_Movement_5:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_4:
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_3:
	walk_right
	walk_right
	step_end

Route14_EventScript_Suicune::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE14_SUICUNE, Route14_Movement_SuicuneLeave
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE14_EUSINE
	addobject LOCALID_ROUTE14_EUSINE
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineEnter
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 0
	msgbox Route14_Text_Eusine, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineLeave
	waitmovement 0
	setflag FLAG_HIDE_ROUTE14_EUSINE
	setflag FLAG_HIDE_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 5
	call_if_ge VAR_CERULEAN_CITY_STATE, 3, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

Route14_Movement_SuicuneLeave:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	step_end

Route14_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_slow_up
	walk_slow_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	walk_slow_right
	step_end

Route14_Movement_EusineLeave:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER Route14_Text_PokefanmCarterSeen, Route14_Text_PokefanmCarterBeaten
	msgbox Route14_Text_PokefanmCarterAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Roy::
	trainerbattle_single TRAINER_ROY Route14_Text_BirdKeeperRoySeen, Route14_Text_BirdKeeperRoyBeaten
	msgbox Route14_Text_BirdKeeperRoyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Trevor::
	trainerbattle_single TRAINER_TREVOR Route14_Text_PokefanmTrevorSeen, Route14_Text_PokefanmTrevorBeaten
	msgbox Route14_Text_PokefanmTrevorAfterBattle, MSGBOX_AUTOCLOSE
	end



Route14_Text_Eusine:
	.string "米那君：{PLAYER}！又是这样！\n下次我一定比你先到！\p追着它来到这里，\n我渐渐明白\l水君想要做什么了。\p说实话，这些信息\n我本来想自己留着。\p但在水君面前，\n我想当一个诚实的训练家！\p所以，我分你一条线索。\p看来……\n水君喜欢地势高的地方……\l靠近水边……\l还要偏北……\p具体在哪里，我还不知道。\n这次就只有你和我！\p看谁先找到它？\n我向你发出挑战！$"
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
	.string ""
	.string ""

Route14_Text_PokefanmCarterSeen:
	.string "跟你说，我抓到这只心爱的\n宝可梦可费了不少劲。$"
	.string ""

Route14_Text_PokefanmCarterBeaten:
	.string "呜哇啊！$"

Route14_Text_PokefanmCarterAfterBattle:
	.string "小锯鳄、火球鼠、菊草叶……\p我觉得这个搭配\n相当均衡。$"
	.string ""

Route14_Text_BirdKeeperRoySeen:
	.string "和心爱的鸟宝可梦\n一起飞翔，是我的梦想。$"
	.string ""

Route14_Text_BirdKeeperRoyBeaten:
	.string "做梦可以，\n可我怎么也飞不起来……$"

Route14_Text_BirdKeeperRoyAfterBattle:
	.string "你的宝可梦会秘传招式飞翔吧？\n真羡慕你。$"
	.string ""

Route14_Text_PokefanmTrevorSeen:
	.string "你好。你知道吗……？\p在宝可梦记得的地方训练，\n它会变得更亲近你。$"
	.string ""
	.string ""
	.string ""

Route14_Text_PokefanmTrevorBeaten:
	.string "我是在哪儿\n遇见这只巨钳螳螂的？$"

Route14_Text_PokefanmTrevorAfterBattle:
	.string "要是有个简单办法，\n能看出宝可梦的来处就好了……$"
	.string ""

Route14_EventScript_Pidgeotto::
	lockall
	faceplayer
	playmoncry SPECIES_PIDGEOTTO, CRY_MODE_NORMAL
	msgbox Route14_Text_Pidgeotto, MSGBOX_DEFAULT
	waitmoncry
	goto_if_set FLAG_GOT_ROUTE_14_AERIAL_ACE, Route14_EventScript_PidgeottoBlowPlayer
	msgbox Route14_Text_PidgeottoBerry, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route14_EventScript_PidgeottoBlowPlayer
	@chooseitem BERRIES_POCKET
	removeitem VAR_ITEM_ID, 1
	goto_if_ne VAR_ITEM_ID, ITEM_QUALOT_BERRY, Route14_EventScript_PidgeottoDislikedBerry
	msgbox Route14_Text_PidgeottoAteBerry, MSGBOX_DEFAULT
	setflag FLAG_GOT_ROUTE_14_AERIAL_ACE
Route14_EventScript_PidgeottoBlowPlayer::
	closemessage
	playse SE_M_TWISTER
	call_if_eq VAR_FACING, DIR_EAST, Route14_EventScript_PidgeottoBlowPlayerLeft
	releaseall
	end
Route14_EventScript_PidgeottoDislikedBerry::
	msgbox Route14_Text_PidgeottoTurnedAway, MSGBOX_DEFAULT
	goto Route14_EventScript_PidgeottoBlowPlayer

Route14_EventScript_PidgeottoBlowPlayerLeft::
	applymovement LOCALID_ROUTE14_PIDGEOTTO, Route14_Movement_JumpLeft
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_Player_BlownLeft
	waitmovement 0
	return

Route14_Movement_Player_BlownUp:
	lock_facing_direction
	walk_up
	walk_up
	unlock_facing_direction
	step_end

Route14_Movement_Player_BlownLeft:
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	lock_facing_direction
	walk_left
	walk_left
	unlock_facing_direction
	step_end

Route14_Movement_JumpUp:
	jump_in_place_up
	step_end

Route14_Movement_JumpLeft:
	jump_in_place_left
	step_end

Route14_Movement_StuckPidgeottoJump0:
	jump_in_place_up
	step_end

Route14_Movement_StuckPidgeottoJump:
	jump_2_up
	jump_in_place_left_right
	jump_in_place_left_right
	face_left
	step_end

Route14_Text_Pidgeotto:
	.string "比比鸟：嘎啊啊啊！$"
Route14_Text_PidgeottoBerry:
	.string "要给比比鸟树果吗？$"
Route14_Text_PidgeottoAteBerry:
	.string "比比鸟高兴地吃下了比巴果！$"
Route14_Text_PidgeottoTurnedAway:
	.string "比比鸟不喜欢！$"

