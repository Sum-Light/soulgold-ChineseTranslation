Route16_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route16_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route16_EventScript_Sign::
	msgbox Route16_Text_Sign, MSGBOX_SIGN
	end

Route16_Text_Sign:
	.string "自行车道\n一路下坡\l畅行到底！$"
	.string ""
	.string ""
