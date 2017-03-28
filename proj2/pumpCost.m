function cost = pumpCost(Np, h)
    h = floor(h / 10) * 10;
    switch(Np)
        case 0.80
            switch(h)
                case 20
                    cost = 200;
                case 30
                    cost = 220;
                case 40
                    cost = 242;
                case 50
                    cost = 266;
                case 60
                    cost = 293;
                case 70
                    cost = 322;
                case 80
                    cost = 354;
                case 90
                    cost = 390;
                case 100
                    cost = 429;
                case 110
                    cost = 472;
                case 120
                    cost = 519;
            end
        case 0.83
            switch(h)
                case 20
                    cost = 240;
                case 30
                    cost = 264;
                case 40
                    cost = 290;
                case 50
                    cost = 319;
                case 60
                    cost = 351;
                case 70
                    cost = 387;
                case 80
                    cost = 425;
                case 90
                    cost = 468;
                case 100
                    cost = 514;
                case 110
                    cost = 566;
                case 120
                    cost = 622;
            end
        case 0.86
            switch(h)
                case 20
                    cost = 288;
                case 30
                    cost = 317;
                case 40
                    cost = 348;
                case 50
                    cost = 383;
                case 60
                    cost = 422;
                case 70
                    cost = 464;
                case 80
                    cost = 510;
                case 90
                    cost = 561;
                case 100
                    cost = 617;
                case 110
                    cost = 679;
                case 120
                    cost = 747;
            end
        case 0.89
            switch(h)
                case 20
                    cost = 346;
                case 30
                    cost = 380;
                case 40
                    cost = 418;
                case 50
                    cost = 460;
                case 60
                    cost = 506;
                case 70
                    cost = 557;
                case 80
                    cost = 612;
                case 90
                    cost = 673;
                case 100
                    cost = 741;
                case 110
                    cost = 815;
                case 120
                    cost = 896;
            end
        case 0.92
            switch(h)
                case 20
                    cost = 415;
                case 30
                    cost = 456;
                case 40
                    cost = 502;
                case 50
                    cost = 552;
                case 60
                    cost = 607;
                case 70
                    cost = 668;
                case 80
                    cost = 735;
                case 90
                    cost = 808;
                case 100
                    cost = 889;
                case 110
                    cost = 978;
                case 120
                    cost = 1076;
            end
    end
end
