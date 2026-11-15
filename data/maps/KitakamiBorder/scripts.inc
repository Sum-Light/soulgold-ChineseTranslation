KitakamiBorder_MapScripts::
	.byte 0


KitakamiBorder_OldLady::
	msgbox KitakamiBorder_OldLady_Text_0, MSGBOX_NPC
	return


KitakamiBorder_HikerMoulder::
	trainerbattle_single TRAINER_MOULDER, KitakamiBorder_HikerMoulder_Text_0, KitakamiBorder_HikerMoulder_Text_1
	msgbox KitakamiBorder_HikerMoulder_Text_2, MSGBOX_AUTOCLOSE
	return


KitakamiBorder_OldLady_Text_0:
	.string "我常来这儿，眺望这边\n和白银山之间的山谷。\p心里就平静下来了。$"

KitakamiBorder_HikerMoulder_Text_0:
	.string "你是要去北上村吗？$"

KitakamiBorder_HikerMoulder_Text_1:
	.string "好好欣赏风景吧！$"

KitakamiBorder_HikerMoulder_Text_2:
	.string "我几乎每个月都会来这儿一趟！$"
