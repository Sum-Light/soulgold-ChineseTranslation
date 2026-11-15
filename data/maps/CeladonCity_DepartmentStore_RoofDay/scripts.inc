CeladonCity_DepartmentStore_RoofDay_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_RoofDay_OnTransition
	.byte 0

CeladonCity_DepartmentStore_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay
	end

CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_NIGHT
	return

CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_DAY
	return

CeladonDept6_EventScript_Nerd::
	msgbox CeladonDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept6_EventScript_Youngster::
	msgbox CeladonDeptStore6F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept6_EventScript_Directory::
	msgbox CeladonDeptStore6F_Text_Directory, MSGBOX_SIGN
	end


CeladonDeptStore6F_Text_Vending:
	.string "是自动贩卖机！\n这里是菜单。$"

CeladonDeptStore6F_Text_Clang:
	.string "哐当！\p{STRING}掉了出来。$"
	.string ""

CeladonDeptStore6F_Text_VendingNoMoney:
	.string "哎呀，钱不够……$"

CeladonDeptStore6F_Text_VendingNoSpace:
	.string "已经装不下更多东西了……$"

CeladonDeptStore6F_Text_SuperNerd:
	.string "一台带抽奖轮盘的\n自动贩卖机……\p现在很少见得到这种东西了。$"
	.string ""
	.string ""

CeladonDeptStore6F_Text_Youngster:
	.string "唉！这里没有游戏！\p我好想玩啊……$"
	.string ""

CeladonDeptStore6F_Text_Directory:
	.string "6楼　休闲广场\n自动贩卖机$"
	.string ""
