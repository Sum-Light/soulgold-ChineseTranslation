
Route40_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	.byte 0

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "下水前要先做热身运动。\p这是基本常识。$"
	.string ""
	.string ""

Route40_Text_SwimmermSimonBeaten:
	.string "好啦好啦！我认输！$"

Route40_Text_SwimmermSimonAfter:
	.string "这里到湛蓝市\n还有好一段路呢。$"
	.string ""

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end


BattleTower_Outside_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_SwimmermRandallSeen:
	.string "喂，你年轻力壮的！\p别骑在宝可梦身上！\n自己游！$"
	.string ""
	.string ""

Route40_Text_SwimmermRandallBeaten:
	.string "糟了，我输了……$"

Route40_Text_SwimmermRandallAfter:
	.string "游泳能锻炼全身，\n有益健康。$"
	.string ""

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "你要去湛蓝市吗？\p先来快速对战一场\n怎么样？$"
	.string ""
	.string ""

Route40_Text_SwimmerfElaineBeaten:
	.string "这一场是我输了！$"

Route40_Text_SwimmerfElaineAfter:
	.string "论游泳，我肯定\n比你厉害。没错！$"
	.string ""

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "我才不用游泳圈。\p我抱住海里的宝可梦\n就行了！$"
	.string ""
	.string ""

Route40_Text_SwimmerfPaulaBeaten:
	.string "哎呀，我有点头晕！$"

Route40_Text_SwimmerfPaulaAfter:
	.string "这里的阳光比别处\n暖和舒服多了。$"
	.string ""

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "虽然从这里看不见，\n但湛蓝市就在海对岸。$"
	.string ""

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "我坐船来浅葱市观光，\n顺便感受一下\l这里的气氛。\p港口城市果然\n和大城市很不一样。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "你去过对战塔吗？\p我想已经有很多\n厉害的训练家聚集在那里了。\p不过你有那么多徽章，\p应该不会吃亏的。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route40_Text_Monica:
	.string "星琪怡：很高兴见到你。\n我是星期兄弟里的星琪怡。\p你肯定猜不出我最喜欢\n星期几！$"
	.string ""
	.string ""
	.string ""

Route40_Text_MonicaGivesGift:
	.string "答对了！\p作为我们友情的纪念，\n我送你一件礼物！$"
	.string ""
	.string ""

Route40_Text_MonicaGaveGift:
	.string "星琪怡：这是能提升\n飞行属性招式威力的道具。\p给鸟宝可梦带上\n这个道具吧。$"
	.string ""
	.string ""
	.string ""

Route40_Text_MonicaMonday:
	.string "星琪怡：我的兄弟姐妹\n分散在各个地方。\p你去把他们\n全都找出来吧！$"
	.string ""
	.string ""
	.string ""

Route40_Text_MonicaNotMonday:
	.string "星琪怡：今天好像\n不是星期一。好可惜……$"
	.string ""

Route40_Text_MonicaNope:
	.string "不对哦。$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end

TuberGirlRoute40::
	msgbox TuberGirlRoute40_Text_0, MSGBOX_NPC
	return


CafeSignRoute40::
	msgbox CafeSignRoute40_Text_0, MSGBOX_SIGN
	return


BattleTowerBaldingMan::
	msgbox BattleTowerBaldingMan_Text_0, MSGBOX_NPC
	return


TuberGirlRoute40_Text_0:
	.string "我身后的咖啡馆\n卖好吃的食物哦！$"

CafeSignRoute40_Text_0:
	.string "浅葱海滨咖啡馆！\n全天供应小吃和正餐！$"

BattleTowerBaldingMan_Text_0:
	.string "我要成为第一个\n进入对战塔的人！$"
