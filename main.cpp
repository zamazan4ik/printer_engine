#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

std::vector<short> readData()
{
    std::size_t zoneCount;
    std::cin >> zoneCount;

    std::vector<short> zones(zoneCount);
    for(auto& zone : zones)
    {
        std::cin >> zone;
    }

    return zones;
}

void initializeZones(const std::vector<short>& zones, std::vector<bool>& mp, std::vector<bool>& mo)
{
    for(std::size_t i = 0; i < zones.size(); ++i)
    {
        if(zones[i] > 0)
        {
            mp[i] = true;
            mo[i] = false;
        }
        else if(zones[i] < 0)
        {
            mp[i] = false;
            mo[i] = true;
        }
        else // zones[i] == 0
        {
            mp[i] = mo[i] = false;
        }
    }
}

void dump(const std::vector<bool>& mp, const std::vector<bool>& mo)
{
    std::cout << "MP: ";
    for(const auto value : mp)
    {
        std::cout << value << " ";
    }
    std::cout << '\n' << "MO: ";
    for(const auto value : mo)
    {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

void process(const std::vector<short>& zones, std::vector<bool>& mp, std::vector<bool>& mo)
{
    const auto maxZoneValue = *std::max_element(zones.begin(), zones.end(), [](const short v1, const short v2)
    {
        return std::abs(v1) < std::abs(v2);
    });

    for(short angle = 1; angle <= maxZoneValue; ++angle)
    {
        dump(mp, mo);
        for(std::size_t i = 0; i < zones.size(); ++i)
        {
            if(std::abs(zones[i]) == angle)
            {
                mp[i] = mo[i] = false;
            }
        }
    }
    dump(mp, mo);
}

int main()
{
    const auto zones = readData();
    std::vector<bool> mo(zones.size()), mp(zones.size());

    initializeZones(zones, mp, mo);
    process(zones, mp, mo);

    return 0;
}