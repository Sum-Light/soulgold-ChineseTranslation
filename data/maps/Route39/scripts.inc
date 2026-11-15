

Route39_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "那个影子……会不会是\n一只巨大的波波？$"
	.string ""

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "大奶罐：哞——！$"

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "我刚回到浅葱市。\p来一场宝可梦对战\n怎么样？$"
	.string ""

Route39_Text_SailorEugeneBeaten:
	.string "哇啊啊——！$"

Route39_Text_SailorEugeneAfter:
	.string "我的宝可梦是在国外\n捕捉并培育的。\p它们是我漫长航海\n旅途中的伙伴。$"
	.string ""
	.string ""
	.string ""

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "现在正是炫耀我的\n皮卡丘的好时机！$"
	.string ""

Route39_Text_PokefanMDerekBeaten:
	.string "我都没机会炫耀\n皮卡丘……$"
	.string ""

Route39_Text_PokefanMDerekAfter:
	.string "我才不听你自吹自擂！\p我们发烧友有个规矩，\n就是不听别人自吹自擂！$"
	.string ""
	.string ""
	.string ""

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "多可爱的宝可梦。\p我们一起来把各自的\n宝可梦展示出来吧。$"
	.string ""
	.string ""

Route39_Text_PokefanFRuthBeaten:
	.string "输了也没关系。$"

Route39_Text_PokefanFRuthAfter:
	.string "你知道幼年宝可梦吗？\p我敢说它们肯定\n特别可爱！$"
	.string ""
	.string ""

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "让我看看你的宝可梦\n有什么本事。$"
	.string ""

Route39_Text_PsychicNormanBeaten:
	.string "哦，你的宝可梦\n很有潜力。$"
	.string ""

Route39_Text_PsychicNormanAfter:
	.string "你知道宝可梦有着\n各种不同的能力吧？\p人也一样，每个人\n都有不同的\l潜力。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "你来得正是\n时候。\p来对战吧。$"
	.string ""
	.string ""

Route39_Text_PokefanFJaimeBeaten:
	.string "唉，真让人失望……$"

Route39_Text_PokefanFJaimeAfter:
	.string "我是在39号道路的这里\n夜里遇见月亮伊布的。\p不知为什么，它好像\n很喜欢我在这里\l训练。\p比起别的地方，在这里\n训练似乎能让它\l更亲近我。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "39号道路\p浅葱市——缘朱市$"
	.string ""

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "哞哞牧场\p请品尝新鲜美味的牛奶$"
	.string ""

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "训练家提示\p对着树使用头锤，\n就能把宝可梦摇下来。\p不同的树会掉下\n不同种类的宝可梦。\p见到的树都用头锤\n撞一撞吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route39_NorthSign::
	msgbox Route39_NorthSign_Text_0, MSGBOX_SIGN
	return


Route39_BaobaTrigger::
	lock
	applymovement LOCALID_R39_BAOBA, Route39_BaobaTrigger_Movement_0
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_ExclamationMark
	waitmovement 0
	approachobject LOCALID_R39_BAOBA, LOCALID_PLAYER, DIR_EAST, DIR_WEST
	waitmovement 0
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox Route39_BaobaTrigger_Text_0
	waitmessage
	removefieldmugshot
	msgbox Route39_BaobaTrigger_Text_1
	waitmessage
	playse MUS_HG_POKEGEAR_REGISTERED
	msgbox Route39_BaobaTrigger_Text_2
	waitse
	createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox Route39_BaobaTrigger_Text_3
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_BaobaTrigger_Movement_1
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	setvar VAR_ROUTE39_BAOBA_STATE, 1
	release
	end


Route39_BaobaTrigger_Movement_0:
	face_right
	step_end

Route39_BaobaTrigger_Movement_1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_NorthSign_Text_0:
	.string "{UP_ARROW} 雪顶山山道$"

Route39_BaobaTrigger_Text_0:
	.string "巴奥巴：……哦哦！\n你手里拿的那个……\l就是传说中的……宝可梦图鉴！\l我已经好久没见过那东西了。\p我叫巴奥巴！\p我以前在浅红市经营狩猎地带，\n可随着各种新奇娱乐项目\l不断出现，那里渐渐\l跟不上时代了。\p于是我决定出国学习\n最新技术，在湛蓝市开一家\l最先进的狩猎地带。\p我们在这里聊上天，\n也许不只是巧合。\p要不要在宝可梦装置里\n互相登录一下号码？\p等狩猎地带开业，我会第一个\n打电话通知你！$"

Route39_BaobaTrigger_Text_1:
	.string "...$"

Route39_BaobaTrigger_Text_2:
	.string "{PLAYER}在宝可梦装置里\n登录了巴奥巴！$"

Route39_BaobaTrigger_Text_3:
	.string "这就对了！等它准备好了，\n我会用宝可梦装置通知你！$"
