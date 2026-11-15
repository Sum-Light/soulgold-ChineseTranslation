CeladonCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "我来买冲浪邮件，\n想寄给我女朋友。\p等等，卖完了？$"
	.string ""
	.string ""

CeladonDeptStore4F_Text_Youngster:
	.string "这里是唯一能买到\n可爱邮件的地方。$"
	.string ""

CeladonDeptStore4F_Text_Directory:
	.string "用礼物表达你的心意！\p4楼　智者礼品专柜$"
	.string ""
