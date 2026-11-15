EcruteakCity_House1_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "这是我年轻时的事。\p天空突然变黑了，一只\n巨大的飞行宝可梦遮住了\l太阳。\p那究竟是什么宝可梦呢？\p它像鸟，又像龙。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "真有那么大的宝可梦吗？\p要是有，一定很厉害。$"
	.string ""
