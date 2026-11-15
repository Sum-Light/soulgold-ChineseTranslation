RintoHouse1_MapScripts::
	.byte 0


RintoHouse1_Vullaby::
	lock
	faceplayer
	playmoncry SPECIES_VULLABY, CRY_MODE_NORMAL
	msgbox RintoHouse1_Vullaby_Text_0
	waitmoncry
	release
	end


RintoHouse1_Girl::
	msgbox RintoHouse1_Girl_Text_0, MSGBOX_NPC
	return


RintoHouse1_Mom::
	msgbox RintoHouse1_Mom_Text_0, MSGBOX_NPC
	return


RintoHouse1_Vullaby_Text_0:
	.string "秃鹰丫头：呜哇啊啊啊！$"

RintoHouse1_Girl_Text_0:
	.string "听说有好几种宝可梦\n在城都会比别的地区\l早早进化呢。$"

RintoHouse1_Mom_Text_0:
	.string "我们的秃鹰丫头最近\n吃得特别多。\p说不定快进化了。$"
