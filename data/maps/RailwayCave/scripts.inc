RailwayCave_MapScripts::
	.byte 0


RailwayCave1_Keira::
	trainerbattle_single TRAINER_KEIRA, RailwayCave1_Keira_Text_0, RailwayCave1_Keira_Text_1
	msgbox RailwayCave1_Keira_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave1_Tammy::
	trainerbattle_single TRAINER_TAMMY, RailwayCave1_Tammy_Text_0, RailwayCave1_Tammy_Text_1
	msgbox RailwayCave1_Tammy_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave1_Keira_Text_0:
	.string "喂！这里很危险！$"

RailwayCave1_Keira_Text_1:
	.string "小心点，我们还在施工……$"

RailwayCave1_Keira_Text_2:
	.string "我们正在借助这里的\n宝可梦，扩建铁路。$"

RailwayCave1_Tammy_Text_0:
	.string "这里充满了电！$"

RailwayCave1_Tammy_Text_1:
	.string "我脊背都发麻了！$"

RailwayCave1_Tammy_Text_2:
	.string "这里似乎很适合\n训练地面属性的宝可梦。$"
