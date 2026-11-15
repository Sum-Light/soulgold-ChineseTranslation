CeladonCity_House1_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "您好！\p我们现在正在举办大胃王比赛。\p现在没法为您服务，\n抱歉。$"
	.string ""
	.string ""
	.string ""

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "……吸溜，吧唧吧唧……$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "别跟我说话！\p你害我分心了！$"
	.string ""

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "……咕咚……吧唧……$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "我讲究数量大于质量！\p吃饱了我就开心！$"
	.string ""

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "吧唧，吧唧……$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "这里的饭菜很好吃，\n不过要说最好吃的，\l还得是满金市。$"
	.string ""
	.string ""

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "咔嚓……咔嚓……$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "这里没人会给你代币盒。\n你该去城都地区找找看。$"
	.string ""

CeladonCity_House1_Text_TeacherKeepEating:
	.string "咔嚓……咔嚓……\p我还能继续吃！\p再来一份，厨师！$"
	.string ""
	.string ""

CeladonCity_House1_Text_EatathonContestPoster:
	.string "大胃王比赛！不限时间！\p永无止境的对决！\n吃得最多的人，全部免单！$"
	.string ""
	.string ""

