SSAqua_RoomNE_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
    .string "你是一个人吗？\n那就来对战吧！$"
    .string ""

SSAqua_RoomNE_Text_HikerNolandBeaten:
    .string "这可应付不来！$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
    .string "不知道关都有没有\n值得一爬的山？$"
    .string ""

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "你知道莉莉吗？\n她是关都当红的DJ。$"
    .string ""

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "哇啊啊！$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "莉莉是不错，但胡桃最棒！\n我想听城都的广播节目！$"
    .string ""
    .string ""
    .string ""
    .string ""
