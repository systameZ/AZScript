#pragma execution_character_set("utf-8")
#include "ScriptPCH.h"

#include "Player.h"

#include "Chat.h"

#include "ObjectMgr.h"

#include "ScriptMgr.h"

#include "Item.h"

#include "Config.h"

#include "Pet.h"



uint32 countjf;
uint32 needjf;
uint32 nowlevel;
uint32 upneedjf;
const VipTemplate* vt;
class Gossip_OnNpcVip : public CreatureScript

{

public:

    Gossip_OnNpcVip() :CreatureScript("Gossip_OnNpcVip") {}



    //转职函数

    bool OnGossipHello(Player* player, Creature* creature)

    {
        countjf = player->GetUserJfCount();
        needjf = player->GetVipUpJf();
        nowlevel = player->GetVipNowLevel();
        upneedjf = countjf > needjf ? 0 : needjf - countjf;
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t欢迎使用 VIP 功能", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        AddGossipItemFor(player, 10, ("|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t当前VIP等级为：|cFF0000FF " + to_string(nowlevel) + "|r").c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        if (needjf > 0) {
            AddGossipItemFor(player, 10, ("|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t当前累计积分为：|cFF0000FF " + to_string(countjf) + "|r").c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            AddGossipItemFor(player, 10, ("|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t升级所需累计积分达到：|cFF0000FF" + to_string(needjf)).c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            AddGossipItemFor(player, 10, ("|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t升级还需积分：|cFF0000FF" + to_string(upneedjf)).c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|t确认升级", GOSSIP_SENDER_MAIN, 10010);
        }
        else
        {
            AddGossipItemFor(player, 10, "|TInterface\\ICONS\\Trade_Engineering.blp:25:25:-20:-3|tVIP等级已经满！", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        }





        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());



        return true;

    }



    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)

    {

        ClearGossipMenuFor(player);



        if (sender == GOSSIP_SENDER_MAIN && action == GOSSIP_ACTION_INFO_DEF)

        {

            OnGossipHello(player, creature);

            return true;

        }



        if (sender == GOSSIP_SENDER_MAIN && action == 10010)
        {
            if ( upneedjf == 0) {
                player->SetVipLevel(nowlevel + 1);
                ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【VIP公告】|r 升级成功!");
                GiveForPlayer(player,creature);
            }
            else {
                ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【VIP公告】|r 累计积分不足!");
            }

        }



        CloseGossipMenuFor(player);



        return true;

    }
    void GiveForPlayer(Player* player,Creature* creature) {
        vt = sObjectMgr->GetVipTemplate(nowlevel + 1);
        if (vt->give_1_type == 1) {
            player->AddItem(vt->give_1, 1);
        }
        else if(vt->give_1_type == 2) {
			if (player->HasSpell(vt->give_1-1)) {
				player->removeSpell(vt->give_1 - 1, SPEC_MASK_ALL, false);
			}
			if (player->HasSpell(vt->give_1)) {
				return;
			}
            player->learnSpell(vt->give_1);
        }
        if (vt->give_2_type == 1) {
            player->AddItem(vt->give_2, 1);
        }
        else if (vt->give_2_type == 2) {
			if (player->HasSpell(vt->give_1 - 1)) {
				player->removeSpell(vt->give_1 - 1, SPEC_MASK_ALL, false);
			}
			if (player->HasSpell(vt->give_1)) {
				return;
			}
            player->learnSpell(vt->give_2);
        }
        if (vt->give_3_type == 1) {
            player->AddItem(vt->give_3, 1);
        }
        else if (vt->give_3_type == 2) {
			if (player->HasSpell(vt->give_1 - 1)) {
				player->removeSpell(vt->give_1 - 1, SPEC_MASK_ALL, false);
			}
			if (player->HasSpell(vt->give_1)) {
				return;
			}
            player->learnSpell(vt->give_3);
        }
        if (vt->give_4_type == 1) {
            player->AddItem(vt->give_4, 1);
        }
        else if (vt->give_4_type == 2) {
			if (player->HasSpell(vt->give_1 - 1)) {
				player->removeSpell(vt->give_1 - 1, SPEC_MASK_ALL, false);
			}
			if (player->HasSpell(vt->give_1)) {
				return;
			}
            player->learnSpell(vt->give_4);
        }
        if (vt->give_5_type == 1) {
            player->AddItem(vt->give_5, 1);
        }
        else if (vt->give_5_type == 2) {
			if (player->HasSpell(vt->give_1 - 1)) {
				player->removeSpell(vt->give_1 - 1, SPEC_MASK_ALL, false);
			}
			if (player->HasSpell(vt->give_1)) {
				return;
			}
            player->learnSpell(vt->give_5);
        }
    }

};

void AddGossipOnNpcVipScripts()
{
    new Gossip_OnNpcVip();
}
