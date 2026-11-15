GoldenrodCity_UndergroundEntrance_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "有人在楼下向我\n挑战对战。\p下面很不太平。\n你最好小心一点。$"
	.string ""
	.string ""
	.string ""


GoldenrodUnderground1_Text_Teacher:
	.string "楼下有些商店……\n但也有训练家。\p我都不敢下去了。$"
	.string ""
	.string ""
