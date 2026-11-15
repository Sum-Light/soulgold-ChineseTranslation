.set LOCALID_FAN_CLUB_CLEFAIRY_DOLL, 5

VermilionCity_FanClub_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "我是宝可梦发烧友俱乐部的\n会长。\p我培育的宝可梦\n超过了150只。\p一聊起宝可梦，我可是\n非常讲究的。\p你特地来，是想听听\n我的宝可梦的事吗？$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

PokemonFanClub_Text_Chairman_Rapidash:
	.string "好！那你听好了！\p说起……我最喜欢的烈焰马……\p它……可爱……迷人……聪明……\n讨人喜欢得不得了……\l还有……惊人……哦……你觉得\l是吧？……\l太过头了……狂野……美丽……\l温柔……\l我爱死它了！\p抱着它……睡觉时……又暖\n又软……\l哦，还有……壮观……\l娇艳……简直是神圣……\p哎呀！都这个时间了！\n我留你太久了！$"
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

PokemonFanClub_Text_Chairman_Gift:
	.string "谢谢你听我说完。\n这个就给你吧！$"
	.string ""

PokemonFanClub_Text_Chairman_Candy:
	.string "这是能让宝可梦变强的\n神奇糖果。\p我更喜欢靠对战让宝可梦\n变强，所以这个\l就给你吧。$"
	.string ""
	.string ""
	.string ""
	.string ""

PokemonFanClub_Text_Chairman_MoreTales:
	.string "你好，{PLAYER}！\p你又来听我讲\n宝可梦的事了吗？\p不是？哦……我本来还有\n更多故事想讲呢……$"
	.string ""
	.string ""
	.string ""
	.string ""

PokemonFanClub_Text_Chairman_Disappointed:
	.string "真失望……\p想听的话就再来吧。$"
	.string ""

PokemonFanClub_Text_Receptionist:
	.string "我们的会长一聊起宝可梦，\n话就特别多……$"
	.string ""

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "皮皮想用挥指时，会\n摇动它的手指，\l我最爱看那模样。\p真是太可爱了！$"
	.string ""
	.string ""
	.string ""

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "我很喜欢皮皮，可是\n怎么也抓不到。\p所以只好拿捡来的\n皮皮玩偶凑合着。$"
	.string ""
	.string ""
	.string ""

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "哦，我明白了。弄丢这个\n皮皮玩偶的女孩很伤心……\p好吧。能请你把这个皮皮玩偶\n还给那个可怜的小女孩吗？\p总有一天，我会靠自己的力量\n和真正的皮皮成为伙伴。别担心！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "你等着瞧。我一定会和真正的\n皮皮成为伙伴的。$"
	.string ""

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "你看我可爱的月桂叶！\p它头上的叶子太可爱了！$"
	.string ""

PokemonFanClub_Text_ClefairyDoll:
	.string "是皮皮！咦？\p哦，对。是皮皮玩偶啊。$"
	.string ""
	.string ""

PokemonFanClub_Text_Bayleef:
	.string "月桂叶：哩哩～$"

PokemonFanClub_Text_Listen:
	.string "我们要有礼貌地听\n其他训练家说话。$"
	.string ""

PokemonFanClub_Text_Bragging:
	.string "别人跟你炫耀，\n你就加倍炫耀回去！$"
	.string ""
