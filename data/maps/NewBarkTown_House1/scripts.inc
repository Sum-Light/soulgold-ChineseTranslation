NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "皮卡丘是已经进化过的\n宝可梦。\p空木博士的研究成果真是\n让我惊叹。\p他在宝可梦进化方面的研究\n太有名了。\p……唉……\p真希望我也能成为像他那样的\n研究者……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""


NewBarkTown_House1_Text_Neighbor:
	.string "我女儿一心要当\n空木博士的助手。\p她真的很喜欢宝可梦！\p不过嘛，我也一样！$"
	.string ""
	.string ""
	.string ""

