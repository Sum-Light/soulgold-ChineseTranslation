Route10_PowerPlantBackRoom_MapScripts::
	.byte 0


Route10_PowerPlantBackRoom_EventScript_Manager::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 0, Route10_PowerPlantBackRoom_EventScript_ManagerInitial
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 1, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantBackRoom_EventScript_ManagerDone
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerInitial::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart::
	checkitem ITEM_MACHINE_PART
	goto_if_eq VAR_RESULT, FALSE, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	removeitem ITEM_MACHINE_PART
	msgbox Route10_PowerPlantBackRoom_Text_ManagerThatsThePart, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 7
	clearflag FLAG_HIDE_ROUTE25_MISTY
	setvar VAR_CERULEAN_CITY_STATE, 2
	setflag FLAG_HIDE_POWER_PLANT_ENGINEER
	setflag FLAG_RETURNED_MACHINE_PART
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDone::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_Engineer::
	msgbox Route10_PowerPlantBackRoom_Text_Engineer, MSGBOX_NPC
	end

Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator:
	.string "厂长：我、我、我恨不得\n把谁炸飞！\p是谁竟敢弄坏我的\n发电机？\p我可是花了\n那么多心血在上面！\p要是让我逮到他，\n就让他尝尝我的电磁炮！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit:
	.string "厂长：我绝不原谅他！\p就算犯人哭着道歉，\p我也照样要狠狠教训他！\p哇哈哈哈！$"
	.string ""
	.string ""
	.string ""
	.string ""

Route10_PowerPlantBackRoom_Text_ManagerThatsThePart:
	.string "厂长：啊！没错！\p我心爱的发电机缺的那个零件！\n你找到了？$"
	.string ""
	.string ""

Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM:
	.string "哇哈！谢谢！\p来！这个招式学习器\n就当谢礼，拿去吧！$"
	.string ""

Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon:
	.string "厂长：招式学习器里装的是打雷。\p它的威力可强了！\p虽然算不上百发百中，\n但挨上一下，\l可够受的！$"
	.string ""
	.string ""
	.string ""
	.string ""

Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator:
	.string "厂长：我心爱的发电机！\p继续发电吧，\n把电力源源不断地送出去！$"
	.string ""

Route10_PowerPlantBackRoom_Text_Engineer:
	.string "没有电，这扇门不安全。$"

