PewterCity_Museum_2F_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "听说有陨石坠落到了\n诞生之岛。\p我们很想把它们摆进\n我们的博物馆里，可是……\p据说这些陨石会释放\n奇怪的能量，根本\l搬不走……$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "我想要皮卡丘！\n它好可爱！\p我已经求爸爸去给我\n抓一只了！$"
    .string ""
    .string ""

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "对对，很快就有皮卡丘了，\n我保证！$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "航天飞机$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "坠落在月见山的陨石。\n人们认为它是一块月之石。$"
    .string ""
