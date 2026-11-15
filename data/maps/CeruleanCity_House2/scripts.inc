CeruleanCity_House2_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Woman::
	msgbox CeruleanPolice_Text_PokefanF, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Man::
	msgbox CeruleanPolice_Text_FishingGuru, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Diglett::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
	msgbox CeruleanPolice_Text_Diglett, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanPolice_Text_FishingGuru:
	.string "听说有个可疑的家伙\n在附近鬼鬼祟祟。\p要是他真是小偷，\n我绝不会放过他。$"
	.string ""
	.string ""
	.string ""

CeruleanPolice_Text_PokefanF:
	.string "以前，我们被强盗打劫过。$"

CeruleanPolice_Text_Diglett:
	.string "地鼠：嘟咕嘟咕。$"
