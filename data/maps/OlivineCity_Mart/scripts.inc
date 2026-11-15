
OlivineCity_Mart_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "你的宝可梦\n已经学会可以\l载人渡水的招式了吗？$"
	.string ""
	.string ""

OlivineCity_Text_MartLass:
	.string "我的巴大蝶是国外的\n男朋友送来的。\p它还带来了他写的邮件。\p想知道上面写了什么吗？\p让我看看……不行！\n这是秘密！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Olivine_Mart2::
	lock
	faceplayer
	message Olivine_Mart2_Text_0
	waitmessage
	pokemart Olivine2
	msgbox Olivine_Mart2_Text_1
	release
	end


	.align 2
Olivine2:
	.2byte ITEM_TM_DRAINING_KISS
	.2byte ITEM_TM_BRUTAL_SWING
	.2byte ITEM_TM_CHARGE_BEAM
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_LEVEL_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_NONE

Olivine_Mart2_Text_0:
	.string "欢迎光临！有什么能为您效劳的？$"

Olivine_Mart2_Text_1:
	.string "欢迎您随时再来！$"
