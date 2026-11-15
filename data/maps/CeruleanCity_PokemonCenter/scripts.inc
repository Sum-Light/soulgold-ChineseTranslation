.set LOCALID_NURSE, 1

CeruleanCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "对战时，我宁愿用自己\n一直培育的宝可梦，\p就算它们比刚抓到的\n宝可梦要弱一些。$"
	.string ""
	.string ""
	.string ""

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "磁浮列车时速超过340英里。\n它往返关都和城都地区，\l几乎眨眼就到。\p去城都地区真是方便多了。$"
	.string ""
	.string ""
	.string ""
