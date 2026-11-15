CeladonCity_Apartments_RoofDay_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_Apartments_RoofDay_OnTransition
	.byte 0

CeladonCity_Apartments_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_Apartments_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_Apartments_RoofDay_EventScript_SetDay
	end

CeladonCity_Apartments_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_APARTMENTS_ROOF_NIGHT
	return

CeladonCity_Apartments_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_APARTMENTS_ROOF_DAY
	return

CeladonCity_Apartments_RoofDay_EventScript_Fisher::
	msgbox CeladonMansionRoof_Text_Fisher, MSGBOX_NPC
	end

CeladonCity_Apartments_RoofDay_EventScript_Sign::
	msgbox CeladonMansionRoof_Text_Graffiti, MSGBOX_NPC
	end

CeladonMansionRoof_Text_Fisher:
	.string "高处——我真是太喜欢了！\p要说和我一样爱高的，\n那大概就只有烟了！$"
	.string ""
	.string ""

CeladonMansionRoof_Text_Graffiti:
	.string "墙上涂着涂鸦……\p{PLAYER}添上了一撇小胡子！$"
	.string ""
