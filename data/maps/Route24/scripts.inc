.set LOCALID_ROUTE24_WOMAN, 4
.set LOCALID_ROUTE24_MAN, 3
.set LOCALID_ROUTE24_GRUNT, 1

Route24_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route24_OnTransition:
	call_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_MapScript_SetRocketScene
	callnative SetTimeBasedEncounters
	end

Route24_MapScript_SetRocketScene:
	setobjectxyperm LOCALID_ROUTE24_GRUNT, 10, 28
	setobjectxyperm LOCALID_ROUTE24_WOMAN, 10, 29
	setobjectmovementtype LOCALID_ROUTE24_GRUNT, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_ROUTE24_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ROUTE24_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

Route24_EventScript_Woman::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_WomanRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_WomanAfterRocket
	msgbox Route24_Text_Woman, MSGBOX_NPC
	end

Route24_EventScript_WomanRocket::
	msgbox Route24_Text_WomanRocket, MSGBOX_NPC
	end

Route24_EventScript_WomanAfterRocket::
	msgbox Route24_Text_WomanAfterRocket, MSGBOX_NPC
	end

Route24_EventScript_Man::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_ManRocket
		goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_ManAfterRocket
	msgbox Route24_Text_Man, MSGBOX_NPC
	end

Route24_EventScript_ManRocket::
	msgbox Route24_Text_ManRocket, MSGBOX_NPC
	end

Route24_EventScript_ManAfterRocket::
	msgbox Route24_Text_ManAfterRocket, MSGBOX_NPC
	end

Route24_Trigger_GruntScene::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE24_GRUNT Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntHide
	delay 10
	applymovement LOCALID_ROUTE24_WOMAN, Route24_Movement_WomanMove
	waitmovement 0
	turnobject LOCALID_ROUTE24_MAN, DIR_SOUTH
	setvar VAR_KANTO_ROCKET_STORY_STATE, 4
	call Route24_MapScript_SetRocketScene
	release
	end

Route24_Movement_GruntHide:
	walk_fast_left
	walk_fast_left
	step_end

Route24_Movement_WomanMove:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

Route24_EventScript_Grunt::
	lock
	faceplayer
	msgbox Route24_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_31, Route24_Text_RocketBeaten
	msgbox Route24_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement FLAG_HIDE_CERULEAN_CAPE_ROCKET, Common_Movement_QuestionMark
	delay 50
	msgbox Route24_Text_RocketDisappears, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_PlayerSlide
	delay 20
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntLeave
	waitmovement LOCALID_ROUTE24_GRUNT
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	removeobject LOCALID_ROUTE24_GRUNT
	setvar VAR_KANTO_ROCKET_STORY_STATE, 5
	clearflag FLAG_HIDDEN_ITEM_MACHINE_PART
	release
	end

Route24_Movement_PlayerSlide:
	delay_16
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

Route24_Movement_GruntLeave:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route24_Text_RocketSeen:
	.string "嘿，小家伙！火箭队的人，\n我是！\p从别国来的，\n第一的训练家，我！\p我想，电停下，\n这里的人，大恐慌！\p秘密的任务，我有，\n所以告诉你，我不！\p但是！对战赢了我，\n说话算话，我，秘密\l全告诉你！\p嘿，小家伙！对战，开始，我们！$"
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

Route24_Text_RocketBeaten:
	.string "哇呀呀！不，不，不，\n信不了，我！\p你，非常强！\n不是对手，我！$"
	.string ""
	.string ""
	.string ""

Route24_Text_RocketAfter:
	.string "好。秘密，告诉你，我。\n机械零件，偷了，藏起来\l在华蓝道馆。\p水里面，放了。\n道馆的水中央，找吧。\p但是，忘了我，不行！\p火箭队，一定赢你，\n肯定的。\p城都的同伙，会来的，\n我的伙伴，是的。报复，\l他们会的。$"
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

Route24_Text_RocketDisappears:
	.string "……\p你说什么？火箭队，\n拜拜没了吗？坏了，\l你说？\p哦，不！怎么办，现在，\n我？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""



Route24_Text_Woman:
	.string "景色真美啊。$"
Route24_Text_Man:
	.string "我可以在这儿待一整天。$"

Route24_Text_WomanRocket:
	.string "谁也别推我！$"
Route24_Text_ManRocket:
	.string "谁也别推我女朋友！$"

Route24_Text_WomanAfterRocket:
	.string "刚才那到底是怎么回事？$"
Route24_Text_ManAfterRocket:
	.string "刚才那是火箭队的人吗？$"
