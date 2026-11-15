BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

.macro setitemandprice item:req, price:req
	setvar VAR_0x8009, \item
	setvar VAR_0x8008, \price
.endm

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1::
	bufferdecorationname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	setitemandprice DECOR_KISS_POSTER, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	setitemandprice DECOR_KISS_CUSHION, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
	setitemandprice DECOR_SMOOCHUM_DOLL, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	setitemandprice DECOR_TOGEPI_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	setitemandprice DECOR_MEOWTH_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	setitemandprice DECOR_CLEFAIRY_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	setitemandprice DECOR_DITTO_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	setitemandprice DECOR_CYNDAQUIL_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	setitemandprice DECOR_CHIKORITA_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	setitemandprice DECOR_TOTODILE_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2::
	bufferdecorationname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	setitemandprice DECOR_LAPRAS_DOLL, 128
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	setitemandprice DECOR_SNORLAX_DOLL, 128
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	setitemandprice DECOR_VENUSAUR_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	setitemandprice DECOR_CHARIZARD_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	setitemandprice DECOR_BLASTOISE_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_EonTicket
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_MysticTicket
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_AuroraTicket
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_OldMap
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brace
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_Upgrade
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_EonTicket::
	checkitem ITEM_EON_TICKET, 1
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmEonTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setitemandprice ITEM_EON_TICKET, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MysticTicket::
	checkitem ITEM_MYSTIC_TICKET, 1
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMysticTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setitemandprice ITEM_MYSTIC_TICKET, 96
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_AuroraTicket::
	checkitem ITEM_AURORA_TICKET, 1
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAuroraTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setitemandprice ITEM_AURORA_TICKET, 96
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_OldMap::
	checkitem ITEM_OLD_SEA_MAP, 1
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmOldMap, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setitemandprice ITEM_OLD_SEA_MAP, 96
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brace::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrace, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setitemandprice ITEM_MACHO_BRACE, 4
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Upgrade::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmUpgrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setitemandprice ITEM_UP_GRADE, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	setitemandprice ITEM_PROTEIN, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	setitemandprice ITEM_CALCIUM, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	setitemandprice ITEM_IRON, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	setitemandprice ITEM_ZINC, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	setitemandprice ITEM_CARBOS, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	setitemandprice ITEM_HP_UP, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	setitemandprice ITEM_LEFTOVERS, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	setitemandprice ITEM_WHITE_HERB, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	setitemandprice ITEM_QUICK_CLAW, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	setitemandprice ITEM_MENTAL_HERB, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	setitemandprice ITEM_BRIGHT_POWDER, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	setitemandprice ITEM_CHOICE_BAND, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	setitemandprice ITEM_KINGS_ROCK, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	setitemandprice ITEM_FOCUS_BAND, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	setitemandprice ITEM_SCOPE_LENS, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_YouAlreadyHaveThis:
	.string "您已经拥有这个道具了。$"

BattleFrontier_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "嗨！您要是想找\n奇迹交换，它现在已经设在了\l每个宝可梦中心。玩得开心！$"
	.string ""
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "您好，这里是兑换服务区。\p我们用精美的奖品同您收集到的\n对战点数进行兑换。\p请在列表中选择一个奖品。$"
	.string ""
	.string ""
	.string ""
	.string ""

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "请选择一个奖品。$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase:
	.string "您选择了{STR_VAR_1}。\n可以吗？$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ConfirmEonTicket:
	.string "您选择了无限船票。\n可以吗？$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMysticTicket:
	.string "您选择了神秘船票。\n可以吗？$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ConfirmAuroraTicket:
	.string "您选择了极光船票。\n可以吗？$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ConfirmOldMap:
	.string "您选择了古航海图。\n可以吗？$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrace:
	.string "您选择了强制锻炼器。\n可以吗？$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ConfirmUpgrade:
	.string "您选择了升级数据。\n可以吗？$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "谢谢！\n我们会把它送到您家的电脑上的。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "这里是您的奖品！$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "很抱歉……\n您没有足够的对战点数……$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "很抱歉……\n您的电脑好像满了……$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "很抱歉……\n您的包包已经放不下了……$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "非常感谢。\p存够了对战点数的话，\n欢迎再来光顾。$"
	.string ""
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "哦，它们真棒！\n我想要它们！\l漂亮的垫子！\l大号豪华的玩偶！\l小号豪华的玩偶！\l我希望能全部得到！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "交给你的妈妈吧！\p无论你想要什么，我都会尽我所能\n为你得到的，我的小宝贝！$"
	.string ""
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "如果我能获得这里的道具，\n我的宝可梦会变得更强。\p你要相信它们肯定会的！\n毫无疑问！$"
	.string ""
	.string ""
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "啊？\n你在看什么呢？\p我不喜欢你那样盯着\n我的漂亮娃娃看。\p如果你想要，自己去弄一只！\n对不对，迷唇娃？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "你知道吗？\p如果你能在任何对战设施\n创造新纪录，他们会开始给你\l越来越多的对战点数。$"
	.string ""
	.string ""
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_TreeckoDollDesc::
	.string "一个木守宫玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_TorchicDollDesc::
	.string "一个火稚鸡玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_MudkipDollDesc::
	.string "一个水跃鱼玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "一个波克比玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "一个喵喵玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "一个皮皮玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "一个百变怪玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "一个火球鼠玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "一个菊草叶玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "一个小锯鳄玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "一个巨大的玩偶。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "提升宝可梦的攻击\n能力。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "提升宝可梦的特攻\n能力。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "提升宝可梦的防御\n能力。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "提升宝可梦的特防\n能力。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "提升宝可梦的速度\n能力。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "提升宝可梦的体力。$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "一件能在对战中逐渐\n回复体力的道具。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "一件能回复所有能力\n的道具。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "一件有概率能先制\n攻击的道具。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "一件能解除宝可梦着迷\n的道具。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "一件能射出眩目的光降低\n命中率的道具。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "提升物理招式的威力，但无法\n使用其他招式。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "一件在接触攻击时能使对手\n畏缩的道具。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "一件能偶尔防止昏厥\n的道具。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "一件能提高击中要害率的\n道具。$"
	.string ""

EventScript_DoWonderTrade::
	goto_if_set FLAG_GARBAGEFLAG, EventScript_DoWonderTradeStartNoLimit
	goto_if_unset FLAG_GARBAGEFLAG, EventScript_FirstTimeWonderRandomizer
	@special CheckIfRandomizerIsActive
	@goto_if_unset FLAG_GARBAGEFLAG, EventScript_DoWonderTradeStart
	@@special CheckIfChallengesAreActive
	goto_if_set FLAG_WONDERTRADE3, EventScript_NoMoreForToday
	goto_if_set FLAG_NO_WT_BECAUSE_CHALLENGE, EventScript_WTChallenges
	goto_if_unset FLAG_WONDERTRADE1, EventScript_DoWonderTradeFirstTrade	
	goto_if_unset FLAG_WONDERTRADE2, EventScript_DoWonderTradeSecondTrade
	goto_if_unset FLAG_WONDERTRADE3, EventScript_DoWonderTradeThirdTrade
	end

EventScript_DoWonderTradeStart:
	goto_if_unset FLAG_BADGE05_GET, EventScript_WTNotActiveYet
	msgbox EventScript_DoWonderTrade_Text_Welcome, MSGBOX_DEFAULT
	closemessage
	@special CheckIfChallengesAreActive
	goto_if_set FLAG_WONDERTRADE3, EventScript_NoMoreForToday
	goto_if_set FLAG_NO_WT_BECAUSE_CHALLENGE, EventScript_WTChallenges
	goto_if_unset FLAG_WONDERTRADE1, EventScript_DoWonderTradeFirstTrade	
	goto_if_unset FLAG_WONDERTRADE2, EventScript_DoWonderTradeSecondTrade
	goto_if_unset FLAG_WONDERTRADE3, EventScript_DoWonderTradeThirdTrade
	end

EventScript_WTChallenges::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_WTChallengesCancel
	goto_if_unset FLAG_WONDERTRADE1, EventScript_DoWonderTradeFirstTrade	
	goto_if_unset FLAG_WONDERTRADE2, EventScript_DoWonderTradeSecondTrade
	goto_if_unset FLAG_WONDERTRADE3, EventScript_DoWonderTradeThirdTrade
	end

EventScript_WTChallengesCancel::
	msgbox EventScript_DoWonderTrade_Text_Challenges, MSGBOX_DEFAULT
	closemessage
	end

EventScript_WTNotActiveYet::
	msgbox EventScript_DoWonderTrade_Text_FiveBadges, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeFirstTrade::
	setflag FLAG_WONDERTRADE1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveFirstTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_DoWonderTradeCancelSaveFirstTrade::
	clearflag FLAG_WONDERTRADE1
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeSecondTrade::
	setflag FLAG_WONDERTRADE2
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveSecondTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_DoWonderTradeCancelSaveSecondTrade::
	clearflag FLAG_WONDERTRADE2
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeThirdTrade::
	setflag FLAG_WONDERTRADE3
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveThirdTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_DoWonderTradeCancelSaveThirdTrade::
	clearflag FLAG_WONDERTRADE3
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeStartNoLimit::
	goto_if_unset FLAG_GARBAGEFLAG, EventScript_FirstTimeWonderUnlimited
	goto_if_unset FLAG_BADGE05_GET, EventScript_WTNotActiveYet
	@special CheckIfChallengesAreActive
	goto_if_set FLAG_NO_WT_BECAUSE_CHALLENGE, EventScript_WTChallengesUnlimited
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveThirdTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_WTChallengesUnlimited::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_WTChallengesCancel
	return

EventScript_DoWonderTradeTrade::
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge EventScript_End
	copyvar VAR_0x8005, VAR_0x8004
	@special CreateWonderTradePokemon
	special DoInGameTradeScene
	waitstate
	@special ForceSaveGame
	waitstate
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_NoMoreForToday::
	msgbox EventScript_NoMoreForToday_Text, MSGBOX_DEFAULT
	closemessage
	end

EventScript_FirstTimeWonderRandomizer::
	msgbox EventScript_FirstTimeWonder_Text, MSGBOX_DEFAULT
	setflag FLAG_GARBAGEFLAG
	closemessage
	end

EventScript_FirstTimeWonderUnlimited::
	msgbox EventScript_FirstTimeWonder_Text_Unlimited, MSGBOX_DEFAULT
	setflag FLAG_GARBAGEFLAG
	closemessage
	end

EventScript_End::
	end

EventScript_DoWonderTrade_Text_Welcome:
	.string "欢迎来到宝可梦中心的\n奇迹交换站！\p请选择要进行\n奇迹交换的宝可梦。$"
	.string ""
	.string ""
	.string ""

EventScript_NoMoreForToday_Text:
	.string "哦！看来今天的3次\n每日交换机会已经用完了。\p明天再来吧！$"
	.string ""
	.string ""

EventScript_FirstTimeWonder_Text:
	.string "你好，训练家！\p哦，这是你第一次\n使用奇迹交换系统吗？\p奇迹交换是得文公司开发的\n匿名交换技术。\p简单来说，就是把选中的宝可梦\n发送给某个人，对方也会\p送你一只作为交换。\n你和对方都不知道\p会出现哪只宝可梦。\n而这正是奇迹交换的\p乐趣！哦对了，为了不让\n服务器超负荷，\p每天最多只能进行3次\n奇迹交换。\p希望你能享受\n奇迹交换的乐趣！$"
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
	.string ""
	.string ""
	.string ""
	.string ""

EventScript_FirstTimeWonder_Text_Unlimited:
	.string "你好，训练家！\p哦，这是你第一次\n使用奇迹交换系统吗？\p奇迹交换是得文公司开发的\n匿名交换技术。\p简单来说，就是把选中的宝可梦\n发送给某个人，对方也会\p送你一只作为交换。\n你和对方都不知道\p会出现哪只宝可梦。\n而这正是\l奇迹交换的乐趣！\p希望你能享受\n奇迹交换的体验！$"
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
	.string ""
	.string ""

EventScript_DoWonderTrade_Text_Done:
	.string "希望你这次\n奇迹交换玩得开心！$"
	.string ""

EventScript_DoWonderTrade_Text_Challenges:
	.string "看来你开启了挑战模式。\n请在打过宝可梦联盟之后\l再来吧。$"
	.string ""
	.string ""

EventScript_DoWonderTrade_Text_FiveBadges:
	.string "很遗憾，奇迹交换系统\n目前还没有开放。\l请过些时候再来吧。$"
	.string ""
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "一幅有迷唇娃\n图案的大海报。$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "一个迷唇娃垫子。\n要放置在地毯或桌子上。$"
	.string ""

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "一个迷唇娃玩偶。\n要放置在地毯或桌子上。$"
	.string ""
