Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "我们是关都宝可梦联合\n训练家团体。\p我们要用车轮\n把你碾平！$"
	.string ""
	.string ""

Route8_Text_BikerDwayneBeaten:
	.string "对、对不起！$"

Route8_Text_BikerDwayneAfter:
	.string "关都宝可梦联合\n永不倒下！$"
	.string ""

Route8_Text_BikerHarrisSeen:
	.string "警察把我们的\n地下通道封了！\p真是气死我了！$"
	.string ""
	.string ""

Route8_Text_BikerHarrisBeaten:
	.string "饶、饶了我吧！$"

Route8_Text_BikerHarrisAfter:
	.string "居然栽在城都来的\n小鬼手里……$"
	.string ""

Route8_Text_BikerZekeSeen:
	.string "我们是关都宝可梦联合！\n没错，就是这样！$"
	.string ""
	.string ""

Route8_Text_BikerZekeBeaten:
	.string "哎呀！对不起！$"

Route8_Text_BikerZekeAfter:
	.string "今后我们会尽量\n不打扰别人……$"
	.string ""

Route8_Text_SupernerdSamSeen:
	.string "磁浮列车是怎么跑起来的？$"

Route8_Text_SupernerdSamBeaten:
	.string "我只是想看看\n磁浮列车……$"
	.string ""

Route8_Text_SupernerdSamAfter:
	.string "磁铁的力量太厉害了！$"

Route8_Text_SupernerdTomSeen:
	.string "嗯……你的道馆徽章真不少。$"

Route8_Text_SupernerdTomBeaten:
	.string "果然不出我所料……你很强！$"

Route8_Text_SupernerdTomAfter:
	.string "道馆徽章能让你在对战中\n占优势。$"
	.string ""

Route8_Text_LockedDoor:
	.string "上锁了……$"

Route8_Text_UndergroundPathSign:
	.string "传单被撕破了。\p已经没法读了……$"
	.string ""
