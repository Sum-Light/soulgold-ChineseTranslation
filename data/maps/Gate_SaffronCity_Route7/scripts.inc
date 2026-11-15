Gate_SaffronCity_Route7_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "你听说无人发电厂\n出事故了吗？\p它在东边，就在\n紫苑镇附近。$"
	.string ""
	.string ""
	.string ""

Route7_Text_SaffronGuard_Serious:
	.string "我对警备工作可是很认真的。\p喂！你带着宝可梦图鉴。\p好。你可以通过了。$"
	.string ""
	.string ""
