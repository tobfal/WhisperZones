modded class MissionServer
{
    override void OnInit()
	{		
		super.OnInit();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.LoadWhisperZonesConfig, 1000, false);
	}

    void LoadWhisperZonesConfig()
    {
        string filePath = "$profile:WhisperZones/config.json";
        		
        WhisperZonesConfig config = new WhisperZonesConfig();

        if (FileExist(filePath))
        {
            JsonFileLoader<WhisperZonesConfig>.JsonLoadFile(filePath, config);
            Print("[WhisperZones] Config file successfully loaded: " + filePath);
        }
        else
        {
            Print("[WhisperZones] Config file not found, creating a default configuration");

            string directoryPath = "$profile:WhisperZones";
            if (!FileExist(directoryPath))
            {
                MakeDirectory(directoryPath);
            }

            config.m_Zones.Insert(new WhisperZoneData("0 0 0", 1.0, 1.0));
            JsonFileLoader<WhisperZonesConfig>.JsonSaveFile(filePath, config);
            Print("[WhisperZones] Default config file has been created: " + filePath);
        }

        int i = 0;
        foreach (WhisperZoneData data : config.m_Zones)
        {
            i++;
            SpawnWhisperZone(data.m_Position, data.m_Radius, data.m_Height);
        }

        if(i > 0)
        {
            Print("[WhisperZones] " + i + "WhisperZone(s) created");
        }
    }

    private void SpawnWhisperZone(vector position, float radius, float height)
    {
        WhisperZoneTrigger newTrigger;
        if (Class.CastTo(newTrigger, GetGame().CreateObjectEx("WhisperZoneTrigger", position, ECE_NONE)))
        {
            vector triggerPosition = position;
            triggerPosition[1] = triggerPosition[1] - (height / 2.0);
            newTrigger.SetPosition(triggerPosition);
            newTrigger.SetCollisionCylinder(radius, height);
        }
    }
}
