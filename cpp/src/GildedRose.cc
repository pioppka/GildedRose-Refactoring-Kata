#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{
}

void updateQuality(int q, int value)
{
    if(0 < q && q < 50)
    {
        q += value;
    }
}

void GildedRose::updateData()
{
    const string itemNames[3] = {"Aged Brie", "Backstage passes to a TAFKAL80ETC concert", "Sulfuras, Hand of Ragnaros"};
    for (auto &item: items)
    {
        item.sellIn -= (item.name == itemNames[2]) ? 0 : 1;

        switch(item.name)
        {
            case itemNames[0]:
                
                updateQuality(item.quality, (item.sellIn < 0) ? 2 : 1)
                break;
                
            case itemNames[1]:
                if (item.sellIn < 0)
                {
                    updateQuality(item.quality, -item.quality);
                }
                else if (item.sellIn < 5)
                {
                    updateQuality(item.quality, 3);
                }
                else if (item.sellIn < 10)
                {
                    updateQuality(item.quality, 2);
                }
                else
                {
                    updateQuality(item.quality, 1);
                }
                break;
                
            case itemNames[2]:
                updateQuality(item.quality, 0);
                break;
                
            default:
                updateQuality(item.quality, (item.sellIn < 0) ? -2 : -1)
                break;
        }
    }
}
