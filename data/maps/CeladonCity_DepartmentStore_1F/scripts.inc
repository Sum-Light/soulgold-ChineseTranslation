CeladonCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "你好！欢迎光临\n玉虹百货！\p楼层导览图就在墙上。$"
    .string ""
    .string ""

CeladonDeptStore_Text_1FGentleman:
    .string "这家百货和满金市的那家\n是同一连锁店的。\p它们是同一时间\n重新装修的。$"
    .string ""
    .string ""
    .string ""

CeladonDeptStore_Text_1FTeacher:
    .string "我是第一次来这里。\p这里真大……\p我怕我会迷路。$"
    .string ""
    .string ""

CeladonDeptStore_Text_1FDirectory:
    .string "1楼　服务台\p2楼　训练家超市\p3楼　招式学习器专柜\p4楼　智者礼品专柜\p5楼　药品专柜\p6楼　屋顶广场$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
