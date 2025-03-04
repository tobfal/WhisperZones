modded class VONManagerBase
{
    void SetIsInWhisperZone(bool isInWhisperZone);
}

modded class VONManagerImplementation extends VONManagerBase
{
    protected bool m_IsInWhisperZone = false;

    override void SetIsInWhisperZone(bool isInWhisperZone)
    {
        m_IsInWhisperZone = isInWhisperZone;

        if (isInWhisperZone)
        {
            ForceVoiceLevel(VoiceLevelWhisper);
        }
    }

    override void HandleInput(Input inp)
    {
        if (!m_IsInWhisperZone)
        {
            super.HandleInput(inp);
            return;
        }

        if (inp.LocalPress_ID(UAVoiceDistanceUp,false) || inp.LocalPress_ID(UAVoiceDistanceDown,false))
        {
            ForceVoiceLevel(VoiceLevelWhisper);
        }
    }

    private bool ForceVoiceLevel(int voiceLevel)
    {
        int oldLevel = GetGame().GetVoiceLevel();
        if (oldLevel == -1)
        {
            return false;
        }

        if (oldLevel != VoiceLevelWhisper) {
            GetGame().SetVoiceLevel(voiceLevel);
            UpdateVoiceIcon();
        }

        ShowVoiceNotification(voiceLevel, !GetGame().GetMission().IsVoNActive());
        return true;
    }
}
