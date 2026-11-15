GoldenrodCity_DepartmentStore_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore3_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore3_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore3_EventScript_Rocker::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FRocker, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_3FSuperNerd:
    .string "我、我、我性子特别急！\p对战时我会用速度强化\n来提升宝可梦的速度。$"
    .string ""
    .string ""

GoldenrodDeptStore_Text_3FRocker:
    .string "嘿！你对战时会用\n特攻强化吗？\p那可太厉害了。它能\n大幅提升特攻！$"
    .string ""
    .string ""
    .string ""

GoldenrodDeptStore_Text_3FDirectory:
    .string "献给追求胜利的人\p3楼　对战藏品$"
    .string ""


Goldenrod_3F_Berries_Shop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Goldenrod_3f_Berries
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Goldenrod_3f_Berries:
	.2byte ITEM_ZEROMIN
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_TAMATO_BERRY
	pokemartlistend

Goldenrod_DepartmentStore_3F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Goldenrod_DepartmentStore_3F_Pokemart_Vitamins
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Goldenrod_DepartmentStore_3F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Goldenrod_DepartmentStore_3F_Pokemart_StatBoosters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Goldenrod_DepartmentStore_3F_Pokemart_StatBoosters:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

Goldenrod_DepartmentStore_3F_EventScript_TriathleteM::
	msgbox Goldenrod_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
	end

Goldenrod_DepartmentStore_3F_EventScript_PokefanM::
	msgbox Goldenrod_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
	end

Goldenrod_DepartmentStore_3F_EventScript_Woman::
	msgbox Goldenrod_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
	end

Goldenrod_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
	.string "想让宝可梦快速变强，\n道具最管用。\p攻击增强剂能提升攻击，\n特攻增强剂能提升特攻。$"
	.string ""
	.string ""
	.string ""

Goldenrod_DepartmentStore_3F_Text_WantMoreEndurance:
	.string "我想让宝可梦的\n耐力更强。\p该用防御增强剂提升防御，\n还是用特防增强剂提升特防呢？$"
	.string ""
	.string ""
	.string ""

Goldenrod_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
	.string "我给我的宝可梦喂了速度\n增强剂，它的速度提升了。$"
	.string ""
