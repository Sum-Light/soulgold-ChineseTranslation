RuinsOfAlph_PuzzleAndRewardChambers_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_PuzzleAndRewardChambers_OnLoad
	.byte 0

RuinsOfAlph_PuzzleAndRewardChambers_OnLoad::
	call_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoHole
	call_if_set FLAG_COMPLETED_OMANYTE_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteHole
	call_if_set FLAG_COMPLETED_AERODACTYL_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylHole
	call_if_set FLAG_COMPLETED_HOOH_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohHole

	call_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDoor
	call_if_set FLAG_OMANYTE_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteDoor
	call_if_set FLAG_AERODACTYL_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDoor
	call_if_set FLAG_HOOH_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDoor
	end

RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoHole::
	setmetatile 20, 5, 0x482, FALSE
	setmetatile 21, 5, 0x483, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteHole::
	setmetatile 4, 22, 0x482, FALSE
	setmetatile 5, 22, 0x483, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylHole::
	setmetatile 20, 22, 0x482, FALSE
	setmetatile 21, 22, 0x483, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohHole::
	setmetatile 4, 5, 0x482, FALSE
	setmetatile 5, 5, 0x483, FALSE
	return


RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDoor::
	setmetatile 21, 1, 0x488, FALSE 
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteDoor::
	setmetatile 5, 18, 0x488, FALSE 
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDoor::
	setmetatile 21, 18, 0x488, FALSE 
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDoor::
	setmetatile 5, 1, 0x488, FALSE 
	return


RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDescripton::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Kabuto, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Omanyte, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Aerodactyl, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Hooh, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Statue, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_UnownText::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_UnownText, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist3
	goto_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist2
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist1, MSGBOX_DEFAULT
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist2::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist2, MSGBOX_DEFAULT
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist3::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist3, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_KABUTO
	goto_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoSuccess::
	setflag FLAG_COMPLETED_KABUTO_PUZZLE
	addvar VAR_RUINS_OF_ALPH_PUZZLES, 1
	clearflag FLAG_HIDE_ALPH_PUZZLE_NPCS
	setflag FLAG_HIDE_INSIDE_ALPH_NPCS
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 20, 5, 0x482, FALSE
	setmetatile 21, 5, 0x483, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	setvar VAR_RUINSOFALPH_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	waitstate
	release
	end


RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall:
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OmanytePuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_OMANYTE
	goto_if_set FLAG_COMPLETED_OMANYTE_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OmanytePuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OmanytePuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteSuccess::
	setflag FLAG_COMPLETED_OMANYTE_PUZZLE
	addvar VAR_RUINS_OF_ALPH_PUZZLES, 1
	clearflag FLAG_HIDE_ALPH_PUZZLE_NPCS
	setflag FLAG_HIDE_INSIDE_ALPH_NPCS
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 4, 22, 0x482, FALSE
	setmetatile 5, 22, 0x483, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	waitstate
	release
	end


RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_AERODACTYL
	goto_if_set FLAG_COMPLETED_AERODACTYL_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylSuccess::
	setflag FLAG_COMPLETED_AERODACTYL_PUZZLE
	addvar VAR_RUINS_OF_ALPH_PUZZLES, 1
	clearflag FLAG_HIDE_ALPH_PUZZLE_NPCS
	setflag FLAG_HIDE_INSIDE_ALPH_NPCS
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 20, 22, 0x482, FALSE
	setmetatile 21, 22, 0x483, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	waitstate
	release
	end


RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HooHPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_HO_OH
	goto_if_set FLAG_COMPLETED_HOOH_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohSuccess::
	setflag FLAG_COMPLETED_HOOH_PUZZLE
	addvar VAR_RUINS_OF_ALPH_PUZZLES, 1
	clearflag FLAG_HIDE_ALPH_PUZZLE_NPCS
	setflag FLAG_HIDE_INSIDE_ALPH_NPCS
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 4, 5, 0x482, FALSE
	setmetatile 5, 5, 0x483, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	waitstate
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseEscapeRopeOpenKabuto::
	lockall
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedEscapeRope, MSGBOX_DEFAULT
	closemessage
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardKabuto

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseWaterStoneOpenOmanyte::
	lockall
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedWaterStone, MSGBOX_DEFAULT
	closemessage
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardOmanyte

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseFlashOpenAerodactyl::
	lockall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedFlash, MSGBOX_DEFAULT
	closemessage
	animateflash 1
	setflashlevel 1
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardAerodactyl

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckHooh::
	lock
	goto_if_set FLAG_HOOH_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	specialvar VAR_RESULT, CheckHooh
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardHooh
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohWall, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardHooh::
	goto_if_set FLAG_HOOH_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 5, 1, 0x488, FALSE 
	special DrawWholeMapView
	setflag FLAG_HOOH_BROUGHT
	addvar VAR_RUINS_OF_ALPH_PUZZLES, 1
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckAerodactyl::
	lock
	goto_if_set FLAG_AERODACTYL_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_LightWall, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardAerodactyl::
	goto_if_set FLAG_AERODACTYL_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 21, 18, 0x488, FALSE 
	special DrawWholeMapView
	setflag FLAG_AERODACTYL_BROUGHT
	addvar VAR_RUINS_OF_ALPH_PUZZLES, 1
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckKabuto::
	lock
	goto_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_EscapeWall, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardKabuto::
	goto_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 21, 1, 0x488, FALSE 
	special DrawWholeMapView
	setflag FLAG_KABUTO_BROUGHT
	addvar VAR_RUINS_OF_ALPH_PUZZLES, 1
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckOmanyte::
	lock
	goto_if_set FLAG_OMANYTE_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_WaterWall, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardOmanyte::
	goto_if_set FLAG_OMANYTE_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 5, 18, 0x488, FALSE 
	special DrawWholeMapView
	setflag FLAG_OMANYTE_BROUGHT
	addvar VAR_RUINS_OF_ALPH_PUZZLES, 1
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Solved, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward:
	.string "石室产生了反应！\n道路打开了。$"
	.string ""

RuinsOfAlph_PuzzleAndRewardChambers_Text_EscapeWall:
	.string "The wall reads:\n"
	.string "ESCAPE$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_LightWall:
	.string "The wall reads:\n"
	.string "LIGHT$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohWall:
	.string "The wall reads:\n"
	.string "HO OH$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_WaterWall:
	.string "The wall reads:\n"
	.string "WATER$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedEscapeRope:
	.string "{PLAYER}使用了\n离洞绳。$"
	.string ""

RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedWaterStone:
	.string "{PLAYER}使用了\n水之石。$"
	.string ""

RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedFlash:
	.string "{STR_VAR_1}使用了闪光！$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Solved:
	.string "道路打开了。$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist1:
	.string "欢迎来到这间石室。\p墙上有古人描绘宝可梦的\n滑动石板。\p滑动石板，把图画\n拼合完整吧。\p左边是这只宝可梦的\n说明。\p研究所的研究员们正在调查\n新发现的几种花纹。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist2:
	.string "地板上刚刚开了一个洞！\n我得去告诉大家。$"
	.string ""

RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist3:
	.string "这次连墙上也开了一个洞？！\n越来越吓人了。$"
	.string ""


RuinsOfAlph_PuzzleAndRewardChambers_Text_Kabuto:
	.string "藏身于海底的宝可梦。\n背上的眼睛扫视着四周。$"
	.string ""

RuinsOfAlph_PuzzleAndRewardChambers_Text_UnownText:
	.string "是未知图腾的文字！$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Statue:
	.string "这是古代宝可梦的\n仿制品。$"
	.string ""

RuinsOfAlph_PuzzleAndRewardChambers_Text_Aerodactyl:
	.string "这种飞行宝可梦用锯齿般的\n獠牙袭击猎物。$"
	.string ""

RuinsOfAlph_PuzzleAndRewardChambers_Text_Omanyte:
	.string "这只宝可梦扭动十条触手，\n在海中漂游。$"
	.string ""

RuinsOfAlph_PuzzleAndRewardChambers_Text_Hooh:
	.string "展开虹色的翅膀，\n优雅地飞翔的宝可梦。$"
	.string ""

@==========================================================================================================================================================
@ Hooh
@ Aero
@ Kabuto
@ Omanyte
