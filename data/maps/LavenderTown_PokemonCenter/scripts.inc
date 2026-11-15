.set LOCALID_NURSE, 1

LavenderTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "紫苑镇北边是岩山隧道。\n穿过隧道就能到达\l发电厂。$"
	.string ""
	.string ""

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "有个广播节目会播放\n宝可梦之笛的音乐。\p哦？啊，您的收音机需要装上\n扩张卡才能收听。$"
	.string ""
	.string ""
	.string ""

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "要是发电厂不运转，\n磁浮列车也就开不了……\p这也就是说，播音塔\n也没法继续广播……$"
	.string ""
	.string ""
	.string ""

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "播音塔的局长真是高兴坏了。\p他说因为发电厂重新平稳运转，\n他们又能\l继续广播了。$"
	.string ""
	.string ""
	.string ""
	.string ""
