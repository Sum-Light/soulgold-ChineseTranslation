RintoVillage_Mart_MapScripts::
	.byte 0


Rinto_Mart2::
	lock
	faceplayer
	message Rinto_Mart2_Text_0
	waitmessage
	pokemart Rinto2
	msgbox Rinto_Mart2_Text_1
	release
	end


	.align 2
Rinto2:
	.2byte ITEM_TM_BRICK_BREAK
	.2byte ITEM_TM_FACADE
	.2byte ITEM_TM_PLAY_ROUGH
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_NONE

RintoMart_Youngster::
	msgbox RintoMart_Youngster_Text_0, MSGBOX_NPC
	return


RintoMart_Beauty::
	msgbox RintoMart_Beauty_Text_0, MSGBOX_NPC
	return


Rinto_Mart2_Text_0:
	.string "欢迎光临！您需要什么？$"

Rinto_Mart2_Text_1:
	.string "欢迎下次再来！$"

RintoMart_Youngster_Text_0:
	.string "城都的每家友好商店\n都备有自家的招式学习器。\p全都收集齐可是很花钱的！$"

RintoMart_Beauty_Text_0:
	.string "我只是来这儿蹭\n空调的。$"
