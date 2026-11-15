PalletTown_Lab_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_PALLETTOWN_LABSTATE, 2
	release
	end

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "宝可梦图鉴收集得怎么样了？$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "大木博士：啊，{PLAYER}！\n你大老远跑到关都来，\l真是有心了。\p你觉得这边的训练家\n怎么样？很强吧？$"
	.string ""
	.string ""
	.string ""
	.string ""

PalletTown_Lab_Text_OakLabGoodbye:
	.string "要是你到附近来，希望\n你再来坐坐。$"
	.string ""

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "大木博士：哦！太出色了！\p你收集齐了关都各道馆的\n徽章。干得好！\p我看人的眼光果然没错。\p这样吧，{PLAYER}。我来\n安排一下，让你能上\l白银山。\p白银山是一座大山，\n栖息着许多野生宝可梦。\p对普通训练家来说太危险，\n所以是禁止进入的。不过\l对你，{PLAYER}，\l我们可以破个例。\p你去石英高原吧。从那里\n就能上白银山了。$"
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

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "大木博士：嗯？你还没在收集\n关都的道馆徽章吗？\p关都的道馆馆主，和你在\n城都交手过的一样强。\p我建议你去挑战他们。$"
	.string ""
	.string ""
	.string ""
	.string ""

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "大木博士：啊，你在收集关都\n的道馆徽章啊。\p我想这不容易，但这些\n经验一定会帮到你。\p等你全部集齐了，\n就来找我吧。\p我会送你一份礼物。\p继续加油，{PLAYER}！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

PalletTown_Lab_Text_OaksAssistant1:
	.string "博士的“宝可梦讲座”\n在关都这边收不到。\p真遗憾——我很想听呢。$"
	.string ""
	.string ""

PalletTown_Lab_Text_OaksAssistant2:
	.string "多亏了你帮忙收集图鉴，\n博士的研究\l进展得很顺利。$"
	.string ""
	.string ""

PalletTown_Lab_Text_OaksAssistant3:
	.string "别跟别人说，大木博士的\n“宝可梦讲座”不是直播。$"
	.string ""

PalletTown_Lab_Text_OaksLabPC:
	.string "电脑上有一封电子邮件。\p……\p大木博士，您的研究\n进展还顺利吗？\p我还在埋头苦干呢。\p听说{PLAYER}已经\n闯出不小的名头了。\p听到这个我很高兴。\p若叶镇　空木　8-)$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
