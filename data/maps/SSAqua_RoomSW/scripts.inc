SSAqua_RoomSW_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "我想忘掉烦心事。\n来对战吧！$"
    .string ""

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "我的心在哭泣……$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "坐船旅行最适合\n治愈心碎。\p可是高速船的旅程\n太短了，来不及伤心。$"
    .string ""
    .string ""
    .string ""

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "我要去满金市的播音塔\n参加歌曲试音。$"
    .string ""

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "哇！\n彻底走音了！$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "我本来想在对战塔\n首次登台的……\p我还是回枯叶市\n重新修行吧……$"
    .string ""
    .string ""
    .string ""

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "说起播音塔，\n这周的幸运数字是几号？$"
    .string ""
