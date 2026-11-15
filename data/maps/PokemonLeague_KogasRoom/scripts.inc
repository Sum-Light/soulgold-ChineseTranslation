PokemonLeague_KogasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KogasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KogasRoom_OnResume::
	setvar VAR_0x8004, 1
	@special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KogasRoom_EventScript_Koga::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 3, PokemonLeague_KogasRoom_EventScript_KogaDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematch
	msgbox PokemonLeague_KogasRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_1, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematch::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	goto_if_eq VAR_TEMP_1, 1, PokemonLeague_KogasRoom_EventScript_KogaRematchAlt
	trainerbattle_no_intro TRAINER_KOGA_2, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematchAlt::
	trainerbattle_no_intro TRAINER_KOGA_REMATCH_ALT, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaOnDefeat::
	clearflag FLAG_TEMP_5
	createfieldmugshot MUGSHOT_KOGA
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 3
	release
	end

PokemonLeague_KogasRoom_EventScript_KogaDefeated::
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KogasRoom_Text_RematchBefore:
    .string "阿桔：哇哈哈哈哈！\p你回来了，勇敢的挑战者。\p我的忍术更加精进了。\p新的阴险陷阱等着你。\p毒、睡眠，还有更多……\n做好准备！\p哇哈哈哈哈！\p让我看看你成长了多少！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

PokemonLeague_KogasRoom_Text_Before:
    .string "哇哈哈哈哈！\p我是四天王的阿桔。\p我栖身于阴影之中，是一名忍者！\p我这变幻莫测的战法，\n会让你迷惑、溃败！\p混乱、睡眠、毒……\p就等着领教我阴险的\n招数吧！\p哇哈哈哈哈！\p宝可梦可不只是靠蛮力\n就能取胜——你很快就会明白！$"
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

PokemonLeague_KogasRoom_Text_Beaten:
    .string "哦！\n你证明了自己的价值！$"
    .string ""

PokemonLeague_KogasRoom_Text_Defeat:
    .string "我已把会使的招数\n全都用上了。\p但还是未能取胜。我必须\n更加磨练自己。\p去下一个房间吧，\n去检验你的实力！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
