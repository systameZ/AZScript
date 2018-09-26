/*
 * Originally written by Xinef - Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "Player.h"


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

        void Initialize()
        {
            _encounterProgress = 0;
            _barrelCount = 0;
            _attemptsCount = 0;

            _thrallGUID = 0;
            _tarethaGUID = 0;

            _initalFlamesSet.clear();
            _finalFlamesSet.clear();
            _prisonersSet.clear();
            _events.Reset();
        }

        void OnPlayerEnter(Player* player)
        {
           
        }

        void CleanupInstance()
        {
            
        }

        void OnCreatureCreate(Creature* creature)
        {
            
        }

        void OnGameObjectCreate(GameObject* gameobject)
        {
            switch (gameobject->GetEntry())
            {
                
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                
            }
        }

        uint32 GetData(uint32 data) const
        {
            
        }

        uint64 GetData64(uint32 data) const
        {
            
        }

        void Update(uint32 diff)
        {
            
        }

        void Reposition(Creature* thrall)
        {
           
        }

        void EnsureGridLoaded()
        {
            
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
                saveStream << "O H " << _encounterProgress << ' ' << _attemptsCount;

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint32 data0, data1;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1;

            if (dataHead1 == 'O' && dataHead2 == 'H')
            {
                _encounterProgress = data0;
                _attemptsCount = data1;
            }
            else
                OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        private:
            uint32 _encounterProgress;
            uint32 _barrelCount;
            uint32 _attemptsCount;

            uint64 _thrallGUID;
            uint64 _tarethaGUID;
            std::set<uint64> _initalFlamesSet;
            std::set<uint64> _finalFlamesSet;
            std::set<uint64> _prisonersSet;

            EventMap _events;
    };

};

void AddSC_instance_diy()
{
    new instance_diy();
}
