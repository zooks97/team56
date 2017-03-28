function cost = turbCost(Nt, h)
    h = floor(h / 10) * 10;
    switch(Nt)
        case 0.83
            switch(h)
                case 20
                    cost = 360;
                case 30
                    cost = 396;
                case 40
                    cost = 436;
                case 50
                    cost = 479;
                case 60
                    cost = 527;
                case 70
                    cost = 580;
                case 80
                    cost = 638;
                case 90
                    cost = 702;
                case 100
                    cost = 772;
                case 110
                    cost = 849;
                case 120
                    cost = 934;
            end
        case 0.86
            switch(h)
                case 20
                    cost = 432;
                case 30
                    cost = 475;
                case 40
                    cost = 523;
                case 50
                    cost = 575;
                case 60
                    cost = 632;
                case 70
                    cost = 696;
                case 80
                    cost = 765;
                case 90
                    cost = 842;
                case 100
                    cost = 926;
                case 110
                    cost = 1019;
                case 120
                    cost = 1120;
            end
        case 0.89
            switch(h)
                case 20
                    cost = 518;
                case 30
                    cost = 570;
                case 40
                    cost = 627;
                case 50
                    cost = 690;
                case 60
                    cost = 759;
                case 70
                    cost = 835;
                case 80
                    cost = 918;
                case 90
                    cost = 1010;
                case 100
                    cost = 1111;
                case 110
                    cost = 1222;
                case 120
                    cost = 1345;
            end
        case 0.92
            switch(h)
                case 20
                    cost = 622;
                case 30
                    cost = 684;
                case 40
                    cost = 753;
                case 50
                    cost = 828;
                case 60
                    cost = 911;
                case 70
                    cost = 1002;
                case 80
                    cost = 1102;
                case 90
                    cost = 1212;
                case 100
                    cost = 1333;
                case 110
                    cost = 1467;
                case 120
                    cost = 1614;
            end
        case 0.94
            switch(h)
                case 20
                    cost = 746;
                case 30
                    cost = 821;
                case 40
                    cost = 903;
                case 50
                    cost = 994;
                case 60
                    cost = 1093;
                case 70
                    cost = 1202;
                case 80
                    cost = 1322;
                case 90
                    cost = 1455;
                case 100
                    cost = 1600;
                case 110
                    cost = 1760;
                case 120
                    cost = 1936;
            end
    end
end
