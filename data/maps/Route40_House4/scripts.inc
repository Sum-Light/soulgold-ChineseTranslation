Route40_House4_MapScripts::
	.byte 0


AchievementGuy::
	lock
	faceplayer
	msgbox AchievementGuy_Text_0
	special GetCompletedAchievementsCount
	copyvar VAR_TEMP_0, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_TEMP_0
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 15
	goto_if_lt AchievementGuy_3
AchievementGuy_1:
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 30
	goto_if_lt AchievementGuy_8
AchievementGuy_6:
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 45
	goto_if_lt AchievementGuy_13
AchievementGuy_11:
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 60
	goto_if_lt AchievementGuy_18
AchievementGuy_16:
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 75
	goto_if_lt AchievementGuy_23
AchievementGuy_21:
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 100
	goto_if_lt AchievementGuy_28
AchievementGuy_26:
	compare VAR_TEMP_0, 100
	goto_if_ge AchievementGuy_32
	setvar VAR_TEMP_1, 15
	compare VAR_TEMP_0, 15
	goto_if_ge AchievementGuy_35
AchievementGuy_34:
	compare VAR_TEMP_0, 30
	goto_if_ge AchievementGuy_38
AchievementGuy_37:
	compare VAR_TEMP_0, 45
	goto_if_ge AchievementGuy_41
AchievementGuy_40:
	compare VAR_TEMP_0, 60
	goto_if_ge AchievementGuy_44
AchievementGuy_43:
	compare VAR_TEMP_0, 75
	goto_if_ge AchievementGuy_47
AchievementGuy_46:
	copyvar VAR_TEMP_2, VAR_TEMP_1
	subvar VAR_TEMP_2, VAR_TEMP_0
	buffernumberstring STR_VAR_2, VAR_TEMP_2
	msgbox AchievementGuy_Text_2
	release
	end

AchievementGuy_2:
	goto AchievementGuy_Reward15
	goto AchievementGuy_1

AchievementGuy_3:
	compare VAR_TEMP_0, 15
	goto_if_ge AchievementGuy_2
	goto AchievementGuy_1

AchievementGuy_7:
	goto AchievementGuy_Reward30
	goto AchievementGuy_6

AchievementGuy_8:
	compare VAR_TEMP_0, 30
	goto_if_ge AchievementGuy_7
	goto AchievementGuy_6

AchievementGuy_12:
	goto AchievementGuy_Reward45
	goto AchievementGuy_11

AchievementGuy_13:
	compare VAR_TEMP_0, 45
	goto_if_ge AchievementGuy_12
	goto AchievementGuy_11

AchievementGuy_17:
	goto AchievementGuy_Reward60
	goto AchievementGuy_16

AchievementGuy_18:
	compare VAR_TEMP_0, 60
	goto_if_ge AchievementGuy_17
	goto AchievementGuy_16

AchievementGuy_22:
	goto AchievementGuy_Reward75
	goto AchievementGuy_21

AchievementGuy_23:
	compare VAR_TEMP_0, 75
	goto_if_ge AchievementGuy_22
	goto AchievementGuy_21

AchievementGuy_27:
	goto AchievementGuy_Reward100
	goto AchievementGuy_26

AchievementGuy_28:
	compare VAR_TEMP_0, 100
	goto_if_ge AchievementGuy_27
	goto AchievementGuy_26

AchievementGuy_32:
	msgbox AchievementGuy_Text_1
	release
	end

AchievementGuy_35:
	setvar VAR_TEMP_1, 30
	goto AchievementGuy_34

AchievementGuy_38:
	setvar VAR_TEMP_1, 45
	goto AchievementGuy_37

AchievementGuy_41:
	setvar VAR_TEMP_1, 60
	goto AchievementGuy_40

AchievementGuy_44:
	setvar VAR_TEMP_1, 75
	goto AchievementGuy_43

AchievementGuy_47:
	setvar VAR_TEMP_1, 100
	goto AchievementGuy_46


keepUpTheGoodWork::
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox keepUpTheGoodWork_Text_0
	release
	end


AchievementGuy_Reward15::
	msgbox AchievementGuy_Reward15_Text_0
	giveitem ITEM_SHIN_GENOME
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 15
	goto keepUpTheGoodWork
	release
	end


AchievementGuy_Reward30::
	msgbox AchievementGuy_Reward30_Text_0
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GRENINJA_BOND
	bufferspeciesname STR_VAR_1, SPECIES_GRENINJA_BOND
	givemon SPECIES_GRENINJA_BOND, 36
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 30
	goto keepUpTheGoodWork
	release
	end


AchievementGuy_Reward45::
	msgbox AchievementGuy_Reward45_Text_0
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_POIPOLE
	bufferspeciesname STR_VAR_1, SPECIES_POIPOLE
	givemon SPECIES_POIPOLE, 5
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 45
	goto keepUpTheGoodWork
	release
	end


AchievementGuy_Reward60::
	msgbox AchievementGuy_Reward60_Text_0
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FLOETTE_ETERNAL
	bufferspeciesname STR_VAR_1, SPECIES_FLOETTE_ETERNAL
	givemon SPECIES_FLOETTE_ETERNAL, 30
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 60
	goto keepUpTheGoodWork
	release
	end


AchievementGuy_Reward75::
	msgbox AchievementGuy_Reward75_Text_0
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZARUDE
	bufferspeciesname STR_VAR_1, SPECIES_ZARUDE
	givemon SPECIES_ZARUDE, 50
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 75
	goto keepUpTheGoodWork
	release
	end


AchievementGuy_Reward100::
	msgbox AchievementGuy_Reward100_Text_0
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MAGEARNA_ORIGINAL
	bufferspeciesname STR_VAR_1, SPECIES_MAGEARNA_ORIGINAL
	givemon SPECIES_MAGEARNA_ORIGINAL, 80
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 100
	goto keepUpTheGoodWork
	release
	end


AchievementGuy_Text_0:
	.string "我这辈子已经取得了很多成就。\n现在，我想看看年轻一代\l能做些什么。\p让我好好看看你……$"

AchievementGuy_Text_1:
	.string "你已经取得了全部成就！\n我再没有什么可以授予你了，\l真正的宝可梦大师。$"

AchievementGuy_Text_2:
	.string "嗯……\n你目前为止已经取得了\l{STR_VAR_1}项成就！\p再取得{STR_VAR_2}项成就，\n我或许就有东西给你了！$"

keepUpTheGoodWork_Text_0:
	.string "永远不要停止向更高处攀登。\n我期待着看到你\l接下来会做些什么。$"

AchievementGuy_Reward15_Text_0:
	.string "嗯！\p你至少已经取得了\n{STR_VAR_1}项成就！\p开局不错！这个就作为奖励\n授予你吧！$"

AchievementGuy_Reward30_Text_0:
	.string "太出色了！\p你已经取得了{STR_VAR_1}项成就，\n在旅程中又迈进了\l新的一步！\p我有件好东西给你！$"

AchievementGuy_Reward45_Text_0:
	.string "太棒了！\p你已经取得了{STR_VAR_1}项成就，\n抵达了下一个\l里程碑！\p我有件好东西给你！$"

AchievementGuy_Reward60_Text_0:
	.string "哇！你已经取得了\n{STR_VAR_1}项成就，\l在城都地区也小有名气了！\p我有样东西给你，\n纪念这份成就！$"

AchievementGuy_Reward75_Text_0:
	.string "难以置信！\p你已经取得了{STR_VAR_1}项成就，\n抵达了下一个\l里程碑！\p这是专门给你的另一份奖励！$"

AchievementGuy_Reward100_Text_0:
	.string "了不起！\p你已经取得了{STR_VAR_1}项成就，\n抵达了我最后的\l里程碑！\p这些是我最后能给你的东西，\n再没有别的了！$"
