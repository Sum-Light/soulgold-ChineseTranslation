VioletCity_House2_MapScripts::
	.byte 0

VioletCity_House2_EventScript_Lass::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VioletCity_NicknameHouse_Text_Bird, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_NicknameHouse_Text_Teacher:
	.string "她喜欢用自己爱吃的东西\n来起名字。\p我是说她给宝可梦\n起的昵称。$"
	.string ""
	.string ""
	.string ""

VioletCity_NicknameHouse_Text_Lass:
	.string "我把我的波波叫作小草莓！$"

VioletCity_NicknameHouse_Text_Bird:
	.string "小草莓：啵啵！$"
