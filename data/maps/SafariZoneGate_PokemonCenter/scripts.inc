.set LOCALID_NURSE, 1

SafariZoneGate_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "常来宝可梦中心的人，\n通常都很爱护宝可梦。\p你不这么觉得吗？$"
	.string ""
	.string ""

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "在山里走了很久，\n到处找宝可梦中心，\l累得快要倒下的时候……\p然后感觉就像到了天堂！$"
	.string ""
	.string ""
	.string ""

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "狩猎，狩猎，真开心。\n狩猎，狩猎，真有趣！\p好多宝可梦在等着我们！\p……这是我编的歌。\n我在狩猎地带时就会唱。$"
	.string ""
	.string ""
	.string ""
	.string ""
