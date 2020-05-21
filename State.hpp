/* Credit :  Sonarsystems  */

//This is a abstract class, for create different state of game later

#pragma once

namespace YL
{
    class State{
    public:
        virtual void Init () = 0;
        
        virtual void HandleInput () =0;
        virtual void Update (float dt)=0;
        virtual void Draw( float dt ) = 0;
        
        virtual void Pause () {}
        virtual void Resume () {}
    };
}
