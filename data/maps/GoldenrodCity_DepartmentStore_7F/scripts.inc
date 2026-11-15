.set LOCALID_GOLDENROD_ROOF_NERD, 1

GoldenrodCity_DepartmentStore_7F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 20
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
    .string "呼，逛得真累。\p逛累了，我时不时\n会上楼顶来歇口气。$"
    .string ""
    .string ""

GoldenrodDeptStore_Text_RoofFisher:
    .string "你说什么？谁说大人就不能\n迷上这个？\p我以后天天都来，\n把玩偶全部收集齐！$"
    .string ""
    .string ""
    .string ""

GoldenrodDeptStore_Text_RoofTwin:
    .string "这里时不时就会\n搞一次大减价。$"
    .string ""

GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
    .string "哇！$"

GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
    .string "你别再烦我了好不好？$"

GoldenrodDeptStore_Text_RoofPokefanM:
    .string "有样东西我特别想要，\n可手头的钱不够……\p也许该把攒下的树果\n卖掉一些……$"
    .string ""
    .string ""
    .string ""

GoldenrodDeptStore_Text_RoofTeacher:
    .string "哎呀，东西都好便宜！\p我买了一大堆，\n包包都塞满了！$"
    .string ""

GoldenrodDeptStore_Text_RoofBugCatcher:
    .string "一到关键时候，我的宝可梦\n就麻痹啊中毒啊……\p所以我来买万灵药。\p不知道还有没有剩的？$"
    .string ""
    .string ""
    .string ""
