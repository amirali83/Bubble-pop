#include <iostream>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
//#include <dos.h>
#include <conio.h>
#include <vector>
#include <bits/stdc++.h>
#include <SDL2/SDL_image.h>
#include <ctime>
#include <fstream>

using namespace std;
SDL_Color black = {0, 0, 0};
SDL_Color White = {255, 255, 255};
double shoa = 0 ;
double zaribeshoa = 0.1 , zaribeshiftesorati = 0.1;
double shiftesorati = 0 ;
SDL_Renderer *m_renderer;
SDL_Texture *background[6];
SDL_Texture *play_now_button;
SDL_Texture *setting_button;
SDL_Texture *score_bord_button;
SDL_Texture *normal_button;
SDL_Texture *unlimited_button;
SDL_Texture *time_limited_button;
SDL_Texture *enter_your_name_image;
SDL_Texture *blank_image;
SDL_Texture *next_music_image;
SDL_Texture *check_image;
SDL_Texture *no_sound_image;
SDL_Texture *sound_image;
SDL_Texture *music_image;
SDL_Texture *play_again_image;
SDL_Texture *no_music_image;
SDL_Texture *pre_music_image;
SDL_Texture *exit_image;
SDL_Texture *pause_image;
SDL_Surface* surfaceMessage;
SDL_Texture* Message;
SDL_Texture* kalesubasa;
SDL_Texture* kalekakero;
SDL_Texture* pause_icon;
SDL_Texture* resume_icon;
SDL_Texture* background_leaderboard;
SDL_Texture* third;
SDL_Texture* second;
SDL_Texture* back;
SDL_Texture* Leader_board_dakheli;
SDL_Texture* dokme_leader_board;
TTF_Font* Sans;
SDL_Surface* karbarname;
SDL_Texture* nameekarbar;
SDL_Rect namekarbar_rect;
int song_num = 0, max_song = 4;
Mix_Music *ahang[5];
Mix_Music * ahang_bord;
Mix_Music * ahang_bakht;
Mix_Chunk  * sedaye_toop;
Mix_Chunk *sedaye_terekidan;
Mix_Chunk *sedaye_enfejar;
Mix_Chunk *sedaye_laizer;
Mix_Chunk *sedaye_oftadan;
int volume = 50;

int theta;
struct coordination {
    int x;
    int y;
};

struct ballakharin{
    int color;
    int index;
    double x;
    double y;
};
struct player {
    string username;
    int timedscore;
    int normalscore;
    int infinitescore;
};

coordination atraf[6] = {{+2,0},
                         {-2,0},
                         {+1,+1},
                         {-1,+1},
                         {-1,-1},
                         {+1,-1}
};

/// variables
/// variables
int tstop;
int mode_leaderboard = -1;
int shomare_current_karbar;
int score;
int tedad_toop_terekide;
int adadepowerball=50;
int zamane_bazi = 70 ;
vector<coordination> vectorkhali , vectorezaman;
coordination colid { -1 , -1};
time_t start_time = time(NULL);
int level = 5;
bool slow_motion_effect_flag , pause_effect_flag;
double shift_az_bala = 0;
double zaribe_sorat = 1;
double slow_motion_level = 4;
double speed_shift_bala = 0.5 * zaribe_sorat * (!pause_effect_flag);
bool shft_ofoghi_radof_jadid = 0;
int grid[26][25], vasl[26][25], tedad_rang[5], grid_copy[26][25];
int rand11[6];
int W = 800; //ertefa safhe
int L = 624;//tool safhe
int mode = -1;
int n, nn, nnn, time_bazi = -1;
int t_pause;
int first_menu_bar_lenght = 400, first_menu_bar_height = 200;
int setting_bar_lenght = 500, setting_bar_height = 200 + W / 4, setting_exit_lenght = 50;
int safheye_name_karbar_length = 400 ,  safheye_name_karbar_height = 200;
double andaze_seda_ahang = 0, andaze_seda_barkhord = 5;
double xmouse_barkhord = 20 * andaze_seda_barkhord + ( L / 2 - 100), xmouse_ahang = 20 * andaze_seda_ahang + ( L / 2 - 100) , ymouse_level = W / 4 + 100 + 20 * level;
int theme = 0;
int pause_effect_start_time , slow_motion_effect_start_time;
SDL_Event e;
double xmouse = e.button.x, ymouse = e.button.y, last_xmouse;
bool flag_seda_barkhord = true, flag_seda_ahang = true, flag_in_game = false,flag_playing_ahang = true;
bool flag_menu_pause = false;
bool flag_taghiir_rang_theme_2 = true , flag_taghiir_rang_theme_4 = true ;
bool flag_control_pakhsh_music;
int r = L / 24;
double xc0 = L / 2, yc0 = W - 2 * r;
double ballx = xc0, bally = yc0 , ball2x = xc0 - r, ball2y = yc0 - r;/// bayad +r bashe y esh
double vx = 0, vy = 0, ux = 0 , uy = 0 , dx = 0 , dy = 0 , m = 0;
bool flag[26][25];
bool flag_radif_0_dafe_aval = false;
int cccc;
int dddd;
int rann , rann2;
bool running1 = true;
int x_enfejar = L / 2 - 5 * r , y_enfejar = W - 1.5 * r;
int x_lazer = x_enfejar - 2.5 * r , y_lazer = y_enfejar ;
int x_chandrang = x_lazer - 2.5 * r , y_chandrang = y_lazer;
int rangs[35][3] = {
        {255, 237, 0}, //zard
        {255, 0, 0}, //red
        {0, 0, 204}, //abi
        {0, 181, 0}, //sabz
        {128, 128, 128}, // tosi
        {50, 50, 50}, //block
        {0, 181, 0},  // khali
        {75, 0, 130},   // leizer
        {232, 105, 6}, // enfejar
        {0, 0, 0}, // chand rang
        {255, 119, 0}, //narenji = zard + red
        {128, 154, 86}, // zard + abi
        {128, 209, 0}, //zard + sabz
        {170, 164, 85}, // zard + tosi
        {128, 36, 86}, // red + abi
        {128, 91, 0}, // red + sabz
        {170, 85, 85}, // red + tosi
        {0, 126, 86}, //abi + sabz
        {85, 109, 142}, //abi + tosi
        {85, 145, 85} , //sabz + tosi
        {255, 237, 0}, //zard ( az in be bad ghofli an )
        {255, 0, 0}, //red
        {0, 0, 204}, //abi
        {0, 181, 0}, //sabz
        {128, 128, 128}, // tosi
        {255, 237, 0}, //zard
        {255, 0, 0}, //red    pause effect
        {0, 0, 204}, //abi
        {0, 181, 0}, //sabz
        {128, 128, 128}, // tosi
        {255, 237, 0}, //zard
        {255, 0, 0}, //red     slow motion
        {0, 0, 204}, //abi
        {0, 181, 0}, //sabz
        {128, 128, 128}, // tosi

};


int dorangs[11][50][3] {
/*  chandrang */       { {255, 237, 0},{255, 237, 0},  {255, 237, 0}, {255, 237, 0}, {255, 237, 0}, {255, 237, 0}, {255, 0, 0},{255, 0, 0},{255, 0, 0},{255, 0, 0},{255, 0, 0},{255, 0, 0},{255, 0, 0},{255, 0, 0},{255, 0, 0},{255, 0, 0},{255, 0, 0},{255, 0, 0}, {0, 71, 171}, {0, 71, 171},{0, 71, 171},{0, 71, 171},{0, 71, 171},{0, 71, 171},{0, 71, 171},{0, 71, 171},{0, 71, 171},{0, 71, 171},{0, 71, 171},{0, 71, 171},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{0, 181, 0},{128, 128, 128},{128, 128, 128},{128, 128, 128},{128, 128, 128},{128, 128, 128},{128, 128, 128},},
/*  red-zard */       { {255, 0 ,0} , {255, 0 ,0} , {255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} , { 204 , 0 , 0} ,{ 204 , 0 , 0} ,{ 204 , 0 , 0} ,{ 204 , 0 , 0} ,{152, 0 , 0} , {152, 0 , 0},{152, 0 , 0},{152, 0 , 0},{152, 0 , 0},{152, 0 , 0}, {100,100,0}, {100,100,0}, {100,100,0}, {100,100,0}, {100,100,0}, {100,100,0}, {153, 153,0} , {153, 153,0}, {153, 153,0}, {153, 153,0} , {204, 204 , 0} , {204, 204 , 0}, {204, 204 , 0}, {204, 204 , 0} , {255 ,255 ,  0} , {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0} , {255 ,255 ,  0}},
/*  zard-abi */       { {255,255,0},{255,255,0},{255,255,0},{255,255,0},{255,255,0},{255,255,0},{255,255,0},{255,255,0},{255,255,0},{255,255,0},{204,204,0},{204,204,0},{204,204,0},{204,204,0},{153,153,0},{153,153,0},{153,153,0},{153,153,0},{153,153,0},{153,153,0},{102,102,0},{102,102,0},{102,102,0},{102,102,0},{0 , 0, 70},{0 , 0, 70},{0 , 0, 70},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204}},
/*  zard-sabz */        { {0, 255 ,0} , {0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} , {0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{ 0 , 204 , 0} ,{ 0 , 204 , 0},{ 0 , 204 , 0},{ 0 , 204 , 0},{0, 152 , 0} ,{0, 152 , 0},{0, 152 , 0},{0, 152 , 0},{0, 152 , 0},{0, 152 , 0}, {100,100,0}, {100,100,0}, {100,100,0}, {100,100,0}, {100,100,0}, {100,100,0}, {153, 153,0} , {153, 153,0}, {153, 153,0}, {153, 153,0} , {204, 204 , 0} , {204, 204 , 0}, {204, 204 , 0}, {204, 204 , 0} , {255 ,255 ,  0} , {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0} , {255 ,255 ,  0}},
/*  zard-tosi */        {  {128,128,128} ,{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128} ,{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96} , {100,100,0}, {100,100,0}, {100,100,0}, {100,100,0}, {100,100,0}, {100,100,0}, {153, 153,0} , {153, 153,0}, {153, 153,0}, {153, 153,0} , {204, 204 , 0} , {204, 204 , 0}, {204, 204 , 0}, {204, 204 , 0} , {255 ,255 ,  0} , {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0}, {255 ,255 ,  0} , {255 ,255 ,  0}},
/*  red-abi */{ {255, 0 ,0} , {255, 0 ,0} , {255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} , { 204 , 0 , 0} ,{ 204 , 0 , 0} ,{ 204 , 0 , 0} ,{ 204 , 0 , 0} ,{152, 0 , 0} , {152, 0 , 0},{152, 0 , 0},{152, 0 , 0},{152, 0 , 0},{152, 0 , 0},{0 , 0, 70},{0 , 0, 70},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204}},
/* red-sabz */     { {255, 0 ,0} , {255, 0 ,0} , {255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} ,{255, 0 ,0} , { 204 , 0 , 0} ,{ 204 , 0 , 0} ,{ 204 , 0 , 0} ,{ 204 , 0 , 0} ,{152, 0 , 0} , {152, 0 , 0},{152, 0 , 0},{152, 0 , 0},{152, 0 , 0},{152, 0 , 0},{0 , 152 , 0},{0 , 152 , 0},{0 , 152 , 0},{0 , 152 , 0},{0 , 152 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0}  ,{0,255,0},{0,255,0} },
/*  red-tosi  */    {  {128,128,128} ,{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128} ,{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96} , {152 , 0 , 0}, {152 , 0 , 0}, {152 , 0 , 0}, {152 , 0 , 0}, {152 , 0 , 0}, {152 , 0 , 0},{204,0,0},{204,0,0},{204,0,0},{204,0,0},{204,0,0},{204,0,0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0},{255,0, 0}},
/*  abi-sabz  */       { {0, 255 ,0} , {0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} , {0, 255 ,0} ,{0, 255 ,0} ,{0, 255 ,0} ,{ 0 , 204 , 0} ,{ 0 , 204 , 0},{ 0 , 204 , 0},{ 0 , 204 , 0},{0, 152 , 0} ,{0, 152 , 0},{0, 152 , 0},{0, 152 , 0},{0, 152 , 0},{0, 152 , 0}, {0 , 0, 70},{0 , 0, 70},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204}},
/*  abi-tosi  */    {{128,128,128} ,{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128} ,{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96} , {0 , 0, 70},{0 , 0, 70},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{ 0 , 0 , 102},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0 ,0 , 153},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204},{0,0,204}},
/*  sabz-tosi  */    {{128,128,128} ,{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128} ,{128,128,128},{128,128,128},{128,128,128},{128,128,128},{128,128,128},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96},{96,96,96} ,{0 , 152 , 0},{0 , 152 , 0},{0 , 152 , 0},{0 , 152 , 0},{0 , 152 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0, 204 , 0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0}  ,{0,255,0},{0,255,0} }
};
double zaribeandisrang[11] = {0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2};
double andisrangs[11];
vector <coordination> lazervec;
vector <int> zaribelazervec;
double khoshgelli[11] = {  5 , 4 , 3 , 2 , 1 , 0 , 1 , 2 , 3 , 4 , 5};
/// functions
void effect_haye_bade_barkhord ();
void ghalat_kardam ( int &i , int k);
bool atraf_check(int &i , int j ,  int k);
void image(SDL_Texture *text, int x, int y, int w, int h, double alfa);
void mohasebescore();
void printscore();
bool colors_are_same(int a, int b);
int x_j(int x) ;
int j_x(int j) ;
int y_i(int y) ;
int i_y(int i) ;
void sadekon ( int i );
void generateballyekradif(int y);
void generatelines(int n);
void timeeffect ();
void print() ;
void generate_rann( int &rann , int & rann2);
bool iscolided(double x1, double y1, int j , int i);
void makelist(int i, int j) ;
void check_vasl(int i, int j);
void terekidananimaion(int i , int j);
void oftadananimation(int i ) ;
void enfejaranimation(coordination ja[] , int c);
void preenfejaranimation ();
void enfejar (int i, int j, int n) ;
void pakkon(int i, int j);
void line_komaki() ;
void draw_changeball(int rann , int R , double ballxx , double ballyy );
void controleandis ( int rann);
void shift_radifha();
void generate_redif_jadid(int i);
void drawtoop_general ( int xt , int yt , int rt , int rang_t , int alpha_t);
coordination is_colided_general(double x, double y);
void shiftcheck ();
bool tedad_rang_check (int kk);///////////////////////////////////// bayad neveshte beshe


bool click_in_circle ( int xshape , int yshape , int rshape);
void changeball_with_click ( int rang_b , int xshape , int yshape , int rshape , bool halat );
bool click_in(int xshape, int yshape, int tool, int ertefa);
bool click_keshidan(int xshape, int yshape, int tool, int ertefa);
void set_window_color(int R, int G, int B) ;
void rect(float x, float y,float w,float h,int R, int G, int B, int fill_boolian );
int screen_name();
void menu_play();
void menu_leaderbord();
vector<player> create_vec_timed ();
vector<player> create_vec_normal ();
vector<player> create_vec_infinite ();
void menu_namayeshe_leaderboard();
void menu_jadval();
void menu_setting();
void screen_gameover();
void menu_bord_game();
void menu_tamam_game();
void first_menu();
void menu_pause();
void printtime();
void drawpaein ();
coordination yaftemakan ( coordination colision );
string readNthValue(const string &filePath, int n);
bool searchStringInCSV(const string &filename, const string &target);
void replaceNthStringInCSV(const string &filePath, int n, const string &replacement);
int findIndexInCSV(const string &filePath, const string &targetString);
int main(int argc, char *argv[]) {
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window *m_window;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen res olution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_VolumeMusic(andaze_seda_ahang);
    sedaye_toop = Mix_LoadWAV("Sobasa shoot.wav");
    sedaye_terekidan = Mix_LoadWAV("cartoon-sound-fx-effect-shot.wav");
    sedaye_enfejar = Mix_LoadWAV("big_explosion_sfx_1.WAV");
//    sedaye_laizer = Mix_LoadWAV("cartoon-sound-fx-effect-shot.wav");
    sedaye_oftadan = Mix_LoadWAV("falling-snare.wav");


    Mix_VolumeChunk(sedaye_toop , andaze_seda_barkhord);
    Mix_VolumeChunk(sedaye_terekidan , andaze_seda_barkhord);
    Mix_VolumeChunk(sedaye_enfejar , andaze_seda_barkhord);
//    Mix_VolumeChunk(sedaye_laizer, andaze_seda_barkhord);
    Mix_VolumeChunk(sedaye_oftadan, andaze_seda_barkhord);

    ahang[0] = Mix_LoadMUS("sobasa.mp3");
    ahang[1] = Mix_LoadMUS("April Rain - Sleeping Beauty Syndrome.mp3");
    ahang[2] = Mix_LoadMUS("1_1 - Polish Cow - D orange Verte (320).mp3");
    ahang[3] = Mix_LoadMUS("Man Sag Mikham.mp3");
    ahang[4] = Mix_LoadMUS("Maco Mamuko - Tequila.mp3");


//    level = 3;

    ahang_bord = Mix_LoadMUS("bord.mp3");
    ahang_bakht = Mix_LoadMUS("bakht.mp3");

    TTF_Init();
    Sans = TTF_OpenFont("arial.ttf", 100);

    play_now_button = IMG_LoadTexture(m_renderer , "play now.png");
    setting_button = IMG_LoadTexture(m_renderer , "setting.png");
    score_bord_button = IMG_LoadTexture(m_renderer , "score bord.png");
    normal_button = IMG_LoadTexture(m_renderer , "normal.png");
    unlimited_button = IMG_LoadTexture(m_renderer , "unlimited.png");
    time_limited_button = IMG_LoadTexture(m_renderer , "time limited.png");
    enter_your_name_image = IMG_LoadTexture(m_renderer , "enter your name.png");
    blank_image = IMG_LoadTexture(m_renderer, "blank.png");
    next_music_image = IMG_LoadTexture(m_renderer, "nextmusic.png");
    check_image = IMG_LoadTexture(m_renderer, "check.png");
    no_sound_image = IMG_LoadTexture(m_renderer, "nosound.png");
    sound_image = IMG_LoadTexture(m_renderer, "sound.png");
    music_image = IMG_LoadTexture(m_renderer, "music.png");
    play_again_image = IMG_LoadTexture(m_renderer, "play again.png");
    no_music_image = IMG_LoadTexture(m_renderer, "nomusic.png");
    pre_music_image = IMG_LoadTexture(m_renderer, "premusic.png");
    exit_image = IMG_LoadTexture(m_renderer, "exit.png");
    pause_image = IMG_LoadTexture(m_renderer, "pause.png");
    background[0] = IMG_LoadTexture(m_renderer , "mabe background.png");
    background[1] = IMG_LoadTexture(m_renderer , "theme1.png");
    background[2] = IMG_LoadTexture(m_renderer , "theme2.png");
    background[3] = IMG_LoadTexture(m_renderer , "theme3.png");
    background[4] = IMG_LoadTexture(m_renderer , "theme4.png");
    background[5] = IMG_LoadTexture(m_renderer , "back asli 1.png");
    kalesubasa = IMG_LoadTexture(m_renderer , "kalesubasa.png");
    kalekakero = IMG_LoadTexture(m_renderer , "kalekakero.png");
    pause_icon = IMG_LoadTexture(m_renderer , "pause icon.png");
    resume_icon = IMG_LoadTexture(m_renderer , "resume icon.png");
    background_leaderboard = IMG_LoadTexture(m_renderer , "background leader board.jpg");
    third = IMG_LoadTexture(m_renderer , "third.png");
    second = IMG_LoadTexture(m_renderer , "second.png");
    back = IMG_LoadTexture(m_renderer , "back .png");
    Leader_board_dakheli = IMG_LoadTexture(m_renderer , "Leader board dakheli.png");
    dokme_leader_board = IMG_LoadTexture(m_renderer , "dokme leader board.png");

    srand(time(NULL));
    bool flagg = false;
    coordination mahalle_barkhorde_noghtechin;
    flag_control_pakhsh_music = true;
//flag_seda_ahang = true;
    while (running1) {
//        if (flag_seda_ahang)
//            Mix_PlayMusic(ahang[song_num], -1);

//        if ( flag_in_game /*&& flag_control_pakhsh_music*/ )
//        {
        if (flag_control_pakhsh_music && flag_playing_ahang)
        {
            flag_control_pakhsh_music = false;
//                flag_control_pakhsh_music = false;
            Mix_PlayMusic(ahang[song_num] , -1);
        }
//        }
        image( background[theme] , 0 , 0 , L , W , 0 );
        shift_az_bala = 0 ;
        shft_ofoghi_radof_jadid = 0 ;
        ballx = xc0;
        bally = yc0;
        flagg = false;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                SDL_DestroyWindow( m_window );
                SDL_DestroyRenderer( m_renderer );
                SDL_Quit();
                running1 = false;
            }
        }

        SDL_ShowCursor(SDL_ENABLE);
        xmouse = e.button.x; ymouse = e.button.y;

        if (!flag_in_game) {

            first_menu();

        }

        else {

            cout << "injam" << endl;  /// inja miad
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 25; j++)
                    grid[i][j] = -1;

            generatelines(n);
            rann = rand() % 5;
            rann2 = rand() % 5;
            ///// fek konam in eshkal dare;
//            while (tedad_rang[rann] == 0)
//                rann = rand() % 5;
//
//            while (tedad_rang[rann2] == 0)
//                rann2 = rand() % 5;

            shft_ofoghi_radof_jadid = 1;
            cout << "man hanooz zendam" << endl;
            generate_redif_jadid(0);
            generate_redif_jadid(25);

            rann = 8;/////////////////////////////////////////////////////////////////////////////////////////////////
            //rann2 = 7 ;////////////////////////////////////////////////////////////////////////////////////////////////
            print();
            flagg = false;
            coordination colision;

            if (time_bazi != -1) {
                start_time = time(NULL);
                cout << "time doroste" << endl;
            }
//            flag_control_pakhsh_music = true;
            bool running = true;
            tedad_rang[1] = 1;
//            ***********************************************       running        ***************************************************
            while(running) {


                if( mode != 2)
                    speed_shift_bala = 0.5 * zaribe_sorat * (!pause_effect_flag);
                else
                    speed_shift_bala = 0.1 * zaribe_sorat * (!pause_effect_flag);


                speed_shift_bala = 0.5 * zaribe_sorat * (!pause_effect_flag);
                if(pause_effect_flag)
                    if (pause_effect_start_time + 8 <= time(NULL))
                    {
                        start_time = time(NULL) - t_pause;
                        pause_effect_flag = false;
                    }
                if(slow_motion_effect_flag)
                    if ( slow_motion_effect_start_time + 8 <= time(NULL))
                    {
                        slow_motion_effect_flag = false;
                        zaribe_sorat *= slow_motion_level;
                    }
//                if (time(NULL) - start_time >= time_bazi && time_bazi != -1) {
//                    cout << "time finished \n";
//                    running = false;
//                    flag_in_game = false;
//                    menu_tamam_game();
//                }

                if ( !((time(NULL) - start_time) % 10) && theme == 2)
                    flag_taghiir_rang_theme_2 = true;
                if ( !((time(NULL) - start_time) % 10) && theme == 4)
                    flag_taghiir_rang_theme_4 = true;








                drawtoop_general(ballx , bally, r , rann , 255 );
                drawtoop_general(ball2x , ball2y , r/2 , rann2 , 255);

                if (nn > 0 || nn == -1) {
                    shiftcheck();
                    if (nn == 0) {
                        if ((n + nnn) % 2 == 1)
                            for (int i = 2; i < 25; i += 2)
                                grid[0][i] = 6;
                        else
                            for (int i = 1; i < 25; i += 2)
                                grid[0][i] = 6;
                    }
                }
//                cout << shomare_current_karbar;
                changeball_with_click ( 8 , x_enfejar , y_enfejar , r , false);
                changeball_with_click ( 7 , x_lazer , y_lazer , r , false);
                changeball_with_click(9 , x_chandrang , y_chandrang , r, false);


                menu_pause();
                SDL_RenderPresent(m_renderer);
//***************************************        mogheye partab      **************************************************************
                while (flagg == false) {


                    speed_shift_bala = 0.5 * zaribe_sorat * (!pause_effect_flag);
                    if(pause_effect_flag)
                        if (pause_effect_start_time + 8 <= time(NULL))
                        {
                            start_time = time(NULL) - t_pause;
                            pause_effect_flag = false;
                        }
                    if(slow_motion_effect_flag)
                        if ( slow_motion_effect_start_time + 8 <= time(NULL))
                        {
                            slow_motion_effect_flag = false;
                            zaribe_sorat *= slow_motion_level;
                        }

//                    if (time(NULL) - start_time >= time_bazi && time_bazi != -1) {
//                        cout << "time finished \n";
//                        running = false;
//                        flag_in_game = false;
//                        menu_tamam_game();
//                    }

                    if ( !((time(NULL) - start_time) % 10) && theme == 2)
                        flag_taghiir_rang_theme_2 = true;
                    if ( !((time(NULL) - start_time) % 10) && theme == 4)
                        flag_taghiir_rang_theme_4 = true;

                    if ( zamane_bazi - (time(NULL) - start_time) <= 0 && time_bazi != -1 )
                    {
                        cout << "game over" << endl;
                        cout << "time finished \n";
                        running = false;
                        flag_in_game = false;
//                        Mix_FreeMusic(ahang[song_num]);
                        Mix_PlayMusic(ahang_bakht , 1);
                        screen_gameover();
//                        Mix_FreeMusic(ahang_bakht);
                    }



                    for (int j = 1; j < 24; j++)
                        if (grid[16][j] != -1) {
                            cout << "game over" << endl;
                            screen_gameover();
                            running = false;
                            flagg = true;
                            break;
                        }

                    if (nn > 0 || nn == -1) {
                        shiftcheck();
                        if (nn == 0) {
                            if ((n + nnn) % 2 == 1)
                                for (int i = 2; i < 25; i += 2)
                                    grid[0][i] = 6;
                            else
                                for (int i = 1; i < 25; i += 2)
                                    grid[0][i] = 6;
                        }
                    }



                    SDL_PollEvent(&e);
                    SDL_ShowCursor(SDL_ENABLE);

                    if (e.type == SDL_QUIT) {
                        SDL_DestroyWindow(m_window);
                        SDL_DestroyRenderer(m_renderer);
                        SDL_Quit();
                        running = false;
                        flagg = true;
                    }
                    if (e.type == SDL_KEYDOWN) {
                        if (e.key.keysym.sym == ' ' &&  rann != 7 && rann != 8 && rann != 9) {
                            swap(rann,rann2);
                            drawtoop_general(ballx , bally , r , rann , 255);
                            drawtoop_general(ball2x , ball2y , r/2 , rann2 , 255);
                        }
                        else if ( e.key.keysym.sym == 27) {
                            SDL_DestroyWindow(m_window);
                            SDL_DestroyRenderer(m_renderer);
                            SDL_Quit();
                            running = false;
                            flagg = true;
                        }
                    }

                    double xmouse = e.button.x, ymouse = e.button.y;
                    image(background[theme] ,0 , 0 , L , W , 0 );
                    changeball_with_click ( 8 , x_enfejar , y_enfejar , r , true);
                    changeball_with_click ( 7 , x_lazer , y_lazer , r , true);
                    changeball_with_click(9 , x_chandrang , y_chandrang , r, true);
                    print();
                    printscore();
                    if (mode == 1)
                        printtime();
                    drawtoop_general(ballx , bally, r , rann , 255 );
                    drawtoop_general(ball2x , ball2y , r/2 , rann2 , 255);
                    if ( ymouse <  y_enfejar - 1.5 * r) {
                        theta = atan((xmouse - xc0) / (-ymouse + yc0)) * 180 / 3.1415;

                        uy = 5 * (ymouse - yc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
                        ux = 5 * (xmouse - xc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
                    }
                    if( theme == 0 || theme == 2  || theme == 4)
                        image(kalesubasa , xc0 - 2 * r - 2 * r * ux , yc0 - 2 * r - 2 * r * uy , 4 * r , 4 * r , theta);
                    if (theme == 1 || theme == 3  )
                        image(kalekakero , xc0 - 1.5 * r -  r * ux , yc0 - 1.5 * r - r * uy , 3 * r , 3 * r , theta);
                    dx = xc0 + r * ux / sqrt(ux * ux + uy * uy);
                    dy = yc0 + r * uy / sqrt(ux * ux + uy * uy);
                    colid.x = is_colided_general(dx, dy).x;
                    m = 0;
                    while (colid.x == -1 && dy > 0 && dy < W && (ux != 0 || uy != 0)  && ymouse <  y_enfejar - 1.5 * r  &&  (-ymouse + yc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse) >= (sqrt(6) - sqrt(2) )/ 4 )) {
                        if (m >= 3) {
//                            shoa += 3.141516/3;
                            shoa += 0.4;
                            if ( shoa + shiftesorati  >= 10){
//                                           shoa += shiftesorati;
                                shoa = 0 - shiftesorati;
                            }

                            if ( rann == 9 )
                            {
//                                pixelRGBA(m_renderer, dx, dy,  dorangs[rann - 9][int (andisrangs[rann - 9])][0],dorangs[rann - 9][int(andisrangs[rann - 9])][1], dorangs[rann - 9][int(andisrangs[rann - 9])][2],255);
//                                pixelRGBA(m_renderer, dx, dy + 1,  dorangs[rann - 9][int (andisrangs[rann - 9])][0],dorangs[rann - 9][int(andisrangs[rann - 9])][1], dorangs[rann - 9][int(andisrangs[rann - 9])][2],255);
//                                pixelRGBA(m_renderer, dx + 1, dy,  dorangs[rann - 9][int (andisrangs[rann - 9])][0],dorangs[rann - 9][int(andisrangs[rann - 9])][1], dorangs[rann - 9][int(andisrangs[rann - 9])][2],255);
//                                pixelRGBA(m_renderer, dx + 1, dy + 1,  dorangs[rann - 9][int (andisrangs[rann - 9])][0],dorangs[rann - 9][int(andisrangs[rann - 9])][1], dorangs[rann - 9][int(andisrangs[rann - 9])][2],255);
                                filledCircleRGBA( m_renderer , dx , dy , khoshgelli[int (shoa + shiftesorati)], dorangs[rann - 9][int (andisrangs[rann - 9])][0],dorangs[rann - 9][int(andisrangs[rann - 9])][1], dorangs[rann - 9][int(andisrangs[rann - 9])][2],255);
                            }
                            else {
//                                pixelRGBA(m_renderer, dx, dy, rangs[rann][0], rangs[rann][1], rangs[rann][2], 255);
//                                pixelRGBA(m_renderer, dx, dy + 1, rangs[rann][0], rangs[rann][1], rangs[rann][2], 255);
//                                pixelRGBA(m_renderer, dx + 1, dy, rangs[rann][0], rangs[rann][1], rangs[rann][2], 255);
//                                pixelRGBA(m_renderer, dx + 1, dy + 1, rangs[rann][0], rangs[rann][1], rangs[rann][2],
//                                          255);
                                filledCircleRGBA( m_renderer , dx , dy , khoshgelli[int (shoa + shiftesorati)], rangs[rann][0], rangs[rann][1], rangs[rann][2], 255);




///                                   shoa += 0.31415;
//                                    shoa += zaribeshoa;
//                                    if ( shoa >= 5 || shoa<= 0)
//                                    {
//                                        zaribeshoa *= -1;
//                                        shoa += zaribeshoa;
//                                    }
                            }
                            m = 0;
                        }

                        m++;
                        dx += ux;
                        dy += uy;
                        if (dx <= r || dx >= L - r) {
                            if (rann != 7)
                                ux *= -1;
                            else
                                ux = uy = 0;
                        }
                        colid = is_colided_general(dx, dy);
                        if ( colid.x != -1)
                        {
                            uy = (ymouse - yc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
                            ux = (xmouse - xc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
                        }
                    }
                    menu_pause();
                    if ( rann == 8 ) {
                        mahalle_barkhorde_noghtechin = yaftemakan(colid);
                        enfejar(mahalle_barkhorde_noghtechin.y, mahalle_barkhorde_noghtechin.x, 2);
                        preenfejaranimation();
                    }
//                    shiftesorati-=0.1;
//                    shoa = 0 ;
//                    if ( shiftesorati <= -1.57)
//                        shiftesorati = 1.57;

                    SDL_Delay(3);
                    shiftesorati += 0.1;
                    shoa = 0 ;
                    if (shiftesorati >= 10)
                        shiftesorati = 0 ;
//                    if (shiftesorati + shoa >= 10)
//                    {
////                        zaribeshiftesorati = !(zaribeshiftesorati) / 10;
//                        shoa = 0 - shiftesorati;
//                    }
//                    shoa = zaribeshiftesorati * 50;



//                    shiftesorati += zaribeshiftesorati;
//                    shoa = 0 ;
//                    if  ( shiftesorati >= 4 || shiftesorati <=0)
//                    {
//                        zaribeshiftesorati *= -1;
//                        shiftesorati += zaribeshiftesorati;
//                    }
                    SDL_RenderPresent(m_renderer);

//                    filledCircleRGBA(m_renderer, ball2x, ball2y, r / 2, rangs[rann2][0], rangs[rann2][1],
//                                     rangs[rann2][2], 255);
                    if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN  &&  ymouse <  y_enfejar - 1.5 * r  &&  (-ymouse + yc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse) >= (sqrt(6) - sqrt(2) )/ 4 )) {
                        flagg = true;
                        vy = 10 * (ymouse - yc0) /
                             sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
                        vx = 10 * (xmouse - xc0) /
                             sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
//                        if ( rann  != 7)
                            int channel = Mix_PlayChannel(-1,sedaye_toop,0);
//                        else
//                            int channel = Mix_PlayChannel(-1,sedaye_laizer,0);

                    }
//                    }
                }
                if (!running)
                    break;
//        filledCircleRGBA(m_renderer, ballx, bally, r, 0, 0,0, 255);
                SDL_Delay(1);
                if (flag_menu_pause) {
                    vx = vy = 0;
                    SDL_Delay(500);
                    flagg = false;
                    flag_menu_pause = false;
                }
                ballx += vx;
                bally += vy;

                if ((ballx >= L - r || ballx <= r) && rann != 7)
                    vx *= -1;
                if (bally <= r && rann != 7)
                    vx = vy = 0;

                colision = is_colided_general(ballx, bally);



                //************************************************  lazer   **********************************************************
                timeeffect();

                if ( rann == 7 && colision.x != -1 && colision.y != -1 && colision.y != 0)
                {

                    lazervec.push_back(colision);
                    tedad_toop_terekide++;
                    mohasebescore();
//                    if ( grid[colision.y][colision.x] <5)
//                        tedad_rang[grid[colision.y][colision.x]]--;
                    if ( grid[colision.y][colision.x] >= 25 && grid[colision.y][colision.x] < 30)
                    {
                        if(pause_effect_flag)
                        {
                            t_pause = time(NULL) - start_time;
                            pause_effect_start_time = time(NULL);
                        }
                        else
                        {
                            pause_effect_flag = true;
                            t_pause = time(NULL) - start_time;
                            pause_effect_start_time = time(NULL);
                        }

                    }
                    if ( grid[colision.y][colision.x] >= 30 && grid[colision.y][colision.x] < 35 ) {
                        if (slow_motion_effect_flag) {
                            slow_motion_effect_start_time = time(NULL);
                        } else {
                            slow_motion_effect_flag = true;
                            slow_motion_effect_start_time = time(NULL);
                            zaribe_sorat /= slow_motion_level;
                        }
                    }

                    grid[colision.y][colision.x] = -1;

                    zaribelazervec.push_back(255);
                }

                else if ( colision.x != -1 && colision.y != -1 && rann != 7) {
                    vx = vy = 0;

                    coordination minn = yaftemakan(colision);

                    grid[minn.y][minn.x] = rann;
//                    if (rann < 5)
//                        tedad_rang[rann]++;

                    pakkon(minn.y, minn.x);
                    ballx = xc0;
                    bally = yc0;
                    flagg = false;
                    effect_haye_bade_barkhord();
                    generate_rann(rann, rann2);
                    rann2 = rand() % 100;
                    generate_rann(rann2, rann2);
//                    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
//                    SDL_RenderClear(m_renderer);
//            print();
                }
                image( background[theme] , 0 , 0 , L , W , 0 );
                print();
                bool flag_bord_bazi = true;
                for (int j = 0; j < 25; j++) {
                    if (grid[1][j] != -1 && grid[1][j] != 5)
                        flag_bord_bazi = false;
                }
                if (flag_bord_bazi) {
                    cout << "bordi";
//                    Mix_CloseAudio();
//                    Mix_FreeMusic(ahang[song_num]);
                    Mix_PlayMusic(ahang_bord , 1);
                    menu_bord_game();
//                    Mix_FreeMusic(ahang_bord);
                    flag_in_game = false;
                    running = false;
                }

                if (((ballx > L + 2 * r || ballx < -2 * r || bally <= r)) && rann == 7 )
                {

//                        pakkon(mini, minj);
                    ballx = xc0;
                    bally = yc0;
                    flagg = false;
                    effect_haye_bade_barkhord();
                    generate_rann(rann, rann2);
                    rann2 = rand() % 100;
                    static int rannd2 = rann2;
                    generate_rann(rann2, rannd2);
                    pakkon(20, 4);
                    image(background[theme], 0 , 0 , L , W , 0);

                    print();
                }


                for (int j = 1; j < 24; j++)
                    if (grid[16][j] != -1) {
                        cout << "game over mother fucker" << endl;
                        running = false;
                        flag_in_game = false;
//                        Mix_FreeMusic(ahang[song_num]);
                        Mix_PlayMusic(ahang_bakht , 1);
                        screen_gameover();
//                        Mix_FreeMusic(ahang_bakht);
                    }

                if ( zamane_bazi - (time(NULL) - start_time) <= 0 && time_bazi != -1 )
                {
                    cout << "game over mother fucker" << endl;
                    cout << "time finished \n";
                    running = false;
                    flag_in_game = false;
//                    Mix_FreeMusic(ahang[song_num]);
                    Mix_PlayMusic(ahang_bakht , 1);
                    screen_gameover();
//                    Mix_FreeMusic(ahang_bakht);
                }

//        SDL_Delay(1);

                printscore();
                if ( mode == 1)
                    printtime();
                /// chape score;
                double xmouse = e.button.x, ymouse = e.button.y;
                if ( ymouse <  y_enfejar - 1.5 * r)
                    theta = atan ( (xmouse - xc0) / (-ymouse + yc0) ) * 180 / 3.1415;
                if (xmouse || ymouse) {
                    uy = (ymouse - yc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
                    ux = (xmouse - xc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
                }
                if( theme == 0 || theme == 2  || theme == 4)
                    image(kalesubasa , xc0 - 2 * r , yc0 - 2 * r , 4 * r , 4 * r , theta);
                if( theme == 1 || theme == 3)
                    image(kalekakero , xc0 - 1.5 * r , yc0 - 1.5 * r , 3 * r , 3 * r , theta);

            }

        }

    }
}


void drawpaein ()
{
    mohasebescore();
//    image(background[theme] ,0 , 0 , L , W , 0 );
    if ( mode == 1)
        printtime();
    printscore();
//    double xmouse = e.button.x, ymouse = e.button.y;
    changeball_with_click ( 8 , x_enfejar , y_enfejar , r , true);
    changeball_with_click ( 7 , x_lazer , y_lazer , r , true);
    changeball_with_click(9 , x_chandrang , y_chandrang , r, true);
    drawtoop_general(ball2x , ball2y , r/2 , rann2 , 255);
    if ( ymouse <  y_enfejar - 1.5 * r) {
        theta = atan((xmouse - xc0) / (-ymouse + yc0)) * 180 / 3.1415;

        uy = (ymouse - yc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
        ux = (xmouse - xc0) / sqrt((yc0 - ymouse) * (yc0 - ymouse) + (xc0 - xmouse) * (xc0 - xmouse));
    }
    if( theme == 0 || theme == 2  || theme == 4)
        image(kalesubasa , xc0 - 2 * r - 2 * r * ux , yc0 - 2 * r - 2 * r * uy , 4 * r , 4 * r , theta);
    if (theme == 1 || theme == 3  )
        image(kalekakero , xc0 - 1.5 * r -  r * ux , yc0 - 1.5 * r - r * uy , 3 * r , 3 * r , theta);

}

void printtime()
{

    string a = to_string(zamane_bazi - (time(NULL) - start_time));
    surfaceMessage = TTF_RenderText_Solid(Sans, a.c_str(), black);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = L - 3 * r;  //controls the rect's x coordinate
    Message_rect.y = yc0 - 1.5 * r  ; // controls the rect's y coordinte
    Message_rect.w = r * a.length() / 2; // controls the width of the rect
    Message_rect.h = r; // controls the height of the rect
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);

}
void mohasebescore()
{
    if ( mode == 2)
        score = tedad_toop_terekide * 10000 / (100);
    if ( mode == 1 || mode == 0 )
        score = tedad_toop_terekide * 10000 / (60 + time(NULL) - start_time);

}
void printscore()
{

    string a = to_string(score);
    surfaceMessage = TTF_RenderText_Solid(Sans, to_string(score).c_str(), White);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = xc0 + 2 * r;  //controls the rect's x coordinate
    Message_rect.y = yc0 - r / 2 ; // controls the rect's y coordinte
    Message_rect.w = r * a.length(); // controls the width of the rect
    Message_rect.h = r; // controls the height of the rect
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);
}

bool colors_are_same(int a, int b) {

//    if (a >= 20 && a<=24)
//        a %= 20;
//    if (b >= 20 && b<=24 )//&& b % 20 == a ye hamchin chizi inja mikhad fek konam  ,,,, alanam to reshte 2 taii bashe mitereke
//        b %= 20;

    if ( a >= 20 )
        return colors_are_same ( a % 5 , b);
    if ( b>=20)
        return colors_are_same( a , b % 5);

    if (a == -1 || b == -1)
        return false;

    if (a == b || (a == 9 && b != 5)|| (b == 9 && a != 5) )
        return true;


    if ((a == 10 || b == 10) && (a == 0 || b == 0 || a == 1 || b == 1)) return true;
    if ((a == 11 || b == 11) && (a == 0 || b == 0 || a == 2 || b == 2)) return true;
    if ((a == 12 || b == 12) && (a == 0 || b == 0 || a == 3 || b == 3)) return true;
    if ((a == 13 || b == 13) && (a == 0 || b == 0 || a == 4 || b == 4)) return true;
    if ((a == 14 || b == 14) && (a == 2 || b == 2 || a == 1 || b == 1)) return true;
    if ((a == 15 || b == 15) && (a == 3 || b == 3 || a == 1 || b == 1)) return true;
    if ((a == 16 || b == 16) && (a == 4 || b == 4 || a == 1 || b == 1)) return true;
    if ((a == 17 || b == 17) && (a == 3 || b == 3 || a == 2 || b == 2)) return true;
    if ((a == 18 || b == 18) && (a == 4 || b == 4 || a == 2 || b == 2)) return true;
    if ((a == 19 || b == 19) && (a == 4 || b == 4 || a == 3 || b == 3)) return true;
    return false;
}

int x_j(int x) {
    return (x - r) / (r) + 1;
}

int j_x(int j) {
    return (j - 1) * r + r;
}

int y_i(int y) {
    if (y < r -2 * (sqrt(3) * r) + shift_az_bala )
        return 25;
    return (y - r - shift_az_bala) / (sqrt(3) * r) + 1;
}

int i_y(int i) {
    if (i == 25)
        return (-1-1)*(sqrt(3) * r) + r + shift_az_bala;
    return (i - 1) * (sqrt(3) * r) + r + shift_az_bala;
}

void sadekon ( int i )
{
    int randomm;
    bool checkk;
    if (i == 25) {
        for (int j = 1; j < 24; j++) {
            randomm = rand() % 4;
            if ( randomm == 0 && j + 2 < 24)
            {
                if ( (grid[25][j] != -1 && grid[25][j] != 6 && grid[25][j] != 5 && grid[25][j + 2] != 5 && grid[25][j + 2] != -1 && grid[25][j + 2] != 6))
                {
                    grid[25][j] = grid[25][j + 2] % 5;
                }
            }

            if ( randomm == 1 && j - 2 >= 0)
            {
                if ( (grid[25][j] != -1 && grid[25][j] != 6 && grid[25][j] != 5 && grid[25][j - 2] != 5 && grid[25][j - 2] != -1 && grid[25][j - 2] != 6))
                {
                    grid[25][j] = grid[25][j - 2] % 5;
                }
            }

            if ( randomm == 2 && j + 1 < 24)
            {
                if ( (grid[25][j] != -1 && grid[25][j] != 6 && grid[25][j] != 5 && grid[0][j + 1] != 5 && grid[0][j + 1] != -1 && grid[0][j + 1] != 6))
                {
                    grid[25][j] = grid[0][j + 1] % 5;
                }
            }
            if ( randomm == 3 && j - 1 > 0)
            {
                if ( (grid[25][j] != -1 && grid[25][j] != 6 && grid[25][j] != 5 && grid[0][j - 1] != 5 && grid[0][j - 1] != -1 && grid[0][j - 1] != 6))
                {
                    grid[25][j] = grid[0][j - 1] % 5;
                }
            }
//            if (checkk) {
//                if (grid[i][j] != -1 && grid[i][j] != 6 && grid[i][j] != 5 &&
//                    grid[i + atraf[randomm].y][j + atraf[randomm].x] != 5 &&
//                    grid[i + atraf[randomm].y][j + atraf[randomm].x] != -1 &&
//                    grid[i + atraf[randomm].y][j + atraf[randomm].x] != 6) {
//                    grid[i][j] = grid[i + atraf[randomm].y][j + atraf[randomm].x];
//                }
//            }
//            ghalat_kardam(i, randomm);
        }
        return;
    }
//    if (i >= 23)///  alaki
//        i = -1;
    else {
        srand(time(NULL));
        for (int j = 0; j < 24; j++) {
            randomm = rand() % 6;
            checkk = atraf_check(i, j, randomm);
            if (checkk) {
                if (grid[i][j] != -1 && grid[i][j] != 6 && grid[i][j] != 5 &&
                    grid[i + atraf[randomm].y][j + atraf[randomm].x] != 5 &&
                    grid[i + atraf[randomm].y][j + atraf[randomm].x] != -1 &&
                    grid[i + atraf[randomm].y][j + atraf[randomm].x] != 6) {
                    grid[i][j] = grid[i + atraf[randomm].y][j + atraf[randomm].x] % 5;
                }
            }
            ghalat_kardam(i, randomm);
        }
    }
    return;
}

void generateballyekradif(int y) {
    int rnd;
    for (int i = 1; i + shft_ofoghi_radof_jadid < 24 ; i += 2) {
        rnd = rand () % 300;
        if ( rnd >= 50 && rnd <= 64)
            rnd = rnd - 40;
        else {
            if (rnd % 24 == 0)
                rnd = 5;
            else
                rnd %= 5;
        }

        grid[y][i + shft_ofoghi_radof_jadid] = rnd;
//        tedad_rang[rnd]++;
    }
    shft_ofoghi_radof_jadid = !shft_ofoghi_radof_jadid;

    for ( int l = 0 ; l < (level * 2) ; l ++)
    {
        sadekon(y);
    }

}

void generatelines(int n) {
    for (int i = 1; i <= n; i++)
        generateballyekradif(i);
}

void timeeffect ()
{
    if (!(( time(NULL) - start_time) % 6))
    {
        for ( int k = 0 ; k < vectorezaman.size() ; k ++)
        {
            if ( grid[vectorezaman[k].y][vectorezaman[k].x] >= 30)
                grid[vectorezaman[k].y][vectorezaman[k].x] -= 30;
            else if (grid[vectorezaman[k].y][vectorezaman[k].x] >= 25)
                grid[vectorezaman[k].y][vectorezaman[k].x]-=25;
        }
        srand(time(NULL));
        vectorezaman.clear();
        int randi = rand() % 16;
        int randj = rand() & 24;
        if ( grid[randi][randj] >= 0 && grid[randi][randj] <= 4 )
        {
            grid[randi][randj] += 25;
            vectorezaman.push_back({randj , randi});
        }
        randi = rand() % 16;
        randj = rand() & 24;
        if ( grid[randi][randj] >= 0 && grid[randi][randj] <= 4 )
        {
            grid[randi][randj] += 30;
            vectorezaman.push_back({randj , randi});
        }
    }
}
void print() {

    for (int i = 0; i < 26; i++)
        for (int j = 1; j < 25; j++)
            if (grid[i][j] != -1) {
                drawtoop_general(j_x(j), i_y(i), r , grid[i][j] , 255);
            }
    int countcount = 0;
    for ( int i =0 ; i < lazervec.size() ; i++)
    {
        filledCircleRGBA(m_renderer , j_x(lazervec[i - countcount].x) , i_y(lazervec[i- countcount].y) , r , rangs[7][0], rangs[7][1], rangs[7][2] , zaribelazervec[i- countcount]);
        if(zaribelazervec[i] <= 0)
        {
            zaribelazervec.erase(zaribelazervec.begin() + i);
            lazervec.erase(lazervec.begin() + i);
            countcount ++ ;
        }
        if (lazervec[i-countcount].y == 0)
            zaribelazervec[i- countcount] = 0;
        else
            zaribelazervec[i- countcount]-=5;
    }
}


void generate_rann( int &rann , int & rann2) {

    while (true) {
        if (rann2 < 5 ) {
            if (tedad_rang_check(rann2))
                break;
        }
        rann2 = rand();
    }
    rann = rann2;
}

bool iscolided(double x1, double y1, int j , int i) {
    if ((j_x(j) - x1) * (j_x(j) - x1) + (i_y(i) - y1) * (i_y(i) - y1)  <= 4 * (r) * (r) && grid[i][j] != -1)
        return true;
    return false;
}

coordination is_colided_general(double x, double y ) {
    coordination temp = {-1, -1};
//    for (int i = 1; i < 24; i++)
//        for (int j = 1; j < 25; j++) {
//            if (grid[i][j] == -1)
//                continue;
//            if ((i_y(i) - y) * (i_y(i) - y) + (j_x(j) - x) * (j_x(j) - x) <= 4 * r * r) {
//                temp.x = j;
//                temp.y = i;
//                return temp;
//            }
//        }
//    return temp;
    int ii = y_i(y);
    for (int k = 0; k < 6; k++) {
        if (atraf_check(ii , x_j(x) , k))
        {

            if (grid[ y_i(y) + atraf[k].y ][ x_j(x) + atraf[k].x ] == -1)
            {
                ghalat_kardam(ii , k);
                continue;
            }
            if ((i_y( y_i(y) + atraf[k].y ) - y) * (i_y( y_i(y) + atraf[k].y ) - y) + (j_x( x_j(x) + atraf[k].x ) - x) * (j_x( x_j(x) + atraf[k].x ) - x) <= 4 * r * r) {
                temp.x =  x_j(x) + atraf[k].x ;
                temp.y =  y_i(y) + atraf[k].y ;
//                ghalat_kardam(ii , k);
                return temp;
            }
        }
    }
    for (int k = 0; k < 6; k++) {
        if (x_j(x) + 1 + atraf[k].x > 0 && x_j(x) + 1 + atraf[k].x < 24 && y_i(y) + atraf[k].y > -1 && y_i(y) + atraf[k].y < 26)
        {
            if (grid[ y_i(y) + atraf[k].y ][ x_j(x) + atraf[k].x + 1 ] == -1)
            {
                ghalat_kardam(ii , k);
                continue;
            }
            if ((i_y( y_i(y) + atraf[k].y ) - y) * (i_y( y_i(y) + atraf[k].y ) - y) + (j_x( x_j(x) + atraf[k].x + 1 ) - x) * (j_x( x_j(x) + 1 + atraf[k].x ) - x) <= 4 * r * r) {
                temp.x =  x_j(x) + 1 + atraf[k].x ;
                temp.y =  y_i(y) + atraf[k].y ;
                return temp;
            }
        }
    }
    ii = y_i(y) + 1;
    for (int k = 0; k < 6; k++) {
        if (x_j(x) + 1 + atraf[k].x > 0 && x_j(x) + 1 + atraf[k].x < 24 && y_i(y) + atraf[k].y + 1 > -1 && y_i(y) + atraf[k].y + 1< 26)
        {
            if (grid[ y_i(y) + atraf[k].y + 1][ x_j(x) + atraf[k].x + 1 ] == -1)
            {
                ghalat_kardam(ii , k);
                continue;
            }
            if ((i_y( y_i(y) + atraf[k].y + 1) - y) * (i_y( y_i(y) + atraf[k].y +1  ) - y) + (j_x( x_j(x) + atraf[k].x + 1 ) - x) * (j_x( x_j(x) + 1 + atraf[k].x ) - x) <= 4 * r * r) {
                temp.x =  x_j(x) + 1 + atraf[k].x ;
                temp.y =  y_i(y) + 1 + atraf[k].y ;
                return temp;
            }
        }
    }

    for (int k = 0; k < 6; k++) {
        if (x_j(x) + atraf[k].x > 0 && x_j(x) + atraf[k].x < 24 && y_i(y) + atraf[k].y + 1 > -1 && y_i(y) + atraf[k].y + 1< 26)
        {
            if (grid[ y_i(y) + atraf[k].y + 1][ x_j(x) + atraf[k].x ] == -1)
            {
                ghalat_kardam(ii , k);
                continue;
            }
            if ((i_y( y_i(y) + atraf[k].y + 1) - y) * (i_y( y_i(y) + atraf[k].y +1  ) - y) + (j_x( x_j(x) + atraf[k].x ) - x) * (j_x( x_j(x) + atraf[k].x ) - x) <= 4 * r * r) {
                temp.x =  x_j(x) + atraf[k].x ;
                temp.y =  y_i(y) + 1 + atraf[k].y ;
                return temp;
            }
        }
    }
    return temp;

}
//************************************     niaz be tamir      **********************************************
void makelist(int i, int j) {
    if (flag[i][j])
        return;
    flag[i][j] = true;
    vectorkhali.push_back({j, i});
    for (int k = 0; k < 6; k++) {
        if (atraf_check(i, j, k))
            if (colors_are_same(grid[i][j], grid[i + atraf[k].y][j + atraf[k].x]))
                makelist(i + atraf[k].y, j + atraf[k].x);

//        if (j + atraf[k].x > 0 && j + atraf[k].x < 24 && i + atraf[k].y > 0 && i + atraf[k].y < 26)
//            if (grid[i + atraf[k].y][j + atraf[k].x] > 19)
//                if (colors_are_same(grid[i][j], grid[i + atraf[k].y][j + atraf[k].x] % 20))
//                    grid[i + atraf[k].y][j + atraf[k].x] %= 20;
        ghalat_kardam(i, k);
    }
}
//******************************************** vasl[i][j] va flag[i][j] eslah beshan tamome ********************************************
void check_vasl(int i, int j){

    if (vasl[i][j] == 1) {
        for (int k = 0; k < 6; k++) {
            if (j + atraf[k].x > 0 && j + atraf[k].x < 24 && i + atraf[k].y > -1 && i + atraf[k].y < 26 && grid[i + atraf[k].y][j + atraf[k].x] != -1) {
                vasl[i + atraf[k].y][j + atraf[k].x] = 1;
            }
        }
        return;
    }
    if (i == 0) {
        vasl[i][j] = 1;
    }
    if (vasl[i][j] != 0)
        return;
    vasl[i][j] = -1;
    for (int k = 0; k < 6; k++) {
        if (j + atraf[k].x > 0 && j + atraf[k].x < 24 && i + atraf[k].y > -1 && i + atraf[k].y < 26 && grid[i + atraf[k].y][j + atraf[k].x] != -1) {
            if (vasl[i + atraf[k].y][j + atraf[k].x] == 1) {
                vasl[i][j] = 1;
                return;
            }
        }
    }
    for (int k = 0; k < 6; k ++){
        if (j + atraf[k].x > 0 && j + atraf[k].x < 24 && i + atraf[k].y > -1 && i + atraf[k].y < 26 && grid[i + atraf[k].y][j + atraf[k].x] != -1) {
            if (vasl[i + atraf[k].y][j + atraf[k].x] == 0) {
                check_vasl(i , j);
                if (vasl[i + atraf[k].y][j + atraf[k].x] == 1) {
                    vasl[i][j] = 1;
                    return;
                }
            }
        }
    }
    return;
}

void terekidananimaion(int i , int j) {
//    if (grid[i][j] < 5)
//        tedad_rang[grid[i][j]]--;
    int back = grid[i][j];
    if ( grid[i][j] >= 25 && grid[i][j] < 30)
    {
        if(pause_effect_flag)
        {
            t_pause = time(NULL) - start_time;
            pause_effect_start_time = time(NULL);
        }
        else
        {
            pause_effect_flag = true;
            t_pause = time(NULL) - start_time;
            pause_effect_start_time = time(NULL);
        }

    }
    if (grid[i][j] >= 30 && grid[i][j] < 35 ) {
        if (slow_motion_effect_flag) {
            slow_motion_effect_start_time = time(NULL);
        }
        else {
            slow_motion_effect_flag = true;
            slow_motion_effect_start_time = time(NULL);
            zaribe_sorat /= slow_motion_level;
        }
    }
    grid[i][j] = -1;
    for (int k = r; k >= 0; k-=3) {
        image(background[theme] ,0 , 0 , L , W , 0 );
//        filledCircleRGBA(m_renderer , j_x(j) , i_y(i) , k  , rangs[back][0],rangs[back][1],rangs[back][2],255);
        drawtoop_general(j_x(j) , i_y(i) , k, back, 255);
        drawpaein();
        print ();
        drawtoop_general(ball2x , ball2y , r/2 , rann2 , 255);
        SDL_RenderPresent(m_renderer);
//        SDL_Delay(1);
    }
}

void oftadananimation(int i ) {
//    int yayyay = 10, imin = W;
//    for (int l = 0; l < vectorkhali.size(); l++) {
//        if (imin >vectorkhali[l].y)
//            imin = vectorkhali[l].y;
//    }
//    while (i_y(imin) + yayyay < W + 10) {
//        for (int l = 0; l < vectorkhali.size(); l++) {
//            filledCircleRGBA(m_renderer, j_x(vectorkhali[l].x), i_y(vectorkhali[l].y) + yayyay - 10, r, 0, 0, 0, 255);
//            filledCircleRGBA(m_renderer, j_x(vectorkhali[l].x), i_y(vectorkhali[l].y) + yayyay, r, rangs[grid[vectorkhali[l].y][vectorkhali[l].x]][0], rangs[grid[vectorkhali[l].y][vectorkhali[l].x]][1], rangs[grid[vectorkhali[l].y][vectorkhali[l].x]][2],255);
//        }
//        yayyay += 10;
//        SDL_RenderPresent(m_renderer);
//        print(m_renderer);
//
//    }
    int xx = j_x(vectorkhali[i].x), yy = i_y(vectorkhali[i].y);
    srand(cccc);
    double vyyy = - 10 * abs(sin(rand()));
    double vxxx = 7 * cos(rand());
    int rangeoftade = grid[vectorkhali[i].y][vectorkhali[i].x];
    grid[vectorkhali[i].y][vectorkhali[i].x] = -1;
    while ( xx > -r && xx < L + r && yy > -r && yy < W + r)
    {
//        print(m_renderer);

        vyyy += 6;
        yy += vyyy;
        xx += vxxx;
        //filledCircleRGBA(m_renderer, xx -vxxx, yy - vyyy  , r, 0, 0, 0, 255);
        image(background[theme] ,0 , 0 , L , W , 0 );
        print();
        drawpaein();
        drawtoop_general(ball2x , ball2y , r/2 , rann2 , 255);
        filledCircleRGBA(m_renderer, xx, yy, r,rangs[rangeoftade][0] , rangs[rangeoftade][1], rangs[rangeoftade][2],255);
        SDL_RenderPresent(m_renderer);
//        SDL_Delay(2);
    }

    cccc++;
}

void enfejaranimation(coordination ja[] , int c) {
    int kr, kg , kb;
    for ( int i = 0 ; i < c ; i ++)
        filledCircleRGBA(m_renderer , j_x(ja[i].x) , i_y(ja[i].y), r , 255 , 0, 0 , 255);
    for (int k = 255; k >= 0; k-= 5) {
        image(background[theme] ,0 , 0 , L , W , 0 );
        drawtoop_general(ball2x , ball2y , r/2 , rann2 , 255);
        for ( int i = 0 ; i < c ; i ++)
            filledCircleRGBA(m_renderer , j_x(ja[i].x) , i_y(ja[i].y), r , 255 , 0, 0 , k);
        drawpaein();
        print();
        SDL_RenderPresent(m_renderer);
        SDL_Delay(3);
    }
}
void preenfejaranimation ()
{
    int c = 0;
    bool flaag = true;
    coordination ja[vectorkhali.size()];
    for (int k = 0; k < vectorkhali.size(); k++) {
        for (int l = 0 ; l < c; l++){
            if (ja[l].x == vectorkhali[k].x &&ja[l].y == vectorkhali[k].y) {
                flaag = false;
                break;
            }
        }
        if (flaag) {
            ja[c] = vectorkhali[k];
            c++;
        }
        flaag = true;
    }
    vectorkhali.clear();
    for ( int i = 0 ; i < c ; i ++ )
    {
        filledCircleRGBA(m_renderer , j_x(ja[i].x) , i_y(ja[i].y) , r , rangs[8][0] , rangs[8][1] , rangs[8][2] , 100);
    }
}
void enfejar (int i, int j, int n) {
    coordination temp;
    temp.x = j;
    temp.y = i;
    vectorkhali.push_back(temp);
    if (n <= 0)
        return;
    for (int k = 0; k < 6;k++)
        if (atraf_check(i , j , k))
        {
            enfejar ( i + atraf[k].y ,j + atraf[k].x , n-1);
            ghalat_kardam(i , k);
        }
}

bool atraf_check(int &i , int j ,  int k)
{
    if ( j + atraf[k].x >= 0 && j + atraf[k].x < 24 && i + atraf[k].y >= 0 && i + atraf[k].y < 26 )
        return true;
    else if ( i + atraf[k].y == -1 )
    {
        i = 25 - atraf[k].y ;
        return true;
    }
    return false;
}

void effect_haye_bade_barkhord ()
{

    if ( flag_taghiir_rang_theme_2 && theme == 2)
        {
//                            for ( int i = 0 ; i <5 ; i ++)
            dddd = rand11[0] = rand() % 5 ;
            dddd++;
            for( int i = 1 ; i < 5 ; i ++ )
            {
                if(dddd > 4)
                    dddd = 0 ;
                rand11[i] = dddd;
                dddd++;
            }

            for ( int i = 0 ; i < 18 ; i ++ )
                for ( int j = 0 ; j < 24 ; j ++)
                {
                    if(grid[i][j] == -1 || grid[i][j] == 6)
                        continue;
                    else if ( grid[i][j] < 5  )
                        grid[i][j] = rand11[grid[i][j]];
                    else if ( grid[i][j] >= 20 && grid[i][j] < 25)
                        grid[i][j] = rand11[grid[i][j] % 5] + 20;
                    else if ( grid[i][j] >= 25 && grid[i][j] < 30)
                        grid[i][j] = rand11[grid[i][j] % 5] + 25;
                    else if ( grid[i][j] >= 30 && grid[i][j] < 35)
                        grid[i][j] = rand11[grid[i][j]  % 5] + 30;
                }
            flag_taghiir_rang_theme_2 = false;
        }

    if ( theme == 3)
    {
//                            for ( int i = 0 ; i <5 ; i ++)
        dddd = rand11[0] = rand() % 5 ;
        dddd++;
        for( int i = 1 ; i < 5 ; i ++ )
        {
            if(dddd > 4)
                dddd = 0 ;
            rand11[i] = dddd;
            dddd++;
        }

        for ( int i = 0 ; i < 18 ; i ++ )
            for ( int j = 0 ; j < 24 ; j ++)
            {
                if(grid[i][j] == -1 || grid[i][j] == 6)
                    continue;
                else if ( grid[i][j] < 5  )
                    grid[i][j] = rand11[grid[i][j]];
                else if ( grid[i][j] >= 20 && grid[i][j] < 25)
                    grid[i][j] = rand11[grid[i][j] % 5] + 20;
                else if ( grid[i][j] >= 25 && grid[i][j] < 30)
                    grid[i][j] = rand11[grid[i][j] % 5] + 25;
                else if ( grid[i][j] >= 30 && grid[i][j] < 35)
                    grid[i][j] = rand11[grid[i][j]  % 5] + 30;
            }
    }

    if ( flag_taghiir_rang_theme_4 && theme == 4)
    {
        for ( int i = 0 ; i <5 ; i++)
        {
            rand11[i] = rand() % 5;
        }

        for ( int i = 0 ; i < 18 ; i ++ )
            for ( int j = 0 ; j < 24 ; j ++)
            {
                if(grid[i][j] == -1 || grid[i][j] == 6)
                    continue;
                else if ( grid[i][j] < 5  )
                    grid[i][j] = rand11[grid[i][j]];
                else if ( grid[i][j] >= 20 && grid[i][j] < 25)
                    grid[i][j] = rand11[grid[i][j] % 5] + 20;
                else if ( grid[i][j] >= 25 && grid[i][j] < 30)
                    grid[i][j] = rand11[grid[i][j] % 5] + 25;
                else if ( grid[i][j] >= 30 && grid[i][j] < 35)
                    grid[i][j] = rand11[grid[i][j]  % 5] + 30;
            }
        flag_taghiir_rang_theme_4 = false;
    }
}


void ghalat_kardam ( int &i , int k)
{
    if (i + atraf[k].y == 25)
        i = -1 - atraf[k].y;
    return;
}

void pakkon(int i, int j) {
    vectorkhali.clear();
    if (grid[i][j] != 8 && grid[i][j] != -1) {
        for (int u = 0; u < 26; u++)
            for (int k = 0; k < 25; k++)
                flag[u][k] = false;
        makelist(i, j);
        if (vectorkhali.size() <= 2) {
            vectorkhali.clear();
            return;
        }
        tstop = time(NULL) - start_time;
        for (int k = 0; k < vectorkhali.size(); k++) {
            if ( grid[vectorkhali[k].y][vectorkhali[k].x] < 20 || grid[vectorkhali[k].y][vectorkhali[k].x] >= 25 ) {
                int channel = Mix_PlayChannel(-1,sedaye_terekidan,0);
            terekidananimaion(vectorkhali[k].y, vectorkhali[k].x);
                tedad_toop_terekide++;
                mohasebescore();
            }
            else
                grid[vectorkhali[k].y][vectorkhali[k].x] %= 20;
        }
        start_time = time(NULL) - tstop;
        vectorkhali.clear();
    }
    else if (grid[i][j] == 8){
        enfejar( i , j , 2);
        int c = 0;
        bool flaag = true;
        coordination ja[vectorkhali.size()];
        for (int k = 0; k < vectorkhali.size(); k++) {
            for (int l = 0 ; l < c; l++){
                if (ja[l].x == vectorkhali[k].x &&ja[l].y == vectorkhali[k].y) {
                    flaag = false;
                    break;
                }
            }
            if (flaag) {
                ja[c] = vectorkhali[k];
                c++;
            }
            flaag = true;
        }

        for (int k = 0; k < c; k++) {

            if ( grid[ja[k].y][ja[k].x] >= 25 && grid[ja[k].y][ja[k].x] < 30)
            {
                if(pause_effect_flag)
                {
                    t_pause = time(NULL) - start_time;
                    pause_effect_start_time = time(NULL);
                }
                else
                {
                    pause_effect_flag = true;
                    t_pause = time(NULL) - start_time;
                    pause_effect_start_time = time(NULL);
                }

            }
            if ( grid[ja[k].y][ja[k].x] >= 30 && grid[ja[k].y][ja[k].x] < 35 ) {
                if (slow_motion_effect_flag) {
                    slow_motion_effect_start_time = time(NULL);
                } else {
                    slow_motion_effect_flag = true;
                    slow_motion_effect_start_time = time(NULL);
                    zaribe_sorat /= slow_motion_level;
                }
            }

            if (grid[ja[k].y][ja[k].x] != 6) {
                tedad_toop_terekide++;
                mohasebescore();
                grid[ja[k].y][ja[k].x] = -1;
            }
        }
        tstop = time(NULL) - start_time;
        int channel = Mix_PlayChannel(-1,sedaye_enfejar,0);
        enfejaranimation(ja , c);
        start_time = time(NULL) - tstop;
//        cout << c;

        vectorkhali.clear();
    }
    /////     age toope iah bashe emtiaz nemide
    coordination temp;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 25; j++)
            vasl[i][j] = 0;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 25; j++)
            if (grid[i][j] != -1)
                check_vasl(i, j);

    for (int i = 1; i < 24; i++)
        for (int j = 1; j < 24; j++)
            if (vasl[i][j] == -1) {
//                tedad_rang[grid[i][j] % 5]--;
                temp.x = j;
                temp.y = i;
                vectorkhali.push_back(temp);
            }
    start_time = time(NULL) - tstop;
    for (int i = 0; i <vectorkhali.size(); i++)
    {

        oftadananimation(i);
        int channel = Mix_PlayChannel(-1,sedaye_oftadan,0);
        grid[vectorkhali[i].y][vectorkhali[i].x] = -1;

    }
    tstop = time(NULL) - start_time;
    cccc=0;
    vectorkhali.clear();
    return;
}

void line_komaki() {
    for (int i = 1; i < 24; i++)
        aalineRGBA(m_renderer, j_x(i), 0, j_x(i), W, 255, 255, 255, 255);
    for (int i = 1; i < 25; i++)
        aalineRGBA(m_renderer, 0, i_y(i), L, i_y(i), 255, 255, 255, 255);
}

void draw_changeball(int rann, int R ,double ballxx , double ballyy ) {
    if (rann <= 19 && rann >= 9) {
//        filledCircleRGBA(m_renderer, ballxx - vxx, ballyy - vyy, R, 0, 0, 0, 255);
//        image( background[0] , 0 , 0 , L , W , 0 );
        filledCircleRGBA(m_renderer, ballxx, ballyy, R, dorangs[rann - 9][int (andisrangs[rann - 9])][0],
                         dorangs[rann - 9][int(andisrangs[rann - 9])][1], dorangs[rann - 9][int(andisrangs[rann - 9])][2],
                         255);
        return;
    }
}

void controleandis (int rann) {
    andisrangs[rann - 9]+= 4 * zaribeandisrang[rann - 9];
    if (andisrangs[rann - 9] >= 50 || andisrangs[rann - 9] <= 0) {
        andisrangs[rann - 9] -= 4 * zaribeandisrang[rann - 9];
        zaribeandisrang[rann-9] *= -1;
    }
}

void image(SDL_Texture *text, int x, int y, int w, int h, double alfa) {
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderCopyEx(m_renderer, text, NULL, &rect, alfa, NULL, SDL_FLIP_NONE);
}

void generate_redif_jadid(int i) {
    generateballyekradif(i);
}

void shift_radifha() {
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 25; j++)
            grid_copy[i][j] = grid[i][j];
    for (int i = 24; i > 0; i--)
        for (int j = 0; j < 25; j++)
            grid[i][j] = grid_copy[i - 1][j];
    for (int j = 0; j < 25; j++) {
        grid[0][j] = grid_copy[25][j];
        grid[25][j] = -1;
    }
}

void drawtoop_general ( int xt , int yt , int rt , int rang_t , int alpha_t)
{
    if (rang_t <= 5 || rang_t == 8 || rang_t == 7 )
    {
        filledCircleRGBA(m_renderer, xt, yt, rt, rangs[rang_t][0], rangs[rang_t][1],rangs[rang_t][2], 255);
    }
    else if ( rang_t >= 20 && rang_t <= 24)
    {
        filledCircleRGBA(m_renderer, xt, yt, rt, 255, 255,255, 255);
        filledCircleRGBA(m_renderer, xt, yt, rt - 5, rangs[rang_t][0], rangs[rang_t][1],rangs[rang_t][2], 255);

    }
    else if ( rang_t >= 25 && rang_t <= 29)
    {
        filledCircleRGBA(m_renderer, xt, yt, rt, rangs[rang_t][0], rangs[rang_t][1],rangs[rang_t][2], 255);
        image( pause_icon , xt - rt/2, yt  - rt/2,  rt, rt , 0 );
    }
    else if (rang_t >= 30 && rang_t <= 34)
    {
        // slow image
        filledCircleRGBA(m_renderer, xt, yt, rt, rangs[rang_t][0], rangs[rang_t][1],rangs[rang_t][2], 255);
        image( next_music_image , xt - rt/2, yt - rt/2,  rt, rt , 90 );

    }
    else
    {
        draw_changeball(rang_t , rt ,xt , yt );
        controleandis(rang_t);
    }

}

void shiftcheck ()
{
    shift_az_bala += speed_shift_bala;
    if (shift_az_bala > sqrt(3) * r) {
        shift_az_bala = 0;
        shift_radifha();
        if (nn != -1)
            nn--;
        generate_redif_jadid(25);
    }
}

bool tedad_rang_check (int kk)

{
    bool flag_bord_bazi = true;
    for (int j = 0; j < 25; j++) {
        if (grid[1][j] != -1 && grid[1][j] != 5)
            flag_bord_bazi = false;
    }
    if (flag_bord_bazi)
        return true;
    for ( int i = 0 ; i < 5; i ++)
        tedad_rang[i] = 0;
    for ( int i = 1 ; i < 18 ; i ++)
        for( int j =0 ; j < 24 ; j ++)
        {
            if ( grid[i][j] == -1 || grid[i][j] == 6)
                continue;
            else if ( grid[i][j] < 5 || grid[i][j] >= 20)
                tedad_rang[(grid[i][j] % 5)]++;
            else if ( grid[i][j] >= 10 && grid[i][j] <= 19)
                vectorkhali.push_back({j , i});
        }

    if ( tedad_rang[kk] > 0) {
        vectorkhali.clear();
        return true;
    }

    for ( int i = 0 ; i < vectorkhali.size() ; i ++ )
    {
        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 10) {
            if (tedad_rang[1] && tedad_rang[0]) {
                tedad_rang[1]++;
                tedad_rang[0]++;
            }
            if ( !tedad_rang[1] && tedad_rang[0] )
                tedad_rang[0]++;
            if ( !tedad_rang[0] && tedad_rang[1] )
                tedad_rang[1]++;
        }
        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 11) {
            if (tedad_rang[2] && tedad_rang[0]) {
                tedad_rang[2]++;
                tedad_rang[0]++;
            }
            if ( !tedad_rang[2] && tedad_rang[0] )
                tedad_rang[0]++;
            if ( !tedad_rang[0] && tedad_rang[2] )
                tedad_rang[2]++;
        }
        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 12) {
            if (tedad_rang[3] && tedad_rang[0]) {
                tedad_rang[3]++;
                tedad_rang[0]++;
            }
            if ( !tedad_rang[3] && tedad_rang[0] )
                tedad_rang[0]++;
            if ( !tedad_rang[0] && tedad_rang[3] )
                tedad_rang[3]++;
        }

        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 13) {
            if (tedad_rang[4] && tedad_rang[0]) {
                tedad_rang[4]++;
                tedad_rang[0]++;
            }
            if ( !tedad_rang[4] && tedad_rang[0] )
                tedad_rang[0]++;
            if ( !tedad_rang[0] && tedad_rang[4] )
                tedad_rang[4]++;
        }
        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 14) {
            if (tedad_rang[1] && tedad_rang[2]) {
                tedad_rang[1]++;
                tedad_rang[2]++;
            }
            if ( !tedad_rang[1] && tedad_rang[2] )
                tedad_rang[2]++;
            if ( !tedad_rang[2] && tedad_rang[1] )
                tedad_rang[1]++;
        }
        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 15) {
            if (tedad_rang[1] && tedad_rang[3]) {
                tedad_rang[1]++;
                tedad_rang[3]++;
            }
            if ( !tedad_rang[1] && tedad_rang[3] )
                tedad_rang[3]++;
            if ( !tedad_rang[3] && tedad_rang[1] )
                tedad_rang[1]++;
        }
        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 16 ) {
            if (tedad_rang[1] && tedad_rang[4]) {
                tedad_rang[1]++;
                tedad_rang[4]++;
            }
            if ( !tedad_rang[1] && tedad_rang[4] )
                tedad_rang[4]++;
            if ( !tedad_rang[4] && tedad_rang[1] )
                tedad_rang[1]++;
        }
        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 17  ) {
            if (tedad_rang[3] && tedad_rang[2]) {
                tedad_rang[3]++;
                tedad_rang[2]++;
            }
            if ( !tedad_rang[3] && tedad_rang[2] )
                tedad_rang[2]++;
            if ( !tedad_rang[2] && tedad_rang[3] )
                tedad_rang[3]++;
        }
        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 18  ) {
            if (tedad_rang[4] && tedad_rang[2]) {
                tedad_rang[4]++;
                tedad_rang[2]++;
            }
            if ( !tedad_rang[4] && tedad_rang[2] )
                tedad_rang[2]++;
            if ( !tedad_rang[2] && tedad_rang[4] )
                tedad_rang[4]++;
        }
        if ( grid[vectorkhali[i].y][vectorkhali[i].x] == 19  ) {
            if (tedad_rang[3] && tedad_rang[4]) {
                tedad_rang[3]++;
                tedad_rang[4]++;
            }
            if ( !tedad_rang[3] && tedad_rang[4] )
                tedad_rang[4]++;
            if ( !tedad_rang[4] && tedad_rang[3] )
                tedad_rang[3]++;
        }

    }
    vectorkhali.clear();
    if ( tedad_rang[kk] > 0 )
        return true;

}



bool click_in_circle ( int xshape , int yshape , int rshape)
{
    ///////pol event nadare vaghti mikhay run koni toy main biya ghablesh poll event bezar
//    SDL_PollEvent(&e);
//    SDL_ShowCursor(SDL_ENABLE);
//    xmouse = e.button.x ; ymouse = e.button.y ;
    if ( (xshape - xmouse) * (xshape - xmouse) + (yshape - ymouse) * (yshape - ymouse) <= rshape * rshape )
    {
        if ( e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
        {
            return true;
        }
    }
    return false;
}
void changeball_with_click ( int rang_b , int xshape , int yshape , int rshape , bool halat )
{
    if(halat)
        if (click_in_circle(xshape , yshape , rshape))
        {

            if ( adadepowerball > 0 ) {
                rann = rang_b;
//            cout << rann << endl;
                adadepowerball--;
                replaceNthStringInCSV( "powerball.txt" , shomare_current_karbar , to_string(adadepowerball));
                SDL_Delay(150);
//                cout << adadepowerball;
            }


        }
    if ( adadepowerball > 0 )
        drawtoop_general(xshape ,yshape , rshape , rang_b , 255);
    else
        drawtoop_general(xshape ,yshape , rshape , 5 , 255);
    return;
}

bool click_in(int xshape, int yshape, int tool, int ertefa) {
    SDL_PollEvent(&e);
    SDL_ShowCursor(SDL_ENABLE);
    xmouse = e.button.x; ymouse = e.button.y;
    if (xmouse >= xshape && xmouse <= xshape + tool && ymouse >= yshape && ymouse <= yshape + ertefa) {
        if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
            return true;
    }
    return false;
}

bool click_keshidan(int xshape, int yshape, int tool, int ertefa) {
    SDL_PollEvent(&e);
    SDL_ShowCursor(SDL_ENABLE);
    xmouse = e.button.x; ymouse = e.button.y;
    if (xmouse >= xshape && xmouse <= xshape + tool && ymouse >= yshape && ymouse <= yshape + ertefa)
        if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN) {
            while (xmouse >= xshape && xmouse <= xshape + tool && ymouse >= yshape && ymouse <= yshape + ertefa &&
                   e.type == SDL_MOUSEMOTION) {
                last_xmouse = xmouse;
            }
            return true;
        }
    return false;
}

void set_window_color(int R, int G, int B) {
    SDL_SetRenderDrawColor( m_renderer, R, G, B, 255 );
    SDL_RenderClear( m_renderer );
    SDL_RenderPresent( m_renderer );
}

void rect(float x, float y,float w,float h,int R, int G, int B, int fill_boolian ) {
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(m_renderer, R, G, B, 255);
    if (fill_boolian==1)
        SDL_RenderFillRect(m_renderer, &rectangle);
    SDL_RenderDrawRect(m_renderer, &rectangle);
}

int screen_name() {
    image(background[5], 0, 0, L , W , 0);
    //set_window_color(255, 255, 255);
//    image(enter_your_name_image, L / 2 - safheye_name_karbar_length / 2, W / 5 - safheye_name_karbar_height / 2, safheye_name_karbar_length, safheye_name_karbar_height, 0);
    image(enter_your_name_image, L / 2 - safheye_name_karbar_length / 2, W / 5 + 1 * safheye_name_karbar_height / 2 , safheye_name_karbar_length, safheye_name_karbar_height, 0);
    //rect(L / 2 - safheye_name_karbar_length / 2, W / 5 - safheye_name_karbar_height / 2, safheye_name_karbar_length,
    //   safheye_name_karbar_height, 0, 255, 0, 1);
    image(back , L / 30 , W / 40 , L / 10 , W / 12 , 0);
    SDL_RenderPresent(m_renderer);
    SDL_Delay(300);

//    SDL_PollEvent(&e);
//    SDL_ShowCursor(SDL_ENABLE);
//    xmouse = e.button.x ; ymouse = e.button.y ;

    bool back_raftan1 = false;
    bool back_raftan2 = false;
    while (true) {
        if ( click_in(  L / 30 , W / 40 , L / 10 , W / 12))
        {
            back_raftan1 = true;
            break;
        }
        if (click_in(L / 2 - safheye_name_karbar_length / 2, W / 5 + 1 * safheye_name_karbar_height / 2 , safheye_name_karbar_length, safheye_name_karbar_height)) {
            SDL_Event name;
            string name_of_karbar = "";
            SDL_Color White = {255, 255, 255};
            back_raftan2 = false;
            while (true) {

//                if ( click_in(  L / 30 , W / 40 , L / 10 , W / 12))
//                {
//                    back_raftan2 = true;
//                    break;
//                }
//                if(click_in_circle( L / 30 + L / 20 , W / 40 + W / 24 , int(1.3 * L/ 10)))
//                {
//                    back_raftan2 = true;
//                    break;
//                }
                SDL_PollEvent(&name);
                bool flagepak = true;
                if (name.type == SDL_KEYDOWN) {
                    if ( name.key.keysym.sym == 27)
                    {
                        back_raftan2 = true;
                        break;
                    }
                    if (name.key.keysym.sym == 13)
                    {
                        SDL_Delay(200);
                        back_raftan2 = false;
                        back_raftan1 = false;
                        break;
                    }
                    else if ((name.key.keysym.sym >= 65 && name.key.keysym.sym <= 90) ||
                             (name.key.keysym.sym >= 97 && name.key.keysym.sym <= 122) || name.key.keysym.sym == ' ') {
                        name_of_karbar += char(name.key.keysym.sym);
//                        SDL_Delay(200);
                    }
                    else if (name.key.keysym.sym == SDLK_BACKSPACE && name_of_karbar.size() > 0 && flagepak) {
                        flagepak = false;
                        string copyname = "";
                        for (int i = 0; i < name_of_karbar.size() - 1; i++)
                            copyname += name_of_karbar[i];
                        name_of_karbar = copyname;
                        SDL_Delay(200);
                    }
                    flagepak = true;

                }
                karbarname = TTF_RenderText_Solid(Sans, name_of_karbar.c_str(), White);
                nameekarbar = SDL_CreateTextureFromSurface(m_renderer, karbarname);
                namekarbar_rect.x = L / 2 - name_of_karbar.length() * 15 / 2 ;  //controls the rect's x coordinate
                namekarbar_rect.y = W / 5 + 1 * safheye_name_karbar_height / 2 + 50 ; // controls the rect's y coordinte
                namekarbar_rect.w = name_of_karbar.length() * 15;// controls the width of the rect
                namekarbar_rect.h = safheye_name_karbar_height / 3; // controls the height of the rect
                SDL_RenderCopy(m_renderer, nameekarbar, NULL, &namekarbar_rect);
                SDL_RenderPresent(m_renderer);
//                image(enter_your_name_image, L / 2 - safheye_name_karbar_length / 2, W / 5 - safheye_name_karbar_height / 2, safheye_name_karbar_length, safheye_name_karbar_height, 0);
                image(blank_image,L / 2 - safheye_name_karbar_length / 2, W / 5 + 1 * safheye_name_karbar_height / 2 , safheye_name_karbar_length, safheye_name_karbar_height, 0);
                //rect(L / 2 - safheye_name_karbar_length / 2, W / 5 - safheye_name_karbar_height / 2,
                //    safheye_name_karbar_length, safheye_name_karbar_height, 0, 255, 0, 1);
            }
            if ( !back_raftan2)
            {
                ofstream username("names.txt", ios::app);
                ofstream mode1("normalscores.txt", ios::app);
                ofstream mode2("timedscores.txt", ios::app);
                ofstream mode3("infinitescores.txt", ios::app);
                ofstream powerball("powerball.txt", ios::app);
                if (!searchStringInCSV("names.txt", name_of_karbar)) {

                    username << name_of_karbar + ",";
                    mode1 << "0,";
                    mode2 << "0,";
                    mode3 << "0,";
                    powerball << "10,";
                }
                username.close();
                mode1.close();
                mode2.close();
                mode3.close();
                powerball.close();
//            findIndexInCSV();
//            readNthValue();
//            replaceNthStringInCSV();
                shomare_current_karbar = findIndexInCSV("names.txt", name_of_karbar);
                adadepowerball = stoi(readNthValue("powerball.txt", shomare_current_karbar));
//            cout << adadepowerball;
                return shomare_current_karbar;
                break;
            }
        }
    }
        if (back_raftan1)
            menu_play();
}
void menu_play() {
    image(background[5] , 0 , 0 , L , W , 0);
    // MODE ADI
    //rect(L / 2 - first_menu_bar_lenght / 2, W / 5, first_menu_bar_lenght, first_menu_bar_height, 0, 255, 0, 1);
    image(normal_button, L / 2 - first_menu_bar_lenght / 2, W / 5, first_menu_bar_lenght, first_menu_bar_height, 0);
    // zaman dar
    //rect(L / 2 - first_menu_bar_lenght / 2, W / 5 + 2 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 0, 255, 0, 1);
    image(time_limited_button, L / 2 - first_menu_bar_lenght / 2, W / 5 + 2 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 0);
    // binahayat
    //rect(L / 2 - first_menu_bar_lenght / 2, W / 5 + 4 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 0, 255, 0, 1);
    image(unlimited_button, L / 2 - first_menu_bar_lenght / 2, W / 5 + 4 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 0);

    image(back , L / 30 , W / 40 , L / 10 , W / 12 , 0);

    SDL_RenderPresent(m_renderer);

    SDL_Delay(300);
        mode = -1;
    while(true) {
        // mode adi
        if (click_in(L / 2 - first_menu_bar_lenght / 2, W / 5 + 0 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height))
            mode = 0;

        // zaman adi
        if (click_in(L / 2 - first_menu_bar_height / 2, W / 5 + 2 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height))
            mode = 1;

        // binahayat
        if (click_in(L / 2 - first_menu_bar_lenght / 2, W / 5 + 4 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height))
            mode = 2;

        if (mode != -1)
            break;
        if ( click_in(  L / 30 , W / 40 , L / 10 , W / 12))
        {
            break;
        }
    }

    n = rand() % 8;
    nn = rand() % 8;
    if (mode == 1)
        time_bazi = zamane_bazi;
    if (mode == 2) {
        nn = -1;
        speed_shift_bala = 0.1;
    }
    if (nn == 0)
        nn++;

    cout << "n " << n << endl << "nn " << nn << endl;

    nnn = nn;

    /////////////////////////////////////////////////
if ( mode != -1)
    screen_name();
else
    first_menu();

//    image(background[5], 0, 0, L , W , 0);
    //set_window_color(255, 255, 255);
    flag_in_game = true;
    SDL_Delay(300);
}



void menu_leaderbord() {

    image( background_leaderboard ,  ( L - W) / 2 , - ( L - W) / 2, W , L , 90 );
    // MODE ADI
    //rect(L / 2 - first_menu_bar_lenght / 2, W / 5, first_menu_bar_lenght, first_menu_bar_height, 0, 255, 0, 1);
    image(normal_button, L / 2 - first_menu_bar_lenght / 2, W / 5, first_menu_bar_lenght, first_menu_bar_height, 0);
    // zaman dar
    //rect(L / 2 - first_menu_bar_lenght / 2, W / 5 + 2 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 0, 255, 0, 1);
    image(time_limited_button, L / 2 - first_menu_bar_lenght / 2, W / 5 + 2 * first_menu_bar_height,
          first_menu_bar_lenght, first_menu_bar_height, 0);
    // binahayat
    //rect(L / 2 - first_menu_bar_lenght / 2, W / 5 + 4 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 0, 255, 0, 1);
    image(unlimited_button, L / 2 - first_menu_bar_lenght / 2, W / 5 + 4 * first_menu_bar_height, first_menu_bar_lenght,
          first_menu_bar_height, 0);

    image(back , L / 30 , W / 40 , L / 10 , W / 12 , 0);

    SDL_RenderPresent(m_renderer);
    SDL_Delay(300);
    mode_leaderboard = -1;
    while (true) {
        // mode adi
        if (click_in(L / 2 - first_menu_bar_lenght / 2, W / 5 + 0 * first_menu_bar_height, first_menu_bar_lenght,
                     first_menu_bar_height))
            mode_leaderboard = 0;

        // zaman adi
        if (click_in(L / 2 - first_menu_bar_height / 2, W / 5 + 2 * first_menu_bar_height, first_menu_bar_lenght,
                     first_menu_bar_height))
            mode_leaderboard = 1;

        // binahayat
        if (click_in(L / 2 - first_menu_bar_lenght / 2, W / 5 + 4 * first_menu_bar_height, first_menu_bar_lenght,
                     first_menu_bar_height))
            mode_leaderboard = 2;
        if (mode_leaderboard != -1)
            break;

        if ( click_in(  L / 30 , W / 40 , L / 10 , W / 12))
            {
                break;
            }
    }
    if ( mode_leaderboard == 0)
    {
        menu_namayeshe_leaderboard();
        menu_leaderbord();
        //adi
    }
    else if ( mode_leaderboard == 1)
    {
        menu_namayeshe_leaderboard();
        menu_leaderbord();
        // zamani
    }
    else if ( mode_leaderboard == 2)
    {
        menu_namayeshe_leaderboard();
        menu_leaderbord();
        // binahayat
    }
    else
    {
        first_menu();
    }

}

vector<player> create_vec_timed ()
{
    int hajm = 0;vector  <player> vecplayer;
    player playeralaki;
    while (readNthValue("powerball.txt", hajm) != "")
        hajm++;
        for(int i=0;i<hajm;i++)
        {
        playeralaki.username= readNthValue("names.txt", i);
        playeralaki.normalscore= stoi(readNthValue("normalscores.txt", i));
        playeralaki.infinitescore= stoi(readNthValue("infinitescores.txt", i));
        playeralaki.timedscore= stoi(readNthValue("timedscores.txt", i));
//        playeralaki.total=playeralaki.normalscore+playeralaki.infinitescore+playeralaki.timedscore;
        vecplayer.push_back(playeralaki);
        }
    for(int i=0;i<hajm;i++){
        for(int j=0;j<hajm-1;j++){
            if(vecplayer[j].timedscore < vecplayer[j+1].timedscore)
            {
                swap(vecplayer[j],vecplayer[j+1]);
            }
        }
    }
    return vecplayer;
}

vector<player> create_vec_normal ()
{
    int hajm = 0;vector  <player> vecplayer;
    player playeralaki;
    while (readNthValue("powerball.txt", hajm) != "")
        hajm++;
    for(int i=0;i<hajm;i++)
    {
        playeralaki.username= readNthValue("names.txt", i);
        playeralaki.normalscore= stoi(readNthValue("normalscores.txt", i));
        playeralaki.infinitescore= stoi(readNthValue("infinitescores.txt", i));
        playeralaki.timedscore= stoi(readNthValue("timedscores.txt", i));
//        playeralaki.total=playeralaki.normalscore+playeralaki.infinitescore+playeralaki.timedscore;
        vecplayer.push_back(playeralaki);
    }
    for(int i=0;i<hajm;i++){
        for(int j=0;j<hajm-1;j++){
            if(vecplayer[j].normalscore < vecplayer[j+1].normalscore)
            {
                swap(vecplayer[j],vecplayer[j+1]);
            }
        }
    }
    return vecplayer;
}

vector<player> create_vec_infinite ()
{
    int hajm = 0;vector  <player> vecplayer;
    player playeralaki;
    while (readNthValue("powerball.txt", hajm) != "")
        hajm++;
    for(int i=0;i<hajm;i++)
    {
        playeralaki.username= readNthValue("names.txt", i);
        playeralaki.normalscore= stoi(readNthValue("normalscores.txt", i));
        playeralaki.infinitescore= stoi(readNthValue("infinitescores.txt", i));
        playeralaki.timedscore= stoi(readNthValue("timedscores.txt", i));
//        playeralaki.total=playeralaki.normalscore+playeralaki.infinitescore+playeralaki.timedscore;
        vecplayer.push_back(playeralaki);
    }
    for(int i=0;i<hajm;i++){
        for(int j=0;j<hajm-1;j++){
            if(vecplayer[j].infinitescore < vecplayer[j+1].infinitescore)
            {
                swap(vecplayer[j],vecplayer[j+1]);
            }
        }
    }
    return vecplayer;
}
void typestring ( string baratype , int xupleft , int yupleft , int ertefa)
{

    surfaceMessage = TTF_RenderText_Solid(Sans, baratype.c_str(), White);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = xupleft;  //controls the rect's x coordinate
    Message_rect.y = yupleft  ; // controls the rect's y coordinte
    Message_rect.w = ertefa / 3 * baratype.length(); // controls the width of the rect
    Message_rect.h = ertefa; // controls the height of the rect
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);
}

void menu_namayeshe_leaderboard()
{
//        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
//        SDL_RenderClear(m_renderer);
        int nnnnnn = 6;
    image( background_leaderboard ,  ( L - W) / 2 , - ( L - W) / 2, W , L , 90 );
    image( Leader_board_dakheli , L / 30 + 50 , W / 40 + 15 , L  - 2 * ( L / 30 + 50 ) , W / 4 - 20 - ( W / 40 + 15) , 0 );

//    for (int i = 0; i < nnnnnn; i++) {
////            rect(L / 15, W / 6 + 65 * i, 350, 50, 255, 255, 255, 1);
//            image(dokme_leader_board ,L / 15, W / 4 + 90 * i, 350, 105 , 0);
////            rect(L / 15 + 380, W / 6 + 65 * i, 160, 50, 255, 255, 255, 1);
//            image ( dokme_leader_board , L / 15 + 380, W / 4 + 90 * i, 160, 105 , 0);
//        }
        // dokme back
        image(back , L / 30 , W / 40 , L / 10 , W / 12 , 0);
//        rect( L / 30 , W / 40 , L / 10 , W / 12 , 0 , 255 ,255 , 1 );
        vector<player> players_sort_shode;
    if ( mode_leaderboard == 0 )
    {
    players_sort_shode = create_vec_normal();
    }
    if ( mode_leaderboard == 1)
    {
        players_sort_shode = create_vec_timed();
    }
    if ( mode_leaderboard == 2)
    {
        players_sort_shode = create_vec_infinite();
    }
    int nnnnnn2 = players_sort_shode.size();
    if ( nnnnnn2 < nnnnnn )
        nnnnnn = nnnnnn2;
    for ( int i = 0 ; i < nnnnnn ; i++)
    {

        image(dokme_leader_board ,L / 15, W / 4 + 90 * i, 350, 120 , 0);
        typestring( players_sort_shode[i].username ,L / 15 + 125 , W / 4 + 90 * i + 15 + 5 , 45);
        image ( dokme_leader_board , L / 15 + 380, W / 4 + 90 * i, 160, 120 , 0);
        if ( mode_leaderboard == 0 )
        {
            typestring(to_string(players_sort_shode[i].normalscore) , L / 15 + 380 + 45, W / 4 + 90 * i + 15 + 5 , 45);
        }
        if ( mode_leaderboard == 1)
        {
            typestring(to_string(players_sort_shode[i].timedscore) , L / 15 + 380 + 45, W / 4 + 90 * i + 15 + 5 , 45);
        }
        if ( mode_leaderboard == 2)
        {
            typestring(to_string(players_sort_shode[i].infinitescore) , L / 15 + 380 + 45, W / 4 + 90 * i + 15 + 5 , 45);
        }

    }
    SDL_RenderPresent(m_renderer);

    while ( true) {

        if ( click_in(  L / 30 , W / 40 , L / 10 , W / 12))
        {
            break;
        }
    }

}

void menu_jadval() {

//    image(background[5], 0, 0, L , W , 0);
    menu_leaderbord();
    //set_window_color(255, 255, 255);
}

void menu_setting() {
    bool running = true;
    int t = start_time  -  time(NULL);
    int tp = pause_effect_start_time - time(NULL);
    int ts = slow_motion_effect_start_time - time(NULL);
    while (running) {
        //kol setting
//        rect(L / 2 - setting_bar_lenght / 2, W / 4, setting_bar_lenght, W / 4 + setting_bar_height, 0, 100, 0, 1);
        roundedBoxRGBA(m_renderer , L / 2 - setting_bar_lenght / 2, W / 4 , L / 2 + setting_bar_lenght / 2, W / 4 + setting_bar_height , 10 , 0 ,  0 , 100 , 15);
//        roundedBoxRGBA(m_renderer , L / 2 + 110, W / 4 + 100,L / 2 + 130 ,W/4 + 300 ,   10 , 255,255,255,255);/////
        filledCircleRGBA ( m_renderer , L / 2 + 120 , W / 4 + 110 , 10 , 0 , 0 , 255 , 255);
        filledCircleRGBA ( m_renderer , L / 2 + 120 , W / 4 +290 , 10 , 0 , 0 , 255 , 255);
        rect(L / 2 + 110 , W / 4 + 110 , 21 , 180 , 0 ,0 ,255 ,1);
        //dokme khoroj
        //rect(L / 2 + setting_bar_lenght / 2 - setting_exit_lenght, W / 4, setting_exit_lenght, setting_exit_lenght, 0, 0, 100, 1);
        image(check_image, L / 2 + setting_bar_lenght / 2 - setting_exit_lenght, W / 4, setting_exit_lenght, setting_exit_lenght, 0);
        //dokme seda barkhord va ...
        //rect(L / 2 - 100, W / 4 + 25, 50, 50, 0, 0, 255, 1);
        if (flag_seda_barkhord)
            image(music_image, L / 2 - 100, W / 4 + 25, 50, 50, 0);
        else
            image(no_music_image, L / 2 - 100, W / 4 + 25, 50, 50, 0);
        //dokme seda ahang
        //rect(L / 2 + 50, W / 4 + 25, 50, 50, 0, 0, 255, 1);
        if (flag_seda_ahang)
            image(sound_image, L / 2 + 50, W / 4 + 25, 50, 50, 0);
        else
            image(no_sound_image, L / 2 + 50, W / 4 + 25, 50, 50, 0);
        if (flag_playing_ahang)
            image(pause_icon, L / 2 - 25, W / 4 + 25, 50, 50, 0);

        else
            image(resume_icon, L / 2 - 33, W / 4 + 25, 60, 60, 5);



        //dokme taghir seda ahang
        image(sound_image , L / 2 - 100 - 50 - 5 - 10, W / 4 + 125, 50, 50, 0);
        roundedBoxRGBA(m_renderer ,  L / 2 - 100, W / 4 + 140 , L / 2 + 100, W / 4 + 160 , 10 , 0 ,0, 255 , 255 );
        //        rect(L / 2 - 100, W / 4 + 125, 200, 50, 255, 255, 255, 1);
        //dokme taghir seda barkhord
        image(music_image, L / 2 - 100 - 50 - 5 - 10, W / 4 + 225, 50, 50, 0);
//        rect(L / 2 - 100, W / 4 + 225, 200, 50, 0, 0, 255, 1);

        roundedBoxRGBA(m_renderer ,  L / 2 - 100, W / 4 + 240 , L / 2 + 100, W / 4 + 260 , 10 , 0 ,0, 255 , 255 );
        //dokme theme 0
//        rect(L / 2 - 200, W / 4 + 300, 50, 50, 0, 0, 255, 1);
        image(background[0], L / 2 - 200, W / 4 + 300, 50, 50, 0);
        //dokme theme 1
        //rect(L / 2 - 115, W / 4 + 300, 50, 50, 0, 0, 255, 1);
        image(background[1], L / 2 - 115, W / 4 + 300, 50, 50, 0);
        //dokme theme 2
        //rect(L / 2 - 30, W / 4 + 300, 50, 50, 0, 0, 255, 1);
        image(background[2], L / 2 - 30, W / 4 + 300, 50, 50, 0);
        //dokme theme 3
        //rect(L / 2 + 55, W / 4 + 300, 50, 50, 0, 0, 255, 1);
        image(background[3], L / 2 + 55, W / 4 + 300, 50, 50, 0);
        //dokme theme 4
        //rect(L / 2 + 140, W / 4 + 300, 50, 50, 0, 0, 255, 1);
        image(background[4], L / 2 + 140, W / 4 + 300, 50, 50, 0);
        //dokme next song
        //rect(L / 2 + 175, W / 4 + 175, 50, 50, 0, 0, 255, 1);
        image(next_music_image, L / 2 + 175, W / 4 + 175, 50, 50, 0);
        //dokme pre song
        image(pre_music_image, L / 2 - 175 - 50, W / 4 + 175, 50, 50, 0);








        // dokme khoroj
        if (click_in(L / 2 + setting_bar_lenght / 2 - setting_exit_lenght, W / 4, setting_exit_lenght, setting_exit_lenght))
        {
            start_time = t + time(NULL);
            pause_effect_start_time = tp + time(NULL);
            slow_motion_effect_start_time = ts + time(NULL);
            SDL_Delay(300);
            break;
        }
        if ( click_in(  L / 2 - 25, W / 4 + 25, 50, 50))
        {
            if ( flag_playing_ahang)
            {
                Mix_PauseMusic();
                flag_playing_ahang = false;
            }
            else
            {
                Mix_ResumeMusic();
                flag_playing_ahang = true;
            }
            SDL_Delay(200);
        }
        if (click_in(L / 2 - 100, W / 4 + 25, 50, 50))
        {
            flag_seda_barkhord = !flag_seda_barkhord;
//            Mix_VolumeChunk(sedaye_toop , flag_seda_barkhord * andaze_seda_barkhord);
            Mix_VolumeChunk(sedaye_toop , flag_seda_barkhord *andaze_seda_barkhord);
            Mix_VolumeChunk(sedaye_terekidan , flag_seda_barkhord *andaze_seda_barkhord);
            Mix_VolumeChunk(sedaye_enfejar , flag_seda_barkhord *andaze_seda_barkhord);
//    Mix_VolumeChunk(sedaye_laizer, flag_seda_barkhord *andaze_seda_barkhord);
            Mix_VolumeChunk(sedaye_oftadan, flag_seda_barkhord *andaze_seda_barkhord);
            SDL_Delay(200);
        }
        if (click_in(L / 2 + 50, W / 4 + 25, 50, 50) /*&& flag_playing_ahang*/)
        {
            flag_seda_ahang = !flag_seda_ahang;
            Mix_VolumeMusic(flag_seda_ahang * andaze_seda_ahang);
            SDL_Delay(200);
        }
        if (click_in(L / 2 + 108, W / 4 + 100,24 , 200))
        {
            ymouse_level = e.button.y;
            level = -(W / 4 + 100  - ymouse_level) / 20 ;
            cout << level;

        }

        if(flag_seda_ahang /*&& flag_playing_ahang*/)
            if (click_in(L / 2 - 100, W / 4 + 125, 200, 50)) { //click_in (L / 2 + 150, W/4 + 100 , 50 , 200)
                xmouse_ahang = e.button.x;
                andaze_seda_ahang = (xmouse_ahang - (L / 2 - 100)) / 20;
                Mix_VolumeMusic( andaze_seda_ahang);
                SDL_Delay(10);
            }
        if(flag_seda_barkhord)
            if (click_in(L / 2 - 100, W / 4 + 225, 200, 50)) {
                xmouse_barkhord = e.button.x;
                andaze_seda_barkhord = (xmouse_barkhord - (L / 2 - 100)) / 20;
//                Mix_VolumeChunk(sedaye_toop , andaze_seda_barkhord);
                Mix_VolumeChunk(sedaye_toop , andaze_seda_barkhord);
                Mix_VolumeChunk(sedaye_terekidan , andaze_seda_barkhord);
                Mix_VolumeChunk(sedaye_enfejar , andaze_seda_barkhord);
//    Mix_VolumeChunk(sedaye_laizer, andaze_seda_barkhord);
                Mix_VolumeChunk(sedaye_oftadan, andaze_seda_barkhord);
            }
        if (click_in(L / 2 - 200, W / 4 + 300, 50, 50))
            theme = 0;
        if (click_in(L / 2 - 115, W / 4 + 300, 50, 50))
            theme = 1;
        if (click_in(L / 2 - 30, W / 4 + 300, 50, 50))
            theme = 2;
        if (click_in(L / 2 + 55, W / 4 + 300, 50, 50))
            theme = 3;
        if (click_in(L / 2 + 140, W / 4 + 300, 50, 50))
            theme = 4;
//        if(flag_playing_ahang)
        if (click_in(L / 2 + 175, W / 4 + 175, 50, 50))
        {
            song_num++;
            if (song_num > max_song)
                song_num = 0;
            Mix_PlayMusic(ahang[song_num] , -1);
            SDL_Delay(200);
            flag_playing_ahang = true;
        }
//        if(flag_playing_ahang)
        if (click_in(L / 2 - 175 - 50, W / 4 + 175, 50, 50))
        {
            song_num--;
            if (song_num < 0)
                song_num = max_song;
            Mix_PlayMusic(ahang[song_num] , -1);
            SDL_Delay(200);
            flag_playing_ahang = true;
        }
        //cout << flag_seda_ahang << " " << flag_seda_barkhord << " " << andaze_seda_ahang << " " << andaze_seda_barkhord << " " << theme << endl;
//        filledCircleRGBA(m_renderer , xmouse_barkhord , W / 4 + 250  , 10, 255 , 255 ,255 , 255);
        roundedBoxRGBA(m_renderer ,  L / 2 - 100 - 10, W / 4 + 240  , xmouse_barkhord + 10, W / 4 + 260 , 10 , 255 ,255, 255 , 255 );
        roundedBoxRGBA(m_renderer ,  L / 2 - 100 - 10, W / 4 + 140  , xmouse_ahang + 10, W / 4 + 160  , 10 , 255 ,255, 255 , 255 );
//        filledCircleRGBA(m_renderer , xmouse_ahang , W / 4 + 150  , 10, 255 , 255 ,255 , 255);



        filledCircleRGBA ( m_renderer , L / 2 + 120 , ymouse_level , 10 , 255 , 255 , 255 , 255);
        filledCircleRGBA ( m_renderer , L / 2 + 120 , W / 4 + 290 , 10 , 255 , 255 , 255 , 255);
        rect(L / 2 + 110 ,  ymouse_level , 21 , W / 4 + 290 - ymouse_level,  255 ,255 ,255 ,1);


        SDL_RenderPresent(m_renderer);

    }
    if (!flag_in_game)
        image(background[5], 0, 0, L , W , 0);
    //set_window_color(255, 255, 255);
}

void screen_gameover() {
    mohasebescore();
    if ( mode == 0)
    {
        if ( score > stoi(readNthValue("normalscores.txt" , shomare_current_karbar) ))
            replaceNthStringInCSV( "normalscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 1)
    {
        if ( score > stoi(readNthValue("timedscores.txt" , shomare_current_karbar) ))
            replaceNthStringInCSV( "timedscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 2)
    {
        if ( score > stoi(readNthValue("infinitescores.txt" , shomare_current_karbar) ))
            replaceNthStringInCSV( "infinitescores.txt" , shomare_current_karbar , to_string(score));
    }
    replaceNthStringInCSV( "powerball.txt" , shomare_current_karbar , to_string(adadepowerball));


    mode = -1;
    set_window_color(0, 0, 0);
    SDL_Color White = {255, 255, 255};
    string a = "GAME OVER";
    surfaceMessage = TTF_RenderText_Solid(Sans, a.c_str(), White);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = L / 2 - 200;  //controls the rect's x coordinate
    Message_rect.y = W / 4; // controls the rect's y coordinte
    Message_rect.w = 400; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);

    // writing score
    a = to_string(score);
    surfaceMessage = TTF_RenderText_Solid(Sans, a.c_str(), White);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    Message_rect.x = L / 2 - 1.5 * r * (a.length()/2 + a.length() % 2) / 2.0;  //controls the rect's x coordinate
    Message_rect.y = W / 4 + 100; // controls the rect's y coordinte
    Message_rect.w = 1.5 * r * (a.length()/2 + a.length() % 2); // controls the width of the rect
    Message_rect.h = 1.5 * r; // controls the height of the rect
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);



    score = 0;

    ///////start game again
    //rect(L / 2 - 200, W / 4 + 100 + 50, 150, 50, 255, 255, 255, 1);
    image(play_again_image, L / 2 - 200, W / 4 + 100 + 50, 150, 50, 0);
    ///////exit
    //rect(L / 2 + 50, W / 4 + 100 + 50, 150, 50, 255, 255, 255, 1);
    image(exit_image, L / 2 + 50, W / 4 + 100 + 50, 150, 50, 0);
    SDL_RenderPresent(m_renderer);
    while (true) {

        if (click_in(L / 2 - 200, W / 4 + 100 + 50, 150, 50)) {
            flag_in_game = false;
            image(background[5], 0, 0, L , W , 0);
            //set_window_color(255,255,255);
            break;
        }
        if (click_in(L / 2 + 50, W / 4 + 100 + 50, 150, 50)) {
            running1 = false;
            break;
        }
    }
}

void menu_bord_game() {
    mohasebescore();
    if ( mode == 0)
    {
        if ( score > stoi(readNthValue("normalscores.txt" , shomare_current_karbar) ))
            replaceNthStringInCSV( "normalscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 1)
    {
        if ( score > stoi(readNthValue("timedscores.txt" , shomare_current_karbar) ))
            replaceNthStringInCSV( "timedscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 2)
    {
        if ( score > stoi(readNthValue("infinitescores.txt" , shomare_current_karbar) ))
            replaceNthStringInCSV( "infinitescores.txt" , shomare_current_karbar , to_string(score));
    }
    adadepowerball += 1;
    replaceNthStringInCSV( "powerball.txt" , shomare_current_karbar  , to_string(adadepowerball));

    mode = -1;
    set_window_color(0, 0, 0);
    SDL_Color White = {255, 255, 255};
    string a = "YOU WON";
    surfaceMessage = TTF_RenderText_Solid(Sans, a.c_str(), White);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = L / 2 - 200;  //controls the rect's x coordinate
    Message_rect.y = W / 4; // controls the rect's y coordinte
    Message_rect.w = 400; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);

    // writing score
    a = to_string(score);
    surfaceMessage = TTF_RenderText_Solid(Sans, a.c_str(), White);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    Message_rect.x = L / 2 - 1.5 * r * (a.length()/2 + a.length() % 2) / 2.0;  //controls the rect's x coordinate
    Message_rect.y = W / 4 + 100; // controls the rect's y coordinte
    Message_rect.w = 1.5 * r * (a.length()/2 + a.length() % 2); // controls the width of the rect
    Message_rect.h = 1.5 * r; // controls the height of the rect
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);


    if ( mode == 0)
    {
        replaceNthStringInCSV( "normalscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 1)
    {
        replaceNthStringInCSV( "timedscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 2)
    {
        replaceNthStringInCSV( "infinitescores.txt" , shomare_current_karbar , to_string(score));
    }


//
//    ///////start game again
//    //rect(L / 2 - 200, W / 4 + 100 + 50, 150, 50, 255, 255, 255, 1);
//    image(play_again_image, L / 2 - 200, W / 4 + 100 + 50, 150, 50, 0);
//    ///////exit
//    //rect(L / 2 + 50, W / 4 + 100 + 50, 150, 50, 255, 255, 255, 1);
//    image(exit_image, L / 2 + 50, W / 4 + 100 + 50, 150, 50, 0);
//    SDL_RenderPresent(m_renderer);
//    while (true) {
//
//        if (click_in(L / 2 - 200, W / 4 + 100 + 50, 150, 50)) {
//            flag_in_game = false;
//            image(background[5], 50, 50, L - 100, W - 100, 0);
//            //set_window_color(255,255,255);
//            break;
//        }
//        if (click_in(L / 2 + 50, W / 4 + 100 + 50, 150, 50)) {
//            running1 = false;
//            break;
//        }
//    }
    score = 0;
    ///////start game again
//    rect(L / 2 - 200, W / 4 + 100 + 50, 150, 50, 255, 255, 255, 1);
    image(play_again_image, L / 2 - 200, W / 4 + 100 + 50, 150, 50, 0);
    ///////exit
//    rect(L / 2 + 50, W / 4 + 100 + 50, 150, 50, 255, 255, 255, 1);
    image(exit_image, L / 2 + 50, W / 4 + 100 + 50, 150, 50, 0);
    SDL_RenderPresent(m_renderer);
    while (true) {

        if (click_in(L / 2 - 200, W / 4 + 100 + 50, 150, 50)) {
            flag_in_game = false;
            image(background[5], 0, 0, L , W , 0);
            //set_window_color(255,255,255);
            break;
        }
        if (click_in(L / 2 + 50, W / 4 + 100 + 50, 150, 50)) {
            running1 = false;
            break;
        }
    }
}
/////// score in abadesh dorost nist
void menu_tamam_game() {
    mohasebescore();
    if ( mode == 0)
    {
        replaceNthStringInCSV( "normalscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 1)
    {
        replaceNthStringInCSV( "timedscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 2)
    {
        replaceNthStringInCSV( "infinitescores.txt" , shomare_current_karbar , to_string(score));
    }

    mode = -1;
    set_window_color(0, 0, 0);
    SDL_Color White = {255, 255, 255};
    string a = "YOURE SCORE IS ";
    a += to_string(score);
    surfaceMessage = TTF_RenderText_Solid(Sans, a.c_str(), White);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = L / 2 - 200;  //controls the rect's x coordinate
    Message_rect.y = W / 4; // controls the rect's y coordinte
    Message_rect.w = 400; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);
    ///////start game again
    rect(L / 2 - 200, W / 4 + 100 + 50, 150, 50, 255, 255, 255, 1);
    ///////exit
    rect(L / 2 + 50, W / 4 + 100 + 50, 150, 50, 255, 255, 255, 1);
    SDL_RenderPresent(m_renderer);

    if ( mode == 0)
    {
        replaceNthStringInCSV( "normalscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 1)
    {
        replaceNthStringInCSV( "timedscores.txt" , shomare_current_karbar , to_string(score));
    }
    if ( mode == 2)
    {
        replaceNthStringInCSV( "infinitescores.txt" , shomare_current_karbar , to_string(score));
    }
    score = 0;
    while (true) {

        if (click_in(L / 2 - 200, W / 4 + 100 + 50, 150, 50)) {
            flag_in_game = false;
            image(background[5], 0, 0, L, W , 0);
            //set_window_color(255,255,255);
            break;
        }
        if (click_in(L / 2 + 50, W / 4 + 100 + 50, 150, 50)) {
            running1 = false;
            break;
        }
    }
}

void first_menu() {
    if (mode != -1)
        return;
    first_menu_bar_lenght = 400, first_menu_bar_height = 100;

    image(background[5],  0, 0, L , W , 0);
    //set_window_color(255, 255, 255);
    while (true) {
        // esm bazi
        ////L / 2 - bar_lenght / 2, W / 5
        /// dokmehay meno
        // shoro bazi
        //rect(L / 2 - first_menu_bar_lenght / 2, W / 5, first_menu_bar_lenght, first_menu_bar_height, 255, 0, 0, 1);
        image( play_now_button, L / 2 - first_menu_bar_lenght / 2, W / 5, first_menu_bar_lenght, first_menu_bar_height, 0);
        // jadval emtiazat
        //rect(L / 2 - first_menu_bar_lenght / 2, W / 5 + 2 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 255, 0, 0, 1);
        image( score_bord_button, L / 2 - first_menu_bar_lenght / 2, W / 5 + 2 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 0);
        // tanzimat
        //rect(L / 2 - first_menu_bar_lenght / 2, W / 5 + 4 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 255, 0, 0, 1);
        image( setting_button, L / 2 - first_menu_bar_lenght / 2, W / 5 + 4 * first_menu_bar_height, first_menu_bar_lenght, first_menu_bar_height, 0);
        SDL_RenderPresent(m_renderer);
        /// check click mouse
        // check play
        bool play = false, jadval = false, setting = false;
        if (click_in(L / 2 - first_menu_bar_lenght / 2, W / 5 + 0 * first_menu_bar_height, first_menu_bar_lenght,
                     first_menu_bar_height))
            play = true;

        // check jadval
        if (click_in(L / 2 - first_menu_bar_height / 2, W / 5 + 2 * first_menu_bar_height, first_menu_bar_lenght,
                     first_menu_bar_height))
            jadval = true;

        // check tanzimat
        if (click_in(L / 2 - first_menu_bar_lenght / 2, W / 5 + 4 * first_menu_bar_height, first_menu_bar_lenght,
                     first_menu_bar_height))
            setting = true;

        //cout << xmouse << " " << ymouse << " " << play << " " << jadval << " " << setting << endl;

        if (play) {
            play = false;
            menu_play();
            break;
        }

        if (jadval) {
            jadval = false;
            menu_jadval();
        }

        if (setting) {
            setting = false;
            menu_setting();
        }
    }

}

void menu_pause() {
    //rect(L - setting_exit_lenght, yc0 - 2 * setting_exit_lenght, setting_exit_lenght, setting_exit_lenght, 255, 255, 255, 1);
    image(pause_image, L - setting_exit_lenght, yc0 - setting_exit_lenght / 2, setting_exit_lenght, setting_exit_lenght, 0);
    //SDL_RenderPresent(m_renderer);
    if (click_in(L - setting_exit_lenght, yc0 - setting_exit_lenght / 2, setting_exit_lenght, setting_exit_lenght)) {
        menu_setting();
        flag_menu_pause = true;
    }
}






string readNthValue(const string &filepath, int n) {
//    n-=1;
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filepath << endl;
        return "";
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        vector<string> tokens;

        while (getline(ss, value, ',')) {
            tokens.push_back(value);
        }

        if (n >= 0 && n < tokens.size()) {
            file.close();
            return tokens[n];
        }
    }
    file.close();
    return "";
}







//string readNthValue(const string &filePath, int n) {
//    ifstream file(filePath);
//
//    if (!file.is_open()) {
//        cerr << "Error opening file: " << filePath << endl;
//        return "";  // Return an empty string indicating failure
//    }
//    string value;
//    for ( int i = 0 ; i < n ; i ++)
//        getline(file, value, ',');
////            cout<< value;
//    file.close();
//    return value;
//
//}




//string readNthValue(const string &filePath, int n) {
//    ifstream file(filePath);
//
//    if (!file.is_open()) {
//        cerr << "Error opening file: " << filePath << endl;
//        return "";  // Return an empty string indicating failure
//    }
//
//    string line;
//    while (getline(file, line)) {
//        stringstream ss(line);
//        string value;
//
//        for (int i = 1; i <= n; ++i) {
//            if (!getline(ss, value, ',')) {
//                cerr << "Error reading value at position " << n << " in line: " << line << endl;
//                return "";  // Return an empty string indicating failure
//            }
//        }
//
//        if (n == 1) {
//            return value;  // Return the nth value
//        }
//    }
//
//    cerr << "Error: Could not find value at position " << n << " in the file." << endl;
//    return "";  // Return an empty string indicating failure
//}

bool searchStringInCSV(const string &filename, const string &target) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string cell;

        while (getline(iss, cell, ',')) {
            if (cell == target) {
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

int findIndexInCSV(const string &filePath, const string &targetString) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return -1; // Return -1 to indicate an error
    }

    string line;
    getline(file, line); // Read the header line

    istringstream headerStream(line);
    string column;
    int index = 0;

    while (getline(headerStream, column, ',')) {
        if (column == targetString) {
            file.close(); // Close the file after finding the index
            return index;
        }
        ++index;
    }

    file.close(); // Close the file if the target string is not found
    return -1; // Return -1 to indicate that the target string is not in the CSV
}




void replaceNthStringInCSV(const string &filePath, int n, const string &replacement) {
    fstream file(filePath, ios::in | ios::out);
    n++;
    if (file.is_open()) {
        vector<string> tokens;
        string line;

        while (getline(file, line)) {
            stringstream ss(line);
            string token;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() >= n) {
                tokens[n - 1] = replacement;  // Assuming 1-based index
                file.seekp(0, ios::cur);  // Move the write pointer to the current position
                file.seekg(0, ios::beg);  // Move the read pointer to the beginning

                for (const auto &t: tokens) {
                    file << t;
                    file << ',';

                }
                break;  // Stop after processing the first line
            }
            tokens.clear();
        }

        file.close();

    } else {
        cerr << "Error opening the file.\n";
    }
}


//void replaceNthStringInCSV(const string &filePath, int n, const string &replacement) {
//    fstream file(filePath, ios::in | ios::out);
//    n++;
//    if (file.is_open()) {
//        vector<string> tokens;
//        string line;
//
//        while (getline(file, line)) {
//            stringstream ss(line);
//            string token;
//
//            while (getline(ss, token, ',')) {
//                tokens.push_back(token);
//            }
//
//            if (tokens.size() >= n) {
//                tokens[n - 1] = replacement;  // Assuming 1-based index
//                file.seekp(0, ios::cur);  // Move the write pointer to the current position
//                file.seekg(0, ios::beg);  // Move the read pointer to the beginning
//
//                for (const auto &t: tokens) {
//                    file << t;
//                    if (&t != &tokens.back()) file << ',';
//                }
//                file << ',';
//                break;  // Stop after processing the first line
//            }
//            tokens.clear();
//        }
//
//        file.close();
//
//    } else {
//        cerr << "Error opening the file.\n";
//    }
//}





//string readNthValue(const string &filePath, int n) {
//    ifstream file(filePath);
//
//    if (!file.is_open()) {
//        cerr << "Error opening file: " << filePath << endl;
//        return "";  // Return an empty string indicating failure
//    }
//
//    string line;
//    while (getline(file, line)) {
//        stringstream ss(line);
//        string value;
//
//        for (int i = 1; i <= n; ++i) {
//            if (!getline(ss, value, ',')) {
//                cerr << "Error reading value at position " << n << " in line: " << line << endl;
//                return "";  // Return an empty string indicating failure
//            }
//        }
//
//        if (n == 1) {
//            return value;  // Return the nth value
//        }
//    }
//
//    cerr << "Error: Could not find value at position " << n << " in the file." << endl;
//    return "";  // Return an empty string indicating failure
//}
//
//bool searchStringInCSV(const string &filename, const string &target) {
//    ifstream file(filename);
//
//    if (!file.is_open()) {
//        cerr << "Error opening file: " << filename << endl;
//        return false;
//    }
//
//    string line;
//    while (getline(file, line)) {
//        istringstream iss(line);
//        string cell;
//
//        while (getline(iss, cell, ',')) {
//            if (cell == target) {
//                file.close();
//                return true;
//            }
//        }
//    }
//
//    file.close();
//    return false;
//}
//
//int findIndexInCSV(const string &filePath, const string &targetString) {
//    ifstream file(filePath);
//    if (!file.is_open()) {
//        cerr << "Error opening file: " << filePath << endl;
//        return -1; // Return -1 to indicate an error
//    }
//
//    string line;
//    getline(file, line); // Read the header line
//
//    istringstream headerStream(line);
//    string column;
//    int index = 0;
//
//    while (getline(headerStream, column, ',')) {
//        if (column == targetString) {
//            file.close(); // Close the file after finding the index
//            return index;
//        }
//        ++index;
//    }
//
//    file.close(); // Close the file if the target string is not found
//    return -1; // Return -1 to indicate that the target string is not in the CSV
//}
//
//
//void replaceNthStringInCSV(const string &filePath, int n, const string &replacement) {
//    fstream file(filePath, ios::in | ios::out);
//    n++;
//    if (file.is_open()) {
//        vector<string> tokens;
//        string line;
//
//        while (getline(file, line)) {
//            stringstream ss(line);
//            string token;
//
//            while (getline(ss, token, ',')) {
//                tokens.push_back(token);
//            }
//
//            if (tokens.size() >= n) {
//                tokens[n - 1] = replacement;  // Assuming 1-based index
//                file.seekp(0, ios::cur);  // Move the write pointer to the current position
//                file.seekg(0, ios::beg);  // Move the read pointer to the beginning
//
//                for (const auto &t: tokens) {
//                    file << t;
//                    if (&t != &tokens.back()) file << ',';
//                }
//                file << '\n';
//                break;  // Stop after processing the first line
//            }
//            tokens.clear();
//        }
//
//        file.close();
//
//    } else {
//        cerr << "Error opening the file.\n";
//    }
//}

coordination yaftemakan ( coordination colision )
{
    int mind = 10000000, mini, minj;

    if (grid[colision.y][colision.x - 2] == -1) {
        if ((i_y(colision.y) - bally) * (i_y(colision.y) - bally) +
            (j_x(colision.x - 2) - ballx) * (j_x(colision.x - 2) - ballx) < mind) {
            mind = (i_y(colision.y) - bally) * (i_y(colision.y) - bally) +
                   (j_x(colision.x - 2) - ballx) * (j_x(colision.x - 2) - ballx);
            mini = colision.y;
            minj = colision.x - 2;
        }
    }
    if (grid[colision.y][colision.x + 2] == -1) {
        if ((i_y(colision.y) - bally) * (i_y(colision.y) - bally) +
            (j_x(colision.x + 2) - ballx) * (j_x(colision.x + 2) - ballx) < mind) {
            mind = (i_y(colision.y) - bally) * (i_y(colision.y) - bally) +
                   (j_x(colision.x + 2) - ballx) * (j_x(colision.x + 2) - ballx);
            mini = colision.y;
            minj = colision.x + 2;
        }
    }
    if (grid[colision.y + 1][colision.x + 1] == -1) {
        if ((i_y(colision.y + 1) - bally) * (i_y(colision.y + 1) - bally) +
            (j_x(colision.x + 1) - ballx) * (j_x(colision.x + 1) - ballx) < mind) {
            mind = (i_y(colision.y + 1) - bally) * (i_y(colision.y + 1) - bally) +
                   (j_x(colision.x + 1) - ballx) * (j_x(colision.x + 1) - ballx);
            mini = colision.y + 1;
            minj = colision.x + 1;
        }
    }
    if (grid[colision.y + 1][colision.x - 1] == -1) {
        if ((i_y(colision.y + 1) - bally) * (i_y(colision.y + 1) - bally) +
            (j_x(colision.x - 1) - ballx) * (j_x(colision.x - 1) - ballx) < mind) {
            mind = (i_y(colision.y + 1) - bally) * (i_y(colision.y + 1) - bally) +
                   (j_x(colision.x - 1) - ballx) * (j_x(colision.x - 1) - ballx);
            mini = colision.y + 1;
            minj = colision.x - 1;
        }
    }
    if (grid[colision.y - 1][colision.x - 1] == -1) {
        if ((i_y(colision.y - 1) - bally) * (i_y(colision.y - 1) - bally) +
            (j_x(colision.x - 1) - ballx) * (j_x(colision.x - 1) - ballx) < mind) {
            mind = (i_y(colision.y - 1) - bally) * (i_y(colision.y - 1) - bally) +
                   (j_x(colision.x - 1) - ballx) * (j_x(colision.x - 1) - ballx);
            mini = colision.y - 1;
            minj = colision.x - 1;
        }
    }
    if (grid[colision.y - 1][colision.x + 1] == -1) {
        if ((i_y(colision.y - 1) - bally) * (i_y(colision.y - 1) - bally) +
            (j_x(colision.x + 1) - ballx) * (j_x(colision.x + 1) - ballx) < mind) {
            mind = (i_y(colision.y - 1) - bally) * (i_y(colision.y - 1) - bally) +
                   (j_x(colision.x + 1) - ballx) * (j_x(colision.x + 1) - ballx);
            mini = colision.y - 1;
            minj = colision.x + 1;
        }
    }
    coordination temp;
    temp.x = minj;
    temp.y = mini;
    return temp;
}