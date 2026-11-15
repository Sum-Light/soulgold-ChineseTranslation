Route2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route2_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route2_EventScript_Rob::
	trainerbattle_single TRAINER_ROB, Route2_Text_BugCatcherRob_Seen, Route2_Text_BugCatcherRob_Beaten
	msgbox Route2_Text_BugCatcherRob_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Ed::
	trainerbattle_single TRAINER_ED, Route2_Text_BugCatcherEd_Seen, Route2_Text_BugCatcherEd_Beaten
	msgbox Route2_Text_BugCatcherEd_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route2_Text_BugCatcherDoug_Seen, Route2_Text_BugCatcherDoug_Beaten
	msgbox Route2_Text_BugCatcherDoug_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_Text_BugCatcherRob_Seen:
	.string "我的虫宝可梦很强。\n做好输的准备吧！$"
	.string ""

Route2_Text_BugCatcherRob_Beaten:
	.string "被打得一败涂地……$"

Route2_Text_BugCatcherRob_AfterBattle:
	.string "我要去找更强的\n虫宝可梦。$"
	.string ""

Route2_Text_BugCatcherEd_Seen:
	.string "穿着短裤走进草丛，\n腿不会被划伤吗？$"
	.string ""

Route2_Text_BugCatcherEd_Beaten:
	.string "哎哟，哎哟，好疼！$"

Route2_Text_BugCatcherEd_AfterBattle:
	.string "泡澡的时候，\n伤口可疼了。$"
	.string ""

Route2_Text_BugCatcherDoug_Seen:
	.string "女孩子为什么不喜欢\n虫宝可梦呢？$"

Route2_Text_BugCatcherDoug_Beaten:
	.string "不行了！$"

Route2_Text_BugCatcherDoug_AfterBattle:
	.string "捏虫宝可梦的肚子，\n会像毛绒玩具一样软。\p那种手感我最喜欢了！$"
	.string ""
	.string ""

Route2_Text_Sign:
	.string "2号道路\p常青市——深灰市$"
	.string ""

Route2_Text_DiglettsCaveSign:
	.string "地鼠洞穴$"

