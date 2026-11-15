
GoldenrodCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
    map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodDeptSundayNpc
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
    .string "您好。哦，您的宝可梦……$"

GoldenrodDeptStore_Text_5FReceptionistWait:
    .string "等等，那个招式学习器\n我不是已经给您了吗！$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "嗯……\n说不上差，但也不算好。\p您作为训练家，还得\n再下点功夫。$"
	.string ""
	.string ""
	.string ""


GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
    .string "每天晚上我们都会赠送\n招式学习器的样品。请收下吧。$"

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect2:
    .string "希望那个招式学习器\n对您有用。$"

GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
    .string "它看起来有点邪气。\n这个招式学习器怎么样？$"
    .string ""

GoldenrodDeptStore_Text_5FReceptionistThereAreTMsPerfectForMon:
    .string "一定有和您的宝可梦\n无比契合的招式学习器。$"
    .string ""

GoldenrodDeptStore_Text_5FLass:
    .string "一到晚上，就有一位女士\n来派发免费的招式学习器！$"
    .string ""

GoldenrodDeptStore_Text_5FPokefanM:
    .string "交换来的宝可梦是\n不能改名的。\p名字里凝聚着原训练家\n对它的感情。$"
    .string ""
    .string ""
    .string ""

GoldenrodDeptStore_Text_Girl:
	.string "昨天晚上，一位好心的\n女士送了我报恩！$"
    .string ""

GoldenrodDeptStore_Text_5FDirectory:
    .string "打造您的宝可梦\p5楼　招式学习器专柜$"
    .string ""

GoldenrodDeptSundayNpc::
	compare VAR_DAY_OF_WEEK, 0
	goto_if_ne GoldenrodDeptSundayNpc_1
	return

GoldenrodDeptSundayNpc_1:
	setflag FLAG_TEMP_A
	return


Goldenrod_F5_ReturnClerk::
	lock
	goto_if_set FLAG_GOT_RETURN, Goldenrod_F5_ReturnClerk_2
	msgbox Goldenrod_F5_ReturnClerk_Text_1
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	msgbox Goldenrod_F5_ReturnClerk_Text_0
	release
	end

Goldenrod_F5_ReturnClerk_2:
	msgbox Goldenrod_F5_ReturnClerk_Text_0
	release
	end


GoldenrodDept5FMart::
	lock
	msgbox GoldenrodDept5FMart_Text_0
	waitmessage
	pokemart Goldenrod_F5_TMMart
	msgbox GoldenrodDept5FMart_Text_1
	release
	end


	.align 2
Goldenrod_F5_TMMart:
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_DIG
	.2byte ITEM_TM_FIRE_PUNCH
	.2byte ITEM_TM_ICE_PUNCH
	.2byte ITEM_TM_THUNDER_PUNCH
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_NONE

Goldenrod_F5_ReturnClerk_Text_0:
	.string "报恩这招，宝可梦越喜欢您，\n威力就越大！$"

Goldenrod_F5_ReturnClerk_Text_1:
	.string "我们现在正在派发\n最受欢迎招式学习器的样品。\p来，请拿一个吧！$"

GoldenrodDept5FMart_Text_0:
	.string "欢迎光临招式学习器专柜！$"

GoldenrodDept5FMart_Text_1:
	.string "欢迎再来！$"
