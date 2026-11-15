EcruteakCity_House2_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "哦。你在和宝可梦\n一起冒险？\p那么，冒险怎么能少了\n寻宝呢？\p我说得对吧？$"
	.string ""
	.string ""
	.string ""
	.string ""

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "好！你懂冒险的\n真正精神。\p我喜欢！这个拿去用吧。$"
	.string ""
	.string ""

Ecruteak_Text_ItemfinderExplanation:
	.string "地上散落着很多\n一眼看不出的道具。\p用探宝器就能查出身边\n地上有没有道具。\p它不会指出确切位置，\n还得你自己找。\p对了，听说圆朱的烧焦塔里\n也有道具。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "哦……大概是\n人各有志吧……$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	msgbox Ecruteak_Text_ItemFinderMan, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "圆朱是座非常古老的城市。\n一代代人靠着这样的书\l把历史传了下来。$"
	.string ""
	.string ""

Ecruteak_Text_HistoryBook:
	.string "圆朱的历史\p要读读看吗？$"
	.string ""

Ecruteak_Text_TwoTowers:
	.string "在圆朱，曾有两座塔。\p每座塔都是强大飞行\n宝可梦的栖息地。\p但其中一座塔\n被烧成了灰烬。\p那两只宝可梦\n从此再没出现过……\p要继续读下去吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Ecruteak_Text_ThreeMon:
	.string "圆朱也曾是三只宝可梦的故乡，\n它们绕着城镇奔跑。\p据说它们诞生自\n水、雷电和火焰。\p但它们无法抑制\n自身过剩的力量。\p于是传说这三只宝可梦\n如风一般奔向了草原。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
