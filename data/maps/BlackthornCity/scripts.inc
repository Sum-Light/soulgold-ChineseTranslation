.set LOCALID_BLACKTHORN_BOY, 2

BlackthornCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BlackthornCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BlackthornCity_OnLoad::
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_MoveGymBoy
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	end

BlackThornCity_EventScript_MoveGymBoy::
	setobjectxyperm LOCALID_BLACKTHORN_BOY, 24, 27
	end

BlackthornCity_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 4, BlackthornCity_EventScript_Call
	.2byte 0

BlackthornCity_EventScript_CityEnter:: 
	setflag FLAG_VISITED_BLACKTHORN_CITY
	callnative SetTimeBasedEncounters
	end

BlackthornCity_EventScript_Call::
	lock
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_BLACKTHORN_CITY_STATE, 5
	setvar VAR_NEWBARKTOWN_LABSTATE, 7
	release
	end

BlackthornCity_Text_BaobaCall:
	.string "园长巴奥巴：{PLAYER}！\p我是园长巴奥巴。\p打电话是想告诉您，\n狩猎地带扩建了！\p欢迎您来玩！$"
	.string ""
	.string ""
	.string ""
	.string ""

BlackthornCity_Text_ElmCall:
	.string "空木博士：喂，是{PLAYER}吗？\p我这儿有东西要给你。\n能来一趟我的研究所吗？\p回头见！$"
	.string ""
	.string ""
	.string ""

BlackThornCity_EventScript_Sage::
	lock
	faceplayer
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_SageRefuse
	msgbox BlackthornGrampsGrantsEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_SageRefuse::
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_Trigger_Sage::
	lock
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_EAST
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_SOUTH
	release
	end

BlackthornCity_EventScript_GymBoy::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_GymBoyBefore
	msgbox BlackthornCity_Text_ClairIsBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackThornCity_EventScript_GymBoyNotReady::
	msgbox BlackthornCity_Text_ClairNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyBefore::
	msgbox BlackthornCity_Text_ClairIsIn, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackthornCity_EventScript_BlackBelt::
	msgbox BlackBeltText_VoicesInMyHead, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF::
	msgbox BlackthornCooltrainerF1Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornYoungsterText, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF2::
	msgbox BlackthornCooltrainerF2Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCitySignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornGymSignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_Text_DragonDenSign, MSGBOX_SIGN
	end

Blackthorn_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end


BlackthornCity_EventScript_Santos::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SPELL_TAG, BlackthornCity_EventScript_SantosCompleted
	msgbox BlackthornCity_MeetSantosText, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, BlackthornCity_EventScript_SantosNope
	case 1, BlackthornCity_EventScript_SantosNope
	case 2, BlackthornCity_EventScript_SantosNope
	case 3, BlackthornCity_EventScript_SantosNope
	case 4, BlackthornCity_EventScript_SantosNope
	case 5, BlackthornCity_EventScript_SantosNope
	case 6, BlackthornCity_EventScript_SantosYes
	case 7 BlackthornCity_EventScript_SantosCancel
	case MULTI_B_PRESSED, BlackthornCity_EventScript_SantosCancel
	closemessage
	release
	end
BlackthornCity_EventScript_SantosYes::
	msgbox BlackthornCity_SantosGivesGiftText, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SPELL_TAG
	msgbox BlackthornCity_SantosGaveGiftText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosNope::
	msgbox BlackthornCity_SantosNopeText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCancel::
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCompleted::
	msgbox BlackthornCity_SantosSaturdayText, MSGBOX_DEFAULT
	closemessage
	release
	end


BlackthornCity_Text_ClairNotReady:
	.string "本市的道馆馆主小椿\n一直在关注你的成长。\p不过，她只和已经拿到\n7枚徽章的训练家对战。$"
	.string ""
	.string ""
	.string ""

BlackthornCity_Text_ClairIsIn:
	.string "本市的道馆馆主小椿\n正在等着你。\p不过，一般的训练家\n是不可能赢过她的。$"
	.string ""
	.string ""
	.string ""

BlackthornCity_Text_ClairIsBeaten:
	.string "你打赢了小椿？\p太厉害了！\p除了阿渡大人以外，我还没\n听说她输给过任何人。$"
	.string ""
	.string ""
	.string ""

BlackthornGrampsRefusesEntryText:
	.string "不行。只有被选中的训练家\n才能在这里修行。\p请回吧。$"
	.string ""
	.string ""

BlackthornGrampsGrantsEntryText:
	.string "既然小椿答应，她的爷爷——\n也就是我们的长老——也会答应。\p你可以进去了。$"
	.string ""
	.string ""

BlackBeltText_VoicesInMyHead:
	.string "嗷呜！我脑袋里有声音！\p嗯？我在听收音机呀！$"
	.string ""

BlackthornCooltrainerF1Text:
	.string "你是要让宝可梦\n回忆起招式吗？$"
	.string ""

BlackthornYoungsterText:
	.string "驯龙师全是从烟墨市\n走出去的。$"
	.string ""

BlackthornCity_MeetSantosText:
	.string "星琪柳：……\p我是星期兄弟里的星琪柳。\p猜猜看吧。$"
	.string ""
	.string ""

BlackthornCity_SantosGivesGiftText:
	.string "这个给你……$"

BlackthornCity_SantosGaveGiftText:
	.string "星琪柳：……\p咒术之符……\p幽灵属性的招式会变强……\p会吓你一跳的……$"
	.string ""
	.string ""
	.string ""

BlackthornCity_SantosSaturdayText:
	.string "星琪柳：……\p下个星期六再见吧……\p礼物已经没有了……$"
	.string ""
	.string ""

BlackthornCity_SantosNopeText:
	.string "星琪柳：不行。$"

BlackthornCooltrainerF2Text:
	.string "哇，你是穿过冰雪小径\n过来的？\p你一定是个很厉害的\n训练家！$"
	.string ""

BlackthornCitySignText:
	.string "烟墨市\p幽静的山间小镇$"
	.string ""

BlackthornGymSignText:
	.string "烟墨市宝可梦道馆\n馆主：小椿\p神圣的驯龙师$"
	.string ""
	.string ""

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "招式兄弟之家$"

BlackthornCity_Text_DragonDenSign:
	.string "前方　龙穴$"
