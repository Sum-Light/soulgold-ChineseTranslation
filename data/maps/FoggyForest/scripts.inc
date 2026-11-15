FoggyForest_MapScripts::
	.byte 0


FoggyForest_HexManiac::
	trainerbattle_single TRAINER_MINA, FoggyForest_HexManiac_Text_0, FoggyForest_HexManiac_Text_1
	msgbox FoggyForest_HexManiac_Text_2, MSGBOX_AUTOCLOSE
	return


FoggyForest_Girl::
	msgbox FoggyForest_Girl_Text_0, MSGBOX_NPC
	return


FoggyForest_Phantump::
	lock
	faceplayer
	playmoncry SPECIES_PHANTUMP, CRY_MODE_NORMAL
	msgbox FoggyForest_Phantump_Text_0
	waitmoncry
	release
	end


FoggyForestBMTeleport::
	checkitem ITEM_BLACK_MIRROR
	compare VAR_RESULT, TRUE
	goto_if_eq FoggyForestBMTeleport_2
FoggyForestBMTeleport_1:
	release
	end

FoggyForestBMTeleport_2:
	warpwhitefade MAP_FOGGYFOREST_DEPTHS, 8, 24
	waitstate
	goto FoggyForestBMTeleport_1


FoggyForestBMTeleportR::
	checkitem ITEM_BLACK_MIRROR
	compare VAR_RESULT, TRUE
	goto_if_eq FoggyForestBMTeleportR_2
FoggyForestBMTeleportR_1:
	release
	end

FoggyForestBMTeleportR_2:
	warpwhitefade MAP_FOGGYFOREST_DEPTHS, 9, 24
	waitstate
	goto FoggyForestBMTeleportR_1


FoggyForestBMOutTeleport::
	warpwhitefade MAP_FOGGY_FOREST, 38, 5
	waitstate
	release
	end


FoggyForestBMOutTeleportR::
	warpwhitefade MAP_FOGGY_FOREST, 39, 5
	waitstate
	release
	end


FoggyForest_HexManiac_Text_0:
	.string "嘻嘻嘻，你迷路了吗？$"

FoggyForest_HexManiac_Text_1:
	.string "天上的眼睛在看着。$"

FoggyForest_HexManiac_Text_2:
	.string "勇敢，还是愚蠢？\n你身上带着哪一个？$"

FoggyForest_Girl_Text_0:
	.string "转啊转啊，所有的路\n都绕回这里，啦啦啦！$"

FoggyForest_Phantump_Text_0:
	.string "小木灵：噗！$"
