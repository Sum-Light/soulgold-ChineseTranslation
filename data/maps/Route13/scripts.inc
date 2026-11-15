Route13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route13_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route13_EventScript_Alex::
	trainerbattle_single TRAINER_ALEX Route13_Text_PokefanmAlexSeen, Route13_Text_PokefanmAlexBeaten
	msgbox Route13_Text_PokefanmAlexAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA Route13_Text_PokefanmJoshuaSeen, Route13_Text_PokefanmJoshuaBeaten
	msgbox Route13_Text_PokefanmJoshuaAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY Route13_Text_BirdKeeperPerrySeen, Route13_Text_BirdKeeperPerryBeaten
	msgbox Route13_Text_BirdKeeperPerryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Bret::
	trainerbattle_single TRAINER_BRET Route13_Text_BirdKeeperBretSeen, Route13_Text_BirdKeeperBretBeaten
	msgbox Route13_Text_BirdKeeperBretAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Kenny::
	trainerbattle_single TRAINER_KENNY Route13_Text_HikerKennySeen, Route13_Text_HikerKennyBeaten
	msgbox Route13_Text_HikerKennyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_TrainerTips::
	msgbox Route13_Text_TrainerTips, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_Sign, MSGBOX_SIGN
	end

Route13_EventScript_DirectionsSign::
	msgbox Route13_Text_DirectionsSign, MSGBOX_SIGN
	end

Route13_Text_PokefanmAlexSeen:
	.string "在我高贵的宝可梦面前\n跪下吧！$"

Route13_Text_PokefanmAlexBeaten:
	.string "你……\n竟敢冒犯王室！$"

Route13_Text_PokefanmAlexAfterBattle:
	.string "谁不想有朝一日\n当上国王呢？$"
	.string ""

Route13_Text_PokefanmJoshuaSeen:
	.string "嘻嘻嘻！想不想和我的\n皮卡丘军团打一场？$"
	.string ""

Route13_Text_PokefanmJoshuaBeaten:
	.string "皮、皮卡丘！$"

Route13_Text_PokefanmJoshuaAfterBattle:
	.string "你好像有很多宝可梦，\p不过最棒的\n还是皮卡丘。$"
	.string ""
	.string ""

Route13_Text_BirdKeeperPerrySeen:
	.string "敏捷是鸟宝可梦\n最重要的特质。$"
	.string ""

Route13_Text_BirdKeeperPerryBeaten:
	.string "你竟然靠速度\n赢了我……$"

Route13_Text_BirdKeeperPerryAfterBattle:
	.string "你的宝可梦\n训练得真好。$"
	.string ""

Route13_Text_BirdKeeperBretSeen:
	.string "看看我的宝可梦！\n瞧瞧它们的毛色与羽毛。$"
	.string ""
	.string ""

Route13_Text_BirdKeeperBretBeaten:
	.string "可恶！\n还差得远呢！$"

Route13_Text_BirdKeeperBretAfterBattle:
	.string "多给宝可梦梳理毛发，\n它们就会很高兴。$"
	.string ""

Route13_Text_HikerKennySeen:
	.string "我该去岩山隧道\n抓只大岩蛇。$"
	.string ""

Route13_Text_HikerKennyBeaten:
	.string "我输了……$"

Route13_Text_HikerKennyAfterBattle:
	.string "地形看上去\n好像从来不变。\p但其实它正一点一点地\n发生变化。$"
	.string ""
	.string ""
	.string ""

Route13_Text_TrainerTips:
	.string "训练家提示\p看！就在那里，\n柱子的左边。$"
	.string ""
	.string ""

Route13_Text_Sign:
	.string "13号道路\p北　寂静桥$"
	.string ""

Route13_Text_DirectionsSign:
	.string "北　紫苑镇\p西　浅红市$"
	.string ""

