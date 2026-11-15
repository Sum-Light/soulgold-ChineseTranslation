GoldenrodCity_RadioTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x4B5, FALSE
	setmetatile 25, 9, 0x4B5, FALSE

	setmetatile 26, 8, 0x4B4, FALSE
	setmetatile 26, 9, 0x4B4, FALSE

	setmetatile 27, 8, 0x4B4, FALSE
	setmetatile 27, 9, 0x4B4, FALSE

	setmetatile 28, 8, 0x4B4, FALSE
	setmetatile 28, 9, 0x4B4, FALSE

	setmetatile 29, 8, 0x4B4, FALSE
	setmetatile 29, 9, 0x4B4, FALSE

	setmetatile 30, 8, 0x4B4, FALSE
	setmetatile 30, 9, 0x4B4, FALSE

	setmetatile 31, 8, 0x4B4, FALSE
	setmetatile 31, 9, 0x4B4, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6 GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7 GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8 GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SKILL_SWAP, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_ROUND
	setflag FLAG_GOT_SKILL_SWAP
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "这里是钥匙卡的插口。$"

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{PLAYER}插入了钥匙卡。$"
 
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "铁门开着。$"

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "3楼　人事部$"

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "宝可梦音乐　主持人：靖史$"

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "我们录下了\n所有已发现的\l宝可梦的叫声。\p我们的收藏\n肯定超过1000种。$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "对训练家来说，宝可梦\n是心爱的伙伴。\p火箭队想要控制宝可梦，\n真是太恶劣了。$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "我们24小时不间断地\n播出有趣的节目。\p我也会全天候\n努力工作！$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "火箭队的老大把自己\n关在了里面。\p不过局长能打开它。\p局长在5楼。\p求求您，救救他！$"
	.string ""
	.string ""
	.string ""
	.string ""

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "局长没事吧？$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "谢谢您！您是我的英雄！\p这是我的一点心意。$"
	.string ""

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "是轮唱。其他宝可梦\n同时使用时，威力会提升。$"
	.string ""

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "您的表现真是太精彩了！$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "我接到了严格的命令。\p凡是敢挑战火箭队的家伙，\n统统击溃！$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "什么？！$"

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "我任务失败了……\p阿波罗会发火的……$"
	.string ""

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "命令宝可梦去干坏事，\n感觉真爽。$"
	.string ""

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "怎么可能！$"

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "输了真窝火！\p可恶！\n我最讨厌没用的宝可梦了！$"
	.string ""

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "卷帘门为什么开了？\n这事跟你有关吗？$"
	.string ""

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "我完了！$"

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "什么？！你居然闯过了\n地下通道的看守？\p怎么可能？$"
	.string ""
	.string ""

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "有个陌生小孩在这儿乱转？\p你是什么人？$"
	.string ""

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "啧！是我太小看你了！$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "哇哈哈哈……\p在这里，我想发多强的信号\n都发得出去。$"
	.string ""
	.string ""

