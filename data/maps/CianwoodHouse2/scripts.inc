CianwoodHouse2_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "你是从浅葱市来的吧？\p路上那四座岛，\n你记得吗？\p听说有传说中的海中生物\n就藏在里面。$"
	.string ""
	.string ""
	.string ""
	.string ""

CianwoodCity_Text_LugiaHouseLass:
	.string "听说只有拿着银色之羽，\n才能见到它。\p它身上一定有和那生物\n相同的气味。$"
	.string ""
	.string ""
	.string ""

CianwoodCity_Text_LugiaHouseTwin:
	.string "听说那几座岛周围的漩涡，\n是那只海中生物\l造成的。\p要过去的话，也许需要\n特别的招式。$"
	.string ""
	.string ""
	.string ""
	.string ""
