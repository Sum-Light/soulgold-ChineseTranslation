PokemonLeague_BrunosRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 2
	@special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_1, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	goto_if_eq VAR_TEMP_1, 1, PokemonLeague_BrunosRoom_EventScript_BrunoRematchAlt
	trainerbattle_no_intro TRAINER_BRUNO_2, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematchAlt::
	trainerbattle_no_intro TRAINER_BRUNO_REMATCH_ALT, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5	
	createfieldmugshot MUGSHOT_BRUNO
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
    .string "希巴：欢迎回来，年轻的\n战士。\p经过严苛的修行，我们\n变得更强了。\p我如岩石般的意志，如今\n更加坚定不屈。\p准备好迎接\n更大的挑战了吗？\p让我看看你修行的成果。\p唔！哈！$"
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

PokemonLeague_BrunosRoom_Text_Before:
    .string "我是四天王的希巴。\p我总是把修行推到极限，\n因为我相信我们的潜力。\p我们就是这样变强的。\p你能承受我们的力量吗？\p嗯？你脸上毫无惧色。\n眼神坚定。正适合一战！\p准备好了吗，{PLAYER}？\n向我们的强大力量低头吧！\p唔！哈！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

PokemonLeague_BrunosRoom_Text_Beaten:
    .string "为什么？我们怎么会输？$"

PokemonLeague_BrunosRoom_Text_Defeat:
    .string "既然输了，我就没有资格\n再说什么……\p去迎接下一个挑战吧！$"
    .string ""
    .string ""
