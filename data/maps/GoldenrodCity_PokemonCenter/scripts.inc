.set LOCALID_NURSE, 1

GoldenrodCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid1::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid2::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Granny::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GrannyText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_LassText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_GrannyText:
    .string "我真是太喜欢住在大城市了！\n我搬来这里的时候，还是个\l像你一样的年轻训练家！$"
    .string ""
    .string ""

GoldenrodCity_PokemonCenter_GameboyKidText1:
    .string "这是一家特别的宝可梦中心。\n它的屋顶是金子做的！$"
    .string ""

GoldenrodCity_PokemonCenter_GameboyKidText2:
    .string "我告诉我弟弟，\n这屋顶是纯金做的。\l他什么都信！$"
    .string ""
	.string ""

GoldenrodCity_PokemonCenter_LassText:
    .string "等级高的宝可梦\n也不一定会赢。\p毕竟，它也可能\n属性上吃亏。\p我觉得世上根本没有\n哪只宝可梦是最强的。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText:
    .string "您就是{PLAYER}吧？\p恭喜您！\p作为特别活动，我们为您\n送上了一个GS球！\p请您收下！$"
    .string ""
    .string ""
    .string ""
    .string ""

GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText:
    .string "欢迎您再来！$"

GoldenrodCity_PokemonCenter_PokefanFDoYouHaveEonMailText:
    .string "哎呀，您的包包看着好沉！\p哦！您身上有没有那种\n叫伊布邮件的东西？\p我女儿正想要一个呢。\p您能分我一个吧？$"
    .string ""
    .string ""
    .string ""
    .string ""

GoldenrodCity_PokemonCenter_AskGiveAwayAnEonMailText:
    .string "送出伊布邮件吗？$"

GoldenrodCity_PokemonCenter_PokefanFThisIsForYouText:
    .string "哦，太好了！谢谢您，\n亲爱的！\p来，这个送给您作为回礼！$"
    .string ""
    .string ""

GoldenrodCity_PokemonCenter_PokefanFDaughterWillBeDelightedText:
    .string "我女儿一定会很高兴的！$"

GoldenrodCity_PokemonCenter_PokefanFTooBadText:
    .string "哦？您没有吗？真可惜。$"

GoldenrodCity_PokemonCenter_PokefanFAnotherTimeThenText:
    .string "哦……那，下次再说吧。$"

GoldenrodCity_PokemonCenter_PlayerGaveAwayTheEonMailText:
    .string "{PLAYER}送出了伊布邮件。$"
