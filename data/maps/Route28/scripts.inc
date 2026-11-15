
Route28_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route28_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route28_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route28_EventScript_Sign::
	msgbox Route28_Text_Sign, MSGBOX_SIGN
	end

Route28_Text_Sign:
	.string "28号道路$"

Route28Guard::
	msgbox Route28Guard_Text_0, MSGBOX_NPC
	return


Route28Guard_Text_0:
	.string "再往前就是险峻的\n白银山了。只有得到联盟\l明确许可的人，\l才能进入那里。$"
