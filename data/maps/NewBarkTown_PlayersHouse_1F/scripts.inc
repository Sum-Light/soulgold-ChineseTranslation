.set LOCALID_MOMS_FRIEND, 2

NewBarkTown_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_PlayersHouse_1F_OnTransition
	.byte 0

NewBarkTown_PlayersHouse_1F_OnTransition::
	call_if_eq VAR_NEWBARK_TOWN_STATE, 1, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 3, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	end

NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_LEFT

	@add to newgame later
	clearflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_MOM_VISITED
	return

NewBarkTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_MOM_VISITED, NewBarkTown_PlayersHouse_1F_EventScript_Mom_Regular
	goto_if_set FLAG_ADVENTURE_STARTED, NewBarkTown_PlayersHouse_1F_MomEventScript_GoodLuck
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MovementFaceLeft
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsFriend::
	lock
	faceplayer
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomsFriend, MSGBOX_DEFAULT
	applymovement LOCALID_MOMS_FRIEND, NewBarkTown_PlayersHouse_1F_MovementFaceRight
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_MomEventScript_GoodLuck::
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomLeaving, MSGBOX_DEFAULT
	setflag FLAG_MOM_VISITED
	clearflag FLAG_HIDE_ROUTE_30_NPCS
	setvar VAR_NEWBARK_TOWN_STATE, 5
	release
	end


NewBarkTown_PlayersHouse_1F_EventScript_Mom_Regular::
	call PlayersHouse_1F_EventScript_MomHealsParty
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end


NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro::
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_1
	waitmovement 0
	createfieldmugshot MUGSHOT_MOM
	msgbox NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear
	call NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes
	removefieldmugshot
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_2
	waitmovement 0
	setvar VAR_NEWBARK_TOWN_STATE, 2
	setvar VAR_NEWBARKTOWN_LABSTATE, 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	setflag FLAG_VISITED_NEWBARK_TOWN

	@former flagheap location

	releaseall
	end



NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear::
	playfanfare MUS_OBTAIN_ITEM
	removefieldmugshot
	message NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_REGISTER_RIVAL_POKENAV
	createfieldmugshot MUGSHOT_MOM
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear, MSGBOX_DEFAULT
	closemessage
	delay 30
	return
	
NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes::
	createfieldmugshot MUGSHOT_MOM
	msgbox NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	special EnableAutorun
	createfieldmugshot MUGSHOT_MOM
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1:
	delay_8
	walk_down
	walk_right
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2:
	delay_8
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_1:
	face_right
	walk_right
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_2:
	face_left
	walk_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceRight:
	face_right
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceLeft:
	face_left
	step_end

NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou:
	.string "哦，{PLAYER}……！隔壁的\n空木博士正在找你。\p他说有件事想\n请你帮忙。\p哦！差点忘了！你的宝可梦装置\n从修理店拿回来了。\p给你！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear:
	.string "{PLAYER}得到了宝可梦装置。$"

NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear:
	.string "妈妈：电话号码都记在\n里面了。\p想打给谁，选个名字就行。\p哎呀，是不是很方便？$"
	.string ""
	.string ""
	.string ""

NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes:
	.string "还有，别忘了你的\n跑步鞋！$"
	.string ""

NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER}换上了\n跑步鞋。$"
	.string ""

NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes:
	.string "妈妈：穿上它，去哪里\n都能快得多！$"
	.string ""

NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting:
	.string "妈妈：空木博士还在等你呢。\p快去吧，宝贝！$"
	.string ""

NewBarkTown_PlayersHouse_1F_Text_MomsFriend:
	.string "嗨，{PLAYER}！\p我是来串门的！\p你听说了吗？\p我女儿一心想要当\n空木博士的助手。\p她真的很喜欢宝可梦！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

NewBarkTown_PlayersHouse_1F_Text_MomLeaving:
	.string "妈妈：哇，好可爱的宝可梦。\n你从哪里得到的？\p……\p这样啊，你要出去旅行了……\n听起来确实很辛苦……\p一定要小心啊。\p宝可梦是你的朋友。\n你们要齐心协力。\p好了，去吧！\n我会一直支持你的！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
