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
        upneedjf = needjf - countjf > 0 ? needjf - countjf : 0;
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
            player->SetVipLevel(nowlevel + 1);
            GiveForPlayer(player);
            ChatHandler(player->GetSession()).SendSysMessage("|cFF009933【VIP公告】|r 升级成功!");
        }



        CloseGossipMenuFor(player);



        return true;

    }
    void GiveForPlayer(Player* player) {
        vt = sObjectMgr->GetVipTemplate(nowlevel + 1);
        if (vt->give_1_type == 1) {
            player->AddItem(vt->give_1, 1);
        }
    }

};

void AddGossipOnNpcVipScripts()
{
    new Gossip_OnNpcVip();
}
