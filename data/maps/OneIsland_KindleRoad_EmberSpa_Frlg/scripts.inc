OneIsland_KindleRoad_EmberSpa_Frlg_MapScripts::
	.byte 0

OneIsland_KindleRoad_EmberSpa_EventScript_OldMan::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan1::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan2::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_OldWoman::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BlackBelt::
	lock
	faceplayer
	msgbox OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_RockSmashMan::
	lock
	faceplayer
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_SpaHeal::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed
	setvar VAR_TEMP_1, 1
	releaseall
	end

OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore::
	.string "嗯！\n哈哈！\p真是天堂般的感受！\n这些温暖的水涌入我的心！\p你也应该跳进来的。\p到中间去，放松，\n去体会温暖和美好！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder::
	.string "马上要进行的是\n沐浴中我最喜欢的一个环节。\p我也喜欢吃下一碗大杂烩，\n享受从身体内部涌出温暖的感觉。$"
	.string ""
	.string ""
	.string ""

OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed::
	.string "水非常温暖。\n有一种绝妙的感觉……\p{PLAYER}的宝可梦完全恢复精神了！$"
	.string ""
	.string ""
	.string ""

OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic::
	.string "据说，\n泡温泉有益于身体健康。$"
	.string ""

OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs::
	.string "看看我的脸。\n我的皮肤是不是很光滑？\p泡温泉使我看起来更年轻。$"
	.string ""
	.string ""
	.string ""

OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion::
	.string "在经过一天辛苦的训练之后，\n没有比泡温泉更让人惬意的事了。\p我的一个前辈叫做希巴。\n有时会他会和他的宝可梦\p一起来到这个温泉，\n在这里做水疗。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa::
	.string "温泉是伴随着火山而产生的。\p几年前，\n我在这里建造了灯火温泉。\p我从一堆巨大的岩石中，\n亲手开辟出了这个池子。\p那时我使用了这招，\n我想我是时候该放开它了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06::
	.string "就像它们是用饼干做的一样，\n我用这招砸碎了巨石。$"
	.string ""

