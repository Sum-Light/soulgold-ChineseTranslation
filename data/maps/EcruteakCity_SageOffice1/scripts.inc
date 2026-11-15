.set LOCALID_SAGEOFFICE_SAGE, 3

EcruteakCity_SageOffice1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "铃铛清鸣，\n只为受塔庇护之人。$"
	.string ""

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageARecallDirector
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageARecallDirector::
	msgbox EcruteakTinTowerEntrance_Text_RecallDirector, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 60
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "铃铛塔不许无资格者进入。\n抱歉，请您\l离开这里。$"
	.string ""
	.string ""

EcruteakTinTowerEntrance_Text_RecallDirector:
	.string "你回想起播音塔局长\n说过的话……\p“就算你去了我说的那个地方，\n传说的宝可梦\l也不会现身。\p看来还需要\n别的条件……”\p也许你该\n改天再来。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "没有圆朱道馆的徽章，\n谁也不许进铃铛塔。\p啊！\p是圆朱道馆的徽章！\n请进，请进。$"
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "发生了件大事。\p恕我失礼，\n请您离开。\p……能让心灵平静的东西……\p三位贤人说的话，\n真是深奥得让人听不懂……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "发生了件大事。\p恕我失礼，\n请您离开。\p………………$"
	.string ""
	.string ""
	.string ""
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "啊！\p那透明铃铛的声音！\p真……真是太动听了！\p我从没听过\n这么美妙的声音！\p那铃音，正映照着\n持铃者心灵的纯净。\p你……\p也许你能登上\n铃铛塔。\p请进吧。$"
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

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "请进吧。$"

EcruteakTinTowerEntrance_Text_SageDone:
	.string "那铃音，正映照着\n持铃者心灵的纯净。\p你……\n确实有资格。$"
	.string ""
	.string ""
	.string ""

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "前方那座铃铛塔，\n是美丽神圣的九重宝塔。\p所有见到它的人，\n心灵都会得到安宁。$"
	.string ""
	.string ""
	.string ""

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "铃铛塔摇晃了！\n一定有宝可梦回到塔顶了！$"
	.string ""

EcruteakTinTowerEntrance_Text_Gramps:
	.string "两座塔……两只宝可梦……\p可是其中一座烧毁后，\n两只宝可梦都飞走，再也没有回来。$"
	.string ""
	.string ""
