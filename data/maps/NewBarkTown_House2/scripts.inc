NewBarkTown_House2_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "你好，{PLAYER}！我丈夫总是\n那么忙，但愿他没事。\p他一旦钻进宝可梦研究里，\n连饭都会\l忘记吃。$"
	.string ""
	.string ""
	.string ""
	.string ""

NewBarkTown_House2_Text_ElmsSon:
	.string "我长大后要帮爸爸的忙！\p我要成为很厉害的\n宝可梦博士！$"
	.string ""
	.string ""
	.string ""
