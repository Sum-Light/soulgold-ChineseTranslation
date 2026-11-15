LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end


LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end


LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "唔……\p攻击招式……\n防御招式……\p决定教给宝可梦\n什么招式真是困难……$"
	.string ""
	.string ""
	.string ""
	.string ""

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "有许多不同种类的\n招式学习器呢，\p我读过的图鉴上说\n一共有50种不同的类型。$"
	.string ""
	.string ""
	.string ""

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "我想要所有的招式学习器，\n但1只宝可梦只能学4种招式。$"
	.string ""

