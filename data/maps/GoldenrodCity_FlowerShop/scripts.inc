
GoldenrodCity_FlowerShop_MapScripts::
	.byte 0

GoldenrodCity_FlowerShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRTBOTTLE
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Normal::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_FlowerShop_EventScript_Floria2::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria3::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_RandomBerryGirl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
	random 8
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry::
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_MintOwner::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE04_GET, Route104_PrettyPetalFlowerShop_EventScript_NoSellMints
	msgbox Route104_PrettyPetalFlowerShop_Text_Mints1, MSGBOX_DEFAULT
	waitmessage
	pokemart Route104_PrettyPetalFlowerShop_MintShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_Text_Mints1:
	.string "性格薄荷补货了！\n您来看看吧！$"
	.string ""

Route104_PrettyPetalFlowerShop_Text_Mints2:
	.string "您好，亲爱的训练家。\n想买性格薄荷的话，您来晚了。\l最后一份刚卖完，请改天再来吧。$"
	.string ""
	.string ""
	.string ""

	.align 2
Route104_PrettyPetalFlowerShop_MintShop:
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_NONE
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_NoSellMints::
	msgbox Route104_PrettyPetalFlowerShop_Text_Mints2, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet::
	msgbox Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries::
	msgbox Route104_PrettyPetalFlowerShop_Text_BerriesExplanation, MSGBOX_DEFAULT
	return

Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries::
	msgbox Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness, MSGBOX_DEFAULT
	return

GoldenrodCity_FlowerShop_Text_Floria:
	.string "我跟姐姐说起那棵会晃的树，\n她说那很危险。\p要是我打赢了小茜，\n不知道她肯不肯把喷壶借我……$"
	.string ""
	.string ""
	.string ""

GoldenrodCity_FlowerShop_Text_Owner1:
.string "听说36号道路上\n长着一棵奇怪的树。\p据说给它浇浇水，\n它就会跳起舞来……\p啊，不行不行！\p这里是花店，喷壶倒是\n有的……\p可我不能借给您！\n太危险了！\p不过，如果您能打赢\n道馆馆主小茜，\l也许就可以。$"
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

GoldenrodCity_FlowerShop_Text_Owner2:
.string "听说36号道路上\n长着一棵奇怪的树。\p据说给它浇浇水，\n它就会跳起舞来……\p哦，那是满金道馆的\n标准徽章！\p您打赢小茜了？！\p那就没什么好担心的了，\n对吧？\p我就把这杰尼龟喷壶\n借您用一阵子吧……\l那个……\p啊，算了算了。\n就送给您吧！$"
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

GoldenrodCity_FlowerShop_Text_Owner3:
.string "那棵奇怪的树在36号道路。\n请多加小心！$"
.string ""

GoldenrodCity_FlowerShop_Text_Owner4:
    .string "啦啦啦，啦啦啦啦。\n多浇点水吧，我的宝贝！$"
    .string ""

GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
    .string "哇，你打赢小茜了？好厉害！$"

GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
    .string "原来那真的是宝可梦啊！$"

FlowerShopMulchVendor::
	lock
	faceplayer
	msgbox FlowerShopMulchVendor_Text_0
	goto_if_set FLAG_BADGE06_GET, FlowerShopMulchVendor_2
	pokemart FlowerShopMulches
	msgbox FlowerShopMulchVendor_Text_2
FlowerShopMulchVendor_1:
	release
	end

FlowerShopMulchVendor_2:
	pokemart FlowerShopMulchesSixBadges
	msgbox FlowerShopMulchVendor_Text_1
	goto FlowerShopMulchVendor_1


	.align 2
FlowerShopMulches:
	.2byte ITEM_GRASSY_SEED
	.2byte ITEM_LUMINOUS_MOSS
	.2byte ITEM_GROWTH_MULCH
	.2byte ITEM_DAMP_MULCH
	.2byte ITEM_STABLE_MULCH
	.2byte ITEM_GOOEY_MULCH
	.2byte ITEM_NONE

	.align 2
FlowerShopMulchesSixBadges:
	.2byte ITEM_CHILAN_BERRY
	.2byte ITEM_OCCA_BERRY
	.2byte ITEM_PASSHO_BERRY
	.2byte ITEM_WACAN_BERRY
	.2byte ITEM_RINDO_BERRY
	.2byte ITEM_YACHE_BERRY
	.2byte ITEM_CHOPLE_BERRY
	.2byte ITEM_KEBIA_BERRY
	.2byte ITEM_SHUCA_BERRY
	.2byte ITEM_COBA_BERRY
	.2byte ITEM_PAYAPA_BERRY
	.2byte ITEM_TANGA_BERRY
	.2byte ITEM_CHARTI_BERRY
	.2byte ITEM_KASIB_BERRY
	.2byte ITEM_HABAN_BERRY
	.2byte ITEM_COLBUR_BERRY
	.2byte ITEM_BABIRI_BERRY
	.2byte ITEM_ROSELI_BERRY
	.2byte ITEM_GRASSY_SEED
	.2byte ITEM_LUMINOUS_MOSS
	.2byte ITEM_GROWTH_MULCH
	.2byte ITEM_DAMP_MULCH
	.2byte ITEM_STABLE_MULCH
	.2byte ITEM_GOOEY_MULCH
	.2byte ITEM_NONE

UniversityFlorist::
	lock
	faceplayer
	msgbox UniversityFlorist_Text_0
	checkspecies SPECIES_SHAYMIN
	compare VAR_RESULT, TRUE
	goto_if_eq UniversityFlorist_2
UniversityFlorist_1:
	release
	end

UniversityFlorist_2:
	goto GiveGracidea
	goto UniversityFlorist_1


GiveGracidea::
	goto_if_set FLAG_GOT_GRACIDEA, GiveGracidea_2
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	msgbox GiveGracidea_Text_1
	giveitem ITEM_GRACIDEA
	msgbox GiveGracidea_Text_0
	setflag FLAG_GOT_GRACIDEA
	release
	end

GiveGracidea_2:
	msgbox GiveGracidea_Text_0
	release
	end


FlowerShopMulchVendor_Text_0:
	.string "欢迎光临！请看看我们的商品！$"

FlowerShopMulchVendor_Text_1:
	.string "谢谢惠顾！欢迎再来！$"

FlowerShopMulchVendor_Text_2:
	.string "谢谢惠顾，我们近期\n希望能进一些稀有的树果！$"

UniversityFlorist_Text_0:
	.string "我正在学习，想成为一名植物学家！\p我努力研究各种珍稀的\n植物和花卉！$"

GiveGracidea_Text_0:
	.string "据说谢米能借助那朵花\n改变形态。$"

GiveGracidea_Text_1:
	.string "哦！您带着的那只宝可梦！\p真的是谢米！\p我在书上读到过，\n可从没想过能亲眼见到！\p请您试着\n把这朵花送给它吧。$"
