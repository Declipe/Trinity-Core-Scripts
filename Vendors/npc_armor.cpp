/*
<--------------------------------------------------------------------------->
- Developer(s): InfusionWoW
- Updated By: Ghostcrawler336
- Complete: %0
- ScriptName: 'npc_armor'
- Comment: N/A
<--------------------------------------------------------------------------->
*/
class multi_armor : public CreatureScript
{
	public:
		multi_armor() : CreatureScript("multi_armor")
		{
		}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			Creature * npc_next = pPlayer->FindNearestCreature(600010, 30.0f, true);
			
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Bracer_19:24|t|r Offsets", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELRY_NECKLACE_15:24|t|r Accessories", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Offhand_PVEAlliance_D_01:24|t|r Non-set items", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Bow_1H_Auchindoun_D_01:24|t|r 284 items", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\spell_magic_lesserinvisibilty:24|t|r Nevermind", GOSSIP_SENDER_MAIN, 4);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			return true;
		}

		
		bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			if(!Player)
				return true;
			
			WorldSession * m_session = Player->GetSession();
			
			switch(uiAction)
			{
				case 0:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500031);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 1:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500032);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 2:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 3:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500034);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 4:
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_multi_armor()
{
	new multi_armor();
}