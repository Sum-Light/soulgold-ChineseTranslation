LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_GARBAGEFLAG, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GARBAGEFLAG
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "欢迎来到中药店，\n这里出售便宜而有效的药！$"
	.string ""

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "你是来釜炎镇\n买中药的吗？\p不错，我喜欢你！\p这个给你吧！$"
	.string ""
	.string ""
	.string ""

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "我给你的木炭是用来\n煮中药的，\p如果给宝可梦的话\n也会出现些奇妙的事情，\p它能增强火属性招式的\n威力。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "中药的效果极佳，\n但那会让宝可梦讨厌你。\l它实在太苦了！$"
	.string ""
	.string ""

