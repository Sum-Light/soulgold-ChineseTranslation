
.set LOCALID_NURSE, 1

IndigoPlateau_PokemonCenter_MapScripts::
	@map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_PokemonCenter_OnFrame 
	map_script MAP_SCRIPT_ON_LOAD, IndigoPlateau_PokemonCenter_OnLoad
	.byte 0

IndigoPlateau_PokemonCenter_OnLoad::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU_POKEMON_CENTER
	end

IndigoPlateau_PokemonCenter_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 0, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 2, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 3, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 4, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 5, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 6, IndigoPlateau_PokemonCenter_Enter
	.2byte 0

IndigoPlateau_PokemonCenter_Enter::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	setvar VAR_LEAGUE_STATE, 1
	end

IndigoPlateau_EventScript_Cooltrainer::
	msgbox IndigoPlateau_Text_CooltrainerM, MSGBOX_NPC
	end

IndigoPlateau_EventScript_BlackBelt::
	msgbox IndigoPlateau_Text_Blackbelt, MSGBOX_NPC
	end

IndigoPlateau_EventScript_ShigyNinja::
	msgbox IndigoPlateau_Text_ShigyNinja, MSGBOX_NPC
	end

IndigoPlateau_Text_ShigyNinja:
	.string "恭喜你来到了这里！\p这些年来，我见过无数训练家\n从这里经过，\l他们个个都独具个性。\p能走到这一步，\n你应该为自己骄傲！\p那么，去大干一场吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

IndigoPlateau_Text_Blackbelt:
	.string "宝可梦联盟目前\n不接受新的挑战者。\p请您稍后再来。$"
	.string ""
	.string ""

IndigoPlateau_Text_CooltrainerM:
    .string "在宝可梦联盟，你将\n接受四天王的考验。\p必须把他们全部打败。\n一旦输了，就得从头再来！$"
    .string ""
    .string ""
    .string ""

IndigoPlateau_EventScript_Silver::
	lock
	faceplayer 
	goto_if_set FLAG_DAILY_BEAT_SILVER, IndigoPlateau_EventScript_SilverBeat
	msgbox IndigoPlateau_Text_RivalEntrance1, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, IndigoPlateau_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, IndigoPlateau_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, IndigoPlateau_Silver_Battle_Chikorita
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BEAT_SILVER
	release
	end

IndigoPlateau_EventScript_SilverBeat::
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_7, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_7, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_7, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Text_RivalEntrance1:
    .string "站住。\p你现在就要去挑战\n宝可梦联盟了吗？\p休想。\p我那训练有素的宝可梦\n会把你打得落花流水。\p{PLAYER}！\n我要向你挑战！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

IndigoPlateau_Text_RivalWin:
    .string "……\p好吧……我输了……$"
    .string ""

IndigoPlateau_Text_RivalAfter:
    .string "……可恶……我还是赢不了……\p我……我得重新想想\n我的宝可梦……\p哼！你可别输了！$"
    .string ""
    .string ""
    .string ""

IndigoPlateau_Text_TeleportGuy1:
    .string "啊！你要挑战四天王吗？\n你确定准备好了吗？\p要是还想再修行一阵，\n我的凯西可以帮你。\p它能用瞬间移动送你回家。\p现在就想回家吗？$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

IndigoPlateau_Text_TeleportGuyYes:
    .string "好，好。在脑海中\n想象一下你家的样子……$"
    .string ""

IndigoPlateau_Text_TeleportGuyNo:
    .string "好，好。祝你好运！$"

IndigoPlateau_Text_Abra:
    .string "凯西：凯……西……$"

IndigoPlateau_StoneMerchant::
	lock
	faceplayer
	message IndigoPlateau_StoneMerchant_Text_0
	waitmessage
	goto_if_set FLAG_GOT_ADAMANT_ORB, IndigoPlateau_StoneMerchant_5
IndigoPlateau_StoneMerchant_3:
	goto_if_set FLAG_ONETIME_GROUDON, IndigoPlateau_StoneMerchant_16
IndigoPlateau_StoneMerchant_15:
	pokemart IndigoPlateau_StoneMerchantMart
IndigoPlateau_StoneMerchant_1:
	msgbox IndigoPlateau_StoneMerchant_Text_1
	release
	end

IndigoPlateau_StoneMerchant_2:
	goto_if_set FLAG_ONETIME_GROUDON, IndigoPlateau_StoneMerchant_11
IndigoPlateau_StoneMerchant_10:
	pokemart IndigoPlateau_StoneMerchantMart2
	goto IndigoPlateau_StoneMerchant_1

IndigoPlateau_StoneMerchant_4:
	goto_if_set FLAG_GOT_GRISEOUS_ORB, IndigoPlateau_StoneMerchant_2
	goto IndigoPlateau_StoneMerchant_3

IndigoPlateau_StoneMerchant_5:
	goto_if_set FLAG_GOT_LUSTROUS_ORB, IndigoPlateau_StoneMerchant_4
	goto IndigoPlateau_StoneMerchant_3

IndigoPlateau_StoneMerchant_9:
	pokemart IndigoPlateau_StoneMerchantMart4
	goto IndigoPlateau_StoneMerchant_1

IndigoPlateau_StoneMerchant_11:
	goto_if_set FLAG_ONETIME_KYOGRE, IndigoPlateau_StoneMerchant_9
	goto IndigoPlateau_StoneMerchant_10

IndigoPlateau_StoneMerchant_14:
	pokemart IndigoPlateau_StoneMerchantMart3
	goto IndigoPlateau_StoneMerchant_1

IndigoPlateau_StoneMerchant_16:
	goto_if_set FLAG_ONETIME_KYOGRE, IndigoPlateau_StoneMerchant_14
	goto IndigoPlateau_StoneMerchant_15


IndigoPlateau_GemMerchant::
	lock
	faceplayer
	message IndigoPlateau_StoneMerchant_Text_0
	waitmessage
	pokemart IndigoPlateau_GemMerchantMart
	msgbox IndigoPlateau_StoneMerchant_Text_1
	release
	end


	.align 2
IndigoPlateau_StoneMerchantMart:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_AUSPICIOUS_ARMOR
	.2byte ITEM_MALICIOUS_ARMOR
	.2byte ITEM_PEAT_BLOCK
	.2byte ITEM_BLACK_AUGURITE
	.2byte ITEM_NONE

	.align 2
IndigoPlateau_StoneMerchantMart2:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_AUSPICIOUS_ARMOR
	.2byte ITEM_MALICIOUS_ARMOR
	.2byte ITEM_PEAT_BLOCK
	.2byte ITEM_BLACK_AUGURITE
	.2byte ITEM_ADAMANT_ORB
	.2byte ITEM_LUSTROUS_ORB
	.2byte ITEM_GRISEOUS_ORB
	.2byte ITEM_NONE

	.align 2
IndigoPlateau_StoneMerchantMart3:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_AUSPICIOUS_ARMOR
	.2byte ITEM_MALICIOUS_ARMOR
	.2byte ITEM_PEAT_BLOCK
	.2byte ITEM_BLACK_AUGURITE
	.2byte ITEM_RED_ORB
	.2byte ITEM_BLUE_ORB
	.2byte ITEM_NONE

	.align 2
IndigoPlateau_StoneMerchantMart4:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_AUSPICIOUS_ARMOR
	.2byte ITEM_MALICIOUS_ARMOR
	.2byte ITEM_PEAT_BLOCK
	.2byte ITEM_BLACK_AUGURITE
	.2byte ITEM_ADAMANT_ORB
	.2byte ITEM_LUSTROUS_ORB
	.2byte ITEM_GRISEOUS_ORB
	.2byte ITEM_RED_ORB
	.2byte ITEM_BLUE_ORB
	.2byte ITEM_NONE

	.align 2
IndigoPlateau_GemMerchantMart:
	.2byte ITEM_NORMAL_GEM
	.2byte ITEM_FIRE_GEM
	.2byte ITEM_WATER_GEM
	.2byte ITEM_ELECTRIC_GEM
	.2byte ITEM_GRASS_GEM
	.2byte ITEM_ICE_GEM
	.2byte ITEM_FIGHTING_GEM
	.2byte ITEM_POISON_GEM
	.2byte ITEM_GROUND_GEM
	.2byte ITEM_FLYING_GEM
	.2byte ITEM_PSYCHIC_GEM
	.2byte ITEM_BUG_GEM
	.2byte ITEM_ROCK_GEM
	.2byte ITEM_GHOST_GEM
	.2byte ITEM_DRAGON_GEM
	.2byte ITEM_DARK_GEM
	.2byte ITEM_STEEL_GEM
	.2byte ITEM_FAIRY_GEM
	.2byte ITEM_NONE

IndigoPlateau_StoneMerchant_Text_0:
	.string "欢迎光临！有什么可以帮您的吗？$"

IndigoPlateau_StoneMerchant_Text_1:
	.string "欢迎再来！$"
