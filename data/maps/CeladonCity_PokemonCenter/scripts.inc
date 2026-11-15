.set LOCALID_NURSE, 1

CeladonCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "莉佳是草属性宝可梦的高手。\p你要是不当心，\n可是要付出代价的。$"
	.string ""
	.string ""
	.string ""

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "火箭队的基地就在游戏城的地下。\p哦，等等。那都是三年前的事了。$"
	.string ""
	.string ""
	.string ""

Celadon_Text_Eusine1:
	.string "米那君：嗨！\p我回老家来看看。\p好久没回来了。$"
	.string ""
	.string ""

Celadon_Text_EusineLeaves:
	.string "{PLAYER}，你听说了吗？\p听说最近又有传闻，\n有虹色的宝可梦出现在铃铛塔。\p我刚治好宝可梦，\n现在正要去缘朱市。\p再见了，{PLAYER}！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

Celadon_Text_NoBeasts:
	.string "对了，{PLAYER}。\p你抓到传说的宝可梦\n雷公和炎帝了吗？\p<……><……><……>\p好吧……\p就算只抓到一只，\n也希望你能告诉我。\p拜托你了，{PLAYER}！$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
