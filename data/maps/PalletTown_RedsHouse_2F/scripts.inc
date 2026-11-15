PalletTown_RedsHouse_2F_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

RedsHouse_Text_NES:
	.string "{PLAYER}玩了一会儿NES。\p该走了——没时间耽搁！$"
	.string ""

RedsHouse_Text_PC:
	.string "看样子已经很久\n没人用过了……$"
	.string ""
