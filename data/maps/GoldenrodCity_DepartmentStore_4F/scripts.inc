GoldenrodCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

	.align 2
Goldenrod_DepartmentStore_3F_Pokemart_Vitamins:
	.2byte ITEM_REVERSE_CANDY
	.2byte ITEM_POWER_WEIGHT
	.2byte ITEM_POWER_BRACER
	.2byte ITEM_POWER_BELT
	.2byte ITEM_POWER_LENS
	.2byte ITEM_POWER_BAND
	.2byte ITEM_POWER_ANKLET
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "嘿。我最喜欢强大的宝可梦。\p我会喂它们攻击增强剂，\n把攻击力提上去。$"
    .string ""
    .string ""

GoldenrodDeptStore_Text_4FBugCatcher:
    .string "防御增强剂能提升\n宝可梦的防御力。$"
    .string ""

GoldenrodDeptStore_Text_4FGameboyKid:
    .string "有传闻说，有些宝可梦\n只有通过连接线\l和别人交换\l才会进化。\p切……\p这种假消息。\p我知道好几种传闻里的\n宝可梦：\l豪力、勇基拉、鬼斯通，\l还有，嗯，隆隆石，\l但它们其实都是靠\l联系绳进化的。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

GoldenrodDeptStore_Text_4FDirectory:
    .string "让您的宝可梦更强！\p4楼　药盒$"
    .string ""
