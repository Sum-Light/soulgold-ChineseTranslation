CeladonCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "我最近才成为训练家。\p是我儿子鼓励我这么做的。\p这里方便的道具种类之丰富\n让我很佩服。$"
	.string ""
	.string ""
	.string ""

CeladonDeptStore2F_Text_Youngster:
	.string "我爸爸怎么也记不住\n道具的名字和\l它们的用法……$"
	.string ""
	.string ""

CeladonDeptStore2F_Text_Directory:
	.string "训练家的一流道具！\p2楼　训练家超市$"
	.string ""

