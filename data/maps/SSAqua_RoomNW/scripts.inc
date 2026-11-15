.set LOCALID_SSAQUA_SLEEPYSAILOR, 1

SSAqua_RoomNW_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomNW_OnTransition
	.byte 0

SSAqua_RoomNW_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 3, SSAqua_RoomNW_SetTrainerPos
    end

SSAqua_RoomNW_SetTrainerPos::
    setobjectxyperm 2, 2, 6
    setobjectxyperm 3, 4, 3
    end

SSAqua_RoomNW_EventScript_Stanly::
    lock
    faceplayer
    msgbox SSAqua_RoomNW_Text_SailorStanlySeen, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_STANLY, SSAqua_RoomNW_Text_SailorStanlyBeaten
	msgbox SSAqua_RoomNW_Text_SailorStanlyAfterBattle, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    delay 60
    playse SE_DOOR
    removeobject LOCALID_SSAQUA_SLEEPYSAILOR
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_SSAQUA_STATE, 3
	end

SSAqua_RoomNW_EventScript_Edward::
    trainerbattle_single TRAINER_EDWARD SSAqua_RoomNW_Text_GentlemanEdwardSeen, SSAqua_RoomNW_Text_GentlemanEdwardBeaten
	msgbox SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNW_EventScript_Corey::
    trainerbattle_single TRAINER_COREY SSAqua_RoomNW_Text_BurglarCoreySeen, SSAqua_RoomNW_Text_BurglarCoreyBeaten
	msgbox SSAqua_RoomNW_Text_BurglarCoreyAfterBattle, MSGBOX_AUTOCLOSE
	end


SSAqua_RoomNW_Text_SailorStanlySeen:
	.string "没错，我是船员。\p我可没有偷懒！\p这间客房空着，\n我就稍微打了个盹！\p唉，算了！来对战吧！$"
	.string ""
	.string ""
	.string ""
	.string ""

SSAqua_RoomNW_Text_SailorStanlyBeaten:
	.string "对不起！都是我的错！$"

SSAqua_RoomNW_Text_SailorStanlyAfterBattle:
	.string "当船员就得干体力活，\n真是累人！$"
	.string ""

SSAqua_RoomNW_Text_GentlemanEdwardSeen:
	.string "哎呀，糟了。我把一件\n很重要的东西弄丢了。$"
	.string ""

SSAqua_RoomNW_Text_GentlemanEdwardBeaten:
	.string "我……我找不到……$"

SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle:
	.string "算了，我放弃了。\n您不用帮我找了。\p就当没这回事吧！$"
	.string ""
	.string ""

SSAqua_RoomNW_Text_BurglarCoreySeen:
	.string "哟嗬！真走运！$"

SSAqua_RoomNW_Text_BurglarCoreyBeaten:
	.string "真倒霉！我输了！$"

SSAqua_RoomNW_Text_BurglarCoreyAfterBattle:
	.string "我在这里捡到了一枚\n漂亮的硬币。\p一定是有人掉在这儿的……$"
	.string ""
