Route42_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route42_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route42_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route42_MapScript_HideTrigger::
	setvar VAR_TEMP_0, 1
	return

Route42_EventScript_Suicune_Trigger::
	lock
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0

	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune3
	applymovement OBJ_EVENT_ID_PLAYER, Route42_Movement_Player
	playse SE_LEDGE
	delay 60
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	waitmovement LOCALID_ROUTE42_SUICUNE
	waitmovement 0
	delay 60
	removeobject LOCALID_ROUTE42_SUICUNE
	setflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_HIDE_ROUTE42_EUSINE
	addobject LOCALID_ROUTE42_EUSINE
	playse SE_EXIT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine1
	waitmovement 0
	msgbox Route42_Text_EusineAdmireSuicune, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE42_EUSINE, DIR_WEST
	msgbox Route42_Text_EusineJealous, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE42_EUSINE, DIR_EAST
	msgbox Route42_Text_EusineWontGiveUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine2
	waitmovement 0
	setflag FLAG_HIDE_ROUTE42_EUSINE
	removeobject LOCALID_ROUTE42_EUSINE
	setvar VAR_TEMP_0, 1
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 2, Route42_EventScript_DoneJohtoSuicune
	release
	end

Route42_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

Route42_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	step_end

Route42_Movement_Suicune2:
	jump_2_left
	jump_2_left
	jump_2_left
	jump_2_up
	step_end

Route42_Movement_Suicune3:
	jump_in_place_up
	delay_2
	face_up
	jump_2_up
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

Route42_Movement_Player:
	lock_facing_direction
	delay_2
	jump_2_up
	unlock_facing_direction
	step_end

Route42_Movement_Eusine1:
	walk_down
	walk_down
	walk_left
	face_right
	step_end

Route42_Movement_Eusine2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route42_Text_EusineAdmireSuicune:
	.string "米那君：水君……\n多么勇敢！\p多么清爽！\n多么美丽！\p而且动作多么迅速！$"
	.string ""
	.string ""
	.string ""
	.string ""

Route42_Text_EusineJealous:
	.string "{PLAYER}！\p你好像总出现在\n水君会出现的地方。\p算了，没关系。\n我追寻水君的心情\l可比你强烈得多……\p我爷爷……对神话\n相当着迷。\p水君的故事，我从爷爷\n那儿听了不知多少。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route42_Text_EusineWontGiveUp:
	.string "水君……\n我会一直追着你，\l直到查明你究竟\l在追寻什么……\p你听见了吗！$"
	.string ""
	.string ""
	.string ""
	.string ""


Route42_EventScript_Tully::
	trainerbattle_single TRAINER_TULLY Route42_Text_FisherTullySeen, Route42_Text_FisherTullyBeaten
	msgbox Route42_Text_FisherTullyAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Ben::
	trainerbattle_single TRAINER_BENJAMIN Route42_Text_HikerBenjaminSeen, Route42_Text_HikerBenjaminBeaten
	msgbox Route42_Text_HikerBenjaminAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE Route42_Text_PokemaniacShaneSeen, Route42_Text_PokemaniacShaneBeaten
	msgbox Route42_Text_PokemaniacShaneAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Sign::
	lock
	msgbox Route42_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_MortarSign::
	lock
	msgbox Route42_Text_MtMortarSign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_Philip::
	trainerbattle_single TRAINER_PHILIP Route42_Text_SawyerIntro, Route42_Text_SawyerDefeat
	msgbox Route42_Text_SawyerPostBattle, MSGBOX_AUTOCLOSE
	end

Route42_Text_SawyerIntro:
	.string "喂，你！\n把宝可梦交出来！$"
	.string ""

Route42_Text_SawyerDefeat:
	.string "哎呀呀！\n那我付钱给你吧！$"
	.string ""

Route42_Text_SawyerPostBattle:
	.string "听说有人在附近\n看见了火箭队……$"
	.string ""

Route42_Text_FisherTullySeen:
	.string "让你见识一下我抓到的\n宝可梦有多强！$"
	.string ""

Route42_Text_FisherTullyBeaten:
	.string "什么？不可能。\n我简直不敢相信！$"
	.string ""

Route42_Text_FisherTullyAfter:
	.string "我想用自己亲手钓到的\n宝可梦\l成为训练家冠军。\p这才是钓鱼的最大乐趣！$"
	.string ""
	.string ""
	.string ""

Route42_Text_HikerBenjaminSeen:
	.string "啊，还是户外好啊！\n感觉真自由！$"
	.string ""

Route42_Text_HikerBenjaminBeaten:
	.string "哇哈哈！打得真痛快！$"
	.string ""

Route42_Text_HikerBenjaminAfter:
	.string "抬头看看广阔的天空，\n输赢就变得微不足道了！$"
	.string ""

Route42_Text_PokemaniacShaneSeen:
	.string "喂！\p这里是我的秘密地点！\n外人快走开！$"
	.string ""
	.string ""

Route42_Text_PokemaniacShaneBeaten:
	.string "早知道就该用\n月之石的……$"
	.string ""

Route42_Text_PokemaniacShaneAfter:
	.string "你在收集宝可梦图鉴？\p哇，那你一定认识\n不少稀有的宝可梦！\p能让我看看吗？\n求你了！$"
	.string ""
	.string ""
	.string ""
	.string ""

Route42_Text_Sign1:
	.string "42号道路\p缘朱市——卡吉镇$"
	.string ""

Route42_Text_MtMortarSign1:
	.string "擂钵山\p里面是攀瀑洞窟$"
	.string ""
