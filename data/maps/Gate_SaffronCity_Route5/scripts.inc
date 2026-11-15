Gate_SaffronCity_Route5_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route5_EventScript_Guard::
	msgbox Route5_Text_SaffronGateOfficer, MSGBOX_NPC
	end

Route5_Text_SaffronGateOfficer:
	.string "你是城都来的吧？\p你觉得关都怎么样？\n是个好地方吧？$"
	.string ""
	.string ""
