AbandonedRocketHideoutBackroom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedRocketHideoutBackroom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

AbandonedRocketHideoutBackroom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_IS_CHAMPION, AbandonedRocketHideoutBackroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
AbandonedRocketHideoutBackroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_HIDE_GENESECT
	return

AbandonedRocketHideoutBackroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_GENESECT
	return

AbandonedRocketHideoutBackroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	goto_if_unset FLAG_CAUGHT_GENESECT, AbandonedRocketHideoutBackroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto AbandonedRocketHideoutBackroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_2


ARH_LaptopBackroom::
	msgbox ARH_LaptopBackroom_Text_0, MSGBOX_NPC
	return


ARH_NotesBackroom::
	msgbox ARH_NotesBackroom_Text_0, MSGBOX_SIGN
	return


ARH_Strangewall::
	msgbox ARH_Strangewall_Text_0, MSGBOX_SIGN
	return


GenesectEncounter::
	lock
	faceplayer
	bosslegendaryencounter SPECIES_GENESECT, 70, LOCALID_GENESECT, FLAG_HIDE_GENESECT, 2, SPECIES_NONE, 110
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GenesectEncounter_2
GenesectEncounter_1:
	release
	end

GenesectEncounter_2:
	setflag FLAG_CAUGHT_GENESECT
	goto GenesectEncounter_1


ARH_LaptopBackroom_Text_0:
	.string "笔记本电脑已经没电了，\n它下面压着一张便利贴。\p实验体：黑暗L????\p其余文字被似乎是\n咖啡渍的痕迹浸透了。$"

ARH_NotesBackroom_Text_0:
	.string "记录——情绪压缩研究\p我们把从某种传说的\n宝可梦身上结晶出的\l能量，制成了能储存\l强烈负面情绪的容器。\p把这些容器用在\n纯净度高的生物身上，\l就能像磁铁一样，\l把它们的情绪逆转\l到相反的一端。\p长期影响还需要\n进一步实验确认。$"

ARH_Strangewall_Text_0:
	.string "这面墙总感觉哪里不对，\n可看不到钥匙孔，\l也没有读卡器。$"
