AzaleaTown_House1_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "镇上的呆呆兽全都\n不见了。\p森林的守护神也许是\n在生我们的气……\p这或许是不祥的预兆。\n我们还是待在家里吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CharcoalKiln_Text_Boss2:
	.string "呆呆兽回来了……$"

CharcoalKiln_Text_Boss3:
	.string "呆呆兽回来了……\p可我的徒弟去了栎树林，\n到现在还没回来。\p那个懒家伙\n到底跑哪儿去了？$"
	.string ""
	.string ""
	.string ""

CharcoalKiln_Text_Boss4:
	.string "你赶跑了火箭队，\n还一个人去了栎树林？\p有胆量！我喜欢。\n来和我们一起修行吧。$"
	.string ""
	.string ""
	.string ""

CharcoalKiln_Text_Apprentice1:
	.string "呆呆兽们都去哪儿了？\p是不是跑到哪里玩去了？$"
	.string ""

CharcoalKiln_Text_Apprentice2:
	.string "呆呆兽回来了！$"

CharcoalKiln_Text_Apprentice3:
	.string "不好意思——我忘了向你道谢。\p这是我做的木炭。\p火属性的宝可梦\n会很高兴带着它的。$"
	.string ""
	.string ""
	.string ""

CharcoalKiln_Text_Apprentice4:
	.string "呆呆兽回来了，你还找到了\n大葱鸭。\p你真是太帅了，老兄！$"
	.string ""
	.string ""

CharcoalKiln_Text_Farfetchd:
	.string "大葱鸭：嘎哇！$"
