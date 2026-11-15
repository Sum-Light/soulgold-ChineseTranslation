CianwoodPokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkfieldmove MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "要说水属性的宝可梦，\n玛瑙水母绝对第一，\l领先整整一海里！$"
	.string ""
	.string ""

CianwoodPokemoncenter_Text_Fisher2:
	.string "看来你正需要一只\n水属性的宝可梦。\p来，这只给你，\n我还有很多。$"
	.string ""
	.string ""

CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "你见过那位宝可梦狂热迷了吗？\p他总在炫耀自己\n稀有的宝可梦。$"
	.string ""
	.string ""


CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "这里的道馆训练家\n都是粗鲁的莽汉。\p我要是老待在这儿，\n说不定会挨他们揍。\p给你个建议：这里的馆主\n用的是格斗属性。\p所以你应该用超能力宝可梦\n来对付他。\p趁它们还没使出力气，\n先把它们打倒。\p还有道馆正中间的那些巨石呢？\p推移顺序不对的话，\n就到不了馆主那里。\p要是卡住了，就先出去一趟。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodCity_Text_GymGuideWin:
	.string "{PLAYER}！你赢了！\n光看你的样子我就知道了！$"
	.string ""

CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "我最爱炫耀自己\n培养的宝可梦了。\p你不也一样吗？\p我要去到处对战，\n好好炫耀我的宝可梦！$"
	.string ""
	.string ""
	.string ""
	.string ""
