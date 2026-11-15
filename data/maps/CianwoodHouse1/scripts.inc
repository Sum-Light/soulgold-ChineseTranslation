CianwoodHouse1_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "不记得上回有人来\n看我是多久以前了。\p我年轻时也是\n宝可梦训练家。\l我曾想登上那座塔，\l潜入大海。\p为了各种事情\n都努力过。\p如今我在这片海滩上\n听着波浪和海风，\l悠闲度日。$"
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

CianwoodCity_Text_BellTowerStory:
	.string "你听说过缘朱市的\n铃铛塔吗？\p塔顶上挂着所谓的\n透明铃铛。\p再大的风\n也吹不响它们。\p让它们响起来的\n方法只有一个。\p就是得到另一个透明铃铛，\n和塔顶那些\l一模一样的。\p我年轻时也去找过。\n可始终没能得到……$"
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

CianwoodCity_Text_WhirlIslandsStory:
	.string "你听说过漩涡岛吗？\p那里的瀑布深潭中有\n所谓的海声铃铛。\p再猛的海浪\n也震不响它们。\p让它们响起来的\n方法只有一个。\p就是得到另一个海声铃铛，\n和瀑布深潭里那些\l一模一样的。\p我年轻时也去找过。\n可始终没能得到……$"
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

CianwoodCity_Text_ClearBellReaction:
	.string "哦！你竟然得到了\n透明铃铛？\p我多年的梦想……\n原来如此……\p你做到了……\n……\l……我听到了！\p风声送来的铃声，\n是从铃铛塔那边\l传来的……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodCity_Text_TidalBellReaction:
	.string "哦！你竟然得到了\n海声铃铛？\p我多年的梦想……\n原来如此……\p你做到了……\n……\l……我听到了！\p海风送来的铃声，\n是从漩涡岛那边\l传来的……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
