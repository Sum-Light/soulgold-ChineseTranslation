.set LOCALID_INDIGOJUNCTION_POLICEMAN, 1
.set LOCALID_INDIGOJUNCTION_JANINE, 4

ReceptionGate_MapScripts::
	.byte 0

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
    .string "阿杏：我正要去父亲家里\n给他送午饭。\p四天王不分昼夜\n都没空休息。真是\l辛苦的差事啊。\p你要是还想再战一场，\n回头来道场找我。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""


ReceptionGate_EventScript_Officer::
    lock
    faceplayer
    goto_if_set FLAG_IS_CHAMPION, ReceptionGate_EventScript_OfficerCleared
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_OfficerNotEnough
    goto_if_set FLAG_LEGENDARY_STORY_CAP, ReceptionGate_EventScript_OfficerCleared
    call ReceptionGate_EventScript_ShowStoryGuidance
    closemessage
    release
    end

ReceptionGate_EventScript_OfficerNotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    release
    end

ReceptionGate_EventScript_OfficerCleared::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    release
    end

ReceptionGate_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 20
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_NotEnough
    goto_if_unset FLAG_LEGENDARY_STORY_CAP, ReceptionGate_EventScript_StoryBlocked
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 1
    release
    end

ReceptionGate_EventScript_StoryBlocked::
    call ReceptionGate_EventScript_ShowStoryGuidance
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end 

ReceptionGate_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

ReceptionGate_EventScript_ShowStoryGuidance::
    goto_if_ge VAR_ECRUTEAK_CITY_THEATER, 7, ReceptionGate_EventScript_ShowLegendaryGuidance
    goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 9, ReceptionGate_EventScript_ShowLegendaryGuidance
    goto_if_ge VAR_ECRUTEAK_CITY_THEATER, 4, ReceptionGate_EventScript_ShowKimonoGuidance
    goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 8, ReceptionGate_EventScript_ShowKimonoGuidance
    msgbox VictoryRoadGate_Text_VisitElm, MSGBOX_DEFAULT
    return

ReceptionGate_EventScript_ShowKimonoGuidance::
    msgbox VictoryRoadGate_Text_VisitKimonoGirls, MSGBOX_DEFAULT
    return

ReceptionGate_EventScript_ShowLegendaryGuidance::
    goto_if_eq VAR_LUGIA_OR_HOOH, 1, ReceptionGate_EventScript_ShowWhirlIslandsGuidance
    goto ReceptionGate_EventScript_ShowTinTowerGuidance

ReceptionGate_EventScript_ShowWhirlIslandsGuidance::
    msgbox VictoryRoadGate_Text_VisitWhirlIslands, MSGBOX_DEFAULT
    return

ReceptionGate_EventScript_ShowTinTowerGuidance::
    msgbox VictoryRoadGate_Text_VisitTinTower, MSGBOX_DEFAULT
    return

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
ReceptionGate_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_VisitElm:
    .string "你是{PLAYER}吧？\p空木博士一直在\n想办法联系你。\p请去若叶镇的\n研究所找他！$"
    .string ""
    .string ""
    .string ""
    .string ""

VictoryRoadGate_Text_VisitKimonoGirls:
    .string "一位和服女孩让我\n给你带个话。\p她们在圆朱舞场\n等你。$"
    .string ""
    .string ""
    .string ""

VictoryRoadGate_Text_VisitWhirlIslands:
    .string "和服女孩追踪传说的宝可梦，\n一路追到了\l漩涡岛。\p请在挑战宝可梦联盟之前\n先去那里。$"
    .string ""
    .string ""
    .string ""
    .string ""

VictoryRoadGate_Text_VisitTinTower:
    .string "和服女孩追踪传说的宝可梦，\n一路追到了\l铃铛塔。\p请在挑战宝可梦联盟之前\n先去那里。$"
    .string ""
    .string ""
    .string ""
    .string ""

VictoryRoadGate_Text_NotEnoughBadges:
    .string "你还没有集齐城都地区的\n所有道馆徽章。\p很抱歉，我不能\n放你过去。$"
    .string ""
    .string ""
    .string ""

VictoryRoadGate_Text_EightBadges:
    .string "哦！城都地区的八枚徽章！\p请吧，您可以直接通过！$"
    .string ""

VictoryRoadGate_Text_LeftBlackBelt:
    .string "这边通往白银山。\p山那边有强得\n吓人的宝可梦。$"
    .string ""
    .string ""

VictoryRoadGate_Text_RightBlackBelt:
    .string "要去宝可梦联盟吗？\p四天王强得吓人，\n他们可都等着你呢！$"
    .string ""
    .string ""
