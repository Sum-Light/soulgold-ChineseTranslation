
GoldenrodCity_BikeShop_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, receivedBikePostDialogue
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "只要把它在包包里登记，\n骑车就简单得只需\l按一下按键。$"
	.string ""
	.string ""

GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "……唉……我搬来这里，\n可自行车就是卖不掉。为什么？\p你能骑着自行车到处跑，\n帮我做做宣传吗？$"
    .string ""
    .string ""
    .string ""

GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "真的吗？太好了！\p把名字和电话号码告诉我，\n我就把自行车借给你。$"
    .string ""
    .string ""

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
    .string "{PLAYER}借用了自行车。$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "总店在关都地区的华蓝市。\p要是你去那边，替我向\n店长问个好！$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_BikeShop_Text_Refused:
    .string "……唉……\n人啊，怎么就不能多点善意呢……$"
    .string ""

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
    .string "新品上市！\p一流的小型自行车！$"
    .string ""

GoldenrodCity_BikeShop_Text_Bicycle:
    .string "是闪闪发亮的自行车！$"

receivedBikePostDialogue::
	goto_if_set FLAG_SYS_GAME_CLEAR, receivedBikePostDialogue_2
	msgbox receivedBikePostDialogue_Text_1
	closemessage
	release
	end

receivedBikePostDialogue_2:
	msgbox receivedBikePostDialogue_Text_0
	closemessage
	release
	end


receivedBikePostDialogue_Text_0:
	.string "喂，小家伙！多亏了你，我的\n生意红火得不得了！\l真是欠你个人情！$"

receivedBikePostDialogue_Text_1:
	.string "希望现在大家能开始\n关注我的自行车了！$"
