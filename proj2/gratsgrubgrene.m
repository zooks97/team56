%%FILE SHIT
fileName = 'out.txt';
outFile = fopen(fileName, 'w');
fprintf(outFile, 'FLOW\tTIME\tF\tD\tN\tSITE\n');

%%CONSTANTS
PWATER = 1000; %% kg / m^3
G = 9.81; %% m / s^2
MWH2J = 3.6e9; %% J / MWh
HR2SEC = 3600; %% s / hr
EMIN = 120; %% MWh
EMAX = 132; %% MWh
EMINJ = EMIN * MWH2J; %% J
EMAXJ = EMAX * MWH2J; %% J

%%STEPS
FSTEP = 1; %% m^3 / s
TSTEP = 1 / 60; %% hr
TMIN = 6; %% hr

%%VARS
flow = [1:FSTEP:500]; %% m^3 / s
t = [TMIN:TSTEP:12];  %% hr
f = [.05, .03, .02, .01, .005, .002];  % unitless
D = [.1, .25, .5, .75, 1, 1.25, 1.50, 1.75, 2, 2.25, 2.5, 2.75, 3]; %% m
Nt = [.83, .86, .89, .92, .94];  % unitless

%%SITES
%S =  [h (m), L (m), N (#), xi (unitless), sa (m^2)];
S1 = [30, sqrt(30^2 + 60^2), 1, 0.15, 600^2];
S21 = [100, 100 * sqrt(2) + 30, 2, 0.2, sqrt(275^2 - 100^2) * 100];
S22 = [100, 100 / sind(60) + 130 - 100 / tand(60), 2, 0.22, sqrt(275^2 - 100^2) * 100];
S3 = [65, 65 * sqrt(2) + 26.2, 1, 0.2, pi * (225 / 2)^2];

S = [S1; S21; S22; S3];

for(i=1:length(flow))
    i %%print status
    for(j=1:length(t))
        %j %%print status
        volM3 = flow(i) * (t(j) * HR2SEC);
        volKg = volM3 * PWATER;
        for(k=1:size(S, 1))
            hwall = volM3 / S(k, 5);
            for(l=1:length(D))
                vel = flow(i) / (pi * (D(l) / 2)^2);
                for(m=1:length(Nt))
                    for(n=1:length(f))
                        %   J    =     kg    none     m        m/s       m
                        fricLoss = (volKg * f(n) * S(k, 2) * vel^2 / (2 * D(l)));
                        
                        %   J    =  MWh                none
                        turbLoss = (EMINJ * ((1 / Nt(m)) - 1));
                        
                        %   J    =   #          kg     none     m/s
                        bendLoss = (S(k, 3) * volKg * S(k, 4) * vel^2 / 2);
                        
                        %J  =   kg   m/s^2    m
                        Ein = (volKg * G * S(k, 1));
                        
                        Eout = Ein - fricLoss - turbLoss - bendLoss;
                        
                        if (Eout >= EMINJ) && (Eout <= EMAXJ) 
                            
                            
                            
                            %fprintf(outFile, '%f\t%f\t%f\t%f\t%f\t%i\n', flow(i), t(j), f(n), D(l), Nt(m), k);
                        end
                    end
                end
            end
        end
    end
end

%%MORE FILE SHIT
fclose(outFile);