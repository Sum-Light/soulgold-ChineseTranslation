OlivineCity_House2_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "去湛蓝市的路上，\n有四个无人岛。\p坏孩子会被送到\n那些岛上去受罚！$"
	.string ""
	.string ""
	.string ""

OlivineCity_Text_PunishmentBoy:
	.string "每次我一闯祸，\n哥哥就会吓唬我。$"
	.string ""
