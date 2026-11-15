Kitakami_Temple_TrainingRoom_MapScripts::
	.byte 0


dojoFexpert::
	lock
	faceplayer
	msgbox dojoFexpert_Text_0
	goto_if_unset FLAG_RECEIVED_FOCUS_SASH, dojoFexpert_2
dojoFexpert_1:
	release
	end

dojoFexpert_2:
	msgbox dojoFexpert_Text_1
	giveitem ITEM_FOCUS_SASH
	setflag FLAG_RECEIVED_FOCUS_SASH
	goto dojoFexpert_1


dojoTrainer::
	lock
	msgbox dojoTrainer_Text_0
	closemessage
	release
	end


dojoFexpert_Text_0:
	.string "锻炼身心与锻炼宝可梦\n同样重要。\p身心柔弱，就无法\n面对艰难的挑战。$"

dojoFexpert_Text_1:
	.string "这个或许能帮您集中精神修行。$"

dojoTrainer_Text_0:
	.string "弟子正在打坐，\n打扰他未免失礼。$"
