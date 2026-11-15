Route30_House_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "顺着这条路往北走，\n就能看到宝可梦爷爷的家。\p不过在那之前，\n让我先跟你说说树果吧！\p宝可梦吃了树果\n会变得更健康。\p对战时，它们还能吃掉\n带在身上的树果。\p来，我分你一个！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route30_BerryHouse_Text_CheckTrees:
	.string "检查果树就能采到树果。\n12小时后会重新长出来。$"
	.string ""
