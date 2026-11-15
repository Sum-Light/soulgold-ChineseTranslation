

Route34_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	call Common_EventScript_SetupRivalGfxId
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_Text_YoungsterSamuel_Seen:
	.string "嘿！我正在找幕下力士！$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "居然被路过的陌生人打败了！$"

Route34_Text_YoungsterSamuel_After:
	.string "我要更加努力地特训。\p毕竟，我的目标是\n当上道馆馆主。$"
	.string ""
	.string ""

Route34_Text_YoungsterIan_Seen:
	.string "在班上，我的宝可梦\n是最厉害的。$"
	.string ""

Route34_Text_YoungsterIan_Beaten:
	.string "不！原来还有更强的\n训练家……$"

Route34_Text_YoungsterIan_After:
	.string "我正在努力，好成为\n班上的明星。$"
	.string ""

Route34_Text_CamperTodd_Seen:
	.string "我对培育宝可梦很有自信。\p想看成果吗？$"
	.string ""
	.string ""

Route34_Text_CamperTodd_Beaten:
	.string "是我的培育方法错了吗？$"

Route34_Text_CamperTodd_After:
	.string "要不把一只送去培育屋，\n或者用些道具……$"
	.string ""

Route34_Text_PicnickerGina_Seen:
	.string "你是训练家吗？\p来陪我练习对战吧。$"
	.string ""

Route34_Text_PicnickerGina_Beaten:
	.string "不行！我怎么就是赢不了……$"

Route34_Text_PicnickerGina_After:
	.string "你太强了，\n没法当练习对手。$"
	.string ""

Route34_Text_OfficerKeith_Seen:
	.string "什么人？\n你在干什么？$"
	.string ""

Route34_Text_OfficerKeith_Win:
	.string "你这个小鬼还挺能打。$"

Route34_Text_OfficerKeith_After:
	.string "嗯，今天没什么异常。\p乖乖的，别惹麻烦。$"
	.string ""

Route34_Text_OfficerKeith_Daytime:
	.string "我在巡逻，查看有没有\n可疑人物。$"
	.string ""

Route34_Text_PokefanBrandon_Seen:
	.string "我的宝可梦刚从培育屋\n接回来。\p让我看看它变强了多少！$"
	.string ""
	.string ""

Route34_Text_PokefanBrandon_Beaten:
	.string "怎么会是这样的结局？$"

Route34_Text_PokefanBrandon_After:
	.string "我的宝可梦回来后\n学会了新招式。\p这可真让我摸不着头脑！$"
	.string ""

Route34_Text_Sign_IlexForest:
	.string "栎树林\n穿过这道门$"
	.string ""

Route34_Text_Sign_Route34:
	.string "34号道路\n满金市——桧皮镇\p栎树林　就在两者之间$"
	.string ""
	.string ""

Route34_Text_TrainerTips:
	.string "训练家提示\p树果树一天会\n结好几次树果。\p记清哪棵树结哪种树果。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route34_Text_CooltrainerIrene_Seen:
	.string "真理纱：呀啊！\n被人发现了！$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "真理纱：呜！你太强了！$"

Route34_Text_CooltrainerIrene_After1:
	.string "真理纱：我姐姐真理亚\n会替我报仇的！$"
	.string ""

Route34_Text_CooltrainerIrene_After2:
	.string "真理纱：这片海滩不错吧？\p这是只属于我们的\n秘密据点！$"
	.string ""

Route34_Text_CooltrainerJenn_Seen:
	.string "真理香：打赢了真理纱，\n可别以为就这么算了！$"
	.string ""

Route34_Text_CooltrainerJenn_Beaten:
	.string "真理香：对不起，真理纱！\n我亲爱的姐姐！$"

Route34_Text_CooltrainerJenn_After1:
	.string "真理香：别得意！我姐姐\n真理亚很厉害的！$"
	.string ""

Route34_Text_CooltrainerJenn_After2:
	.string "真理香：晒晒太阳，\n身体就会变结实。$"
	.string ""

Route34_Text_CooltrainerKate_Seen:
	.string "真理亚：你对我的妹妹们\n可真够狠的！$"
	.string ""

Route34_Text_CooltrainerKate_Beaten:
	.string "真理亚：不！真不敢相信\n我居然输了。$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "真理亚：你太强了，我不是对手。\n这个给你，是你应得的。$"
	.string ""
	.string ""

Route34_Text_CooltrainerKate_After:
	.string "真理亚：突然袭击你，很抱歉。\p我们从没想过会有人找到这里。\n你可真把我们吓了一跳。$"
	.string ""
	.string ""


Route34_Text_Sign_DayCare:
	.string "培育屋\p让我们来培育您的宝可梦吧！$"
	.string ""

Route34_RivalEncounter::
	lock
	applymovement LOCALID_ROUTE34_RIVAL, Common_Movement_ExclamationMark
	applymovement LOCALID_ROUTE34_RIVAL, Route34_RivalEncounter_Movement_0
	playse SE_PIN
	waitse
	waitmovement 0
	playbgm MUS_HG_LYRA, TRUE
	approachobject LOCALID_ROUTE34_RIVAL, LOCALID_PLAYER, DIR_SOUTH, DIR_NORTH
	waitmovement
	applymovement LOCALID_ROUTE34_DAYCAREMAN, Route34_RivalEncounter_Movement_0
	waitmovement
	createfieldmugshotrival
	msgbox Route34_RivalEncounter_Text_0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route34_RivalEncounter_2
	trainerbattle_no_intro TRAINER_RIVALGOLD2, Route34_RivalEncounter_Text_1
Route34_RivalEncounter_1:
	createfieldmugshotrival
	msgbox Route34_RivalEncounter_Text_2
	waitmessage
	playse SE_USE_ITEM
	waitse
	special HealPlayerParty
	msgbox Route34_RivalEncounter_Text_3
	random 7
	addvar VAR_RESULT, 1
	giveoddegg VAR_RESULT
	removefieldmugshot
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq Route34_RivalEncounter_6
	setflag FLAG_RECEIVED_ODD_EGG
	playfanfare MUS_HG_OBTAIN_ITEM
	message Route34_RivalEncounter_Text_5
	waitfanfare
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Route34_RivalEncounter_9
Route34_RivalEncounter_8:
	createfieldmugshotrival
	msgbox Route34_RivalEncounter_Text_7
	closemessage
	applymovement LOCALID_ROUTE34_RIVAL, Route34_RivalEncounter_Movement_1
	waitmovement 0
	applymovement LOCALID_ROUTE34_DAYCAREMAN, Route34_RivalEncounter_Movement_2
	waitmovement 0
	removeobject LOCALID_ROUTE34_RIVAL
	fadedefaultbgm
	setvar VAR_RIVAL_STATE, 6
	release
	end

Route34_RivalEncounter_2:
	trainerbattle_no_intro TRAINER_RIVALCRYSTAL2, Route34_RivalEncounter_Text_1
	goto Route34_RivalEncounter_1

Route34_RivalEncounter_6:
	msgbox Route34_RivalEncounter_Text_4
	closemessage
	release
	end

Route34_RivalEncounter_9:
	msgbox Route34_RivalEncounter_Text_6
	goto Route34_RivalEncounter_8


Route34_RivalEncounter_Movement_0:
	face_down
	step_end

Route34_RivalEncounter_Movement_1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route34_RivalEncounter_Movement_2:
	face_left
	step_end

Route34_RivalEncounter_Text_0:
	.string "脚步不错，{PLAYER}！\n你马上就要到满金市了！\p我是来探望祖父母的，\n他们在这一带经营培育屋。\p既然你来了，爷爷又在看着，\n要不要打一场？我终于能\l让他们看看我进步了多少！$"

Route34_RivalEncounter_Text_1:
	.string "还是不够强……$"

Route34_RivalEncounter_Text_2:
	.string "怎么会……要是奶奶知道了，\n我非得被念叨个没完……\p这次是我挑起的，就让我\n先快速帮你治疗一下队伍吧。$"

Route34_RivalEncounter_Text_3:
	.string "我祖父母最近发现了这颗奇怪的蛋。\n他们说我想要的话就拿去，不过\l我觉得它更适合你。\p就当作打赢我的奖品，收下吧！$"

Route34_RivalEncounter_Text_4:
	.string "咦，你身上没空位了，真奇怪……$"

Route34_RivalEncounter_Text_5:
	.string "{PLAYER}得到了奇怪的蛋。$"

Route34_RivalEncounter_Text_6:
	.string "奇怪的蛋被送进了你的电脑。$"

Route34_RivalEncounter_Text_7:
	.string "那么，我可不能每次都输给你，\n我要开始认真特训了！\p你就等着被我彻底打败吧！$"
