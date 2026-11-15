Route26_House1_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	lock
	faceplayer
	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
	release
	end


Route26_Text_HealHouseRest:
    .string "你的宝可梦看起来有点累了。\p让它们好好休息一下吧。$"
    .string ""

Route26_Text_HealHouseKeepAtIt:
    .string "好了！\p宝可梦看起来精神多了！\p继续保持哦！$"
    .string ""
    .string ""
