local CreatureEntry=71000
local MENU_MAIN=1
local MENU_SHANGYE=2
local MENU={
	[MENU_MAIN]={
		{icon=1,text="|TInterface\\ICONS\\Spell_Magic_PolymorphRabbit.blp:40:40:-20:-3|t职业技能训练",sender=0,index=1,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t商业技能训练",sender=0,index=2,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t武器技能训练",sender=0,index=3,func=func_pass},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t武器熟练度加满",sender=0,index=6,func=func_pass,code=false,popup="需要扣除1000积分",money=0},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t商业熟练度加满",sender=0,index=7,func=func_pass,code=false,popup="需要扣除2000积分",money=0},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t重置天赋",sender=0,index=4,func=func_pass,code=false,popup="确认重置天赋",money=100000},
		{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t开启双天赋",sender=0,index=5,func=func_pass,code=false,popup="确认开启双天赋",money=100000},
		--{icon=1,text="|TInterface\\ICONS\\INV_ThanksGiving_Turkey_ACT.blp:40:40:-20:-3|t积分查询",sender=0,index=6,func=func_pass},
	},
	[MENU_SHANGYE]={
		{icon=1,text="烹饪",sender=0,index=21,func=func_pass},
		{icon=1,text="裁缝",sender=0,index=22,func=func_pass},
		{icon=1,text="锻造",sender=0,index=23,func=func_pass},
		{icon=1,text="剥皮",sender=0,index=24,func=func_pass},
		{icon=1,text="采矿",sender=0,index=25,func=func_pass},
		{icon=1,text="药草学",sender=0,index=26,func=func_pass},
		{icon=1,text="地精工程",sender=0,index=27,func=func_pass},
		{icon=1,text="钓鱼",sender=0,index=28,func=func_pass},
		{icon=1,text="飞行",sender=0,index=29,func=func_pass},
		{icon=1,text="附魔",sender=0,index=30,func=func_pass},
		{icon=1,text="工程学",sender=0,index=31,func=func_pass},
		{icon=1,text="急救",sender=0,index=32,func=func_pass},
		{icon=1,text="炼金术",sender=0,index=33,func=func_pass},
		{icon=1,text="铭文",sender=0,index=34,func=func_pass},
		{icon=1,text="骑术",sender=0,index=35,func=func_pass},
		{icon=1,text="制皮",sender=0,index=36,func=func_pass},
		{icon=1,text="侏儒工程学",sender=0,index=37,func=func_pass},
		{icon=1,text="珠宝加工",sender=0,index=38,func=func_pass},
	},
}
local ZHIYE_CLASS_ENTRY={
	[1]=913,--战士
	[8]=331,--法师
	[3]=987,--猎人
	[5]=376,--牧师
	[11]=3033,--德鲁伊
	[4]=917,--潜行者
	[7]=986,--萨满
	[9]=461,--术士
	[2]=71007,--圣骑士
	[6]=28472,--死亡骑士
}
local SHANGYE_ENTRY={
	[21]=26905,--烹饪
	[22]=71001,--裁缝
	[23]=71002,--锻造
	[24]=33618,--剥皮
	[25]=33617,--采矿
	[26]=33616,--药草学
	[27]=8738,--地精工程
	[28]=33623,--钓鱼
	[29]=28746,--飞行
	[30]=33610,--附魔
	[31]=71003,--工程学
	[32]=33621,--急救
	[33]=33608,--炼金术
	[34]=33615,--铭文
	[35]=4752,--骑术
	[36]=71004,--制皮
	[37]=7406,--侏儒工程学
	[38]=33614,--珠宝加工
}
function traceback( msg )  
    print("----------------------------------------")  
    print("LUA ERROR: " .. tostring(msg) .. "\n")  
    print(debug.traceback())  
    print("----------------------------------------")  
end  
local FUNC={
	function (player,Creature,zhiye_flag)--发送职业技能学习列表
		player:SendTrainerListByFlag(Creature,ZHIYE_CLASS_ENTRY[zhiye_flag])
		--player:SendTrainerList(Creature)
	end,
	function (player,Creature,intid)--发送商业技能学习列表
		player:SendTrainerListByFlag(Creature,SHANGYE_ENTRY[intid])
	end,
	function (player,Creature)--发送武器技能学习列表
		player:SendTrainerListByFlag(Creature,71011)
	end,
	function (player,Creature)--重置天赋
		player:ResetTalents(false)
		player:ModifyMoney(-MENU[MENU_MAIN][3]["money"])
		player:SendBroadcastMessage("已经扣除"..tostring(MENU[MENU_MAIN][3]["money"]/10000).."个金！")
		player:SendBroadcastMessage("已经重置天赋！")
	end,
	function (player,Creature)--开启双天赋
		if(player:HasSpell( 63644 ))then
			player:SendBroadcastMessage("你已经开启了双天赋，不要重复开启！")
		else
		player:CastSpell( player, 63624, false )
		player:CastSpell( player, 63680, false )
		player:ModifyMoney(-MENU[MENU_MAIN][4]["money"])
		player:SendBroadcastMessage("已经扣除"..tostring(MENU[MENU_MAIN][4]["money"]/10000).."个金！")
		player:SendBroadcastMessage("已经开启双天赋！")
		end
	end,
	-- function (player)--查询剩余积分
	-- 	--player:SendAddonMessage(AIO_ServerPrefix, msg, 7, player)
	-- 	jf=player:GetPlayerJF()
	-- 	player:SendBroadcastMessage("剩余可用积分："..tostring(jf))
	-- end,
	function (player)--武器熟练度加满
		if (player:GetPlayerJF()>=1000) then
		player:AdvanceSkillsToMax()
		player:SetPlayerJF(-1000);
		player:SendBroadcastMessage("当前武器熟练度已经达到最大值")
		else
			player:SendBroadcastMessage("积分不足！")
		end

	end,
	function (player)--商业技能熟练度加满
		if (player:GetPlayerJF()>=2000) then
			player:AdvanceSkill(171, 450)
	        player:AdvanceSkill(164, 450)
	        player:AdvanceSkill(333, 450)
	        player:AdvanceSkill(202, 450)
	        player:AdvanceSkill(182, 450)
	        player:AdvanceSkill(773, 450)
	        player:AdvanceSkill(755, 450)
	        player:AdvanceSkill(165, 450)
	        player:AdvanceSkill(186, 450)
	        player:AdvanceSkill(393, 450)
	        player:AdvanceSkill(197, 450)
	        player:AdvanceSkill(185, 450)
	        player:AdvanceSkill(129, 450)
	        player:AdvanceSkill(356, 450)
	        player:SetPlayerJF(-2000);
	        player:GossipComplete("当前技能已满")
        else
			player:SendBroadcastMessage("积分不足！")
		end
        
	end,
}

function MenuItemAdd_Tra(player, Creature,Menu_flag)--演示添加选项
	player:GossipClearMenu()
	Rows=MENU[Menu_flag]
	for k,v in pairs(Rows) do
		if(v["popup"]~=nil)then
			player:GossipMenuAddItem(v["icon"],v["text"] ,v["sender"],v["index"],v["code"],v["popup"],v["money"])--如果popup内有内容，则会在点击之后提示一个确认框，确认后才会执行对应的函数。money可以自动检测钱是否够，不够就不会执行函数.code则可以通过select事件将值传递到函数内部
		else
			player:GossipMenuAddItem(v["icon"],v["text"] ,v["sender"],v["index"])
		end
	end
	player:GossipSendMenu(2,Creature)
end
function sayhello(event, player, Creature)
	MenuItemAdd_Tra(player, Creature,MENU_MAIN)
end
function sayselect(event, player, Creature, sender, intid, code, menu_id)
--player:GossipComplete()
if (intid==1) then
	FUNC[intid](player,Creature,player:GetClass())
	player:GossipComplete()	
elseif(intid==2) then
	MenuItemAdd_Tra(player, Creature,MENU_SHANGYE)
elseif(intid>20 and intid<40) then
	FUNC[MENU_SHANGYE](player,Creature,intid)
	player:GossipComplete()
elseif(intid==3 or intid==4 or intid==5 )then
	FUNC[intid](player,Creature)
	player:GossipComplete()
elseif(intid==6) then
	FUNC[intid](player)
	player:GossipComplete()
elseif(intid==7) then
	FUNC[intid](player)
	player:GossipComplete()
elseif(intid==8) then
	FUNC[intid](player)
	player:GossipComplete()
end

end

RegisterCreatureGossipEvent( CreatureEntry, 1, sayhello )--注册右键对话事件
RegisterCreatureGossipEvent( CreatureEntry, 2, sayselect, 0 )--注册选择事件，0执行几次函数