Rinto_PoemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Rinto_PoemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Rinto_PoemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_TEMP_1
	setrespawn HEAL_LOCATION_RINTO_VILLAGE_POKEMON_CENTER
	end


RintoPC_Gbakid1::
	msgbox RintoPC_Gbakid1_Text_0, MSGBOX_NPC
	return


RintoPC_Battlegirl::
	msgbox RintoPC_Battlegirl_Text_0, MSGBOX_NPC
	return


RintoPC_Hiker::
	msgbox RintoPC_Hiker_Text_0, MSGBOX_NPC
	return


RintoPC_Gbakid1_Text_0:
	.string "真想和世界各地的朋友们\n一较高下啊。$"

RintoPC_Battlegirl_Text_0:
	.string "沙尘暴有时\n会让进出这座村庄变得困难。$"

RintoPC_Hiker_Text_0:
	.string "听说最近有人在这一带\n看到了模样古怪的\l一对飞行宝可梦。$"
