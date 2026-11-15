Gate_EcruteakCity_Route42_MapScripts::
	.byte 0

Gate_EcruteakCity_Route42_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route42_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route42_Text_EcruteakGateOfficer:
	.string "擂钵山里面\n就像迷宫一样。\p小心点，别在里面\n迷路了。$"
	.string ""
	.string ""
	.string ""

