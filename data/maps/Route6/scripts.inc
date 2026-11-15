Route6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route6_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route6_EventScript_Rex::
	trainerbattle_single TRAINER_REX PokefanM_Text_RexSeen, PokefanM_Text_RexBeaten
	msgbox PokefanM_Text_RexAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Allan::
	trainerbattle_single TRAINER_ALLAN PokefanM_Text_AllanSeen, PokefanM_Text_AllanBeaten
	msgbox PokefanM_Text_AllanAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Pokefan::
	msgbox Route6_Text_PokefanM, MSGBOX_NPC
	end

Route6_EventScript_Sign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route6_Text_PokefanM:
	.string "在无人发电厂的\n问题解决之前，\l这条路禁止通行。$"
	.string ""
	.string ""

Route6_Text_UndergroundPathSign:
	.string "地下通道\p华蓝市——枯叶市$"
	.string ""

PokefanM_Text_RexSeen:
	.string "我的惊角鹿是全世界\n最可爱的。$"
	.string ""

PokefanM_Text_RexBeaten:
	.string "我的惊角鹿！$"

PokefanM_Text_RexAfter:
	.string "你看我的惊角鹿\n多可爱！\p可爱得让人心都要\n融化了吧？$"
	.string ""
	.string ""
	.string ""

PokefanM_Text_AllanSeen:
	.string "我的布鲁皇是全世界\n最可爱的。$"
	.string ""

PokefanM_Text_AllanBeaten:
	.string "我的布鲁皇！$"

PokefanM_Text_AllanAfter:
	.string "你看我的布鲁皇\n多可爱！\p可爱得让人心都要\n融化了吧？$"
	.string ""
	.string ""
	.string ""

