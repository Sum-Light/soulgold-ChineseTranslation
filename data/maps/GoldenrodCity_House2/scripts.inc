GoldenrodCity_House2_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "有一次对战时，我的宝可梦\n一招也使不出来。\p因为它所有招式的\n招式点数，也就是PP，都用光了。$"
    .string ""
    .string ""
    .string ""

GoldenrodPPSpeechHouse_Text_Lass:
    .string "有时候，明明很健康的宝可梦\n也会使不出招式。\p遇到这种情况，就去宝可梦中心\n治疗，或者用道具吧。$"
    .string ""
    .string ""
    .string ""
