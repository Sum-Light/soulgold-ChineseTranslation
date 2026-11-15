LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, LavenderTown_OnLoad
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_OnLoad::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "那栋建筑很气派吧？\p那是关都的播音塔。$"
	.string ""

LavenderTown_Text_Teacher:
	.string "关都有很多好听的广播节目。$"

LavenderTown_Text_Gramps:
	.string "人们从各地赶来，\n悼念逝去的\l宝可梦灵魂。$"
	.string ""
	.string ""

LavenderTown_Text_Youngster:
	.string "要想叫醒睡着的宝可梦，\n得用宝可梦之笛。\p这是每个训练家\n都必须知道的！$"
	.string ""
	.string ""

LavenderTown_Text_Sign:
	.string "紫苑镇\p高贵的紫色城镇$"
	.string ""

LavenderTown_Text_KantoRadioStationSign:
	.string "关都播音塔\p您喜爱的节目\n全天候播出！$"
	.string ""
	.string ""

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "紫苑志愿者\n宝可梦之家$"
	.string ""

LavenderTown_Text_SoulHouseSign:
	.string "灵魂之家\p愿宝可梦的灵魂\n得以安息$"
	.string ""
	.string ""
