.set LOCALID_NURSE, 1

MahoganyTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANYTOWN
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
    .string "什么？火箭队又回来了？\p我在愤怒之湖见到了几个\n穿黑衣服的男人……$"
    .string ""
    .string ""
    .string ""

MahoganyTown_PokemonCenter_Text_Youngster:
    .string "我会阻止我的宝可梦\n过早进化。\p我会先让它学会某些招式，\n再让它进化。$"
    .string ""
    .string ""
    .string ""

MahoganyTown_PokemonCenter_Text_CooltrainerF:
    .string "宝可梦进化后确实会\n变强，\p但学会招式也会\n变慢。$"
    .string ""
    .string ""
    .string ""
