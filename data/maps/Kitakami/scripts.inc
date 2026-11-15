Kitakami_MapScripts::
	.byte 0


Kitakami_OldLady::
	msgbox Kitakami_OldLady_Text_0, MSGBOX_NPC
	return


Kitakami_Trigger::
	setflag FLAG_VISITED_KITAKAMI
	setvar VAR_KITAKAMI_STATE, 1
	end


Kitakami_OgerponTrigger::
	lock
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	turnobject LOCALID_KITAKAMI_OGERPON, DIR_SOUTH
	applymovement LOCALID_KITAKAMI_OGERPON, Common_Movement_ExclamationMark
	delay 30
	playmoncry SPECIES_OGERPON, CRY_MODE_NORMAL
	waitmoncry
	playse SE_LEDGE
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_0
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_0
	waitmovement 0
	playmoncry SPECIES_OGERPON, CRY_MODE_NORMAL
	waitmoncry
	delay 20
	playse SE_LEDGE
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_2
	waitmovement 0
	waitse
	playse SE_LEDGE
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_2
	waitmovement 0
	waitse
	playse SE_LEDGE
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_2
	waitmovement 0
	waitse
	playse SE_LEDGE
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_2
	waitmovement 0
	waitse
	setflag FLAG_HIDE_KITAKAMI_OGERPON
	removeobject LOCALID_KITAKAMI_OGERPON
	setvar VAR_KITAKAMI_STATE, 2
	release
	end


Kitakami_Fatman::
	msgbox Kitakami_Fatman_Text_0, MSGBOX_NPC
	return


Kitakami_Battlegirl::
	msgbox Kitakami_Battlegirl_Text_0, MSGBOX_NPC
	return


Kitakami_Littlegirl::
	msgbox Kitakami_Littlegirl_Text_0, MSGBOX_NPC
	return


Kitakami_WestSign::
	msgbox Kitakami_WestSign_Text_0, MSGBOX_SIGN
	return


Kitakami_WellSign::
	msgbox Kitakami_WellSign_Text_0, MSGBOX_SIGN
	return


Kitakami_OgerponTrigger_Movement_0:
	jump_in_place_down
	delay_16
	step_end

Kitakami_OgerponTrigger_Movement_1:
	jump_in_place_up
	delay_16
	step_end

Kitakami_OgerponTrigger_Movement_2:
	jump_up
	step_end

Kitakami_OldLady_Text_0:
	.string "哦？是客人吗？你是从哪儿来的？\n……\l若叶镇？跑到这儿来，\l可真是一段远路啊！$"

Kitakami_Fatman_Text_0:
	.string "这地方连点现代科技都没有！\n我到底该干点什么啊？？$"

Kitakami_Battlegirl_Text_0:
	.string "我每年都来这儿修行一次。\n这里正好介于繁忙的城市生活\l和严酷的白银山之间。$"

Kitakami_Littlegirl_Text_0:
	.string "妈妈以前说，坏孩子会被抓到\n下面那个洞里去。\p那里是吉雉鸡\n夏天栖息的地方。$"

Kitakami_WestSign_Text_0:
	.string "北上村 - 亘古不变的传统$"

Kitakami_WellSign_Text_0:
	.string "老井 - 上下梯子请当心！$"
