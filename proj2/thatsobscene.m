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

%M = flowrate * 1000 / L;
%Econs = (1-Np)Ein + Nt*Np*Ein*(1/Nt - 1) + M(f*L*V^2/D) + M*V^2/2*xi;

V = (D / 2) ^ 2 * pi / flow;

Lz1 = sqrt(30^2 + 60^20);
Lz2 = [sqrt(100^2 + 130^2):STEP:((100 / sind(60)) + (130 - (100 / tand(60))))];
Lz3 = [sqrt(91.2^2 + 65^2):STEP:((41.2 / cosd(20) + sqrt(2) * (65 - 41.2 * tand(20))))];

time = [6:(1 / 60):12]; %keep these together!
Ein = 120 ./ time;      %keep these together!
M = flow * PWATER / V * L;

xi = [.1, .15, .2, .22, .27, .3];
D = [.1, .25, .5, .75, 1, 1.25, 1.50, 1.75, 2, 2.25, 2.5, 2.75, 3];
f = [.05, .03, .02, .01, .005, .002];
Np = [.8, .83, .86, .89, .92];
Nt = [.83, .86, .89, .92, .94];
hwall = [5:.1:20];
