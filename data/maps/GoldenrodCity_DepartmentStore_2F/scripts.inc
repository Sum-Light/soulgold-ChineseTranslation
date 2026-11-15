GoldenrodCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore2_EventScript_Youngster::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Gent::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FGentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_2FYoungster:
    .string "宝可梦装置最多能存25个\n电话号码。\p要决定留下哪些号码\n可真难。$"
    .string ""
    .string ""
    .string ""

GoldenrodDeptStore_Text_2FCooltrainerF:
    .string "我的单首龙是在游戏城\n得到的。\p现在它是我最好的\n伙伴。$"
    .string ""

GoldenrodDeptStore_Text_2FGentleman:
    .string "这家百货店让我真切感到\n满金市真是座大城市。\p这里的商品之丰富，\n别处根本比不了。$"
    .string ""
    .string ""
    .string ""

GoldenrodDeptStore_Text_2FDirectory:
    .string "旅行的好帮手\p2楼　训练家超市$"
    .string ""
