FuchsiaCity_Route15_Gate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_OnFrame
	.byte 0

Route15_EventScript_Officer::
	msgbox Route15FuchsiaGate_Text_Officer, MSGBOX_NPC
	end

Route15FuchsiaGate_Text_Officer:
	.string "你在做宝可梦图鉴？\n真了不起。\p别放弃啊！$"
	.string ""
	.string ""
