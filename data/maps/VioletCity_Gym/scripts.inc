
VioletCity_Gym_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_ROOST
	call violetExplainTm
	setvar VAR_VIOLET_CITY_STATE, 3
	clearflag FLAG_HIDE_TUESCANY
	setrespawn HEAL_LOCATION_VIOLET_CITY
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "我是桔梗宝可梦\n道馆馆主阿速！\p人们说，飞行属性宝可梦\n的翅膀一电击就断……\p竟敢这样侮辱\n鸟宝可梦！\l我绝不原谅！\p就让你见识一下，\n华丽鸟宝可梦的真正实力！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

VioletGym_Text_Falkner_WinLoss:
	.string "……可恶！爸爸心爱的\n鸟宝可梦……\p好吧，这个给你。\p这是宝可梦联盟公认的\n飞翼徽章。$"
	.string ""
	.string ""
	.string ""
	.string ""

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER}得到了飞翼徽章。$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "持有飞翼徽章后，\n学会闪光的\l宝可梦随时都能使用它。\p这个也给你吧。$"
	.string ""
	.string ""
	.string ""



VioletGym_Text_Falkner_AfterFight:
	.string "前方的城镇里还有\n宝可梦道馆。\p就去那些道馆\n检验一下自己的实力吧。\p为了成为最强的鸟宝可梦大师，\n我还要继续刻苦修炼！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

VioletGym_Text_Falkner_Rematch:
	.string "恭喜你战胜了\n四天王！\p我一直在更加刻苦地\n训练飞行属性宝可梦。\p想再挑战一次\n天空的力量吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

VioletGym_Text_Falkner_RematchLoss:
	.string "哇……你又赢了我。\p为了成为最强的鸟宝可梦大师，\n我还要继续刻苦修炼！$"
	.string ""
	.string ""

VioletGym_Text_BirdKeeperRod_Seen:
	.string "关键是毅力！\p这里的人为了成为最强的\n鸟宝可梦大师，日夜训练。\p来吧！$"
	.string ""
	.string ""
	.string ""

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "哇啊啊！$"

VioletGym_Text_BirdKeeperRod_After:
	.string "阿速的实力是货真价实的！\p别因为赢了我\n就得意忘形！$"
	.string ""
	.string ""

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "让我看看你有没有\n挑战阿速的实力！$"
	.string ""

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "怎么可能！$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "竟然输给一个新手训练家，\n真丢人……$"
	.string ""

VioletGym_Text_GymGuide_Intro:
	.string "嘿！你好！我不是训练家，\n但我能给你点建议！\p相信我！只要心怀信念，\n冠军之梦就能实现。\p你信？那就听好。\p阿速的王牌是一只\n爱吃树果的结实鸟宝可梦。\p它虽然不是最强，\n却非常耐打。\p用电属性和岩石属性\n招式能伤到它，\l但要当心掷泥！\p想要更多帮助，就去\n宝可梦学院看看吧。\p那里的学生\n真的很有两下子！$"
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

VioletGym_Text_GymGuide_Win:
	.string "打得漂亮！保持下去，\n你很快就能成为\l宝可梦冠军！$"
	.string ""
	.string ""

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "桔梗市宝可梦道馆$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "桔梗市宝可梦道馆\p阿速认证训练家：\n{PLAYER}$"
	.string ""
	.string ""

violetExplainTm::
	msgbox violetExplainTm_Text_0
	return


violetExplainTm_Text_0:
	.string "宝可梦可以通过招式学习器\n学会新招式。\p这里面装着羽栖，\n能让飞行属性宝可梦回复HP。\p这个可以反复使用，\n多少次都行。\p下一站该去桧皮镇了。\n祝你顺利。$"
