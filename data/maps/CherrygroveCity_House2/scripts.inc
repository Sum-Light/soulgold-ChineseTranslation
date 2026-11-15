CherrygroveCity_House2_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "我小时候可是个\n很厉害的训练家！\p给你一句忠告：\n多抓些宝可梦！\p要好好善待它们！$"
	.string ""
	.string ""
	.string ""
	.string ""
