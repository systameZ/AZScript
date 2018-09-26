#include "ScriptPCH.h"

#include "Player.h"

#include "Chat.h"

#include "ObjectMgr.h"

#include "ScriptMgr.h"

#include "Item.h"

#include "Config.h"

#include "Pet.h"

#include "../../mod-transmog/src/Transmogrification.h"

#pragma execution_character_set("utf-8")
#define sT  sTransmogrification
enum INFO_SEND {
	ITEM_ENTRY_MIN = 200000,
	SEND_ACK_GOOSIP = 1,
	SEND_UP_ITEM=2

};


class Gossip_OnItemQh : public ItemScript

{
public:
	Gossip_OnItemQh() :ItemScript("Gossip_OnItemQh") {}
	bool OnUse(Player* player, Item* item, SpellCastTargets const& selectItem) {
		sel_item = selectItem;
		ItemTemplate const* upitem = sObjectMgr->GetItemTemplate(selectItem.GetItemTargetEntry() + 1000);
		if (selectItem.GetItemTargetEntry() >= ITEM_ENTRY_MIN) {
			if (upitem) {
				OnGossipHello(player, item, selectItem);
			}
			else
			{
				ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【强化公告】|r该物品强化等级已满。");
			}
		}
		else
		{
			ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【强化公告】|r此装备无法升级。");
		}
		return true;
	}

	bool OnGossipHello(Player* player, Item* item, SpellCastTargets const& selectItem)

	{
		exflag = {};
		exitems = {};
		haves = 0;
		uint32 sel_item_entry = selectItem.GetItemTargetEntry();
		uint64 sel_item_guid = selectItem.GetItemTargetGUID();
		session = player->GetSession();
		player->PlayerTalkClass->ClearMenus();
		//player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, sT->GetItemIcon(newItem->GetEntry(), 30, 30, -18, 0) + sT->GetItemLink(newItem, session), slot, newItem->GetGUIDLow(), "Using this item for transmogrify will bind it to you and make it non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + sT->GetItemIcon(newItem->GetEntry(), 40, 40, -15, -10) + sT->GetItemLink(newItem, session) + ss.str(), price, false);
		//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 1, 0);

		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t强化后为：", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t  " + sT->GetItemIcon(sel_item_entry + 1000, 20, 20, 0, 0) + sT->GetItemLink(sel_item_entry + 1000, session), GOSSIP_SENDER_MAIN, SEND_UP_ITEM);
		addExGoosipItem(player, sel_item_entry, session);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t确认强化", GOSSIP_SENDER_MAIN, SEND_ACK_GOOSIP);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
		return true;

	}
	void addExGoosipItem(Player* player, uint32 entry, WorldSession* session) {
		float scale_num = 1;
		uint32 entry_up = entry;
		ItemTemplate const* upitem = sObjectMgr->GetItemTemplate(entry);

		if (findstr(upitem->Name1,"阶")) {
			string upn = getupnum(upitem->Name1);
			if (upn== "一") {
				entry_up = entry - 1000;
				scale_num = pow(1.5, 1);
			}
			else if (upn == "二") {
				entry_up = entry - 2000;
				scale_num = pow(1.5, 2);
			}
			else if (upn == "三") {
				entry_up = entry - 3000;
				scale_num = pow(1.5, 3);
			}
			else if (upn == "四") {
				entry_up = entry - 4000;
				scale_num = pow(1.5, 4);
			}
			else if (upn == "五") {
				entry_up = entry - 5000;
				scale_num = pow(1.5, 5);
			}
			else if (upn == "六") {
				entry_up = entry - 6000;
				scale_num = pow(1.5, 6);
			}
			else if (upn == "七") {
				entry_up = entry - 7000;
				scale_num = pow(1.5, 7);
			}
			else if (upn == "八") {
				entry_up = entry - 8000;
				scale_num = pow(1.5, 8);
			}
		}

		const ItemUpExTemplate* itemUpExTem = sObjectMgr->GetItemUpExTemplate(entry_up);
		if (itemUpExTem) {
			if (itemUpExTem->excount_1 > 0) {
				if (itemUpExTem->exitem_1 == 710001) {
					haves = player->GetUSERJF();
				}
				else
				{
					haves = player->GetItemCount(itemUpExTem->exitem_1);
				}
				if (haves >= itemUpExTem->excount_1) {
					exflag[itemUpExTem->exitem_1] = false;
					exitems[itemUpExTem->exitem_1] = (int)(itemUpExTem->excount_1*scale_num);
				}
				else
				{
					exflag[itemUpExTem->exitem_1] = true;
				}
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t需要" + sT->GetItemLink(itemUpExTem->exitem_1, session) + "  " + "|cFF0000FF " + to_string(haves).c_str() + "/" + to_string((int)(itemUpExTem->excount_1*scale_num)).c_str() + "|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
			}
			if (itemUpExTem->excount_2 > 0) {
				if (itemUpExTem->exitem_2 == 710001) {
					haves = player->GetUSERJF();
				}
				else
				{
					haves = player->GetItemCount(itemUpExTem->exitem_2);
				}
				if (haves >= itemUpExTem->excount_2) {
					exflag[itemUpExTem->exitem_2] = false;
					exitems[itemUpExTem->exitem_2] = (int)(itemUpExTem->excount_2*scale_num);

				}
				else
				{
					exflag[itemUpExTem->exitem_2] = true;
				}
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t需要" + sT->GetItemLink(itemUpExTem->exitem_2, session) + "  " + "|cFF0000FF " + to_string(haves).c_str() + "/" + to_string((int)(itemUpExTem->excount_2*scale_num)).c_str() + "|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
			}
			if (itemUpExTem->excount_3 > 0) {
				if (itemUpExTem->exitem_3 == 710001) {
					haves = player->GetUSERJF();
				}
				else
				{
					haves = player->GetItemCount(itemUpExTem->exitem_3);
				}
				if (haves >= itemUpExTem->excount_3) {
					exflag[itemUpExTem->exitem_3] = false;
					exitems[itemUpExTem->exitem_3] = (int)(itemUpExTem->excount_3*scale_num);
				}
				else
				{
					exflag[itemUpExTem->exitem_3] = true;
				}
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t需要" + sT->GetItemLink(itemUpExTem->exitem_3, session) + "  " + "|cFF0000FF " + to_string(haves).c_str() + "/" + to_string((int)(itemUpExTem->excount_3*scale_num)).c_str() + "|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
			}
			if (itemUpExTem->excount_4 > 0) {
				if (itemUpExTem->exitem_4 == 710001) {
					haves = player->GetUSERJF();
				}
				else
				{
					haves = player->GetItemCount(itemUpExTem->exitem_4);
				}
				if (haves >= itemUpExTem->excount_4) {
					exflag[itemUpExTem->exitem_4] = false;
					exitems[itemUpExTem->exitem_4] = (int)(itemUpExTem->excount_4*scale_num);
				}
				else
				{
					exflag[itemUpExTem->exitem_4] = true;
				}
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t需要" + sT->GetItemLink(itemUpExTem->exitem_4, session) + "  " + "|cFF0000FF " + to_string(haves).c_str() + "/" + to_string((int)(itemUpExTem->excount_4*scale_num)).c_str() + "|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
			}
			if (itemUpExTem->excount_5 > 0) {
				if (itemUpExTem->exitem_5 == 710001) {
					haves = player->GetUSERJF();
				}
				else
				{
					haves = player->GetItemCount(itemUpExTem->exitem_5);
				}
				if (haves >= itemUpExTem->excount_5) {
					exflag[itemUpExTem->exitem_5] = false;
					exitems[itemUpExTem->exitem_5] = (int)(itemUpExTem->excount_5*scale_num);
				}
				else
				{
					exflag[itemUpExTem->exitem_5] = true;
				}

				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t需要" + sT->GetItemLink(itemUpExTem->exitem_5, session) + "  " + "|cFF0000FF " + to_string(haves).c_str() + "/" + to_string((int)(itemUpExTem->excount_5*scale_num)).c_str() + "|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
			}
		}
		else
		{
			ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【强化公告】|r加载失败。");
		}
	}
	//void OnGossipSelect(Player* /*player*/, Item* /*item*/, uint32 /*sender*/, uint32 /*action*/) { }
	void OnGossipSelect(Player* player, Item* item, uint32 sender, uint32 action)

	{
		player->PlayerTalkClass->ClearMenus();

		if (sender == GOSSIP_SENDER_MAIN && action == GOSSIP_ACTION_INFO_DEF)

		{

			OnGossipHello(player, item, sel_item);

			return;
		}



		if (action == SEND_ACK_GOOSIP && sender)

		{
			bool flag_local = false;
			if (exflag.size() > 0) {
				for (auto iter = exflag.begin();iter != exflag.end();++iter) {
					if (iter->second)
					{
						flag_local = true;
						break;
					}
				}
			}
			else
			{
				flag_local = true;
			}
			
			if (flag_local) {

				ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【强化公告】|r材料不足！");
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
				//player->DestroyItemCount(sel_item.GetItemTargetEntry(), 1, true);
				player->AddItem(sel_item.GetItemTargetEntry() + 1000, 1);

			}
			exflag = {};
			exitems = {};
			haves = 0;
			//以下是扣材料
			//7910,710000
			//----

		}

		if (action == SEND_UP_ITEM && sender)

		{
			string outputstr = "|cFF009933【强化公告】|r 下一级装备预览 " + sT->GetItemLink(sel_item.GetItemTargetEntry() + 1000, session);
			////string ss = "|cFF009933【强化公告】|r ";
			////const char *buff = ss.c_str();
			const char *buffer = outputstr.c_str();
			ChatHandler(player->GetSession()).SendSysMessage(buffer);
			OnGossipHello(player, item, sel_item);
			return;
		}

		player->CLOSE_GOSSIP_MENU();

		return;

	}
private:

	SpellCastTargets sel_item;
	std::unordered_map<uint32, uint32> exitems = {};
	std::unordered_map<uint32, bool> exflag = {};
	uint32 haves = 0;
	WorldSession* session;

	
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

	bool findstr( string str, string s_str) {
		vector<string> vstr = {};
		splitWord(str, vstr);
		string ss;
		for (int i = 0;i < vstr.size();i++) {
			ss = "";
			for (int j = 0;j < s_str.length()/3;j++)
			{
				if (i+j> vstr.size() -1) {
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

	string getupnum(string str) {
		vector<string> vstr = {};
		splitWord(str, vstr);
		for (int i = 0;i < vstr.size();i++) {
			if (vstr[i+1] == "阶"&&i+1<vstr.size()) {
				return vstr[i];
			}
		}
		return "";
	}
};

void AddGossipOnItemQhScripts()
{
	new Gossip_OnItemQh();
}