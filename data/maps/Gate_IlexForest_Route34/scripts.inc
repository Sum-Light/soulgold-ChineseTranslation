Gate_IlexForest_Route34_MapScripts::
	.byte 0

Route34IlexForestGate_EventScript_Lass::
	lock
	faceplayer
	msgbox Route34IlexForestGate_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34IlexForestGate_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	msgbox Route34IlexForestGate_Text_Butterfree, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34IlexForestGate_Text_Lass:
	.string "你看到那座祭祀\n守护神的祠堂了吗？\p它跨越时光，\n一直守护着这座森林。\p我觉得它一定是\n草属性的宝可梦。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route34IlexForestGate_Text_Butterfree:
	.string "巴大蝶：呼咿！$"
