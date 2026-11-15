Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_Text_SwimmermHaroldSeen:
	.string "你夜里在海里游过泳吗？$"
	.string ""

Route19_Text_SwimmermHaroldBeaten:
	.string "咕噜……$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "一到夜里，大海就一片漆黑。\n感觉像要把你吞进去一样。$"
	.string ""

Route19_Text_SwimmermTuckerSeen:
	.string "呼，呼……\n就差……一点点……\p再往前……到……\n浅红市……$"
	.string ""

Route19_Text_SwimmermTuckerBeaten:
	.string "我要淹死了！$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "我……是请女朋友游到\n浅红市的……呼……$"
	.string ""

Route19_Text_SwimmerfDawnSeen:
	.string "我最讨厌没骨气的人！$"

Route19_Text_SwimmerfDawnBeaten:
	.string "游泳的话，我不会输……$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "从浅红市到双子岛，\n游过去很快的……\p唉，我的男朋友算什么\n大男人啊！真是个窝囊废！$"
	.string ""
	.string ""
	.string ""

Route19_Text_SwimmermJeromeSeen:
	.string "游泳？我可不行。\p我只在这片浅水里\n扑腾扑腾。$"
	.string ""
	.string ""

Route19_Text_SwimmermJeromeBeaten:
	.string "我还以为能赢呢。$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "我游泳虽然不行，\n但我喜欢大海。$"
	.string ""

Route19_Text_Fisher1:
	.string "抱歉。这条路正在施工，\n不能通行。\p要去红莲镇的话，\n还是从真新镇往南走吧。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route19_Text_Kingler:
	.string "巨钳蟹：嘎——！$"

Route19_Text_Fisher1_RocksCleared:
	.string "我出了一身汗。\n去游个泳吧！$"

Route19_Text_Fisher2:
	.string "哎呀，巨钳蟹把海滩\n给挡住了。$"
	.string ""

Route19_Text_FisherBefore:
	.string "这些巨钳蟹不走，\n就钓不了鱼。$"
	.string ""

Route19_Text_Fisher2_RocksCleared:
	.string "那些巨钳蟹总算走了！\p这下又能钓鱼了。$"
	.string ""

Route19_Text_Sign:
	.string "19号水路\p浅红市——双子岛$"
	.string ""

Route19_Text_CarefulSwimmingSign:
	.string "游往双子岛的人，\n请务必小心。\p浅红市警察$"
	.string ""
	.string ""

