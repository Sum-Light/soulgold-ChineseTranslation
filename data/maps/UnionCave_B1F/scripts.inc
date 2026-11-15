UnionCave_B1F_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "好久没见过\n别的人了。\p别害羞，来对战吧！$"
	.string ""
	.string ""

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "呜啊啊……$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "我迷路好久了……\p待在这里倒无所谓，\n可是我肚子好饿好饿啊！$"
	.string ""
	.string ""

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "真没想到！\n有客人来了！$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "哇哈哈！你还挺有精神！$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "我就住在这下面。\p你要是愿意，\n也可以住下来。\p你看，这里宽敞得很。$"
	.string ""
	.string ""

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "谁在那儿？\p别打扰我和我的宝可梦！$"
	.string ""

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "走……走开！$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "只有我和我的宝可梦。\n我高兴得快疯了。$"
	.string ""

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "我大老远跑到这里，\n就是为了研究宝可梦。\p让我用实战\n来展示我的研究成果！$"
	.string ""
	.string ""
	.string ""

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "反倒是你给我演示了一番！$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "我该把研究结果\n整理起来发表了。\p说不定我会像空木博士\n一样出名。$"
	.string ""
	.string ""
	.string ""
