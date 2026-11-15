Gate_EcruteakCity_Route38_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "你说你是从哪儿来的？\p若叶镇？\p空木博士就住在那一边，\n对吧？\p你可真是大老远\n跑过来的。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
