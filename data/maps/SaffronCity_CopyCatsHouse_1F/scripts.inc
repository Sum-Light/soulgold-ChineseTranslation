SaffronCity_CopyCatsHouse_1F_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "我女儿喜欢模仿别人。\p她模仿得太像，\n附近的人都叫她模仿少女。$"
	.string ""
	.string ""

CopycatsHouse1F_Text_PokefanF:
	.string "我女儿太以自我为中心了……\p她几乎没什么朋友。$"
	.string ""

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "她最近弄丢了皮皮玩偶，\n那是三年前一个男孩\l送给她的。\p从那以后，她的模仿\n越来越厉害了……$"
	.string ""
	.string ""
	.string ""
	.string ""

CopycatsHouse1F_Text_Blissey:
	.string "幸福蛋：哩咿咿！$"
