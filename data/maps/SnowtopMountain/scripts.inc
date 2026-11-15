SnowtopMountain_MapScripts::
	.byte 0


SnowtopMountain_Sage::
	lock
	faceplayer
	msgbox SnowtopMountain_Sage_Text_0
	msgbox SnowtopMountain_Sage_Text_1
	release
	end


SnowtopMountain_Slowking::
	lock
	faceplayer
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	msgbox SnowtopMountain_Slowking_Text_0
	waitmoncry
	release
	end


SnowtopMountain_Sage_Text_0:
	.string "只有证明了自己\n不仅仅是本地区冠军的人，\l才能从这里通过。$"

SnowtopMountain_Sage_Text_1:
	.string "……你还没有资格。$"

SnowtopMountain_Slowking_Text_0:
	.string "呆——呆……！$"
