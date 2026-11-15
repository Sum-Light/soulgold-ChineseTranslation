CherrygroveCity_House1_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "你想知道自己作为\n宝可梦训练家的实力吗？\p那你就该去城都地区各地的\n宝可梦道馆，收集\l徽章。$"
	.string ""
	.string ""
	.string ""
	.string ""

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "等我长大了，我要当\n道馆馆主！\p我会让我的宝可梦和\n朋友的宝可梦对战，\l让它们变得更强！$"
	.string ""
	.string ""
	.string ""
	.string ""
