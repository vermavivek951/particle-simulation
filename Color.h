#pragma once
class Color {
    
    public:
        Uint8 red,green,blue,alpha;
        Color(Uint8 r , Uint8 g , Uint8 b , Uint8 a) {
            red = r;
            green = g;
            blue = b;
            alpha = a;
        }
};