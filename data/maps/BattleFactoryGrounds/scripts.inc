BattleFactoryGrounds_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFactoryGrounds_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

BattleFactoryGrounds_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto setFactoryFlightFlag
	return


setFactoryFlightFlag::
	setflag FLAG_VISITED_BATTLE_FACTORY
	end


FactoryGrounds_CooltrainerF::
	msgbox FactoryGrounds_CooltrainerF_Text_0, MSGBOX_NPC
	return


FactoryGrounds_Fisher::
	lock
	msgbox FactoryGrounds_Fisher_Text_0
	release
	end


FactoryGrounds_Boy::
	lock
	faceplayer
	msgbox FactoryGrounds_Boy_Text_0
	applymovement LOCALID_FACTORY_ESPURR, FactoryGrounds_Boy_Movement_0
	waitmovement
	applymovement LOCALID_FACTORY_KID, FactoryGrounds_Boy_Movement_1
	waitmovement
	msgbox FactoryGrounds_Boy_Text_1
	delay 30
	msgbox FactoryGrounds_Boy_Text_1
	faceplayer
	msgbox FactoryGrounds_Boy_Text_2
	release
	end


FactoryGrounds_Espurr::
	lock
	faceplayer
	playmoncry SPECIES_ESPURR, CRY_MODE_NORMAL
	msgbox FactoryGrounds_Espurr_Text_0
	waitmoncry
	release
	end


FactoryGrounds_OldLady::
	msgbox FactoryGrounds_OldLady_Text_0, MSGBOX_NPC
	return


FactoryGrounds_Boy_Movement_0:
	face_right
	step_end

FactoryGrounds_Boy_Movement_1:
	face_left
	step_end

FactoryGrounds_CooltrainerF_Text_0:
	.string "对战工厂的对战可是很艰难的！\p不能用自己的宝可梦，\n所以必须随机应变。$"

FactoryGrounds_Fisher_Text_0:
	.string "唔，这个池塘里没有鲤鱼王，\n只有麻麻小鱼和灯笼鱼……$"

FactoryGrounds_Boy_Text_0:
	.string "我和妙喵不用开口\n就能交流！看好了！$"

FactoryGrounds_Boy_Text_1:
	.string "...$"

FactoryGrounds_Boy_Text_2:
	.string "很厉害吧？$"

FactoryGrounds_Espurr_Text_0:
	.string "妙喵：嘶——！$"

FactoryGrounds_OldLady_Text_0:
	.string "我不太喜欢这些新式建筑\n盖得离我们心爱的\l缘朱市这么近。$"
