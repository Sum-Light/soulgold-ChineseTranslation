ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "嘿，训练家！\n你的笑容很灿烂。\p我有个爱好——收集宝可梦训练家\n的个人信息档案。$"
	.string ""
	.string ""
	.string ""

ProfileMan_Text_MayISeeYourProfile:
	.string "怎么样？\n我可以看看你的档案吗？$"
	.string ""

ProfileMan_Text_EasyChatExplanation:
	.string "你可以用4个单词或短语\n组合起来创建自己的个人资料。\p我先在这里给你展示一个\n用4个文本组成的档案的例子。\p你可以把里面的文本换成\n你自己喜欢的文本\l来构成你自己的档案。\p这里有很多的文本可以\n供你选择使用。\p它们根据类型分组排列，\n例如宝可梦，生活方式，或是爱好，\l以便你查找。\p所以你可以先选择分组\n来显示其中的文本选项。\p然后再从中选出你要的文本。\p如此反复选择好所有文本，这样\n你就拥有一个你自己的个人档案了。$"
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
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

ProfileMan_Text_LetsSeeItThen:
	.string "好的！谢谢！\n那么，我们来看看吧。$"
	.string ""

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "哦，真的不要吗？\p我认为像你这样的人\n个人档案肯定会很棒……$"
	.string ""
	.string ""

ProfileMan_Text_NotIntoItRightNow:
	.string "啊？你现在还不想编辑？\p好吧，那随时来找我！$"
	.string ""

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "你好呀，训练家！\n你的笑容很灿烂。$"
	.string ""

ProfileMan_Text_MayISeeYourNewProfile:
	.string "我能看看你的新档案吗？$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "好的！谢谢！\p我希望这份档案比之前\n那份还要更好。$"
	.string ""
	.string ""

ProfileMan_Text_LikeProfileWayItIs:
	.string "啊，你喜欢现在的个人档案呀。\p不怪你——现在的个人档案\n已经非常棒了。$"
	.string ""
	.string ""

ProfileMan_Text_FantasticProfile:
	.string "太，太棒了！\p你的档案，太棒了！\n它完美地展现了你的个性。\p任何看到这份档案的人\n都会被你迷住的！\p谢谢！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "哦？\n你明白这句话的含义了！\p你现在是神秘事件\n俱乐部的一员了！$"
	.string ""
	.string ""
	.string ""
