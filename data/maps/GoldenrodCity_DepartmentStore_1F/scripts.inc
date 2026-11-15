GoldenrodCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "欢迎光临满金百货店。$"

GoldenrodDeptStore1_Text_Gentleman:
    .string "百货店的商品还算\n齐全。\p不过有些商品只有游戏城\n兑换奖品里才有。$"
    .string ""
    .string ""
    .string ""

GoldenrodDeptStore1_Text_PokefanF:
    .string "今天也要大买特买！$"

GoldenrodDeptStore1_Text_BugCatcher:
    .string "我妈很会淘便宜货。\p她总能以更低的\n价格买到东西。$"
    .string ""
    .string ""

GoldenrodDeptStore1_Text_Directory:
    .string "<1楼　服务台>\p2楼　训练家超市\p3楼　对战藏品\p4楼　药盒\p5楼　招式学习器专柜\p6楼　休息广场\p屋顶观景台$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
