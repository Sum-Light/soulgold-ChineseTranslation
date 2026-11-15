Gate_Route39North_MapScripts::
	.byte 0


Route39North_Police::
	msgbox Route39North_Police_Text_0, MSGBOX_NPC
	return


Route39North_Elder::
	msgbox Route39North_Elder_Text_0, MSGBOX_NPC
	return


Route39North_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_R39_NORTH_ROCKY_HELMET, Route39North_Hiker_2
	msgbox Route39North_Hiker_Text_1
	giveitem ITEM_ROCKY_HELMET
	setflag FLAG_R39_NORTH_ROCKY_HELMET
	msgbox Route39North_Hiker_Text_2
	release
	end

Route39North_Hiker_2:
	msgbox Route39North_Hiker_Text_0
	release
	end


Route39North_Poster::
	msgbox Route39North_Poster_Text_0, MSGBOX_SIGN
	return


Route39North_Binoculars::
	msgbox Route39North_Binoculars_Text_0, MSGBOX_SIGN
	return


Route39North_Gameboykid::
	lock
	faceplayer
	goto_if_set FLAG_R39_NORTH_TRADE, Route39North_Gameboykid_2
	ingame_trade INGAME_TRADE_ROTOM, Route39North_Gameboykid_Text_1, RotomTrade_Declined, RotomTrade_NotRequested, Route39North_Gameboykid_Text_2
	setflag FLAG_R39_NORTH_TRADE
Route39North_Gameboykid_1:
	release
	end

Route39North_Gameboykid_2:
	msgbox Route39North_Gameboykid_Text_0
	goto Route39North_Gameboykid_1


RotomTrade_Declined::
	msgbox RotomTrade_Declined_Text_0
	release
	end


RotomTrade_NotRequested::
	msgbox RotomTrade_NotRequested_Text_0
	release
	end


Route39North_Police_Text_0:
	.string "再往北走的话，\n最好先准备好御寒的衣物。\l海拔一高，身体会吃不消的。$"

Route39North_Elder_Text_0:
	.string "我年轻时每天都要徒步\n上山，来回全靠一双腿！\l哪像你们现在，有宝可梦驮，\l还有时髦的自行车！$"

Route39North_Hiker_Text_0:
	.string "凸凸头盔能让伤害你的对手，\n也尝到同样的痛楚！$"

Route39North_Hiker_Text_1:
	.string "总挨打，受够了吧？\n试试这个！$"

Route39North_Hiker_Text_2:
	.string "疼痛这下该回到对手身上了。$"

Route39North_Poster_Text_0:
	.string "告示上写着：\n有人在群山中目击到大型鸟宝可梦。$"

Route39North_Binoculars_Text_0:
	.string "你朝望远镜里望去……\n……\l……！\l远处矗立着一座\l雄伟的雪山！$"

Route39North_Gameboykid_Text_0:
	.string "听说洛托姆能附身在家用电器上，\n借此改变形态。$"

Route39North_Gameboykid_Text_1:
	.string "我找一只稀有宝可梦\n找了很久。\l你身上有索罗亚吗？\l我愿意用洛托姆跟你换。$"

Route39North_Gameboykid_Text_2:
	.string "太感谢了！我可是合众地区的\n超级粉丝，真想快点给朋友看看！$"

RotomTrade_Declined_Text_0:
	.string "真遗憾，那可是相当稀有的宝可梦。$"

RotomTrade_NotRequested_Text_0:
	.string "呃，不行，不对。\n那看起来不像索罗亚。$"
