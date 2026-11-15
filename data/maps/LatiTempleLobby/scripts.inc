LatiTempleLobby_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_CAUGHT_LATIAS, LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD_2
	return

LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 18, 10, 0x441, FALSE
	return

LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	goto_if_set FLAG_CAUGHT_LATIOS, LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return


LobbyDoorLati::
	lock
	goto_if_set FLAG_CAUGHT_LATIAS, LobbyDoorLati_4
LobbyDoorLati_3:
	msgbox LobbyDoorLati_Text_1
LobbyDoorLati_1:
	release
	end

LobbyDoorLati_2:
	msgbox LobbyDoorLati_Text_0
	goto LobbyDoorLati_1

LobbyDoorLati_4:
	goto_if_set FLAG_CAUGHT_LATIOS, LobbyDoorLati_2
	goto LobbyDoorLati_3


LobbyDoorLati_Text_0:
	.string "门已经打开了。$"

LobbyDoorLati_Text_1:
	.string "门上刻满了\n古老的文字。\p门扉紧闭。$"
