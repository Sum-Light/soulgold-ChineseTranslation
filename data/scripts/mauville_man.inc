MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "我是装饰物品交换大叔。\n要跟我交换装饰物品吗？$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "是吗……\n真是遗憾啊……$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "不过，我们之前\n有交换过装饰物品哦。$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "如果你看到我这里有什么\n你想要的装饰物品，就直说吧。$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "没有想要的吗？\n真遗憾……$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "这个可是{STR_VAR_1}\n用过的装饰物品。\p要交换吗？$"
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "嗯……等一下，你这家伙，\n一件装饰物品也没有嘛！$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "那么，选择你要用来\n跟我交换的装饰物品吧。$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "你不想跟我换？\n真遗憾……$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "你有太多{STR_VAR_2}了。\n已经放不下了。$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "那么，开始用我的{STR_VAR_3}\n和你的{STR_VAR_2}交换吧？$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "这件装饰物品在使用中。\n不能交换。$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "那么开始交换！\n我把我的装饰物品发送到你的电脑。$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "啊！抱歉！\n这件装饰物品太珍贵了。\l不能交换这个！\l有其他想要的吗？$"
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "我是吟游诗人。\n我可以告诉你传说中的\l训练家的故事。\p想听我的故事吗？$"
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "这样啊……\n真遗憾……$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "我知道这些传说。\n你想听哪个？$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "不过，我不知道什么传说中的训练家。\n所以，也就不知道有什么故事。\p这世上存在能称为\n传说中的训练家的人吗？$"
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "啊？！\n你……你……\p{STR_VAR_2}\n{STR_VAR_1}次？！\p太强了！\n这是新传说的诞生啊！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "我开始想，是否还有其他\n训练家有着更感人的故事\l等待着人们的发现呢？$"
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "你是训练家吗？\p那么告诉我吧，\n你听说过更遥远的传说吗？$"
	.string ""
	.string ""

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "顺带一提……你要听另一个\n传说吗？$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "嗯……\n我不满意啊……\p希望你能让我听到\n值得成为传说的故事啊。$"
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "真希望能有更多的人来听\n我这些关于传说中的训练家们\l的史诗般的故事。$"
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "谨慎的训练家$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "写入记录$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他在游戏中记录了\n{STR_VAR_1}次！\p没有比{STR_VAR_3}更小心的\n人了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "先驱者$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "引领新潮$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他至少站在流行前沿\n{STR_VAR_1}次了！\p{STR_VAR_3}引领整个\n丰缘地区的潮流！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "植树学家$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "种植树果$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他至少种了{STR_VAR_1}\n棵树！\p{STR_VAR_3}是个举世闻名的果树\n爱好者！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "单车发烧友$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "单车交换$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他已经换了{STR_VAR_1}辆\n车了！\p{STR_VAR_3}对自行车的热情犹如滔滔\n江水，连绵不绝！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "明星$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "接受采访$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他曾经受到了{STR_VAR_1}次\n采访！\p我相信{STR_VAR_3}一定能成为\n备受瞩目的训练家！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "对战狂$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "对战$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他参加了{STR_VAR_1}次对战！\p{STR_VAR_3}不会错过任何\n对战的机会！$"
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "捕捉专家$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "捕捉宝可梦$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p据不完全统计，共捕捉了\n{STR_VAR_1}只宝可梦！\p{STR_VAR_3}——传说中的\n宝可梦捕捉专家！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "钓圣$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "用钓竿钓宝可梦$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他在钓鱼时\n钓到{STR_VAR_1}只宝可梦！\p{STR_VAR_3}——传说中的\n钓圣！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "孵化专家$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "孵蛋$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他曾在{STR_VAR_1}只蛋中孵\n出了宝可梦！\p{STR_VAR_3}是名副其实的\n孵化专家！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "进化专家$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "宝可梦进化$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他已使{STR_VAR_1}只宝可梦\n进化！\p{STR_VAR_3}是最强的\n宝可梦进化专家！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "爱心使者$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "使用宝可梦中心$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他在宝可梦中心共治疗宝可梦\n{STR_VAR_1}次！\p在宝可梦中心没有比{STR_VAR_3}更有\n爱心的人了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "宝可梦保姆$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "在家照顾宝可梦$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "关于{STR_VAR_3}是这样\n流传的。\p他在家中治愈过{STR_VAR_1}次\n宝可梦！\p找不到比{STR_VAR_3}更守家的\n人了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "旅游爱好者$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "参加旅行团$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他已经参加了{STR_VAR_1}\n个旅行团！\p{STR_VAR_3}是一个狂热的\n旅游粉丝！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "斩剑狂$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "用居合劈$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p此人使用居合劈高达\n{STR_VAR_1}次！\p{STR_VAR_3}十分喜欢\n居合劈！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "碎岩大师$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "打碎岩石$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p此人使用碎岩有\n{STR_VAR_1}次！\p碎岩早已是{STR_VAR_3}生活\n的一部分！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "神秘人$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "转移秘密基地$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他换过{STR_VAR_1}次秘密\n基地！\p{STR_VAR_3}真是喜欢搬家\n啊！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "弹跳达人$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "使用弹跳$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他曾使用{STR_VAR_1}次\n弹跳！\p{STR_VAR_3}大概喜欢四处\n乱跳吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "顽强的训练家$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "采取绝境反击战术$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他依靠绝境反击获胜\n{STR_VAR_1}次！\p{STR_VAR_3}在绝境中总能表现出\n惊人的实力！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "赌神$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "赢筹码$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他赢取筹码已经\n有{STR_VAR_1}次了。\p{STR_VAR_3}在赌桌上真是常受幸运女神\n的关照啊！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "轮盘王$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "赌轮盘连胜$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他的轮盘纪录是\n{STR_VAR_1}连胜。\p滚珠在轮盘中转动时{STR_VAR_3}\n是最幸运的！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "对战塔挑战王$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "挑战对战塔$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他向对战塔\n挑战了{STR_VAR_1}次！\p{STR_VAR_3}立志成为\n对战塔中优秀的训练家！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "树果有爱混合师$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "做宝可方块$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他做出了树果\n有{STR_VAR_1}次！\p没有人比{STR_VAR_3}更精通\n树果混合器了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "华丽大赛大师$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "参加华丽大赛$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p至今为止他已参加{STR_VAR_1}次\n华丽大赛！\p{STR_VAR_3}喜欢向他人炫耀\n自己的宝可梦！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "华丽大赛专家$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "获得华丽大赛冠军$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他已获得了{STR_VAR_1}次\n华丽大赛冠军！\p{STR_VAR_3}是个令人难以置信的\n华丽大赛大师！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "购物爱好者$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "购物$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他在商店购买道具有\n{STR_VAR_1}次了！\p{STR_VAR_3}可能是在商店\n里出生的吧。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "搜索专家$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "使用探宝器$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他用探宝器找出道具\n{STR_VAR_1}次！\p{STR_VAR_3}一定想找出\n所有隐藏道具！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "被雨淋湿的训练家$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "淋雨$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他被淋湿过\n{STR_VAR_1}次！\p{STR_VAR_3}对雨有着超凡的\n吸引力！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "宝可梦图鉴研究者$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "校对图鉴数据$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他校对宝可梦图鉴有\n{STR_VAR_1}次了！\p{STR_VAR_3}喜欢在宝可梦图鉴中查看\n宝可梦的数据！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "奖章收藏家$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "收藏奖章$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他一共收藏了奖章\n{STR_VAR_1}条！\p{STR_VAR_3}一定很喜欢\n收藏奖章！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "蹦极狂热爱好者$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "跳下岩礁$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他几经跳过\n{STR_VAR_1}次了！\p如果有适合跳跃的岩礁，\n{STR_VAR_3}一定会去跳的！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "电视迷$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "看电视$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他看电视超过了\n{STR_VAR_1}次！\p{STR_VAR_3}一定对电视情有独钟！$"
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "时间魔术师$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "调表$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他总共调过\n{STR_VAR_1}次表！\p{STR_VAR_3}一定是个自觉\n遵守时间的训练家。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "中奖奇才$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "赢得宝可梦彩票$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他中过的宝可梦彩票有{STR_VAR_1}次\n之多！\p{STR_VAR_3}一定有很多交换\n宝可梦的朋友！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "在培育屋工作的训练家$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "在培育屋照顾宝可梦$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他在培育屋照顾的宝可梦\n有{STR_VAR_1}只！\p{STR_VAR_3}一定是一个培育\n宝可梦的老手了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "缆车王$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "乘缆车$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他乘坐缆车已经有\n{STR_VAR_1}次了！\p{STR_VAR_3}始终都在上上下下\n一定很忙吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "温泉爱好者$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "洗温泉$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "关于{STR_VAR_3}是这样流传\n的。\p他在温泉中洗过\n{STR_VAR_1}次！\p{STR_VAR_3}会有着婴儿般\n细嫩的皮肤吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "我是格蒂！\n我给你准备了一个非常炫的故事！\p想听听吗？$"
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "哎……\n你真是给我泼了一盆冷水……$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "我也一直在想……$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "就是这样了，我想……\p我们下次再聊吧！\n再见！$"
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "嘿，我是巴德。\n想听听我的歌吗？$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "哎……\n你真是给我泼了一盆冷水……$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "啊，多么动感的音乐……\n我真希望能演奏给别人听……$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "是这样吗？\n你有多喜欢我的歌？\p但是我对歌词\n一点都不满意。\p能为我写一篇新\n歌词吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "哎……\n你真是给我泼了一盆冷水……$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "太感谢你了！\n让我为你尽情的唱吧。$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "这就是你想让你的歌达到的\n效果吗？$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "好极了！就是这样。\n我马上就唱这首歌。$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "嘿，你！别人都叫我时髦青年。\n我会教给你如何走在时代的最前端。$"
	.string ""

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "但是，嘿，我已经教了你很多\n潮流的东西了。\p我还想和别人分享这么\n美妙的话语。$"
	.string ""
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "但是，嘿，你已经能抓住\n最新潮流的去向了。\p我没什么新东西可以交给你了！$"
	.string ""
	.string ""

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "嘿，你听过\n“{STR_VAR_1}”吗？\p那是什么意思？好的……\n去问你的爸爸妈妈，明白吗？$"
	.string ""
	.string ""
	.string ""
