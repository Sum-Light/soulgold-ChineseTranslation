BattleFrontier_ShowCaughtBannedSpecies::
	goto_if_eq VAR_0x8005, 0, BattleFrontier_ShowCaughtBannedSpeciesEnd
	msgbox BattleFrontier_DoYouWantToSeeTheListOfCaughtBannedSpecies, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ShowCaughtBannedSpeciesEnd
	callnative ShowBattleFrontierCaughtBannedSpecies
	waitstate
BattleFrontier_ShowCaughtBannedSpeciesEnd:
	return


BattleFrontier_DoYouWantToSeeTheListOfCaughtBannedSpecies:
	.string "要查看无法参加的\n宝可梦名单吗？$"
	.string ""

BattleFrontier_EventScript_ShowLevelModeInfo::
	msgbox BattleFrontier_Text_LevelModeInfo, MSGBOX_DEFAULT
	return

BattleFrontier_EventScript_ChooseInnates::
	goto_if_set FLAG_BATTLE_FACILITY_NO_INNATES, BattleFrontier_EventScript_EnableInnates
	msgbox BattleFrontier_Text_DisableInnates, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, BattleFrontier_EventScript_ChooseInnatesEnd
	setflag FLAG_BATTLE_FACILITY_NO_INNATES
	playse SE_SWITCH
	waitse
	msgbox BattleFrontier_Text_InnatesDisabled, MSGBOX_DEFAULT
	return

BattleFrontier_EventScript_EnableInnates:
	msgbox BattleFrontier_Text_EnableInnates, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, BattleFrontier_EventScript_ChooseInnatesEnd
	clearflag FLAG_BATTLE_FACILITY_NO_INNATES
	playse SE_SWITCH
	waitse
	msgbox BattleFrontier_Text_InnatesEnabled, MSGBOX_DEFAULT
BattleFrontier_EventScript_ChooseInnatesEnd:
	return

BattleFrontier_EventScript_ChooseBattleBgm::
	message BattleFrontier_Text_ChooseBattleBgm
	waitmessage
	special BuildBattleFacilityBgmMenu
	dynmultistack 0, 0, FALSE, 6, FALSE, VAR_BATTLE_FACILITY_BGM, DYN_MULTICHOICE_CB_NONE
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, BattleFrontier_EventScript_ChooseBattleBgmEnd
	copyvar VAR_BATTLE_FACILITY_BGM, VAR_RESULT
	msgbox BattleFrontier_Text_BattleBgmUpdated, MSGBOX_DEFAULT
BattleFrontier_EventScript_ChooseBattleBgmEnd:
	return

BattleFrontier_Text_LevelModeInfo:
	.string "经典模式下，队伍等级会调整为\nLv. 50，并且受限的传说宝可梦\l无法参加设施对战。\p混沌模式下，队伍等级会调整为\nLv. 100，没有任何限制。\p天赋特性可以另外\n单独开启或关闭。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

BattleFrontier_Text_DisableInnates:
	.string "当前天赋特性为开启状态。\n要关闭吗？$"
	.string ""

BattleFrontier_Text_EnableInnates:
	.string "当前天赋特性为关闭状态。\n要开启吗？$"
	.string ""

BattleFrontier_Text_InnatesDisabled:
	.string "所有设施中的天赋特性\n均已关闭。$"
	.string ""

BattleFrontier_Text_InnatesEnabled:
	.string "所有设施中的天赋特性\n均已开启。$"
	.string ""

BattleFrontier_Text_ChooseBattleBgm:
	.string "请选择设施对战的音乐。$"

BattleFrontier_Text_BattleBgmUpdated:
	.string "设施对战的音乐已更改。$"
