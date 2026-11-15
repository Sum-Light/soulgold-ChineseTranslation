SnowtopMountainOutside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SnowtopMountainOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SnowtopMountainOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_SNOWTOP_MOUNTAIN
	end


SnowtopMountainOutside_Snover::
	lock
	faceplayer
	playmoncry SPECIES_SNOVER, CRY_MODE_NORMAL
	msgbox SnowtopMountainOutside_Snover_Text_0
	waitmoncry
	release
	end


SnowtopMountainOutside_Articuno::
	lock
	faceplayer
	legendaryencounter SPECIES_ARTICUNO, 50, LOCALID_ARTICUNO, FLAG_HIDE_ARTICUNO
	release
	end


SnowtopMountainOutside_Sign::
	msgbox SnowtopMountainOutside_Sign_Text_0, MSGBOX_SIGN
	return


SnowtopMountainOutside_Snover_Text_0:
	.string "雪笠怪：雪呜！$"

SnowtopMountainOutside_Sign_Text_0:
	.string "雪顶山\n前方气温严寒！$"
