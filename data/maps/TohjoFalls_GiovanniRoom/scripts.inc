
TohjoFalls_GiovanniRoom_MapScripts::
	.byte 0

TohjoPassGuard::
	lock
	faceplayer
	playmoncry SPECIES_RHYPERIOR, CRY_MODE_NORMAL
	msgbox TohjoPassGuard_Text_0
	waitmoncry
	msgbox TohjoPassGuard_Text_1
	release
	end


TohjoPassGuard_Text_0:
	.string "超甲狂犀：呜……$"

TohjoPassGuard_Text_1:
	.string "超甲狂犀守在山洞入口，\n气势逼人。\p你决定改天再来。$"
