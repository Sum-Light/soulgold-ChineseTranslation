
CherrygroveCity_Mart_MapScripts::
	.byte 0

Cherrygrove_Pokemart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_ge VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Clerk2
	pokemart Cherrygrove_Pokemart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Cherrygrove_Pokemart_EventScript_Youngster::
	lock
	faceplayer
	msgbox Cherrygrove_Pokemart_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Bugcatcher::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Bugcatcher2
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Cherrygrove_Pokemart_EventScript_Bugcatcher2::
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Clerk2::
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 3
Cherrygrove_Pokemart_Pokemart:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_NONE
	release
	end

Cherrygrove_Pokemart_Text_CooltrainerM:
	.string "精灵球都卖光了！\p什么时候才能补货啊？$"
	.string ""

Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock:
	.string "精灵球有货了！\n这下我能抓宝可梦了！$"
	.string ""

Cherrygrove_Pokemart_Text_Youngster:
	.string "我在草丛里走的时候，\n虫宝可梦让我的宝可梦中毒了！\p我硬撑着往前走，\n结果宝可梦昏了过去。\p你身上最好\n常备解毒药。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Cherrygrove_Mart2::
	lock
	faceplayer
	compare VAR_NEWBARK_TOWN_STATE, 5
	goto_if_lt Cherrygrove_Mart2_2
	message Cherrygrove_Mart2_Text_1
	waitmessage
	pokemart Cherrygrove2
	msgbox Cherrygrove_Mart2_Text_2
	release
	end

Cherrygrove_Mart2_2:
	msgbox Cherrygrove_Mart2_Text_0
	release
	end


	.align 2
Cherrygrove2:
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_NONE

Cherrygrove_Mart2_Text_0:
	.string "我们还在准备，\n请稍后再来。$"

Cherrygrove_Mart2_Text_1:
	.string "欢迎光临！$"

Cherrygrove_Mart2_Text_2:
	.string "欢迎再次光临。$"
