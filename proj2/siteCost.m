function cost = siteCost(S, sa, hwall)

    switch S(1)
        case 30
            if(sa <= 300^2 * pi)
                wallCost = hwallCost(hwall) * sqrt(sa / pi) * 2 * pi;
            else
                wallCost = hwallCost(hwall) * 4 * sqrt(sa);
            end
            cost = wallCost + 40000 + 0.25 * sa + 8000;
        case 100
            wallCost = hwallCost(hwall) * 15^(3/4) * sqrt(sa) / 7^(1/4);
            cost = wallCost + 100000 + 0.5 * sa + 2000;
        case 65
            wallCost = hwallCost(hwall) * sqrt(sa / pi) * 2 * pi;
            cost = wallCost + 150000 + 0.3 * sa + 0.6 * ((225 / 2)^2 * pi - sa);
    end
    cost = cost + S(6) * 250 + S(2) * 500;  %area under pipe & pipe length
end