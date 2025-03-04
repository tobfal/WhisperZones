class WhisperZoneTrigger : CylinderTrigger
{
	override protected void OnEnterClientEvent(TriggerInsider insider) 
	{
		super.OnEnterClientEvent(insider);
        UpdateVONManager(insider, true);
        Print("[WhisperZones] Entered WhisperZone");
	}

    override protected void OnLeaveClientEvent(TriggerInsider insider) 
	{
		super.OnLeaveClientEvent(insider);
		UpdateVONManager(insider, false);
        Print("[WhisperZones] Left WhisperZone");
	}

    private void UpdateVONManager(TriggerInsider insider, bool isInWhisperZone)
    {
		PlayerBase player;
		if (!Class.CastTo(player, insider.GetObject()))
        {
            return;
        }
		
		#ifdef ENFUSION_AI_PROJECT
		if (player.IsAI())
			return;
		#endif

		if (player == GetGame().GetPlayer())
        {
            VONManager.GetInstance().SetIsInWhisperZone(isInWhisperZone);
        }
    }
}