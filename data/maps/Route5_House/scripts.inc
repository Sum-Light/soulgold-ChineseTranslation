Route5_House_MapScripts::
	.byte 0

Route5_House_EventScript_Granny::
	goto_if_set FLAG_GOT_CLEANSE_TAG, Route5_House_EventScript_GrannyAfter
	msgbox Route5_House_Text_Granny1, MSGBOX_NPC
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_CLEANSE_TAG
	release
	end

Route5_House_EventScript_GrannyAfter::
	msgbox Route5_House_Text_Granny2, MSGBOX_NPC
	end

Route5_House_EventScript_Woman::
	msgbox Route5_House_Text_Woman, MSGBOX_NPC
	end

Route5_House_Text_Granny1:
	.string "呀啊啊啊！\p我感觉到一股邪气\n缠绕在你身上。\l拿这个去挡一挡吧！$"
	.string ""
	.string ""
	.string ""

Route5_House_Text_Granny2:
	.string "你刚才是性命攸关，\n不过现在没事了。$"
	.string ""

Route5_House_Text_Woman:
	.string "我奶奶热衷于驱除\n她认定的恶灵。\p不好意思，吓到你了。$"
	.string ""
	.string ""
