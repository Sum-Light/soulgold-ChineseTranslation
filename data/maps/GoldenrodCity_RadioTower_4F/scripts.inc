
GoldenrodCity_RadioTower_4F_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28 GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9 GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2 GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, RadioF4_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "兰斯：等等，别急！\p在呆呆兽之井\n妨碍我们的，不就是你吗？\p我明白了……你这么做\n就是想惹我发火。\l小心点！\p既然你这么想，我就让你\n见识一下火箭队干部的\l怒火到底有多可怕！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "呼……$"

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "兰斯：这次算你赢了……\n不过，你只是让火箭队的\p怒火烧得更旺而已。$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "我去遗迹的时候，\n听了收音机。\p那边收到了一段\n很奇怪的广播。$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "胡桃：为什么？为什么\n我非得受这种罪？\p喵喵，救救我！$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "胡桃：哎呀！你可是我的小救星！\p这个就当作谢礼，\n你肯收下吗？$"
	.string ""

GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "胡桃：有了它，就能躲开\p敌人的攻击。$"
	.string ""

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "胡桃：请一定收听大木博士的\n宝可梦讲座，听我主持哦！$"
	.string ""

GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "喵喵：喵……$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "你想救出局长？\p那是不可能的，\n因为我会把你打趴下！$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "不！难以置信！$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "我不信！我居然输了！$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "站住！我可是人称\n火箭队的堡垒！\p你休想再往前走一步！$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "我这个堡垒……垮了！$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "你赢得了我的敬意，\n我劝你一句。\p现在还不晚，\n你还可以回头。$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "问我觉不觉得宝可梦可爱？\p等我的宝可梦打赢你的，\p我才会觉得它们可爱！$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "哎呀！真是没用的东西！$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "我最爱的就是美丽的自己！\p宝可梦什么的，谁管啊？$"
	.string ""

GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "太棒了。\p这座播音塔，会让我们的\n宏伟计划得以实现。$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "嗯……\p再宏伟的计划，也会遇到\n些许阻碍。$"
	.string ""

GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "你真的以为，凭你就能\n阻止火箭队吗？$"
	.string ""

GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "4楼　制作部$"

GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "4楼　第2演播室$"

RadioF4_Mary3::
	msgbox RadioF4_Mary3_Text_0
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox RadioF4_Mary3_Text_1
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end


RadioF4_Mary3_Text_0:
	.string "胡桃：哎呀，我的小救星！\n这个就当作谢礼，你肯收下吗？$"

RadioF4_Mary3_Text_1:
	.string "有了它，就能躲开敌人的攻击！\n我的喵喵最喜欢它了！$"
