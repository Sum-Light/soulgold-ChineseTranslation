MahoganyTown_House1_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 5, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 14, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
    .string "我听说湖里出现了红色的\n暴鲤龙。\p真奇怪，那个湖里连普通的\n暴鲤龙都很少见……$"
    .string ""
    .string ""
    .string ""

MahoganyRedGyaradosHouse_Text_Teacher:
    .string "我最喜欢的广播节目？\n那要数宝可梦音乐了。$"
    .string ""

MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
    .string "最近广播里一直传来\n笑声……\p真让人毛骨悚然。$"
    .string ""
    .string ""
