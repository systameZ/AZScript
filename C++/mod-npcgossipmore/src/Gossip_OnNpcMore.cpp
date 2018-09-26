#pragma execution_character_set("utf-8")
#include "ScriptPCH.h"

#include "Player.h"

#include "Chat.h"

#include "ObjectMgr.h"

#include "ScriptMgr.h"

#include "Item.h"

#include "Config.h"

#include "Pet.h"

#include "SharedDefines.h"

#include "../../mod-transmog/src/Transmogrification.h"

#define sT  sTransmogrification



class Gossip_OnNpcOneQuest : public CreatureScript

{

public:

	Gossip_OnNpcOneQuest() :CreatureScript("Gossip_OnNpcOneQuest") {}

	



	//bool OnGossipHello(Player* player, Creature* creature)

	//{

	//	ClearGossipMenuFor(player);
	//	
	//	AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t新手任务", GOSSIP_SENDER_MAIN, 1010);

	//	SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
	//	return true;
	//	/*AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t测试任务", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
	//	SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());*/


	//}

	//bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) { 
	//	ClearGossipMenuFor(player);
	//	switch (sender)
	//	{
	//	case 1:
	//		switch (action)
	//		{
	//		case 1010:
	//		{
	//			uint32 flag = 0;
	//			for each(auto quest_id in xinshouquest)
	//			{
	//				if (!player->IsActiveQuest(quest_id.first) ) {
	//					if (player->IsQuestRewarded(quest_id.first)) {
	//						continue;
	//					}
	//					switch (flag) {
	//					case 0:
	//							AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t小试牛刀", 2, 2010);
	//						break;
	//					case 1:
	//						AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t初露锋芒", 2, 2020);
	//						break;
	//					default:
	//						break;
	//					}
	//				}
	//				else if (player->GetQuestStatus(quest_id.first) == QUEST_STATUS_COMPLETE) {
	//					if (player->IsQuestRewarded(quest_id.first)) {
	//						continue;
	//					}
	//					switch (flag)
	//					{
	//					case 0:
	//						AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t|cffffff00小试牛刀（完成）|r", 21, 2010);
	//						break;
	//					case 1:
	//						AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t|cffffff00初露锋芒（完成）|r", 2, 2020);
	//						break;
	//					default:
	//						break;
	//					}
	//					
	//				}
	//				flag++;
	//			}
	//			AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t返回主菜单", GOSSIP_SENDER_MAIN, 1090);
	//			SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
	//			return true;
	//		}
	//		case 1090:
	//			OnGossipHello(player, creature);
	//			return true;
	//		default:
	//			break;
	//		}
	//		
	//		break;
	//	case 2:
	//		switch (action)
	//		{
	//		case 2010: 
	//			AcceptQuest(player,creature, 975100, xinshouquest[975100][0]);
	//			break;
	//		case 2020:
	//			AcceptQuest(player, creature, 976100, xinshouquest[976100][0]);
	//			break;
	//		default:
	//			break;
	//		}
	//		break;
	//	case 21://二菜单的完成任务
	//		switch (action)
	//		{
	//		case 2010:
	//			ComplateQuest(player,creature, 975100);
	//			break;
	//		case 2020:
	//			ComplateQuest(player, creature, 976100);
	//			break;
	//		default:
	//			break;
	//		}
	//		break;
	//	default:
	//		break;
	//	}

	//	CloseGossipMenuFor(player);
	//	return true;
	//}
	//




	bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
	{ 

		/*if (HaveOtherQuest(player,quest->GetQuestId(),xinshouquest[quest->GetQuestId()][0])) {
			ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【任务公告】|r存在未完成的其他等级的当前任务,！");
			player->RemoveActiveQuest(quest->GetQuestId(),true);
		}
		else {
			if (player->QueryDiffQuestByInstance(player->GetGUID(), xinshouquest[quest->GetQuestId()][0])) {
				player->DelDiffQuestByInstance(player->GetGUID(), xinshouquest[quest->GetQuestId()][0]);
				player->SetDiffQuestByInstance(player->GetGUID(), xinshouquest[quest->GetQuestId()][0], xinshouquest[quest->GetQuestId()][1]);
				return true;
			}
			else {
				player->SetDiffQuestByInstance(player->GetGUID(), xinshouquest[quest->GetQuestId()][0], xinshouquest[quest->GetQuestId()][1]);
				return true;
			}
		}*/
		if (!HaveOtherQuest(player, quest->GetQuestId(), xinshouquest[quest->GetQuestId()][0])) {
			if (player->QueryDiffQuestByInstance(player->GetGUID(), xinshouquest[quest->GetQuestId()][0])) {
				player->DelDiffQuestByInstance(player->GetGUID(), xinshouquest[quest->GetQuestId()][0]);
				player->SetDiffQuestByInstance(player->GetGUID(), xinshouquest[quest->GetQuestId()][0], xinshouquest[quest->GetQuestId()][1]);
				return true;
			}
			else {
				player->SetDiffQuestByInstance(player->GetGUID(), xinshouquest[quest->GetQuestId()][0], xinshouquest[quest->GetQuestId()][1]);
				return true;
			}
		}
		return false; 
	}

	bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt) {
	    player->DelDiffQuestByInstance(player->GetGUID(), xinshouquest[quest->GetQuestId()][0]);
		return true;
	}
private:
	std::unordered_map<uint32, vector<int>> xinshouquest = {
		{ 975100 ,{547,1}},
		{ 976100 ,{ 547,2}},
		{ 977100 ,{ 547,3}},
		{ 985100 ,{ 409,1 } },
		{ 986100 ,{	409,2 } },
		{ 987100 ,{	409,3 } },
		{ 915100 ,{ 550,1 } },
		{ 916100 ,{ 550,2 } },
		{ 917100 ,{ 550,3 } },
		{ 925100 ,{ 544,1 } },
		{ 926100 ,{ 544,2 } },
		{ 927100 ,{ 544,3 } },
	};


	void GiveQuest(Player* player, Creature* creature,uint32 questid) {
		Quest const* quest = sObjectMgr->GetQuestTemplate(questid);
		if (!player->IsQuestRewarded(quest->GetQuestId())) {
			if (!player->GetQuestStatus(quest->GetQuestId())) {
				player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, creature->GetGUID(), false);
				return ;
			}
			//player->PlayerTalkClass->SendQuestGiverRequestItems(quest, creature->GetGUID(), true, true);
		}
	}

	bool HaveOtherQuest(Player* player,uint32 questid,uint32 mapid) {
		uint32 initid = ((questid / 10000) * 10000) + 5100;
		for (uint32 i = initid;i < initid + 3000;i += 1000) {
			if (player->IsActiveQuest(i) && i != questid) {	
				return true;
			}
		}		
		return false;
	}

	void AcceptQuest(Player* player, Creature* creature, uint32 questid,uint32 mapid) {
		if (HaveOtherQuest(player, questid,mapid)) {
			ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【任务公告】|r存在未完成的其他等级的当前任务！");
		}
		else {
			if (player->QueryDiffQuestByInstance(player->GetGUID(), mapid)) {
				player->DelDiffQuestByInstance(player->GetGUID(), mapid);
			}
			else {
				GiveQuest(player, creature, questid);
			}
		}
	}

	void ComplateQuest(Player* player, Creature* creature,uint32 questid) {
		Quest const* quest = sObjectMgr->GetQuestTemplate(questid);
		player->PlayerTalkClass->SendQuestGiverRequestItems(quest, creature->GetGUID(), true, true);
	}

};



class Item_AddTalent : public ItemScript

{
public:
	Item_AddTalent():ItemScript("Item_AddTalent") {}
	bool OnUse(Player* player, Item* item, SpellCastTargets const& selectItem) {
		uint32 maxusedcount = 0;
		uint32 allcount = player->GetUsedTalentCount() + player->GetFreeTalentPoints();
		switch (player->getClass())
		{
			case CLASS_WARRIOR:
				maxusedcount = 228;
				break;
			case CLASS_PALADIN:
				maxusedcount = 211;
				break;
			case CLASS_HUNTER:
				maxusedcount = 227;
				break;
			case CLASS_ROGUE:
				maxusedcount = 224;
				break;
			case CLASS_PRIEST:
				maxusedcount = 220;
				break;
			case CLASS_DEATH_KNIGHT:
				maxusedcount = 231;
				break;
			case CLASS_SHAMAN:
				maxusedcount = 225;
				break;
			case CLASS_MAGE:
				maxusedcount = 228;
				break;
			case CLASS_WARLOCK:
				maxusedcount = 215;
				break;
			case CLASS_DRUID:
				maxusedcount = 233;
				break;
		}


		if (allcount >= maxusedcount) {
			ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【公告】|r天赋点已满，已将点数转化为积分。");
			player->ModifyUSERJF(100);
			return true;
		}
		player->ModifyTalentAddCount(1);
		ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【公告】|r天赋点+1");
		return true;
	}

	

};



class Gossip_OnNpcOneXinShouShangRen : public CreatureScript

{

public:

	Gossip_OnNpcOneXinShouShangRen() :CreatureScript("Gossip_OnNpcOneXinShouShangRen") {}




	bool OnGossipHello(Player* player, Creature* creature)

	{
		ClearGossipMenuFor(player);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t新手板甲", GOSSIP_SENDER_MAIN, 1011);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t新手布甲", GOSSIP_SENDER_MAIN, 1012);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t新手锁甲", GOSSIP_SENDER_MAIN, 1013);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t新手皮甲", GOSSIP_SENDER_MAIN, 1014);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t新手首饰", GOSSIP_SENDER_MAIN, 1015);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t新手武器", GOSSIP_SENDER_MAIN, 1016);
		SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;

	}
	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) {
		
		ClearGossipMenuFor(player);

		if (sender == GOSSIP_SENDER_MAIN ) {
			switch (action)
			{
			case 1011:
				player->GetSession()->SendListInventory(creature->GetGUID(), 76001);
				break;
			case 1012:
				player->GetSession()->SendListInventory(creature->GetGUID(), 76002);
				break;
			case 1013:
				player->GetSession()->SendListInventory(creature->GetGUID(), 76003);
				break;
			case 1014:
				player->GetSession()->SendListInventory(creature->GetGUID(), 76004);
				break;
			case 1015:
				player->GetSession()->SendListInventory(creature->GetGUID(), 76005);
				break;
			case 1016:
				player->GetSession()->SendListInventory(creature->GetGUID(), 76006);
				break;
			default:
				break;
			}
			
		}
		CloseGossipMenuFor(player);
		return true;
	}
};



class Gossip_OnNpcOneDuiHuanShangRen : public CreatureScript

{

public:

	Gossip_OnNpcOneDuiHuanShangRen() :CreatureScript("Gossip_OnNpcOneDuiHuanShangRen") {}




	bool OnGossipHello(Player* player, Creature* creature)

	{
		ClearGossipMenuFor(player);
		exitems.clear();
		haves = 0;
		exflag = {};
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t训练营传说兑换", GOSSIP_SENDER_MAIN, 11000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t先锋传说兑换", GOSSIP_SENDER_MAIN, 12000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t卫士传说兑换", GOSSIP_SENDER_MAIN, 13000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t卫将传说兑换", GOSSIP_SENDER_MAIN, 14000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t政官传说兑换", GOSSIP_SENDER_MAIN, 15000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t玉将传说兑换", GOSSIP_SENDER_MAIN, 16000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t龙王传说兑换", GOSSIP_SENDER_MAIN, 17000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t名人传说兑换", GOSSIP_SENDER_MAIN, 18000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t圣龙传说兑换", GOSSIP_SENDER_MAIN, 19000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t王座传说兑换", GOSSIP_SENDER_MAIN, 20000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t王将传说兑换", GOSSIP_SENDER_MAIN, 21000);
		

		SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;

	}
	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) {

		ClearGossipMenuFor(player);
		WorldSession* session = player->GetSession();
		if (sender == GOSSIP_SENDER_MAIN) {
			/*switch (action) {
			case 11000:
				AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t传说首饰", 7, action+1);
				SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
				return true;
			case 12000:
				AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t传说首饰", 7, action+1);
				AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t传说武器", 7, action + 2);
				AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t传说护甲", 7, action + 3);
				SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
				return true;
			default:
				break;
			}*/
			addExGoosipItem(player, session, action+1);
			SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			return true;
		}
		if (sender == 2) {
			addExGoosipItemCount(player, action,session);
			AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t预览", 6, action);
			AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t确认兑换", 4, action);
			AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t返回", 5, action);
			SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			return true;
		}

		if (sender == 4 ) {
			bool flag_local = false;
			if (exflag.size() > 0) {
				for (auto iter = exflag.begin();iter != exflag.end();++iter) {
					if (iter->second)
					{
						flag_local = true;
					}
				}
			}
			else
			{
				flag_local = true;
			}
			if (flag_local) {

				ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【兑换公告】|r材料不足！");
			}
			else
			{
				for (auto iter = exitems.begin(); iter != exitems.end(); iter++)
				{
					if (iter->first == 710001) {
						player->ModifyUSERJF(-int32(iter->second));
					
					}
					else {
						player->DestroyItemCount(iter->first, iter->second, true);
					}
				}
				player->AddItem(action, 1);
			}
			exflag = {};
			exitems = {};
		}
		if (sender==5) {
			OnGossipHello(player,creature);
			return true;
		}
		if (sender == 6)

		{
			string outputstr = "|cFF009933【兑换公告】|r 装备预览 " + sT->GetItemLink(action, session);
			////string ss = "|cFF009933【强化公告】|r ";
			////const char *buff = ss.c_str();
			const char *buffer = outputstr.c_str();
			ChatHandler(player->GetSession()).SendSysMessage(buffer);
			OnGossipSelect(player,creature,2, action);
			return true;
		}

		CloseGossipMenuFor(player);
		return true;
	}
	//classid 标注装备类型，对应到item_class。1-首饰，2-武器，3-护甲
	//flag_class 标注为哪个阶级的装备，对应为q_class
	void addExGoosipItem(Player* player,WorldSession* session,uint32 action ) {
		uint32 flag_class = 0;
		uint32 classid = 0;
		ItemExchangeContainer const* itemexchange = sObjectMgr->GetItemExchangeStore();
		
		if (itemexchange) {
			for (int i = 1;i < 4;i++) {
				switch (action-i)
				{
				case 11000:
					flag_class = 1;
					break;
				case 12000:
					flag_class = 2;
					break;
				case 13000:
					flag_class = 3;
					break;
				case 14000:
					flag_class = 4;
					break;
				case 15000:
					flag_class = 5;
					break;
				case 16000:
					flag_class = 6;
					break;
				case 17000:
					flag_class = 7;
					break;
				case 18000:
					flag_class = 8;
					break;
				case 19000:
					flag_class = 9;
					break;
				case 20000:
					flag_class = 10;
					break;
				case 21000:
					flag_class = 11;
					break;
				default:
					break;
				}
				if (flag_class>0) {
					classid = i;
					break;
				}
			}
			

			for (ItemExchangeContainer::const_iterator iter = itemexchange->begin();iter != itemexchange->end();++iter) {

				if (iter->second.item_q_class==flag_class && iter->second.item_class==classid) {
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t兑换" + sT->GetItemLink(iter->second.entry, session), 2, iter->second.entry);
				}
			}
			
		}
		else
		{
			ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【兑换公告】|r加载失败。");
		}
		
	}
	void addExGoosipItemCount(Player* player, uint32 entry, WorldSession* session) {
		const ItemExchange* itemexchange = sObjectMgr->GetItemExchange(entry);
		if (itemexchange) {

				if (itemexchange->item_1_couunt > 0) {
					if (itemexchange->item_1 == 710001) {
						haves = player->GetUSERJF();
					}
					else
					{
						haves = player->GetItemCount(itemexchange->item_1);
					}
					if (haves >= itemexchange->item_1_couunt) {
						exflag[itemexchange->item_1] = false;
						exitems[itemexchange->item_1] = itemexchange->item_1_couunt;
					}
					else {
						exflag[itemexchange->item_1] = true;
					}
			
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t需要" + sT->GetItemLink(itemexchange->item_1, session) + "  " + "|cFF0000FF " + to_string(haves).c_str() + "/" + to_string(itemexchange->item_1_couunt).c_str() + "|r", 2, entry);
			}
			if (itemexchange->item_2_couunt > 0) {
				if (itemexchange->item_2 == 710001) {
					haves = player->GetUSERJF();
				}
				else
				{
					haves = player->GetItemCount(itemexchange->item_2);
				}
				if (haves >= itemexchange->item_2_couunt) {
					exflag[itemexchange->item_2] = false;
					exitems[itemexchange->item_2] = itemexchange->item_2_couunt;
				}
				else {
					exflag[itemexchange->item_2] = true;
				}

				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t需要" + sT->GetItemLink(itemexchange->item_2, session) + "  " + "|cFF0000FF " + to_string(haves).c_str() + "/" + to_string(itemexchange->item_2_couunt).c_str() + "|r", 2, entry);
			}
			if (itemexchange->item_3_couunt > 0) {
				if (itemexchange->item_3 == 710001) {
					haves = player->GetUSERJF();
				}
				else
				{
					haves = player->GetItemCount(itemexchange->item_3);
				}
				if (haves >= itemexchange->item_3_couunt) {
					exflag[itemexchange->item_3] = false;
					exitems[itemexchange->item_3] = itemexchange->item_3_couunt;
				}
				else {
					exflag[itemexchange->item_3] = true;
				}
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t需要" + sT->GetItemLink(itemexchange->item_3, session) + "  " + "|cFF0000FF " + to_string(haves).c_str() + "/" + to_string(itemexchange->item_3_couunt).c_str() + "|r", 2, entry);
			}
		}
		else
		{
			ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【兑换公告】|r加载失败。");
		}
	}
private:
	std::unordered_map<uint32, uint32> exitems = {};
	std::unordered_map<uint32, bool> exflag = {};
	uint32 haves = 0;
};



class Gossip_OnItemLuShi : public ItemScript

{
public:
	Gossip_OnItemLuShi() :ItemScript("Gossip_OnItemLuShi") {}
	bool OnUse(Player* player, Item* item, SpellCastTargets const& selectItem) {
		selitem = selectItem;
		player->CastStop();
		OnGossipHello(player,item, selectItem);
		return true;
	}
	bool OnGossipHello(Player* player, Item* item, SpellCastTargets const& selectItem) {
		uint32 ontimes = player->GetTotalPlayedTime();
		uint32 ondays = round(ontimes / (24 * 3600));
		uint32 onhours = round((ontimes - (ondays * 24 * 3600)) / 3600);
		uint32 onmins = round((ontimes - (ondays * 24 * 3600 + onhours * 3600)) / 60);
		string onlinetimes = "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t在线总时间：|cFF000080"+to_string(ondays)+"天"+ to_string(onhours)+"小时"+ to_string(onmins)+"分钟|r";
		const char *buffer = onlinetimes.c_str();

		ClearGossipMenuFor(player);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t传回|cFFF0F000→|r位置", GOSSIP_SENDER_MAIN, 1010);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t记录|cFFF0F000←|r位置", GOSSIP_SENDER_MAIN, 1020);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t|cFFB22222地图传送|r", GOSSIP_SENDER_MAIN, 1030);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t修理装备", GOSSIP_SENDER_MAIN, 1040);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t随身银行", GOSSIP_SENDER_MAIN, 1050);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t随身拍卖行", GOSSIP_SENDER_MAIN, 1060);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t随身邮箱", GOSSIP_SENDER_MAIN, 1070);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t积分查询", GOSSIP_SENDER_MAIN, 1100);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t强制脱离战斗", GOSSIP_SENDER_MAIN, 1080);
		AddGossipItemFor(player, 10,  buffer, GOSSIP_SENDER_MAIN, 1090);

		SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
		return true;
	}
	void OnGossipSelect(Player* player, Item* item, uint32 sender, uint32 action) {
		ClearGossipMenuFor(player);
		if (sender== GOSSIP_SENDER_MAIN) {
			switch (action)
			{
			case 1010:
				player->CastSpell(player,8690,true);
				player->RemoveSpellCooldown(8690,true);
				ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【传送公告】|r已经穿越回来了");
				break;
			case 1020:
			{
				WorldLocation loc(player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
				player->SetHomebind(loc, player->GetAreaId());
				ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【传送公告】|r已经记录当前位置");
				break;
			}
			case 1030:
			{uint32 flag = 2010;
			for (auto iter = map_gps_main.begin();iter != map_gps_main.end();++iter) {
				string str = "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t" + iter->first;
				string str_tel = "是否传送到 |cFFFFFF00" + iter->first + "|r ?";
				AddGossipItemFor(player, 10, str.c_str(), 2, flag, str_tel.c_str(), 0, false);
				flag++;
			}
			AddGossipItemFor(player, 10,"|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t返回主菜单", GOSSIP_SENDER_MAIN, 1090);
			SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
			return;
			}
			case 1040:
				player->DurabilityRepairAll(true, 1, false);
				ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【修理公告】|r装备修理完成");
				break;
			case 1050:
				player->GetSession()->SendShowBank(player->GetGUID());
				break;
			case 1060:
				player->GetSession()->SendAuctionHello(player->GetGUID());
				break;
			case 1070:
				player->GetSession()->SendShowMailBox(player->GetGUID());
				break;
			case 1080:
				if (!player->IsInCombat()) {
					ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【脱战公告】|r未在战斗状态！");
					break;
				}
				player->ClearInCombat();
				ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【脱战公告】|r你已经脱离战斗！");
				break;
			case 1090:
				OnGossipHello(player, item, selitem);
				return;
			case 1100: {

				string	str_login = "|cFF009933【查询公告】|r当前的积分剩余|cff00ffff" + to_string(player->GetUSERJF()) + "|r  ，累计总积分：|cff00ffff" + to_string(player->GetUserJfCount()) + "|r。";
				const char *buffer = str_login.c_str();
				ChatHandler(player->GetSession()).SendSysMessage(buffer);
				break;
			}

			default:
				break;
			}
			
		}
		
		switch (sender)
		{
		case 2:
			switch (action)
			{
			case 2010:
				PlayerTel(player,map_gps_main["铁炉堡"][0],map_gps_main["铁炉堡"][1],map_gps_main["铁炉堡"][2], map_gps_main["铁炉堡"][3],map_gps_main["铁炉堡"][4]);
				break;
			case 2011:
				PlayerTel(player, map_gps_main["幽暗城"][0], map_gps_main["幽暗城"][1], map_gps_main["幽暗城"][2], map_gps_main["幽暗城"][3], map_gps_main["幽暗城"][4]);

				break;
			case 2012:
				PlayerTel(player, map_gps_main["暴风城"][0], map_gps_main["暴风城"][1], map_gps_main["暴风城"][2], map_gps_main["暴风城"][3], map_gps_main["暴风城"][4]);
				
				break;
			case 2013:
				PlayerTel(player, map_gps_main["雷霆崖"][0], map_gps_main["雷霆崖"][1], map_gps_main["雷霆崖"][2], map_gps_main["雷霆崖"][3], map_gps_main["雷霆崖"][4]);
				
				break;
			case 2014:
				PlayerTel(player, map_gps_main["奥格瑞玛"][0], map_gps_main["奥格瑞玛"][1], map_gps_main["奥格瑞玛"][2], map_gps_main["奥格瑞玛"][3], map_gps_main["奥格瑞玛"][4]);
				break;
			case 2015:
				PlayerTel(player, map_gps_main["达纳苏斯"][0], map_gps_main["达纳苏斯"][1], map_gps_main["达纳苏斯"][2], map_gps_main["达纳苏斯"][3], map_gps_main["达纳苏斯"][4]);

				break;
			case 2016:
				PlayerTel(player, map_gps_main["埃索达"][0], map_gps_main["埃索达"][1], map_gps_main["埃索达"][2], map_gps_main["埃索达"][3], map_gps_main["埃索达"][4]);
				break;
			case 2017:
				PlayerTel(player, map_gps_main["银月城"][0], map_gps_main["银月城"][1], map_gps_main["银月城"][2], map_gps_main["银月城"][3], map_gps_main["银月城"][4]);
				break;
			case 2018:
				PlayerTel(player, map_gps_main["[诺森德]达拉然"][0], map_gps_main["[诺森德]达拉然"][1], map_gps_main["[诺森德]达拉然"][2], map_gps_main["[诺森德]达拉然"][3], map_gps_main["[诺森德]达拉然"][4]);
				break;
			case 2019:
				PlayerTel(player, map_gps_main["[中立]加基森"][0], map_gps_main["[中立]加基森"][1], map_gps_main["[中立]加基森"][2], map_gps_main["[中立]加基森"][3], map_gps_main["[中立]加基森"][4]);
				break;
			case 2020:
				PlayerTel(player, map_gps_main["[外域]沙塔斯"][0], map_gps_main["[外域]沙塔斯"][1], map_gps_main["[外域]沙塔斯"][2], map_gps_main["[外域]沙塔斯"][3], map_gps_main["[外域]沙塔斯"][4]);
				break;
			case 2021:
				PlayerTel(player, map_gps_main["[中立]藏宝海湾"][0], map_gps_main["[中立]藏宝海湾"][1], map_gps_main["[中立]藏宝海湾"][2], map_gps_main["[中立]藏宝海湾"][3], map_gps_main["[中立]藏宝海湾"][4]);
				break;
			case 2022:
				PlayerTel(player, map_gps_main["[中立]棘齿城"][0], map_gps_main["[中立]棘齿城"][1], map_gps_main["[中立]棘齿城"][2], map_gps_main["[中立]棘齿城"][3], map_gps_main["[中立]棘齿城"][4]);
				break;
			case 2023:
				PlayerTel(player, map_gps_main["[中立]广场"][0], map_gps_main["[中立]广场"][1], map_gps_main["[中立]广场"][2], map_gps_main["[中立]广场"][3], map_gps_main["[中立]广场"][4]);
				break;
			case 2024:
				PlayerTel(player, map_gps_main["[中立]沙漠赛道"][0], map_gps_main["[中立]沙漠赛道"][1], map_gps_main["[中立]沙漠赛道"][2], map_gps_main["[中立]沙漠赛道"][3], map_gps_main["[中立]沙漠赛道"][4]);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

		CloseGossipMenuFor(player);
		return;
	}
private:
	SpellCastTargets  selitem;
	std::unordered_map<string, vector<double>> map_gps_main = {
		{"铁炉堡",{ 0,-4900.47, -962.585, 501.455, 5.40538,TEAM_ALLIANCE }},
		{"暴风城",{ 0,-8842.09, 626.358, 94.0867, 3.61363,TEAM_ALLIANCE }},
		{"达纳苏斯",{ 1, 9869.91, 2493.58, 1315.88, 2.78897,TEAM_ALLIANCE } },
		{ "埃索达",{ 530, -3864.92, -11643.7, -137.644, 5.50862,TEAM_ALLIANCE } },
		{ "奥格瑞玛",{ 1, 1601.08, -4378.69, 9.9846, 2.14362,TEAM_HORDE } },
		{ "雷霆崖",{ 1, -1274.45, 71.8601, 128.159, 2.80623,TEAM_HORDE } },
		{ "幽暗城",{ 0, 1633.75, 240.167, -43.1034, 6.26128,TEAM_HORDE } },
		{ "银月城",{ 530, 9738.28, -7454.19, 13.5605, 0.043914,TEAM_HORDE } },
		{ "[诺森德]达拉然",{ 571, 5809.55, 503.975, 657.526, 2.38338,TEAM_NEUTRAL } },
		{ "[外域]沙塔斯",{ 530, -1910.84, 5571.70, -12.4279, 1.741771,TEAM_NEUTRAL } },
		{ "[中立]藏宝海湾",{ 0, -14281.9, 552.564, 8.90422, 0.860144,TEAM_NEUTRAL } },
		{ "[中立]棘齿城",{ 1,	-955.21875,-3678.92,8.29946,	0,TEAM_NEUTRAL } },
		{ "[中立]加基森",{ 1,	-7122.79834,-3704.82,14.0526,	0,TEAM_NEUTRAL } },
		{ "[中立]广场",{ 609,	2457.89,-5595.5,550.22,	1.41,TEAM_NEUTRAL } },
		{ "[中立]沙漠赛道",{ 1,-6202.16,-3901.68,-60.2858,0,TEAM_NEUTRAL } },
	};
	bool PlayerTel(Player* player, uint32 mapId,float x, float y, float z, float o) {
		if (player->IsInFlight())
		{
			player->GetMotionMaster()->MovementExpired();
			player->m_taxi.ClearTaxiDestinations();
		}
		if (player->TeleportTo(mapId, x, y, z, o)) {
			return true;
		}
		return false;
	}
	double round(double r)
	{
		return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
	}
};


class Gossip_OnNpcHeXinShuiJing : public CreatureScript

{

public:

	Gossip_OnNpcHeXinShuiJing() :CreatureScript("Gossip_OnNpcHeXinShuiJing") {}




	bool OnGossipHello(Player* player, Creature* creature)

	{
		uint32 ontimes = player->GetTotalPlayedTime();
		uint32 ondays = round(ontimes / (24 * 3600));
		uint32 onhours = round((ontimes - (ondays * 24 * 3600)) / 3600);
		uint32 onmins = round((ontimes - (ondays * 24 * 3600 + onhours * 3600)) / 60);
		string onlinetimes = "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t在线总时间：|cFF000080" + to_string(ondays) + "天" + to_string(onhours) + "小时" + to_string(onmins) + "分钟|r";
		const char *buffer = onlinetimes.c_str();
		c_creature = creature;

		ClearGossipMenuFor(player);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t|cFF006400勇者副本★|r", GOSSIP_SENDER_MAIN, 1010);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t|cFF4B0082英雄副本★|r", GOSSIP_SENDER_MAIN, 1020);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t|cFFB22222团队副本★|r", GOSSIP_SENDER_MAIN, 1030);
		
		AddGossipItemFor(player, 10, buffer, GOSSIP_SENDER_MAIN, 1090);
		SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;

	}
	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) {

		ClearGossipMenuFor(player);

		if (sender == GOSSIP_SENDER_MAIN) {
			switch (action)
			{
			case 1010:
			{uint32 flag = 2010;
			for (auto iter = map_yz_main.begin();iter != map_yz_main.end();++iter) {
				string str = "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t" + iter->first;
				string str_tel = "是否传送到 |cFFFFFF00" + iter->first + "|r ?";
				AddGossipItemFor(player, 10, str.c_str(), 2, flag, str_tel.c_str(), 0, false);
				flag += 10;
			}
			AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t返回主菜单", GOSSIP_SENDER_MAIN, 1090);
			SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			return true;
			}
			case 1020:
			{uint32 flag = 3010;
			for (auto iter = map_yx_main.begin();iter != map_yx_main.end();++iter) {
				string str = "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t" + iter->first;
				string str_tel = "是否传送到 |cFFFFFF00" + iter->first + "|r ?";
				AddGossipItemFor(player, 10, str.c_str(), 3, flag, str_tel.c_str(), 0, false);
				flag+=10;
			}
			AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t返回主菜单", GOSSIP_SENDER_MAIN, 1090);
			SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			return true;
			}
				break;
			case 1030:
			{uint32 flag = 4010;
			for (auto iter = map_td_main.begin();iter != map_td_main.end();++iter) {
				string str = "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t" + iter->first;
				string str_tel = "是否传送到 |cFFFFFF00" + iter->first + "|r ?";
				AddGossipItemFor(player, 10, str.c_str(), 4, flag, str_tel.c_str(), 0, false);
				flag += 10;
			}
			AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:15:15:-20:-3|t返回主菜单", GOSSIP_SENDER_MAIN, 1090);
			SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			return true;
			}
				break;
			case 1090:
				OnGossipHello(player, creature);
				return true;
			default:
				break;
			}

		}
		
		switch (sender)
		{
		case 2 :
		{
			uint32 ff = ((action % 2000) / 10) - 1;
			uint32 index = 0;
			for (auto iter = map_yz_main.begin();iter != map_yz_main.end();++iter) {
				if (index == ff) {
					PlayerTel(player, iter->first, map_yz_main);
					break;
				}
				index++;
			}
			break;
		}
		case 3:
		{
			uint32 ff = ((action % 3000) / 10) - 1;
			uint32 index = 0;
			for (auto iter = map_yx_main.begin();iter != map_yx_main.end();++iter) {
				if (index == ff) {
					PlayerTel(player, iter->first, map_yx_main);
					break;
				}
				index++;
			}
			break;
		}
		case 4:
		{
			uint32 ff = ((action % 4000) / 10) - 1;
			uint32 index = 0;
			for (auto iter = map_td_main.begin();iter != map_td_main.end();++iter) {
				if (index == ff) {
					PlayerTel(player, iter->first, map_td_main);
					break;
				}
				index++;
			}
			break;
		}
		default:
			break;
		}
		CloseGossipMenuFor(player);
		return true;
	}
private:
	Creature* c_creature;
	std::unordered_map<string, vector<double>> map_yz_main = {
		{ "怒焰裂谷",{ 1, 1811.78, -4410.5, -18.4704, 5.20165,TEAM_HORDE } },
		{ "死亡矿井",{ 0, -11209.6, 1666.54, 24.6974, 1.42053,TEAM_NEUTRAL } },
		{ "哀嚎洞穴",{ 1, -731.607, -2218.39, 17.0281, 2.78486,TEAM_NEUTRAL } },
		{ "影牙城堡",{ 0, -234.675, 1561.63, 76.8921, 1.24031,TEAM_NEUTRAL } },
		{ "黑暗深渊",{ 1, 4249.99, 740.102, -25.671, 1.34062,TEAM_NEUTRAL } },
		{ "暴风监狱",{ 0, -8799.15, 832.718, 97.6348, 6.04085,TEAM_ALLIANCE }  },
		{ "剃刀沼泽",{ 1, -4470.28, -1677.77, 81.3925, 1.16302,TEAM_NEUTRAL } },
		{ "诺莫瑞根",{ 0, -5163.54, 925.423, 257.181, 1.57423,TEAM_NEUTRAL } },
		{ "血色修道院",{ 0, 2873.15, -764.523, 160.332, 5.10447,TEAM_NEUTRAL } },
		{ "剃刀高地",{ 1, -4657.3, -2519.35, 81.0529, 4.54808,TEAM_NEUTRAL } },
		{ "奥达曼",{ 0, -6071.37, -2955.16, 209.782, 0.015708,TEAM_NEUTRAL } },
		{ "玛拉顿",{ 1, -1421.42, 2907.83, 137.415, 1.70718,TEAM_NEUTRAL } },
		{ "沉没的神庙",{ 0, -10177.9, -3994.9, -111.239, 6.01885,TEAM_NEUTRAL } },
		{ "祖尔法拉克",{ 1, -6801.19, -2893.02, 9.00388, 0.158639,TEAM_NEUTRAL } },
		{ "通灵学院",{ 0, 1269.64, -2556.21, 93.6088, 0.620623,TEAM_NEUTRAL } },
		{ "黑石深渊",{ 0, -7179.34, -921.212, 165.821, 5.09599,TEAM_NEUTRAL } },
		{ "黑石塔",{ 0, -7527.05, -1226.77, 285.732, 5.29626,TEAM_NEUTRAL } },
		{ "厄运之槌",{ 1, -3520.14, 1119.38, 161.025, 4.70454,TEAM_NEUTRAL } },
	};

	std::unordered_map<string, vector<double>> map_yx_main = {
		{ "斯坦索姆",{ 0, 3352.92, -3379.03, 144.782, 6.25978,TEAM_NEUTRAL } },
		{ "奥金顿",{ 530, -3324.49, 4943.45, -101.239, 4.63901,TEAM_NEUTRAL } },
		{ "地狱火堡垒",{ 530, -347.29, 3089.82, 21.394, 5.68114,TEAM_NEUTRAL } },
		{ "时光之穴",{ 1, -8369.65, -4253.11, -204.272, -2.70526,TEAM_NEUTRAL } },
		{ "魔导师平台",{ 530, 12884.6, -7317.69, 65.5023, 4.799,TEAM_NEUTRAL } },
		{ "风暴要塞",{ 530, 3100.48, 1536.49, 190.3, 4.62226,TEAM_NEUTRAL } },
		{ "盘牙水库",{ 530, 738.865, 6865.77, -69.4659, 6.27655,TEAM_NEUTRAL } },
		{ "艾卓-尼鲁布",{ 571, 3707.86, 2150.23, 36.76, 3.22,TEAM_NEUTRAL } },
		{ "斯坦索姆的抉择",{ 1, -8756.39, -4440.68, -199.489, 4.66289,TEAM_NEUTRAL } },
		{ "冠军的试炼",{ 571, 8590.95, 791.792, 558.235, 3.13127,TEAM_NEUTRAL } },
		{ "达克萨隆堡垒",{ 571, 4765.59, -2038.24, 229.363, 0.887627,TEAM_NEUTRAL } },
		{ "古达克",{ 571, 6722.44, -4640.67, 450.632, 3.91123,TEAM_NEUTRAL } },
		{ "冰冠城塞",{ 571, 5643.16, 2028.81, 798.274, 4.60242,TEAM_NEUTRAL } },
		{ "魔枢",{ 571, 3782.89, 6965.23, 105.088, 6.14194,TEAM_NEUTRAL } },
		{ "紫罗兰监狱",{ 571, 5693.08, 502.588, 652.672, 4.0229,TEAM_NEUTRAL } },
		{ "闪电大厅",{ 571, 9136.52, -1311.81, 1066.29, 5.19113,TEAM_NEUTRAL } },
		{ "石头大厅",{ 571, 8922.12, -1009.16, 1039.56, 1.57044,TEAM_NEUTRAL } },
		{ "乌特加德城堡",{ 571, 1203.41, -4868.59, 41.2486, 0.283237,TEAM_NEUTRAL } },
		{ "乌特加德之巅",{ 571, 1267.24, -4857.3, 215.764, 3.22768,TEAM_NEUTRAL } },
	};

	std::unordered_map<string, vector<double>> map_td_main = {
		{ "安其拉废墟",{ 1, -8409.82, 1499.06, 27.7179, 2.51868,TEAM_NEUTRAL } },
		{ "熔火之心",{ 230, 1126.64, -459.94, -102.535, 3.46095,TEAM_NEUTRAL } },
		{ "黑翼之巢",{ 229, 152.451, -474.881, 116.84, 0.001073,TEAM_NEUTRAL } },
		{ "安其拉神殿",{ 1, -8240.09, 1991.32, 129.072, 0.941603,TEAM_NEUTRAL } },
		{ "祖尔格拉布",{ 0, -11916.7, -1215.72, 92.289, 4.72454,TEAM_NEUTRAL } },
		{ "奥妮克希亚的巢穴",{ 1, -4708.27, -3727.64, 54.5589, 3.72786,TEAM_NEUTRAL } },
		{ "海加尔山之巅",{ 1, -8177.89, -4181.23, -167.552, 0.913338,TEAM_NEUTRAL } },
		{ "格鲁尔的巢穴",{ 530, 3530.06, 5104.08, 3.50861, 5.51117,TEAM_NEUTRAL } },
		{ "玛瑟里顿的巢穴",{ 530, -336.411, 3130.46, -102.928, 5.20322,TEAM_NEUTRAL } },
		{ "卡拉赞",{ 0, -11118.9, -2010.33, 47.0819, 0.649895,TEAM_NEUTRAL } },
		{ "黑暗神庙",{ 530, -3649.92, 317.469, 35.2827, 2.94285,TEAM_NEUTRAL } },
		{ "毒蛇神殿",{ 530, 797.855, 6865.77, -65.4165, 0.005938,TEAM_NEUTRAL } },
		{ "祖阿曼",{ 530, 6851.78, -7972.57, 179.242, 4.64691,TEAM_NEUTRAL } },
		{ "风暴要塞",{ 530, 3088.49, 1381.57, 184.863, 4.61973,TEAM_NEUTRAL } },
		{ "太阳井高地",{ 530, 12574.1, -6774.81, 15.0904, 3.13788,TEAM_NEUTRAL } },
		{ "纳克萨玛斯",{ 571, 3668.72, -1262.46, 243.622, 4.785,TEAM_NEUTRAL } },
		{ "永恒之眼",{ 571, 3784.17, 7028.84, 161.258, 5.79993,TEAM_NEUTRAL } },
		{ "黑曜石圣殿",{ 571, 3472.43, 264.923, -120.146, 3.27923,TEAM_NEUTRAL } },
		{ "奥杜尔",{ 571, 9222.88, -1113.59, 1216.12, 6.27549,TEAM_NEUTRAL } },
		{ "阿尔卡冯的宝库",{ 571, 5453.72, 2840.79, 421.28, 0,TEAM_NEUTRAL } },
		{ "冰冠堡垒",{ 571, 5855.22, 2102.03, 635.991, 3.57899,TEAM_NEUTRAL } },
		{ "十字军的试炼",{ 571, 8515.61, 714.153, 558.248, 1.57753,TEAM_NEUTRAL } },
	};

	bool PlayerTel(Player* player, string mapname, std::unordered_map<string, vector<double>> list) {
		uint32 mapId = list[mapname][0];
		float x = list[mapname][1];
			float y = list[mapname][2];
			float z = list[mapname][3];
			float o	= list[mapname][4];

		if (player->IsInFlight())
		{
			player->GetMotionMaster()->MovementExpired();
			player->m_taxi.ClearTaxiDestinations();
		}
		if (player->TeleportTo(mapId, x, y, z, o)) {
			return true;
		}
		return false;
	}
};


class PlayerOnline : public PlayerScript

{
public:
	PlayerOnline() :PlayerScript("PlayerOnline") {}
	void OnLogin(Player* player) { 
		uint32 lev = player->GetVipNowLevel();
		string str_login;
		const char *buffer;
		if (lev>8) {
			str_login = "|cFF009933【公告】|r欢迎：|cffff8000大会员|r  |cff0000ff" +player->GetName() +"|r 进入游戏";
			buffer = str_login.c_str();
			ChatHandler(player->GetSession()).SendGlobalSysMessage(buffer);
			return;
		}
		if (player->HasAtLoginFlag(AT_LOGIN_FIRST)) {
			str_login = "|cFF009933【公告】|r热烈欢迎：|cff00ffff新人|r  |cff0000ff" + player->GetName() + "|r 进入游戏";
			buffer = str_login.c_str();
			ChatHandler(player->GetSession()).SendGlobalSysMessage(buffer);
			return;
		}
		str_login = "|cFF009933【公告】|r欢迎：|cff0000ff" + player->GetName() + "|r 回到游戏";
		buffer = str_login.c_str();
		ChatHandler(player->GetSession()).SendGlobalSysMessage(buffer);

	}

	// Called when a player logs out.
	//void OnLogout(Player* player) { 
	//}
};


class world_chat : public CommandScript
{
public:
	world_chat() : CommandScript("world_chat") { }

	std::vector<ChatCommand> GetCommands() const override
	{
		/*static std::vector<ChatCommand> worlchatCommandTable =
		{
			{ "",               SEC_PLAYER,      false, &HandleChatCommand,               "" }
		};*/

		static std::vector<ChatCommand> commandTable =
		{
			{ "sj",             SEC_PLAYER,      true, &HandleChatCommand,                ""},
		};
		return commandTable;
	}

	static bool HandleChatCommand(ChatHandler* handler, char const* args)
	{
		if (!*args)
			return false;
		if (handler->GetSession()->GetPlayer()->GetUSERJF() < 100)
		{
			handler->GetSession()->GetPlayer()->GetSession()->SendNotification("【聊天公告】积分少于100无法使用世界频道");
			return false;
		}
		std::string str = "|cff00ff00[世界频道]|r[|cffff0000";//"|cfff0ff00[世界频道][|r"
		str += handler->GetSession()->GetPlayerName();
		str += "|r]:|cffffffff";
		str += args;
		str += "|r";
		sWorld->SendServerMessage(SERVER_MSG_STRING, str.c_str(),0);
		handler->GetSession()->GetPlayer()->ModifyUSERJF(int32(-100));
		//handler->GetSession()->GetPlayer()->GetSession()->SendNotification("");//世界频道广播已经发送,扣取费用一金币!
		return true;
	}
};


class Gossip_OnNpcHuiShou : public CreatureScript

{

public:

	Gossip_OnNpcHuiShou() :CreatureScript("Gossip_OnNpcHuiShou") {}




	bool OnGossipHello(Player* player, Creature* creature)

	{
		l_give.clear();
		uint32 ontimes = player->GetTotalPlayedTime();
		uint32 ondays = round(ontimes / (24 * 3600));
		uint32 onhours = round((ontimes - (ondays * 24 * 3600)) / 3600);
		uint32 onmins = round((ontimes - (ondays * 24 * 3600 + onhours * 3600)) / 60);
		string onlinetimes = "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t在线总时间：|cFF000080" + to_string(ondays) + "天" + to_string(onhours) + "小时" + to_string(onmins) + "分钟|r";
		const char *buffer = onlinetimes.c_str();

		ClearGossipMenuFor(player);

		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t回收优秀级装备", GOSSIP_SENDER_MAIN, 1000);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t回收精良级装备", GOSSIP_SENDER_MAIN, 1010);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t回收史诗级装备", GOSSIP_SENDER_MAIN, 1020);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t回收传说级装备", GOSSIP_SENDER_MAIN, 1030);
		AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:35:35:-20:1|t回收极品级装备", GOSSIP_SENDER_MAIN, 1040);
		AddGossipItemFor(player, 10, buffer, GOSSIP_SENDER_MAIN, 1090);
		SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;

	}
	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) {

		ClearGossipMenuFor(player);

		if (sender == GOSSIP_SENDER_MAIN) {
			switch (action)
			{
			case 1000:
				for (auto iter = l_pinji.begin();iter != l_pinji.end();++iter) {
					HuiShou(player,iter->first,1);
				}
				break;
			case 1010:
				for (auto iter = l_pinji.begin();iter != l_pinji.end();++iter) {
					HuiShou(player, iter->first, 2);
				}
				break;
			case 1020:
				for (auto iter = l_pinji.begin();iter != l_pinji.end();++iter) {
					HuiShou(player, iter->first, 3);
				}
				break;
			case 1030:
				for (auto iter = l_pinji.begin();iter != l_pinji.end();++iter) {
					HuiShou(player, iter->first, 4);
				}
				break;
			case 1040:
				for (auto iter = l_pinji.begin();iter != l_pinji.end();++iter) {
					HuiShou(player, iter->first, 5);
				}
				break;
			case 1090:
				OnGossipHello(player, creature);
				return true;
			default:
				break;
			}

		}

		
		CloseGossipMenuFor(player);
		return true;
	}
private:
	std::unordered_map<int, string> l_pinji = {
		{1,"『先锋"},
		{2,"『卫士"},
		{3,"『卫将"},
		{4,"『政官"},
		{5,"『玉将"},
		{6,"『龙王 "},
		{7,"『名人"},
		{8,"『圣龙 "},
		{9,"『王座"},
		{10,"『王将"}
	};
	std::unordered_map<int, string> l_pinjie = {
		{ 1,"（优秀）" },
		{ 2,"（精良）" },
		{ 3,"（史诗）" },
		{ 4,"（传说）" },
		{ 5,"（极品）" },
	};

	std::unordered_map<uint32, uint32> l_give = {};

	void HuiShou(Player* player,uint32 pinji,uint32 pinjie) {
		string str_pinji = l_pinji[pinji];
		string str_pinjie = l_pinjie[pinjie];

		for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
		{
			if (Bag* bag = player->GetBagByPos(i))
			{
				for (uint32 j = 0; j < bag->GetBagSize(); j++)
				{
					if (Item* item = bag->GetItemByPos(j))
					{
						const ItemTemplate* item_tem = item->GetTemplate();
						if (findstr(item_tem->Name1,str_pinji)&& !findstr(item_tem->Name1,"之传说")) {
							if (findstr(item_tem->Name1, str_pinjie)) {
								fullgive(pinji,pinjie);
								player->DestroyItem(i, j, true);
							}
						}
					}
				}
			}
		}
		
		for (auto iter = l_give.begin();iter != l_give.end();++iter) {
			if (iter->first==710001) {
				player->ModifyUSERJF(iter->second);
			}
			else {
				player->AddItem(iter->first, iter->second);
			}
		}
		l_give.clear();
	}

	void fullgive(uint32 pinji,uint32 pinjie) {
		const ItemHuiShouTemplate* ihst = sObjectMgr->GetItemHuiShouTemplate(pinji, pinjie);
		if (ihst->lootitem_1_count!=0 && ihst->lootitem_1!=0) {
			if (l_give.find(ihst->lootitem_1)!=l_give.end()) {
				l_give[ihst->lootitem_1] += ihst->lootitem_1_count;
			}
			else {
				l_give[ihst->lootitem_1] = ihst->lootitem_1_count;
			}
			
		}
		if (ihst->lootitem_2_count != 0 && ihst->lootitem_2 != 0) {
			if (l_give.find(ihst->lootitem_2) != l_give.end()) {
				l_give[ihst->lootitem_2] += ihst->lootitem_2_count;
			}
			else {
				l_give[ihst->lootitem_2] = ihst->lootitem_2_count;
			}
		}
		if (ihst->lootitem_3_count != 0 && ihst->lootitem_3 != 0) {
			if (l_give.find(ihst->lootitem_3) != l_give.end()) {
				l_give[ihst->lootitem_3] += ihst->lootitem_3_count;
			}
			else {
				l_give[ihst->lootitem_3] = ihst->lootitem_3_count;
			}
		}
		if (ihst->lootitem_4_count != 0 && ihst->lootitem_4 != 0) {
			if (l_give.find(ihst->lootitem_1) != l_give.end()) {
				l_give[ihst->lootitem_4] += ihst->lootitem_4_count;
			}
			else {
				l_give[ihst->lootitem_4] = ihst->lootitem_4_count;
			}
		}

	}

	void splitWord(const string & word, vector<string> & characters)
	{
		int num = word.size();
		int i = 0;
		while (i < num)
		{
			int size = 1;
			if (word[i] & 0x80)
			{
				char temp = word[i];
				temp <<= 1;
				do {
					temp <<= 1;
					++size;
				} while (temp & 0x80);
			}
			string subWord;
			subWord = word.substr(i, size);
			characters.push_back(subWord);
			i += size;
		}
	}

	bool findstr(string str, string s_str) {
		vector<string> vstr = {};
		splitWord(str, vstr);
		string ss;
		for (int i = 0;i < vstr.size();i++) {
			ss = "";
			for (int j = 0;j < s_str.length() / 3;j++)
			{
				if (i + j> vstr.size() - 1) {
					break;
				}
				ss += vstr[i + j];
			}
			if (s_str == ss) {
				return true;
			}
		}
		return false;
	}
};


enum ZidingyiEvents
{
	EVENT_SPELL_1 = 1,
	EVENT_SPELL_2,
	EVENT_SPELL_3,
	EVENT_SPELL_SOUL_FLAY,
	EVENT_SPELL_BERSERK,
};

class boss_my : public CreatureScript
{
public:
	boss_my() : CreatureScript("boss_my") { }

	struct boss_myAI : public ScriptedAI
	{
		boss_myAI(Creature* pCreature) : ScriptedAI(pCreature)
		{
			pInstance = pCreature->GetInstanceScript();
		}

		InstanceScript* pInstance;
		EventMap events;
		void Reset()
		{
			events.Reset();

		}

		void EnterCombat(Unit* who)
		{
			events.Reset();

			if (me->GetEntry() <= 98005)
			{
				me->CastSpell(me, 934001, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
			}
			else if (me->GetEntry() > 98005 && me->GetEntry() <= 98010)
			{
				me->CastSpell(me, 934002, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
				events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
			}
			else if (me->GetEntry() > 98010 && me->GetEntry() <= 98015)
			{
				me->CastSpell(me, 934003, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
				events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
				events.ScheduleEvent(EVENT_SPELL_3, urand(18000, 22000));
			}
			else if (me->GetEntry() > 98015 && me->GetEntry() <= 98020)
			{
				me->CastSpell(me, 934004, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
				events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
				events.ScheduleEvent(EVENT_SPELL_3, urand(18000, 22000));
			}
			else if (me->GetEntry() > 98020 && me->GetEntry() <= 98025)
			{
				me->CastSpell(me, 934005, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
				events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
				events.ScheduleEvent(EVENT_SPELL_3, urand(18000, 22000));
			}
			else if (me->GetEntry() > 98025 && me->GetEntry() <= 98030)
			{
				me->CastSpell(me, 934006, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
				events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
				events.ScheduleEvent(EVENT_SPELL_3, urand(18000, 22000));
			}
			else if (me->GetEntry() > 98030 && me->GetEntry() <= 98035)
			{
				me->CastSpell(me, 934007, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
				events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
				events.ScheduleEvent(EVENT_SPELL_3, urand(18000, 22000));
			}
			else if (me->GetEntry() > 98035 && me->GetEntry() <= 98040)
			{
				me->CastSpell(me, 934008, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
				events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
				events.ScheduleEvent(EVENT_SPELL_3, urand(18000, 22000));
			}
			else if (me->GetEntry() > 98040 && me->GetEntry() <= 98045)
			{
				me->CastSpell(me, 934009, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
				events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
				events.ScheduleEvent(EVENT_SPELL_3, urand(18000, 22000));
			}
			else if (me->GetEntry() > 98045)
			{
				me->CastSpell(me, 934010, true);
				events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
				events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
				events.ScheduleEvent(EVENT_SPELL_3, urand(18000, 22000));
			}

		}

		//void JustDied(Unit* killer)
		//{
		//	uint32 a = urand(1, 100);
		//	if (a >= 95)
		//	{
		//		//me->SummonCreature(70004, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 180);
		//		me->CastSpell((Unit*)NULL, 938001, true);
		//		char buff[2048];
		//		sprintf(buff, "|CFF00FF00【隐藏商人】:|r|cffffffff|Hplayer:%s|h[%s]|h|r将|cffffffff[%s]|r击杀后,隐藏商人出现了~|r", killer->GetName(), killer->GetName(), me->GetName());
		//		sWorld->SendServerMessage(SERVER_MSG_STRING, buff);
		//	}
		//	//sLog->outString("JustDied  (%u)", a);
		//}

		//void InitializeAI()
		//{
		//	//Talk(SAY_ENTER);
		//	ScriptedAI::InitializeAI();

		//	if (Unit* medivh = ObjectAccessor::GetUnit(*me, pInstance->GetData64(10)))
		//	{
		//		me->SetHomePosition(medivh->GetPositionX() + 14.0f*cos(medivh->GetAngle(me)), medivh->GetPositionY() + 14.0f*sin(medivh->GetAngle(me)), medivh->GetPositionZ(), me->GetAngle(medivh));
		//		me->GetMotionMaster()->MoveTargetedHome();
		//	}
		//}

		uint32 DoSpellCasta(uint32 BossSpell)
		{
			switch (BossSpell)
			{
			case 0:
				return 24573;//致死打击-释放
			case 1:
				return 75418;//震荡波-释放
			case 2:
				return 60899;//击飞-释放
			case 3:
				return 71001;//凋零-释放
			case 4:
				return 59192;//仇恨打击-释放
			case 5:
				return 66012;//寒冰打击-释放
			default:
				return 0;
			}
		}

		uint32 DoSpellCastb(uint32 BossSpell)
		{
			switch (BossSpell)
			{
			case 0:
				return 62910;//咪咪-释放
			case 1:
				return 71058;//冰霜吐息-释放
			case 2:
				return 75956;//黑暗吐息
			case 3:
				return 57544;//灰烬使者-释放
			case 4:
				return 22247;//镇压光环-释放
			default:
				return 0;
			}
		}

		uint32 DoSpellCastc(uint32 BossSpell)
		{
			switch (BossSpell)
			{
			case 0:
				return 935001;//升天-释放
			case 1:
				return 32309;//酸液箭释放
			case 2:
				return 935002;//巫妖王之怒-释放
			case 3:
				return 935001;//升天-释放
			default:
				return 0;
			}
		}

		void UpdateAI(uint32 diff)
		{
			if (!UpdateVictim())
				return;

			events.Update(diff);

			switch (events.GetEvent())
			{
			case 0:
				break;
			case EVENT_SPELL_1:
				me->CastSpell(me->GetVictim(), DoSpellCasta(urand(0, 5)), false);
				events.RepeatEvent(urand(10000, 12000));
				break;
			case EVENT_SPELL_2:
				me->CastSpell(me->GetVictim(), DoSpellCastb(urand(0, 4)), false);
				events.RepeatEvent(urand(14000, 16000));
				break;
			case EVENT_SPELL_3:
				me->CastSpell((Unit*)NULL, DoSpellCastc(urand(0, 3)), false);
				events.RepeatEvent(urand(18000, 22000));
				break;
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* pCreature) const
	{
		return new boss_myAI(pCreature);
	}
};


class boss_myworld : public CreatureScript
{
public:
	boss_myworld() : CreatureScript("boss_myworld") { }

	struct boss_myworldAI : public ScriptedAI
	{
		boss_myworldAI(Creature* pCreature) : ScriptedAI(pCreature)
		{
			pInstance = pCreature->GetInstanceScript();
		}

		InstanceScript* pInstance;
		EventMap events;
		void Reset()
		{
			events.Reset();
			me->CastSpell(me, 934014, true);
		}

		void EnterCombat(Unit* who)
		{
			events.Reset();
			me->CastSpell(me, 934014, true);
			me->CastSpell(me, 70842, true);
			events.ScheduleEvent(EVENT_SPELL_SOUL_FLAY, 0);
			//events.ScheduleEvent(EVENT_SPELL_1, urand(10000, 12000));
			events.ScheduleEvent(EVENT_SPELL_2, urand(14000, 16000));
			events.ScheduleEvent(EVENT_SPELL_3, urand(18000, 22000));
			events.ScheduleEvent(EVENT_SPELL_BERSERK, 900000);





		}

		void DamageTaken(Unit*, uint32& damage, DamageEffectType, SpellSchoolMask)
		{
			if (damage >= me->GetPower(POWER_MANA))
			{
				damage -= me->GetPower(POWER_MANA);
				me->SetPower(POWER_MANA, 0);
				me->RemoveAurasDueToSpell(70842);
			}
		}

		//void JustDied(Unit* killer)
		//{
		//	uint32 a = urand(1, 100);
		//	if (a >= 95)
		//	{
		//		//me->SummonCreature(70004, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 180);
		//		me->CastSpell((Unit*)NULL, 938001, true);
		//		char buff[2048];
		//		sprintf(buff, "|CFF00FF00【隐藏商人】:|r|cffffffff|Hplayer:%s|h[%s]|h|r将|cffffffff[%s]|r击杀后,隐藏商人出现了~|r", killer->GetName(), killer->GetName(), me->GetName());
		//		sWorld->SendServerMessage(SERVER_MSG_STRING, buff);
		//	}
		//	//sLog->outString("JustDied  (%u)", a);
		//}

		void JustRespawned()
		{
				string	str_login = "|cFF009933【公告】|r|cff00ffff世界BOSS|r  |cff0000ff" + me->GetName() + "|r 已经刷新，请传送到沙漠赛道进行攻打";
				const char *buffer = str_login.c_str();
				sWorld->SendServerMessage(SERVER_MSG_STRING, buffer, 0);
		}

		uint32 DoSpellCasta(uint32 BossSpell)
		{
			switch (BossSpell)
			{
			case 0:
				return 24573;//致死打击-释放
			case 1:
				return 75418;//震荡波-释放
			case 2:
				return 60899;//击飞-释放
			case 3:
				return 71001;//凋零-释放
			case 4:
				return 59192;//仇恨打击-释放
			case 5:
				return 66012;//寒冰打击-释放
			default:
				return 0;
			}
		}

		uint32 DoSpellCastb(uint32 BossSpell)
		{
			switch (BossSpell)
			{
			case 0:
				return 62910;//咪咪-释放
			case 1:
				return 62910;//冰霜吐息-释放
			case 2:
				return 62910;//黑暗吐息
			case 3:
				return 22247;//灰烬使者-释放
			case 4:
				return 22247;//镇压光环-释放
			default:
				return 0;
			}
		}

		uint32 DoSpellCastc(uint32 BossSpell)
		{
			switch (BossSpell)
			{
			case 0:
				return 935003;//升天-释放
			case 1:
				return 935003;//酸液箭释放
			case 2:
				return 935004;//巫妖王之怒-释放
			case 3:
				return 935004;//升天-释放
			default:
				return 0;
			}
		}

		void UpdateAI(uint32 diff)
		{
			if (!UpdateVictim())
				return;

			events.Update(diff);

			switch (events.GetEvent())
			{
			case 0:
				break;
			case EVENT_SPELL_1:
				me->CastSpell(me->GetVictim(), DoSpellCasta(urand(0, 5)), false);
				events.RepeatEvent(urand(10000, 12000));
				break;
			case EVENT_SPELL_2:
				me->CastSpell(me->GetVictim(), DoSpellCastb(urand(0, 4)), false);
				events.RepeatEvent(urand(14000, 16000));
				break;
			case EVENT_SPELL_3:
				me->CastSpell((Unit*)NULL, DoSpellCastc(urand(0, 3)), false);
				events.RepeatEvent(urand(18000, 22000));
				break;
			case EVENT_SPELL_SOUL_FLAY:
				me->CastSpell(me->GetVictim(), 940001, false);
				events.RepeatEvent(urand(4000, 5000));
				break;
			case EVENT_SPELL_BERSERK:
				me->CastSpell(me, 934013, true);
				break;
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* pCreature) const
	{
		return new boss_myworldAI(pCreature);
	}
};

void AddGossipOnNpcMoreScripts()
{
    new Gossip_OnNpcOneQuest();
	new Item_AddTalent();
	new Gossip_OnNpcOneXinShouShangRen();
	new Gossip_OnNpcOneDuiHuanShangRen();
	new Gossip_OnItemLuShi();
	new PlayerOnline();
	new world_chat();
	new Gossip_OnNpcHeXinShuiJing();
	new Gossip_OnNpcHuiShou();
	new boss_myworld();
	new boss_my();
}
