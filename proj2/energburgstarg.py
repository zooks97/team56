from math import *

##CONSTANTS
Eout = 120 # MWh
MWH2J = 3.6e9 # J / MWh
G = 9.81 # m / s^2
P = 1000 # kg / m^3
HR2SEC = 3600 # s / hr

##float(input
Np = float(input("Pump efficiency: "))
volP = float(input("Pump flow volume (m^3/s): "))
D = float(input("Pipe diameter (m): "))
L = float(input("Pipe length (m):"))
f = float(input("Pipe friction coeff:"))
hwall = float(input("Wall height / depth of reservoir (m):"))
height = float(input("Elevation of reservoir (m):"))
K1 = float(input("Bend 1 xi: "))
K2 = float(input("Bend 2 xi: "))
Nt = float(input("Turbine efficiency: "))
volT = float(input("Turbine flow volume (m^3/s): "))
tEmpty = float(input("Time to empty (hr): "))

##CALCS
areaPipe = (D / 2)**2 * pi # m^2
velUp = volP / areaPipe # m / s
velDown = volT / areaPipe # m / s
hEff = height # m
mass = volT * tEmpty * HR2SEC * P # kg
#LOSSES
fricLoss = mass * f * L * velDown**2 / (2 * D) 
turbLoss = Eout * MWH2J * ((1 / Nt) - 1)
bendLoss = (K1 + K2) * mass * velDown**2 / 2  
pumpLoss = (mass * G * hEff + fricLoss + bendLoss) * ((1 / Np) - 1)
Eout = Eout - 2 * fricLoss - turbLoss - 2 * bendLoss - pumpLoss # J

##OUTPUTS
sa = volT * tEmpty / hwall
Ein = ((Eout / Nt) + mass * (velUp**2 + velDown**2) * (f * L / (2 * D) + (K1 + K2) / 2)) / Np
eff = Eout / Ein
tFill = volP * mass / P

print(sa ,Ein, eff, tFill)