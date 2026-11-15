
SproutTower_1F_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_Text_SageChow_Seen:
	.string "我们在这座塔里站岗放哨。\p在这里，我们怀着感激之情，\n向所有的宝可梦致敬。$"
	.string ""
	.string ""

SproutTower_Text_SageChow_Beaten:
	.string "谢、谢谢你！$"

SproutTower_Text_SageChow_AfterBattle:
	.string "众生相依，\n互助共存。\p我们应当永远\n对此心怀感激。$"
	.string ""
	.string ""
	.string ""

SproutTower_Text_1F_Sage1:
	.string "只有登上塔顶，\n才能得到秘传学习器。$"
	.string ""

SproutTower_Text_1F_Sage2:
	.string "这座喇叭芽之塔是很久以前\n为了修炼宝可梦而建的。$"
	.string ""

SproutTower_Text_1F_Granny:
	.string "据说曾有一株\n高达100英尺的喇叭芽……\p人们说，它后来变成了\n这座塔正中央的柱子。$"
	.string ""
	.string ""
	.string ""

SproutTower_Text_1F_Teacher:
	.string "看到柱子在晃了吗？\p上面有人正在修行呢。$"
	.string ""

SproutTower_Text_1F_Statue:
	.string "一座宝可梦雕像……\p看起来非常庄严肃穆。$"
	.string ""

SproutTower_1F_Guard::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE08_GET, SproutTower_1F_Guard_2
	msgbox SproutTower_1F_Guard_Text_1
	release
	end

SproutTower_1F_Guard_2:
	msgbox SproutTower_1F_Guard_Text_0
	release
	end


SproutTower_1F_Guard_Text_0:
	.string "非常抱歉，通往下面\n楼层的入口禁止入内。\l只有获得长老许可的人\l才能进入。$"

SproutTower_1F_Guard_Text_1:
	.string "你好，{PLAYER}。\n李长老想和你谈谈。\p请到顶层去见他。$"
