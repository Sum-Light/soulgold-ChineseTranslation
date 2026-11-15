Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "训练家碰了面，\n第一件事就是对战。$"
	.string ""

Route1_Text_SchoolboyDanny_Beaten:
	.string "唉……我又多了一场败绩……$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "对训练家来说，\n碰了面就该对战，这是常识。$"
	.string ""

Route1_Text_CooltrainerFQuinn_Seen:
	.string "喂，你！要不要对战？$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "一败涂地……$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "你挺强的。\p看来你一定下过\n不少苦功。$"
	.string ""
	.string ""

Route1_Text_Sign:
	.string "1号道路\p真新镇——常青市$"
	.string ""
