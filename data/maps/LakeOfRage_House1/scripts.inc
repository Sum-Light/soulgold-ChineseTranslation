
LakeOfRage_House1_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	goto_if_eq VAR_POSTGAME_RIVAL_LEGENDARYQ, 1, LakeOfRageMystic_CresseliaQuest
	goto_if_eq VAR_POSTGAME_RIVAL_LEGENDARYQ, 2, LakeOfRageMystic_CresseliaQuest
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
    .string "……你远道而来……\p我在此地冥想。在我体内，\n有新的力量觉醒了。\p让我把这力量分给你的宝可梦。\n孩子，收下这个。$"
    .string ""
    .string ""
    .string ""
    .string ""

HiddenPowerGuy_Text_Explanation:
    .string "看见了吗？这就是觉醒力量！\p它能引出宝可梦的力量\n来发动攻击。\p记住：它的属性和威力，\n取决于使用它的宝可梦。$"
    .string ""
    .string ""
    .string ""
    .string ""

HiddenPowerGuy_Text_Meditating:
    .string "我正在冥想……$"

LakeOfRageMystic_CresseliaQuest::
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
	goto_if_eq LakeOfRageMystic_CresseliaQuest_2
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 3
	goto_if_ge LakeOfRageMystic_CresseliaQuest_5
	msgbox LakeOfRageMystic_CresseliaQuest_Text_2
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
	release
	end

LakeOfRageMystic_CresseliaQuest_2:
	msgbox LakeOfRageMystic_CresseliaQuest_Text_0
	release
	end

LakeOfRageMystic_CresseliaQuest_5:
	msgbox LakeOfRageMystic_CresseliaQuest_Text_1
	release
	end


LakeOfRageMystic_CresseliaQuest_Text_0:
	.string "仔细找找的话，树木之间\n也许有一条隐秘的小径。$"

LakeOfRageMystic_CresseliaQuest_Text_1:
	.string "我正在冥想……$"

LakeOfRageMystic_CresseliaQuest_Text_2:
	.string "嗯？\n你想知道克雷色利亚的事？\p有意思。\p会主动向我求教的人\n实在少见。\p我确实见过那头生物，\n在难得的夜晚，\l它沐浴着皎洁的月光。\p可一旦被发现，它就会消失在\n湖泊远方的角落！\p仔细找找的话，树木之间\n也许有一条隐秘的小径。$"
