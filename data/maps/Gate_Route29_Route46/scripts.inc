Gate_Route29_Route46_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "台阶是爬不上去的。\p但可以从上面跳下来，\n抄个近路。$"
	.string ""
	.string ""

Gate_Route29_Route46_Text_Youngster:
	.string "过了这里，出现的宝可梦\n种类就不一样了。\p想把它们全都捉到，\n就得四处去找。$"
	.string ""
	.string ""
	.string ""
