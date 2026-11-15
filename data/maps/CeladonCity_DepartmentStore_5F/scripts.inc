.set LOCALID_CELADON_FALKNER, 5

CeladonCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept5_EventScript_Gent::
	msgbox CeladonDeptStore5F_Text_Gentleman, MSGBOX_NPC
	end
CeladonDept5_EventScript_Sailor::
	msgbox CeladonDeptStore5F_Text_Sailor, MSGBOX_NPC
	end
CeladonDept5_EventScript_Teacher::
	msgbox CeladonDeptStore5F_Text_Teacher, MSGBOX_NPC
	end
CeladonDept5_EventScript_Directory::
	msgbox CeladonDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore5_EventScript_Falkner::
	lock
	faceplayer
	msgbox CeladonDeptStore5_Text_Falkner, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_VIOLET_SCHOOL_FALKNER
	removeobject LOCALID_CELADON_FALKNER
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_FALKNER
	release
	end

CeladonDeptStore5_Text_Falkner:
	.string "{PLAYER}。没想到会在这里\n见到你。\p我来给我的鸟宝可梦\n买些装备。\p要是你还想和我对战，\n就到金黄市的格斗道场来吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeladonDeptStore5F_Text_Gentleman:
	.string "我想买些能提升宝可梦能力的\n道具，可我的钱\l不够……$"
	.string ""
	.string ""

CeladonDeptStore5F_Text_Sailor:
	.string "我想要PP提升剂，好提升\n招式的PP。可是买不到……$"
	.string ""

CeladonDeptStore5F_Text_Teacher:
	.string "给宝可梦用道具，\n它们会很高兴。\p不过有些道具它们很讨厌……$"
	.string ""
	.string ""

CeladonDeptStore5F_Text_Directory:
	.string "5楼　药店$"
