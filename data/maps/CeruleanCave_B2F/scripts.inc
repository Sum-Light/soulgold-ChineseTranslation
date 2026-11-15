
CeruleanCave_B2F_MapScripts::
	.byte 0

CeruleanCave3_EventScript_MewtwoNew::
	lock
	faceplayer
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_MEWTWO, 80
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CeruleanCave3_EventScript_MewtwoRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CERULEANCAVE_MEWTWO
	setflag FLAG_HIDE_MEWTWO
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

CeruleanCave3_EventScript_MewtwoRan::
	release
	end

NamelessDungeonMewtwo::
	lock
	faceplayer
	bosslegendaryencounterwithmoves SPECIES_MEWTWO, 80, LOCALID_CERULEANCAVE_MEWTWO, FLAG_HIDE_MEWTWO, 4, SPECIES_NONE, 110, MOVE_PSYSTRIKE, MOVE_ICE_BEAM, MOVE_FIRE_BLAST, MOVE_TAUNT, BOSS_PHASE_PROFILE_MEWTWO
	release
	end


NamelessDungeon_Leaf::
	lock
	goto_if_unset FLAG_TEMP_3, NamelessDungeon_Leaf_2
NamelessDungeon_Leaf_1:
	faceplayer
	msgbox NamelessDungeon_Leaf_Text_4, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NamelessDungeon_Leaf_5
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox NamelessDungeon_Leaf_Text_6
	trainerbattle_no_intro TRAINER_NAMELESS_LEAF, NamelessDungeon_Leaf_Text_7
	createfieldmugshot MUGSHOT_LEAF
	msgbox NamelessDungeon_Leaf_Text_8
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_LEAF_NAMELESS
	setflag FLAG_POSTGAME_CAP1
	playse SE_EXIT
	removeobject LOCALID_NAMELESS_LEAF
	delay 60
	fadescreen FADE_FROM_BLACK
	release
	end

NamelessDungeon_Leaf_2:
	msgbox NamelessDungeon_Leaf_Text_0
	delay 30
	playse SE_PIN
	applymovement LOCALID_NAMELESS_LEAF, Common_Movement_ExclamationMark
	faceplayer
	waitse
	createfieldmugshot MUGSHOT_LEAF
	msgbox NamelessDungeon_Leaf_Text_1
	turnobject LOCALID_NAMELESS_LEAF, DIR_WEST
	msgbox NamelessDungeon_Leaf_Text_2
	faceplayer
	msgbox NamelessDungeon_Leaf_Text_3
	setflag FLAG_TEMP_3
	goto NamelessDungeon_Leaf_1

NamelessDungeon_Leaf_5:
	msgbox NamelessDungeon_Leaf_Text_5
	turnobject LOCALID_NAMELESS_LEAF, DIR_SOUTH
	release
	end


NamelessDungeon_Leaf_Text_0:
	.string "？？？：嗯，超梦应该就在前面……$"

NamelessDungeon_Leaf_Text_1:
	.string "？？？：哦，你好！你是哪位？\p……\p哦，你叫{PLAYER}啊？\n很高兴认识你！\p我叫叶子。\p我正在寻找比普通的稀有宝可梦\n还要更稀有的宝可梦。$"

NamelessDungeon_Leaf_Text_2:
	.string "我一路追查到了这个洞窟，\n它唯一可能藏身的地方，\l就在这片水域的对面。$"

NamelessDungeon_Leaf_Text_3:
	.string "勾起你的兴趣了吧？\p这也难怪，听说这只宝可梦\n是用其他宝可梦的基因\l制造出来的实验体呢！\p不过很可惜，是我先到的！\p想让我改变主意，\n就只有在对战中打赢我了。$"

NamelessDungeon_Leaf_Text_4:
	.string "怎么样？有兴趣吗？\n不过我可提醒你，\l我真的很强哦！$"

NamelessDungeon_Leaf_Text_5:
	.string "啊，真可惜，\n我还盼着你答应呢。$"

NamelessDungeon_Leaf_Text_6:
	.string "太好了！准备好被我痛打一顿吧！$"

NamelessDungeon_Leaf_Text_7:
	.string "可恶，你真厉害！$"

NamelessDungeon_Leaf_Text_8:
	.string "说实话，\n这我可真没想到！\p你对战起来简直是个怪物！\p什么？你是这个地区的冠军？\p哦……\p那就难怪了！\p总之，按照约定，\n这只就让给你了。不过你记住，\l下次见面我一定会赢过你！\p回头见！$"
