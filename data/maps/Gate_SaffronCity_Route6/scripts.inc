Gate_SaffronCity_Route6_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "欢迎来到金黄市，\n磁浮列车的故乡！\p……平时我都会这么说的，\n不过磁浮列车现在\l停运了。\p因为无人发电厂出了故障，\n列车断了电，\l开不动了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Route6_Text_SaffronGuardMagnetTrain:
	.string "金黄市最有名的，\n就是磁浮列车了。$"
	.string ""
