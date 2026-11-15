MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "感谢使用\n神秘礼物系统。\p持有这张神秘卡片，\n您就能在友好商店\l参加问卷调查。\p通过问卷调查，\n可以邀请训练家来到琉璃市。\p……告诉您问卷调查\n所需的秘密口令吧：\p“GIVE ME\nAWESOME TRAINER”\p把口令填入问卷，\n再通过无线通信系统发送。$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "感谢使用\n神秘礼物系统。\p一位训练家已经来到\n琉璃市寻找您。\p系统您可以享受\n与训练家的对战。\p您可以邀请其他训练家\n通过填写密码。\p试着找寻其他\n有用的密码吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
