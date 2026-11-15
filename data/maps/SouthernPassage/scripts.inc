SouthernPassage_MapScripts::
	.byte 0


BlockSouthJohtoAccess::
	lock
	msgbox BlockSouthJohtoAccess_Text_0
	applymovement LOCALID_PLAYER, BlockSouthJohtoAccess_Movement_0
	release
	end


BlockSouthJohtoAccess_Movement_0:
	walk_up
	step_end

BlockSouthJohtoAccess_Text_0:
	.string "前方的潮水似乎太急，现在\n过不去。最好先回去吧。\p系统提示：前方区域在此版本\n中尚未开放。$"
