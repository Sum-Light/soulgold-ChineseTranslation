RintoVillage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_RINTO_VILLAGE
	goto_if_set FLAG_IS_CHAMPION, RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setvar VAR_POSTGAME_UNLOCKS_STATE, 1
	goto RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION_1


Rinto_Sign::
	msgbox Rinto_Sign_Text_0, MSGBOX_SIGN
	return


Rinto_OldLady::
	msgbox Rinto_OldLady_Text_0, MSGBOX_NPC
	return


Rinto_TempleSage::
	msgbox Rinto_TempleSage_Text_0, MSGBOX_NPC
	return


Rinto_Gible::
	lock
	faceplayer
	playmoncry SPECIES_GIBLE, CRY_MODE_NORMAL
	msgbox Rinto_Gible_Text_0
	waitmoncry
	release
	end


Rinto_Maractus::
	lock
	faceplayer
	playmoncry SPECIES_MARACTUS, CRY_MODE_NORMAL
	msgbox Rinto_Maractus_Text_0
	waitmoncry
	release
	end


Rinto_Piplup::
	lock
	msgbox Rinto_Piplup_Text_0
	release
	end


Rinto_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_REST, Rinto_Gentleman_2
	msgbox Rinto_Gentleman_Text_1
	giveitem ITEM_TM_REST
	setflag FLAG_GOT_TM_REST
	msgbox Rinto_Gentleman_Text_0
	release
	end

Rinto_Gentleman_2:
	msgbox Rinto_Gentleman_Text_0
	release
	end


Rinto_EastGuard::
	msgbox Rinto_EastGuard_Text_0, MSGBOX_NPC
	return


Rinto_TriggerEastGuard::
	lock
	applymovement LOCALID_RINTO_EAST_GUARD, Rinto_TriggerEastGuard_Movement_0
	waitmovement
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_1
	waitmovement
	msgbox Rinto_EastGuard_Text_0
	closemessage
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_2
	waitmovement
	release
	end


Rinto_LittleGirl::
	msgbox Rinto_LittleGirl_Text_0, MSGBOX_NPC
	return


Rinto_Fatman::
	msgbox Rinto_Fatman_Text_0, MSGBOX_NPC
	return


Rinto_Dancer::
	lock
	msgbox Rinto_Dancer_Text_0
	release
	end


Rinto_DancerOricorio::
	lock
	playmoncry SPECIES_ORICORIO_SENSU, CRY_MODE_NORMAL
	msgbox Rinto_DancerOricorio_Text_0
	waitmoncry
	release
	end


Rinto_Merchant::
	lock
	faceplayer
	msgbox Rinto_Merchant_Text_0
	pokemart Rinto_Stall
	msgbox Rinto_Merchant_Text_1
	release
	end


	.align 2
Rinto_Stall:
	.2byte ITEM_RING_TARGET
	.2byte ITEM_BINDING_BAND
	.2byte ITEM_EJECT_BUTTON
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_WISE_GLASSES
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_NONE

Rinto_GameboyKid::
	msgbox Rinto_GameboyKid_Text_0, MSGBOX_NPC
	return


Rinto_TriggerEastGuard_Movement_0:
	walk_in_place_down
	step_end

Rinto_TriggerEastGuard_Movement_1:
	face_up
	step_end

Rinto_TriggerEastGuard_Movement_2:
	walk_left
	step_end

Rinto_Sign_Text_0:
	.string "林都村\n阳光沐浴的村庄$"

Rinto_OldLady_Text_0:
	.string "哎呀，又来了游客吗？\p希望您不介意\n气温变化这么大！呵呵呵！$"

Rinto_TempleSage_Text_0:
	.string "我以前是熔岩队的一员。\p离开以后，我决定\n以朝圣者的身份周游世界。\p能见识世界的美好，\n真是让人神清气爽。$"

Rinto_Gible_Text_0:
	.string "圆陆鲨：嘎嘎！$"

Rinto_Maractus_Text_0:
	.string "沙铃仙人掌：沙啊啊伊！$"

Rinto_Piplup_Text_0:
	.string "……波加曼好像睡着了。$"

Rinto_Gentleman_Text_0:
	.string "“睡觉”能让您恢复体力，\n继续上路。\p别硬撑，\n记得抽空好好休养。$"

Rinto_Gentleman_Text_1:
	.string "远行之后好好休息，\n同样重要！年轻也别\l不顾身体！\p这个给您。$"

Rinto_EastGuard_Text_0:
	.string "现在沙暴太猛了。\n在它平息之前，\l我不能放您过去。$"

Rinto_LittleGirl_Text_0:
	.string "我看见了！\p红的和蓝的！\p它们往东边飞过镇子了！$"

Rinto_Fatman_Text_0:
	.string "要不是有那一小处\n通向大海的缺口，\l这烈日早把这里烤得没法住人了。$"

Rinto_Dancer_Text_0:
	.string "上吧，花舞鸟！露一手给他们看！$"

Rinto_DancerOricorio_Text_0:
	.string "哩咿咿！$"

Rinto_Merchant_Text_0:
	.string "嘿，来看看我的货吧！$"

Rinto_Merchant_Text_1:
	.string "欢迎您再来！$"

Rinto_GameboyKid_Text_0:
	.string "西边那座金字塔\n已经锁了很久了。\p我怀疑打开它的钥匙\n现在还存在吗？$"
