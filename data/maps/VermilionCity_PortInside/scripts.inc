.set LOCALID_VERMILIONMARINA_SAILOR, 1
.set LOCALID_VERMILIONMARINA_BOAT, 2

VermilionCity_PortInside_MapScripts::
	.byte 0

VermilionPortIndoor_EventScript_Teacher::
	msgbox VermilionPortPassage_Text_Teacher, MSGBOX_NPC
	end
VermilionPortIndoor_EventScript_Nerd::
	msgbox VermilionPort_Text_SuperNerd, MSGBOX_NPC
	end

VermilionPortPassage_Text_Teacher:
	.string "高速船每天都会出航！$"

VermilionPort_Text_SuperNerd:
	.string "您是从城都地区来的？\p听说那边住着许多\n珍稀的宝可梦。$"
	.string ""
	.string ""

VermilionPort_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_RETURNED_MACHINE_PART, VermilionPort_EventScript_SailorCantSail
	goto_if_set FLAG_DEFEATED_MTSILVER_RIVAL, VermilionPort_EventScript_Sailor_After_Red
	goto_if_ge VAR_SSAQUA_STATE, 7, VermilionPort_EventScript_Sailor_AfterKanto
	msgbox VermilionPort_Text_AskBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, VermilionPort_EventScript_Sailor_MaidenVoyage
	msgbox VermilionPort_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_EventScript_SailorCantSail::
	msgbox VermilionPort_Text_SailorCantSail, MSGBOX_NPC
	closemessage
	release
	end

VermilionPort_EventScript_Sailor_AfterKanto::
	message VermilionPort_Text_WhereSail
	multichoice 20, 0, MULTI_VERMILION_HARBOR, FALSE
	switch VAR_RESULT
	case 0, VermilionPort_EventScript_ChoseOlivine
	case 1, VermilionPort_EventScript_ChoseSouthernIsland
	case 2, VermilionPort_EventScript_ChoseBirthIsland
	case 3, VermilionPort_EventScript_ChoseFarawayIsland
	case 4, VermilionPort_EventScript_Sailor_Refused
	case MULTI_B_PRESSED, VermilionPort_EventScript_Sailor_Refused
	release
	end

VermilionPort_EventScript_Sailor_After_Red::
	message VermilionPort_Text_WhereSail
	multichoice 20, 0, MULTI_VERMILION_HARBOR_RED, FALSE
	switch VAR_RESULT
	case 0, VermilionPort_EventScript_ChoseOlivine
	case 1, VermilionPort_EventScript_ChoseSouthernIsland
	case 2, VermilionPort_EventScript_ChoseBirthIsland
	case 3, VermilionPort_EventScript_ChoseFarawayIsland
	case 4, VermilionPort_EventScript_ChoseBattleFrontier
	case 5, VermilionPort_EventScript_Sailor_Refused
	case MULTI_B_PRESSED, VermilionPort_EventScript_Sailor_Refused
	release
	end

VermilionPort_EventScript_ChoseOlivine::
	closemessage
	delay 20
	checkitem ITEM_SS_TICKET
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	release
	end

VermilionPort_EventScript_ChoseSouthernIsland::
	closemessage
	delay 20
	checkitem ITEM_EON_TICKET
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	release
	end

VermilionPort_EventScript_ChoseBirthIsland::
	closemessage
	delay 20
	checkitem ITEM_AURORA_TICKET
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	release
	end

VermilionPort_EventScript_ChoseFarawayIsland::
	closemessage
	delay 20
	checkitem ITEM_OLD_SEA_MAP
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	release
	end	

VermilionPort_EventScript_Sailor_MaidenVoyage::
	msgbox VermilionPort_Text_FlashTicket, MSGBOX_DEFAULT
	call VermilionPort_EventScript_EnterShip
	setvar VAR_SSAQUA_STATE, 1
	release
	end

VermilionPort_EventScript_ChoseBattleFrontier::
	closemessage
	delay 20
	call VermilionPort_EventScript_EnterShip
	release
	end	

VermilionPort_EventScript_EnterShip::
	msgbox VermilionPort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_VERMILIONMARINA_SAILOR, VermilionPort_Movement_SailorEnterBoat
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, VermilionPort_Movement_PlayerEnterBoat
	waitmovement 0
	special SpawnCameraObject
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement LOCALID_VERMILIONMARINA_SAILOR, VermilionPort_Movement_BoatLeave
	applymovement LOCALID_VERMILIONMARINA_BOAT, VermilionPort_Movement_BoatLeave
	waitmovement LOCALID_VERMILIONMARINA_BOAT
	setrespawn HEAL_LOCATION_VERMILION_CITY
	return

VermilionPort_EventScript_Sailor_Refused::
	msgbox VermilionPort_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_EventScript_Sailor_NoCredentials::
	msgbox VermilionPort_Text_NoPass, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

VermilionPort_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

VermilionPort_Movement_BoatLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VermilionPort_Text_SailorCantSail:
	.string "发电厂遭了贼，\n在找到小偷之前\l我们不能出航。$"
	.string ""
	.string ""

VermilionPort_Text_NoPass:
    .string "{PLAYER}想出示\n{STR_VAR_1}……\p……可是没有{STR_VAR_1}！\p抱歉！\n您必须持有\l{STR_VAR_1}才能上船。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

VermilionPort_Text_SailorGetOnBoard:
    .string "马上就要出航了。\n请您上船吧。$"
    .string ""

VermilionPort_Text_CantBoard:
    .string "抱歉，您现在不能上船。$"

VermilionPort_Text_WhereSail:
    .string "您想坐船去哪里？$"

VermilionPort_Text_AskBoard:
    .string "欢迎乘坐高速船水流号。\p您今天要乘船吗？$"
    .string ""

VermilionPort_Text_AskTicket:
    .string "能让我看一下您的船票吗？$"

VermilionPort_Text_ComeAgain:
    .string "欢迎您随时再来！$"

VermilionPort_Text_FlashTicket:
    .string "{PLAYER}出示了船票。\p没错，谢谢您！$"
    .string ""

VermilionPort_Text_NoTicket:
    .string "{PLAYER}拿出了船票\n想出示给您……\p……可是没有船票！\p抱歉！\n您必须有船票\l才能上船。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
