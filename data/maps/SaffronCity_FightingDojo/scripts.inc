.set LOCALID_DOJO_LICKILICKY, 1
.set LOCALID_DOJO_MACHAMP, 2
.set LOCALID_DOJO_STEELIX, 3
.set LOCALID_DOJO_ALAKAZAM, 4
.set LOCALID_DOJO_SLOWKING, 5
.set LOCALID_DOJO_RAICHU, 6

SaffronCity_FightingDojo_MapScripts::
	.byte 0

SaffronCity_FightingDojo_EventScript_StatueLeft::
	msgbox SaffronCity_FightingDojo_Text_Sign1, MSGBOX_SIGN
	end
SaffronCity_FightingDojo_EventScript_StatueRight::
	msgbox SaffronCity_FightingDojo_Text_Sign2, MSGBOX_SIGN
	end

SaffronCity_FightingDojo_EventScript_BlackBelt::
	msgbox SaffronCity_FightingDojo_Text_BlackBelt, MSGBOX_NPC
	end

SaffronCity_FightingDojo_EventScript_Cooltrainer::
	msgbox SaffronCity_FightingDojo_Text_Cooltrainer, MSGBOX_NPC
	end

SaffronCity_FightingDojo_EventScript_Refused::
	closemessage
	release
	end

SaffronCity_FightingDojo_EventScript_Lickilicky_EV_HP::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LICKILICKY, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Lickilicky, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_1, SaffronCity_FightingDojo_EventScript_BattleLickilicky_EV_HP
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_LICKILICKY
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_HP
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleLickilicky_EV_HP::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_GARBAGEFLAG
	setwildbattle SPECIES_LICKILICKY, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_TEMP_1
	release
	end
	
SaffronCity_FightingDojo_Text_Lickilicky:
	.string "大舌舔：舔——！$"

SaffronCity_FightingDojo_EventScript_Machamp_EV_Attack::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Machamp, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_2, SaffronCity_FightingDojo_EventScript_BattleMachamp_EV_Attack
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_MACHAMP
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_Attack
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleMachamp_EV_Attack::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_GARBAGEFLAG
	setwildbattle SPECIES_MACHAMP, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_TEMP_2
	release
	end

SaffronCity_FightingDojo_Text_Machamp:
	.string "怪力：恰姆！$"

SaffronCity_FightingDojo_EventScript_Steelix_EV_Defense::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Steelix, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_3, SaffronCity_FightingDojo_EventScript_BattleSteelix_EV_Defense
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_STEELIX
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_Defense
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleSteelix_EV_Defense::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_GARBAGEFLAG
	setwildbattle SPECIES_STEELIX, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_TEMP_3
	release
	end

SaffronCity_FightingDojo_Text_Steelix:
	.string "大钢蛇：嘎隆隆！$"

SaffronCity_FightingDojo_EventScript_Alakazam_EV_SpecialAttack::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Alakazam, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_4, SaffronCity_FightingDojo_EventScript_BattleAlakazam_EV_SpecialAttack
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_ALAKAZAM
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_SpecialAttack
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleAlakazam_EV_SpecialAttack::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_GARBAGEFLAG
	setwildbattle SPECIES_ALAKAZAM, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_TEMP_4
	release
	end

SaffronCity_FightingDojo_Text_Alakazam:
	.string "胡地：嗡姆！$"

SaffronCity_FightingDojo_EventScript_Slowking_EV_SpecialDefense::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Slowking, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_5, SaffronCity_FightingDojo_EventScript_BattleSlowking_EV_SpecialDefense
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_SLOWKING
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_SpecialDefense
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleSlowking_EV_SpecialDefense::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_GARBAGEFLAG
	setwildbattle SPECIES_SLOWKING, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_TEMP_5
	release
	end

SaffronCity_FightingDojo_Text_Slowking:
	.string "呆呆王：嗯姆……$"

SaffronCity_FightingDojo_EventScript_Raichu_EV_Speed::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Raichu, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_6, SaffronCity_FightingDojo_EventScript_BattleRaichu_EV_Speed
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_RAICHU
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_Speed
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleRaichu_EV_Speed::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_GARBAGEFLAG
	setwildbattle SPECIES_RAICHU, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_TEMP_6
	release
	end

SaffronCity_FightingDojo_Text_Raichu:
	.string "雷丘：啾——！$"

SaffronCity_FightingDojo_Text_HP:
	.string "HP$"
SaffronCity_FightingDojo_Text_Attack:
	.string "攻击$"
SaffronCity_FightingDojo_Text_Defense:
	.string "防御$"
SaffronCity_FightingDojo_Text_SpecialAttack:
	.string "特攻$"
SaffronCity_FightingDojo_Text_SpecialDefense:
	.string "特防$"
SaffronCity_FightingDojo_Text_Speed:
	.string "速度$"

SaffronCity_FightingDojo_Text_WouldYouLikeToBattle:
	.string "和{STR_VAR_1}对战，\n获得3点{STR_VAR_2}基础点数？$"

SaffronCity_FightingDojo_Text_BlackBelt:
	.string "你走进了格斗道场！\p在这里，你可以通过对战\n锻炼宝可梦的能力！$"
	.string ""
	.string ""

SaffronCity_FightingDojo_Text_Sign1:
	.string "左侧：HP、防御、特防$"

SaffronCity_FightingDojo_Text_Sign2:
	.string "右侧：攻击、特攻、速度$"

SaffronCity_FightingDojo_Text_Cooltrainer::
	.string "集齐关都徽章的训练家\n方可进入VIP休息室。$"
	.string ""

@Ability swapper

SaffronCity_FightingDojo_Ability_Man::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojo_Ability_Text1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_FightingDojo_Ability_CheckMoney
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_FightingDojo_Ability_No
	end

SaffronCity_FightingDojo_Ability_No:
	msgbox SaffronCity_FightingDojo_Ability_Text_No, MSGBOX_DEFAULT
	waitmessage
	release
	end

SaffronCity_FightingDojo_SetZeroNoMoney::
	msgbox SaffronCity_FightingDojo_SetZeroTextNoMoney, MSGBOX_DEFAULT
	waitmessage
	release
	end

SaffronCity_FightingDojo_Ability_CheckMoney:
	checkmoney 25000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq SaffronCity_FightingDojo_Ability_Continue
	compare VAR_RESULT, FALSE
	goto_if_eq SaffronCity_FightingDojo_SetZeroNoMoney
	end

SaffronCity_FightingDojo_Ability_Continue:
	closemessage
	special ChoosePartyMon
	waitstate
	@special SwitchMonAbility
	compare VAR_RESULT, TRUE
	goto_if_eq SaffronCity_FightingDojo_Ability_Finish
	compare VAR_RESULT, FALSE
	goto_if_eq SaffronCity_FightingDojo_Ability_Cant
	end

SaffronCity_FightingDojo_Ability_Cant:
	msgbox SaffronCity_FightingDojo_Ability_Text_Cant, MSGBOX_DEFAULT
	waitmessage
	release
	end

SaffronCity_FightingDojo_Ability_Finish:
	fadescreen 0x1
	delay 100
	fadescreen 0x0
	faceplayer
	waitse
	playse SE_EXP_MAX
	msgbox SaffronCity_FightingDojo_Ability_Finish_Text, MSGBOX_DEFAULT
	removemoney 25000, 0
	closemessage
	release
	end

SaffronCity_FightingDojo_Ability_Finish_Text:
	.string "好了！不用谢！$"

SaffronCity_FightingDojo_Ability_Text1:
	.string "欢迎！我是特性专家！\p只要¥25,000，我就能\n瞬间替换宝可梦的特性！\p要替换哪只宝可梦的\n特性吗？$"
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojo_Ability_Text_No:
	.string "好的。需要我时就来找我。$"

SaffronCity_FightingDojo_Ability_Text_Cant:
	.string "这我可办不到。这只宝可梦\n没有第二种特性！$"
	.string ""

SaffronCity_FightingDojo_Ability_Text_NoChampion:
	.string "欢迎！我是特性专家！\p我能在转眼之间替换\n宝可梦的特性。\p不巧，我今天腰疼，\n没法干活。\p下次再来吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_FightingDojo_SetZeroTextNoMoney:
	.string "您的钱不够。\p等钱够了再来吧。$"
	.string ""

