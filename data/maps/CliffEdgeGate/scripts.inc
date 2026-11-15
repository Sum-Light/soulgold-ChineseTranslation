CliffEdgeGate_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "你知道吗？\n前面不远处就有个狩猎地带。\p那里真的很好玩！\n能见到各种各样的宝可梦，\l而且可以尽情地抓！\p没理由不去吧？\n就在前面不远处哦。$"
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""
	.string ""

CliffEdgeGate_Text_Expectations:
	.string "大家都这么期待，\n我是很感激啦。\p不过接待处的那位女士\n好像有点太夸张了……\p可别抱太高的期望哦！$"
	.string ""
	.string ""
	.string ""
	.string ""

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "处处惊险刺激！\n探索寻找野生宝可梦！\l园长巴奥巴的狩猎地带\l正在营业中！$"
	.string ""
	.string ""
	.string ""

