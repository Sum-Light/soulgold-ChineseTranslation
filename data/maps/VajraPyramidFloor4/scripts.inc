VajraPyramidFloor4_MapScripts::
	.byte 0


Floor4_Ghost1::
	trainerbattle_single TRAINER_SPIRIT1, Floor4_Ghost1_Text_0, Floor4_Ghost1_Text_1
	msgbox Floor4_Ghost1_Text_2, MSGBOX_AUTOCLOSE
	return


Floor4_Ghost2::
	trainerbattle_single TRAINER_SPIRIT2, Floor4_Ghost2_Text_0, Floor4_Ghost2_Text_1
	msgbox Floor4_Ghost2_Text_2, MSGBOX_AUTOCLOSE
	return


Floor4_Ghost3::
	trainerbattle_single TRAINER_SPIRIT3, Floor4_Ghost3_Text_0, Floor4_Ghost3_Text_1
	msgbox Floor4_Ghost3_Text_2, MSGBOX_AUTOCLOSE
	return


Floor4_Urn1::
	lock
	goto_if_set FLAG_FLOOR4_URN1LOOT, Floor4_Urn1_2
	finditem ITEM_RELIC_GOLD
	setflag FLAG_FLOOR4_URN1LOOT
	release
	end

Floor4_Urn1_2:
	msgbox Floor4_Urn1_Text_0
	release
	end


Floor4_Urn2::
	lock
	goto_if_set FLAG_FLOOR4_URN2LOOT, Floor4_Urn2_2
	finditem ITEM_RELIC_GOLD
	setflag FLAG_FLOOR4_URN2LOOT
	release
	end

Floor4_Urn2_2:
	msgbox Floor4_Urn1_Text_0
	release
	end


Floor4_Ghost1_Text_0:
	.string "呜！$"

Floor4_Ghost1_Text_1:
	.string "呜……$"

Floor4_Ghost1_Text_2:
	.string "呜呜……$"

Floor4_Ghost2_Text_0:
	.string "给我……$"

Floor4_Ghost2_Text_1:
	.string "被拿走了……$"

Floor4_Ghost2_Text_2:
	.string "丢了……$"

Floor4_Ghost3_Text_0:
	.string "不要放它出来！$"

Floor4_Ghost3_Text_1:
	.string "必须一直封印着……$"

Floor4_Ghost3_Text_2:
	.string "它会把你也吞掉。$"

Floor4_Urn1_Text_0:
	.string "瓮里已经空了。$"
