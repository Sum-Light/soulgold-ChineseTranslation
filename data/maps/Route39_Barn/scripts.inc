Route39_Barn_MapScripts::
	.byte 0

Route39_Barn_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	goto_if_eq VAR_ROUTE39_BARN, 0, Route39_Barn_EventScript_Miltank_NeedBerries5
	goto_if_eq VAR_ROUTE39_BARN, 1, Route39_Barn_EventScript_Miltank_NeedBerries4
	goto_if_eq VAR_ROUTE39_BARN, 2, Route39_Barn_EventScript_Miltank_NeedBerries3
	goto_if_eq VAR_ROUTE39_BARN, 3, Route39_Barn_EventScript_Miltank_NeedBerries2
	goto_if_eq VAR_ROUTE39_BARN, 4, Route39_Barn_EventScript_Miltank_NeedBerries1
	msgbox Route39_Text_MoomooHappyMoo, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Barn_EventScript_Miltank_NeedBerries5::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused

	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnLittleHealthier, MSGBOX_DEFAULT
	closemessage

	setvar VAR_ROUTE39_BARN, 1
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries4::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused

	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnLittleHealthier, MSGBOX_DEFAULT
	closemessage

	setvar VAR_ROUTE39_BARN, 2
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries3::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnQuiteHealthy, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE39_BARN, 3
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries2::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnQuiteHealthy, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE39_BARN, 4
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries1::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnTotallyHealthy, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE 
	waitfanfare
	giveitem(ITEM_SCOPE_LENS)
	closemessage
	setvar VAR_ROUTE39_BARN, 5
	special Achievement_CheckAll
	release
	end

Route39_Barn_EventScript_Miltank_Refused::
	msgbox Route39_Text_BarnRefusedBerry, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Barn_EventScript_Miltank_NoBerries::
	msgbox Route39_Text_BarnNoBerries, MSGBOX_DEFAULT
	release
	end

Route39_Barn_EventScript_Twins::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39_Barn_EventScript_TwinsAfter
	msgbox Route39_Text_BarnTwinMoomooIsSick, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Barn_EventScript_TwinsAfter::
	msgbox Route39_Text_BarnTwinFeedingMoomoo
	closemessage
	release
	end

Route39_Text_BarnTwinMoomooIsSick:
	.string "哞哞生病了……\p它需要很多橙橙果。$"
	.string ""

Route39_Text_BarnTwinFeedingMoomoo:
	.string "哞哞全好了！\n谢谢你！$"
	.string ""

Route39_Text_MoomooWeakMoo:
	.string "大奶罐：……哞……$"

Route39_Text_BarnCryIsWeak:
	.string "叫声有气无力……\n要给大奶罐橙橙果吗？$"
	.string ""

Route39_Text_MoomooHappyMoo:
	.string "大奶罐：哞哞！$"

Route39_Text_BarnGaveBerry:
	.string "{PLAYER}把橙橙果给了\n大奶罐。$"
	.string ""

Route39_Text_BarnLittleHealthier:
	.string "大奶罐稍微\n恢复精神了！$"
	.string ""

Route39_Text_BarnQuiteHealthy:
	.string "大奶罐\n精神多了！$"
	.string ""

Route39_Text_BarnTotallyHealthy:
	.string "大奶罐完全\n恢复健康了！$"
	.string ""

Route39_Text_BarnNoBerries:
	.string "{PLAYER}没有橙橙果……$"

Route39_Text_BarnRefusedBerry:
	.string "{PLAYER}不愿给出\n橙橙果。\p大奶罐一脸难过。$"
	.string ""
	.string ""
