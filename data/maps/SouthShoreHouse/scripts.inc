SouthShoreHouse_MapScripts::
	.byte 0


SouthShoreHouseMan::
	lock
	faceplayer
	goto_if_set FLAG_SHOWN_MIRROR, SouthShoreHouseMan_2
	msgbox SouthShoreHouseMan_Text_1
	checkitem ITEM_BLACK_MIRROR
	compare VAR_RESULT, TRUE
	goto_if_eq SouthShoreHouseMan_5
	release
	end

SouthShoreHouseMan_2:
	msgbox SouthShoreHouseMan_Text_0
	release
	end

SouthShoreHouseMan_5:
	goto_if_unset FLAG_SHOWN_MIRROR, SouthShoreHouseMan_7
	msgbox SouthShoreHouseMan_Text_0
	release
	end

SouthShoreHouseMan_7:
	msgbox SouthShoreHouseMan_Text_2
	setflag FLAG_SHOWN_MIRROR
	release
	end


SouthShoreHouseSableye::
	lock
	faceplayer
	playmoncry SPECIES_SABLEYE, CRY_MODE_NORMAL
	msgbox SouthShoreHouseSableye_Text_0
	waitmoncry
	release
	end


SouthShoreHouseMan_Text_0:
	.string "你必须拿着镜子，\n跟随乌鸦，找到那头\l野兽的巢穴。$"

SouthShoreHouseMan_Text_1:
	.string "我的祖辈总爱讲这样的故事：\n有一头野兽藏在森林深处。\p普通人无论怎么找，\n都别想找到它，\l因为它栖身于一条小路，\l只有一面不映照主人的镜子\l才能让这条路显现。\p我怀疑世上是否真有这样的东西。$"

SouthShoreHouseMan_Text_2:
	.string "哦！你手里的那个东西！那和\n我爷爷描述给我听的\l物件一模一样！\p没想到那些故事是真的。\p他说，只要跟着乌鸦，\n就能找到那条路。\p训练家，祝你顺利找到野兽。$"

SouthShoreHouseSableye_Text_0:
	.string "勾魂眼：叽哩咕噜噜噜！$"
