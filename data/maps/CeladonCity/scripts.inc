.set LOCALID_CELADON_ERIKA, 15

CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, CeladonCity_OnLoad
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_OnLoad::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
    .string "哦，{PLAYER}。\n今天的喷泉真美，对吧？\p还想再对战的话，\n就到格斗道场来吧。$"
	.string ""
	.string ""
	.string ""

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_Text_Fisher:
	.string "这只蚊香泳士是我的搭档。\p不知道它会不会进化成\n青蛙宝可梦。$"
	.string ""
	.string ""

CeladonCity_Text_Poliwrath:
	.string "蚊香泳士：呱呱！$"

CeladonCity_Text_Teacher1:
	.string "我又在老虎机那里输光了……\p现在我们女孩子也玩老虎机了。\p你也去看看吧。$"
	.string ""
	.string ""

CeladonCity_Text_Gramps1:
	.string "最近臭泥经常出现。\p看到屋子前面那个池塘了吗？\n现在臭泥就住在那里。\p它们是从哪儿来的？\n这真是个大问题……$"
	.string ""
	.string ""
	.string ""
	.string ""

CeladonCity_Text_Gramps2:
	.string "嘿嘿嘿！这座道馆真好！\n这里只许女孩子进！$"
	.string ""

CeladonCity_Text_Youngster1:
	.string "想知道一个秘密吗？\p玉虹大厦有一扇隐蔽的\n后门哦。$"
	.string ""
	.string ""

CeladonCity_Text_Youngster2:
	.string "餐厅正在举办大胃王比赛。\p光是看着他们狼吞虎咽，\n我就觉得肚子胀……$"
	.string ""
	.string ""
	.string ""

CeladonCity_Text_Teacher2:
	.string "玉虹百货公司的商品\n最齐全，品质也最好。\p要是那里都买不到，\n别处就更买不到了。\p唉……我听着像个售货员。$"
	.string ""
	.string ""
	.string ""
	.string ""

CeladonCity_Text_Lass:
	.string "走路的时候一直盯着地面，\n看得我头都晕了。$"
	.string ""

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "玉虹市\p彩虹之梦的城市$"
	.string ""

CeladonGym_Text_Sign:
	.string "玉虹市宝可梦道馆\n馆主：莉佳\p热爱自然的大小姐$"
	.string ""
	.string ""

CeladonCity_Text_DeptStoreSign:
	.string "在玉虹百货公司\n定能找到心仪的商品！$"
	.string ""

CeladonCity_Text_MansionSign:
	.string "玉虹大厦$"

CeladonCity_Text_GameCornerSign:
	.string "大家的游乐场——\n玉虹游戏城$"
	.string ""

CeladonCity_Text_TrainerTips:
	.string "训练家提示\p能力防守能保护宝可梦，\n不受火、水等特殊攻击的伤害。\p买道具，就到\n玉虹百货公司！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
