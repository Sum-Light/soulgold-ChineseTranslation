.set LOCALID_ROUTE_30_JOEY, 6

Route30_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 30
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "宝可梦爷爷的家$"

Route30_Text_UseTackle:
	.string "上吧，小拉达！\p撞击！$"
	.string ""

Route30_Text_ThisIsABigBattle:
	.string "什么？这可是很重要的决斗！\n别来烦我！$"
	.string ""

Route30_Text_YoungsterJoey1Seen:
	.string "我刚才输了一场，正在找\n更多的宝可梦。\p等等！你看起来很弱！\n来对战吧！$"
	.string ""
	.string ""
	.string ""

Route30_Text_YoungsterJoey1Beaten:
	.string "啊！我又输了！\n真可恶！$"
	.string ""

Route30_Text_YoungsterJoey1After:
	.string "要变得更强，就必须\n多带几只宝可梦吗？\p不！我就坚持用这一只，\n不管发生什么！$"
	.string ""
	.string ""
	.string ""

Route30_Text_YoungsterMikeySeen:
	.string "你是宝可梦训练家吧？\p那就来对战吧！$"
	.string ""
	.string ""

Route30_Text_YoungsterMikeyBeaten:
	.string "真奇怪。\n刚才我明明赢了。$"
	.string ""

Route30_Text_YoungsterMikeyAfter:
	.string "想成为优秀的训练家，\n真的很不容易。\p我要到处和人\n对战，变得更强。$"
	.string ""
	.string ""
	.string ""

Route30_Text_BugCatcherDonSeen:
	.string "没找到虫宝可梦，\n倒是发现了训练家！$"
	.string ""

Route30_Text_BugCatcherDonBeaten:
	.string "啊呜！你太强了！$"

Route30_Text_BugCatcherDonAfter:
	.string "抓宝可梦的时候，\n精灵球用完了。\p早知道就多买一些了……$"
	.string ""
	.string ""

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "宝可梦爷爷的家？\n就在前面不远。$"
	.string ""

Route30_Text_YoungsterEveryoneIsBattling:
	.string "大家都在开心地\n对战呢！\p你也去试试吧！$"
	.string ""
	.string ""

Route30_Text_CooltrainerF:
	.string "我可不是训练家。\p不过要是和训练家对上眼，\n就要做好对战的准备。$"
	.string ""
	.string ""

Route30_Text_Sign:
	.string "30号道路\p桔梗市——吉花市$"
	.string ""

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "宝可梦爷爷的家\n就在正前方！$"
	.string ""

Route30_Text_MrPokemonsHouseSign:
	.string "宝可梦爷爷的家$"

Route30_Text_TrainerTips:
	.string "训练家提示\p不可以偷别人的\n宝可梦！\p精灵球只能投向\n野生的宝可梦！$"
	.string ""
	.string ""
	.string ""
	.string ""

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "我又输了……\n你可真强！\p对了，我差点忘了，\n这个要交给你。\p用它变得更强吧，\n好吗？\p我也会变得更强的。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route30_Text_Elm_Disaster:
	.string "空木博士：喂、喂？是{PLAYER}吗？\n出大事了！\p那个，嗯，真是太糟糕了！\p该怎么办才好？它……\n不，糟了……\p总之请你马上回来！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""


Route30_Text_Poliwag:
	.string "蚊香蝌蚪：呱哇哇！$"
