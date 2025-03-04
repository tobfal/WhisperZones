class WhisperZonesConfig
{
    ref array<ref WhisperZoneData> m_Zones;

    void WhisperZonesConfig()
    {
        m_Zones = new array<ref WhisperZoneData>();
    }
}

class WhisperZoneData
{
    vector m_Position;
    float m_Radius;
    float m_Height;

    void WhisperZoneData(vector position, float radius, float height)
    {
        m_Position = position;
        m_Radius = radius;
        m_Height = height;
    }
}