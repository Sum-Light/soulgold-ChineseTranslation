Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_Text_CamperDeanSeen:
	.string "我是来岩山隧道探险的。$"

Route9_Text_CamperDeanBeaten:
	.string "哇！这可太危险了。$"

Route9_Text_CamperDeanAfter:
	.string "还没进岩山隧道，\n我的宝可梦就受伤了。\p我得马上带它们\n去宝可梦中心。$"
	.string ""
	.string ""
	.string ""

Route9_Text_PicnickerHeidiSeen:
	.string "你野餐过吗？\p野餐可好玩了！$"
	.string ""

Route9_Text_PicnickerHeidiBeaten:
	.string "呜哇——！$"

Route9_Text_PicnickerHeidiAfter:
	.string "我们会烤好多点心，\n分给大家吃。\p可好吃了！$"
	.string ""
	.string ""

Route9_Text_CamperSidSeen:
	.string "喂，你！别乱扔垃圾！$"

Route9_Text_CamperSidBeaten:
	.string "我只是提醒你一下……$"

Route9_Text_CamperSidAfter:
	.string "抱歉。你没乱扔垃圾，\n是我看错了。$"
	.string ""

Route9_Text_PicnickerEdnaSeen:
	.string "垃圾不能随便\n扔在路边。$"
	.string ""

Route9_Text_PicnickerEdnaBeaten:
	.string "唉……我输了……$"

Route9_Text_PicnickerEdnaAfter:
	.string "节约能源很重要，\n不过比起能源，\l环境更加重要。$"
	.string ""
	.string ""

Route9_Text_HikerTimSeen:
	.string "她绕过白银山\n就要来啦……\p白银山是在城都地区吧？$"
	.string ""
	.string ""

Route9_Text_HikerTimBeaten:
	.string "我光顾着唱歌了……$"

Route9_Text_HikerTimAfter:
	.string "对战靠的就是集中力。$"

Route9_Text_HikerSidneySeen:
	.string "我告诉你一个秘密。\p不过，先跟我打一场！$"
	.string ""

Route9_Text_HikerSidneyBeaten:
	.string "哎呀！这局我输了……$"

Route9_Text_HikerSidneyAfter:
	.string "无人发电厂就在\n小河对面。$"
	.string ""

Route9_Text_Sign:
	.string "9号道路\p华蓝市——岩山隧道$"
	.string ""
