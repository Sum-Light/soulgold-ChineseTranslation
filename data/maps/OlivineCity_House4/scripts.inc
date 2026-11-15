OlivineCity_House4_MapScripts::
	.byte 0


OlivineTutorMoveMaster::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_MOVES_UNLOCKED, OlivineTutorMoveMaster_2
	msgbox OlivineTutorMoveMaster_Text_1
	showmoneybox 0, 0
	msgbox OlivineTutorMoveMaster_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq OlivineTutorMoveMaster_5
	hidemoneybox
	msgbox OlivineTutorMoveMaster_Text_6
	release
	end

OlivineTutorMoveMaster_2:
	msgbox OlivineTutorMoveMaster_Text_0
	release
	end

OlivineTutorMoveMaster_4:
	release
	end

OlivineTutorMoveMaster_5:
	checkmoney 44444
	compare VAR_RESULT, FALSE
	goto_if_eq OlivineTutorMoveMaster_9
	removemoney 44444
	updatemoneybox 0
	playse SE_SHOP
	waitse
	setflag FLAG_TUTOR_MOVES_UNLOCKED
	special Achievement_CheckAll
	msgbox OlivineTutorMoveMaster_Text_4
	hidemoneybox
	closemessage
	fadescreen FADE_TO_BLACK
	delay 60
	fadescreen FADE_FROM_BLACK
	delay 20
	playfanfare MUS_OBTAIN_ITEM
	msgbox OlivineTutorMoveMaster_Text_5
	waitse
	msgbox OlivineTutorMoveMaster_Text_0
	goto OlivineTutorMoveMaster_4

OlivineTutorMoveMaster_9:
	msgbox OlivineTutorMoveMaster_Text_3
	hidemoneybox
	release
	end


OlivineTutorMoveMaster_Text_0:
	.string "想教宝可梦教授招式，\n请在查看能力画面的\l战斗招式页按START键，\l再切换到教授招式页。$"

OlivineTutorMoveMaster_Text_1:
	.string "我是教授招式大师。\p关于教授招式，我无所不知。\p只要你愿意，我可以把我\n知道的全部教给你，\l一次性收费¥44,444。$"

OlivineTutorMoveMaster_Text_2:
	.string "怎么样？你想学会\n教授招式的全部吗？$"

OlivineTutorMoveMaster_Text_3:
	.string "看来你的钱不够\n学这些啊。真遗憾。$"

OlivineTutorMoveMaster_Text_4:
	.string "多谢惠顾！\p现在，就让我来传授你\n教授招式的奥秘吧。$"

OlivineTutorMoveMaster_Text_5:
	.string "你现在可以教自己的宝可梦\n学习教授招式了！$"

OlivineTutorMoveMaster_Text_6:
	.string "真遗憾。$"
