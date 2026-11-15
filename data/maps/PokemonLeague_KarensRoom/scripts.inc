PokemonLeague_KarensRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_KarensRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnTransition::
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_SetTitleDefenseWarp
	setdynamicwarp MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM, 0
	end

PokemonLeague_KarensRoom_SetTitleDefenseWarp::
	setdynamicwarp MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM_TITLE_DEFENSE, 0
	end

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	@special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	goto_if_eq VAR_TEMP_1, 1, PokemonLeague_KarensRoom_EventScript_KarenRematchAlt
	trainerbattle_no_intro TRAINER_KAREN_2, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeatPostgame

PokemonLeague_KarensRoom_EventScript_KarenRematchAlt::
	trainerbattle_no_intro TRAINER_KAREN_REMATCH_ALT, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeatPostgame

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	createfieldmugshot MUGSHOT_KAREN
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x40E, FALSE
	setmetatile 6, 2, 0x416, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenOnDefeatPostgame::
    clearflag FLAG_TEMP_5
	createfieldmugshot MUGSHOT_KAREN
	msgbox PokemonLeague_KarensRoom_Text_DefeatPostgame, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x40E, FALSE
	setmetatile 6, 2, 0x416, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeatedPostgame::
	msgbox PokemonLeague_KarensRoom_Text_DefeatPostgame, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
    .string "梨花：啊，又是你。\p我想你没忘记\n我的信念吧：\p真正的强大，源于对\n宝可梦的信赖。\p自从上次交手，\n我和宝可梦的羁绊\l又加深了许多。\p准备好面对一支靠\n坚不可摧的羁绊团结的队伍了吗？\p让我看看你和宝可梦\n之间羁绊的力量吧。$"
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

PokemonLeague_KarensRoom_Text_Before:
    .string "我是四天王的梨花。\p你就是{PLAYER}？真有趣。\p我最爱恶属性的宝可梦。\p它们那种野性、强悍的形象\n实在迷人。而且，它们\l还那么强。\p你觉得能对付得了它们吗？\n就努力让我高兴高兴吧。\p开始吧。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

PokemonLeague_KarensRoom_Text_Beaten:
    .string "哎呀，你还真有两下子。\n我就欣赏这样的训练家。$"
    .string ""

PokemonLeague_KarensRoom_Text_Defeat:
    .string "强大的宝可梦。\p弱小的宝可梦。\p那不过是人们\n自私的看法。\p真正有本领的训练家，\n应该用自己喜爱的宝可梦取胜。\p我欣赏你的风格。你明白\n什么才是最重要的。\p去吧——冠军在等着你。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

PokemonLeague_KarensRoom_Text_DefeatPostgame:
    .string "强大的宝可梦。\p弱小的宝可梦。\p那不过是人们\n自私的看法。\p真正有本领的训练家，\n应该用自己喜爱的宝可梦取胜。\p我欣赏你的风格。你明白\n什么才是最重要的。\p去吧——挑战者就要来了。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
