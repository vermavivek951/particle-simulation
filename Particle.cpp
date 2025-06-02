class Particle  {
    public:
        float x , y;
        float vx , vy;
        float ax , ay;

    Particle(float x_init , float y_init , float vx_init = 0.0f , float vy_init = 0.0f)
            : x(x_init) , y(y_init) , vx(vx_init) , vy(vy_init) , ax(0) , ay(0) {}

    void update(float dt) {
        vx = vx + ax * dt;
        vy = vy + ay * dt;

        x = x + vx * dt;
        y = y + vy * dt;
        

        //reset acceleration after update(forces need to be applied each frame)
        ax = 0;
        ay = 0;
    }
        
    void applyForce(float fx , float fy) {
        ax = ax + fx;
        ay = ay + fy;
    }
};