
MtSilver_SummitDay_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_SummitDay_OnTransition
	.byte 0

MtSilver_SummitDay_OnFrame::
	map_script_2 VAR_TEMP_0, 0 MtSilver_SummitDay_Blizzard
	.2byte 0

MtSilver_SummitDay_Blizzard::
	playse SE_M_BLIZZARD
	setvar VAR_TEMP_0, 1
	end

MtSilver_SummitDay_OnTransition:
    call Common_EventScript_SetupRivalGfxId
	call_if_set FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetDay
	end


MtSilver_SummitDay_OnTransition_SetLayout:
	call_if_set FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetDay
	end

MtSilver_SummitDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_MT_SILVER_SUMMIT_NIGHT
	return

MtSilver_SummitDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_MT_SILVER_SUMMIT_DAY
	return

MtSilver_SummitDay_EventScript_Rival::
	lock
	createfieldmugshotrival
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_0
	delay 30
	faceplayer
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_1
	closemessage
	applymovement LOCALID_MTSILVER_RIVAL, MtSilver_SummitDay_EventScript_Rival_Movement_0
	waitmovement 0
	delay 30
	faceplayer
	createfieldmugshotrival
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_2
	removefieldmugshot
	closemessage
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MtSilver_SummitDay_EventScript_Rival_2
	trainerbattle_no_intro TRAINER_RIVAL_GOLD_FINAL, MtSilver_SummitDay_EventScript_Rival_Text_3
MtSilver_SummitDay_EventScript_Rival_1:
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	createfieldmugshotrival
	delay 30
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_4
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_5
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_6
	playfanfare MUS_OBTAIN_ITEM
	removefieldmugshot
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_7
	waitfanfare
	giveegg SPECIES_JIRACHI
	createfieldmugshotrival
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_8
	removefieldmugshot
	closemessage
	fadescreenspeed FADE_TO_BLACK, 24
	setflag FLAG_HIDE_MTSILVER_RIVAL
	removeobject LOCALID_MTSILVER_RIVAL
	setflag FLAG_DEFEATED_MTSILVER_RIVAL
	setvar VAR_RIVAL_STATE, 12
	clearflag FLAG_HIDE_NEWBARK_RIVAL
	clearflag FLAG_HIDE_RIVAL_AZUMARILL
	setflag FLAG_HIDE_RIVAL_MARILL
	delay 40
	warp MAP_NEW_BARK_TOWN_HOUSE3, 33, 3
	waitstate
	releaseall
	end

MtSilver_SummitDay_EventScript_Rival_2:
	trainerbattle_no_intro TRAINER_RIVAL_CRYSTAL_FINAL, MtSilver_SummitDay_EventScript_Rival_Text_3
	goto MtSilver_SummitDay_EventScript_Rival_1


MtSilver_SummitDay_EventScript_Rival_Movement_0:
	walk_in_place_up
	step_end

MtSilver_SummitDay_EventScript_Rival_Text_0:
	.string "我就知道你会来这里。$"

MtSilver_SummitDay_EventScript_Rival_Text_1:
	.string "我一直在上面想事情。\n反正也没别的事可做。\p我总对自己说，\n再来一枚徽章，再赢一场。\p然后我就终于能追上你了。\p很傻对吧？说到底，我不过\n是想出风头而已。\p总以为大家对我抱着某种期待，\n指望我攀上高峰、成为最强。$"

MtSilver_SummitDay_EventScript_Rival_Text_2:
	.string "说到底，这一切都只是\n我在钻牛角尖，哈哈。\p那么！{PLAYER}，就让我\n跟你再打最后一场，好让\l我清醒清醒！\p不是作为心存芥蒂的劲敌，\n而是作为你最好的朋友！\p我没什么要证明的了，\n就让我们像从前那样\l开心地打一场吧。$"

MtSilver_SummitDay_EventScript_Rival_Text_3:
	.string "哈，真有你的。$"

MtSilver_SummitDay_EventScript_Rival_Text_4:
	.string "好。\n这才是我想要的。$"

MtSilver_SummitDay_EventScript_Rival_Text_5:
	.string "你对战的时候总是带着笑容，\n这场对战里我也\l感受到了。$"

MtSilver_SummitDay_EventScript_Rival_Text_6:
	.string "我一个人站在这里的时候，\n正盼着你能来。\p然后，我就看到了地上\n这颗蛋。\p我觉得它是回应我的愿望\n才出现的，但它应该\l属于你。\p毕竟，是你让我的愿望\n成真了！\p所以，谢谢你，{PLAYER}。$"

MtSilver_SummitDay_EventScript_Rival_Text_7:
	.string "{PLAYER}得到了蛋！$"

MtSilver_SummitDay_EventScript_Rival_Text_8:
	.string "来呀，我们一路跑回家吧！\p光是站在这里，我的手指\n都快冻僵了。$"
