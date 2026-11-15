ViridianCity_Gym_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	
	@ if Blue is already at dojo, just do defeated dialogue
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_Blue_Defeated
	@ if Blue is not already at dojo, but player is kanto champion, send him to dojo
	goto_if_set FLAG_IS_KANTO_CHAMPION, ViridianCity_Gym_EventScript_BlueGotoDojo
	@ if player is not champion yet, just do defeated dialogue
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	setflag FLAG_BADGE16_GET
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_POTION @ NOT POTION
	msgbox ViridianCity_Gym_Text_BulkUpSpeech, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_CERULEANCAVE_GUARD
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "青绿：又来挑战了？\p还想再和我打一场，\n就到格斗道场来！$"
	.string ""
	.string ""

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "青绿：哟！你终于来了啊？\p在红莲的时候我没那个心情，\p但现在我准备好和你一战了。\p……\p你说你把城都地区的\n道馆全都打下来了？\p哼！那城都的道馆\n想必也够差劲的。\p喂，别在意。\p你现在就和我打一场，\n我自然知道你有几斤几两。\p准备好了吗，城都的冠军？$"
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

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "青绿：怎么会？\p我到底是怎么\n输给你的？\p……\p嘁，好吧……给，这个给你——\n绿色徽章。$"
	.string ""
	.string ""
	.string ""
	.string ""

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER}得到了绿色徽章。$"

ViridianCity_Gym_Text_BulkUpSpeech:
    .string "这枚招式学习器里\n装的是健美。\p它能让宝可梦同时变成\n势不可挡的力量和\l无可撼动的堡垒！\p别让别人告诉你，\n必须在攻和守之间\l二选一。$"
    .string ""
    .string ""
	.string ""
    .string ""
    .string ""
	.string ""

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "青绿：……\p好吧，是我错了。你是\n真有本事。你是个好训练家。\p但我总有一天会打倒你。\p你可别忘了！$"
	.string ""
	.string ""
	.string ""
	.string ""

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "青绿：听好了。\p在我打倒你之前，\n你可不许输给别人。记住了？$"
	.string ""
	.string ""


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "哟，未来的冠军！\p最近怎么样？看来你\n势头正猛啊。\p这里的馆主，就是三年前\n和冠军交过手的那个人。\p他可不是好对付的。\p拿出全力来吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

ViridianCity_Gym_Text_Guide_Win:
	.string "真是厉害啊……\p那场对战令人振奋，\n我都看哭了。$"
	.string ""
	.string ""


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "常青宝可梦道馆\n馆主：青绿\p优胜训练家：\n青绿、赤红$"
    .string ""
	.string ""
	.string ""

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "常青宝可梦道馆\n馆主：青绿\p优胜训练家：\n青绿、赤红、{PLAYER}$"
    .string ""
    .string ""
	.string ""
