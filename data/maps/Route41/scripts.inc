
Route41_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "这里的海水很暖和，\n我身子都活动开了。\p好啊，我接受挑战！$"
	.string ""
	.string ""

Route41_Text_SwimmermCharlieBeaten:
	.string "哎呀！我皮肤都泡皱了！$"

Route41_Text_SwimmermCharlieAfter:
	.string "就这样漂着，\n是不是很舒服？$"
	.string ""

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "我有点累了。\n我要是赢了，把宝可梦借我。$"
	.string ""

Route41_Text_SwimmermGeorgeBeaten:
	.string "呼，呼……$"

Route41_Text_SwimmermGeorgeAfter:
	.string "去湛蓝市好远啊。\p可是回浅葱市的路\n也不好走。\p我该怎么办呢？$"
	.string ""
	.string ""
	.string ""

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "你看到那些被漩涡\n围住的小岛了吗？\p那里肯定藏着秘密！$"
	.string ""
	.string ""

Route41_Text_SwimmermBerkeBeaten:
	.string "你强大的秘诀\n是什么？$"
	.string ""

Route41_Text_SwimmermBerkeAfter:
	.string "那是一个暴风雨的夜晚……\p我看见一只巨大的宝可梦\n从岛上飞起。\p它银色的翅膀\n撒落着羽毛。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "这里的海浪很凶。\p游泳的时候\n会把你累坏的。$"
	.string ""
	.string ""

Route41_Text_SwimmermKirkBeaten:
	.string "我累垮了！$"

Route41_Text_SwimmermKirkAfter:
	.string "海流太急，我一直\n游不到那座岛。$"
	.string ""

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "你也是在探寻漩涡岛\n的秘密吗？$"
	.string ""

Route41_Text_SwimmermMathewBeaten:
	.string "哦哦，你的体力真不错！$"

Route41_Text_SwimmermMathewAfter:
	.string "漩涡岛的秘密啊……\p里面一片漆黑！$"
	.string ""

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "我正要去漩涡岛。\p我和朋友约好一起去探险。$"
	.string ""

Route41_Text_SwimmerfKayleeBeaten:
	.string "原来是这么打的啊。$"

Route41_Text_SwimmerfKayleeAfter:
	.string "听说漩涡岛的深处\n有一只巨大的宝可梦。\p会是什么样的宝可梦呢？$"
	.string ""
	.string ""

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "你骑着宝可梦的样子\n真优雅。$"
	.string ""

Route41_Text_SwimmerfSusieBeaten:
	.string "我受打击了……$"

Route41_Text_SwimmerfSusieAfter:
	.string "不是有首流行歌，唱的是\n骑拉普拉斯的少年吗？$"
	.string ""

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "天气太好了，\n我都看得入神了！$"
	.string ""

Route41_Text_SwimmerfDeniseBeaten:
	.string "哦哦！$"

Route41_Text_SwimmerfDeniseAfter:
	.string "晒伤对皮肤最不好了。\p可是我不涂防晒霜。\p我不想污染海水。$"
	.string ""
	.string ""

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "需要休息的话，\n踩水就行了。\p喘过气来，\n就能继续有力地游下去。$"
	.string ""
	.string ""
	.string ""

Route41_Text_SwimmerfKaraBeaten:
	.string "哦！你比我还有精神。$"

Route41_Text_SwimmerfKaraAfter:
	.string "我听见岛的最深处\n传来吼声。$"
	.string ""

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "一到晚上，海星星就会\n聚集到海面附近。$"
	.string ""

Route41_Text_SwimmerfWendyBeaten:
	.string "哎呀呀……$"

Route41_Text_SwimmerfWendyAfter:
	.string "成群的海星星会同时\n发出光芒。\p美得让人害怕。$"
	.string ""
	.string ""

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_GARBAGEFLAG
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_GARBAGEFLAG
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_SYS_NO_CATCHING
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_SYS_NO_CATCHING
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_SYS_NO_CATCHING
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "毒刺水母：咕噜噜……$"

Route41_Text_TentacruelAttack:
	.string "毒刺水母：咕噜噜噜噜！$"

Route41_Text_TentacruelHeal:
	.string "毒刺水母使用了自我再生！\n它的体力完全恢复了！$"
	.string ""

GuardingDewgong::
	lock
	faceplayer
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox GuardingDewgong_Text_0
	waitmoncry
	checkitem ITEM_SILVER_WING
	compare VAR_RESULT, TRUE
	goto_if_eq GuardingDewgong_2
GuardingDewgong_1:
	release
	end

GuardingDewgong_2:
	checkitem ITEM_TIDAL_BELL
	compare VAR_RESULT, FALSE
	goto_if_eq GuardingDewgong_4
	goto GuardingDewgong_1

GuardingDewgong_4:
	msgbox GuardingDewgong_Text_1
	goto GuardingDewgong_1


GuardingDewgong_Text_0:
	.string "白海狮：咕咕！$"

GuardingDewgong_Text_1:
	.string "你回想起了播音塔\n局长说过的话……\p“就算去了我说的那个地方，\n传说的宝可梦也不会出现。\p看来还需要别的东西……”\p也许你该晚些再来这里。$"
