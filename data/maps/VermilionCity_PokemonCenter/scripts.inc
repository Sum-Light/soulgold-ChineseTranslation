.set LOCALID_NURSE, 1

VermilionCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "地鼠洞穴前面\n躺着一只睡着的宝可梦。\p这是收服它的好机会，\n可是要怎么弄醒它呢？$"
	.string ""
	.string ""
	.string ""

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "以前有只宝可梦\n睡在地鼠洞穴的\l入口前面。\p可是现在好像\n不见了。$"
	.string ""
	.string ""
	.string ""

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "高速船上很适合\n和训练家相遇、对战。$"
	.string ""

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "哦？你有几枚我\n从没见过的徽章？\p哦，我明白了。\n你是在城都得到的吧。$"
	.string ""
	.string ""
	.string ""
