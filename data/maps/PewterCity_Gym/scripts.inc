PewterCity_Gym_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	setflag FLAG_BADGE09_GET
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers
	msgbox PewterCity_Gym_Text_EarthquakeSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "小刚：哦，从城都来的挑战者\n可不常见啊。\p我是深灰道馆的馆主，\n小刚。\p我是岩石属性宝可梦\n的专家。\p我的宝可梦大多数物理\n攻击都不放在眼里。想\l造成伤害可不容易。\p来吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

PewterCity_Gym_Text_Brock_WinLoss:
	.string "小刚：你宝可梦强大的攻击\n打穿了我岩石般的防御……\p你比我想象的要强……\p拿去——这个徽章是你的了。$"
	.string ""
	.string ""
	.string ""

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER}得到了灰色徽章。$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "小刚：{PLAYER}，谢谢你。\n虽然有点不甘心，但这场\l对战我很尽兴。\p这枚灰色徽章会让你\n的宝可梦更强。$"
	.string ""
	.string ""
	.string ""
	.string ""

PewterCity_Gym_Text_EarthquakeSpeech:
    .string "这个招式学习器里装的是地震。\p它是能撼动整个战场\n的强大招式。\p不过要小心，别把\n自己的宝可梦也震到！$"
    .string ""
    .string ""
    .string ""
    .string ""

PewterCity_Gym_Text_Brock_FightDone:
	.string "小刚：世界真大啊。像你这么\n强的训练家还有不少。\p你等着看吧。我也要变得\n强得多才行。$"
	.string ""
	.string ""
	.string ""

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "这个道馆的训练家\n都使用岩石属性宝可梦。\p岩石属性的防御力很高。\p战斗可能会拖得很久。\n你做好心理准备了吗？$"
	.string ""
	.string ""
	.string ""
	.string ""

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "这些战斗我一定要赢……$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "喂，你！城都来的训练家！小刚\n很强。你要是不认真对待，\l会吃苦头的。$"
	.string ""
	.string ""

PewterCity_Gym_Text_Guide:
	.string "哟！未来的冠军！你最近可是\n干劲十足啊。\p你在挑战关都的\n道馆馆主吗？\p他们个个又强又执着，\n和城都的道馆馆主一样。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

PewterCity_Gym_Text_Guide_Win:
	.string "哟！未来的冠军！那个道馆\n没给你添多少麻烦嘛。\p你那股掌控全局的劲头\n真让人振奋。我是认真的。$"
	.string ""
	.string ""
	.string ""

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "深灰市宝可梦道馆\n馆主：小刚\p优胜训练家：\n青绿、赤红$"
    .string ""
	.string ""
	.string ""

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "深灰市宝可梦道馆\n馆主：小刚\p优胜训练家：\n青绿、赤红、{PLAYER}$"
    .string ""
    .string ""
	.string ""

