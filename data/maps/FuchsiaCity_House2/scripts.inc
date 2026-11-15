FuchsiaCity_House2_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "我爷爷是狩猎地带的\n园长。\p至少以前是……\p他决定去度假，\n就一个人跑到国外去了。\p他就这么撒手不管\n狩猎地带了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "狩猎地带关门，\n让很多人失望了，但我爷爷\l就是这么固执……$"
	.string ""
	.string ""

FuchsiaCity_House2_Text_WardenPhoto:
	.string "是一张照片：一位老爷爷\n笑得开心，被宝可梦围着。$"
	.string ""

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "是一张照片：辽阔的草原上，\n稀有的宝可梦在嬉戏。$"
	.string ""
