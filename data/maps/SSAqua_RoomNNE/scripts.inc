SSAqua_RoomNNE_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
    .string "我要去关都\n检验一下自己的实力。$"
    .string ""

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
    .string "我本来想赢的！$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
    .string "城都的训练家\n也能和关都的\l道馆馆主对战。$"
    .string ""
    .string ""

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
    .string "我正在特训，\n要成为冠军！$"
    .string ""

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
    .string "我们之间到底\n差在哪里？$"
    .string ""

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
    .string "总有一天\n我要赢过你！$"
    .string ""
