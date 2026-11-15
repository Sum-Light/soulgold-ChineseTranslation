GoldenrodCity_UndergroundStorage_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

RadioTowerBasement_Text_GruntM24Seen:
    .string "你居然能走到这儿？\p没办法了。\n就让我来收拾你吧。$"
    .string ""
    .string ""

RadioTowerBasement_Text_GruntM24Beaten:
    .string "反倒被收拾了……$"

RadioTowerBasement_Text_GruntM24After:
    .string "火箭队会一直等下去，\n等坂木大人回来。\p我们什么都干得出来。$"
    .string ""
    .string ""

RadioTowerBasement_Text_GruntM14Seen:
    .string "别再往前走了！\p我对敌人绝不手下留情，\n小鬼也一样！$"
    .string ""
    .string ""

RadioTowerBasement_Text_GruntM14Beaten:
    .string "可恶！$"

RadioTowerBasement_Text_GruntM14After:
    .string "我输了……\p坂木大人，请原谅我！$"
    .string ""

RadioTowerBasement_Text_GruntM15Seen:
    .string "嘻嘻嘻！看看是谁来了！\p准备好了吗？我现在可厉害了！$"
    .string ""

RadioTowerBasement_Text_GruntM15Beaten:
    .string "嘻嘻嘻！你可真厉害！\p火箭队这活儿也就是份工作，\n可我看得出来，它在伤害别人。\p行了，我不干了。\p多谢你。对不住了，坂木大人！$"
    .string ""
    .string ""
    .string ""
    .string ""

RadioTowerBasement_Text_GruntM15After:
    .string "嘻嘻嘻！打得真痛快！\n我会记住你的！$"
    .string ""

RadioTowerBasement_Text_DirectorIntro:
    .string "局长：谁？什么？你是来\n救我的吗？\p谢谢你！\p播音塔！\p那边出什么事了？\p被火箭队占领了？\p来，拿着这张钥匙卡。$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

RadioTowerBasement_Text_DirectorCardKey:
    .string "局长：用这个，就能打开\n3楼的卷帘门。$"
    .string ""

RadioTowerBasement_Text_DirectorAfter:
    .string "求求你，帮帮我们。\p他们若控制了无线电发射装置，\n真不知道会干出什么事来。\p说不定他们能用特殊的电波\n操纵宝可梦！\p我能拜托的人只有你了。\p请你救救播音塔……\p还有全国的宝可梦！$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
