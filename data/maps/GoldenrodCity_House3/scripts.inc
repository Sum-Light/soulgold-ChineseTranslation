GoldenrodCity_House3_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
    .string "我老是打输，宝可梦也\n总是濒死……\p也许就是因为这样，\n宝可梦才不太亲近我……$"
    .string ""
    .string ""
    .string ""

GoldenrodHappinessRater_Text_Twin:
    .string "我给宝可梦用道具时，\n它会显得特别高兴！$"
    .string ""
