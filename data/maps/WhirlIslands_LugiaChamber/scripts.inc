.set LOCALID_LUGIA, 1
.set LOCALID_KIMONO_MID, 4
.set LOCALID_KIMONO_1, 3
.set LOCALID_KIMONO_2, 2
.set LOCALID_KIMONO_3, 6
.set LOCALID_KIMONO_4, 5
.set LOCALID_SHADOW_LUGIA, 9

WhirlIslands_LugiaChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WhirlIslands_LugiaChamber_OnTransition
	.byte 0

WhirlIslands_LugiaChamber_OnTransition:
	goto_if_eq VAR_COMPLETED_LUGIA, 2, WhirlIslands_LugiaChamber_MapScript_LugiaStory
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_MapScript_LugiaPostStoryGone
	goto_if_eq VAR_COMPLETED_LUGIA, 4, WhirlIslands_LugiaChamber_MapScript_LugiaPostStoryEncounter
	end

WhirlIslands_LugiaChamber_MapScript_LugiaStory::
	goto_if_unset FLAG_HIDE_SHADOW_LUGIA, WhirlIslands_LugiaChamber_MapScript_ShadowLugiaStory
	clearflag FLAG_HIDE_LUGIA
	end

WhirlIslands_LugiaChamber_MapScript_ShadowLugiaStory::
	setflag FLAG_HIDE_LUGIA
	end

WhirlIslands_LugiaChamber_MapScript_LugiaPostStoryGone::
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_LUGIA
	setflag FLAG_HIDE_SHADOW_LUGIA
	end

WhirlIslands_LugiaChamber_MapScript_LugiaPostStoryEncounter::
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	goto_if_set FLAG_HIDE_LUGIA, WhirlIslands_LugiaChamber_MapScript_ShadowLugiaPostStoryEncounter
	setflag FLAG_HIDE_SHADOW_LUGIA
	clearflag FLAG_HIDE_LUGIA
	setobjectxyperm LOCALID_LUGIA, 29, 12
	end

WhirlIslands_LugiaChamber_MapScript_ShadowLugiaPostStoryEncounter::
	setflag FLAG_HIDE_LUGIA
	end

WhirlIslands_LugiaChamber_EventScript_TalkToKimono::
	lockall
	playbgm MUS_HG_KIMONO_GIRL_DANCE, TRUE
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_Opening, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Step_Aside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, WhirlIslands_LugiaChamber_Walk_To_Center
	waitmovement 0
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Step_In
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Step_Start_Left
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Step_Start_Right
	waitmovement 5
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid	
	waitmovement 0
	playse SE_M_PETAL_DANCE
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	@ 1
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 2
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 3
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 4
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Left
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 5
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right_Up
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Step_Up
	waitmovement LOCALID_KIMONO_1
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	waitse
	setobjectxyperm LOCALID_KIMONO_1, 27, 18
	setobjectxyperm LOCALID_KIMONO_2, 28, 19
	setobjectxyperm LOCALID_KIMONO_MID, 29, 20
	setobjectxyperm LOCALID_KIMONO_4, 30, 19
	setobjectxyperm LOCALID_KIMONO_3, 31, 18
	setobjectmovementtype LOCALID_KIMONO_1, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_KIMONO_2, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_KIMONO_3, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_KIMONO_4, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_KIMONO_MID, MOVEMENT_TYPE_FACE_UP
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_LUGIA, WhirlIslands_LugiaChamber_Movement_LugiaAppear
	applymovement OBJ_EVENT_ID_CAMERA, WhirlIslands_LugiaChamber_Movement_CameraPanUp
	waitmovement 0
	delay 50
	@ setweather WEATHER_NONE
	@ doweather
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_LUGIA, WhirlIslands_LugiaChamber_Movement_LugiaApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WhirlIslands_LugiaChamber_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	waitmovement 0
	createfieldmugshot MUGSHOT_KIMONO_GIRL
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_Closing1, MSGBOX_DEFAULT
	waitmessage
	setobjectxyperm LOCALID_LUGIA, 29, 12

	
	closemessage
	releaseall
	end

WhirlIslands_LugiaChamber_EventScript_Lugia::
	lockall
	goto_if_eq VAR_COMPLETED_LUGIA, 4, WhirlIslands_LugiaChamber_EventScript_LugiaPostgame
	goto_if_unset FLAG_HIDE_SHADOW_LUGIA, WhirlIslands_LugiaChamber_EventScript_MorphedShadowLugia
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	checkitem ITEM_DARK_CRYSTAL
	goto_if_eq VAR_RESULT, FALSE, WhirlIslands_LugiaChamber_EventScript_RegularLugiaBattle
	msgbox WhirlIslands_LugiaChamber_Text_DarkCrystalGlowing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, WhirlIslands_LugiaChamber_EventScript_UseDarkCrystal

WhirlIslands_LugiaChamber_EventScript_RegularLugiaBattle::
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_LUGIA
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	bosslegendaryencounter SPECIES_LUGIA, 65, LOCALID_LUGIA, FLAG_HIDE_LUGIA, 2, SPECIES_NONE, 110
	goto WhirlIslands_LugiaChamber_EventScript_FinishStoryBattle

WhirlIslands_LugiaChamber_EventScript_UseDarkCrystal::
	closemessage
	playmoncry SPECIES_LUGIA, CRY_MODE_HIGH_PITCH
	delay 30
	waitmoncry
	delay 60
	mosaicmorphobject LOCALID_LUGIA, OBJ_EVENT_GFX_SPECIES(LUGIA_SHADOW)
	setflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_SHADOW_LUGIA
	delay 30
	setvar VAR_LAST_TALKED, LOCALID_LUGIA
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	bosslegendaryencounter SPECIES_LUGIA_SHADOW, 65, LOCALID_LUGIA, FLAG_HIDE_LUGIA, 2, SPECIES_NONE, 110

WhirlIslands_LugiaChamber_EventScript_FinishStoryBattle::
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, WhirlIslands_LugiaChamber_EventScript_RanFromLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, WhirlIslands_LugiaChamber_EventScript_RanFromLugia
	call_if_eq VAR_RESULT, B_OUTCOME_WON, WhirlIslands_LugiaChamber_EventScript_LugiaFlewAway
	call_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, WhirlIslands_LugiaChamber_EventScript_CaughtLugia
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_LEGENDARY_STORY_CAP
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right2
	waitmovement 0
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	setvar VAR_ECRUTEAK_CITY_THEATER, 8
	setvar VAR_COMPLETED_LUGIA, 3
	releaseall
	end

WhirlIslands_LugiaChamber_EventScript_ShadowLugia::
	lockall
	setvar VAR_LAST_TALKED, LOCALID_SHADOW_LUGIA
	goto_if_eq VAR_COMPLETED_LUGIA, 4, WhirlIslands_LugiaChamber_EventScript_ShadowLugiaPostgameEncounter
	goto WhirlIslands_LugiaChamber_EventScript_ShadowLugiaEncounter

WhirlIslands_LugiaChamber_EventScript_MorphedShadowLugia:
	setvar VAR_LAST_TALKED, LOCALID_LUGIA

WhirlIslands_LugiaChamber_EventScript_ShadowLugiaEncounter:
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_HIGH_PITCH
	delay 30
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	bosslegendaryencounter SPECIES_LUGIA_SHADOW, 65, LOCALID_SHADOW_LUGIA, FLAG_HIDE_SHADOW_LUGIA, 2, SPECIES_NONE, 110
	goto WhirlIslands_LugiaChamber_EventScript_FinishStoryBattle

WhirlIslands_LugiaChamber_EventScript_LugiaPostgame::
	setvar VAR_LAST_TALKED, LOCALID_LUGIA
	goto_if_unset FLAG_HIDE_SHADOW_LUGIA, WhirlIslands_LugiaChamber_EventScript_ShadowLugiaPostgameEncounter
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	checkitem ITEM_DARK_CRYSTAL
	goto_if_eq VAR_RESULT, FALSE, WhirlIslands_LugiaChamber_EventScript_RegularLugiaPostgameBattle
	msgbox WhirlIslands_LugiaChamber_Text_DarkCrystalGlowing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, WhirlIslands_LugiaChamber_EventScript_UseDarkCrystalPostgame

WhirlIslands_LugiaChamber_EventScript_RegularLugiaPostgameBattle:
	closemessage
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	bosslegendaryencounter SPECIES_LUGIA, 80, LOCALID_LUGIA, FLAG_HIDE_LUGIA, 4, SPECIES_NONE, 110
	goto WhirlIslands_LugiaChamber_EventScript_FinishPostgameBattle

WhirlIslands_LugiaChamber_EventScript_UseDarkCrystalPostgame:
	closemessage
	mosaicmorphobject LOCALID_LUGIA, OBJ_EVENT_GFX_SPECIES(LUGIA_SHADOW)
	setflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_SHADOW_LUGIA
	delay 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	bosslegendaryencounter SPECIES_LUGIA_SHADOW, 80, LOCALID_LUGIA, FLAG_HIDE_LUGIA, 4, SPECIES_NONE, 110
	goto WhirlIslands_LugiaChamber_EventScript_FinishPostgameBattle

WhirlIslands_LugiaChamber_EventScript_ShadowLugiaPostgameEncounter:
	waitse
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	bosslegendaryencounter SPECIES_LUGIA_SHADOW, 80, LOCALID_SHADOW_LUGIA, FLAG_HIDE_SHADOW_LUGIA, 4, SPECIES_NONE, 110

WhirlIslands_LugiaChamber_EventScript_FinishPostgameBattle:
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, WhirlIslands_LugiaChamber_EventScript_RanFromLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, WhirlIslands_LugiaChamber_EventScript_RanFromLugia
	call_if_eq VAR_RESULT, B_OUTCOME_WON, WhirlIslands_LugiaChamber_EventScript_RanFromLugia
	call_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, WhirlIslands_LugiaChamber_EventScript_CaughtLugia
	setvar VAR_COMPLETED_LUGIA, 3
	releaseall
	end

WhirlIslands_LugiaChamber_EventScript_LugiaFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LUGIA
	removeobject LOCALID_SHADOW_LUGIA
	setweather WEATHER_NONE
	doweather
	setflag FLAG_HIDE_LUGIA
	setflag FLAG_HIDE_SHADOW_LUGIA
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	return

WhirlIslands_LugiaChamber_EventScript_CaughtLugia::
	setflag FLAG_CAUGHT_LUGIA
	removeobject LOCALID_LUGIA
	removeobject LOCALID_SHADOW_LUGIA
	setweather WEATHER_NONE
	doweather
	setflag FLAG_HIDE_LUGIA
	setflag FLAG_HIDE_SHADOW_LUGIA
	return

WhirlIslands_LugiaChamber_EventScript_RanFromLugia::
	releaseall
	end

WhirlIslands_LugiaChamber_Text_DarkCrystalGlowing:
	.string "你包里的黑暗水晶\n开始发光了。\p要拿出来吗？$"
	.string ""
	.string ""

WhirlIslands_LugiaChamber_EventScript_Zuki::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_ZukiAfter
	msgbox WhirlIslands_LugiaChamber_Text_Zuki_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_ZukiAfter::
	goto_if_unset FLAG_CAUGHT_LUGIA, WhirlIslands_LugiaChamber_EventScript_ZukiAfterNotCaught
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_AfterCaught, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_ZukiAfterNotCaught::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_AfterNotCaught, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_EventScript_Naoko::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_NaokoAfter
	msgbox WhirlIslands_LugiaChamber_Text_Naoko_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_NaokoAfter::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_After, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_EventScript_Miki::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_MikiAfter
	msgbox WhirlIslands_LugiaChamber_Text_Miki_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_MikiAfter::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_After, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_EventScript_Sayo::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_SayoAfter
	msgbox WhirlIslands_LugiaChamber_Text_Sayo_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_SayoAfter::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_After, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_EventScript_Kuni::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_KuniAfter
	msgbox WhirlIslands_LugiaChamber_Text_Kuni_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_KuniAfter::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_After, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_Text_Kimono_AfterNotCaught:
	.string "你不光让洛奇亚现身，\n甚至还把它\l打倒了……\p我们已经没什么可说的了。\n今后的旅途，\l请多保重……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""	

WhirlIslands_LugiaChamber_Text_Kimono_AfterCaught:
	.string "你不光让洛奇亚现身，\n甚至还把它\l收服了……\p我们已经没什么可说的了。\n今后的旅途，\l请多保重……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

WhirlIslands_LugiaChamber_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WhirlIslands_LugiaChamber_Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WhirlIslands_LugiaChamber_Movement_LugiaApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_LugiaAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end


WhirlIslands_LugiaChamber_Movement_Kimono_Step_Aside:
	face_right
	delay_16
	walk_right
	delay_16
	face_left
	step_end

WhirlIslands_LugiaChamber_Walk_To_Center:
	walk_up
	walk_up
	walk_up
	delay_16
	face_down
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Step_In:
	walk_left
	delay_16
	face_down
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Step_Start_Left:
	face_right
	delay_16
	face_up
	delay_16
	walk_up
	walk_up
	delay_16
	face_left
	delay_16
	walk_left
	delay_16
	face_down
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Step_Start_Right:
	face_right
	delay_16
	face_up
	delay_16
	walk_up
	walk_up
	delay_16
	face_right
	delay_16
	walk_right
	delay_16
	face_down
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid:
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	delay_16
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down:
	face_down
	delay_8
	walk_down
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up:
	face_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	walk_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Right:
	face_right
	delay_8
	walk_right
	walk_right
	walk_right
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Left:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	walk_left
	walk_left
	walk_left
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left_Up:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	walk_left
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right_Up:
	face_right
	delay_8
	walk_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_right
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up:
	face_right
	delay_8
	face_up
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Step_Up:
	face_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right2:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	face_left
	step_end

WhirlIslands_LugiaChamber_Text_Zuki_Before::
	.string "小玉：去吧，去面对洛奇亚。 $"
WhirlIslands_LugiaChamber_Text_Naoko_Before::
	.string "小梅：去吧，去面对洛奇亚。 $"
WhirlIslands_LugiaChamber_Text_Miki_Before::
	.string "小鹃：去吧，去面对洛奇亚。 $"
WhirlIslands_LugiaChamber_Text_Sayo_Before::
	.string "樱花：去吧，去面对洛奇亚。 $"
WhirlIslands_LugiaChamber_Text_Kuni_Before::
	.string "小桃：去吧，去面对洛奇亚。 $"

WhirlIslands_LugiaChamber_Text_Kimono_Opening::
	.string "和服女孩：没错。\n这里就是我们迎接洛奇亚的地方。\p当我们苦练多日的舞蹈，\n与托付给你的海声铃铛之声\l融为一体时，\l洛奇亚就会从瀑布潭的深处\l再次现身。 $"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

WhirlIslands_LugiaChamber_Text_Kimono_Closing1::
	.string "那确实就是洛奇亚……\n自古以来守护着\l这片岛屿的存在…… \p那么多人一次又一次尝试，\n却都以失败告终……\p{PLAYER}，你的心与海声铃铛\n完全共鸣，终于\l让它现身了……\l{PLAYER}，你明白了吗？\p洛奇亚……它一定一直在等待\n像你这样的人。\p你不这么觉得吗？ $"
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

WhirlIslands_LugiaChamber_Text_Kimono_After::
	.string "和服女孩：今天，\n你证明了自己，{PLAYER}。$"
	.string ""
