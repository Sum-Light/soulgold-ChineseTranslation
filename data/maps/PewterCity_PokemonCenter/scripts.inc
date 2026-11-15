.set LOCALID_NURSE, 1

PewterCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "……对，红莲的道馆也没了。\p我真是吓了一跳。\p……啊？我在打电话呢。\n走开啦！$"
	.string ""
	.string ""

PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "胖丁：噗——噗噗。$"

PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "大多数宝可梦只要听到\n胖丁唱歌，就会犯困。\p有些招式只有在宝可梦\n睡着时才能用。$"
	.string ""
	.string ""
	.string ""
