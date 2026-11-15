.set LOCALID_NURSE, 1
.set LOCALID_ECRUTEAK_BILL, 6

EcruteakCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	hidefollower
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_LANETTE
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "嗨，我是正辉。\n你是？\p嗯，{PLAYER}啊？\n你来得正是时候。$"
	.string ""
	.string ""

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "我刚把宝可梦寄放系统\n调整完毕。\p你知道用来存放宝可梦的\n那台电脑吧？\p那是我开发的！\p这次装好之后，\n城都地区所有宝可梦中心的\l电脑都能用了。\p我得赶紧回满金市\n去看看家人。你有空\l随时来玩啊！\p拜拜！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "和服女孩们跳舞的样子\n真是太美了。\p她们用宝可梦的方式\n也一样美。$"
	.string ""
	.string ""
	.string ""

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "你是想和更多的人\n对战，对吧？\p听说有个地方\n聚集了很多训练家。\p你问在哪儿？\p就在浅葱市再过去一点。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "道馆馆主松叶\n真的超帅的。\p他的宝可梦也强得很。$"
	.string ""
	.string ""

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "愤怒之湖……\p暴鲤龙成群出现……\p我嗅到阴谋的味道了。\n绝对没错！$"
	.string ""
	.string ""
	.string ""

