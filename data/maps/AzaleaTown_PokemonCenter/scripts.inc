.set LOCALID_NURSE, 1

AzaleaTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "你的宝可梦学会秘传招式了吗？\p就算宝可梦倒下了，\n那些招式也照样能用。$"
	.string ""
	.string ""

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "一个叫正辉的人发明了\n用电脑寄放宝可梦的系统。\p正辉的电脑每个盒子\n能存30只宝可梦。$"
	.string ""
	.string ""
	.string ""

AzaleaPokecenter_Text_FishingGuru:
	.string "正辉的电脑每个盒子\n能存30只宝可梦。$"
	.string ""

AzaleaPokecenter_Text_PokefanF:
	.string "你知道树果吗？\p把树果敲开、挖空，\n再装上特殊的装置。\p然后就可以用它\n来抓宝可梦了。\p在精灵球发明以前，\n大家都是用树果的。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
