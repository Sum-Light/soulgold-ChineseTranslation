MtMortar_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_2F_EventScript_Nerd::
	trainerbattle_single TRAINER_HUGH MtMortar_2F_Text_SupernerdHughSeen, MtMortar_2F_Text_SupernerdHughBeaten
	msgbox MtMortar_2F_Text_SupernerdHughAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_2F_Text_SupernerdHughSeen::
	.string "哟！学霖！$"

MtMortar_2F_Text_SupernerdHughBeaten:
	.string "抱歉，是我搞错了。\n认错人了。$"
	.string ""

MtMortar_2F_Text_SupernerdHughAfter:
	.string "我是来擂钵山调查的，\n可我的伙伴不见了。\p你有没有见过一个，带着\n会怪力的呆呆兽\l的训练家？$"
	.string ""
	.string ""
	.string ""
	.string ""
