# WhisperZones

## Description
**WhisperZones** allows you to define zones in which players' voice chat is automatically set to whisper mode.

## JSON Configuration
The `config.json` file is located in:
```
$profile/WhisperZones/config.json
```
### **config.json Structure**
```json
{
    "m_Zones": [
        {
            "m_Position": [5000, 0, 5000],
            "m_Radius": 100,
            "m_Height": 100
        },
        {
            "m_Position": [6000, 0, 6000],
            "m_Radius": 150,
            "m_Height": 200
        }
    ]
}
```
- **`position`**: The center position of the zone (X, Y, Z coordinates).
- **`radius`**: The radius of the zone in meters.
- **`height`**: The height of the zone, with the Y coordinate in the center.