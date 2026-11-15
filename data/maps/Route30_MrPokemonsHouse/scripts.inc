

Route30_MrPokemonsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 60
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
    createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
    removefieldmugshot
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
    createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT
    removefieldmugshot
	giveitem ITEM_MYSTERY_EGG

    createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
    removefieldmugshot
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
    createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
    removefieldmugshot
	playbgm MUS_HG_OAK, TRUE
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
    createfieldmugshot MUGSHOT_OAK
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
    removefieldmugshot


	playfanfare MUS_OBTAIN_ITEM
	message MrPokemonHouse_Text_GetDex
	waitfanfare

    createfieldmugshot MUGSHOT_OAK
	msgbox MrPokemonHouse_Text_OakParting MSGBOX_DEFAULT
	closemessage
    removefieldmugshot
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ROUTE30_OAK
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
    createfieldmugshot MUGSHOT_GENTLEMAN
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
    removefieldmugshot
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2
	
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_DEXNAV_OBTAINED
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE

	release
	end

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end	

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_FAIRYTITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
	.string "你好你好！你一定是\n{PLAYER}吧。\p空木博士说你会\n过来一趟。$"
	.string ""
	.string ""
	.string ""

MrPokemonHouse_Text_Intro2:
	.string "这就是我想请空木博士\n调查的东西。$"
	.string ""

MrPokemonHouse_Text_GotEgg:
	.string "{PLAYER}得到了神奇蛋。$"

MrPokemonHouse_Text_Intro3:
	.string "我认识一对经营\n宝可梦培育屋的夫妇。\p这颗蛋就是他们给我的。\p我觉得有意思，\n就写信告诉了空木博士。\p说到宝可梦的进化，\n空木博士可是权威。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""


MrPokemonHouse_Text_Intro4:
	.string "连大木博士都\n认可这一点。$"
	.string ""

MrPokemonHouse_Text_Intro5:
	.string "如果我的推测没错，\n空木博士会知道这是什么。$"
	.string ""

MrPokemonHouse_Text_Heal:
	.string "你要回空木博士那里去？\p来，让你的宝可梦\n好好休息一下。$"
	.string ""
	.string ""

MrPokemonHouse_Text_DependingOnYou:
	.string "就拜托你了！$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "生活真有趣！\n总会有新的发现。$"
	.string ""

MrPokemonHouse_Text_OakIntro:
	.string "大木博士：啊哈！你就是\n{PLAYER}吧！\p我是大木！\n一名宝可梦研究者。\p我正好来拜访老朋友\n宝可梦爷爷。\p听说你在替空木博士\n跑腿，我就在这儿等了。\p哦！这是什么？\n稀有的宝可梦！\p让我看看……\n嗯，我明白了！\p我明白空木博士为什么\n会为这点差事给你宝可梦了。\p对空木博士和我这样的\n研究者来说，宝可梦是朋友。\p他看出你会用心\n爱护自己的宝可梦。\p……啊！\p你看起来很可靠。要不要\n来帮我一个忙？\p看吧？这是最新型的\n宝可梦图鉴。\p它会自动记录你见过或\n捉到的宝可梦的数据。\p这可是高科技的\n百科全书！\p上面记载着它们的栖息地、\n进化方式，还有招式。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MrPokemonHouse_Text_GetDex:
	.string "{PLAYER}得到了宝可梦图鉴！$"

MrPokemonHouse_Text_OakParting:
	.string "去遇见各种各样的宝可梦，\n把图鉴完成吧！\p不过我待得太久了。\p我得去满金市，\n照常上我的电台节目。\p{PLAYER}，就拜托你了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MrPokemonHouse_Text_GimmeTheScale:
	.string "嗯？那个鳞片！是什么？\n红色的暴鲤龙？\p那可太稀罕了！我，我想要……\p{PLAYER}，你愿意\n跟我换吗？\p我可以用大木博士给我的\n这块超级石来换。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MrPokemonHouse_Text_Disappointed:
	.string "真遗憾。\n那可是非常稀有的东西。$"
	.string ""

MrPokemonHouse_Text_ExpShare:
	.string "我还有一件特别的\n东西要送给你。$"
	.string ""

MrPokemonHouse_Text_ForeignMagazines:
	.string "里面塞满了外文\n杂志。\p连标题都看不懂……$"
	.string ""
	.string ""

MrPokemonHouse_Text_BrokenComputer:
	.string "一台大电脑。\n唔，已经坏了。$"
	.string ""

MrPokemonHouse_Text_StrangeCoins:
	.string "好一大堆奇怪的硬币！\p说不定是从别的\n国家来的……$"
	.string ""
	.string ""

MrPokemonHouse_Text_GotExpShare:
	.string "{PLAYER}得到了\n妖精属性进化石！$"
