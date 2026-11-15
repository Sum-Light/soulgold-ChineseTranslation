.set LOCALID_NURSE, 1

BlackthornCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "遥远的石英高原深处，\n就是宝可梦联盟。\p听说全国最强的训练家\n都聚集在那里。$"
	.string ""
	.string ""
	.string ""

BlackthornCity_PokemonCenter1FTwinText:
	.string "我有个招式无论如何都想\n教给宝可梦。\p所以我请遗忘爷爷帮它\n忘掉了一个秘传招式。$"
	.string ""
	.string ""
	.string ""
