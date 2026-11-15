BattleFrontier_Lounge9_MapScripts::
	.byte 0

BattleFrontier_Lounge9_Heal::
	msgbox BattleFrontier_Lounge9_Heal_TEXT, MSGBOX_NPC
	waitmessage
	fadescreen 0x1
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen 0x0
	msgbox BattleFrontier_Lounge9_Heal_TEXT2, MSGBOX_NPC
	waitmessage
	release
	end

BattleFrontier_Lounge9_Heal_TEXT:
	.string "您好！欢迎来到格斗道场！\n我来为您治疗宝可梦。$"
	.string ""

BattleFrontier_Lounge9_Heal_TEXT2:
	.string "期待您再次光临！$"
