
NewBarkTown_House3_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_House3_OnTransition
	.byte 0

NewBarkTown_House3_OnTransition::
    call Common_EventScript_SetupRivalGfxId
    end

NewBarkTown_RivalsMom::
	lock
	faceplayer
	checkplayergender
	msgbox NewBarkTown_RivalsMom_Text_0
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_RivalsMom_2
	compare VAR_RIVAL_STATE, 4
	goto_if_ge NewBarkTown_RivalsMom_12
NewBarkTown_RivalsMom_10:
	msgbox NewBarkTown_RivalsMom_Text_4
NewBarkTown_RivalsMom_1:
	release
	end

NewBarkTown_RivalsMom_2:
	compare VAR_RIVAL_STATE, 4
	goto_if_ge NewBarkTown_RivalsMom_7
NewBarkTown_RivalsMom_5:
	msgbox NewBarkTown_RivalsMom_Text_2
	goto NewBarkTown_RivalsMom_1

NewBarkTown_RivalsMom_6:
	msgbox NewBarkTown_RivalsMom_Text_1
	release
	end

NewBarkTown_RivalsMom_7:
	compare VAR_RIVAL_STATE, 12
	goto_if_lt NewBarkTown_RivalsMom_6
	goto NewBarkTown_RivalsMom_5

NewBarkTown_RivalsMom_11:
	msgbox NewBarkTown_RivalsMom_Text_3
	release
	end

NewBarkTown_RivalsMom_12:
	compare VAR_RIVAL_STATE, 12
	goto_if_lt NewBarkTown_RivalsMom_11
	goto NewBarkTown_RivalsMom_10


NewBarkTown_RivalsSister::
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_RivalsSister_2
	msgbox NewBarkTown_RivalsSister_Text_1
NewBarkTown_RivalsSister_1:
	release
	end

NewBarkTown_RivalsSister_2:
	msgbox NewBarkTown_RivalsSister_Text_0
	goto NewBarkTown_RivalsSister_1


NewBarkTownRivalHouseRival::
	lock
	faceplayer
	createfieldmugshotrival
	compare VAR_RIVAL_STATE, 12
	goto_if_lt NewBarkTownRivalHouseRival_2
	compare VAR_RIVAL_STATE, 12
	goto_if_ge NewBarkTownRivalHouseRival_5
NewBarkTownRivalHouseRival_4:
	release
	end

NewBarkTownRivalHouseRival_2:
	msgbox NewBarkTownRivalHouseRival_Text_0, MSGBOX_NPC
	release
	end

NewBarkTownRivalHouseRival_5:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 7
	goto_if_ge NewBarkTownRivalHouseRival_9
NewBarkTownRivalHouseRival_7:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 5
	goto_if_ge NewBarkTownRivalHouseRival_14
NewBarkTownRivalHouseRival_12:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 0
	goto_if_eq NewBarkTownRivalHouseRival_20
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 1
	goto_if_eq NewBarkTownRivalHouseRival_27
NewBarkTownRivalHouseRival_26:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
	goto_if_eq NewBarkTownRivalHouseRival_30
NewBarkTownRivalHouseRival_29:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 3
	goto_if_eq NewBarkTownRivalHouseRival_33
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 4
	goto_if_eq NewBarkTownRivalHouseRival_36
NewBarkTownRivalHouseRival_35:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 5
	goto_if_eq NewBarkTownRivalHouseRival_39
NewBarkTownRivalHouseRival_38:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 6
	goto_if_eq NewBarkTownRivalHouseRival_42
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 7
	goto_if_eq NewBarkTownRivalHouseRival_45
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 8
	goto_if_eq NewBarkTownRivalHouseRival_45
NewBarkTownRivalHouseRival_44:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 7
	goto_if_eq NewBarkTownRivalHouseRival_53
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 8
	goto_if_eq NewBarkTownRivalHouseRival_53
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 9
	goto_if_eq NewBarkTownRivalHouseRival_65
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 10
	goto_if_eq NewBarkTownRivalHouseRival_67
	goto NewBarkTownRivalHouseRival_4

NewBarkTownRivalHouseRival_8:
	checkitem ITEM_HM_DIVE
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_17
	goto NewBarkTownRivalHouseRival_7

NewBarkTownRivalHouseRival_9:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 10
	goto_if_le NewBarkTownRivalHouseRival_8
	goto NewBarkTownRivalHouseRival_7

NewBarkTownRivalHouseRival_13:
	getcaughtmon SPECIES_DARKRAI
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_22
	goto NewBarkTownRivalHouseRival_12

NewBarkTownRivalHouseRival_14:
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 10
	goto_if_le NewBarkTownRivalHouseRival_13
	goto NewBarkTownRivalHouseRival_12

NewBarkTownRivalHouseRival_17:
	msgbox NewBarkTownRivalHouseRival_Text_1
	giveitem ITEM_HM_DIVE
	createfieldmugshotrival
	checkitem ITEM_HM_DIVE
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_24
	goto NewBarkTownRivalHouseRival_7

NewBarkTownRivalHouseRival_20:
	msgbox NewBarkTownRivalHouseRival_Text_3
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 1
	release
	end

NewBarkTownRivalHouseRival_22:
	msgbox NewBarkTownRivalHouseRival_Text_2
	release
	end

NewBarkTownRivalHouseRival_24:
	release
	end

NewBarkTownRivalHouseRival_27:
	msgbox NewBarkTownRivalHouseRival_Text_4
	goto NewBarkTownRivalHouseRival_26

NewBarkTownRivalHouseRival_30:
	msgbox NewBarkTownRivalHouseRival_Text_5
	goto NewBarkTownRivalHouseRival_29

NewBarkTownRivalHouseRival_33:
	msgbox NewBarkTownRivalHouseRival_Text_6
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 4
	release
	end

NewBarkTownRivalHouseRival_36:
	msgbox NewBarkTownRivalHouseRival_Text_7
	goto NewBarkTownRivalHouseRival_35

NewBarkTownRivalHouseRival_39:
	msgbox NewBarkTownRivalHouseRival_Text_8
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 6
	goto NewBarkTownRivalHouseRival_38

NewBarkTownRivalHouseRival_42:
	msgbox NewBarkTownRivalHouseRival_Text_9
	checkitem ITEM_HM_DIVE
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_50
NewBarkTownRivalHouseRival_49:
	checkitem ITEM_HM_DIVE
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_62
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 7
	createfieldmugshotrival
	msgbox NewBarkTownRivalHouseRival_Text_10
	release
	end

NewBarkTownRivalHouseRival_45:
	goto_if_set FLAG_ONETIME_GROUDON, NewBarkTownRivalHouseRival_58
	goto NewBarkTownRivalHouseRival_44

NewBarkTownRivalHouseRival_50:
	giveitem ITEM_HM_DIVE
	goto NewBarkTownRivalHouseRival_49

NewBarkTownRivalHouseRival_53:
	msgbox NewBarkTownRivalHouseRival_Text_11
	release
	end

NewBarkTownRivalHouseRival_57:
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 9
	goto NewBarkTownRivalHouseRival_44

NewBarkTownRivalHouseRival_58:
	goto_if_set FLAG_ONETIME_KYOGRE, NewBarkTownRivalHouseRival_57
	goto NewBarkTownRivalHouseRival_44

NewBarkTownRivalHouseRival_62:
	release
	end

NewBarkTownRivalHouseRival_65:
	msgbox NewBarkTownRivalHouseRival_Text_12
	giveitem ITEM_OVAL_CHARM
	createfieldmugshotrival
	msgbox NewBarkTownRivalHouseRival_Text_13
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 10
	release
	end

NewBarkTownRivalHouseRival_67:
	msgbox NewBarkTownRivalHouseRival_Text_14
	goto NewBarkTownRivalHouseRival_4


NewBarkTownRivalHouseMarill::
	lock
	faceplayer
	playmoncry SPECIES_MARILL, CRY_MODE_NORMAL
	msgbox NewBarkTownRivalHouseMarill_Text_0
	waitmoncry
	release
	end


NewBarkTownRivalHouseAzumarill::
	lock
	faceplayer
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox NewBarkTownRivalHouseAzumarill_Text_0
	waitmoncry
	release
	end


NewBarkTown_RivalsMom_Text_0:
	.string "哦，你好，{PLAYER}！$"

NewBarkTown_RivalsMom_Text_1:
	.string "如果是来找克丽丝的话，\n她现在出门了。$"

NewBarkTown_RivalsMom_Text_2:
	.string "如果是来找克丽丝的话，她现在\n在楼上。她正在和她的宝可梦\l一起玩。$"

NewBarkTown_RivalsMom_Text_3:
	.string "如果是来找阿响的话，\n他现在出门了。$"

NewBarkTown_RivalsMom_Text_4:
	.string "如果是来找阿响的话，他现在\n在楼上。他正在和他的宝可梦\l一起玩。$"

NewBarkTown_RivalsSister_Text_0:
	.string "空木博士送了我姐姐一只玛力露，\n希望我也能快点拥有一只\l可以一起玩的宝可梦！$"

NewBarkTown_RivalsSister_Text_1:
	.string "空木博士送了我哥哥一只玛力露，\n希望我也能快点拥有一只\l可以一起玩的宝可梦！$"

NewBarkTownRivalHouseRival_Text_0:
	.string "嘿，{PLAYER}！你去过\n什么新地方吗？$"

NewBarkTownRivalHouseRival_Text_1:
	.string "你要探索城都地区的\n水下区域，就得靠这个！$"

NewBarkTownRivalHouseRival_Text_2:
	.string "我们还得调查达克莱伊。\p带着克雷色利亚去吉花市的\n那家老旅馆！$"

NewBarkTownRivalHouseRival_Text_3:
	.string "嘿，{PLAYER}！怎么了？\p我最近想了很多，决定\n要帮空木博士研究传说的宝可梦！\p我开始调查城都地区流传的\n古老传闻和故事，已经找到了\l第一个线索。\p如果你有空、又正好在附近，\n能不能帮我一起去查一查？\p我眼下正在调查的第一只传说\n宝可梦，其实牵涉到两只！\p你听说过达克莱伊和克雷色利亚吗？\p一只带来噩梦，另一只则能治愈\n噩梦，真是奇妙！\p我觉得应该先找到克雷色利亚，\n这样才能找到达克莱伊。\p我听说愤怒之湖附近或湖里\n有人可能知道得更多。$"

NewBarkTownRivalHouseRival_Text_4:
	.string "我听说愤怒之湖附近或湖里\n有人可能知道得更多。$"

NewBarkTownRivalHouseRival_Text_5:
	.string "哦，你找到克雷色利亚的\n位置了？\p太好了！要是能捉的话，\n你就捉住它吧！$"

NewBarkTownRivalHouseRival_Text_6:
	.string "你捉住克雷色利亚了？\n干得好！\p这期间我一直在调查\n达克莱伊。\p我很确定它和吉花市那家\n破旧的老旅馆有关。\p那家旅馆因为有个孩子睡着后\n一直没醒而关了门，对旅馆来说\l名声糟透了。\p所以简单说，带上克雷色利亚，\n去吉花市的老旅馆查一查吧。\l看看你能不能查出点什么！$"

NewBarkTownRivalHouseRival_Text_7:
	.string "去吉花市的老旅馆查一查吧。\n记得带上克雷色利亚！$"

NewBarkTownRivalHouseRival_Text_8:
	.string "你捉住达克莱伊了！太好了！\p不过你看起来好像刚做过噩梦，\n发生什么事了吗？\p总之！$"

NewBarkTownRivalHouseRival_Text_9:
	.string "{PLAYER}！我又找到了一条\n关于传说宝可梦的线索！\p据说丰缘地区的那一对，\n正沉睡在城都地区某处的水下。\p这里深水不多，你得仔细\n找一找才行。\p你会需要这个的！$"

NewBarkTownRivalHouseRival_Text_10:
	.string "它们大概相隔很远，所以\n你最好把整个地区都仔细\l搜一遍。$"

NewBarkTownRivalHouseRival_Text_11:
	.string "固拉多很可能藏在只能从水下\n进入的洞穴里。也许就在\l气候更炎热的地方附近？\p盖欧卡也许更愿意靠近\n开阔的大海。所以去海岸线\l找找看吧！$"

NewBarkTownRivalHouseRival_Text_12:
	.string "两只都捉到了？！\p回头把它们的宝可梦图鉴数据\n发给我。空木博士一定会\l激动坏的！\p眼下我没有什么要找的了，\n而且可能要过很久，我才能找到\l下一个可以一起去搜的目标。\p我没什么能送你的，不过\n这个你拿去吧！$"

NewBarkTownRivalHouseRival_Text_13:
	.string "那么，谢谢你，{PLAYER}！\n谢谢你做我真正的朋友！$"

NewBarkTownRivalHouseRival_Text_14:
	.string "嘿，{PLAYER}！最近怎么样？\n捉到什么新的特别宝可梦了吗？$"

NewBarkTownRivalHouseMarill_Text_0:
	.string "玛力！$"

NewBarkTownRivalHouseAzumarill_Text_0:
	.string "玛力露丽：玛露！$"
