local CreatureEntry=72000
local MENU_MAIN=1
local MENU_DIAOWEN=2
local MENU={
	[MENU_MAIN]={
		{icon=1,text="|TInterface\\ICONS\\Spell_Magic_PolymorphRabbit.blp:40:40:-20:-3|t钥匙1",sender=0,index=1,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t钥匙2",sender=0,index=2,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t钥匙3",sender=0,index=3,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t普通宝石",sender=0,index=4,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t高级宝石",sender=0,index=5,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t材料物品1",sender=0,index=6,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t材料物品2",sender=0,index=7,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t材料物品3",sender=0,index=8,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t材料物品4",sender=0,index=9,func=func_pass},
		--{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t传家宝装备",sender=0,index=10,func=func_pass},
		--{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t职业雕文",sender=0,index=11,func=func_pass},
	},
	[MENU_DIAOWEN]={
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t盗贼雕文",sender=0,index=1101,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t德鲁伊雕文",sender=0,index=1102,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t法师雕文",sender=0,index=1103,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t猎人雕文",sender=0,index=1104,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t牧师雕文",sender=0,index=1105,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t骑士雕文",sender=0,index=1106,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t萨满雕文",sender=0,index=1107,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t术士雕文",sender=0,index=1108,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t死骑雕文",sender=0,index=1109,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t战士雕文",sender=0,index=1110,func=func_pass},
	},
}
local MAIN_CLASS_ENTRY={
	[1]=72006,
	[2]=72007,
	[3]=72008,
	[4]=72009,
	[5]=72010,
	[6]=72002,
	[7]=72003,
	[8]=72004,
	[9]=72005,
	[10]=72001,
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

local FUNC={
	function (player,Creature,Diaowen_flag)
		player:SendListInventoryByFlag(Creature,MAIN_CLASS_ENTRY[Diaowen_flag])
	end,
	function (player,Creature,Diaowen_flag)
		player:SendListInventoryByFlag(Creature,DIAOWEN_ENTRY[Diaowen_flag])
	end
}

function MenuItemAdd_Ven(player, Creature,Menu_flag)--演示添加选项
	player:GossipClearMenu()
	Rows=MENU[Menu_flag]
	for k,v in pairs(Rows) do
			player:GossipMenuAddItem(v["icon"],v["text"] ,v["sender"],v["index"])
	end
	player:GossipSendMenu(2,Creature)
end

function sayhello(event, player, Creature)
	MenuItemAdd_Ven(player, Creature,MENU_MAIN)
end

function sayselect(event, player, Creature, sender, intid, code, menu_id)
--player:GossipComplete()
if (intid<=10 and intid>0) then
	FUNC[1](player,Creature,intid)
	player:GossipComplete()	
-- elseif(intid==11)then
-- 	MenuItemAdd_Ven(player, Creature,MENU_DIAOWEN)
-- elseif(intid>=1101 and intid<=1110) then
-- 	FUNC[2](player,Creature,intid)
-- 	player:GossipComplete()	
end

end



RegisterCreatureGossipEvent( CreatureEntry, 1, sayhello )--注册右键对话事件
RegisterCreatureGossipEvent( CreatureEntry, 2, sayselect, 0 )--注册选择事件，0执行几次函数

