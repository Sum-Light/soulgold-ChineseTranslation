Route7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "这是什么传单？\p……不守规矩的训练家\n在地下通道里\l举行对战。\p最近，附近居民的投诉\n越来越多，地下通道\l已被无限期封锁。\p玉虹市警察$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route7_Text_LockedDoor:
	.string "上锁了……$"

