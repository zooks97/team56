function cost = pipeCost(f, D)
    switch(f)
        case 0.05
            switch(D)
                case 0.1
                    cost = 1.00;
                case 0.25
                    cost = 1.20;
                case 0.5
                    cost = 2.57;
                case 0.75
                    cost = 6.30;
                case 1.00
                    cost = 14.00;
                case 1.25
                    cost = 26.00;
                case 1.50
                    cost = 43.00;
                case 1.75
                    cost = 68.00;
                case 2.00
                    cost = 102.00;
                case 2.25
                    cost = 144.00;
                case 2.50
                    cost = 197.00;
                case 2.75 
                    cost = 262.00;
                case 3.00
                    cost = 340.00;
                otherwise
                    cost = -1;
            end
        case 0.03
            switch(D)
                case 0.1
                    cost = 1.2;
                case 0.25
                    cost = 1.44;
                case 0.5
                    cost = 3.08;
                case 0.75
                    cost = 7.56;
                case 1.00
                    cost = 16;
                case 1.25
                    cost = 31;
                case 1.50
                    cost = 52;
                case 1.75
                    cost = 82;
                case 2.00
                    cost = 122;
                case 2.25
                    cost = 173;
                case 2.50
                    cost = 237;
                case 2.75 
                    cost = 315;
                case 3.00
                    cost = 408;
                otherwise
                    cost = -1;
            end
        case 0.02
            switch(D)
                case 0.1
                    cost = 1.44;
                case 0.25
                    cost = 1.72;
                case 0.5
                    cost = 3.7;
                case 0.75
                    cost = 9.07;
                case 1.00
                    cost = 20;
                case 1.25
                    cost = 37;
                case 1.50
                    cost = 63;
                case 1.75
                    cost = 98;
                case 2.00
                    cost = 146;
                case 2.25
                    cost = 208;
                case 2.50
                    cost = 284;
                case 2.75 
                    cost = 378;
                case 3.00
                    cost = 490;
                otherwise
                    cost = -1;
            end
        case 0.01
            switch(D)
                case 0.1
                    cost = 2.16;
                case 0.25
                    cost = 2.58;
                case 0.5
                    cost = 5.55;
                case 0.75
                    cost = 14;
                case 1.00
                    cost = 29;
                case 1.25
                    cost = 55;
                case 1.50
                    cost = 94;
                case 1.75
                    cost = 148;
                case 2.00
                    cost = 219;
                case 2.25
                    cost = 311;
                case 2.50
                    cost = 426;
                case 2.75 
                    cost = 567;
                case 3.00
                    cost = 735;
                otherwise
                    cost = -1;
            end
        case 0.005
            switch(D)
                case 0.1
                    cost = 2.7;
                case 0.25
                    cost = 3.23;
                case 0.5
                    cost = 6.94;
                case 0.75
                    cost = 17;
                case 1.00
                    cost = 37;
                case 1.25
                    cost = 69;
                case 1.50
                    cost = 117;
                case 1.75
                    cost = 185;
                case 2.00
                    cost = 274;
                case 2.25
                    cost = 389;
                case 2.50
                    cost = 533;
                case 2.75 
                    cost = 708;
                case 3.00
                    cost = 919;
                otherwise
                    cost = -1;
            end
        case 0.002
            switch(D)
                case 0.1
                    cost = 2.97;
                case 0.25
                    cost = 3.55;
                case 0.5
                    cost = 7.64;
                case 0.75
                    cost = 19;
                case 1.00
                    cost = 40;
                case 1.25
                    cost = 76;
                case 1.50
                    cost = 129;
                case 1.75
                    cost = 203;
                case 2.00
                    cost = 302;
                case 2.25
                    cost = 428;
                case 2.50
                    cost = 586;
                case 2.75 
                    cost = 779;
                case 3.00
                    cost = 1011;
                otherwise
                    cost = -1;
            end
        otherwise
            cost = -1;
    end
end