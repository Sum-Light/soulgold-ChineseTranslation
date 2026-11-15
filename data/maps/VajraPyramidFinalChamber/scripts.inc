VajraPyramidFinalChamber_MapScripts::
	.byte 0


FinalChamber_HoopaPrison::
	lock
	goto_if_set FLAG_CAUGHT_HOOPA, FinalChamber_HoopaPrison_2
	msgbox FinalChamber_HoopaPrison_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FinalChamber_HoopaPrison_4
	msgbox FinalChamber_HoopaPrison_Text_3
	release
	end

FinalChamber_HoopaPrison_2:
	msgbox FinalChamber_HoopaPrison_Text_0
	release
	end

FinalChamber_HoopaPrison_4:
	playmoncry SPECIES_HOOPA, 0
	waitmoncry
	bosslegendaryencounter SPECIES_HOOPA, 80, LOCALID_NONE, FLAG_CAUGHT_HOOPA, 3, SPECIES_NONE, 110, BOSS_PHASE_PROFILE_HOOPA
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FinalChamber_HoopaPrison_7
	release
	end

FinalChamber_HoopaPrison_7:
	msgbox FinalChamber_HoopaPrison_Text_2
	finditem ITEM_PRISON_BOTTLE
	release
	end


FinalChamber_HoopaPrison_Text_0:
	.string "装置里面空无一物。$"

FinalChamber_HoopaPrison_Text_1:
	.string "这装置里似乎封印着\n什么东西。要把它放出来吗？$"

FinalChamber_HoopaPrison_Text_2:
	.string "在已经空了的装置底部，\n似乎有什么东西。$"

FinalChamber_HoopaPrison_Text_3:
	.string "妈妈总是告诫我，\n不要碰在古老金字塔深处\l发现的奇怪东西。$"
