float batToVel(float voltageBatt) {
    float vel = (4.3 / 3.0);
    vel = vel + (voltageBatt - 7.5)
    
    return vel;
}