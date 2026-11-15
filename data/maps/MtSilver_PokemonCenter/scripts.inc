.set LOCALID_NURSE, 1

MtSilver_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_PokemonCenter_OnTransition
	.byte 0

MtSilver_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MT_SILVER
	end

MtSilver_PokemonCenter_EventScript_Meara::
	msgbox MtSilver_PokemonCenter_Text_Meara, MSGBOX_NPC
	end

MtSilver_PokemonCenter_Text_Meara:
	.string "我是深灰市\n博物馆的研究员。\p这一带发现了数量异常多的\n文物，所以我\l特地前来调查。\p这座山周围并没有文明的记录，\n可这些文物\l几乎可以确定\l是人工制作的。\p真是相当不可思议。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
