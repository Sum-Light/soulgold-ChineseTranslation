CeladonCity_DepartmentStore_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept3_EventScript_Youngster::
	msgbox CeladonDeptStore3F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid1::
	msgbox CeladonDeptStore3F_Text_GameboyKid1, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid2::
	msgbox CeladonDeptStore3F_Text_GameboyKid2, MSGBOX_NPC
	end
CeladonDept3_EventScript_SuperNerd::
	msgbox CeladonDeptStore3F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept3_EventScript_Directory::
	msgbox CeladonDeptStore3F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore3F_Text_Youngster:
	.string "我还没决定要把这个招式学习器\n用在哪个宝可梦身上……$"
	.string ""

CeladonDeptStore3F_Text_GameboyKid1:
	.string "糟糕！我交换宝可梦时\n忘了取下升级数据。$"
	.string ""

CeladonDeptStore3F_Text_GameboyKid2:
	.string "太好了！我终于\n得到多边兽了！\p我玩老虎机不行，\n所以从来攒不够代币……\p……咦？\p交换来的多边兽\n变成了别的宝可梦！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeladonDeptStore3F_Text_SuperNerd:
	.string "招式学习器专柜\n会卖一些稀有的招式。$"

CeladonDeptStore3F_Text_Directory:
	.string "3楼　招式学习器专柜\p让你的宝可梦变得更强！$"
	.string ""

