Route2_House_MapScripts::
	.byte 0

Route2_House_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_GOT_ROUTE2_NUGGET, Route2_House_EventScript_ManAfter
	msgbox Route2_House_Text_Fisher, MSGBOX_DEFAULT 
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_ROUTE2_NUGGET
	release
	end

Route2_House_EventScript_ManAfter::
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	release
	end

Route2_House_Text_Fisher:
	.string "嗨！哇，见到你真高兴。\p好久好久没有客人\n上门了。\p我太开心了！送你点\n小礼物。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route2_House_Text_Fisher_GotNugget:
	.string "那是金珠。\p我可没什么金玉良言\n送你，就拿这个凑数吧！$"
	.string ""
	.string ""
