class CfgPatches
{
	class WhisperZones
	{
		requiredAddons[] =
		{
            "DZ_Data"
		};
	};
};

class CfgMods
{
	class WhisperZones
	{
        name = "Whisper Zones";
        author = "TobFal";
        version = "0.1";
		type = "mod";
        dependencies[] = {"Game","World","Mission"};

		class defs
		{
			class gameScriptModule
			{
				value="";
				files[] = {"WhisperZones/scripts/3_Game"};
			};

			class worldScriptModule
			{
				value="";
				files[] = {"WhisperZones/scripts/4_World"};
			};

			class missionScriptModule
			{
				value = "";
				files[] = {"WhisperZones/scripts/5_Mission"};
			};
		};
	};
};
