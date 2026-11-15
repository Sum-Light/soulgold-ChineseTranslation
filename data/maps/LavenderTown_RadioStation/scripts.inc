LavenderTown_RadioStation_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "欢迎！这一层您可以随意参观。$"
	.string ""

LavenderTown_RadioStation_Text_Officer:
	.string "抱歉，您只能参观一楼。\p自从城都地区的播音塔\n被犯罪团伙占据以后，\l我们的警备\l就不得不加强了。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "播音塔里有很多人\n在辛勤工作。\p他们一定在全力以赴\n制作好节目。$"
	.string ""
	.string ""
	.string ""

LavenderTown_RadioStation_Text_Gentleman:
	.string "不不不，糟了！\p自从发电厂停工，\n我们就一直没法广播。\p要是不能继续播出，我创办\n这个播音塔的全部心血\l就白费了。\p我就要完蛋了！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "啊！您就是那位解决了\n发电厂问题的{PLAYER}？\p多亏了您，我才没有丢掉工作。\p跟您说，您真是我的大救星！\p请收下这个，聊表谢意。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER}得到了\n收音机升级装置！$"
	.string ""

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "有了那个，您就能收听\n关都地区的广播节目了。\p嘎哈哈哈哈哈！$"
	.string ""
	.string ""

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "你好呀！\p我是超级音乐总监！\p嗯？你的收音机收不到\n我的音乐节目。真可惜！\p只要装上扩张卡升级一下，\n就能收听了。你最好\l去弄一个！$"
	.string ""
	.string "" @Pokégear
	.string ""
	.string ""
	.string ""
	.string ""

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "你好呀！\p我是超级音乐总监！\p空中飘荡的那些优美旋律，\n可都是经由我手的。\p别落伍了，快打开收音机\n听音乐吧！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

LavenderTown_RadioStation_Text_Directory:
	.string "1楼　接待处　2楼　营业部\p3楼　人事部　4楼　制作部\p5楼　局长室$"
	.string ""
	.string ""

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "用宝可梦之笛的舒缓音色\n让宝可梦打起精神\l第20频道$"
	.string ""
	.string ""

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "哇！满满一架子的\n宝可梦CD和录像带。\p这里一定就是参考资料室。$"
	.string ""
	.string ""
	.string ""

