function rate = hwallCost(hwall)
    if((hwall >= 5) && (hwall < 7.5))
       rate = 30 + (hwall - 5) * (30) / (2.5);
    elseif((hwall >= 7.5) && (hwall < 10))
        rate = 60 + (hwall - 7.5) * (35) / 2.5;
    elseif((hwall >= 10) && (hwall < 12.5))
        rate = 95 + (hwall - 10) * (40) / 2.5;
    elseif((hwall >= 12.5) && (hwall < 15))
        rate = 135 + (hwall - 12.5) * (45) / 2.5;
    elseif((hwall >= 15) && (hwall < 17.5))
        rate = 180 + (hwall - 15) * (70) / 2.5;
    elseif((hwall >= 17.5) && (hwall < 20))
        rate = 250 + (hwall - 17.5) * (90) / 2.5;
    elseif(hwall == 20)
        rate = 340;
    else
        rate = -1;
    end
end