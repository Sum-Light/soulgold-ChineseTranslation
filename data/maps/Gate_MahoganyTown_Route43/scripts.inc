Gate_MahoganyTown_Route43_MapScripts::
	.byte 0

Gate_MahoganyTown_Route43_EventScript_Cop::
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, Gate_MahoganyTown_Route43_EventScript_CopAfter
	msgbox Route43MahoganyGate_Text_Officer, MSGBOX_NPC
	end

Gate_MahoganyTown_Route43_EventScript_CopAfter::
	msgbox Route43MahoganyGate_Text_Officer_RocketsCleared, MSGBOX_NPC
	end

Route43MahoganyGate_Text_Officer:
    .string "最近从这儿过去的，\n全是往愤怒之湖去的人。$"
    .string ""

Route43MahoganyGate_Text_Officer_RocketsCleared:
    .string "最近都没人\n往愤怒之湖去了。$"
    .string ""

