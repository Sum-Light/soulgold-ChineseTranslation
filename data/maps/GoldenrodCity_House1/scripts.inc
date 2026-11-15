GoldenrodCity_House1_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "嗨，嗨！我是姓名鉴定师！\n人称名字的占卜师！\p我很乐意为您的宝可梦\n鉴定一下昵称。$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "要鉴定哪只宝可梦的\n昵称呢？$"
	.string ""

GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "嗯……{STR_VAR_1}，是吗？\n这名字取得相当不错。\p不过！我要是给您提个\n更好一点的名字，如何？$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "啊，好的。那么，新的\n昵称要叫什么呢？$"
	.string ""

GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "好了！从今以后，这只宝可梦\n就叫{STR_VAR_1}！\p这名字比原来更好！\n您真是有福气！$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "我明白了。\n欢迎您再来。$"
	.string ""

GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "好了！从今以后，这只宝可梦\n就叫{STR_VAR_1}！\p看起来和以前没什么两样，\n可这名字高明多了！\p您真是有福气！$"
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "嗯……就叫{STR_VAR_1}！\p这是个绝妙的昵称！\n简直无可挑剔！\p从今往后，您可要好好\n珍惜{STR_VAR_1}。$"
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "好了好了。\n那只是一颗蛋！$"
	.string ""


