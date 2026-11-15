
Route46_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "好嘞！让你见识见识\n山中宝可梦的力量！$"
	.string ""

Route46_Text_HikerBaileyBeaten:
	.string "饶了我吧！\n我见识到你的力量了！$"
	.string ""

Route46_Text_HikerBaileyAfterBattle:
	.string "输就输了，我不在意。\n我们登山迷就是这样。$"
	.string ""

Route46_Text_CamperTedSeen:
	.string "我也在培育宝可梦！\p你能和我对战吗？$"
	.string ""

Route46_Text_CamperTedBeaten:
	.string "哎……？$"

Route46_Text_CamperTedAfterBattle:
	.string "我尽力了，可还是\n差了一截。\p不找借口——我认输。$"
	.string ""
	.string ""

Route46_Text_PicnickerErinSeen:
	.string "我也在培育宝可梦！\p你能和我对战吗？$"
	.string ""

Route46_Text_PicnickerErinBeaten:
	.string "可恶！$"

Route46_Text_PicnickerErinAfterBattle:
	.string "我去过很多道馆，\n但最喜欢满金的道馆。\p那里开满了漂亮的花！$"
	.string ""
	.string ""

Route46_Text_PicnickerErin2Beaten:
	.string "唉……我总是输！\p我只好再加把劲了！\n谢谢你一次又一次\n陪我打。\p上次说好的礼物，\n现在给你。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route46_Text_Sign:
	.string "46号道路\n前方为山路$"
	.string ""

Route46_ConfusedBugCatcher::
	lock
	faceplayer
	msgbox Route46_ConfusedBugCatcher_Text_0
	release
	end


Route46_ConfusedBugCatcher_Text_0:
	.string "嗯，我还以为从这儿能去\n"
	.string "烟墨市呢。台阶爬不上去。$"
