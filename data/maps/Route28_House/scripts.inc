Route28_House_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	goto_if_set FLAG_GOT_TM_STEEL_WING Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	createfieldmugshot MUGSHOT_COOLTRAINER_F
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "哎呀，被你找到了。\p请别把我的事\n告诉任何人。\p只要你替我保密，\n我就把这个送给你。拜托了？$"
	.string ""
	.string ""
	.string ""

Route28House_Text_Celebrity2:
	.string "当名人真不容易。\p我走到哪儿，\n都有人追着。\p我只想一个人\n清静清静……$"
	.string ""
	.string ""

Route28House_Text_Fearow:
	.string "大嘴雀：啾噜！$"

