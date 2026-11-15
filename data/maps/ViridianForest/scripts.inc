.set LOCALID_VIRIDIAN_BUGSY, 16

ViridianForest_MapScripts::
	.byte 0

ViridianForest_EventScript_Bugsy::
	lock
	faceplayer
	msgbox ViridianForest_Text_Bugsy, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_NATIONAL_BUGSY
	removeobject LOCALID_VIRIDIAN_BUGSY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_BUGSY
	release
	end

ViridianForest_Text_Bugsy:
	.string "阿笔：我来到了关都，\n寻找虫属性宝可梦，\l为了成为更强的\l虫属性宝可梦训练家！\p想再和我较量的话，\n就到金黄市的格斗道场来！$"
	.string ""
	.string ""
	.string ""
    .string ""
    .string ""

