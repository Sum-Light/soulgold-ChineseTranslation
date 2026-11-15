PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PalletTown_OnLoad
	.byte 0

PalletTown_OnLoad::
	setrespawn HEAL_LOCATION_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "我也在养宝可梦。\p它们是我的私人\n保镖。$"
	.string ""
	.string ""

PalletTown_Text_Fisher:
	.string "科技真是了不起！\p现在可以像发电子邮件一样，\n跨时空交换宝可梦。$"
	.string ""
	.string ""

PalletTown_Text_Sign:
	.string "真新镇\p宁静祥和的\n纯洁之地$"
	.string ""
	.string ""

PalletTown_Text_RedsHouseSign:
	.string "赤红的家$"

PalletTown_Text_OaksLabSign:
	.string "大木宝可梦\n研究所$"
	.string ""

PalletTown_Text_BluesHouseSign:
	.string "青绿的家$"
