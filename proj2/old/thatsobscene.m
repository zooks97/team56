PWATER = 1000; % Kg/ m^3
%Econs  energy consumed
%Np     pump efficiency
%Ein    energy in
%Nt     turbine effeiciency
%f      pipe friction
%L      pipe length
%V      velocity of water in m/s
%D      pipe diameter
%xi     vector of bend factors
%M      mass of water
%flow   Flow rate in m^3/sec

%Econs = (1-Np)*Ein + Nt*Np*Ein*(1/Nt - 1) + M(f*L*V^2/D) + M*V^2/2*xi;

STEP = 1;

% Range of length of pipe for site 1
Lz1 = sqrt(30^2 + 60^2); 
% Range of length of pipe for site 2
Lz2 = [sqrt(100^2 + 130^2):STEP:((100 / sind(60)) + (130 - (100 / tand(60))))];
% Range of length of pipe for site 3
Lz3 = [sqrt(91.2^2 + 65^2):STEP:((41.2 / cosd(20) + sqrt(2) * (65 - 41.2 * tand(20))))];

time = [6:1:12]; %keep these together!
Ein = 120 ./ time;      %keep these together!

% Pipe loss coefficient options
xi = [.1, .15, .2, .22, .27, .3];
% Pipe diameter options
D = [.1, .25, .5, .75, 1, 1.25, 1.50, 1.75, 2, 2.25, 2.5, 2.75, 3];
% Pipe friction coefficient options
f = [.05, .03, .02, .01, .005, .002];
% Pump efficiency options
Np = [.8, .83, .86, .89, .92];
% Turbine efficiency options
Nt = [.83, .86, .89, .92, .94];
% Height of wall range
hwall = [5:0.5:20];
% Flow rate range
flow = [1:1:500];

%V = (D ./ 2) .^ 2 .* pi ./ flow;
%M = flow .* PWATER ./ V .* Lz1;

%E = M * 9.8 * h;

%Econs = zeros(length(Lz1)*length(time)*length(xi)*length(D)*length(f)*...
%        length(Np)*length(Nt)*length(hwall)*length(flow));

counter = 0;
EconsMin = Inf;

for(i=1:length(Lz2))                           %L
    L = Lz2;
    fprintf('\n%d: ', i);
    for(j=1:length(time))                     %time and Ein
        fprintf('%d', j);
        for(k=1:length(xi))
            for(l=1:length(D))
                for(m=1:length(f))
                    for(n=1:length(Np))
                        for(o=1:length(Nt))
                            for(p=1:length(hwall))
                                for(q=1:length(flow))
                                    V = (D(l) / 2) ^ 2 * pi / flow(q);
                                    M = flow(q) * PWATER / V * L(i);
                                    
                                    %Econs(i*j*k*l*m*n*o*p*q) = ...
                                    %    (1-Np(n))*Ein(j) + ...
                                    %    Nt(o)*Np(n)*Ein(j)*(1/Nt(o) - 1) + ...
                                    %    M(f(m)*L(i)*V^2/D(l)) + M*V^2/2*xi(k);
                                    
                                       Econs = (1-Np(n))*Ein(j) + ...
                                        Nt(o)*Np(n)*Ein(j)*(1/Nt(o) - 1) + ...
                                        M * (f(m)*L(i)*V^2/D(l)) + M*V^2/2*xi(k);
                                    
                                        if Econs < EconsMin
                                            EconsMin = Econs;
                                            vals = [L(i), time(j), xi(k), D(l), f(m), Np(n), Nt(o), hwall(p), flow(q)];
                                        end
                                        
                                        counter = counter + 1;
                                end
                            end
                        end
                    end
                end
            end
        end
    end
end
                                
                                        