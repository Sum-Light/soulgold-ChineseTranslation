CherrygroveCity_House3_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "宝可梦在战斗中积累经验，\n外形也会发生变化。$"
	.string ""

CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "宝可梦会变化？\p要真是那样，\n我会吓一大跳的！$"
	.string ""
	.string ""
