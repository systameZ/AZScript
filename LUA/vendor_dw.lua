local diaowenEntry=72100
local DW_MENU_MAIN=1
local DW_MENU_DIAOWEN=2
local DW_MENU={
	[DW_MENU_DIAOWEN]={
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t盗贼雕文",sender=0,index=1101,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t德鲁伊雕文",sender=0,index=1102,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t法师雕文",sender=0,index=1103,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t猎人雕文",sender=0,index=1104,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t牧师雕文",sender=0,index=1105,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t骑士雕文",sender=0,index=1106,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t萨满雕文",sender=0,index=1107,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t术士雕文",sender=0,index=1108,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t死骑雕文",sender=0,index=1109,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t战士雕文",sender=0,index=1110,func=func_pass}
	}
}
local DIAOWEN_ENTRY={
	[1101]=72011,
	[1102]=72012,
	[1103]=72013,
	[1104]=72014,
	[1105]=72015,
	[1106]=72016,
	[1107]=72017,
	[1108]=72018,
	[1109]=72019,
	[1110]=72020,
}

local DW_FUNC={
	function (player,Creature,Diaowen_flag)
		player:SendListInventoryByFlag(Creature,MAIN_CLASS_ENTRY[Diaowen_flag])
	end,
	function (player,Creature,Diaowen_flag)
		player:SendListInventoryByFlag(Creature,DIAOWEN_ENTRY[Diaowen_flag])
	end
}

function DW_MenuItemAdd_Ven(player, Creature,Menu_flag)--演示添加选项
	player:GossipClearMenu()
	Rows=DW_MENU[Menu_flag]
	for k,v in pairs(Rows) do
			player:GossipMenuAddItem(v["icon"],v["text"] ,v["sender"],v["index"])
	end
	player:GossipSendMenu(2,Creature)
end



function diaowenhello(event, player, Creature)
	DW_MenuItemAdd_Ven(player, Creature,DW_MENU_DIAOWEN)
end


function diaowenselect(event, player, Creature, sender, intid, code, menu_id)

if (intid>=1101 and intid<=1110) then
	DW_FUNC[2](player,Creature,intid)
	player:GossipComplete()	
end

end

RegisterCreatureGossipEvent( diaowenEntry, 1, diaowenhello )--注册右键对话事件
RegisterCreatureGossipEvent( diaowenEntry, 2, diaowenselect, 0 )--注册选择事件，0执行几次函数