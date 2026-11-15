Gate_RuinsOfAlph_Route36_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route36_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_Text_Officer:
	.string "阿露福遗迹\p能看能摸的观光景点\p来试试推动石板吧！$"
	.string ""
	.string ""

Gate_RuinsOfAlph_Route36_Text_PokefanM:
	.string "你在研究遗迹？\p我看你是个当科学家的料。$"
	.string ""

Gate_RuinsOfAlph_Route36_Text_Youngster:
	.string "石板上画着图案。\p我试着推了推它们。\n不知道那是什么。$"
	.string ""
	.string ""
	.string ""
