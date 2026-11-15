Kitakami_Temple_MapScripts::
	.byte 0


megaKickTrainer::
	lock
	msgbox megaKickTrainer_Text_0
	release
	end


megaPunchTrainer::
	lock
	msgbox megaPunchTrainer_Text_0
	release
	end


DojoTourist::
	lock
	faceplayer
	msgbox DojoTourist_Text_0
	release
	end


DojoTrainee::
	lock
	faceplayer
	msgbox DojoTrainee_Text_0
	release
	end


DojoTeacher::
	lock
	faceplayer
	msgbox DojoTeacher_Text_0
	release
	end


DojoTeacher2::
	msgbox DojoTeacher2_Text_0, MSGBOX_NPC
	return


megaKickTrainer_Text_0:
	.string "不对不对，你不明白，\n"
	.string "百万吨重拳才是更强的招式！$"

megaPunchTrainer_Text_0:
	.string "蠢货！谁都知道\n"
	.string "百万吨重踢才是力量的象征！$"

DojoTourist_Text_0:
	.string "这里的传统历经无数代传承，\n至今仍延续不绝。\p真是令人敬佩！$"

DojoTrainee_Text_0:
	.string "我们也为来访者提供付费课程。\p若您想早日变强，\n还请资助本寺。$"

DojoTeacher_Text_0:
	.string "我身后是练习室。\p请留神，不要打扰\n他们修行。$"

DojoTeacher2_Text_0:
	.string "这些门通往\n休息的厢房。$"
