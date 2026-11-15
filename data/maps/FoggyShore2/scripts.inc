FoggyShore2_MapScripts::
	.byte 0


NijoTrainer::
	trainerbattle_single TRAINER_NIJO, NijoTrainer_Text_0, NijoTrainer_Text_1
	msgbox NijoTrainer_Text_2, MSGBOX_AUTOCLOSE
	end


SaeTrainer::
	trainerbattle_single TRAINER_SAE, SaeTrainer_Text_0, SaeTrainer_Text_1
	msgbox SaeTrainer_Text_2, MSGBOX_AUTOCLOSE
	end


FoggyShoreSign::
	msgbox FoggyShoreSign_Text_0, MSGBOX_SIGN
	return


FoggyShoreBuizel::
	lock
	faceplayer
	playmoncry SPECIES_BUIZEL, CRY_MODE_NORMAL
	msgbox FoggyShoreBuizel_Text_0
	waitmoncry
	release
	end


NijoTrainer_Text_0:
	.string "这种荒郊野外，\n你跑这儿来做什么？$"

NijoTrainer_Text_1:
	.string "你不会有事的。$"

NijoTrainer_Text_2:
	.string "附近的小路通向一座森林，\n很多人都在里面迷了路。\p要是打算进去，\n可得当心点。$"

SaeTrainer_Text_0:
	.string "安静的海滩，最适合度假了！$"

SaeTrainer_Text_1:
	.string "清静全毁了！$"

SaeTrainer_Text_2:
	.string "因为附近有闹鬼树林的传闻，\n很少有人会到这儿来。$"

FoggyShoreSign_Text_0:
	.string "{UP_ARROW}迷失森林$"

FoggyShoreBuizel_Text_0:
	.string "泳圈鼬：噗咿噗咿噗咿——！$"
