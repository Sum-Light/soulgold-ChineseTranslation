ViridianCity_House1_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "你给宝可梦起名字时\n会花很多心思吗？\p起个好昵称，和别人\n交换时会更有乐趣。$"
	.string ""
	.string ""
	.string ""

ViridianCity_House1_Text_Lass:
	.string "它们叫小尖——一只烈雀——\n还有小吱——一只小拉达。$"
	.string ""

ViridianCity_House1_Text_Speary:
	.string "小尖：叽——叽！$"

ViridianCity_House1_Text_Rattey:
	.string "小吱：唧唧唧！$"

