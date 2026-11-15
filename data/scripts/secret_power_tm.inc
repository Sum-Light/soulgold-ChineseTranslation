Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "哎？你问我在干什么？\p我正想用宝可梦的招式在这里\n造一个只属于自己的房间！\p对了！这个招式学习器送你！\n你也试试看怎么样？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route111_Text_ExplainSecretPower:
	.string "找一棵挂满藤蔓的大树，\n对着树干使用秘密之力——\l藤蔓落下来，就能爬上树干了！\p你会发现超大的空间，\n可以随意布置喜欢的东西。\l那就是独属于你的秘密房间……\l我们叫它——“秘密基地”！\l你也应该弄一个试试！\p还有还有，能制造秘密基地的\n地方可不仅仅只有树上哦！\p试试对岩壁上凹陷的裂缝\n也使用秘密之力吧！\p我还要去找其他好地方呢，\n先走啦！拜拜！$"
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
	.string ""
	.string ""
	.string ""
	.string ""

Route111_Text_DontWantThis:
	.string "啊？你不想要吗？\n改变主意了随时找我呀！$"
	.string ""

Route111_Text_DontHaveAnyRoom:
	.string "啊，你的包包好像满了！\p我先帮你拿着，等下次包包\n空出来了，再过来拿吧！$"
	.string ""
	.string ""

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq FLAG_GARBAGEFLAG, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	goto_if_eq FLAG_GARBAGEFLAG, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	call_if_eq FLAG_GARBAGEFLAG, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq FLAG_GARBAGEFLAG, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq FLAG_GARBAGEFLAG, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject FLAG_GARBAGEFLAG
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement FLAG_GARBAGEFLAG, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement FLAG_GARBAGEFLAG, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
