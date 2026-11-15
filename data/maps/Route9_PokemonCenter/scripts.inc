.set LOCALID_NURSE, 1

Route9_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route9_PokemonCenter_EventScript_Engineer1::
	msgbox Route9_PokemonCenter_Text_Engineer1, MSGBOX_NPC
	end

Route9_PokemonCenter_EventScript_Engineer2::
	msgbox Route9_PokemonCenter_Text_Engineer2, MSGBOX_NPC
	end

Route9_PokemonCenter_Text_Engineer1:
	.string "我们工程师有时会来这儿\n休息一下。\l或者只是躲开厂长。\p那家伙是个怪人。$"
	.string ""
	.string ""
	.string ""

Route9_PokemonCenter_Text_Engineer2:
	.string "发电厂很偏，\n我上班得跑很远。$"
	.string ""
