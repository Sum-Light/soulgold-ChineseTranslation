
EcruteakCity_Gym_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_MORTY_1, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	clearflag FLAG_HIDE_ECRUTEAK_RIVAL
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "缘朱市宝可梦道馆$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "缘朱市宝可梦道馆\p松叶认证训练家：\n{PLAYER}$"
	.string ""
	.string ""

MortyIntroText:
	.string "你能来，真是太好了。\p在圆朱，宝可梦一直\n受到人们的敬重。\p据说，虹色的宝可梦\n会降临到真正的\l训练家面前。\p我相信这个传说，\n才在这里暗中修炼。\p结果，我现在能看见\n别人看不见的东西了。\p就差一点……\p再进一步，我就能看见\n与虹色的宝可梦\l相遇的未来。\p你要帮我达到\n那个境界！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MortyWinLossText:
	.string "我还不够强……\p好吧。这枚徽章\n归你了。$"
	.string ""

Text_ReceivedFogBadge:
	.string "{PLAYER}得到了幻影徽章。$"

MortyText_FogBadgeSpeech:
	.string "有了幻影徽章，50级以下的\n宝可梦都会听你的话。\p而且，学会冲浪的宝可梦\n随时都能\l在对战外使用它。\p这个也给你。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MortyText_ShadowBallSpeech:
	.string "那是暗影球。\n既能造成伤害，还可能\l降低特防。\p觉得合适就用吧。$"
	.string ""
	.string ""
	.string ""

MortyFightDoneText:
	.string "原来如此……\p你的旅程带你走过了\n很远的地方。\p你见过的世面\n比我多得多。\p真让我羡慕……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MortyRematchText:
	.string "啊，城都冠军！\n你能来，真是太好了。\p你有实力也有技巧，\n但比起上次对战，\l你又成长了吗？\p从那以后，我一直和\n幽灵属性的宝可梦一起修炼。\p让我看看你这次能不能\n再次战胜阴影。\p要来再打一场吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Morty_RematchDefeatText:
	.string "我还不够强……\p你见过的世面\n比我多得多。\p真让我羡慕……$"
	.string ""
	.string ""
	.string ""

SageJeffreySeenText:
	.string "我和宝可梦一起\n度过了春天。\p然后是夏天、秋天、冬天……\p接着春天又来了。\n我们在一起很久了。$"
	.string ""
	.string ""
	.string ""
	.string ""

SageJeffreyBeatenText:
	.string "胜与负，\n我都尝过了。$"
	.string ""

SageJeffreyAfterBattleText:
	.string "宝可梦是从哪里来的呢？$"

SagePingSeenText:
	.string "你能对我们的宝可梦\n造成伤害吗？$"
	.string ""

SagePingBeatenText:
	.string "哦！干得漂亮！$"

SagePingAfterBattleText:
	.string "我们用的是幽灵属性宝可梦。\p一般属性的招式\n伤不到它们！$"
	.string ""
	.string ""

MediumMarthaSeenText:
	.string "我一定会赢！$"

MediumMarthaBeatenText:
	.string "我……我……我输了！$"

MediumMarthaAfterBattleText:
	.string "最想赢的人，\n才真的会赢！$"
	.string ""

MediumGraceSeenText:
	.string "被我们的昏暗走廊难住了？\n想听提示的话，就先打赢我！$"
	.string ""

MediumGraceBeatenText:
	.string "什、什么？$"

MediumGraceAfterBattleText:
	.string "好吧。就把影子的秘密\n告诉你。\p路就在你眼前！$"
	.string ""
	.string ""
	.string ""

EcruteakCity_GymGuideText:
	.string "嘿，未来的冠军！\n你差不多走完一半了！\p这里的训练家用的是\n幽灵属性和恶属性的宝可梦。\p松叶是幽灵属性的高手，\n不过还要当心他的\l神秘宝可梦。\p据说它们会让人做\n奇怪的噩梦……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_GymGuideWinText:
	.string "呼，{PLAYER}。你干得太棒了！\p我吓得躲在角落里\n一个劲儿发抖！$"
	.string ""
	.string ""

EcruteakCity_GymClosedText:
	.string "道馆馆主松叶\n不在。\p抱歉，请你\n离开吧。\p呵呵呵。$"
	.string ""
	.string ""
	.string ""
	.string ""
