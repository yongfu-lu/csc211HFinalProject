/* this file create all the constant mumber and file path we will use for the game */

#pragma once

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1124

#define SPLASH_STATE_SHOW_TIME 4.0f

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/opening.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/treebackground.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/city.jpg"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/treebackground.png"


#define PLAY_BUTTON_FILEPATH "Resources/res/startbutton.png"
#define ABOUT_BOTTON_FILEPATH "Resources/res/about.png"
#define ABOUT_WINDOW_FILEPATH "Resources/res/aboutwindow.png"

#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"
#define VIRUS_FILEPATH "Resources/res/virus.png"
#define SMALL_VIRUS_FILEPATH "Resources/res/smallvirus.png"
#define LAND_FILEPATH "Resources/res/caodi.png"
#define MASK_FILEPATH "Resources/res/mask.png"
#define BIG_MASK_FILEPATH "Resources/res/bigmask.png"
#define SANITIZER_FILEPATH "Resources/res/sanitizer.png"


#define BIRD_FRAME_1_FILEPATH "Resources/res/feiji01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/feiji02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/feiji03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/feiji04.png"
#define DEAD_BODY_FILEPATH "Resources/res/deadbody.png"

#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"

#define BRONZE_MEDAL_FILEPATH "Resources/res/danbai.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/lanbaoshi.png"
#define GOLD_MEDAL_FILEPATH "Resources/res/huangjin.png"
#define PLATINUM_MEDAL_FILEPATH "Resources/res/zuanshi.png"

#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"
#define BACK_MUSIC_FILEPATH "Resources/audio/darkmusic.ogg"
#define SANITIZER_MUSIC "Resources/audio/sanitizer.ogg"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.0f

#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f

#define FLYING_DURATION 0.25f

enum GameStates { eReady, ePlaying, eGameOver};

#define FLASH_SPEED 1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 50


