SSAqua_RoomSE_MapScripts::
	.byte 0

SSAqua_RoomSE_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN SSAqua_RoomSE_Text_PokefanmColinSeen, SSAqua_RoomSE_Text_PokefanmColinBeaten
	msgbox SSAqua_RoomSE_Text_PokefanmColinAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Meg::
	trainerbattle_double TRAINER_MEG_AND_PEG, SSAqua_RoomSE_Text_TwinsMegandpeg1Seen, SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg1After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Peg::
	trainerbattle_double TRAINER_MEG_AND_PEG, SSAqua_RoomSE_Text_TwinsMegandpeg2Seen, SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg2After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_Text_PokefanmColinSeen:
    .string "喂，小家伙！\n要不要和我对战？$"
    .string ""

SSAqua_RoomSE_Text_PokefanmColinBeaten:
    .string "你很强！$"

SSAqua_RoomSE_Text_PokefanmColinAfter:
    .string "你一个人旅行？\n你妈妈不担心吗？$"
    .string ""

SSAqua_RoomSE_Text_TwinsMegandpeg1Seen:
    .string "你觉得我是小宝宝？\n太过分了！$"
    .string ""

SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten:
    .string "哎呀！我们输了！$"

SSAqua_RoomSE_Text_TwinsMegandpeg1After:
    .string "叫我们女孩子“小宝宝”，\n可是很没礼貌的！$"
    .string ""

SSAqua_RoomSE_Text_TwinsMegandpeg2Seen:
    .string "我才不是小宝宝！\n对淑女说这种话太失礼了！$"
    .string ""

SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten:
    .string "哎呀！我们输了！$"

SSAqua_RoomSE_Text_TwinsMegandpeg2After:
    .string "有时候，小孩子比\n大人还聪明呢！$"
    .string ""
