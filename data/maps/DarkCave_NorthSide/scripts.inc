
DarkCave2_EventScript_BlackGlasses::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_GOT_BLACK_GLASSES
	closemessage
	release
	end

DarkCave2_EventScript_BlackGlassesGot::
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
	closemessage
	release
	end

DarkCave2_Text_Nerd:
    .string "哇！你吓了我一跳！\p我戴着黑色眼镜，\n所以完全没注意到你。\p你问我在这里做什么？\p嘿，这你就别管了。\p我送你一副黑色眼镜，\n你就当没见过我，好吗？$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

DarkCave2_Text_Nerd2:
    .string "黑色眼镜能提高\n恶属性招式的威力。$"
    .string ""

DarkCave_NorthSide_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_IS_CHAMPION, DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_HIDE_TERRAKION
	return

DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_TERRAKION
	return

DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	goto_if_unset FLAG_CAUGHT_TERRAKION, DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_2


DarkCave_TerrakionEncounter::
	lock
	faceplayer
	bosslegendaryencounter SPECIES_TERRAKION, 80, LOCALID_TERRAKION, FLAG_HIDE_TERRAKION, 2, SPECIES_NONE, 110
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DarkCave_TerrakionEncounter_2
DarkCave_TerrakionEncounter_1:
	release
	end

DarkCave_TerrakionEncounter_2:
	setflag FLAG_CAUGHT_TERRAKION
	goto DarkCave_TerrakionEncounter_1

