.set LOCALID_ECRUTEAK_ROCKET, 12
.set LOCALID_ECRUTEAK_ZUKI, 5
.set LOCALID_SURF_GUY, 7
.set LOCALID_ECRUTEAK_NAOKO, 2
.set LOCALID_ECRUTEAK_MIKI, 4
.set LOCALID_ECRUTEAK_SAYO, 1
.set LOCALID_ECRUTEAK_KUNI, 3
.set LOCALID_ECRUTEAK_SISTER, 11


EcruteakCity_Theater_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_Theater_OnTransition
	.byte 0

EcruteakCity_Theater_OnTransition::
	call_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_MapScript_SetRocketSceneActive
	call_if_eq VAR_ECRUTEAK_CITY_THEATER, 7, EcruteakCity_Theater_MapScript_SetKimonoMovement
	goto_if_set FLAG_IS_CHAMPION, EcruteakTheater_ShowOrHideMeloetta
	setflag FLAG_HIDE_MELOETTA
	end

EcruteakTheater_ShowOrHideMeloetta::
	goto_if_unset FLAG_CAUGHT_MELOETTA, EcruteakTheater_ShowMeloetta
	goto EcruteakTheater_HideMeloetta

EcruteakTheater_ShowMeloetta::
	clearflag FLAG_HIDE_MELOETTA
	return
EcruteakTheater_HideMeloetta::
	setflag FLAG_HIDE_MELOETTA
	return

EcruteakCity_Theater_MapScript_SetRocketSceneActive::
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	return

EcruteakCity_Theater_MapScript_SetKimonoMovement::
	setobjectmovementtype LOCALID_ECRUTEAK_ZUKI, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_NAOKO, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_MIKI, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_SAYO, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_KUNI, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_SISTER, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	return

EcruteakCity_Theater_EventScript_RocketEventTrigger::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 60
	turnobject LOCALID_ECRUTEAK_ROCKET, DIR_NORTH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakCity_Theater_Movement_CameraPanUp
	waitmovement 0
	createfieldmugshot MUGSHOT_ROCKET_GRUNT_M
	msgbox EcruteakCity_Theater_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_KimonoRocket1, MSGBOX_DEFAULT
	closemessage
	createfieldmugshot MUGSHOT_ROCKET_GRUNT_M
	msgbox EcruteakCity_Theater_Text_Rocket2, MSGBOX_DEFAULT
	removefieldmugshot
	applymovement LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_KimonoGirlMoveBack
	waitmovement 0
	createfieldmugshot MUGSHOT_ROCKET_GRUNT_M
	msgbox EcruteakCity_Theater_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakCity_Theater_Movement_RocketDance
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakCity_Theater_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setvar VAR_ECRUTEAK_CITY_THEATER, 1
	releaseall
	end

EcruteakCity_Theater_Movement_RocketDance:
	walk_in_place_down
	delay_2
	walk_in_place_right
	delay_2
	face_up
	delay_2
	face_left
	delay_8
	walk_in_place_down
	delay_2
	walk_in_place_left
	delay_2
	face_up
	delay_8
	face_right
	step_end

EcruteakCity_Theater_Movement_CameraPanUp:
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

EcruteakCity_Theater_Movement_CameraPanDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

EcruteakCity_Theater_Movement_KimonoGirlMoveBack:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

EcruteakCity_Theater_Text_Rocket1:
	.string "火箭队：别跳这么正经的\n舞！给我跳段\l草裙舞看看！$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_KimonoRocket1:
	.string "和服女孩：……您不能\n对我提这种要求的。$"
	.string ""

EcruteakCity_Theater_Text_Rocket2:
	.string "火箭队：啥？\p你的意思是，\n你不把客人的要求\l放在眼里？$"
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_Rocket3:
	.string "那好，我来教教你们\n怎么跳舞。我给你们\l跳一段精彩的。\p哇哈哈哈！$"
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_EventScript_Rocket::
	lock
	faceplayer
	msgbox EcruteakCity_Theater_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_33, EcruteakCity_Theater_Text_RocketBeaten
	msgbox EcruteakCity_Theater_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakCity_Theater_Movement_RocketLeave
	waitmovement 0
	setflag FLAG_HIDE_ECRUTEAK_ROCKET
	removeobject LOCALID_ECRUTEAK_ROCKET
	call_if_eq VAR_FACING, DIR_EAST, EcruteakCity_Theater_EventScript_PostRocketLeft
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_Theater_EventScript_PostRocketRight
	call_if_eq VAR_FACING, DIR_SOUTH, EcruteakCity_Theater_EventScript_PostRocketTop
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox EcruteakCity_Theater_Text_KimonoRocket3, MSGBOX_DEFAULT
	closemessage	
	setvar VAR_ECRUTEAK_CITY_THEATER, 2
	release
	end
	
EcruteakCity_Theater_EventScript_PostRocketLeft::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakCity_Theater_EventScript_PostRocketRight::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakCity_Theater_EventScript_PostRocketTop::
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

EcruteakCity_Theater_Movement_RocketLeave:
	jump_2_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

EcruteakCity_Theater_Text_RocketSeen:
	.string "咦？你是谁？\n竟敢来碍我的事？$"
	.string ""

EcruteakCity_Theater_Text_RocketBeaten:
	.string "哎呀！\n这么一闹，我不就\l成了坏人了吗！$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_RocketAfter:
	.string "糟了！我还有重要的任务！\n要是被发现我在这儿\l浪费时间，就得从\l最底层的小兵重新干起！\p我还是赶紧走吧！$"
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_KimonoRocket3:
	.string "你是{PLAYER}，\n没错吧？刚才真是\l精彩极了。\p既温柔又强大……\n宝可梦也培养得很好……\p那个人看人的眼光\n果然没错……\p哦呵呵！我只是在\n自言自语而已。\l别放在心上。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""


EcruteakCity_Theater_EventScript_KimonoGirl::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 6, EcruteakCity_Theater_EventScript_KimonoGirlDuringEvent
	msgbox EcruteakCity_Theater_Text_KimonoDone, MSGBOX_DEFAULT
	closemessage
	release
	end
EcruteakCity_Theater_EventScript_KimonoGirlDuringEvent::
	msgbox EcruteakCity_Theater_Text_KimonoGirlsBeforeBattle, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Zuki::
	lock
	faceplayer
	goto_if_ge VAR_ECRUTEAK_CITY_THEATER, 7, EcruteakCity_Theater_EventScript_ZukiAfterLegendary
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 6, EcruteakCity_Theater_EventScript_ZukiBattle
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_ZukiDuringRocket
	msgbox EcruteakCity_Theater_Text_Kimono, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_ZukiAfterLegendary::
	msgbox EcruteakCity_Theater_Text_ZukiAfterAll, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_ZukiDuringRocket::
	msgbox EcruteakCity_Theater_Text_KimonoGirlBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Text_Kimono:
	.string "对我们和服女孩来说，\n跳舞就是一切。\p我从来没有一天\n不练习跳舞。\p宝可梦也一样。\n它们每天都和你一起\l一点一点地成长。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_EventScript_SurfGuy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_SurfGuyDuringRocket
	goto_if_unset FLAG_RECEIVED_HM_SURF, EcruteakCity_Theater_EventScript_SurfGuy_GiveSurf
	msgbox EcruteakCity_Theater_Text_SurfGuyAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_SurfGuy_GiveSurf::
	msgbox EcruteakCity_Theater_Text_SurfGuyGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_SOUTHPASSAGE_ARIANA
	setflag FLAG_RECEIVED_HM_SURF
	msgbox EcruteakCity_Theater_Text_SurfGuyGaveSurf
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_CITY_THEATER, 3
	release
	end

EcruteakCity_Theater_EventScript_SurfGuyDuringRocket::
	msgbox EcruteakCity_Theater_Text_SurfGuyRocket, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_TriggerSurfGuy::
	lock
	applymovement LOCALID_SURF_GUY, EcruteakCity_Theater_Movement_SurfGuy1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox EcruteakCity_Theater_Text_SurfGuyGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox EcruteakCity_Theater_Text_SurfGuyGaveSurf
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_CITY_THEATER, 3
	applymovement LOCALID_SURF_GUY, EcruteakCity_Theater_Movement_SurfGuy2
	waitmovement 0 
	release
	end

EcruteakCity_Theater_EventScript_Lotad::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PACHIRISU, CRY_MODE_NORMAL
	msgbox EcruteakCity_Theater_Text_Lotad, MSGBOX_DEFAULT
	waitmoncry
	release
	end


EcruteakCity_Theater_EventScript_Boy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_BoyDuringRocket
	msgbox EcruteakCity_Theater_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_BoyDuringRocket::
	msgbox EcruteakCity_Theater_Text_BoyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Granny::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GrannyDuringRocket
	msgbox EcruteakCity_Theater_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GrannyDuringRocket::
	msgbox EcruteakCity_Theater_Text_GrannyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GrampsDuringRocket
	msgbox EcruteakCity_Theater_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GrampsDuringRocket::
	msgbox EcruteakCity_Theater_Text_GrampsBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_Girl::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GirlDuringRocket
	msgbox EcruteakCity_Theater_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GirlDuringRocket::
	msgbox EcruteakCity_Theater_Text_GirlBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_FancyPanel::
	lock
	msgbox EcruteakCity_Theater_Text_FancyPanel, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Movement_SurfGuy1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

EcruteakCity_Theater_Movement_SurfGuy2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EcruteakCity_Theater_Text_SurfGuyRocket:
	.string "那个火箭队手下\n到底想干嘛，居然\l去骚扰那位和服女孩？\p你是训练家吧？\n请你帮帮她！$"
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_SurfGuyGiveSurf:
	.string "太好了！小小年纪，\n真是有勇气！\p这样的场面可不多见！\n这个就给你了。\p别客气——拿去吧！$"
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_SurfGuyGaveSurf:
	.string "那是冲浪。\n是能让宝可梦\l在水面上轻松游动的招式。$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_SurfGuyAfter:
	.string "和服女孩们不光舞跳得好，\n在宝可梦上也\l很有一套。\p不过她们只会\n为了正当的理由对战。\p要是她们拿出真本事，\n不知道你赢不赢得了……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_Lotad:
	.string "帕奇利兹：帕奇帕奇！$"

EcruteakCity_Theater_Text_BoyBefore:
	.string "呀啊啊——！$"

EcruteakCity_Theater_Text_Boy:
	.string "本来该我出风头的……！\n想接近和服女孩，\l这下全泡汤了！$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_Granny:
	.string "那个人总是带着他的\n可达鸭。\p他说想要一只既会冲浪\n又会跳舞的宝可梦。\p他这是想让宝可梦\n去当花样游泳的\l明星吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_GrannyBefore:
	.string "哎哟……好痛……！\n这肚子疼得！\p要不是肚子疼，\n我哪能由着这家伙胡来……！$"
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_Gramps:
	.string "和服女孩们真美啊……\p可她们要经过\n严格的修行。\p而且在人前露面之前，\n还得学会遵守\l种种规矩。\p不过，只要真心喜欢，\n什么都能做到。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_GrampsBefore:
	.string "哎哟……好痛……！\n这腰疼得！\p要不是腰疼，\n我哪能由着这家伙胡来……！$"
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_Girl:
	.string "和服女孩们是我的姐姐！\n我以后也要\l像她们一样！$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_GirlBefore:
	.string "那个舞真好玩！$"

EcruteakCity_Theater_Text_FancyPanel:
	.string "是一块装饰着花朵的\n漂亮屏风。$"
	.string ""

EcruteakCity_Theater_Trigger_PreBattleCutsceneLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene

EcruteakCity_Theater_Trigger_PreBattleCutsceneTop::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiTop
	applymovement OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiTop
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene

EcruteakCity_Theater_Trigger_PreBattleCutsceneRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiRight
	applymovement OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene


EcruteakCity_Theater_Movement_PlayerWalkToZukiLeft:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiLeft:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

EcruteakCity_Theater_Movement_PlayerWalkToZukiTop:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiTop:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

EcruteakCity_Theater_Movement_PlayerWalkToZukiRight:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiRight::
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


EcruteakCity_Theater_Movement_KimonoSpin:
	face_right
	delay_8
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
	step_end

EcruteakCity_Theater_EventScript_LugiaBuffer::
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA
	return
EcruteakCity_Theater_EventScript_HoohBuffer::
	bufferspeciesname STR_VAR_1, SPECIES_HO_OH
	return
EcruteakCity_Theater_EventScript_LegendaryCutscene::
	call_if_eq VAR_LUGIA_OR_HOOH, 1, EcruteakCity_Theater_EventScript_LugiaBuffer
	call_if_eq VAR_LUGIA_OR_HOOH, 2, EcruteakCity_Theater_EventScript_HoohBuffer 
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_ZukiSeen, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 6
EcruteakCity_Theater_EventScript_ZukiBattle::
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_ZukiSeenAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, EcruteakCity_Theater_EventScript_LegendaryDenied
	call_if_eq VAR_FACING, DIR_SOUTH, EcruteakCity_Theater_Movement_SouthCorrection
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_Theater_Movement_WestCorrection
	call_if_eq VAR_FACING, DIR_EAST, EcruteakCity_Theater_Movement_EastCorrection
	trainerbattle_no_intro TRAINER_ZUKI, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_ZukiWalkUp
	waitmovement 0
EcruteakCity_Theater_EventScript_NaokoBattle::
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_NaokoWalkToPlayer
	waitmovement 0
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_NaokoSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NAOKO, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_NaokoWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_MikiBattle::
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_MikiWalkToPlayer
	waitmovement 0
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_MikiSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MIKI, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_MikiWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_SayoBattle::
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_SayoWalkToPlayer
	waitmovement 0
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_SayoSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAYO, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_SayoWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_KuniBattle::
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KuniWalkToPlayer
	waitmovement 0
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_KuniSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KUNI, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KuniWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_BeatGauntlet::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_ZukiDone, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, EcruteakCity_Theater_EventScript_Lugia
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, EcruteakCity_Theater_EventScript_Hooh

	EcruteakCity_Theater_Movement_SouthCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

	EcruteakCity_Theater_Movement_WestCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

	EcruteakCity_Theater_Movement_EastCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

EcruteakCity_Theater_EventScript_Lugia::
	giveitem ITEM_TIDAL_BELL
	closemessage
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	addobject LOCALID_ECRUTEAK_SISTER
	applymovement LOCALID_ECRUTEAK_SISTER, EcruteakCity_Theater_Movement_Sister
	waitmovement 0
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_WEST
	msgbox EcruteakCity_Theater_Text_GirlLugia, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_ZukiLugia, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	removeobject LOCALID_ECRUTEAK_ZUKI
	removeobject LOCALID_ECRUTEAK_MIKI
	removeobject LOCALID_ECRUTEAK_NAOKO
	removeobject LOCALID_ECRUTEAK_KUNI
	removeobject LOCALID_ECRUTEAK_SAYO
	removeobject LOCALID_ECRUTEAK_MIKI

	removeobject LOCALID_ECRUTEAK_SISTER
	playse SE_EXIT
	delay 120
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_COMPLETED_LUGIA, 2
	setvar VAR_COMPLETED_HO_OH, 3
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setvar VAR_NEWBARKTOWN_LABSTATE, 9
	setvar VAR_ECRUTEAK_CITY_THEATER, 7
	release
	end
EcruteakCity_Theater_EventScript_Hooh::
	giveitem ITEM_CLEAR_BELL
	closemessage
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	addobject LOCALID_ECRUTEAK_SISTER
	applymovement LOCALID_ECRUTEAK_SISTER, EcruteakCity_Theater_Movement_Sister
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_GirlHooh, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_ZukiHooh, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	removeobject LOCALID_ECRUTEAK_ZUKI
	removeobject LOCALID_ECRUTEAK_MIKI
	removeobject LOCALID_ECRUTEAK_NAOKO
	removeobject LOCALID_ECRUTEAK_KUNI
	removeobject LOCALID_ECRUTEAK_SAYO
	removeobject LOCALID_ECRUTEAK_MIKI

	removeobject LOCALID_ECRUTEAK_SISTER
	playse SE_EXIT
	delay 120
	fadescreenswapbuffers FADE_FROM_BLACK

	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setvar VAR_COMPLETED_HO_OH, 2
	setvar VAR_COMPLETED_LUGIA, 3
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setvar VAR_NEWBARKTOWN_LABSTATE, 9
	setvar VAR_ECRUTEAK_CITY_THEATER, 7
	release
	end

EcruteakCity_Theater_MeloettaEncounter::
	lock
	faceplayer
	legendaryencounter SPECIES_MELOETTA, 65, LOCALID_MELOETTA, FLAG_HIDE_MELOETTA
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EcruteakTheater_CaughtMeloetta
	release
	end

EcruteakTheater_CaughtMeloetta::
	setflag FLAG_CAUGHT_MELOETTA
	release
	end

EcruteakCity_Theater_Movement_Sister:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	step_end

EcruteakCity_Theater_EventScript_LegendaryDenied::
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox EcruteakCity_Theater_Text_ZukiNo, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Movement_ZukiWalkUp:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end
EcruteakCity_Theater_Movement_NaokoWalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end
EcruteakCity_Theater_Movement_NaokoWalkBack:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_MikiWalkToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_MikiWalkBack:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

EcruteakCity_Theater_Movement_SayoWalkToPlayer:
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end
EcruteakCity_Theater_Movement_SayoWalkBack:
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	step_end

EcruteakCity_Theater_Movement_KuniWalkToPlayer:
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_KuniWalkBack:
	walk_right
	walk_right
	walk_right
	walk_up
	face_down
	step_end

EcruteakCity_Theater_Text_KimonoGirlBeaten:
	.string "...$"

EcruteakCity_Theater_Text_ZukiSeen:
	.string "欢迎。我是小玉。\n我们之前在桔梗市\l见过面。\p要让{STR_VAR_1}回来，\n需要一个与宝可梦\l心灵相通的人。\p我们拜托宝可梦爷爷，\n把这只神奇蛋交给\l有资质的人。\p于是蛋从宝可梦爷爷\n传到空木博士，再到你手上。\p可是，光有纯净的心灵，\n还不足以面对这只宝可梦的力量。$"
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

EcruteakCity_Theater_Text_ZukiSeenAgain:
	.string "我要考验你，看看你是不是\n优秀的训练家。\p准备好了吗，\n{PLAYER}？$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_ZukiNo:
	.string "好吧……\n我会等你\l准备好。$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_NaokoSeen:
	.string "你相当强呢。你在栎树林\n帮过我。\p我是小梅——\n不太认路。\p我亲眼看到你打跑火箭队，\n就在钢铁在呆呆兽之井\l陷入麻烦的时候。\p让我来挑战你和\n你的宝可梦吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_MikiSeen:
	.string "你真是个了不起的训练家。\n我记得你就在这儿\l赶走了那个火箭队手下。\p多谢你了。\p不过，我也是个训练家。\n真正的强者，\l话最少！\p我是小鹃——\n和服女孩！\p让我来挑战你和\n你的宝可梦吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_SayoSeen:
	.string "好精神！你从背后一推，\n把我推下了冰面。\p我是穿着草鞋滑冰的\n樱花——和服女孩！\p你通过长老考验的时候，\n我就在龙穴里听着呢。\p让我来挑战你和\n你的宝可梦吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_KuniSeen:
	.string "我是最后一个。\p你在满金地下通道里\n真是靠得住。\p我是在地下也要起舞的\n小桃！\p我看到了你挫败\n火箭队夺取播音塔的计划。\p现在让我见识你的实力！\n让我来挑战你和\l你的宝可梦吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_ZukiDone:
	.string "我们果然没看错你。\n你确实配得上这个……\p请收下吧。$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_GirlHooh:
	.string "姐姐们！我刚才看到\n铃铛塔上空有宝可梦的\l巨大身影！\p难道是……$"
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_GirlLugia:
	.string "姐姐们！我刚才看到\n漩涡岛的水里有\l宝可梦的巨大身影！\p难道是……$"
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_ZukiHooh:
	.string "小玉：{PLAYER}！\n我们在铃铛塔等你。再见！$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_ZukiLugia:
	.string "小玉：{PLAYER}！\n我们在漩涡岛\l等你。再见！$"
	.string ""
	.string ""

EcruteakCity_Theater_Text_KimonoDone:
	.string "我们正在排练舞蹈。$"

EcruteakCity_Theater_Text_ZukiAfterAll:
	.string "多谢你前些日子的\n帮忙。\p你看，人与宝可梦的羁绊\n能让人与人走得更近……\p{PLAYER}，谢谢你\n没有辜负我们的期望！\p如果这趟旅程让你有所收获，\n就去谢谢宝可梦爷爷\l和空木博士吧……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_Theater_Text_KimonoGirlsBeforeBattle:
	.string "准备好了的话，\n就去和正中间的小玉说话吧。$"
	.string ""
