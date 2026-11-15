SouthPassageEnd_MapScripts::
	.byte 0


SouthPassageSign::
	msgbox SouthPassageSign_Text_0, MSGBOX_SIGN
	return


SouthPassageAriana::
	lock
	faceplayer
	msgbox SouthPassageAriana_Text_0
	turnobject LOCALID_SP_ARIANA, DIR_NORTH
	msgbox SouthPassageAriana_Text_1
	faceplayer
	msgbox SouthPassageAriana_Text_2
	closemessage
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_SP_ARIANA
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setflag FLAG_SOUTHPASSAGE_ARIANA
	release
	end


SouthPassageSign_Text_0:
	.string "研究所重地，闲人免进！\p文字已褪色，难以辨认。$"

SouthPassageAriana_Text_0:
	.string "哦，是你啊。\p没想到你会跑到\n这种地方来。$"

SouthPassageAriana_Text_1:
	.string "阿波罗派我来这里查点东西。\p这地方一直在以火箭队的\n名义从事非法活动。\p连坂木都没有批准过。\p他一得知消息，就下令\n停止这些活动，参与其中的\l科学家和手下全被开除了。$"

SouthPassageAriana_Text_2:
	.string "他们想烧掉所有证据，但很快\n就被抓住了。\p你想四处看看的话，我不拦你，\n但别指望能找到什么。\p我要的东西已经到手，\n这就回去了。$"
