.set LOCALID_CERULEAN_GYM_ROCKET, 5

CeruleanCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

CeruleanCity_Gym_OnFrame::
	map_script_2 VAR_KANTO_ROCKET_STORY_STATE, 2,  CeruleanCity_Gym_EventScript_RocketGrunt
	map_script_2 VAR_TEMP_0, 0,  CeruleanCity_Gym_EventScript_TryMachinePart
	.2byte 0

CeruleanCity_Gym_EventScript_RocketGrunt::
	lock
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntBumpPlayer
	delay 20
	playse SE_BANG
	waitmovement 0
	
	msgbox CeruleanGym_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CERULEAN_GYM_ROCKET, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkBack
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBigMistake, MSGBOX_DEFAULT
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Gym_Movement_PlayerSlide
	delay 10
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntLeave
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	removeobject LOCALID_CERULEAN_GYM_ROCKET
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	setvar VAR_KANTO_ROCKET_STORY_STATE, 3
	release
	end

CeruleanCity_Gym_EventScript_TryMachinePart::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_MachinePart
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePart::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanUp
	waitmovement 0
	delay 30
	setvar VAR_0x8004, 5  @ x
	setvar VAR_0x8005, 13  @ y
	playse SE_PIN
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	delay 55
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePartItem::
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_DoNothing
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 6, CeruleanCity_Gym_EventScript_DoNothing
	finditem ITEM_MACHINE_PART
	setvar VAR_KANTO_ROCKET_STORY_STATE, 6
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	end

CeruleanCity_Gym_EventScript_DoNothing::
	end

CeruleanCity_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntBumpPlayer:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	lock_facing_direction
	jump_up
	unlock_facing_direction
	delay_16
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntWalkBack:
	lock_facing_direction
	walk_slow_up
	walk_slow_up
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain:
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_PlayerSlide:
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntLeave:
	walk_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE10_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_StatueDuringRocket::
	msgbox CeruleanGym_Text_Note, MSGBOX_SIGN
	end 

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanGym_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA CeruleanGym_Text_SwimmerfDianaSeen, CeruleanGym_Text_SwimmerfDianaBeaten
	msgbox CeruleanGym_Text_SwimmerfDianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Briana::
	trainerbattle_single TRAINER_BRIANA CeruleanGym_Text_SwimmerfBrianaSeen, CeruleanGym_Text_SwimmerfBrianaBeaten
	msgbox CeruleanGym_Text_SwimmerfBrianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER CeruleanGym_Text_SwimmermParkerSeen, CeruleanGym_Text_SwimmermParkerBeaten
	msgbox CeruleanGym_Text_SwimmermParkerAfter, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_GymGuyAfter
	msgbox CeruleanGym_Text_GuideIntro, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuyAfter::
	msgbox CeruleanGym_Text_GuideWin, MSGBOX_NPC
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "华蓝宝可梦道馆\n馆主：小霞\p优胜训练家：\n青绿、赤红$"
    .string ""
	.string ""
	.string ""

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "华蓝宝可梦道馆\n馆主：小霞\p优胜训练家：\n青绿、赤红、{PLAYER}$"
    .string ""
    .string ""
	.string ""

CeruleanGym_Text_Note:
	.string "抱歉，我要离开一阵子。\n道馆馆主 小霞\p小霞不在，\n我们也不在。\l道馆训练家$"
	.string ""
	.string ""
	.string ""
	.string ""


CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_Misty_Defeated
	msgbox CeruleanGym_Text_MistyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MISTY, CeruleanGym_Text_MistyWinLoss
	message CeruleanGym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE10_GET
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_CERULEAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers
	msgbox CeruleanGym_Text_MistyTm, MSGBOX_DEFAULT
	msgbox CeruleanCity_Gym_Text_WaterPulseSpeech, MSGBOX_DEFAULT
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 5, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

CeruleanCity_Gym_SetSuicuneScene::
	setvar VAR_SUICUNE_ENCOUNTERS, 6
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

CeruleanCity_Gym_EventScript_Misty_Defeated::
	msgbox CeruleanGym_Text_MistyFightDone, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanCity_Gym_Text_WaterPulseSpeech:
    .string "这枚招式学习器里\n装着水之波动。\p它有时会让对手\n陷入混乱。\p你连城都地区的训练家\n都一路打败了。我想，\l你一定能用好它。$"
    .string ""
    .string ""
    .string ""
	.string ""

CeruleanGym_Text_GruntIntro:
	.string "哎哟！我、我很抱歉！\n你没受伤吧？\p我很忙。没时间\n跟你说话。要是\l被人看见就糟了。$"
	.string ""
	.string ""
	.string ""
	.string ""

CeruleanGym_Text_GruntBigMistake:
	.string "完了！你、你已经看见我了！\n我犯大错了！$"
	.string ""

CeruleanGym_Text_GruntBye:
	.string "嘿，你！把看见我的事忘掉，\n明白吗？\p你没看见，没听见，\n什么都不知道！\p明白吗？再见，小鬼！\n什么都没发生过！\p拜拜！永不再见！$"
	.string ""
	.string ""
	.string ""
	.string ""

CeruleanGym_Text_Note1:
	.string "抱歉，我要离开一阵子。\n道馆馆主 小霞\p小霞不在，我们也不在。\n道馆训练家$"
	.string ""
	.string ""
	.string ""

CeruleanGym_Text_MistyIntro:
	.string "小霞：我一直在等你呢，\n你这捣蛋鬼！\p你或许有很多城都地区的\n道馆徽章，但最好别\l太看不起我。\p我的水属性宝可梦\n可是很厉害的！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeruleanGym_Text_MistyWinLoss:
	.string "小霞：你还真有两下子……\p我承认你很有实力……\p给你。这是蓝色徽章。$"
	.string ""
	.string ""

CeruleanGym_Text_ReceivedBadge:
	.string "{PLAYER}得到了蓝色徽章。$"

CeruleanGym_Text_MistyFightDone:
	.string "小霞：城都地区有很多\n强大的训练家吗？我是说，\l像你这样的。\p总有一天我也要出去旅行，\n去和厉害的训练家\l对战一番。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeruleanGym_Text_MistyRematch:
	.string "小霞：哇，你现在是\n关都的冠军了！\p太厉害了！{PLAYER}，\n你一路成长了好多。\p不过我可不打算认输。\p要不要再和我对战一场？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeruleanGym_Text_MistyRematchDefeat:
	.string "小霞：你还真有两下子……$"

CeruleanGym_Text_SwimmerfDianaSeen:
	.string "抱歉，刚才我不在。\n咱们开始吧！$"
	.string ""

CeruleanGym_Text_SwimmerfDianaBeaten:
	.string "我认输！你赢了！$"

CeruleanGym_Text_SwimmerfDianaAfter:
	.string "我会安安静静地游泳的。$"

CeruleanGym_Text_SwimmerfBrianaSeen:
	.string "可别被我这优雅的泳姿\n吓住了。$"
	.string ""

CeruleanGym_Text_SwimmerfBrianaBeaten:
	.string "唔，你轻轻松松就打倒了我……$"

CeruleanGym_Text_SwimmerfBrianaAfter:
	.string "别因为赢了我\n就得意忘形。\p你要是松懈下来，\n小霞会把你打得落花流水。$"
	.string ""
	.string ""
	.string ""

CeruleanGym_Text_SwimmermParkerSeen:
	.string "咕嘟……\p我是第一个！放马过来吧！$"
	.string ""

CeruleanGym_Text_SwimmermParkerBeaten:
	.string "怎么会这样……$"

CeruleanGym_Text_SwimmermParkerAfter:
	.string "这几年小霞变强了\n很多。\p别掉以轻心，\n不然会被打得落花流水！$"
	.string ""
	.string ""
	.string ""

CeruleanGym_Text_GuideIntro:
	.string "哟！未来的冠军！\p小霞不在，我也跑出去\p玩了一阵子。嘿嘿嘿。$"
	.string ""
	.string ""

CeruleanGym_Text_GuideWin:
	.string "嚯，你让我见识到了\n你有多强。\p和往常一样，真是场\n精彩绝伦的对战！$"
	.string ""
	.string ""
	.string ""

CeruleanGym_Text_MistyTm:
	.string "这个也拿去吧。$"
