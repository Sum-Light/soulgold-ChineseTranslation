MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_NONE, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "老师……\n请看看我的进步吧！$"
	.string ""

MtPyre_5F_Text_AtsushiDefeat:
	.string "老师……\n请原谅我！$"
	.string ""

MtPyre_5F_Text_AtsushiPostBattle:
	.string "只有当我变强了，沉睡于此的\n老师才能得到真正的安眠……$"
	.string ""

