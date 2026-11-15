ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ViridianCity_OnLoad
	.byte 0

ViridianCity_OnLoad::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisherNew, MSGBOX_NPC
	setflag FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "喂，小家伙！我刚喝了两杯\n浓缩咖啡，现在精神得不得了！\p总得找个人说说话，\n那就你来听我说吧！\p别看我现在这副样子，\n以前可是捉宝可梦的高手。\p你信吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

ViridianCity_Text_CoffeeGramps_Believed:
	.string "好，好。没错，我年轻时可是个\n不一般的人物，\l我跟你说！$"
	.string ""
	.string ""

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "什么？你这小兔崽子！\p我要是再年轻几岁，\n就让你见识见识。哼！$"
	.string ""
	.string ""

ViridianCity_Text_GrampsNearGym:
	.string "这个道馆直到最近才有了馆主。\p真新镇的一个年轻人当了馆主，\n不过他经常不在。$"
	.string ""
	.string ""
	.string ""

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "你要去挑战馆主吗？\p祝你好运。你会用得着的。$"
	.string ""
	.string ""

ViridianCity_Text_DreamEaterFisherNew:
	.string "……呼噜噜……\p呼啊！\p我肯定是在太阳底下\n打个盹就睡着了。\p什么？我让你想起某个人？\p我不知道，这个给你吧。$" 
	.string ""
	.string ""
	.string ""
	.string ""


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "……呼噜噜……$"

ViridianCity_Text_DreamEaterFisher:
	.string "呼啊！\p我肯定是在太阳底下\n打个盹就睡着了。\p……我梦见催眠貘\n吃了我的梦。很奇怪吧？\p咦？这是什么？\p这个招式学习器是从哪来的？\p真有点邪门！来，\n这个招式学习器就给你了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "招式学习器42里装的是食梦……\p……呼噜噜……$"
	.string ""

ViridianCity_Text_Youngster:
	.string "我听说常青森林的地上\n有很多道具。$"
	.string ""

ViridianCity_Text_Sign:
	.string "常青市\p永恒的绿色乐园$"
	.string ""

ViridianCity_Text_GymSign:
	.string "常青市宝可梦道馆\n馆主：……\p后面的文字已经看不清了……$"
	.string ""
	.string ""

ViridianCity_Text_WelcomeSign:
	.string "欢迎来到常青市，\p通往石英高原的门户$"
	.string ""

ViridianCity_Text_TrainerHouseSign:
	.string "训练家之屋\p顶尖训练家对战俱乐部$"
	.string ""
