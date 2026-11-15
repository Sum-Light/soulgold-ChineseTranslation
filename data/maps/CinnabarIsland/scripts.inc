.set LOCALID_CINNABAR_BLUE, 1
.set LOCALID_CINNABAR_BLAINE, 12

CinnabarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_OnLoad
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end
	
CinnabarIsland_OnLoad::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
    .string "夏伯：我绝不放弃，\n直到重建好红莲道馆\l的那一天！\p在那之前，\n我会一直待在格斗道场。$"
	.string ""
	.string ""
	.string ""
	.string ""



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "你是谁？\p嗯，一眼就能看出来，\n你是个训练家……\p我叫青绿。\p我曾经当过冠军，\n不过只当了很短一阵子……\p都是那个多管闲事的赤红\n害的……\p算了，你有何贵干？\n是想来挑战我的吗？\p……虽然不想这么说，\n但我现在没心情对战。\p好好看看你的四周……\p火山一喷发，整座城镇\n转眼间就消失了。\p宝可梦对战里，我们\n尽可以有输有赢。可大自然\l稍微一动，我们转眼就输了。\p……\p事情就是这样……\p不过，我毕竟还是个训练家。\p一看到强大的对手，\n就会忍不住想打一场。\p想和我对战的话，\n你得先拿到15枚徽章。\p到那时我就接受你的挑战。$"
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

CinnabarIsland_Text_Blue:
	.string "你是谁？\p嗯，一眼就能看出来，\n你是个训练家……\p我叫青绿。\p我曾经当过冠军，\n不过只当了很短一阵子……\p都是那个多管闲事的赤红\n害的……\p算了，你有何贵干？\n是想来挑战我的吗？\p……虽然不想这么说，\n但我现在没心情对战。\p好好看看你的四周……\p火山一喷发，整座城镇\n转眼间就消失了。\p宝可梦对战里，我们\n尽可以有输有赢。可大自然\l稍微一动，我们转眼就输了。\p……\p事情就是这样……\p不过，我毕竟还是个训练家。\p一看到强大的对手，\n就会忍不住想打一场。\p想和我对战的话，\n就到常青道馆来吧。\p到那时我就接受你的挑战。$"
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

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "这里贴着一张告示……\p红莲道馆已经搬到\n双子岛了。\p夏伯$"
	.string ""
	.string ""
	.string ""

CinnabarIsland_Text_Sign:
	.string "红莲镇\p燃烧着热情的火焰城镇$"
	.string ""

