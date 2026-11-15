
RuinsOfAlph_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_B1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_B1F_OnFrame
	.byte 0

RuinsOfAlph_B1F_OnLoad::
	call_if_eq VAR_RUINS_OF_ALPH_PUZZLES, 8, RuinsOfAlph_B1F_OpenSecretRoomDoor
	end

RuinsOfAlph_B1F_OpenSecretRoomDoor::
	setmetatile 12, 1, 0x487, FALSE
	return

RuinsOfAlph_B1F_OnFrame::
	map_script_2 VAR_RUINSOFALPH_STATE, 1, RuinsOfAlph_B1F_EventScript_Presence
	.2byte 0

RuinsOfAlph_B1F_EventScript_Presence::
	lock
	msgbox RuinsOfAlph_B1F_Text_Presence, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUINSOFALPH_STATE, 0
	release
	end


RuinsOfAlph_B1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Teacher, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Hiker::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Hiker, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Gramps::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Gramps, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_Text_Presence:
	.string "这里有一股奇怪的气息。$"

RuinsOfAlph_B1F_Text_Hiker:
	.string "虽然是个大房间，\n却什么都没有。$"
	.string ""

RuinsOfAlph_B1F_Text_Teacher:
	.string "这个地方有一种\n神秘的气质。\p甚至可以说是\n飘渺空灵的感觉。$"
	.string ""
	.string ""
	.string ""

RuinsOfAlph_B1F_Text_Gramps:
	.string "古老的建筑往往是\n国王的陵墓。\p比如金字塔，\n就是如此。$"
	.string ""
	.string ""
	.string ""
