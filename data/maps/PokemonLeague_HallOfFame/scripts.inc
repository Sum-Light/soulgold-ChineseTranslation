.set LOCALID_HALLOFFAME_LANCE, 1

PokemonLeague_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_OnFrame
	.byte 0

PokemonLeague_HallOfFame_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 6, PokemonLeague_HallOfFame_EventScript_Cutscene
	.2byte 0

PokemonLeague_HallOfFame_EventScript_Cutscene::
	lock
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	createfieldmugshot MUGSHOT_LANCE
	msgbox PokemonLeague_HallOfFame_LanceText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags
	special Achievement_UnlockHallOfFameDebut
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp::
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	createfieldmugshot MUGSHOT_LANCE
	msgbox PokemonLeague_HallOfFame_Rematch_LanceText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags::
	clearflag FLAG_HIDE_LEAGUE_BLACKBELT
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setflag FLAG_LEGENDARY_STORY_CAP
	setflag FLAG_IS_CHAMPION
	setvar VAR_SHUCKIE, 2
	setvar VAR_LEAGUE_STATE, 1
	setvar VAR_NEWBARK_TOWN_STATE, 6
	setvar VAR_SSAQUA_STATE, 0
	setvar VAR_POSTGAME_UNLOCKS_STATE, 1
	return

PokemonLeague_HallOfFame_EventScript_SetGameClearFlags::
	clearflag FLAG_HIDE_LATIOS
	clearflag FLAG_HIDE_LATIAS
	clearflag FLAG_HIDE_RAYQUAZA
	clearflag FLAG_HIDE_GROUDON
	clearflag FLAG_HIDE_KYOGRE
	clearflag FLAG_HIDE_MEWTWO
	clearflag FLAG_HIDE_VERMILION_SNORLAX
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_HIDE_ZAPDOS
	clearflag FLAG_HIDE_LARVESTA
	clearflag FLAG_HIDE_CRESSELIA
	clearflag FLAG_HIDE_ARTICUNO
	clearflag FLAG_HIDE_MOLTRES
	clearflag FLAG_HIDE_AZELF
	clearflag FLAG_HIDE_MESPRIT
	clearflag FLAG_HIDE_UXIE
	clearflag FLAG_HIDE_CHIENPAO
	clearflag FLAG_HIDE_MANAPHY
	clearflag FLAG_HIDE_SHAYMIN 
	clearflag FLAG_HIDE_IRONVALIANT
	clearflag FLAG_HIDE_FLUTTERMANE
	clearflag FLAG_HIDE_REGIROCK
	clearflag FLAG_HIDE_REGISTEEL
	clearflag FLAG_HIDE_REGICE
	clearflag FLAG_HIDE_HEATRAN
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_HIDE_VIRIZION
	clearflag FLAG_HIDE_REGIGIGAS 
	clearflag FLAG_HIDE_MARSHADOW 
	clearflag FLAG_HIDE_CHI_YU
	clearflag FLAG_CAUGHT_MELOETTA
	clearflag FLAG_CAUGHT_ZERAORA
	clearflag FLAG_CAUGHT_COBALION
	clearflag FLAG_CAUGHT_TERRAKION
	clearflag FLAG_CAUGHT_GENESECT
	clearflag FLAG_HIDE_DIANCIE 
	clearflag FLAG_CAUGHT_HOOPA
	clearflag FLAG_HIDE_OGERPON 
	clearflag FLAG_HIDE_MAGEARNA 
	clearflag FLAG_HIDE_FEZANDIPITI 
	clearflag FLAG_HIDE_SPEAR_PILLAR_DIALGA_PORTAL
	clearflag FLAG_HIDE_SPEAR_PILLAR_PALKIA_PORTAL
	clearflag FLAG_HIDE_SPEAR_PILLAR_GIRATINA_PORTAL
	clearflag FLAG_HIDE_SPEAR_PILLAR_TIME_GEAR
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setflag FLAG_LEGENDARY_STORY_CAP
	setvar VAR_COMPLETED_LUGIA, 4
	clearflag FLAG_HIDE_LUGIA
	setvar VAR_COMPLETED_HO_OH, 4
	clearflag FLAG_HIDE_HO_OH
	call PokemonLeague_HallOfFame_EventScript_SpawnRoamers
	call_if_ge VAR_SUICUNE_ENCOUNTERS, 8, PokemonLeague_HallOfFame_EventScript_SpawnSuicune
	call_if_set FLAG_CAUGHT_CELEBI, PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi
	clearflag FLAG_HIDE_MEW
	clearflag FLAG_CAUGHT_MEW
	clearflag FLAG_BATTLED_DEOXYS
	clearflag FLAG_DEFEATED_DEOXYS
	setvar VAR_LEAGUE_STATE, 1
	return

PokemonLeague_HallOfFame_EventScript_SpawnRoamers::
	setvar VAR_0x8004, 1
	special InitRoamer
	return

PokemonLeague_HallOfFame_EventScript_SpawnSuicune::
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi::
	clearflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
	return

PokemonLeague_HallOfFame_EventScript_SpawnKantoLeaderRematches::
	clearflag FLAG_HIDE_DIGLETT_BROCK
	clearflag FLAG_HIDE_CAPE_MISTY
	clearflag FLAG_HIDE_PLANT_SURGE
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	clearflag FLAG_HIDE_ROUTE22_JANINE
	clearflag FLAG_HIDE_OLIVINE_SABRINA

	@ move Blaine from Seafoam Gym to Cinnabar Rematch location
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE

	@ nothing to do for Blue
	return

PokemonLeague_HallOfFame_Movement_LanceEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

PokemonLeague_HallOfFame_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

PokemonLeague_HallOfFame_LanceText:
    .string "阿渡：我已经很久\n没来过这里了。\p这里永远铭记着\n联盟冠军们的功绩。\p他们勇敢的宝可梦\n也会一同被铭记。\p今天，我们在这里见证\n一位新的联盟冠军诞生——\p一位对所有宝可梦都怀有\n关爱与信赖的训练家。\p一位凭着坚持与决心\n走到这里的训练家。\p这位新的联盟冠军，\n拥有成为伟人的一切资质！\p{PLAYER}，就让我把你\n和你的伙伴登记为冠军吧！$"
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

PokemonLeague_HallOfFame_Rematch_LanceText:
    .string "阿渡：我记得，不久前\n我站在这里，迎接你成为\p城都的冠军。\p而现在，我们又来到这座\n神圣之地，在这里铭记\p最优秀的训练家\n和他们的宝可梦。\p今天，你不仅证明了\n自己在城都的力量，\l还在关都击败了我最强的队伍。\p你展现了对宝可梦的\n非凡关爱与信赖，\l这份羁绊一次次\l带你走向胜利。\p你的旅程写满坚持与\n毫不动摇的决心，\l那是你作为\l训练家真正的\l精神写照。\p你拥有成为真正巨匠的\n一切天赋，甚至是最强的。\p{PLAYER}，我很荣幸\n能再次把你和你信赖的伙伴\l登记为冠军。$"
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
    .string ""
    .string ""
    .string ""
    .string ""
