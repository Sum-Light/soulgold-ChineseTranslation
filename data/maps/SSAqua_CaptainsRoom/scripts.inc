.set LOCALID_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER, 2
.set LOCALID_SSAQUA_CAPTAINS_ROOM_CAPTAIN, 1

SSAqua_CaptainsRoom_MapScripts::
	.byte 0

SSAqua_CaptainsRoom_EventScript_Captain::
	goto_if_eq VAR_TEMP_0, 1, SSAqua_CaptainsRoom_EventScrip_CaptainAfter
	msgbox SSAqua_CaptainsRoom_Text_CaptainExhausting, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
SSAqua_CaptainsRoom_EventScrip_CaptainAfter::
	msgbox SSAqua_CaptainsRoom_Text_CaptainHowDoYouLike, MSGBOX_DEFAULT
	closemessage
	end

SSAqua_CaptainsRoom_EventScript_Granddaughter::
	lock
	applymovement LOCALID_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER, SSAqua_CaptainsRoom_Movement_Jump
	waitmovement 0
	msgbox SSAqua_CaptainsRoom_Text_GranddaughterCaptainPlayWithMe, MSGBOX_DEFAULT
	turnobject LOCALID_SSAQUA_CAPTAINS_ROOM_CAPTAIN, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SSAQUA_CAPTAINS_ROOM_CAPTAIN, Common_Movement_QuestionMark
	waitmovement 0
	delay 60
	faceplayer
	msgbox SSAqua_CaptainsRoom_Text_GranddaughterHasToFindGrandpa, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER
	setvar VAR_SSAQUA_STATE, 4
	clearflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER
	warp MAP_SSAQUA_ROOM_SSE, 0
	release
	end

SSAqua_CaptainsRoom_Movement_Jump:
	jump_in_place_right
	jump_in_place_right
	jump_in_place_right
	step_end

SSAqua_CaptainsRoom_Text_GranddaughterCaptainPlayWithMe:
	.string "船长，陪我玩嘛！\p好无聊啊！我还想玩！$"
	.string ""

SSAqua_CaptainsRoom_Text_GranddaughterHasToFindGrandpa:
	.string "你好！你愿意陪我玩吗？\p……啊！\p爷爷在担心我？\p我得走了！\p我得去找爷爷！$"
	.string ""
	.string ""
	.string ""
	.string ""

SSAqua_CaptainsRoom_Text_CaptainExhausting:
	.string "呼！谢谢您陪她玩。\p哄那个小姑娘可真是\n累人啊。$"
	.string ""
	.string ""

SSAqua_CaptainsRoom_Text_CaptainHowDoYouLike:
	.string "您觉得水流号坐起来怎么样？\p它简直像是在\n海浪上滑行一样。$"
	.string ""
	.string ""

