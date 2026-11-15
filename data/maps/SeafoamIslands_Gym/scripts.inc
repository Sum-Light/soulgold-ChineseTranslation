SeafoamIslands_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_TM, MSGBOX_DEFAULT
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_GARBAGEFLAG, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
    .string "红莲宝可梦道馆\n馆主：夏伯\p优胜训练家：\n青绿、赤红$"
    .string ""
	.string ""
	.string ""

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
    .string "红莲宝可梦道馆\n馆主：夏伯\p优胜训练家：\n青绿、赤红、{PLAYER}$"
    .string ""
    .string ""
	.string ""

SeafoamIslands_Gym_Text_TM:
	.string "拿去吧。这枚招式学习器里\n装着强大的过热。\p希望你下一个对手\n多备些灼伤药！呜哇！$"
	.string ""
	.string ""
	.string ""
SeafoamIslands_Gym_Text_BlaineIntro:
	.string "夏伯：呜哇！\p我在红莲镇的道馆\n被烧毁了。\p火山喷发，害得我和\n会喷火的宝可梦无家可归。\p呜哇！\p不过，我又在这座洞窟里\n当回了道馆馆主。\p你要是能打赢我，\n我就送你一枚徽章。\p哈！你最好多备些灼伤药！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "夏伯：太棒了。\n我烧尽了……\p你赢得了深红徽章！$"
	.string ""

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER}得到了深红徽章。$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "夏伯：这次是我输了，\n下次一定会赢。\p等我重建红莲道馆，\n咱们再较量一场。$"
	.string ""
	.string ""
	.string ""

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "夏伯：我的火焰宝可梦\n还会变得更强。\p你就等着看吧！$"
	.string ""
	.string ""

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "夏伯：喔！\p你已经当上\n关都的冠军了！\p真是火热！\p你的实力是一流的。\p我随时奉陪。\p要不要再和我打一场？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "夏伯：你的实力真是火热！\p把我的防线\n烧得干干净净。$"
	.string ""
	.string ""

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "哟！\p……咦？已经打完了？\p抱歉抱歉！\p红莲道馆没了，我都不知道\n上哪儿去找你。\p不过嘛，就算没有我的建议，\n你也够强了。我就知道你会赢！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "只要道馆馆主在，\n哪里都可以是宝可梦道馆。\p不一定非要有栋建筑不可。$"
	.string ""
	.string ""
