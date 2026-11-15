BlackthornCave_MapScripts::
	.byte 0


BlackthornCave_Hint::
	msgbox BlackthornCave_Hint_Text_0, MSGBOX_SIGN
	return


BlackThornCave_Expert::
	lock
	faceplayer
	goto_if_set FLAG_GOT_KUBFU, BlackThornCave_Expert_2
	msgbox BlackThornCave_Expert_Text_1
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KUBFU
	bufferspeciesname STR_VAR_1, SPECIES_KUBFU
	givemon SPECIES_KUBFU, 5
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	setflag FLAG_GOT_KUBFU
	msgbox BlackThornCave_Expert_Text_2
	release
	end

BlackThornCave_Expert_2:
	msgbox BlackThornCave_Expert_Text_0
	release
	end


BlackthornCave_Hint_Text_0:
	.string "正午时分，一格加上，\n另一格减去。$"

BlackThornCave_Expert_Text_0:
	.string "让我一个人待着！我要冥想！$"

BlackThornCave_Expert_Text_1:
	.string "哼，\n果然有人解开了啊。\p我一直作为隐者\n在这洞窟里修行，\l磨炼武术与精神。\p看来你是想从我\n这里得到点什么。\l行吧！拿上这个，走吧。$"

BlackThornCave_Expert_Text_2:
	.string "我听说，一批用来让\n那只宝可梦进化的挂轴\l被火箭队偷走了。\p真是丢人现眼！要是\n我再年轻30岁，一定\l亲手去追回来！$"
