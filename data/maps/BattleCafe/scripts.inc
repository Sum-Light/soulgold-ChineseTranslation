
BattleCafe_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleCafe_OnTransition
	.byte 0

BattleCafe_OnTransition::
	setflag FLAG_HIDE_BATTLE_CAFE_OPPONENT
	setflag FLAG_VISITED_ROUTE50
	end


BattleCafe_Owner::
	lock
	faceplayer
	goto_if_unset FLAG_BATTLE_CAFE_DIANCIE_RECEIVED, BattleCafe_Owner_4
BattleCafe_Owner_1:
	goto BattleCafe_OwnerMenu
	return

BattleCafe_Owner_2:
	goto BattleCafe_GiveDiancie
	goto BattleCafe_Owner_1

BattleCafe_Owner_3:
	checktrainerflag TRAINER_CAFE_DOVES
	goto_if 1, BattleCafe_Owner_8
	goto BattleCafe_Owner_1

BattleCafe_Owner_4:
	checktrainerflag TRAINER_CAFE_ATHENA
	goto_if 1, BattleCafe_Owner_3
	goto BattleCafe_Owner_1

BattleCafe_Owner_7:
	checktrainerflag TRAINER_CAFE_NEM
	goto_if 1, BattleCafe_Owner_12
	goto BattleCafe_Owner_1

BattleCafe_Owner_8:
	checktrainerflag TRAINER_CAFE_ELTON
	goto_if 1, BattleCafe_Owner_7
	goto BattleCafe_Owner_1

BattleCafe_Owner_11:
	checktrainerflag TRAINER_CAFE_DRAC
	goto_if 1, BattleCafe_Owner_16
	goto BattleCafe_Owner_1

BattleCafe_Owner_12:
	checktrainerflag TRAINER_CAFE_BAI
	goto_if 1, BattleCafe_Owner_11
	goto BattleCafe_Owner_1

BattleCafe_Owner_15:
	checktrainerflag TRAINER_CAFE_TYLARIE
	goto_if 1, BattleCafe_Owner_2
	goto BattleCafe_Owner_1

BattleCafe_Owner_16:
	checktrainerflag TRAINER_CAFE_JUNA
	goto_if 1, BattleCafe_Owner_15
	goto BattleCafe_Owner_1


BattleCafe_GiveDiancie::
	goto_if_unset FLAG_BATTLE_CAFE_DIANCIE_READY, BattleCafe_GiveDiancie_2
	msgbox BattleCafe_GiveDiancie_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_GiveDiancie_5
BattleCafe_GiveDiancie_4:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DIANCIE
	bufferspeciesname STR_VAR_1, SPECIES_DIANCIE
	givemon SPECIES_DIANCIE, 70
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_GiveDiancie_8
BattleCafe_GiveDiancie_7:
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	clearflag FLAG_BATTLE_CAFE_DIANCIE_READY
	setflag FLAG_BATTLE_CAFE_DIANCIE_RECEIVED
	msgbox BattleCafe_GiveDiancie_Text_4
	goto BattleCafe_OwnerMenu
	return

BattleCafe_GiveDiancie_2:
	msgbox BattleCafe_GiveDiancie_Text_0
	msgbox BattleCafe_GiveDiancie_Text_1
	setflag FLAG_BATTLE_CAFE_DIANCIE_READY
	release
	end

BattleCafe_GiveDiancie_5:
	msgbox BattleCafe_GiveDiancie_Text_3
	goto BattleCafe_OwnerMenu
	goto BattleCafe_GiveDiancie_4

BattleCafe_GiveDiancie_8:
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_GiveDiancie_7


BattleCafe_OwnerMenu::
	goto_if_unset FLAG_CAFE_INTRO_DONE, BattleCafe_OwnerMenu_2
BattleCafe_OwnerMenu_1:
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_OwnerMenu_6
BattleCafe_OwnerMenu_4:
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_OwnerMenu_11
BattleCafe_OwnerMenu_9:
	msgbox BattleCafe_OwnerMenu_Text_3
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_OwnerMenu_15
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_OwnerMenu_15
BattleCafe_OwnerMenu_14:
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OwnerMenu_Text_4, BattleCafe_OwnerMenu_Text_5, BattleCafe_OwnerMenu_Text_6, BattleCafe_OwnerMenu_Text_7, BattleCafe_OwnerMenu_Text_9, BattleCafe_OwnerMenu_Text_10, BattleCafe_OwnerMenu_Text_11
	switch VAR_RESULT
	case 0, BattleCafe_OwnerMenu_20
	case 1, BattleCafe_OwnerMenu_21
	case 2, BattleCafe_OwnerMenu_22
	case 3, BattleCafe_OwnerMenu_23
	case 4, BattleCafe_OwnerMenu_24
	case 5, BattleCafe_OwnerMenu_25
	goto BattleCafe_Goodbye
	return

BattleCafe_OwnerMenu_2:
	msgbox BattleCafe_OwnerMenu_Text_0
	setflag FLAG_CAFE_INTRO_DONE
	goto BattleCafe_OwnerMenu_1

BattleCafe_OwnerMenu_5:
	msgbox BattleCafe_OwnerMenu_Text_1
	setflag FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED
	goto BattleCafe_OwnerMenu_4

BattleCafe_OwnerMenu_6:
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON, BattleCafe_OwnerMenu_5
	goto BattleCafe_OwnerMenu_4

BattleCafe_OwnerMenu_10:
	msgbox BattleCafe_OwnerMenu_Text_2
	setflag FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED
	goto BattleCafe_OwnerMenu_9

BattleCafe_OwnerMenu_11:
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON, BattleCafe_OwnerMenu_10
	goto BattleCafe_OwnerMenu_9

BattleCafe_OwnerMenu_15:
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OwnerMenu_Text_4, BattleCafe_OwnerMenu_Text_5, BattleCafe_OwnerMenu_Text_6, BattleCafe_OwnerMenu_Text_7, BattleCafe_OwnerMenu_Text_8, BattleCafe_OwnerMenu_Text_9, BattleCafe_OwnerMenu_Text_10, BattleCafe_OwnerMenu_Text_11
	switch VAR_RESULT
	case 0, BattleCafe_OwnerMenu_28
	case 1, BattleCafe_OwnerMenu_29
	case 2, BattleCafe_OwnerMenu_30
	case 3, BattleCafe_OwnerMenu_31
	case 4, BattleCafe_OwnerMenu_32
	case 5, BattleCafe_OwnerMenu_33
	case 6, BattleCafe_OwnerMenu_34
	goto BattleCafe_Goodbye
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_20:
	goto BattleCafe_AskDailyChallenge
	return

BattleCafe_OwnerMenu_21:
	goto BattleCafe_AskRushMode
	return

BattleCafe_OwnerMenu_22:
	goto BattleCafe_AskSuperChallenge
	return

BattleCafe_OwnerMenu_23:
	goto BattleCafe_AskSuperRush
	return

BattleCafe_OwnerMenu_24:
	goto BattleCafe_RewardMenu
	return

BattleCafe_OwnerMenu_25:
	goto BattleCafe_OptionsMenu
	return

BattleCafe_OwnerMenu_28:
	goto BattleCafe_AskDailyChallenge
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_29:
	goto BattleCafe_AskRushMode
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_30:
	goto BattleCafe_AskSuperChallenge
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_31:
	goto BattleCafe_AskSuperRush
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_32:
	goto BattleCafe_EndlessMenu
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_33:
	goto BattleCafe_RewardMenu
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_34:
	goto BattleCafe_OptionsMenu
	goto BattleCafe_OwnerMenu_14


BattleCafe_OptionsMenu::
	msgbox BattleCafe_OptionsMenu_Text_0
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OptionsMenu_Text_1, BattleCafe_OptionsMenu_Text_2, BattleCafe_OptionsMenu_Text_3, BattleCafe_OptionsMenu_Text_4, BattleCafe_OptionsMenu_Text_5
	switch VAR_RESULT
	case 0, BattleCafe_OptionsMenu_2
	case 1, BattleCafe_OptionsMenu_3
	case 2, BattleCafe_OptionsMenu_4
	case 3, BattleCafe_OptionsMenu_5
	goto BattleCafe_OwnerMenu
	return

BattleCafe_OptionsMenu_2:
	goto BattleCafe_ChooseBattleBgm
	return

BattleCafe_OptionsMenu_3:
	goto BattleCafe_ViewHighScores
	return

BattleCafe_OptionsMenu_4:
	goto BattleCafe_ChooseInnates
	return

BattleCafe_OptionsMenu_5:
	goto BattleCafe_ExplainRules
	return


BattleCafe_ChooseBattleBgm::
	call BattleFrontier_EventScript_ChooseBattleBgm
	goto BattleCafe_OwnerMenu
	return


BattleCafe_ViewHighScores::
	closemessage
	special BattleCafe_ShowRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	goto BattleCafe_OwnerMenu
	return


BattleCafe_ChooseInnates::
	call BattleFrontier_EventScript_ChooseInnates
	goto BattleCafe_OptionsMenu
	return


BattleCafe_ExplainRules::
	msgbox BattleCafe_ExplainRules_Text_0
	msgbox BattleCafe_ExplainRules_Text_1
	msgbox BattleCafe_ExplainRules_Text_2
	msgbox BattleCafe_ExplainRules_Text_3
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_ExplainRules_2
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_ExplainRules_2
BattleCafe_ExplainRules_1:
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ExplainRules_2:
	msgbox BattleCafe_ExplainRules_Text_4
	msgbox BattleCafe_ExplainRules_Text_5
	goto BattleCafe_ExplainRules_1


BattleCafe_AskDailyChallenge::
	goto_if_set FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON, BattleCafe_AskDailyChallenge_2
BattleCafe_AskDailyChallenge_1:
	msgbox BattleCafe_AskDailyChallenge_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskDailyChallenge_5
BattleCafe_AskDailyChallenge_4:
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskDailyChallenge_2:
	msgbox BattleCafe_AskDailyChallenge_Text_0
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_1

BattleCafe_AskDailyChallenge_5:
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_4


BattleCafe_AskRushMode::
	goto_if_set FLAG_DAILY_BATTLE_CAFE_RUSH_WON, BattleCafe_AskRushMode_2
BattleCafe_AskRushMode_1:
	msgbox BattleCafe_AskRushMode_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskRushMode_5
BattleCafe_AskRushMode_4:
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskRushMode_2:
	msgbox BattleCafe_AskRushMode_Text_0
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_1

BattleCafe_AskRushMode_5:
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_4


BattleCafe_AskSuperChallenge::
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON, BattleCafe_AskSuperChallenge_2
BattleCafe_AskSuperChallenge_1:
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperChallenge_5
BattleCafe_AskSuperChallenge_4:
	msgbox BattleCafe_AskSuperChallenge_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperChallenge_8
BattleCafe_AskSuperChallenge_7:
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperChallenge_2:
	msgbox BattleCafe_AskSuperChallenge_Text_0
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_1

BattleCafe_AskSuperChallenge_5:
	msgbox BattleCafe_AskSuperChallenge_Text_1
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_4

BattleCafe_AskSuperChallenge_8:
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_7


BattleCafe_AskSuperRush::
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON, BattleCafe_AskSuperRush_2
BattleCafe_AskSuperRush_1:
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperRush_5
BattleCafe_AskSuperRush_4:
	msgbox BattleCafe_AskSuperRush_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperRush_8
BattleCafe_AskSuperRush_7:
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperRush_2:
	msgbox BattleCafe_AskSuperRush_Text_0
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_1

BattleCafe_AskSuperRush_5:
	msgbox BattleCafe_AskSuperRush_Text_1
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_4

BattleCafe_AskSuperRush_8:
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_7


BattleCafe_EndlessMenu::
	msgbox BattleCafe_EndlessMenu_Text_0
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_EndlessMenu_Text_1, BattleCafe_EndlessMenu_Text_2, BattleCafe_EndlessMenu_Text_3, BattleCafe_OptionsMenu_Text_5
	switch VAR_RESULT
	case 0, BattleCafe_EndlessMenu_2
	case 1, BattleCafe_EndlessMenu_3
	case 2, BattleCafe_EndlessMenu_4
	goto BattleCafe_OwnerMenu
	return

BattleCafe_EndlessMenu_2:
	goto BattleCafe_AskEndlessChallenge
	return

BattleCafe_EndlessMenu_3:
	goto BattleCafe_AskEndlessRush
	return

BattleCafe_EndlessMenu_4:
	goto BattleCafe_ExplainEndlessRules
	return


BattleCafe_ExplainEndlessRules::
	msgbox BattleCafe_ExplainEndlessRules_Text_0
	msgbox BattleCafe_ExplainEndlessRules_Text_1
	msgbox BattleCafe_ExplainEndlessRules_Text_2
	goto BattleCafe_EndlessMenu
	return


BattleCafe_AskEndlessChallenge::
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_AskEndlessChallenge_2
BattleCafe_AskEndlessChallenge_1:
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskEndlessChallenge_5
BattleCafe_AskEndlessChallenge_4:
	msgbox BattleCafe_AskEndlessChallenge_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskEndlessChallenge_8
BattleCafe_AskEndlessChallenge_7:
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskEndlessChallenge_2:
	msgbox BattleCafe_AskEndlessChallenge_Text_0
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_1

BattleCafe_AskEndlessChallenge_5:
	msgbox BattleCafe_AskEndlessChallenge_Text_1
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_4

BattleCafe_AskEndlessChallenge_8:
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_7


BattleCafe_AskEndlessRush::
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_AskEndlessRush_2
BattleCafe_AskEndlessRush_1:
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskEndlessRush_5
BattleCafe_AskEndlessRush_4:
	msgbox BattleCafe_AskEndlessRush_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskEndlessRush_8
BattleCafe_AskEndlessRush_7:
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskEndlessRush_2:
	msgbox BattleCafe_AskEndlessRush_Text_0
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_1

BattleCafe_AskEndlessRush_5:
	msgbox BattleCafe_AskEndlessChallenge_Text_1
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_4

BattleCafe_AskEndlessRush_8:
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_7


BattleCafe_BeginChallenge::
	closemessage
	hidefollower
	special HealPlayerParty
	special BattleCafe_InitChallenge
	moveobjecttocoords LOCALID_PLAYER, 6, 13, DIR_EAST
	waitmovement 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_C, 0
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_BeginChallenge_2
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_BeginChallenge_2
	msgbox BattleCafe_BeginChallenge_Text_1
BattleCafe_BeginChallenge_1:
	closemessage
	goto BattleCafe_ChallengeNextRound
	return

BattleCafe_BeginChallenge_2:
	msgbox BattleCafe_BeginChallenge_Text_0
	goto BattleCafe_BeginChallenge_1


BattleCafe_ChallengeNextRound::
	call BattleCafe_RunRound
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChallengeNextRound_2
BattleCafe_ChallengeNextRound_1:
	special BattleCafe_AdvanceWinCount
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_ChallengeNextRound_5
BattleCafe_ChallengeNextRound_4:
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_ChallengeNextRound_8
BattleCafe_ChallengeNextRound_7:
	compare VAR_TEMP_9, 3
	goto_if_ge BattleCafe_ChallengeNextRound_14
BattleCafe_ChallengeNextRound_13:
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeNextRound_21
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeNextRound_27
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
	goto_if_eq BattleCafe_ChallengeNextRound_30
	msgbox BattleCafe_ChallengeNextRound_Text_6
BattleCafe_ChallengeNextRound_20:
	closemessage
	goto BattleCafe_ChallengeNextRound
	return

BattleCafe_ChallengeNextRound_2:
	goto BattleCafe_ChallengeLost
	goto BattleCafe_ChallengeNextRound_1

BattleCafe_ChallengeNextRound_5:
	setvar VAR_0x8004, 1
	special BattleCafe_AwardPoints
	copyvar VAR_TEMP_B, VAR_RESULT
	special HealPlayerParty
	playse SE_SHOP
	waitse
	buffernumberstring STR_VAR_1, VAR_TEMP_9
	buffernumberstring STR_VAR_2, VAR_TEMP_B
	msgbox BattleCafe_ChallengeNextRound_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChallengeNextRound_11
BattleCafe_ChallengeNextRound_10:
	closemessage
	goto BattleCafe_ChallengeNextRound
	goto BattleCafe_ChallengeNextRound_4

BattleCafe_ChallengeNextRound_8:
	setvar VAR_0x8004, 2
	special BattleCafe_AwardPoints
	copyvar VAR_TEMP_B, VAR_RESULT
	addvar VAR_TEMP_C, 1
	playse SE_SHOP
	waitse
	buffernumberstring STR_VAR_1, VAR_TEMP_9
	buffernumberstring STR_VAR_2, VAR_TEMP_B
	compare VAR_TEMP_C, 3
	goto_if_ge BattleCafe_ChallengeNextRound_17
	msgbox BattleCafe_ChallengeNextRound_Text_2, MSGBOX_YESNO
BattleCafe_ChallengeNextRound_16:
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChallengeNextRound_25
BattleCafe_ChallengeNextRound_24:
	closemessage
	goto BattleCafe_ChallengeNextRound
	goto BattleCafe_ChallengeNextRound_7

BattleCafe_ChallengeNextRound_11:
	goto BattleCafe_EndlessRetired
	goto BattleCafe_ChallengeNextRound_10

BattleCafe_ChallengeNextRound_14:
	goto BattleCafe_ChallengeWon
	goto BattleCafe_ChallengeNextRound_13

BattleCafe_ChallengeNextRound_17:
	setvar VAR_TEMP_C, 0
	special HealPlayerParty
	playse SE_USE_ITEM
	msgbox BattleCafe_ChallengeNextRound_Text_1, MSGBOX_YESNO
	goto BattleCafe_ChallengeNextRound_16

BattleCafe_ChallengeNextRound_21:
	special HealPlayerParty
	playse SE_USE_ITEM
	msgbox BattleCafe_ChallengeNextRound_Text_3
	goto BattleCafe_ChallengeNextRound_20

BattleCafe_ChallengeNextRound_25:
	goto BattleCafe_EndlessRetired
	goto BattleCafe_ChallengeNextRound_24

BattleCafe_ChallengeNextRound_27:
	special HealPlayerParty
	playse SE_USE_ITEM
	msgbox BattleCafe_ChallengeNextRound_Text_4
	goto BattleCafe_ChallengeNextRound_20

BattleCafe_ChallengeNextRound_30:
	msgbox BattleCafe_ChallengeNextRound_Text_5
	goto BattleCafe_ChallengeNextRound_20


BattleCafe_EndlessRetired::
	closemessage
	special BattleCafe_EndChallenge
	special HealPlayerParty
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
	waitmovement 0
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
	buffernumberstring STR_VAR_1, VAR_TEMP_9
	msgbox BattleCafe_EndlessRetired_Text_0
	goto BattleCafe_OwnerMenu
	return


BattleCafe_RunRound::
	copyvar VAR_0x8004, VAR_TEMP_9
	special BattleCafe_SelectOpponent
	setobjectxy LOCALID_BATTLE_CAFE_OPPONENT, 14, 17
	addobject LOCALID_BATTLE_CAFE_OPPONENT
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 10, 13, DIR_WEST
	waitmovement 0
	tower_getopponentintro FRONTIER_BEFORE_TEXT
	msgbox gStringVar4
	closemessage
	dofacilitytrainerbattle FACILITY_BATTLE_CAFE
	waitstate
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	copyvar VAR_TEMP_A, VAR_RESULT
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 14, 17, DIR_EAST
	waitmovement 0
	removeobject LOCALID_BATTLE_CAFE_OPPONENT
	compare VAR_TEMP_A, B_OUTCOME_WON
	goto_if_eq BattleCafe_RunRound_2
	setvar VAR_RESULT, FALSE
BattleCafe_RunRound_1:
	return

BattleCafe_RunRound_2:
	setvar VAR_RESULT, TRUE
	goto BattleCafe_RunRound_1


BattleCafe_ChallengeLost::
	special BattleCafe_EndChallenge
	special HealPlayerParty
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
	waitmovement 0
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_ChallengeLost_2
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_ChallengeLost_2
	msgbox BattleCafe_ChallengeLost_Text_1
BattleCafe_ChallengeLost_1:
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ChallengeLost_2:
	buffernumberstring STR_VAR_1, VAR_TEMP_9
	msgbox BattleCafe_ChallengeLost_Text_0
	goto BattleCafe_ChallengeLost_1


BattleCafe_ChallengeWon::
	special BattleCafe_EndChallenge
	special HealPlayerParty
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
	waitmovement 0
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeWon_2
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
	goto_if_eq BattleCafe_ChallengeWon_5
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeWon_8
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON
	setvar VAR_0x8004, 10
	special BattleCafe_AwardPoints
	copyvar VAR_TEMP_B, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_TEMP_B
	msgbox BattleCafe_ChallengeWon_Text_3
BattleCafe_ChallengeWon_1:
	special BattleCafe_UnlockClearAchievement
	playse SE_SHOP
	waitse
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ChallengeWon_2:
	setflag FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON
	setvar VAR_0x8004, 3
	special BattleCafe_AwardPoints
	copyvar VAR_TEMP_B, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_TEMP_B
	msgbox BattleCafe_ChallengeWon_Text_0
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_5:
	setflag FLAG_DAILY_BATTLE_CAFE_RUSH_WON
	setvar VAR_0x8004, 5
	special BattleCafe_AwardPoints
	copyvar VAR_TEMP_B, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_TEMP_B
	msgbox BattleCafe_ChallengeWon_Text_1
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_8:
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON
	setvar VAR_0x8004, 5
	special BattleCafe_AwardPoints
	copyvar VAR_TEMP_B, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_TEMP_B
	msgbox BattleCafe_ChallengeWon_Text_2
	goto BattleCafe_ChallengeWon_1


BattleCafe_RewardMenu::
	buffernumberstring STR_VAR_1, VAR_BATTLE_CAFE_POINTS
	msgbox BattleCafe_RewardMenu_Text_0
	special BattleCafe_GetParadoxRewardEligibility
	copyvar VAR_TEMP_C, VAR_RESULT
	dynmultipush BattleCafe_RewardMenu_Text_1, 10
	dynmultipush BattleCafe_RewardMenu_Text_2, 11
	dynmultipush BattleCafe_RewardMenu_Text_3, 12
	dynmultipush BattleCafe_RewardMenu_Text_4, 7
	dynmultipush BattleCafe_RewardMenu_Text_5, 8
	dynmultipush BattleCafe_RewardMenu_Text_6, 9
	dynmultipush BattleCafe_RewardMenu_Text_7, 0
	dynmultipush BattleCafe_RewardMenu_Text_8, 1
	dynmultipush BattleCafe_RewardMenu_Text_9, 2
	dynmultipush BattleCafe_RewardMenu_Text_10, 3
	dynmultipush BattleCafe_RewardMenu_Text_11, 4
	dynmultipush BattleCafe_RewardMenu_Text_12, 5
	dynmultipush BattleCafe_RewardMenu_Text_13, 6
	dynmultipush BattleCafe_RewardMenu_Text_14, 16
	dynmultipush BattleCafe_RewardMenu_Text_15, 17
	dynmultipush BattleCafe_RewardMenu_Text_16, 18
	dynmultipush BattleCafe_RewardMenu_Text_17, 19
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_MIRAIDON
	goto_if_eq BattleCafe_RewardMenu_2
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_MIRAIDON + BATTLE_CAFE_PARADOX_REWARD_KORAIDON
	goto_if_eq BattleCafe_RewardMenu_2
BattleCafe_RewardMenu_1:
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_KORAIDON
	goto_if_eq BattleCafe_RewardMenu_7
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_MIRAIDON + BATTLE_CAFE_PARADOX_REWARD_KORAIDON
	goto_if_eq BattleCafe_RewardMenu_7
BattleCafe_RewardMenu_6:
	dynmultipush BattleCafe_OptionsMenu_Text_5, 15
	dynmultistack 0, 0, FALSE, 6, FALSE, 10, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, BattleCafe_RewardMenu_12
	case 1, BattleCafe_RewardMenu_13
	case 2, BattleCafe_RewardMenu_14
	case 3, BattleCafe_RewardMenu_15
	case 4, BattleCafe_RewardMenu_16
	case 5, BattleCafe_RewardMenu_17
	case 6, BattleCafe_RewardMenu_18
	case 7, BattleCafe_RewardMenu_19
	case 8, BattleCafe_RewardMenu_20
	case 9, BattleCafe_RewardMenu_21
	case 10, BattleCafe_RewardMenu_22
	case 11, BattleCafe_RewardMenu_23
	case 12, BattleCafe_RewardMenu_24
	case 13, BattleCafe_RewardMenu_25
	case 14, BattleCafe_RewardMenu_26
	case 16, BattleCafe_RewardMenu_27
	case 17, BattleCafe_RewardMenu_28
	case 18, BattleCafe_RewardMenu_29
	case 19, BattleCafe_RewardMenu_30
	goto BattleCafe_OwnerMenu
	return

BattleCafe_RewardMenu_2:
	dynmultipush BattleCafe_RewardMenu_Text_18, 13
	goto BattleCafe_RewardMenu_1

BattleCafe_RewardMenu_7:
	dynmultipush BattleCafe_RewardMenu_Text_19, 14
	goto BattleCafe_RewardMenu_6

BattleCafe_RewardMenu_12:
	goto BattleCafe_ChooseArticuno
	return

BattleCafe_RewardMenu_13:
	goto BattleCafe_ChooseZapdos
	return

BattleCafe_RewardMenu_14:
	goto BattleCafe_ChooseMoltres
	return

BattleCafe_RewardMenu_15:
	goto BattleCafe_ChooseTornadus
	return

BattleCafe_RewardMenu_16:
	goto BattleCafe_ChooseThundurus
	return

BattleCafe_RewardMenu_17:
	goto BattleCafe_ChooseLandorus
	return

BattleCafe_RewardMenu_18:
	goto BattleCafe_ChooseEnamorus
	return

BattleCafe_RewardMenu_19:
	goto BattleCafe_ChooseShinyGenome
	return

BattleCafe_RewardMenu_20:
	goto BattleCafe_ChooseGoldBottleCaps
	return

BattleCafe_RewardMenu_21:
	goto BattleCafe_ChooseMoney
	return

BattleCafe_RewardMenu_22:
	goto BattleCafe_ChooseVitaminSetAtk
	return

BattleCafe_RewardMenu_23:
	goto BattleCafe_ChooseVitaminSetDef
	return

BattleCafe_RewardMenu_24:
	goto BattleCafe_ChooseVitaminSetSpe
	return

BattleCafe_RewardMenu_25:
	goto BattleCafe_ChooseMiraidon
	return

BattleCafe_RewardMenu_26:
	goto BattleCafe_ChooseKoraidon
	return

BattleCafe_RewardMenu_27:
	goto BattleCafe_ChooseTapuKoko
	return

BattleCafe_RewardMenu_28:
	goto BattleCafe_ChooseTapuLele
	return

BattleCafe_RewardMenu_29:
	goto BattleCafe_ChooseTapuBulu
	return

BattleCafe_RewardMenu_30:
	goto BattleCafe_ChooseTapuFini
	return


BattleCafe_ChooseArticuno::
	goto_if_set FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED, BattleCafe_ChooseArticuno_2
BattleCafe_ChooseArticuno_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_GALAR
	setvar VAR_TEMP_B, 0
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseArticuno_2:
	msgbox BattleCafe_ChooseArticuno_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseArticuno_1


BattleCafe_ChooseZapdos::
	goto_if_set FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED, BattleCafe_ChooseZapdos_2
BattleCafe_ChooseZapdos_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_GALAR
	setvar VAR_TEMP_B, 1
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseZapdos_2:
	msgbox BattleCafe_ChooseZapdos_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseZapdos_1


BattleCafe_ChooseMoltres::
	goto_if_set FLAG_BATTLE_CAFE_MOLTRES_RECEIVED, BattleCafe_ChooseMoltres_2
BattleCafe_ChooseMoltres_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_GALAR
	setvar VAR_TEMP_B, 2
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseMoltres_2:
	msgbox BattleCafe_ChooseMoltres_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoltres_1


BattleCafe_ChooseTornadus::
	goto_if_set FLAG_BATTLE_CAFE_TORNADUS_RECEIVED, BattleCafe_ChooseTornadus_2
BattleCafe_ChooseTornadus_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORNADUS
	setvar VAR_TEMP_B, 3
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTornadus_2:
	msgbox BattleCafe_ChooseTornadus_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTornadus_1


BattleCafe_ChooseThundurus::
	goto_if_set FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED, BattleCafe_ChooseThundurus_2
BattleCafe_ChooseThundurus_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_THUNDURUS
	setvar VAR_TEMP_B, 4
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseThundurus_2:
	msgbox BattleCafe_ChooseThundurus_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseThundurus_1


BattleCafe_ChooseLandorus::
	goto_if_set FLAG_BATTLE_CAFE_LANDORUS_RECEIVED, BattleCafe_ChooseLandorus_2
BattleCafe_ChooseLandorus_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LANDORUS
	setvar VAR_TEMP_B, 5
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseLandorus_2:
	msgbox BattleCafe_ChooseLandorus_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseLandorus_1


BattleCafe_ChooseEnamorus::
	goto_if_set FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED, BattleCafe_ChooseEnamorus_2
BattleCafe_ChooseEnamorus_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ENAMORUS
	setvar VAR_TEMP_B, 6
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseEnamorus_2:
	msgbox BattleCafe_ChooseEnamorus_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseEnamorus_1


BattleCafe_ChooseTapuKoko::
	goto_if_set FLAG_BATTLE_CAFE_TAPU_KOKO_RECEIVED, BattleCafe_ChooseTapuKoko_2
BattleCafe_ChooseTapuKoko_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_KOKO
	setvar VAR_TEMP_B, 7
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuKoko_2:
	msgbox BattleCafe_ChooseTapuKoko_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuKoko_1


BattleCafe_ChooseTapuLele::
	goto_if_set FLAG_BATTLE_CAFE_TAPU_LELE_RECEIVED, BattleCafe_ChooseTapuLele_2
BattleCafe_ChooseTapuLele_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_LELE
	setvar VAR_TEMP_B, 8
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuLele_2:
	msgbox BattleCafe_ChooseTapuLele_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuLele_1


BattleCafe_ChooseTapuBulu::
	goto_if_set FLAG_BATTLE_CAFE_TAPU_BULU_RECEIVED, BattleCafe_ChooseTapuBulu_2
BattleCafe_ChooseTapuBulu_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_BULU
	setvar VAR_TEMP_B, 9
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuBulu_2:
	msgbox BattleCafe_ChooseTapuBulu_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuBulu_1


BattleCafe_ChooseTapuFini::
	goto_if_set FLAG_BATTLE_CAFE_TAPU_FINI_RECEIVED, BattleCafe_ChooseTapuFini_2
BattleCafe_ChooseTapuFini_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_FINI
	setvar VAR_TEMP_B, 10
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuFini_2:
	msgbox BattleCafe_ChooseTapuFini_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuFini_1


BattleCafe_ConfirmRewardMon::
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ConfirmRewardMon_2
BattleCafe_ConfirmRewardMon_1:
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
	msgbox BattleCafe_ConfirmRewardMon_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ConfirmRewardMon_5
BattleCafe_ConfirmRewardMon_4:
	compare VAR_TEMP_B, 3
	goto_if_ge BattleCafe_ConfirmRewardMon_10
BattleCafe_ConfirmRewardMon_7:
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 70
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_ConfirmRewardMon_15
BattleCafe_ConfirmRewardMon_14:
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	subvar VAR_BATTLE_CAFE_POINTS, 5
	switch VAR_TEMP_B
	case 0, BattleCafe_ConfirmRewardMon_21
	case 1, BattleCafe_ConfirmRewardMon_22
	case 2, BattleCafe_ConfirmRewardMon_23
	case 3, BattleCafe_ConfirmRewardMon_24
	case 4, BattleCafe_ConfirmRewardMon_25
	case 5, BattleCafe_ConfirmRewardMon_26
	case 6, BattleCafe_ConfirmRewardMon_27
	case 7, BattleCafe_ConfirmRewardMon_28
	case 8, BattleCafe_ConfirmRewardMon_29
	case 9, BattleCafe_ConfirmRewardMon_30
	case 10, BattleCafe_ConfirmRewardMon_31
BattleCafe_ConfirmRewardMon_19:
	special Achievement_CheckAll
	compare VAR_TEMP_B, 3
	goto_if_ge BattleCafe_ConfirmRewardMon_34
BattleCafe_ConfirmRewardMon_32:
	msgbox BattleCafe_ConfirmRewardMon_Text_2
	goto BattleCafe_RewardMenu
	return

BattleCafe_ConfirmRewardMon_2:
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ConfirmRewardMon_1

BattleCafe_ConfirmRewardMon_5:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ConfirmRewardMon_4

BattleCafe_ConfirmRewardMon_8:
	checkitemspace ITEM_REVEAL_GLASS, 1
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_17
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_9:
	checkitem ITEM_REVEAL_GLASS
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_8
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_10:
	compare VAR_TEMP_B, 6
	goto_if_le BattleCafe_ConfirmRewardMon_9
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_15:
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_ConfirmRewardMon_14

BattleCafe_ConfirmRewardMon_17:
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_21:
	setflag FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_22:
	setflag FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_23:
	setflag FLAG_BATTLE_CAFE_MOLTRES_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_24:
	setflag FLAG_BATTLE_CAFE_TORNADUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_25:
	setflag FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_26:
	setflag FLAG_BATTLE_CAFE_LANDORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_27:
	setflag FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_28:
	setflag FLAG_BATTLE_CAFE_TAPU_KOKO_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_29:
	setflag FLAG_BATTLE_CAFE_TAPU_LELE_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_30:
	setflag FLAG_BATTLE_CAFE_TAPU_BULU_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_31:
	setflag FLAG_BATTLE_CAFE_TAPU_FINI_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_33:
	checkitem ITEM_REVEAL_GLASS
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_37
	goto BattleCafe_ConfirmRewardMon_32

BattleCafe_ConfirmRewardMon_34:
	compare VAR_TEMP_B, 6
	goto_if_le BattleCafe_ConfirmRewardMon_33
	goto BattleCafe_ConfirmRewardMon_32

BattleCafe_ConfirmRewardMon_37:
	msgbox BattleCafe_ConfirmRewardMon_Text_1
	giveitem ITEM_REVEAL_GLASS
	goto BattleCafe_ConfirmRewardMon_32


BattleCafe_ChooseMiraidon::
	goto_if_set FLAG_BATTLE_CAFE_MIRAIDON_RECEIVED, BattleCafe_ChooseMiraidon_2
BattleCafe_ChooseMiraidon_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MIRAIDON
	setvar VAR_TEMP_B, 0
	goto BattleCafe_ConfirmParadoxLegend
	return

BattleCafe_ChooseMiraidon_2:
	msgbox BattleCafe_ChooseMiraidon_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMiraidon_1


BattleCafe_ChooseKoraidon::
	goto_if_set FLAG_BATTLE_CAFE_KORAIDON_RECEIVED, BattleCafe_ChooseKoraidon_2
BattleCafe_ChooseKoraidon_1:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KORAIDON
	setvar VAR_TEMP_B, 1
	goto BattleCafe_ConfirmParadoxLegend
	return

BattleCafe_ChooseKoraidon_2:
	msgbox BattleCafe_ChooseKoraidon_Text_0
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseKoraidon_1


BattleCafe_ConfirmParadoxLegend::
	compare VAR_BATTLE_CAFE_POINTS, 25
	goto_if_lt BattleCafe_ConfirmParadoxLegend_2
BattleCafe_ConfirmParadoxLegend_1:
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
	msgbox BattleCafe_ConfirmParadoxLegend_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ConfirmParadoxLegend_5
BattleCafe_ConfirmParadoxLegend_4:
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 70
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_ConfirmParadoxLegend_8
BattleCafe_ConfirmParadoxLegend_7:
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	subvar VAR_BATTLE_CAFE_POINTS, 25
	switch VAR_TEMP_B
	case 0, BattleCafe_ConfirmParadoxLegend_12
	case 1, BattleCafe_ConfirmParadoxLegend_13
BattleCafe_ConfirmParadoxLegend_10:
	special Achievement_CheckAll
	msgbox BattleCafe_ConfirmParadoxLegend_Text_1
	goto BattleCafe_RewardMenu
	return

BattleCafe_ConfirmParadoxLegend_2:
	goto BattleCafe_NotEnoughLegendPoints
	goto BattleCafe_ConfirmParadoxLegend_1

BattleCafe_ConfirmParadoxLegend_5:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ConfirmParadoxLegend_4

BattleCafe_ConfirmParadoxLegend_8:
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_ConfirmParadoxLegend_7

BattleCafe_ConfirmParadoxLegend_12:
	setflag FLAG_BATTLE_CAFE_MIRAIDON_RECEIVED
	goto BattleCafe_ConfirmParadoxLegend_10

BattleCafe_ConfirmParadoxLegend_13:
	setflag FLAG_BATTLE_CAFE_KORAIDON_RECEIVED
	goto BattleCafe_ConfirmParadoxLegend_10


BattleCafe_ChooseShinyGenome::
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseShinyGenome_2
BattleCafe_ChooseShinyGenome_1:
	msgbox BattleCafe_ChooseShinyGenome_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseShinyGenome_5
BattleCafe_ChooseShinyGenome_4:
	checkitemspace ITEM_SHIN_GENOME, 1
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseShinyGenome_8
BattleCafe_ChooseShinyGenome_7:
	giveitem ITEM_SHIN_GENOME
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseShinyGenome_11
BattleCafe_ChooseShinyGenome_10:
	subvar VAR_BATTLE_CAFE_POINTS, 4
	msgbox BattleCafe_ChooseShinyGenome_Text_1
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseShinyGenome_2:
	goto BattleCafe_NotEnoughFourPoints
	goto BattleCafe_ChooseShinyGenome_1

BattleCafe_ChooseShinyGenome_5:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_4

BattleCafe_ChooseShinyGenome_8:
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseShinyGenome_7

BattleCafe_ChooseShinyGenome_11:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_10


BattleCafe_ChooseGoldBottleCaps::
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseGoldBottleCaps_2
BattleCafe_ChooseGoldBottleCaps_1:
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_5
BattleCafe_ChooseGoldBottleCaps_4:
	checkitemspace ITEM_GOLD_BOTTLE_CAP, 2
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseGoldBottleCaps_8
BattleCafe_ChooseGoldBottleCaps_7:
	giveitem ITEM_GOLD_BOTTLE_CAP, 2
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_11
BattleCafe_ChooseGoldBottleCaps_10:
	subvar VAR_BATTLE_CAFE_POINTS, 5
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_1
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseGoldBottleCaps_2:
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseGoldBottleCaps_1

BattleCafe_ChooseGoldBottleCaps_5:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_4

BattleCafe_ChooseGoldBottleCaps_8:
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseGoldBottleCaps_7

BattleCafe_ChooseGoldBottleCaps_11:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_10


BattleCafe_ChooseMoney::
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseMoney_2
BattleCafe_ChooseMoney_1:
	msgbox BattleCafe_ChooseMoney_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseMoney_5
BattleCafe_ChooseMoney_4:
	subvar VAR_BATTLE_CAFE_POINTS, 5
	showmoneybox 0, 0
	addmoney 250000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	hidemoneybox
	msgbox BattleCafe_ChooseMoney_Text_1
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseMoney_2:
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseMoney_1

BattleCafe_ChooseMoney_5:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoney_4


BattleCafe_ChooseVitaminSetAtk::
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseVitaminSetAtk_2
BattleCafe_ChooseVitaminSetAtk_1:
	msgbox BattleCafe_ChooseVitaminSetAtk_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetAtk_5
BattleCafe_ChooseVitaminSetAtk_4:
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_ATK
	special BattleCafe_TryPurchaseVitaminSet
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetAtk_8
BattleCafe_ChooseVitaminSetAtk_7:
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetAtk_11
BattleCafe_ChooseVitaminSetAtk_10:
	playse SE_SHOP
	waitse
	msgbox BattleCafe_ChooseVitaminSetAtk_Text_1
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetAtk_2:
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetAtk_1

BattleCafe_ChooseVitaminSetAtk_5:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetAtk_4

BattleCafe_ChooseVitaminSetAtk_8:
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetAtk_7

BattleCafe_ChooseVitaminSetAtk_11:
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetAtk_10


BattleCafe_ChooseVitaminSetDef::
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseVitaminSetDef_2
BattleCafe_ChooseVitaminSetDef_1:
	msgbox BattleCafe_ChooseVitaminSetDef_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetDef_5
BattleCafe_ChooseVitaminSetDef_4:
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_DEF
	special BattleCafe_TryPurchaseVitaminSet
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetDef_8
BattleCafe_ChooseVitaminSetDef_7:
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetDef_11
BattleCafe_ChooseVitaminSetDef_10:
	playse SE_SHOP
	waitse
	msgbox BattleCafe_ChooseVitaminSetDef_Text_1
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetDef_2:
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetDef_1

BattleCafe_ChooseVitaminSetDef_5:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetDef_4

BattleCafe_ChooseVitaminSetDef_8:
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetDef_7

BattleCafe_ChooseVitaminSetDef_11:
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetDef_10


BattleCafe_ChooseVitaminSetSpe::
	compare VAR_BATTLE_CAFE_POINTS, 2
	goto_if_lt BattleCafe_ChooseVitaminSetSpe_2
BattleCafe_ChooseVitaminSetSpe_1:
	msgbox BattleCafe_ChooseVitaminSetSpe_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetSpe_5
BattleCafe_ChooseVitaminSetSpe_4:
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_SPE
	special BattleCafe_TryPurchaseVitaminSet
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetSpe_8
BattleCafe_ChooseVitaminSetSpe_7:
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetSpe_11
BattleCafe_ChooseVitaminSetSpe_10:
	playse SE_SHOP
	waitse
	msgbox BattleCafe_ChooseVitaminSetSpe_Text_1
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetSpe_2:
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetSpe_1

BattleCafe_ChooseVitaminSetSpe_5:
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetSpe_4

BattleCafe_ChooseVitaminSetSpe_8:
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetSpe_7

BattleCafe_ChooseVitaminSetSpe_11:
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetSpe_10


BattleCafe_NotEnoughPoints::
	msgbox BattleCafe_NotEnoughPoints_Text_0
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughLegendPoints::
	msgbox BattleCafe_NotEnoughLegendPoints_Text_0
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughFourPoints::
	msgbox BattleCafe_NotEnoughFourPoints_Text_0
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughVitaminSetPoints::
	msgbox BattleCafe_NotEnoughVitaminSetPoints_Text_0
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughBagSpace::
	msgbox BattleCafe_NotEnoughBagSpace_Text_0
	goto BattleCafe_RewardMenu
	return


BattleCafe_Goodbye::
	msgbox BattleCafe_Goodbye_Text_0
	release
	end


BattleCafe_GiveDailyCandyReward::
	random 3
	addvar VAR_RESULT, 1
	giveitem ITEM_EXP_CANDY_XL, VAR_RESULT
	return


BattleCafe_TrainerAthena::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ATHENA, BattleCafe_TrainerAthena_2
	msgbox BattleCafe_TrainerAthena_Text_1
	trainerbattle_no_intro TRAINER_CAFE_ATHENA, BattleCafe_TrainerAthena_Text_2
	setflag FLAG_DAILY_BATTLE_CAFE_ATHENA
	msgbox BattleCafe_TrainerAthena_Text_3
	call BattleCafe_GiveDailyCandyReward
	release
	end

BattleCafe_TrainerAthena_2:
	msgbox BattleCafe_TrainerAthena_Text_0
	release
	end


BattleCafe_TrainerDoves::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DOVES, BattleCafe_TrainerDoves_2
	msgbox BattleCafe_TrainerDoves_Text_1
	trainerbattle_no_intro TRAINER_CAFE_DOVES, BattleCafe_TrainerDoves_Text_2
	setflag FLAG_DAILY_BATTLE_CAFE_DOVES
	msgbox BattleCafe_TrainerDoves_Text_0
	call BattleCafe_GiveDailyCandyReward
	release
	end

BattleCafe_TrainerDoves_2:
	msgbox BattleCafe_TrainerDoves_Text_0
	release
	end


BattleCafe_TrainerElton::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ELTON, BattleCafe_TrainerElton_2
	msgbox BattleCafe_TrainerElton_Text_1
	trainerbattle_no_intro TRAINER_CAFE_ELTON, BattleCafe_TrainerElton_Text_2
	setflag FLAG_DAILY_BATTLE_CAFE_ELTON
	msgbox BattleCafe_TrainerElton_Text_3
	call BattleCafe_GiveDailyCandyReward
	release
	end

BattleCafe_TrainerElton_2:
	msgbox BattleCafe_TrainerElton_Text_0
	release
	end


BattleCafe_TrainerNem::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_CAFE_NEM, BattleCafe_TrainerNem_2
	msgbox BattleCafe_TrainerNem_Text_1
	trainerbattle_no_intro TRAINER_CAFE_NEM, BattleCafe_TrainerNem_Text_2
	setflag FLAG_DAILY_BATTLE_CAFE_NEM
	msgbox BattleCafe_TrainerNem_Text_3
	call BattleCafe_GiveDailyCandyReward
	release
	end

BattleCafe_TrainerNem_2:
	msgbox BattleCafe_TrainerNem_Text_0
	release
	end


BattleCafe_TrainerBai::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_CAFE_BAI, BattleCafe_TrainerBai_2
	msgbox BattleCafe_TrainerBai_Text_1
	trainerbattle_no_intro TRAINER_CAFE_BAI, BattleCafe_TrainerBai_Text_2
	setflag FLAG_DAILY_BATTLE_CAFE_BAI
	msgbox BattleCafe_TrainerBai_Text_3
	call BattleCafe_GiveDailyCandyReward
	release
	end

BattleCafe_TrainerBai_2:
	msgbox BattleCafe_TrainerBai_Text_0
	release
	end


BattleCafe_TrainerDrac::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DRAC, BattleCafe_TrainerDrac_2
	msgbox BattleCafe_TrainerDrac_Text_1
	trainerbattle_no_intro TRAINER_CAFE_DRAC, BattleCafe_TrainerDrac_Text_2
	setflag FLAG_DAILY_BATTLE_CAFE_DRAC
	msgbox BattleCafe_TrainerDrac_Text_0
	call BattleCafe_GiveDailyCandyReward
	release
	end

BattleCafe_TrainerDrac_2:
	msgbox BattleCafe_TrainerDrac_Text_0
	release
	end


BattleCafe_TrainerSimpli::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SIMPLI, BattleCafe_TrainerSimpli_2
	msgbox BattleCafe_TrainerSimpli_Text_1
	trainerbattle_no_intro TRAINER_CAFE_JUNA, BattleCafe_TrainerSimpli_Text_2
	setflag FLAG_DAILY_BATTLE_CAFE_SIMPLI
	msgbox BattleCafe_TrainerSimpli_Text_3
	call BattleCafe_GiveDailyCandyReward
	release
	end

BattleCafe_TrainerSimpli_2:
	msgbox BattleCafe_TrainerSimpli_Text_0
	release
	end


BattleCafe_TrainerTylarie::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_CAFE_TYLARIE, BattleCafe_TrainerTylarie_2
	msgbox BattleCafe_TrainerTylarie_Text_1
	trainerbattle_no_intro TRAINER_CAFE_TYLARIE, BattleCafe_TrainerTylarie_Text_2
	setflag FLAG_DAILY_BATTLE_CAFE_TYLARIE
	msgbox BattleCafe_TrainerTylarie_Text_3
	call BattleCafe_GiveDailyCandyReward
	release
	end

BattleCafe_TrainerTylarie_2:
	msgbox BattleCafe_TrainerTylarie_Text_0
	release
	end


BattleCafe_FreshWaterFountain::
	goto_if_set FLAG_GOT_FRESH_WATER, BattleCafe_FreshWaterFountain_1
	lock
	msgbox BattleCafe_FreshWaterFountain_Text_1
	finditem ITEM_FRESH_WATER
	setflag FLAG_GOT_FRESH_WATER
	msgbox BattleCafe_FreshWaterFountain_Text_2
	release
	end

BattleCafe_FreshWaterFountain_1:
	msgbox BattleCafe_FreshWaterFountain_Text_0, MSGBOX_SIGN
	return


BattleCafe_GiveDiancie_Text_0:
	.string "哎呀，真了不起。您可把我的常客\n个个都至少赢过一次。\p那就该让您带走一位稀有的\n用餐伙伴——蒂安希！$"

BattleCafe_GiveDiancie_Text_1:
	.string "它就在这儿等着。您需要\n做什么准备都行，准备好了\l就来跟我说话，把它\l迎进队伍吧。$"

BattleCafe_GiveDiancie_Text_2:
	.string "蒂安希在等着您。\p您准备好收下它了吗？$"

BattleCafe_GiveDiancie_Text_3:
	.string "不着急。您什么时候\n准备好，蒂安希都在这儿。$"

BattleCafe_GiveDiancie_Text_4:
	.string "蒂安希给菜单增色不少。\n要好好照顾它！$"

BattleCafe_OwnerMenu_Text_0:
	.string "欢迎光临我的对战咖啡馆！\p我的厨艺和战斗本事，\n都是在老家伽勒尔练出来的。\p如今，我在城都把训练家们\n聚到一起，共享美食和\l精彩的对战。\p要是您能打赢这里所有的常客，\n还有一份特别的奖品。\p不过我得提醒您，这里的\n常客可都是硬茬子！\p好了，不说我了……$"

BattleCafe_OwnerMenu_Text_1:
	.string "看您打通了超级挑战，\n我可以再提供一个新模式：\p无尽挑战！$"

BattleCafe_OwnerMenu_Text_2:
	.string "看您征服了超级连战，\n我可以再提供最后一个模式：\p无尽连战！$"

BattleCafe_OwnerMenu_Text_3:
	.string "欢迎！今天想吃点什么？$"

BattleCafe_OwnerMenu_Text_4:
	.string "每日挑战$"

BattleCafe_OwnerMenu_Text_5:
	.string "连战模式$"

BattleCafe_OwnerMenu_Text_6:
	.string "超级挑战$"

BattleCafe_OwnerMenu_Text_7:
	.string "超级连战$"

BattleCafe_OwnerMenu_Text_8:
	.string "无尽模式$"

BattleCafe_OwnerMenu_Text_9:
	.string "积分兑换$"

BattleCafe_OwnerMenu_Text_10:
	.string "咖啡馆选项$"

BattleCafe_OwnerMenu_Text_11:
	.string "离开$"

BattleCafe_OptionsMenu_Text_0:
	.string "您想查看什么？$"

BattleCafe_OptionsMenu_Text_1:
	.string "战斗BGM$"

BattleCafe_OptionsMenu_Text_2:
	.string "最高分$"

BattleCafe_OptionsMenu_Text_3:
	.string "天赋特性$"

BattleCafe_OptionsMenu_Text_4:
	.string "咖啡馆规则$"

BattleCafe_OptionsMenu_Text_5:
	.string "返回$"

BattleCafe_ExplainRules_Text_0:
	.string "每次挑战会有三位咖啡馆来客\n轮番上阵。\p在每日挑战中，他们会带来\n可靠的4只宝可梦队伍。\p每场战斗后，我都会为您\n治疗宝可梦。\p连胜三场，可获得3点咖啡馆点数。$"

BattleCafe_ExplainRules_Text_1:
	.string "连战模式会招来身经百战的\n对手，队伍同样是4只。\p百无禁忌，而且战斗之间\n我不能为您治疗宝可梦。\p连胜三场，可获得5点咖啡馆点数。$"

BattleCafe_ExplainRules_Text_2:
	.string "超级挑战和超级连战，\n对手都是6只宝可梦的完整队伍。\p谁都可能出现，请做好\n应对一切的心理准备。\p轮间治疗规则与前面相同。$"

BattleCafe_ExplainRules_Text_3:
	.string "服务开始后就没有休息了。\p一旦落败，本次挑战就结束，\n不过在获胜前可以反复重试。\p每种挑战每天只能获胜一次。$"

BattleCafe_ExplainRules_Text_4:
	.string "无尽的两个模式都使用6只的\n完整队伍，直到您落败或\l选择退出为止。\p无尽挑战每赢一场都会治疗\n队伍，并获得1点咖啡馆点数。$"

BattleCafe_ExplainRules_Text_5:
	.string "无尽连战每三场胜利治疗\n一次队伍，每场胜利得2点。\p每种模式的最佳连胜纪录，\n都保存在最高分里。$"

BattleCafe_AskDailyChallenge_Text_0:
	.string "您今天已经通过了\n每日挑战。\p明天再来吧，\n或者试试其他挑战！$"

BattleCafe_AskDailyChallenge_Text_1:
	.string "三位咖啡馆来客已经准备好\n4只宝可梦的队伍。\p第一、二轮之后，\n我会为您治疗队伍。\p要开始今天的挑战吗？$"

BattleCafe_AskRushMode_Text_0:
	.string "您今天已经征服了\n连战模式。\p明天再来吧，或者\n换个挑战试试！$"

BattleCafe_AskRushMode_Text_1:
	.string "三位身经百战的来客\n带着4只队伍在等着。\p这些战斗之间，我无法\n为您治疗队伍。\p要开始今天的连战吗？$"

BattleCafe_AskSuperChallenge_Text_0:
	.string "您今天已经通过了\n超级挑战。\p明天再来吧，\n或者挑战其他项目！$"

BattleCafe_AskSuperChallenge_Text_1:
	.string "超级挑战要求每只宝可梦\n都上桌。进场前请带满\l6只宝可梦的队伍。$"

BattleCafe_AskSuperChallenge_Text_2:
	.string "三位来客各会用6只宝可梦\n迎战您的完整队伍。\p战斗之间，我会为您\n治疗队伍。\p要开始超级挑战吗？$"

BattleCafe_AskSuperRush_Text_0:
	.string "您今天已经征服了\n超级连战。\p明天再来体验\n又一场全队试炼吧！$"

BattleCafe_AskSuperRush_Text_1:
	.string "超级连战要求每只宝可梦\n都上桌。\p进场前请带满\n6只宝可梦的队伍。$"

BattleCafe_AskSuperRush_Text_2:
	.string "三位来客各会带来一支\n6只宝可梦的完整队伍。\p连战一旦开始，战斗之间\n我就不能为您治疗宝可梦了。\p要开始超级连战吗？$"

BattleCafe_EndlessMenu_Text_0:
	.string "您想试哪种无尽模式？$"

BattleCafe_EndlessMenu_Text_1:
	.string "无尽挑战$"

BattleCafe_EndlessMenu_Text_2:
	.string "无尽连战$"

BattleCafe_EndlessMenu_Text_3:
	.string "无尽规则$"

BattleCafe_ExplainEndlessRules_Text_0:
	.string "无尽挑战每胜一场\n都会治疗您的队伍。\p每场胜利立刻获得\n1点咖啡馆点数。\p通关超级挑战后解锁。$"

BattleCafe_ExplainEndlessRules_Text_1:
	.string "无尽连战每三场胜利\n治疗一次队伍。\p每场胜利立刻获得\n2点咖啡馆点数。\p通关超级连战解锁。$"

BattleCafe_ExplainEndlessRules_Text_2:
	.string "两种模式都是6对6的完整对战。\n任何一场胜利后都可以退出，\l最佳连胜纪录会被保存。$"

BattleCafe_AskEndlessChallenge_Text_0:
	.string "通关超级挑战，\n即可解锁无尽挑战。$"

BattleCafe_AskEndlessChallenge_Text_1:
	.string "无尽模式的每位对手\n都会带上6只宝可梦。\p就座前请带满\n6只宝可梦的队伍。$"

BattleCafe_AskEndlessChallenge_Text_2:
	.string "6只的完整队伍会一直\n涌来，直到您落败或退出。\p每场胜利后我都会治疗队伍，\n每场胜利得1点咖啡馆点数。\p要开始无尽挑战吗？$"

BattleCafe_AskEndlessRush_Text_0:
	.string "通关超级连战，\n即可解锁无尽连战。$"

BattleCafe_AskEndlessRush_Text_1:
	.string "6只的完整队伍会一直\n涌来，直到您落败或退出。\p每三场胜利治疗一次队伍。\n每场胜利得2点咖啡馆点数。\p要开始无尽连战吗？$"

BattleCafe_BeginChallenge_Text_0:
	.string "没有最后一道菜。没有最后的对手。\n无尽服务现在开始！$"

BattleCafe_BeginChallenge_Text_1:
	.string "三道菜。三位对手。\n服务现在开始！$"

BattleCafe_ChallengeNextRound_Text_0:
	.string "胜利！连胜：{STR_VAR_1}。\n获得{STR_VAR_2}点咖啡馆点数，\l队伍已恢复。\p要继续挑战吗？$"

BattleCafe_ChallengeNextRound_Text_1:
	.string "胜利！连胜：{STR_VAR_1}。\n获得{STR_VAR_2}点咖啡馆点数。\p三场战斗已通过！队伍\n已恢复。要继续挑战吗？$"

BattleCafe_ChallengeNextRound_Text_2:
	.string "胜利！连胜：{STR_VAR_1}。\n获得{STR_VAR_2}点咖啡馆点数。\p队伍尚未恢复。\n要继续挑战吗？$"

BattleCafe_ChallengeNextRound_Text_3:
	.string "队伍已恢复。\n下一位挑战者马上就到！$"

BattleCafe_ChallengeNextRound_Text_4:
	.string "队伍已恢复。\n下一支完整队伍马上就到！$"

BattleCafe_ChallengeNextRound_Text_5:
	.string "超级连战不提供治疗！\n下一支完整队伍马上就到！$"

BattleCafe_ChallengeNextRound_Text_6:
	.string "连战模式不提供治疗！\n下一位挑战者马上就到！$"

BattleCafe_EndlessRetired_Text_0:
	.string "您在{STR_VAR_1}连胜时退出了。\p您的队伍已完全恢复，纪录\n保留，所有点数都归您。$"

BattleCafe_ChallengeLost_Text_0:
	.string "您的无尽挑战止于{STR_VAR_1}\n连胜。我已经\l把您的队伍完全治疗好了。\p您赚到的咖啡馆点数都归您。\n下次试着走得更远吧！$"

BattleCafe_ChallengeLost_Text_1:
	.string "这顿套餐够呛吧？我已经\n把您的队伍完全治疗好了。\p您先喘口气，重新想想\n战术，随时都可以\l再来挑战！$"

BattleCafe_ChallengeWon_Text_0:
	.string "每日挑战完成！\p这是给您的{STR_VAR_1}点\n咖啡馆点数。$"

BattleCafe_ChallengeWon_Text_1:
	.string "连战模式完成！真是\n一场硬仗。\p这是{STR_VAR_1}点咖啡馆点数。$"

BattleCafe_ChallengeWon_Text_2:
	.string "超级挑战完成！\n全队出战，全力以赴！\p这是给您的{STR_VAR_1}点\n咖啡馆点数。$"

BattleCafe_ChallengeWon_Text_3:
	.string "太惊人了！您打通了\n超级连战模式！\p我简直不敢相信！\p这是给您的奖励：\n{STR_VAR_1}点咖啡馆点数。$"

BattleCafe_RewardMenu_Text_0:
	.string "您有{STR_VAR_1}点咖啡馆点数。\n有什么想兑换的吗？$"

BattleCafe_RewardMenu_Text_1:
	.string "攻击增强剂套装 - 4$"

BattleCafe_RewardMenu_Text_2:
	.string "防御增强剂套装 - 4$"

BattleCafe_RewardMenu_Text_3:
	.string "速度增强剂套装 - 2$"

BattleCafe_RewardMenu_Text_4:
	.string "异色基因 - 4$"

BattleCafe_RewardMenu_Text_5:
	.string "金色王冠×2 - 5$"

BattleCafe_RewardMenu_Text_6:
	.string "¥250,000 - 5$"

BattleCafe_RewardMenu_Text_7:
	.string "伽勒尔急冻鸟 - 5$"

BattleCafe_RewardMenu_Text_8:
	.string "伽勒尔闪电鸟 - 5$"

BattleCafe_RewardMenu_Text_9:
	.string "伽勒尔火焰鸟 - 5$"

BattleCafe_RewardMenu_Text_10:
	.string "龙卷云 - 5$"

BattleCafe_RewardMenu_Text_11:
	.string "雷电云 - 5$"

BattleCafe_RewardMenu_Text_12:
	.string "土地云 - 5$"

BattleCafe_RewardMenu_Text_13:
	.string "眷恋云 - 5$"

BattleCafe_RewardMenu_Text_14:
	.string "卡璞・鸣鸣 - 5$"

BattleCafe_RewardMenu_Text_15:
	.string "卡璞・蝶蝶 - 5$"

BattleCafe_RewardMenu_Text_16:
	.string "卡璞・哞哞 - 5$"

BattleCafe_RewardMenu_Text_17:
	.string "卡璞・鳍鳍 - 5$"

BattleCafe_RewardMenu_Text_18:
	.string "密勒顿 - 25$"

BattleCafe_RewardMenu_Text_19:
	.string "故勒顿 - 25$"

BattleCafe_ChooseArticuno_Text_0:
	.string "我已经\n把伽勒尔急冻鸟托付给您了。$"

BattleCafe_ChooseZapdos_Text_0:
	.string "我已经\n把伽勒尔闪电鸟托付给您了。$"

BattleCafe_ChooseMoltres_Text_0:
	.string "我已经\n把伽勒尔火焰鸟托付给您了。$"

BattleCafe_ChooseTornadus_Text_0:
	.string "我已经把龙卷云\n托付给您了。$"

BattleCafe_ChooseThundurus_Text_0:
	.string "我已经把雷电云\n托付给您了。$"

BattleCafe_ChooseLandorus_Text_0:
	.string "我已经把土地云\n托付给您了。$"

BattleCafe_ChooseEnamorus_Text_0:
	.string "我已经把眷恋云\n托付给您了。$"

BattleCafe_ChooseTapuKoko_Text_0:
	.string "我已经把卡璞・鸣鸣\n托付给您了。$"

BattleCafe_ChooseTapuLele_Text_0:
	.string "我已经把卡璞・蝶蝶\n托付给您了。$"

BattleCafe_ChooseTapuBulu_Text_0:
	.string "我已经把卡璞・哞哞\n托付给您了。$"

BattleCafe_ChooseTapuFini_Text_0:
	.string "我已经把卡璞・鳍鳍\n托付给您了。$"

BattleCafe_ConfirmRewardMon_Text_0:
	.string "用5点咖啡馆点数\n兑换{STR_VAR_1}吗？$"

BattleCafe_ConfirmRewardMon_Text_1:
	.string "这个也许对您有用。$"

BattleCafe_ConfirmRewardMon_Text_2:
	.string "很划算的交易。它一定会\n和您的队伍很合拍。$"

BattleCafe_ChooseMiraidon_Text_0:
	.string "我已经把密勒顿\n托付给您了。$"

BattleCafe_ChooseKoraidon_Text_0:
	.string "我已经把故勒顿\n托付给您了。$"

BattleCafe_ConfirmParadoxLegend_Text_0:
	.string "用25点咖啡馆点数\n兑换{STR_VAR_1}吗？$"

BattleCafe_ConfirmParadoxLegend_Text_1:
	.string "这是来自帕底亚的稀有\n个体。好好照顾它！$"

BattleCafe_ChooseShinyGenome_Text_0:
	.string "用4点咖啡馆点数\n兑换一个异色基因吗？$"

BattleCafe_ChooseShinyGenome_Text_1:
	.string "稀有的宝贝。用在您想\n让它闪闪发光的\l宝可梦身上吧。$"

BattleCafe_ChooseGoldBottleCaps_Text_0:
	.string "用5点咖啡馆点数\n兑换2个金色王冠吗？$"

BattleCafe_ChooseGoldBottleCaps_Text_1:
	.string "2个金色王冠，已经打磨好，\n随时可用。拿去吧！$"

BattleCafe_ChooseMoney_Text_0:
	.string "用5点咖啡馆点数\n兑换¥250,000吗？$"

BattleCafe_ChooseMoney_Text_1:
	.string "好好用它，也许还可以\n分一点买甜点！$"

BattleCafe_ChooseVitaminSetAtk_Text_0:
	.string "用4点咖啡馆点数兑换\n攻击增强剂EX和特攻增强剂EX\l各2个吗？$"

BattleCafe_ChooseVitaminSetAtk_Text_1:
	.string "攻击增强剂EX和特攻增强剂EX\n各2个，力量与智慧！$"

BattleCafe_ChooseVitaminSetDef_Text_0:
	.string "用4点咖啡馆点数兑换\n防御增强剂EX和特防增强剂EX\l各2个吗？$"

BattleCafe_ChooseVitaminSetDef_Text_1:
	.string "防御增强剂EX和特防增强剂EX\n各2个，该变得结实了！$"

BattleCafe_ChooseVitaminSetSpe_Text_0:
	.string "用2点咖啡馆点数\n兑换2个速度增强剂EX吗？$"

BattleCafe_ChooseVitaminSetSpe_Text_1:
	.string "2个速度增强剂EX，准备加速！$"

BattleCafe_NotEnoughPoints_Text_0:
	.string "那件奖品要5点咖啡馆点数。\n完成我的一项挑战后\l再来试试！$"

BattleCafe_NotEnoughLegendPoints_Text_0:
	.string "那个奖品要25点咖啡馆点数。\n再多完成些挑战，然后再来！$"

BattleCafe_NotEnoughFourPoints_Text_0:
	.string "异色基因要4点咖啡馆点数。\n完成一次挑战再来吧！$"

BattleCafe_NotEnoughVitaminSetPoints_Text_0:
	.string "您的咖啡馆点数不够\n换那套增强剂。\p再多完成些挑战，\n然后再来吧！$"

BattleCafe_NotEnoughBagSpace_Text_0:
	.string "您的背包放不下那个奖品。\n腾出些空间，准备好了再来！$"

BattleCafe_Goodbye_Text_0:
	.string "欢迎再回来，带着再战的胃口！$"

BattleCafe_TrainerAthena_Text_0:
	.string "玩得开心吗？明天我们再\n打一场吧！$"

BattleCafe_TrainerAthena_Text_1:
	.string "看看你能不能扛住我这套\n消耗战术！$"

BattleCafe_TrainerAthena_Text_2:
	.string "咦？$"

BattleCafe_TrainerAthena_Text_3:
	.string "玩得开心吗？$"

BattleCafe_TrainerDoves_Text_0:
	.string "多夫斯：等明天我的盖诺赛克特\n能上场了，我们再打一场。$"

BattleCafe_TrainerDoves_Text_1:
	.string "多夫斯：让你见识一下\n盖诺赛克特的实力！$"

BattleCafe_TrainerDoves_Text_2:
	.string "又因为太强被禁赛了……$"

BattleCafe_TrainerElton_Text_0:
	.string "埃尔顿：明天再战！一定要来！$"

BattleCafe_TrainerElton_Text_1:
	.string "埃尔顿：用我们最喜欢的宝可梦\n来打一场吧！$"

BattleCafe_TrainerElton_Text_2:
	.string "我的花招全被你破解了！$"

BattleCafe_TrainerElton_Text_3:
	.string "埃尔顿：连耿鬼都服气了，\n它可是很少把输当回事的。$"

BattleCafe_TrainerNem_Text_0:
	.string "内姆：明天再来。$"

BattleCafe_TrainerNem_Text_1:
	.string "内姆：接招吧！$"

BattleCafe_TrainerNem_Text_2:
	.string "我会盯着你的。$"

BattleCafe_TrainerNem_Text_3:
	.string "内姆：明天还能再打。$"

BattleCafe_TrainerBai_Text_0:
	.string "拜伊：打得真不错！\n明天再打一场吧！$"

BattleCafe_TrainerBai_Text_1:
	.string "拜伊：让我看看你能拿出\n什么本事来！$"

BattleCafe_TrainerBai_Text_2:
	.string "这下可真是被你炖熟了……$"

BattleCafe_TrainerBai_Text_3:
	.string "拜伊：打得真不错！\n明天再来一场吧！$"

BattleCafe_TrainerDrac_Text_0:
	.string "德拉克：你真厉害！\n明天再打一场吧！$"

BattleCafe_TrainerDrac_Text_1:
	.string "德拉克：要不要来场双打？$"

BattleCafe_TrainerDrac_Text_2:
	.string "消气了。$"

BattleCafe_TrainerSimpli_Text_0:
	.string "明天一定会更好。$"

BattleCafe_TrainerSimpli_Text_1:
	.string "来和雨天赌一把吧！$"

BattleCafe_TrainerSimpli_Text_2:
	.string "被风雨磨垮了……$"

BattleCafe_TrainerSimpli_Text_3:
	.string "明天也许会好一些。$"

BattleCafe_TrainerTylarie_Text_0:
	.string "大钢蛇已经安顿下来吃午饭了。\n明天我们就能准备好！$"

BattleCafe_TrainerTylarie_Text_1:
	.string "泰拉莉：让你看看我的队伍\n有多结实！$"

BattleCafe_TrainerTylarie_Text_2:
	.string "哎哟。$"

BattleCafe_TrainerTylarie_Text_3:
	.string "泰拉莉：不错嘛。改天我们\n再比一场。$"

BattleCafe_FreshWaterFountain_Text_0:
	.string "是一小座喷泉。$"

BattleCafe_FreshWaterFountain_Text_1:
	.string "您从喷泉里接了些\n清凉的水。$"

BattleCafe_FreshWaterFountain_Text_2:
	.string "注意补水。$"
