

BellchimeTrail_MapScripts::
	.byte 0


BellchimeTrail_EventScript_Morty::
	lock
	faceplayer
	msgbox BellchimeTrail_Text_Morty, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_BELLCHIME_MORTY
	removeobject LOCALID_BELLCHIME_MORTY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_MORTY
	release
	end

BellchimeTrail_Text_Morty:
	.string "松叶：传说的宝可梦\n没有选择我……\p但这并不代表\n我的未来就此失去。\p我要继续修炼，直到\n发现属于我的新未来。\p想再对战的话，\n就到格斗道场来找我。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakBellchimeTrail_EventScript_DoorTrigger::
	lock
	opendoor 28, 12
	waitdooranim
	addobject OBJ_EVENT_ID_CAMERA
	removeobject OBJ_EVENT_ID_PLAYER
	closedoor 28, 12
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakBellchimeTrail_Movement_CameraPanUp
	waitmovement 0
	warp MAP_TIN_TOWER_1F, 1
	release
	end

EcruteakBellchimeTrail_Movement_CameraPanUp::
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

BellchimeTrail_MortyRematch::
	lock
	faceplayer
	msgbox BellchimeTrail_MortyRematch_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq BellchimeTrail_MortyRematch_2
BellchimeTrail_MortyRematch_1:
	release
	end

BellchimeTrail_MortyRematch_2:
	msgbox BellchimeTrail_MortyRematch_Text_1
	trainerbattle_no_intro TRAINER_MORTY_2, BellchimeTrail_MortyRematch_Text_2
	msgbox BellchimeTrail_MortyRematch_Text_3
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_BELLCHIME_MORTY
	removeobject LOCALID_BELLCHIME_MORTY
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	goto BellchimeTrail_MortyRematch_1


BellchimeTrail_MortyRematch_Text_0:
	.string "松叶：最终，传说的\n宝可梦还是没有选择我。\p走在这条小径上时，\n我常常思索原因。\p如果你愿意，{PLAYER}，\n我想再和你对战一次，\l弄清它们这么选的理由。$"

BellchimeTrail_MortyRematch_Text_1:
	.string "谢谢。我要让看着的人知道，\n我也有资格与你比肩！$"

BellchimeTrail_MortyRematch_Text_2:
	.string "我终于明白它们为何选你了。$"

BellchimeTrail_MortyRematch_Text_3:
	.string "光是强大或者聪明，\n有时还远远不够。\l还需要一种你身上有、\l却难以言说的东西。\l愿神灵继续保佑你。\p后会有期。$"
