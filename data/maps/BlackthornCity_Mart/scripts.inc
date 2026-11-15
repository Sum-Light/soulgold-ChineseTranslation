
BlackthornCity_Mart_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "活力块买不到，但它能让\n濒死的宝可梦完全恢复。\p当心——它不会恢复PP，\n也就是招式所需点数。$"
	.string ""
	.string ""
	.string ""

BlackthornMart_Text_BlackBelt:
	.string "黄金喷雾能让弱小的宝可梦\n远离你。\p它是各种喷雾中\n持续时间最长的。$"
	.string ""
	.string ""
	.string ""

Blackthorn_Mart2::
	lock
	faceplayer
	message Blackthorn_Mart2_Text_0
	waitmessage
	pokemart Blackthorn2
	msgbox Blackthorn_Mart2_Text_1
	release
	end


	.align 2
Blackthorn2:
	.2byte ITEM_TM_ACROBATICS
	.2byte ITEM_TM_DRAGON_TAIL
	.2byte ITEM_TM_SKY_DROP
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_NONE

Blackthorn_Mart2_Text_0:
	.string "欢迎光临！\n请问需要什么？$"

Blackthorn_Mart2_Text_1:
	.string "欢迎再来！$"
