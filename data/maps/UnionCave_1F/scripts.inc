UnionCave_1F_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_Text_HikerRussellSeen:
	.string "你要去桧皮镇吗？\p让我的宝可梦来试试，\n你有没有对战的实力。$"
	.string ""
	.string ""

UnionCave_1F_Text_HikerRussellBeaten:
	.string "哦，哦，哦！$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "好，就这么定了！\p在我的宝可梦变强之前，\n我哪儿也不去！$"
	.string ""
	.string ""

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "我走遍各地寻找宝可梦。\p你也在找宝可梦吗？\p那你就是我的收集对手了！$"
	.string ""
	.string ""
	.string ""

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "唉。可怜的宝可梦……$"

UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "每到星期五，就能听见\n洞窟深处传来宝可梦的吼声。$"
	.string ""

UnionCave_1F_Text_HikerDanielSeen:
	.string "哇！吓我一跳！\p没想到这里居然有人！$"
	.string ""

UnionCave_1F_Text_HikerDanielBeaten:
	.string "哇！输得一塌糊涂！$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "我被人忽悠，\n买了一条呆呆兽的尾巴。\p那只宝可梦真可怜。$"
	.string ""
	.string ""

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "超音蝠的超音波\n老是弄乱我的宝可梦。\p我真的很恼火！$"
	.string ""
	.string ""

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "我熄火了！$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "一到周末，就能听见\n洞窟深处传来奇怪的吼声。$"
	.string ""

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "只要有光，洞窟就不可怕。\p只要你够强，\n宝可梦就不可怕。$"
	.string ""
	.string ""

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "闪光！$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "照亮这座洞窟的，\n是我宝可梦的火焰。$"
	.string ""
