.set LOCALID_SSAQUA_B1F_SAILORLOOKING, 10

SSAqua_B1F_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
    .string "呕！\n真不该看的！$"
    .string ""

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "喂，小家伙。能帮我\n去找找我的伙伴吗？\p他不知跑哪儿偷懒去了，\n那个懒鬼！\p我倒是想去找他，\n可我现在正在值班。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "唉呀……\p船长一定会生气的……$"
	.string ""

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "谢啦，小家伙！我狠狠\n训了他一顿，让他别再偷懒。$"
	.string ""

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "一个小女孩？\p我好像看见她\n从这边过去了。$"
	.string ""

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "前面就是餐厅。\p尽头的楼梯\n通往船长室。$"
	.string ""
	.string ""

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "休息时间来场对战，\n那是再好不过了！$"
	.string ""

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "不管输赢，我的休息时间都结束了！$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "看来不拿出真本事\n就赢不了啊。$"
	.string ""

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "好无聊啊。\n要不要来对战？$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "哇！你太强了！$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "金黄市、玉虹市……听说\n关都有很多大城市。$"
	.string ""

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "呜……我晕船了！$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "我动不了了……$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "我再也不坐船了。\n下次，\p我改坐磁浮列车。$"
	.string ""
	.string ""

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "这里是我们船员工作的地方！$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "我在自己的主场输了……$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "从枯叶市开往\n浅葱市的乘客\p每次都不一样。$"
	.string ""
	.string ""

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "明明都出海了，\n却没法钓鱼！\p太无聊了！来对战吧！$"
	.string ""
	.string ""

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "我……我不无聊了……$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "我打算在枯叶市的\n码头上钓鱼。$"
	.string ""

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "我靠着顶住\n船身的摇晃\p来锻炼下盘！$"
	.string ""
	.string ""

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "被摇得东倒西歪！$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "我在城都没找到\n空手道大王。\p听说他正在某个\n洞窟里修行。$"
	.string ""
	.string ""
	.string ""

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "我可是船员！\p不过我正在训练宝可梦，\n好成为冠军！$"
	.string ""
	.string ""

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "看来我明显是训练不足……$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "八枚徽章！\p这一定是你打败过\n道馆馆主的证明。\p难怪你这么强！$"
	.string ""
	.string ""
	.string ""

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "不许对我的\n学生们动手！$"
	.string ""

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "哇啊！$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "我们这次是去参观\n桔梗市郊外的遗迹。$"
	.string ""

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "你知道阿露福遗迹吗？$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "呜哇！$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "在遗迹里，收音机会\n收到奇怪的电波。$"
	.string ""

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "阿露福遗迹里\n有一些奇怪的石板。$"
	.string ""

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "我完蛋了！$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "我看书上说，那种石板\n一共有四块。$"
	.string ""

