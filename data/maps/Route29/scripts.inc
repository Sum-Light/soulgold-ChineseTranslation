
Route29_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "按A键或B键结束查看。$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_Text_OldMan1:
	.string "宝可梦会藏在草丛里。\n不知道什么时候就会冒出来……$"
	.string ""

Route29_Text_OldMan2:
	.string "我已经见过你几次了。\n你抓到多少宝可梦了？\p要我告诉你\n怎么抓宝可梦吗？$"
	.string ""
	.string ""
	.string ""

Route29_Text_OldManExplanation:
	.string "先把宝可梦削弱，\n就更容易抓到。\p然后从包里\n朝它扔球！什么球都行。\p想了解更多的话，\n就去桔梗市的学校吧！\p那里的学生懂得很多\n关于宝可梦的知识。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route29_Text_OldManDeclined:
	.string "哦。那就算了。\p多走走不同的道路，\n就能发现不同种类的宝可梦。\p宝可梦图鉴上也会显示\n能在哪里找到它们！\p想了解更多的话，\n就去桔梗市的学校吧！\p那里的学生懂得很多\n关于宝可梦的知识。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route29_Text_Youngster:
	.string "哟。你的宝可梦怎么样？\p要是它们还弱，\n没准备好战斗，就别进草丛。$"
	.string ""
	.string ""

Route29_Text_Lass:
	.string "看见那些台阶了吗？\n从上面跳下去有点吓人。\p不过这样就能不穿过草丛，\n一路走到若叶镇。$"
	.string ""
	.string ""
	.string ""

Route29_Text_Girl:
	.string "我想休息一下，\n就保存并记录了一下进度。$"
	.string ""

Route29_Text_Boy_WaitingForDay:
	.string "我在等只会在\n今天晚些时候出现的宝可梦。$"
	.string ""

Route29_Text_Boy_WaitingForNight:
	.string "我在等只会在\n夜里出现的宝可梦。$"
	.string ""

Route29_Text_MeetTuscany:
	.string "星琪儿：我想，\n我们这是头一次见面吧？\p我是星期兄弟里的星琪儿。\p您要是能猜中我最喜欢的日子，\n我就送您一份谢礼。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route29_Text_TuscanyNope:
	.string "不对哦！$"

Route29_Text_TuscanyGivesGift:
	.string "没错！就当是见面礼，\n请您收下这条\l丝绸围巾。$"
	.string ""
	.string ""

Route29_Text_TuscanyGaveGift:
	.string "星琪儿：您不觉得它\n非常可爱吗？\p它能增强一般属性\n招式的威力。\p我确信您一定用得上。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route29_Text_TuscanyTuesday:
	.string "星琪儿：您见过我姐姐\n星琪怡了吗？\p或者我弟弟星琪山？\p我是七个孩子里\n排行第三的。$"
	.string ""
	.string ""
	.string ""
	.string ""

Route29_Text_Sign1:
	.string "29号道路\p吉花市——若叶镇$"
	.string ""

Route29ExNightNpc::
	msgbox Route29ExNightNpc_Text_0, MSGBOX_NPC
	return


Route29ExNightNpc_Text_0:
	.string "我正在用宝可梦装置查地图，\n看看自己该往哪儿走！$"
