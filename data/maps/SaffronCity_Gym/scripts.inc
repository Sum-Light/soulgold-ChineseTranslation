SaffronCity_Gym_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers
	closemessage
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "娜姿：我知道你会来……\p三年前，我曾预见\n你的到来。\p你是为我的徽章而来的。\p我不喜欢对战，但身为馆主，\n把徽章授予\l证明了自己实力的人，\l是我的职责。\p既然你希望如此，我就让你\n见识我的超能力！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "娜姿：你的实力……\p远远超出了我的预知……\p也许未来本就\n无法完全预测吧……\p好吧，你赢了。你为自己\n赢得了金色徽章。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER}得到了金色徽章。$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "娜姿：金色徽章会引出\n你潜在的能力……\p虽然我没能准确预知\n你的实力，但这一点\l我确信无疑。\p你将成为一位备受赞誉、\n深受爱戴的冠军！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "娜姿：你对宝可梦的爱\n压过了我的\l超能力……\p我认为，爱的力量\n也是一种超能力……$"
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_Gym_Text_SabrinaRematch:
	.string "娜姿：啊，关都冠军。\p我感应到你的归来了。\p你的力量已经大幅成长。\p直到现在，我仍能感到你的气场。\p要不要再和我打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "娜姿：你对宝可梦的爱\n又一次压过了我的\l超能力……$"
	.string ""
	.string ""

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "被你打败的每一个对手，\n他们的力量都汇聚到我这里！$"
	.string ""

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "好强……实在太强了……$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "你的力量究竟从何而来？$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "超能力就是灵魂的\n力量。$"
	.string ""

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "你的灵魂比我的\n更有力量！$"
	.string ""

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "你让自己的灵魂变强了，\n而不只是能力。$"
	.string ""

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "嘻嘻嘻……我看得很清楚。\p我能看透你的灵魂！$"
	.string ""

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "就算看透了，我还是输了……$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "哎呀！我忘了自己早就\n预见到会输给你了。$"
	.string ""

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "隔壁的格斗道场\n曾是这座城市的道馆。$"
	.string ""

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "我完全不是对手……$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "格斗道场的师傅\n空手道大王，\l被娜姿打得一败涂地。$"
	.string ""
	.string ""

SaffronCity_Gym_Text_GymGuideIntro:
	.string "哟，未来的冠军！\p像你这么有本事的训练家，\n该知道怎么对付\l超能力属性的宝可梦，\l不用我说吧？\p我很看好你！\p祝你好运！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SaffronCity_Gym_Text_GymGuideWin:
	.string "又是一场精彩的战斗！$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_GARBAGEFLAG, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
    .string "金黄宝可梦道馆\n馆主：娜姿\p优胜训练家：\n青绿、赤红$"
    .string ""
	.string ""
	.string ""

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "金黄宝可梦道馆\n馆主：娜姿\p优胜训练家：\n青绿、赤红、{PLAYER}$"
    .string ""
    .string ""
	.string ""
