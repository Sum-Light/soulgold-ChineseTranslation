OneIsland_MapScripts::
	.byte 0

OneIsland_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, OneIsland_EventScript_OldManLinkHoenn
	msgbox OneIsland_Text_LuckyToHaveCelioHere
	release
	end

OneIsland_EventScript_OldManLinkKanto::
	msgbox OneIsland_Text_HavePCLinkageWithKanto
	release
	end

OneIsland_EventScript_OldManLinkHoenn::
	msgbox OneIsland_Text_HavePCLinkageWithHoenn
	release
	end

OneIsland_EventScript_BaldingMan::
	msgbox OneIsland_Text_IsntWarmClimateHereGreat, MSGBOX_NPC
	end

OneIsland_EventScript_IslandSign::
	msgbox OneIsland_Text_IslandSign, MSGBOX_SIGN
	end

OneIsland_EventScript_PokemonNetCenterSign::
	msgbox OneIsland_Text_PokemonNetCenterSign, MSGBOX_SIGN
	end

OneIsland_Text_BillLetsGoSeeCelio::
	.string "正辉：我们到了！\n这里就是第一岛。\p这一带散布着好几座岛，\n这里只是其中之一。\p我的朋友锦辉派船\n把我接到这里来。\p他一个人负责\n这座岛的电脑网络。\p……我怎么现在说起这些了？\n总之，我们快去见锦辉吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Text_WhereDoYouWantToSail::
	.string "喂，客官！\n您要去哪儿？$"
	.string ""

OneIsland_Text_LuckyToHaveCelioHere::
	.string "我们这地方，\n孤零零地坐落在大海中央。\p能有锦辉这样\n正直的年轻人，真是幸运。\p我孙女听说他的朋友之后\n兴奋得不得了。\p好像是个很有名的\n怪兽狂什么的？\p我不太懂那是什么，不过\n锦辉真是个了不起的人！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OneIsland_Text_HavePCLinkageWithKanto::
	.string "我孙女因为一项新突破\n兴奋得不得了。\p她说我们终于能和关都的人\n通过网络连上了。\p我不太懂那是什么，不过\n锦辉真是个了不起的人！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OneIsland_Text_HavePCLinkageWithHoenn::
	.string "我孙女因为一项新突破\n兴奋得不得了。\p她说我们终于能和丰缘的人\n通过网络连上了。\p我不太懂那是什么，不过\n锦辉真是个了不起的人。\p他会是门好亲事，\n配我孙女正合适！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

OneIsland_Text_IslandSign::
	.string "第一岛\n朋友相聚的结缘岛$"
	.string ""

OneIsland_Text_PokemonNetCenterSign::
	.string "拓宽宝可梦的世界！\n宝可梦网络中心$"
	.string ""

@ Unused
OneIsland_Text_ReturnToCinnabar::
	.string "要回红莲镇吗？$"

OneIsland_Text_IsntWarmClimateHereGreat::
	.string "嗨，您是来观光的吧？\n这里气候温暖，很不错吧？$"
	.string ""
