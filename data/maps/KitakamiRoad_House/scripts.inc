KitakamiRoad_House_MapScripts::
	.byte 0


KitakamiBorder_VictiniLady::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VICTINI, KitakamiBorder_VictiniLady_2
	goto_if_unset FLAG_IS_CHAMPION, KitakamiBorder_VictiniLady_5
	goto_if_unset FLAG_STARTED_VICTINI_QUEST, KitakamiBorder_VictiniLady_8
	checktrainerflag TRAINER_FALKNER_2
	goto_if 1, KitakamiBorder_VictiniLady_16
KitakamiBorder_VictiniLady_13:
	msgbox KitakamiBorder_VictiniLady_Text_11
	release
	end

KitakamiBorder_VictiniLady_2:
	msgbox KitakamiBorder_VictiniLady_Text_0
	release
	end

KitakamiBorder_VictiniLady_5:
	goto_if_unset FLAG_MET_VICTINI_LADY, KitakamiBorder_VictiniLady_11
	msgbox KitakamiBorder_VictiniLady_Text_3
	release
	end

KitakamiBorder_VictiniLady_8:
	goto_if_unset FLAG_MET_VICTINI_LADY, KitakamiBorder_VictiniLady_31
	msgbox KitakamiBorder_VictiniLady_Text_5
KitakamiBorder_VictiniLady_30:
	msgbox KitakamiBorder_VictiniLady_Text_6
	setflag FLAG_STARTED_VICTINI_QUEST
	release
	end

KitakamiBorder_VictiniLady_11:
	msgbox KitakamiBorder_VictiniLady_Text_1
	msgbox KitakamiBorder_VictiniLady_Text_2
	setflag FLAG_MET_VICTINI_LADY
	release
	end

KitakamiBorder_VictiniLady_14:
	closemessage
	applymovement LOCALID_VICTINI_LADY, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox KitakamiBorder_VictiniLady_Text_7
	msgbox KitakamiBorder_VictiniLady_Text_8
	msgbox KitakamiBorder_VictiniLady_Text_9
	closemessage
	delay 30
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_VICTINI
	bufferspeciesname STR_VAR_1, SPECIES_VICTINI
	givemon SPECIES_VICTINI, 50
	showgivemonpic 10, 3
	call Common_EventScript_GiftMon
	hidemonpic
	setflag FLAG_GOT_VICTINI
	special Achievement_CheckAll
	delay 60
	msgbox KitakamiBorder_VictiniLady_Text_10
	release
	end

KitakamiBorder_VictiniLady_15:
	checktrainerflag TRAINER_WHITNEY_2
	goto_if 1, KitakamiBorder_VictiniLady_20
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_16:
	checktrainerflag TRAINER_BUGSY_2
	goto_if 1, KitakamiBorder_VictiniLady_15
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_19:
	checktrainerflag TRAINER_CHUCK_2
	goto_if 1, KitakamiBorder_VictiniLady_24
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_20:
	checktrainerflag TRAINER_MORTY_2
	goto_if 1, KitakamiBorder_VictiniLady_19
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_23:
	checktrainerflag TRAINER_PRYCE_2
	goto_if 1, KitakamiBorder_VictiniLady_27
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_24:
	checktrainerflag TRAINER_JASMINE_2
	goto_if 1, KitakamiBorder_VictiniLady_23
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_27:
	checktrainerflag TRAINER_CLAIR_2
	goto_if 1, KitakamiBorder_VictiniLady_14
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_31:
	msgbox KitakamiBorder_VictiniLady_Text_1
	msgbox KitakamiBorder_VictiniLady_Text_4
	setflag FLAG_MET_VICTINI_LADY
	goto KitakamiBorder_VictiniLady_30


KitakamiBorder_VictiniLady_Text_0:
	.string "比克提尼选得不错。\p可要让我们的馆主们\n保持进取心啊？\p不然退休生活\n就太无聊了。$"

KitakamiBorder_VictiniLady_Text_1:
	.string "我曾在城都地区的\n道馆馆主委员会任职。\p别一副很佩服的样子。\n那工作多半就是算预算、\l吵架、伤面子。$"

KitakamiBorder_VictiniLady_Text_2:
	.string "这些日子，我在观察\n有前途的训练家。\p你看起来还乳臭未干。\p不过，我会盯着你的。$"

KitakamiBorder_VictiniLady_Text_3:
	.string "还在摸索门道？很好。\p我会盯着你的。拿出点\n值得一看的东西来。$"

KitakamiBorder_VictiniLady_Text_4:
	.string "成为冠军了？很好。\p头衔会让一些训练家\n变得软弱。让我看看你的本事。$"

KitakamiBorder_VictiniLady_Text_5:
	.string "我们寄予厚望的训练家，\n如今是冠军了。\p不错。\p不过别一脸得意。\n头衔会滋生自满。$"

KitakamiBorder_VictiniLady_Text_6:
	.string "我虽然退休了，\n但仍在培养人才。\p帮我验证一下，现任道馆馆主\n是否还胜任他们的工作。\p去战胜全部八位馆主，\n让他们拿出全部实力。\p让他们成长，也让你自己的\n潜力得到进一步的培养。$"

KitakamiBorder_VictiniLady_Text_7:
	.string "哎呀呀。八位馆主\n全都拿出了真本事。\p你不只是在收集胜利。\p你让每一位馆主都有了理由，\n去追求更高的境界。$"

KitakamiBorder_VictiniLady_Text_8:
	.string "希望他们从那些对战里学到的，\n不比你少。\p要是没有，我就给他们\n寄一份措辞严厉的通知。$"

KitakamiBorder_VictiniLady_Text_9:
	.string "像你这样的才能，\n值得好好投资。\p这只比克提尼，拿去吧。\p看着你在每一场胜利中变强，\n它现在似乎很喜欢你。$"

KitakamiBorder_VictiniLady_Text_10:
	.string "别一脸目瞪口呆。我说过，\n我在培养本地区的精英。\p好了，去吧。我虽然退休了，\n可忙得很呢。$"

KitakamiBorder_VictiniLady_Text_11:
	.string "又回来了？除非八位馆主\n都向你展示了全部实力，\l不然你就是在浪费\l我们两个人的时间。\p去吧。让我这个老太婆\n看到点希望。$"
