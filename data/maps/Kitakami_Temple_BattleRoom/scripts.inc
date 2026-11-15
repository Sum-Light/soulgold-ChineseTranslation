Kitakami_Temple_BattleRoom_MapScripts::
	.byte 0


BattleRoom_Audino::
	lock
	faceplayer
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
	msgbox BattleRoom_Audino_Text_0
	waitmoncry
	release
	end


BattleRoom_Machamp::
	lock
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox BattleRoom_Machamp_Text_0
	waitmoncry
	release
	end


BattleRoom_Mienshao::
	lock
	playmoncry SPECIES_MIENSHAO, CRY_MODE_NORMAL
	msgbox BattleRoom_Mienshao_Text_0
	waitmoncry
	release
	end


BattleRoom_BattleGirl::
	lock
	msgbox BattleRoom_BattleGirl_Text_0
	playmoncry SPECIES_MIENSHAO, CRY_MODE_NORMAL
	applymovement LOCALID_KITAKAMI_MIENSHAO, BattleRoom_BattleGirl_Movement_0
	waitmovement 0
	waitmoncry
	release
	end


BattleRoom_BlackBelt::
	lock
	msgbox BattleRoom_BlackBelt_Text_0
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	applymovement LOCALID_KITAKAMI_MACHAMP, BattleRoom_BlackBelt_Movement_0
	waitmovement 0
	waitmoncry
	release
	end


BattleRoom_MoneyTrainer::
	lock
	faceplayer
	goto_if_unset FLAG_TEMP_1, BattleRoom_MoneyTrainer_2
BattleRoom_MoneyTrainer_1:
	showmoneybox 0, 0
	msgbox BattleRoom_MoneyTrainer_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BattleRoom_MoneyTrainer_5
	hidemoneybox
	msgbox BattleRoom_MoneyTrainer_Text_6
	release
	end

BattleRoom_MoneyTrainer_2:
	msgbox BattleRoom_MoneyTrainer_Text_0
	setflag FLAG_TEMP_1
	goto BattleRoom_MoneyTrainer_1

BattleRoom_MoneyTrainer_4:
	release
	end

BattleRoom_MoneyTrainer_5:
	checkmoney 10000
	compare VAR_RESULT, FALSE
	goto_if_eq BattleRoom_MoneyTrainer_9
	removemoney 10000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	hidemoneybox
	msgbox BattleRoom_MoneyTrainer_Text_3
	trainerbattle_no_intro TRAINER_DOJO_AUDINO, BattleRoom_MoneyTrainer_Text_4
	msgbox BattleRoom_MoneyTrainer_Text_5
	goto BattleRoom_MoneyTrainer_4

BattleRoom_MoneyTrainer_9:
	msgbox BattleRoom_MoneyTrainer_Text_2
	hidemoneybox
	release
	end


BattleRoom_BattleGirl_Movement_0:
	jump_in_place_left
	jump_in_place_left
	step_end

BattleRoom_BlackBelt_Movement_0:
	jump_in_place_right
	jump_in_place_right
	step_end

BattleRoom_Audino_Text_0:
	.string "差不多娃娃：嗷呜！$"

BattleRoom_Machamp_Text_0:
	.string "怪力：哼哈！$"

BattleRoom_Mienshao_Text_0:
	.string "师父鼬：咪！$"

BattleRoom_BattleGirl_Text_0:
	.string "师父鼬，用飞膝踢！$"

BattleRoom_BlackBelt_Text_0:
	.string "怪力，用守住挡下来！$"

BattleRoom_MoneyTrainer_Text_0:
	.string "您好，我们为来访者\n提供付费训练服务。\p这笔钱将用于资助寺院\n和村子。有意向吗？$"

BattleRoom_MoneyTrainer_Text_1:
	.string "只要¥10,000，就能和\n差不多娃娃、幸福蛋一起训练。$"

BattleRoom_MoneyTrainer_Text_2:
	.string "哎呀，看来您现在\n手头不太宽裕。\p请筹到钱后再来。$"

BattleRoom_MoneyTrainer_Text_3:
	.string "谢谢，我们开始吧。$"

BattleRoom_MoneyTrainer_Text_4:
	.string "感谢您的资助。$"

BattleRoom_MoneyTrainer_Text_5:
	.string "想再训练的话，欢迎再来。$"

BattleRoom_MoneyTrainer_Text_6:
	.string "好的，没关系。$"
