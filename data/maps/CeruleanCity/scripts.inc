.set LOCALID_CERULEAN_WOMAN, 2
.set LOCALID_CERULEAN_SLOWBRO, 3

CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, CeruleanCity_OnLoad
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_OnLoad::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "这里是无名洞窟。\p里面住着强得可怕的\n宝可梦。\p只有特别受认可的\n训练家才能进去。\p首先，你得有实力成为\n关都宝可梦联盟的\l冠军。\p而且，你还必须\n立下过伟大的功绩。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

CeruleanCity_Text_CooltrainerM1:
	.string "关都的无人发电厂？\p它就在从这里往东的\n9号道路尽头附近。\p我记得那里好像\n出过什么事故。$"
	.string ""
	.string ""
	.string ""
	.string ""

CeruleanCity_Text_CooltrainerM2:
	.string "你在收集所有种类的\n宝可梦吗？\p这肯定相当不容易，\n不过听着也很有趣。$"
	.string ""
	.string ""
	.string ""

CeruleanCity_Text_SuperNerd:
	.string "北边的海角是个\n约会的好地方。\p女孩子都很喜欢那里！$"
	.string ""
	.string ""

CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "呆壳兽：呀哈？$"

CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "我和呆壳兽的组合\n超厉害的！$"
	.string ""

CeruleanCity_Text_CooltrainerF2:
	.string "呆壳兽，使出念力！$"

CeruleanCity_Text_CooltrainerF3:
	.string "…$"

CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "我是华蓝道馆小霞的\n超级粉丝！$"
	.string ""

CeruleanCity_Text_Fisher_RocketTip:
	.string "我看见一个可疑的家伙\n往华蓝海角去了。$"
	.string ""

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "城镇北边的洞窟里，\n住着强得可怕的宝可梦。$"
	.string ""

CeruleanCity_Text_Youngster2:
	.string "嗯？\p我的探宝器有反应了……$"
	.string ""

CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "华蓝市\p笼罩着神秘的蓝色气息$"
	.string ""

CeruleanCity_Text_GymSign:
	.string "华蓝市宝可梦道馆\n馆主：小霞\p俏皮的美人鱼$"
	.string ""
	.string ""
	.string ""

CeruleanCity_Text_BikeShopSign:
	.string "这里贴着一张告示……\p自行车店已经搬到\n城都地区的满金市了……$"
	.string ""
	.string ""

CeruleanCity_Text_PoliceSign:
	.string "这里贴着一张告示……\p杜绝盗窃，打造\n更友善、更欢乐的\l城市！\p华蓝警察$"
	.string ""
	.string ""
	.string ""
	.string ""

CeruleanCity_Text_CapeSign:
	.string "华蓝海角\n前方$"
	.string ""

CeruleanCity_Text_LockedDoor:
	.string "锁着呢……$"

