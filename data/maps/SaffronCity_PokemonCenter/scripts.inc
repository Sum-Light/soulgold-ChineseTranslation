.set LOCALID_NURSE, 1

SaffronCity_PokemonCenter_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "城都地区的宝可梦中心\n是什么样的呢？\p……哦，原来如此。看来和\n关都的没什么差别。\p那我可以放心去\n城都地区了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "我正好经过\n岩山隧道。\p发电厂那边好像\n出了什么乱子。$"
	.string ""
	.string ""
	.string ""

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "华蓝有个奇怪的洞窟。\p身为专业的登山男，我本该\n去探一探，但那地方连我都怕。$"
	.string ""
	.string ""

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "西尔佛公司的总部和\n磁浮列车车站——\l就是金黄市的名胜。$"
	.string ""
	.string ""
