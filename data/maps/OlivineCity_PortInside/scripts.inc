


OlivineCity_PortInside_Movement_OakFixDex:
	walk_in_place_up
	walk_in_place_up
	step_end

OlivineCity_PortInside_Movement_PlayerMoveOver:
	walk_up
	walk_left
	face_right
	step_end

OlivineCity_PortInside_Movement_OakLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_PortInside_Text_Nationaldex1:
	.string "大木博士：你好！\n你渐渐有了\l冠军的气度，{PLAYER}！\p你的宝可梦图鉴也该\n配得上你现在的身份了。\p让我看看你的图鉴。\p我要用全国模式\n升级你的宝可梦图鉴。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
OlivineCity_PortInside_Text_Nationaldex2:
	.string "{PLAYER}的宝可梦图鉴\n升级成了全国模式！$"
	.string ""
OlivineCity_PortInside_Text_Nationaldex3:
	.string "大木博士：要完成全国图鉴，\n可不是件容易的事……\p不过我相信，你一定会\n替我们认真努力的！$"
	.string ""
	.string ""
	.string ""
OlivineCity_PortInside_Text_Nationaldex4:
	.string "哦，时间过得真快！\p我还要去满金播音塔\n录制节目。\p你接下来是要去七之岛吧。\p听说强大的训练家\n都在那里聚集。真让人兴奋！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OlivinePort_EventScript_CooltrainerF::
	msgbox OlivinePort_Text_CooltrainerF, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher1::
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher2::
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
	end

OlivinePort_EventScript_Youngster::
	msgbox OlivinePort_Text_Youngster, MSGBOX_NPC
	end


OlivinePort_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

OlivinePort_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

OlivinePort_Movement_BoatLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OlivinePort_Text_NoPass:
    .string "{PLAYER}想出示\n{STR_VAR_1}……\p……但是没有{STR_VAR_1}！\p抱歉！\n只有持有{STR_VAR_1}的客人\l才能上船。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

OlivinePort_Text_SailorGetOnBoard:
    .string "船马上要开了。\n请尽快上船。$"
    .string ""

OlivinePort_Text_CantBoard:
    .string "抱歉。您现在不能上船。$"

OlivinePort_Text_WhereSail:
    .string "您想去哪里？$"

OlivinePort_Text_AskBoard:
    .string "欢迎乘坐高速船水流号。\p您今天要上船吗？$"
    .string ""

OlivinePort_Text_AskTicket:
    .string "可以让我看看您的船票吗？$"

OlivinePort_Text_ComeAgain:
    .string "欢迎您随时再来！$"

OlivinePort_Text_FlashTicket:
    .string "{PLAYER}出示了船票。\p好的，谢谢您！$"
    .string ""

OlivinePort_Text_NoTicket:
    .string "{PLAYER}想出示\n船票……\p……可是没有船票！\p抱歉！\n只有持有船票的客人\l才能上船。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

OlivinePort_Text_FishingGuru1:
    .string "在这里很容易钓到好坏星。\p在别的地方，它们算挺稀有的。$"
    .string ""

OlivinePort_Text_FishingGuru2:
    .string "你有几根钓竿？\p不同的钓竿能钓到\n不同的宝可梦。$"
    .string ""
    .string ""

OlivinePort_Text_Youngster:
    .string "水流号靠喷射装置\n在水面上飞驰！$"
    .string ""

OlivinePort_Text_CooltrainerF:
    .string "世界上有很多宝可梦。\p我真希望能出去旅行……$"
    .string ""

OlivinePort_Text_SailorBeforeHOF:
    .string "我们可不想让你掉进海里，\n所以不能放你进去。$"
    .string ""

OlivineCity_PortInside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PortInside_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

OlivineCity_PortInside_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_BADGE08_GET, OlivineCity_PortInside_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
OlivineCity_PortInside_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_HIDE_BLAINE_OLIVINEPORT
	return

OlivineCity_PortInside_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_BLAINE_OLIVINEPORT
	return

OlivineCity_PortInside_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	goto_if_unset FLAG_CANSAIL_FARAWAYISLAND, OlivineCity_PortInside_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto OlivineCity_PortInside_MapScripts_MAP_SCRIPT_ON_TRANSITION_2


OlivinePort_Sailor::
	goto_if_unset FLAG_CANSAIL_FARAWAYISLAND, OlivinePort_Sailor_1
	msgbox OlivinePort_Sailor_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OlivinePort_Sailor_5
	msgbox OlivinePort_Sailor_Text_3
	closemessage
	warp MAP_FARAWAY_ISLAND_OUTSIDE, 13, 38
	waitstate
	release
	end

OlivinePort_Sailor_1:
	msgbox OlivinePort_Sailor_Text_0, MSGBOX_NPC
	return

OlivinePort_Sailor_5:
	msgbox OlivinePort_Sailor_Text_2
	release
	end


OlivinePortBlaine::
	lock
	goto_if_set FLAG_CANSAIL_FARAWAYISLAND, OlivinePortBlaine_2
	goto_if_unset FLAG_TEMP_5, OlivinePortBlaine_5
OlivinePortBlaine_4:
	goto_if_set FLAG_TEMP_5, OlivinePortBlaine_8
OlivinePortBlaine_7:
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox OlivinePortBlaine_Text_9
	msgbox OlivinePortBlaine_Text_10
	trainerbattle_no_intro TRAINER_BLAINE_OLIVINE, OlivinePortBlaine_Text_11
	createfieldmugshot MUGSHOT_BLAINE
	msgbox OlivinePortBlaine_Text_12
	closemessage
	moveobjecttocoords LOCALID_OLI_BLAINE, 8, 16, DIR_SOUTH
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_SOUTH
	delay 60
	moveobjecttocoords LOCALID_OLI_BLAINE, 8, 12, DIR_NORTH
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_OLI_BLAINE, DIR_WEST
	createfieldmugshot MUGSHOT_BLAINE
	msgbox OlivinePortBlaine_Text_13
	closemessage
	applymovement LOCALID_OLI_BLAINE, OlivinePortBlaine_Movement_0
	waitmovement
	playse SE_EXIT
	removeobject LOCALID_OLI_BLAINE
	setflag FLAG_CANSAIL_FARAWAYISLAND
	setflag FLAG_HIDE_BLAINE_OLIVINEPORT
	release
	end

OlivinePortBlaine_2:
	msgbox OlivinePortBlaine_Text_0
	release
	end

OlivinePortBlaine_5:
	msgbox OlivinePortBlaine_Text_1
	faceplayer
	msgbox OlivinePortBlaine_Text_2
	msgbox OlivinePortBlaine_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq OlivinePortBlaine_11
	msgbox OlivinePortBlaine_Text_5, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OlivinePortBlaine_15
	goto OlivinePortBlaine_4

OlivinePortBlaine_8:
	msgbox OlivinePortBlaine_Text_7, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OlivinePortBlaine_13
	goto OlivinePortBlaine_7

OlivinePortBlaine_11:
	msgbox OlivinePortBlaine_Text_4
	release
	end

OlivinePortBlaine_13:
	msgbox OlivinePortBlaine_Text_8
	release
	end

OlivinePortBlaine_15:
	msgbox OlivinePortBlaine_Text_6
	setflag FLAG_TEMP_5
	release
	end


OlivinePortBlaine_Movement_0:
	walk_up
	walk_up
	walk_up
	step_end

OlivinePort_Sailor_Text_0:
	.string "抱歉，这船一时半会儿\n哪儿都不会去。$"

OlivinePort_Sailor_Text_1:
	.string "有人吩咐我把你送到一个\n非常具体的地点。\l你现在就要去吗？$"

OlivinePort_Sailor_Text_2:
	.string "哦，好吧……$"

OlivinePort_Sailor_Text_3:
	.string "那就出发吧！\p起锚！我们要扬帆\n驶向未知的远方！$"

OlivinePortBlaine_Text_0:
	.string "夏伯：我已经把岛的事\n告诉水手了。$"

OlivinePortBlaine_Text_1:
	.string "？？？：啊……还是\n劲爽汽水最痛快！$"

OlivinePortBlaine_Text_2:
	.string "哦！那是城都的8枚徽章吗？\p能集齐这些，你一定是位\n相当了不起的训练家！\p我叫夏伯，是另一个地区的\n道馆馆主。\p夏伯：哦！我有个好主意！\p来答个问题吧！$"

OlivinePortBlaine_Text_3:
	.string "夏伯：你害怕未知吗？$"

OlivinePortBlaine_Text_4:
	.string "哦……答错了！$"

OlivinePortBlaine_Text_5:
	.string "夏伯：很好！\p下一个问题！\p你觉得能在宝可梦对战中\n打赢我吗？$"

OlivinePortBlaine_Text_6:
	.string "夏伯：我欣赏你的诚实，\n不过你该对自己\l多一点信心！$"

OlivinePortBlaine_Text_7:
	.string "关于上一个问题的\n想法改变了吗？\p你觉得能在宝可梦对战中\n打赢我吗？$"

OlivinePortBlaine_Text_8:
	.string "夏伯：还是没什么信心？\n这也难怪。\p毕竟我可是个热情似火的人！\n呵呵呵！$"

OlivinePortBlaine_Text_9:
	.string "夏伯：说得真够大胆！\n我现在就来验证一下！$"

OlivinePortBlaine_Text_10:
	.string "希望你带了灼伤药！$"

OlivinePortBlaine_Text_11:
	.string "哇！你把我烧着了！$"

OlivinePortBlaine_Text_12:
	.string "夏伯：好烫！我被烧到了！\n你果然是真本事！\p事情是这样的。我来城都\n是为了看望老朋友大木，\l他正好也在这里。\p我找到了一张旧地图，\n那是我们很久以前\l去过的一座岛。\p我想那之后\n就再没人去过那儿了。\p我会把这座岛告诉水手。\n你想去的话就去找他。\p说不定能在那里\n找到稀有的宝可梦！$"

OlivinePortBlaine_Text_13:
	.string "祝你好运！$"
