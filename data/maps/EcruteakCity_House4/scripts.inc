EcruteakCity_House4_MapScripts::
	.byte 0


Itemfinder_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_DOWSING_MACHINE, Itemfinder_Cooltrainer_2
	msgbox Itemfinder_Cooltrainer_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Itemfinder_Cooltrainer_5
	msgbox Itemfinder_Cooltrainer_Text_3
Itemfinder_Cooltrainer_4:
	release
	end

Itemfinder_Cooltrainer_2:
	msgbox Itemfinder_Cooltrainer_Text_0
	release
	end

Itemfinder_Cooltrainer_5:
	msgbox Itemfinder_Cooltrainer_Text_2
	giveitem ITEM_DOWSING_MACHINE
	setflag FLAG_GOT_DOWSING_MACHINE
	msgbox Itemfinder_Cooltrainer_Text_0
	goto Itemfinder_Cooltrainer_4


Itemfinder_Cooltrainer_Text_0:
	.string "地上散落着很多\n一眼看不出的道具。\p把探宝器用上一会儿，\n看看它会不会指向道具。\p它一有反应，就说明\n附近有道具。$"

Itemfinder_Cooltrainer_Text_1:
	.string "哦。你在和宝可梦\n一起冒险？\p那么，冒险怎么能少了\n寻宝呢？\p我说得对吧？$"

Itemfinder_Cooltrainer_Text_2:
	.string "好！你懂冒险的\n真正精神。\p我喜欢！这个拿去用吧。$"

Itemfinder_Cooltrainer_Text_3:
	.string "哦……大概是\n人各有志吧……$"
