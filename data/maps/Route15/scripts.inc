Route15_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_Text_TeacherColetteSeen:
	.string "没忘带什么东西吧？$"

Route15_Text_TeacherColetteBeaten:
	.string "呀啊啊！$"

Route15_Text_TeacherColetteAfterBattle:
	.string "我当老师以前，\n也经常忘东西。$"
	.string ""

Route15_Text_TeacherHillarySeen:
	.string "天气好的时候，我觉得孩子们\n更想在校园里玩，而不是上课。$"
	.string ""
	.string ""

Route15_Text_TeacherHillaryBeaten:
	.string "我本不想输的……$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "学习固然重要，\n但运动同样必不可少。$"
	.string ""

Route15_Text_SchoolboyKippSeen:
	.string "等一下。\n我得给妈妈打个电话。$"

Route15_Text_SchoolboyKippBeaten:
	.string "对不起，妈妈！\n我输了！$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "妈妈太担心我了，\n我得经常给她打电话。$"
	.string ""

Route15_Text_SchoolboyTommySeen:
	.string "来对战吧。\n我可不会输！$"

Route15_Text_SchoolboyTommyBeaten:
	.string "我忘了写作业！$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "撒由那拉！这是我\n在日语课刚学的词。$"
	.string ""

Route15_Text_SchoolboyJohnnySeen:
	.string "为了社会课，我们正要去\n紫苑播音塔参观。$"
	.string ""

Route15_Text_SchoolboyJohnnyBeaten:
	.string "你强得离谱！$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "走累了。\n我得歇一会儿。$"
	.string ""

Route15_Text_SchoolboyBillySeen:
	.string "我最喜欢的课是体育课！$"

Route15_Text_SchoolboyBillyBeaten:
	.string "糟了！\n我怎么会输呢？$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "要是学校有宝可梦课，\n我肯定是第一名！$"
	.string ""

Route15_Text_Sign:
	.string "15号道路\p浅红市——紫苑镇$"
	.string ""

