MtMortar_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MountMortar4_EventScript_Kiyo::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TYROGUE, MountMortar4_EventScript_KiyoAfter
	goto_if_set FLAG_BEAT_KIYO, MountMortar4_EventScript_KiyoTryGiveTyrogue
	msgbox MountMortar4_Text_KiyoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIYO, MountMortar4_Text_KiyoWin
	setflag FLAG_BEAT_KIYO
MountMortar4_EventScript_KiyoTryGiveTyrogue::
	createfieldmugshot MUGSHOT_BLACK_BELT
	msgbox MountMortar4_Text_KiyoTyrogueReward, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYROGUE
	bufferspeciesname STR_VAR_1, SPECIES_TYROGUE
	removefieldmugshot
	givemon SPECIES_TYROGUE, 25
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	setflag FLAG_GOT_TYROGUE
MountMortar4_EventScript_KiyoAfter::
	msgbox MountMortar4_Text_KiyoGotTyrogue, MSGBOX_DEFAULT
	closemessage
	release
	end


MountMortar4_Text_KiyoIntro:
	.string "嘿！\p我就是空手道大王！\n在这片黑暗里独自修行！\p你！跟我打一场！\n呜哇啊啊啊！$"
	.string ""
	.string ""
	.string ""
	.string ""

MountMortar4_Text_KiyoWin:
	.string "呜哇啊啊！\n我输了！$"
	.string ""

MountMortar4_Text_KiyoTyrogueReward:
	.string "我……我被打得\n心服口服……\p看来我的修行\n还不够……\p但输了就是输了，\n我承认。\p作为你打败我的证明，\n我就把一只稀有的\l格斗宝可梦送给你。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MountMortar4_Text_ReceiveTyrogue:
	.string "{PLAYER}得到了无畏小子。$"

MountMortar4_Text_KiyoGotTyrogue:
	.string "无畏小子是格斗属性。\p它会进化成\n更强大的宝可梦。\p你也要继续加油。\n我也会继续修行的。\p再会了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MountMortar4_Text_KiyoFullParty:
	.string "你的队伍已经没有\n空位了！$"
