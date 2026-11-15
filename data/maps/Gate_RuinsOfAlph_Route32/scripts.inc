Gate_RuinsOfAlph_Route32_MapScripts::
	.byte 0


Gate_RuinsOfAlph_Route32_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_Text_PokefanM:
	.string "你在研究遗迹？\n我看你是个当科学家的料。$"
	.string ""

Gate_RuinsOfAlph_Route32_Text_Youngster:
	.string "石板上画着图案。\p我试着推了推它们。\n不知道那是什么。$"
	.string ""
	.string ""
	.string ""
