
EcruteakCity_Mart_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "我的伊布进化成了\n太阳伊布。\p可是朋友的伊布\n却进化成了月亮伊布。\p明明都是用同样的方法\n养大的……为什么？$"
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakMart_Text_Granny:
	.string "给濒死的宝可梦用活力碎片，\n它马上就会醒过来哦。$"
	.string ""

Ecruteak_Mart2::
	lock
	faceplayer
	message Ecruteak_Mart2_Text_0
	waitmessage
	pokemart Ecruteak2
	msgbox Ecruteak_Mart2_Text_1
	release
	end


	.align 2
Ecruteak2:
	.2byte ITEM_TM_SNARL
	.2byte ITEM_TM_TRAILBLAZE
	.2byte ITEM_TM_TRICK_ROOM
	.2byte ITEM_TM_WILL_O_WISP
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_NONE

Ecruteak_Mart2_Text_0:
	.string "欢迎光临！有什么可以帮您？$"

Ecruteak_Mart2_Text_1:
	.string "欢迎再来！$"
