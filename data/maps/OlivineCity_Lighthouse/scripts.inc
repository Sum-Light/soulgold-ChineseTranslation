.set LOCALID_LIGHTHOUSE_JASMINE, 12
.set LOCALID_LIGHTHOUSE_AMPHAROS, 13

OlivineCity_Lighthouse_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "很多人在这座浅葱灯塔里修行。\p里面等着挑战的训练家很多，\n想爬到上面可不容易。$"
	.string ""
	.string ""

OlivineLighthouse_Text_1FPokefanF:
	.string "从前，宝可梦会在夜里\n照亮浅葱一带的海面。\p这座灯塔就是为了纪念\n那些高贵的宝可梦而建的。$"
	.string ""
	.string ""
	.string ""

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "大海的男儿，\n随时都想痛痛快快打一场！$"
	.string ""

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "呜啊！\n我输了！$"
	.string ""

OlivineLighthouse_Text_SailorHueyAfter:
	.string "好厉害的力量！要不要\n跟我一起出海远航？$"
	.string ""

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "嗯？这里可不是\n玩耍的地方。$"
	.string ""

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "啊！看得出来，\n你是认真的。$"
	.string ""

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "塔顶有一只宝可梦，\n一直照亮着灯塔。\p但我听说它现在病了，\n普通的办法治不好。$"
	.string ""
	.string ""
	.string ""

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "你跑来干什么？就为了\n看热闹？我劝你快走！$"
	.string ""

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "你还真是关心\n那只生病的宝可梦啊……$"
	.string ""

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "到底要怎么上去啊？\p我想去看看那只生病的宝可梦，\n可就是上不去……$"
	.string ""
	.string ""

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "水手既温柔又强壮。\n你怎么样？$"
	.string ""

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "你既温柔又强壮……$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "每次回浅葱市，\n我都会去道馆看看。\p不知不觉间，馆主用的\n宝可梦属性已经变了。$"
	.string ""
	.string ""
	.string ""

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "我环游世界，锻炼\n自己的宝可梦。我想和你一战。$"
	.string ""

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "……唉……我还得再修行啊……$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "阿蜜以前用的是大岩蛇\n那样的岩石属性宝可梦。$"
	.string ""

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "阿蜜一定担心那只宝可梦\n担心得不得了。\p这些天她连笑都不笑了。$"
	.string ""
	.string ""

OlivineLighthouse_Text_SailorKentBeaten:
	.string "我也笑不出来……$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "说到生病，我听说湛蓝市\n有一家很不错的药店。$"
	.string ""

OlivineLighthouse_Text_LassConnieSeen:
	.string "阿蜜是这个城市的道馆馆主。\p我一定要把她带回去。\p谁也别想拦我！$"
	.string ""
	.string ""

OlivineLighthouse_Text_LassConnieBeaten:
	.string "啊啊！我的宝可梦！$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "是啊。自己的宝可梦受了伤，\n谁都会担心的。\p我会为这里的宝可梦祈祷，\n让阿蜜能回道馆来。$"
	.string ""
	.string ""
	.string ""

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "我本来想和阿蜜对战，\n可她现在的状态不行。\p那就找你吧，怎么样？$"
	.string ""
	.string ""

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "哇，哇。你太强了！$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "道馆馆主不只是要强。\p馆主还得有一颗\n体谅他人的心。$"
	.string ""
	.string ""
	.string ""

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "这里离地面很高，\n我的鸟宝可梦状态正佳。$"
	.string ""

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "哎呀……它们摔下来了……$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "我的宝可梦在湛蓝市\n学会了飞翔。\p既然我输了，就让我用飞翔\n飞过大海吧……$"
	.string ""
	.string ""
	.string ""

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "阿蜜：……这孩子一直\n在夜里照亮海面。\p……可它突然病了……\n现在呼吸都很困难……\p……我听说湛蓝市\n有一家很棒的药店……\p可那在大海对岸……\n我又不能丢下光儿不管……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "……能不能请你替我\n去买些药回来？求你了。$"
	.string ""

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "湛蓝市有一家很棒的药店……\p可那在大海对岸……\n我又不能丢下光儿不管……\p……能不能请你替我\n去买些药回来？求你了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "阿蜜：……那个药\n能治好光儿吗？$"
	.string ""


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playse MUS_HEAL
	waitse
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER}把秘传之药\n交给了阿蜜。$"
	.string ""

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "阿蜜：……那个，请你\n不要介意……\p……除了我，光儿不会\n接受任何人给的东西……$"
	.string ""
	.string ""
	.string ""

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "阿蜜：……\p光儿，你感觉怎么样？$"
	.string ""

OlivineLighthouse_Text_JasmineThankYou:
	.string "阿蜜：……啊，太好了……\p真是太让人高兴了……\p真的、真的非常感谢你。\p……我这就回道馆去……\p另外提醒你一句，\n钢属性的宝可梦很强。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OlivineLighthouse_Text_JasmineISee:
	.string "阿蜜：……我明白了……\n……光儿，撑住！$"
	.string ""

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "光儿：……\n……噼……噼露……$"
	.string ""

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "它的呼吸\n非常艰难……$"
	.string ""

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "光儿：噼露！噼露啾！$"


