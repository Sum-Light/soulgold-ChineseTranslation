
CianwoodHouse3_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 2, CianwoodCity_EventScript_KirkReturnShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "我、我吓坏了！\p来了一个和你差不多年纪、\n目光锐利、留着长发的家伙。\p他把我吓得\n把心爱的宝可梦交了出去！\p我还剩一只，可万一\n他再回来怎么办？\p你看起来很厉害。能帮我\n照顾一阵子宝可梦吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "哦，谢谢你！\p请好好照顾它！$"
	.string ""

CianwoodCity_Text_ManiacGotShuckle:
	.string "{PLAYER}得到了一只宝可梦。$"

CianwoodCity_Text_ManiacPartyFull:
	.string "你的宝可梦队伍已经满了。$"

CianwoodCity_Text_ManiacIfHeComesBack:
	.string "哎呀……要是他再回来，\n我可怎么办？$"
	.string ""

CianwoodCity_Text_ManiacHowsdoing:
	.string "嗨！我的宝可梦还好吗？$"

CianwoodCity_Text_ManiacAskReturn:
	.string "嗨！我的宝可梦还好吗？\p我想现在应该没事了，能把\n它还给我吗？$"
	.string ""
	.string ""

CianwoodCity_Text_ManiacThankYou:
	.string "谢谢你！$"

CianwoodCity_Text_ManiacShuckleNotThere:
	.string "喂，我的宝可梦\n不在你身上啊。$"
	.string ""

CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "我的宝可梦喜欢上你了。\p好吧，就送给你了。\p但要答应我，\n一定要好好待它！$"
	.string ""
	.string ""

CianwoodCity_Text_ManiacRobbed:
	.string "嗯？有点不对劲。$"

CianwoodCity_Text_ManiacRobbed2:
	.string "哎呀，不行不行……那跟\n被抢走有什么两样。$"
	.string ""

CianwoodCity_Text_ManiacHappinessSpeech:
	.string "对宝可梦来说，幸福就是\n和善待它的人在一起。$"
	.string ""

CianwoodCity_Text_ManiacLastMon:
	.string "要是把我的宝可梦要回去，\n你拿什么来对战？$"
	.string ""
	.string ""


CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER}把Shuckie还了回去。$"

Cianwood_Kirk::
	lock
	faceplayer
	goto_if_set FLAG_CIANWOOD_GIMMIGHOUL, Cianwood_Kirk_2
	msgbox Cianwood_Kirk_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Cianwood_Kirk_5
	msgbox Cianwood_Kirk_Text_3
Cianwood_Kirk_4:
	release
	end

Cianwood_Kirk_2:
	msgbox Cianwood_Kirk_Text_0
	release
	end

Cianwood_Kirk_5:
	msgbox Cianwood_Kirk_Text_2
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GIMMIGHOUL_CHEST
	bufferspeciesname STR_VAR_1, SPECIES_GIMMIGHOUL_CHEST
	givemon SPECIES_GIMMIGHOUL_CHEST, 30
	call Common_EventScript_GiftMon
	setflag FLAG_CIANWOOD_GIMMIGHOUL
	goto Cianwood_Kirk_4


Cianwood_Kirk_Text_0:
	.string "嗨，我的宝可梦还好吗？$"

Cianwood_Kirk_Text_1:
	.string "我、我吓坏了！\p来了一个和你差不多年纪、\n目光锐利、留着长发的家伙。\p他把我吓得\n把心爱的宝可梦交了出去！\p我还剩一只，可万一\n他再回来怎么办？\p你看起来很厉害。能帮我\n照顾一阵子宝可梦吗？$"

Cianwood_Kirk_Text_2:
	.string "哦，谢谢你！\p请好好照顾它！$"

Cianwood_Kirk_Text_3:
	.string "哎呀，我该怎么办……$"
