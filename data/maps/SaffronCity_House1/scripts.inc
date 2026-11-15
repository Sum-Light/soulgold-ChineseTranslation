SaffronCity_House1_MapScripts::
	.byte 0

SaffronCity_House1_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_PSYCHIC, SaffronCity_House1_EventScript_MrPsychicAfter
	msgbox MrPsychic_Text_1, MSGBOX_NPC
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	setflag FLAG_GOT_TM_PSYCHIC
	release
	end

SaffronCity_House1_EventScript_MrPsychicAfter::
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	end

MrPsychic_Text_1:
	.string "……\p……\p……\p……我明白了！\p你想要这个吧！$"
	.string ""
	.string ""
	.string ""
	.string ""

MrPsychic_Text_2:
	.string "招式学习器29里装的是\n精神强念。\p有时还能降低对手的\n特防。$"
	.string ""
	.string ""
