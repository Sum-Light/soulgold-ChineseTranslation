
Route33_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "我是穿过隧道过来的，\n可我还剩着\l一身力气呢。$"
	.string ""
	.string ""

Route33_Text_HikerAnthony2Beaten:
	.string "哦！你比我\n还有干劲！$"
	.string ""

Route33_Text_HikerAnthony2After:
	.string "我们登山男在山里\n才是最精神的。$"
	.string ""

Route33_Text_HikerAnthonyDunsparce:
	.string "嘿，你抓到土龙弟弟了吗？\p我也抓到了一只。\p在亮处好好看看它。\n它长着一张好笑的脸！$"
	.string ""
	.string ""
	.string ""

Route33_Text_Lass:
	.string "呼、呼……\p那个洞比我想象中\n还要大。\p找玛力露找得太累了，\n我就先出来了。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route33_HiddenGrotto::
	msgbox Route33_HiddenGrotto_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route33_HiddenGrotto_2
Route33_HiddenGrotto_1:
	release
	end

Route33_HiddenGrotto_2:
	warp MAP_HIDDEN_GROTTO_ROUTE33, 0
	waitstate
	goto Route33_HiddenGrotto_1


fisherMan_Route33::
	lock
	faceplayer
	msgbox fisherMan_Route33_Text_0
	release
	end


Route33_HiddenGrotto_Text_0:
	.string "树丛后面似乎有条小路。\n要进去吗？$"

fisherMan_Route33_Text_0:
	.string "听说这南边的海兔兽群里，\n游着一只非常稀有的宝可梦。$"
