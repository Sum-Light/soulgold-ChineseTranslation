TinTower_1F_MapScripts::
	.byte 0

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "据传说……\n当宝可梦与人类的灵魂\p彼此相通，一只虹色的宝可梦\n便会从天而降……\p这是不是意味着，传说的宝可梦\n正在考验我们人类？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

TinTower_1F_Sage2_Text:
	.string "金钟塔被烧毁时，\n据说有三只没有名字的宝可梦\l失去了生命。真是悲惨。\p然而……\p一只虹色的宝可梦……\n也就是说……\p凤王从天而降，\n赐予了三只宝可梦新的生命。\p它们就是……\n水君、炎帝和雷公。\p传说就是这么说的。$"
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

TinTower_1F_Sage3_Text:
	.string "据说两座塔是为了\n增进宝可梦与人类之间的\p友谊与希望而建。\n那是700年前的事了，但这份理想\p至今仍然重要。$"
	.string ""
	.string ""
	.string ""
	.string ""

TinTower_1F_Sage4_Text1:
	.string "凤王似乎降临了\n这座铃铛塔！$"
	.string ""

TinTower_1F_Sage4_Text2:
	.string "据说传说的宝可梦\n体现了三种力量……\p击中这座塔的闪电。\n烧毁这座塔的火焰。\p还有扑灭那场火的雨水……$"
	.string ""
	.string ""
	.string ""
	.string ""

TinTower_1F_Sage6_Text2:
	.string "在传说的宝可梦中，据说水君\n与凤王最为亲近。\p我还听说，它和未知图腾\n之间可能也有联系。\p未知图腾一定和水君\n保持着互助的羁绊。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

TinTower_1F_EusineHoOh_Text:
	.string "我就知道。\p我就知道你会见到\n那只虹色的宝可梦，{PLAYER}。\p一切正如我所预想。\n可以说我的研究不赖。\p我要继续研究宝可梦，\n成为有名的宝可梦狂热迷！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

TinTower_1F_EusineSuicune_Text:
	.string "米那君：太棒了！简直太棒了！\n我从没见过那么精彩的对战。\p那真是令人振奋。\n水君很强，\p但你比它还要厉害，{PLAYER}。\n我听说水君的神秘力量\p会召唤来虹色的宝可梦。\n也许，今天发生的事\p真能让那只宝可梦出现。\n我要更深入地研究传说。\p谢谢你让我看到\n那么精彩的对战。\p再见了，{PLAYER}！$"
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
