CeladonCity_Apartments_2F_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER}打开了电脑。\p……\p有人正在写一封邮件。\p……希望你能来关都看看。\p我想，这里的变化之大\n会让你吃惊的。\p你还会见到许多\n并非城都原生的宝可梦。\p致制作人\p……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeladonMansion2F_Text_DevOfficeSign:
	.string "Heart & Soul 开发办公室$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_EventScript_IAmAwesome2::
    msgbox CeladonMansion2F_Text_IAmAwesome2, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "大家好，补丁15——\p抱歉，我是说……\p大家好，我是游戏总监！\p地图、图块集、\n还有脚本，很多东西都是我做的。\p但要是没有其他开发人员\n和测试员，我也做不到。\p感谢你的游玩！\n希望你喜欢《Heart & Soul》。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeladonMansion2F_Text_InfiniteBacon:
	.string "我们正用pokeemerald expansion\n重建这个游戏！\p咦？\p已经有人做过了！$"
	.string ""
	.string ""
	.string ""

CeladonMansion2F_Text_TixoRebel:
	.string "你听说过“蛋劫”吗？\n那是测试时出现的一个程序错误，\l会把宝可梦随机变成\l蛋！\p是我做出的修复！$"
	.string ""
	.string ""
	.string ""
	.string ""

CeladonMansion2F_Text_Phant:
	.string "我最爱降级重制版了！\p你玩过Sword And Shield\nUltimate Plus的英文版吗？\l那是我翻译的！\p下一个降级重制版，我想\n做阿罗拉地区！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CeladonMansion2F_Text_Exclsior:
	.string "我为每只宝可梦都实现了\n独一无二的冲浪图像！\p因为项目是开源的，\n你也可以加入自己的功能！$"
	.string ""
	.string ""
	.string ""

CeladonMansion2F_Text_DaniRaibow:
	.string "嗨！\p我很擅长发现问题，\n也能修好小问题。\p想听个笑话吗？\p阿渡想教快龙招式龙息。\p可是快龙用神速跑得太快，\n龙息根本\l追不上它啊！$"
	.string ""
	.string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

CeladonMansion2F_Text_IAmAwesome2:
	.string "是我把这款游戏重制到了\npokeemerald-expansion上！\p现在你可以收集\n第1到第9世代的全部宝可梦！\p我很感激其他《Heart & Soul》\n总监们为这款游戏\l付出的辛勤努力！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
