MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "感谢使用\n神秘礼物系统。\p你一定是{PLAYER}。\n这是给你的票。$"
	.string ""
	.string ""
	.string ""

sText_MysticTicketUseAtPort:
	.string "看起来是在\n水静市港口使用的。\p为什么不试一下\n看看它到底怎么用？$"
	.string ""
	.string ""
	.string ""

sText_MysticTicketThankYou:
	.string "感谢使用\n神秘礼物系统。$"
	.string ""

sText_MysticTicketBagFull:
	.string "哦，抱歉，{PLAYER}。\n你的包包里放重要物品的口袋满了。\p请存一些东西到电脑\n然后回来拿这个吧。$"
	.string ""
	.string ""
	.string ""
