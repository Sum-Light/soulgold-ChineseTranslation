GoldenrodBattleAracdeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodBattleAracdeLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GoldenrodBattleAracdeLobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

GoldenrodBattleAracdeLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleArcade_Registration_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleArcade_Registration_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleArcade_Registration_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleArcade_Registration_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleArcade_Registration_EventScript_LostChallenge
	.2byte 0

GoldenrodBattleAracdeLobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_1, 0, BattleArcade_Lobby_EventScript_PlayerFaceNorth
	.2byte 0


GoldenrodArcadeLobby_Rocker::
	lock
	msgbox GoldenrodArcadeLobby_Rocker_Text_0
	release
	end


GoldenrodArcadeLobby_Oldman::
	lock
	msgbox GoldenrodArcadeLobby_Oldman_Text_0
	release
	end


GoldenrodArcadeLobby_Battlegirl::
	lock
	msgbox GoldenrodArcadeLobby_Battlegirl_Text_0
	release
	end


GoldenrodArcadeLobby_Shop::
	lock
	msgbox GoldenrodArcadeLobby_Shop_Text_0
	waitmessage
	pokemart GoldenrodArcade_Shop
	msgbox GoldenrodArcadeLobby_Shop_Text_1
	release
	end


	.align 2
GoldenrodArcade_Shop:
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_SHIN_GENOME
	.2byte ITEM_SCROLL_OF_WATERS
	.2byte ITEM_SCROLL_OF_DARKNESS
	.2byte ITEM_HP_UP_EX
	.2byte ITEM_PROTEIN_EX
	.2byte ITEM_IRON_EX
	.2byte ITEM_CALCIUM_EX
	.2byte ITEM_ZINC_EX
	.2byte ITEM_CARBOS_EX
	.2byte ITEM_PP_MAX
	.2byte ITEM_NONE

GoldenrodArcade_Queue2::
	msgbox GoldenrodArcade_Queue2_Text_0, MSGBOX_NPC
	return


GoldenrodArcade_Queue3::
	msgbox GoldenrodArcade_Queue3_Text_0, MSGBOX_NPC
	return


GoldenrodArcade_Queue4::
	msgbox GoldenrodArcade_Queue4_Text_0, MSGBOX_NPC
	return


ArcadeLobby_GameMachine::
	msgbox ArcadeLobby_GameMachine_Text_0, MSGBOX_NPC
	return


MagernaKeyBurglar::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGERNA_KEY, MagernaKeyBurglar_2
	goto_if_unset FLAG_GOT_MAGERNA_KEY_INTRODONE, MagernaKeyBurglar_5
MagernaKeyBurglar_4:
	msgbox MagernaKeyBurglar_Text_3
	specialvar VAR_RESULT, GetRocketArcadeWins
	compare VAR_RESULT, 25
	goto_if_ge MagernaKeyBurglar_8
	release
	end

MagernaKeyBurglar_2:
	msgbox MagernaKeyBurglar_Text_0
	msgbox MagernaKeyBurglar_Text_1
	release
	end

MagernaKeyBurglar_5:
	msgbox MagernaKeyBurglar_Text_2
	setflag FLAG_GOT_MAGERNA_KEY_INTRODONE
	goto MagernaKeyBurglar_4

MagernaKeyBurglar_8:
	msgbox MagernaKeyBurglar_Text_4
	playfanfare MUS_HG_OBTAIN_KEY_ITEM
	msgbox MagernaKeyBurglar_Text_5
	waitfanfare
	msgbox MagernaKeyBurglar_Text_6
	msgbox MagernaKeyBurglar_Text_7
	setflag FLAG_GOT_MAGERNA_KEY
	release
	end


GoldenrodArcadeLobby_Rocker_Text_0:
	.string "这些机器肯定动了手脚！\n我怎么可能一下子全输光！$"

GoldenrodArcadeLobby_Oldman_Text_0:
	.string "哈哈！又赢了一局！\n这周末能给女儿买点好东西！$"

GoldenrodArcadeLobby_Battlegirl_Text_0:
	.string "啊啊啊啊啊啊啊啊啊啊啊啊！\n再赢一局我就收手！$"

GoldenrodArcadeLobby_Shop_Text_0:
	.string "欢迎光临。$"

GoldenrodArcadeLobby_Shop_Text_1:
	.string "欢迎下次再来。$"

GoldenrodArcade_Queue2_Text_0:
	.string "我都等不及想在前排\n看下一场对战了！$"

GoldenrodArcade_Queue3_Text_0:
	.string "喂！别推！是我先来的！$"

GoldenrodArcade_Queue4_Text_0:
	.string "这里是满金游戏城吗？\n我好像有点迷路了……$"

ArcadeLobby_GameMachine_Text_0:
	.string "屏幕上刺眼的光和画面不断\n闪烁，看得人眼花。\l还是别碰了……$"

MagernaKeyBurglar_Text_0:
	.string "用这把钥匙就能进入\n"
	.string "满金天空公寓的顶层。$"

MagernaKeyBurglar_Text_1:
	.string "至于我嘛，现在已经\n富得流油啦！\l再见了冰汤，你好腌鲑鱼！$"

MagernaKeyBurglar_Text_2:
	.string "嘿，冠军，有没有兴趣看看\n一些来路可能不太合法的\l特别货品？\p比如说，这把能打开\n满金天空公寓顶层住户\l大门的钥匙！\p谁知道上面有多少财宝\n等着人去拿呢？\p你只要帮我一个小忙，\n它说不定就是你的了。$"

MagernaKeyBurglar_Text_3:
	.string "我要你在火箭游戏城的\n对战里至少赢下25场，\l我的赌注可全押在你\l身上，就等着你替我\l赢一大笔了！$"

MagernaKeyBurglar_Text_4:
	.string "你……你真的做到了！\p太感谢你了。来，这是\n说好的东西。$"

MagernaKeyBurglar_Text_5:
	.string "{PLAYER}得到了公寓钥匙！$"

MagernaKeyBurglar_Text_6:
	.string "用它就能进入满金天空\n"
	.string "公寓的顶层。$"

MagernaKeyBurglar_Text_7:
	.string "至于我嘛，也该跟冰汤\n说再见了！$"
