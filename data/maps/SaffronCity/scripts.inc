SaffronCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, SaffronCity_OnLoad
	.byte 0

SaffronCity_OnFrame::
	map_script_2 VAR_SAFFRON_CITY_STATE, 0,  SaffronCity_EventScript_BaobaCall
	.2byte 0

SaffronCity_OnLoad::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_EventScript_BaobaCall::
	pokenavcall SaffronCity_Text_Baoba
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	setvar VAR_SAFFRON_CITY_STATE, 1
	end

SaffronCity_Text_Baoba:
	.string "园长巴奥巴：{PLAYER}！\p我是园长巴奥巴。\p打电话是想告诉你，\n狩猎地带又扩建了！\p我的狩猎地带终于\n大功告成了！\p你还记得在哪儿吧？\p就在湛蓝市西边！\n回头见！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "我最喜欢六尾了！$"

SaffronCity_Text_Lass1:
	.string "这里住着一个小女孩，\n最会模仿别人。\p连跟她说话的人\n她都要模仿。真让人糊涂。$"
	.string ""
	.string ""
	.string ""

SaffronCity_Text_Lass1_ReturnedPart:
	.string "模仿少女好像心事重重。\p她说她最喜欢的皮皮玩偶\n弄丢了。$"
	.string ""
	.string ""

SaffronCity_Text_PokefanM:
	.string "你是从城都来的？\p要是磁浮列车通车了，\n你眨眼的工夫就能回家。$"
	.string ""
	.string ""

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "你是从城都来的？\p坐上磁浮列车，\n一眨眼就能回家了。$"
	.string ""
	.string ""

SaffronCity_Text_CooltrainerM:
	.string "我兴冲冲地去了道馆，\n准备跟训练家们对战……\p结果一头走进了隔壁\n那个废弃不用的道馆。\p唉，可把我羞死了。$"
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_Text_CooltrainerF:
	.string "这里是以宝可梦商品闻名的\n西尔佛公司。\p正因为如此，火箭队\n以前才盯上了这家公司。$"
	.string ""
	.string ""
	.string ""

SaffronCity_Text_Fisher:
	.string "嚼……嚼……\p听说无人发电厂\n要出大乱子了。\p嚼……嚼……$"
	.string ""
	.string ""
	.string ""

SaffronCity_Text_Fisher_ReturnedPart:
	.string "嚼……嚼……\p听说无人发电厂\n出过大乱子。\p嚼……嚼……哈啊，吃饱了！$"
	.string ""
	.string ""
	.string ""

SaffronCity_Text_Youngster1:
	.string "第一次走进小巷，\n总觉得有点不安。$"
	.string ""

SaffronCity_Text_Youngster2:
	.string "常青市有个地方叫\n训练家之屋。\p各地的训练家都会\n聚到那里去。$"
	.string ""
	.string ""

SaffronCity_Text_Lass2:
	.string "我们的城市上过广播节目。\p听到别人夸自己的城市\n当然高兴，\l不过也有点不好意思。$"
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_Text_Sign:
	.string "金黄市\p闪耀的黄金商业之都$"
	.string ""

SaffronCity_Text_GymSign:
	.string "金黄市\n宝可梦道馆\l馆主：娜姿\p超能力宝可梦的大师！$"
	.string ""
	.string ""
	.string ""

SaffronCity_Text_FightingDojoSign:
	.string "欢迎所有人！\n格斗道场$"
	.string ""

SaffronCity_Text_SilphCoSign:
	.string "西尔佛公司\n办公大楼$"
	.string ""

SaffronCity_Text_MrPsychicHouseSign:
	.string "超能力大叔的家$"
	.string ""

SaffronCity_Text_MagnetTrainStationSign:
	.string "金黄市\n磁浮列车车站$"
	.string ""
