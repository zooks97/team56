function cost = bendCost(xi, D)
    switch(xi)
        case 0.1
            switch(D)
                case 0.1
                    cost = 1;
                case 0.25
                    cost = 1.49;
                case 0.5
                    cost = 4.93;
                case 0.75
                    cost = 14;
                case 1.00
                    cost = 32;
                case 1.25
                    cost = 62;
                case 1.50
                    cost = 107;
                case 1.75
                    cost = 169;
                case 2.00
                    cost = 252;
                case 2.25
                    cost = 359;
                case 2.50
                    cost = 492;
                case 2.75 
                    cost = 654;
                case 3.00
                    cost = 849;
            end
        case 0.15
            switch(D)
                case 0.1
                    cost = 1.05;
                case 0.25
                    cost = 1.57;
                case 0.5
                    cost = 5.17;
                case 0.75
                    cost = 15;
                case 1.00
                    cost = 34;
                case 1.25
                    cost = 65;
                case 1.50
                    cost = 112;
                case 1.75
                    cost = 178;
                case 2.00
                    cost = 265;
                case 2.25
                    cost = 377;
                case 2.50
                    cost = 516;
                case 2.75 
                    cost = 687;
                case 3.00
                    cost = 892;
            end
        case 0.2
            switch(D)
                case 0.1
                    cost = 1.10;
                case 0.25
                    cost = 1.64;
                case 0.5
                    cost = 5.43;
                case 0.75
                    cost = 16;
                case 1.00
                    cost = 36;
                case 1.25
                    cost = 69;
                case 1.50
                    cost = 118;
                case 1.75
                    cost = 187;
                case 2.00
                    cost = 287;
                case 2.25
                    cost = 396;
                case 2.50
                    cost = 542;
                case 2.75 
                    cost = 721;
                case 3.00
                    cost = 936;
            end
        case 0.22
            switch(D)
                case 0.1
                    cost = 1.16;
                case 0.25
                    cost = 1.73;
                case 0.5
                    cost = 5.7;
                case 0.75
                    cost = 16;
                case 1.00
                    cost = 38;
                case 1.25
                    cost = 72;
                case 1.50
                    cost = 124;
                case 1.75
                    cost = 196;
                case 2.00
                    cost = 292;
                case 2.25
                    cost = 415;
                case 2.50
                    cost = 569;
                case 2.75 
                    cost = 757;
                case 3.00
                    cost = 983;
            end
        case 0.27
            switch(D)
                case 0.1
                    cost = 1.22;
                case 0.25
                    cost = 1.83;
                case 0.5
                    cost = 5.99;
                case 0.75
                    cost = 17;
                case 1.00
                    cost = 39;
                case 1.25
                    cost = 76;
                case 1.50
                    cost = 130;
                case 1.75
                    cost = 206;
                case 2.00
                    cost = 307;
                case 2.25
                    cost = 436;
                case 2.50
                    cost = 598;
                case 2.75 
                    cost = 795;
                case 3.00
                    cost = 1032;
            end
        case 0.3
            switch(D)
                case 0.1
                    cost = 1.28;
                case 0.25
                    cost = 1.90;
                case 0.5
                    cost = 7;
                case 0.75
                    cost = 18;
                case 1.00
                    cost = 41;
                case 1.25
                    cost = 80;
                case 1.50
                    cost = 137;
                case 1.75
                    cost = 216;
                case 2.00
                    cost = 322;
                case 2.25
                    cost = 458;
                case 2.50
                    cost = 628;
                case 2.75 
                    cost = 835;
                case 3.00
                    cost = 1084;
            end
    end
end