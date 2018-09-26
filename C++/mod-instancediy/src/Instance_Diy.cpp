#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "Player.h"
#include "MapManager.h"
#pragma execution_character_set("utf-8")


struct AutoBalanceCreatureInfo
{
	uint32 instancePlayerCount;
	float DamageMultiplier;
};

static std::map<uint32, AutoBalanceCreatureInfo> CreatureInfo; // 当该生物死亡时，应添加一个钩子以移除映射的条目，或者应将该条目添加到该生物对象中                 // 映射值与配置文件中的vas.autocalance.xxx.名项相对应。
static int8 PlayerCountDifficultyOffset;

class instance_diy : public InstanceMapScript
{
public:
	instance_diy() : InstanceMapScript("instance_diy", 560) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_diy_InstanceMapScript(map);
    }

    struct instance_diy_InstanceMapScript : public InstanceScript
    {
		instance_diy_InstanceMapScript(Map* map) : InstanceScript(map) { }
		//void Initialize() {
		//	sLog->outString("void Initialize");
		//	
		//	/*for (auto iter = mrf.begin();iter != mrf.end();iter->next()) {
		//		sLog->outString(to_string(iter->GetSource()->GetGUID()).c_str());
		//		if (iter->GetSource()->GetGUID() == 9) {
		//			flag = true;
		//		}
		//	}*/
		//}
		//void OnCreate() {
		//	sLog->outString("void OnCreate");
		//}
		//void OnDestroy(){
		//	sLog->outString("void OnDestroy");
		//}
		//void OnLoadGridMap() {
		//	sLog->outString("void OnLoadGridMap");
		//}
		//void Load(char const* data) {
		//	sLog->outString("void Load");
		//}

		//void FillInitialWorldStates(WorldPacket& /*data*/) {
		//	sLog->outString("void Load");
		//}

  //      void OnPlayerEnter(Player* player)
  //      {
		//	sLog->outString("void OnPlayerEnter");

  //      }

  //      void CleanupInstance()
  //      {
  //          
  //      }

		//void CreatureLooted(Creature* /*creature*/, LootType) {
		//	sLog->outString("void CreatureLooted");
		//}

  //      void OnCreatureCreate(Creature* creature)
  //      {
		///*
		//	sLog->outString("void OnCreatureCreate");
		//	MapRefManager const& mrf = instance->GetPlayers();
		//	sLog->outString(to_string(mrf.getSize()).c_str());
		//	auto iter = mrf.begin();
		//	sLog->outString(to_string(iter->GetSource()->GetGUID()).c_str());
		//	if (iter->GetSource()->GetGUID() == 9) {
		//		flag = true;
		//	}
		//	*/
  //          uint8 diff=0;
  //          MapRefManager const& mrf=instance->GetPlayers();
  //          auto iter = mrf.begin();
		//	sLog->outString(to_string(mrf.getSize()).c_str());
		//	if (mrf.getSize()>=1) {
		//		if (iter->GetSource()->GetGroup() != NULL) {
		//			//判断是否为group
		//			diff = 2;//iter->GetSource()->GetGroupInstanceDiff();
		//		}
		//		else {
		//			diff = 1;//iter->GetSource()->GetInstanceDiff();
		//		}
		//	}
		//	/*for (LinkedListHead::Iterator< MapReference const > iter = mrf.begin();iter!=mrf.end();iter++) {
		//		sLog->outString(to_string(iter->GetSource()->GetGUID()).c_str());
		//		if (iter->GetSource()->GetGUID() == 9) {
		//			flag = true;
		//		}
		//	}*/
  //          if(diff>0){
  //              switch(diff){
  //                  case 1:SetCreatureData(creature,5); break;
		//			case 2:SetCreatureData(creature,10);break;
  //              }
  //          }
  //      }
  //      void SetCreatureData(Creature* creature,uint8 upnum){
		//	CreatureTemplate const* cInfo = creature->GetCreatureTemplate();

		//	uint32 rank = creature->IsPet() ? 0 : cInfo->rank;

		//	// level
		//	uint8 minlevel = std::min(cInfo->maxlevel, cInfo->minlevel);
		//	uint8 maxlevel = std::max(cInfo->maxlevel, cInfo->minlevel);
		//	uint8 level = minlevel == maxlevel ? minlevel : urand(minlevel, maxlevel);

		//	CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(level, cInfo->unit_class);

		//	// health
		//	float healthmod;
		//	switch (rank)                                           // define rates for each elite rank
		//	{
		//	case CREATURE_ELITE_NORMAL:
		//		 healthmod = sWorld->getRate(RATE_CREATURE_NORMAL_HP);
		//	case CREATURE_ELITE_ELITE:
		//		 healthmod = sWorld->getRate(RATE_CREATURE_ELITE_ELITE_HP);
		//	case CREATURE_ELITE_RAREELITE:
		//		 healthmod = sWorld->getRate(RATE_CREATURE_ELITE_RAREELITE_HP);
		//	case CREATURE_ELITE_WORLDBOSS:
		//		 healthmod = sWorld->getRate(RATE_CREATURE_ELITE_WORLDBOSS_HP);
		//	case CREATURE_ELITE_RARE:
		//		 healthmod = sWorld->getRate(RATE_CREATURE_ELITE_RARE_HP);
		//	default:
		//		 healthmod = sWorld->getRate(RATE_CREATURE_ELITE_ELITE_HP);
		//	}

		//	uint32 basehp = std::max<uint32>(1, stats->GenerateHealth(cInfo));
		//	uint32 health = uint32((basehp * healthmod)*(1+upnum));

		//	creature->SetCreateHealth(health);
		//	creature->SetMaxHealth(health);
		//	creature->SetHealth(health);
		//	creature->ResetPlayerDamageReq();

		//	uint32 mana = stats->GenerateMana(cInfo)*(1 + upnum);

		//	creature->SetCreateMana(mana);
		//	creature->SetMaxPower(POWER_MANA, mana);                        
		//	creature->SetPower(POWER_MANA, mana);


		//	creature->SetModifierValue(UNIT_MOD_HEALTH, BASE_VALUE, (float)health);
		//	creature->SetModifierValue(UNIT_MOD_MANA, BASE_VALUE, (float)mana);


		//	creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, cInfo->mindmg*(1 + upnum));
		//	creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, cInfo->maxdmg*(1 + upnum));

		//	creature->SetBaseWeaponDamage(OFF_ATTACK, MINDAMAGE, cInfo->mindmg*(1 + upnum));
		//	creature->SetBaseWeaponDamage(OFF_ATTACK, MAXDAMAGE, cInfo->maxdmg*(1 + upnum));

		//	creature->SetBaseWeaponDamage(RANGED_ATTACK, MINDAMAGE, cInfo->minrangedmg*(1 + upnum));
		//	creature->SetBaseWeaponDamage(RANGED_ATTACK, MAXDAMAGE, cInfo->maxrangedmg*(1 + upnum));
		//	creature->SetModifierValue(UNIT_MOD_ATTACK_POWER, BASE_VALUE, cInfo->attackpower);
		//	creature->SetModifierValue(UNIT_MOD_ATTACK_POWER_RANGED, BASE_VALUE, cInfo->rangedattackpower);
		//	sScriptMgr->Creature_SelectLevel(cInfo, creature);
		//	sLog->outString("UPUPUPUP");
  //      }
  //      void OnGameObjectCreate(GameObject* gameobject)
  //      {
		//	sLog->outString("void OnGameObjectCreate");
  //      }

	 //void SetData64(uint32 /*DataId*/, uint64 /*Value*/) {
		// sLog->outString("void SetData64");
	 //}
	 //void SetData(uint32 /*DataId*/, uint32 /*Value*/) {
		// sLog->outString("void SetData");
	 //}

		
    };

};

class Instance_Diy_UnitScript : public UnitScript
{
public:
	Instance_Diy_UnitScript()
		: UnitScript("Instance_Diy_UnitScript", true)
	{
	}

	uint32 DealDamage(Unit* AttackerUnit, Unit *playerVictim, uint32 damage, DamageEffectType damagetype)
	{
		if ((AttackerUnit->GetMap()->IsDungeon() && playerVictim->GetMap()->IsDungeon()) )
			if (AttackerUnit->GetTypeId() != TYPEID_PLAYER)
			{
				damage = VAS_Modifer_DealDamage(AttackerUnit, damage);
			}
		return damage;
	}

	uint32 HandlePeriodicDamageAurasTick(Unit *target, Unit *caster, int32 damage)
	{
		if ((caster->GetMap()->IsDungeon() && target->GetMap()->IsDungeon()))
			if (caster->GetTypeId() != TYPEID_PLAYER)
			{
				if (!((caster->IsHunterPet() || caster->IsPet() || caster->IsSummon()) && caster->IsControlledByPlayer()))
					damage = (float)damage * (float)CreatureInfo[caster->GetGUID()].DamageMultiplier;
			}
		return damage;
	}

	void CalculateSpellDamageTaken(SpellNonMeleeDamage *damageInfo, int32 damage, SpellInfo const *spellInfo, WeaponAttackType attackType, bool crit)
	{
		if ((damageInfo->attacker->GetMap()->IsDungeon() && damageInfo->target->GetMap()->IsDungeon()) || (damageInfo->attacker->GetMap()->IsBattleground() && damageInfo->target->GetMap()->IsBattleground()))
		{
			if (damageInfo->attacker->GetTypeId() != TYPEID_PLAYER)
			{
				if ((damageInfo->attacker->IsHunterPet() || damageInfo->attacker->IsPet() || damageInfo->attacker->IsSummon()) && damageInfo->attacker->IsControlledByPlayer())
					return;
				damageInfo->damage = (float)damageInfo->damage * (float)CreatureInfo[damageInfo->attacker->GetGUID()].DamageMultiplier;
			}
		}
		return;
	}

	void CalculateMeleeDamage(Unit *playerVictim, uint32 damage, CalcDamageInfo *damageInfo, WeaponAttackType attackType)
	{
		// Make sure the Attacker and the Victim are in the same location, in addition that the attacker is not player.
		if (((damageInfo->attacker->GetMap()->IsDungeon() && damageInfo->target->GetMap()->IsDungeon()) || (damageInfo->attacker->GetMap()->IsBattleground() && damageInfo->target->GetMap()->IsBattleground())) && (damageInfo->attacker->GetTypeId() != TYPEID_PLAYER))
			if (!((damageInfo->attacker->IsHunterPet() || damageInfo->attacker->IsPet() || damageInfo->attacker->IsSummon()) && damageInfo->attacker->IsControlledByPlayer())) // Make sure that the attacker Is not a Pet of some sort
			{
				damageInfo->damage = (float)damageInfo->damage * (float)CreatureInfo[damageInfo->attacker->GetGUID()].DamageMultiplier;
			}
		return;
	}

	uint32 VAS_Modifer_DealDamage(Unit* AttackerUnit, uint32 damage)
	{
		if ((AttackerUnit->IsHunterPet() || AttackerUnit->IsPet() || AttackerUnit->IsSummon()) && AttackerUnit->IsControlledByPlayer())
			return damage;

		float damageMultiplier = CreatureInfo[AttackerUnit->GetGUID()].DamageMultiplier;

		return damage * damageMultiplier;

	}
};

class Instance_Diy_AllCreatureScript : public AllCreatureScript
{
public:
	Instance_Diy_AllCreatureScript()
		: AllCreatureScript("Instance_Diy_AllCreatureScript")
	{
	}


	void Creature_SelectLevel(const CreatureTemplate *creatureTemplate, Creature* creature)
	{
		Player* player = GetPlayer(creature->GetMap());
		if (!player) {
			return;
		}
		if (GetInstanceDiffDiyMapId(player, creature->GetMap()->GetId())) {
			if (creature->GetMap()->IsDungeon())
			{
				ModifyCreatureAttributes(creature,Diff);
				CreatureInfo[creature->GetGUID()].instancePlayerCount = creature->GetMap()->GetPlayersCountExceptGMs() + PlayerCountDifficultyOffset;
			}
		}
		/*else
		{
			LootTemplates_Creature.SetLootMode(creature->GetEntry(), 1,1,0 );
		}*/
		
	}

	void OnAllCreatureUpdate(Creature* creature, uint32 diff)
	{
		if (!(CreatureInfo[creature->GetGUID()].instancePlayerCount == (creature->GetMap()->GetPlayersCountExceptGMs() + PlayerCountDifficultyOffset)))
		{
			Player* player = GetPlayer(creature->GetMap());
			if (!player) {
				return;
			}
			if (GetInstanceDiffDiyMapId(player, creature->GetMap()->GetId())) {
				if ((creature->GetMap()->IsDungeon() || creature->GetMap()->IsBattleground()))
					ModifyCreatureAttributes(creature,Diff);
			}
			/*else
			{
				LootTemplates_Creature.SetLootMode(creature->GetEntry(), 1, 1, 0);
			}*/
			
			CreatureInfo[creature->GetGUID()].instancePlayerCount = creature->GetMap()->GetPlayersCountExceptGMs() + PlayerCountDifficultyOffset;
		}
	}
	Player* GetPlayer(Map* map) {
			Map::PlayerList const &playerList = map->GetPlayers();
			if (!playerList.isEmpty())
			{
				for (Map::PlayerList::const_iterator playerIteration = playerList.begin(); playerIteration != playerList.end(); ++playerIteration)
				{
					if (Player* playerHandle = playerIteration->GetSource())
					{
						return playerHandle;
						break;
					}
				}
			}
			return NULL;
	}
	bool GetInstanceDiffDiyMapId(Player* player, uint32 mapid) {
		string str = "select player,map,diff from instance_diff_diy where player=" + to_string(player->GetGUID());
		QueryResult result = WorldDatabase.Query(str.c_str());
		if (result) {
			do {
				Field* fields = result->Fetch();
					if (fields[1].GetUInt32() == mapid) {
						Diff = fields[2].GetUInt32();
						return true;
				}
			} while (result->NextRow());
		}
		return false;
	}

	void ModifyCreatureAttributes(Creature* creature,uint8 diff)
	{
	/*	if (((creature->IsHunterPet() || creature->IsPet() || creature->IsSummon()) && creature->IsControlledByPlayer()) || (creature->GetMap()->IsDungeon()) || creature->GetMap()->GetPlayersCountExceptGMs() <= 0)
		{
			sLog->outString("false");
			return;
		}*/

		if (diff <= 0) {
			return;
		}
		CreatureTemplate const *creatureTemplate = creature->GetCreatureTemplate();
		CreatureBaseStats const* creatureStats = sObjectMgr->GetCreatureBaseStats(creature->getLevel(), creatureTemplate->unit_class);

		

		float damageMultiplier = 1.0f;
		float healthMultiplier = 1.0f;

		uint32 baseHealth = creatureStats->GenerateHealth(creatureTemplate);
		uint32 baseMana = creatureStats->GenerateMana(creatureTemplate);
		uint32 instancePlayerCount = creature->GetMap()->GetPlayersCountExceptGMs() + PlayerCountDifficultyOffset;
		uint32 maxNumberOfPlayers = ((InstanceMap*)sMapMgr->FindMap(creature->GetMapId(), creature->GetInstanceId()))->GetMaxPlayers();
		uint32 scaledHealth = 0;
		uint32 scaledMana = 0;
		uint32 upnum = creature->GetDiffUpNum(creature->GetMap()->GetId(),maxNumberOfPlayers, diff);
		uint32 lootmode = creature->GetDiffRefLootMode(creature->GetMap()->GetId(),maxNumberOfPlayers, diff);
		

		if (upnum>0) {
			switch (diff) {
			case 1:
				healthMultiplier = (float)upnum / 4;
				break;
			case 2:
				healthMultiplier = (float)upnum / 3;
				break;
			case 3:
				healthMultiplier = (float)upnum / 2;
				break;
			default:
				break;
			}
		}
		else
		{
			healthMultiplier = 1.0f;
		}

		if (lootmode>0) {
			creature->SetLootMode(lootmode);
			//switch (lootmode) {//jiang gaodengji de diaoluo baohan zhe di dengji de diaoluo
			//case 100:
			//	creature->SetLootMode(lootmode);
			//	break;
			//case 200:
			//	creature->SetLootMode(lootmode);
			//	creature->AddLootMode(100);
			//	break;
			//case 300:
			//	creature->SetLootMode(lootmode);
			//	creature->AddLootMode(100);
			//	creature->AddLootMode(200);
			//	break;
			//}
			
		}


		//int32 reflootid= creature->GetDiffRefLootId(maxNumberOfPlayers, diff);
		//uint32 reflootchance = creature->GetDiffRefLootChance(maxNumberOfPlayers, diff);
		/*sLog->outString(to_string(reflootchance).c_str());
		if (reflootid < 0) {
			LootTemplates_Creature.SetLootMode(creature->GetEntry(), 1, reflootid, reflootchance);
		}*/

		// (tanh((X-2.2)/1.5) +1 )/2    // 5 Man formula X = Number of Players
		// (tanh((X-5)/2) +1 )/2        // 10 Man Formula X = Number of Players
		// (tanh((X-16.5)/6.5) +1 )/2   // 25 Man Formula X = Number of players
		//
		// Note:2、5、16.5是获得50%健康所需的球员人数。
		// 不需要这是一个完整的数字，你可以调整这个来调升或调降
		// 用于非整组中的每个额外玩家的HP修饰符。这些
		// 值最终将成为配置文件的一部分，一旦我最后确定了mod。
		// 1.5、2和6.5修改了
		// 玩家数量.一般情况下，当你离1的值越近的时候，你就会得到这个
		// 它的速度就越慢。举个例子，一个5的人需要3的时间
		// 完全的玩家在完全健康的状态下面对暴民。
		// +1和/2值提高了提价                                                                                     
		////   VAS SOLO  - Map 0,1 and 530 ( World Mobs )                                                               // 这可能是输精管和跳棋可能起作用的地方。但这是不小的
		//if ((creature->GetMapId() == 0 || creature->GetMapId() == 1 || creature->GetMapId() == 530) && (creature->isElite() || creature->isWorldBoss()))  // 具体到那些地图中的世界老板和精英们，这将会用进入的xplayer来代替安装播放。
		//{
		//	if (baseHealth > 800000) {
		//		healthMultiplier = (tanh((sConfigMgr->GetFloatDefault("VASAutoBalance.numPlayer", 1.0f) - 5.0f) / 1.5f) + 1.0f) / 2.0f;

		//	}
		//	else {
		//		healthMultiplier = (tanh((sConfigMgr->GetFloatDefault("VASAutoBalance.numPlayer", 1.0f) - 2.2f) / 1.5f) + 1.0f) / 2.0f; // 假设是5人，因为自bbc以来，世界上的老板都相对退休了，所以除非老板有一些实质性的基本健康状况
		//	}

		//}


		//Getting the list of Classes in this group - this will be used later on to determine what additional scaling will be required based on the ratio of tank/dps/healer
		//GetPlayerClassList(creature, playerClassList); // Update playerClassList with the list of all the participating Classes

		scaledHealth = uint32((baseHealth * healthMultiplier) + 1.0f);
		// 现在调整法力，法力是可以线性缩放的东西
		if (maxNumberOfPlayers == 0) {
			scaledMana = uint32((baseMana * healthMultiplier) + 1.0f);
			//现在调整损害，这也是线性的，现在...这将不得不改变我的怀疑。
			damageMultiplier = healthMultiplier;
		}
		else {
			scaledMana = ((baseMana / maxNumberOfPlayers) * instancePlayerCount);
			// 现在调整损害，这也是线性的，现在...这将不得不改变我的怀疑。
			damageMultiplier = (float)instancePlayerCount / (float)maxNumberOfPlayers;
		}
		creature->SetCreateHealth(scaledHealth);
		creature->SetMaxHealth(scaledHealth);
		creature->ResetPlayerDamageReq();
		creature->SetCreateMana(scaledMana);
		creature->SetMaxPower(POWER_MANA, scaledMana);
		creature->SetPower(POWER_MANA, scaledMana);
		creature->SetModifierValue(UNIT_MOD_HEALTH, BASE_VALUE, (float)scaledHealth);
		creature->SetModifierValue(UNIT_MOD_MANA, BASE_VALUE, (float)scaledMana);
		CreatureInfo[creature->GetGUID()].DamageMultiplier = damageMultiplier;
	}
	private:
		uint8 Diff = 0;
};

void AddInstanceDiyScripts()
{
    new instance_diy();
	new Instance_Diy_AllCreatureScript();
	new Instance_Diy_UnitScript();
}
