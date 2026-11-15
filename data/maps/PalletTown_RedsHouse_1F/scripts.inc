PalletTown_RedsHouse_1F_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "你好！\p赤红已经出门很久了。\p他也没打过电话，我完全\n不知道他在哪里、\l在做些什么。\p人们说没消息就说明他\n过得不错，可我还是\l忍不住担心他。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

RedsHouse_Text_Mom2:
	.string "我担心赤红会不会受伤、\n会不会生病，可他是个男孩子。\p他在做自己想做的事，\n我为他骄傲。$"
	.string ""
	.string ""
	.string ""

RedsHouse_Text_TV:
	.string "这里有在城都看不到的\n电视节目……$"
	.string ""
