CliffEdgeCave_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "在洞窟里遇到岔路时，\n多半其中一条\l是正确的路，\l另一条则是死路。\p可人就是忍不住两条都想试试。$"
	.string ""
	.string ""
	.string ""
	.string ""
