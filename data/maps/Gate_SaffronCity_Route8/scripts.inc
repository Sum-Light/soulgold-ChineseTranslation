Gate_SaffronCity_Route8_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route8_EventScript_Guard::
	msgbox Route8_Text_SaffronGateOfficer, MSGBOX_NPC
	end

Route8_Text_SaffronGateOfficer:
	.string "你去过紫苑镇吗？\p那里有一座高高的\n播音塔。$"
	.string ""
