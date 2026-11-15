.set LOCALID_NURSE, 1

ViridianCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "常青市的道馆馆主在哪？\n人家还想来挑战他呢。$"
	.string ""

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "常青道馆里没有\n任何道馆训练家。\p馆主说他的方针是\n不用任何手下取胜。$"
	.string ""
	.string ""
	.string ""

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "听说红莲的道馆\n已经没有了。\p不知道馆主夏伯\n后来怎么样了。$"
	.string ""
	.string ""
	.string ""

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "我的梦想是成为道馆馆主。$"
