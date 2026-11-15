MtMortar_1F_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
	.string "这次我可不会输了！$"

MountMortar2_Text_PokemaniacMillerBeaten:
	.string "我竟然输给了\n一个小鬼……？$"

MountMortar2_Text_PokemaniacMillerAfter:
	.string "前阵子，有个练空手道的家伙\n来找我挑战。\p他强得离谱，\n把我们全打趴下了。\p他还说这是为了修行，\n往更深处去了。\p不知道他现在怎么样了？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MountMortar2_Text_SupernerdMarkusSeen:
	.string "喂！孝文！$"

MountMortar2_Text_SupernerdMarkusBeaten:
	.string "我把你错认成\n别人了……$"
	.string ""

MountMortar2_Text_SupernerdMarkusAfter:
	.string "我是来擂钵山探险的，\n可跟我的搭档\l走散了……\p你有没有遇到过一个，\n带着会攀瀑的海刺龙\l的训练家？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
