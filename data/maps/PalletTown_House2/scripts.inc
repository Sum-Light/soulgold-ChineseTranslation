PalletTown_House2_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_GARBAGEFLAG, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_GARBAGEFLAG
	release
	end

PalletTown_House2_Text_Hello:
	.string "奈奈美：嗨！我弟弟是常青市\n的道馆馆主。\p可他老是出远门，\n给训练家们\l添了不少麻烦。$"
	.string ""
	.string ""
	.string ""
	.string ""

PalletTown_House2_Text_OfferGrooming:
	.string "奈奈美：嗨！来得正好。\n我正要泡茶呢。\p要不要一起来喝一杯？\p哎呀，你的宝可梦有点脏了。\p要我帮其中一只梳理一下吗？$"
	.string ""
	.string ""
	.string ""
	.string ""

PalletTown_House2_Text_WhichMon:
	.string "奈奈美：要梳理哪一只？$"

PalletTown_House2_Text_Alright:
	.string "奈奈美：好，我马上就把它\n打理得漂漂亮亮。$"
	.string ""

PalletTown_House2_Text_AllDone:
	.string "奈奈美：好了！全弄完了。\p看，{STR_VAR_1}是不是\n变得很漂亮？\p真是只可爱的宝可梦。$"
	.string ""
	.string ""
	.string ""

PalletTown_House2_Text_AlreadyGroomed:
	.string "奈奈美：我每天这个时候都会\n喝茶。来陪我喝一杯吧。$"
	.string ""

PalletTown_House2_Text_Refused:
	.string "奈奈美：不想梳理吗？\p那我们就喝茶吧。$"
	.string ""
	.string ""

PalletTown_House2_Text_CantGroomEgg:
	.string "奈奈美：哎呀，抱歉。\n蛋我可实在没法梳理。$"
	.string ""
