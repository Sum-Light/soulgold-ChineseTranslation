Route25_BillsHouse_MapScripts::
	.byte 0


@VAR_BILLS_GRANDPA

Route25_BillsHouse_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_BILLS_GRANDPA, 1, Route25_BillsHouse_EventScript_Gramps_Spinda
	goto_if_eq VAR_BILLS_GRANDPA, 2, Route25_BillsHouse_EventScript_Gramps_Roselia
	goto_if_eq VAR_BILLS_GRANDPA, 3, Route25_BillsHouse_EventScript_Gramps_Lotad
	goto_if_eq VAR_BILLS_GRANDPA, 4, Route25_BillsHouse_EventScript_Gramps_Growlithe
	goto_if_eq VAR_BILLS_GRANDPA, 5, Route25_BillsHouse_EventScript_Gramps_Pichu
	goto_if_eq VAR_BILLS_GRANDPA, 6, Route25_BillsHouse_EventScript_Gramps_ShownAll
	msgbox Route25_BillsHouse_Text_GrandpaIntro, MSGBOX_DEFAULT
	setvar VAR_BILLS_GRANDPA, 1
	goto Route25_BillsHouse_EventScript_Gramps_Spinda

Route25_BillsHouse_EventScript_Gramps_Declined::
	msgbox Route25_BillsHouse_Text_YouDontHaveIt, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_WrongMon::
	msgbox Route25_BillsHouse_Text_WrongPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Spinda::
	msgbox Route25_BillsHouse_Text_Spinda, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	@ Store selected slot in VAR_0x800A
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	@ Get the species of the selected Pokémon
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	@ Check if it's Spinda
	goto_if_ne VAR_RESULT, SPECIES_SPINDA, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_SPINDA
	setvar VAR_TEMP_0, ITEM_EVERSTONE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Roselia::
	msgbox Route25_BillsHouse_Text_Roselia, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_ROSELIA, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_ROSELIA
	setvar VAR_TEMP_0, ITEM_LEAF_STONE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Lotad::
	msgbox Route25_BillsHouse_Text_Lotad, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_LOTAD, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_LOTAD
	setvar VAR_TEMP_0, ITEM_DEEP_SEA_TOOTH
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Growlithe::
	msgbox Route25_BillsHouse_Text_Growlithe, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_GROWLITHE, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
	setvar VAR_TEMP_0, ITEM_SUN_STONE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Pichu::
	msgbox Route25_BillsHouse_Text_Pichu, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_PICHU, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_PICHU
	setvar VAR_TEMP_0, ITEM_DEEP_SEA_SCALE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_ShownAll::
	msgbox Route25_BillsHouse_Text_ShownAll, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Correctmon::
	msgbox Route25_BillsHouse_Text_ShownPokemon, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_Appreciation, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0
	call_if_eq VAR_TEMP_0, ITEM_LEAF_STONE, Route25_BillsHouse_EventScript_Gramps_ExtraLeafStones
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route25_BillsHouse_Text_ComeAgain, MSGBOX_DEFAULT
	addvar VAR_BILLS_GRANDPA, 1
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_ExtraLeafStones::
	additem VAR_TEMP_0
	additem VAR_TEMP_0
	return

Route25_BillsHouse_Test::
	givemon SPECIES_SPINDA, 10
	givemon SPECIES_LOTAD, 10
	givemon SPECIES_ROSELIA, 10
	givemon SPECIES_GROWLITHE, 10
	givemon SPECIES_PICHU, 10
	end

Route25_BillsHouse_Text_GrandpaIntro:
	.string "嗯？你认识正辉？\n他是我孙子。\p他在城都地区。他搞电脑\n方面的事，所以\l我在这里看家。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route25_BillsHouse_Text_Spinda:
	.string "我孙子正辉跟我说过，\n有一种宝可梦浑身\l长着随机的花纹。$"
	.string ""
	.string ""

Route25_BillsHouse_Text_Roselia:
	.string "啊，我孙子提到过一种\n绿色的宝可梦，\l手腕上会长出花来。$"
	.string ""
	.string ""

Route25_BillsHouse_Text_Lotad:
	.string "你知道一种头上顶着\n大荷叶的水属性宝可梦吗？\l我听说浅红市的狩猎地带就有。\p真想亲眼看看啊。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route25_BillsHouse_Text_Growlithe:
	.string "正辉跟我说过一种宝可梦，\n听说它\l对训练家非常忠诚。\p据说它很会吼叫。$"
	.string ""
	.string ""
	.string ""

Route25_BillsHouse_Text_Pichu:
	.string "你知道那种超有人气的\n宝可梦吗？\p就是那个黄色身体、\n红脸颊的宝可梦。\p我真想在它进化之前\n看看它长什么样。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route25_BillsHouse_Text_AskToSeeMon:
	.string "你要是有那只宝可梦，\n能让我看看吗？$"
	.string ""

Route25_BillsHouse_Text_ExcitedToSee:
	.string "你愿意给我看？\n你人真好！$"
	.string ""

Route25_BillsHouse_Text_YouDontHaveIt:
	.string "你没有？\n那太遗憾了……$"
	.string ""

Route25_BillsHouse_Text_ShownPokemon:
	.string "啊，这就是{STR_VAR_1}吗？\p真可爱！你真是好心。$"
	.string ""
	.string ""

Route25_BillsHouse_Text_Appreciation:
	.string "谢谢！\p这是我的一点\n谢意。$"
	.string ""
	.string ""

Route25_BillsHouse_Text_ComeAgain:
	.string "有空再来玩啊。$"

Route25_BillsHouse_Text_ShownAll:
	.string "谢谢你给我看了\n这么多可爱的宝可梦。\p我真的很开心。\n能活到这把年纪，\l真是太好了。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route25_BillsHouse_Text_WrongPokemon:
	.string "嗯？\p我听说的宝可梦，\n好像不是这只啊。$"
	.string ""
	.string ""


