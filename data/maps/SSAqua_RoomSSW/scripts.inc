SSAqua_RoomSSW_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
    .string "我要去关都\n表演喷火特技！$"
    .string ""

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
    .string "扑哧……火苗好小……$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "果然在海面上火会变弱。\n没关系？真的吗？$"
    .string ""

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
    .string "我去看奶奶，\n顺便抓些虫子！$"
    .string ""

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
    .string "哦哦，你挺强的！$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
    .string "城都的树丛里\n能找到很多宝可梦！$"
    .string ""
