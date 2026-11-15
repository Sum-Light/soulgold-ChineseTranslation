VajraDesertWest_2_MapScripts::
	.byte 0


VajraCrossroad_Girl::
	msgbox VajraCrossroad_Girl_Text_0, MSGBOX_NPC
	return


VajraCrossroad_Sign::
	msgbox VajraCrossroad_Sign_Text_0, MSGBOX_SIGN
	return


VajraCrossroad_SignBP::
	msgbox VajraCrossroad_SignBP_Text_0, MSGBOX_SIGN
	return


VajraCrossroad_Girl_Text_0:
	.string "世界各地的许多强大训练家都会\n来到我们村子，参加\l对战金字塔的挑战。\p它是前些时候从丰缘地区\n搬到这里来的。$"

VajraCrossroad_Sign_Text_0:
	.string "{LEFT_ARROW} 古金字塔\n"
	.string "{RIGHT_ARROW} 林都村$"

VajraCrossroad_SignBP_Text_0:
	.string "金刚金字塔，欢迎勇敢的训练家！$"
