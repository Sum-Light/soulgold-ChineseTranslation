MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "感谢使用\n神秘礼物系统。\p您的对战积分卡保留着\n您和其他拥有相同卡的\l训练家对战录像。\p寻找并和拥有与您有相同卡的训练家\n进行对战吧。\p您可以检查最终排名\n通过阅读新闻。\p请一定要试试看！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "感谢使用\n神秘礼物系统。\p恭喜！\p您获得了赢取\n3场对战的奖励！\p希望您再接再厉\n进行更多对战。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
